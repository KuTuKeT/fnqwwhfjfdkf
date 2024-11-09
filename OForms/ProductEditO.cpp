//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProductEditO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormProductEditO *FormProductEditO;
//---------------------------------------------------------------------------
__fastcall TFormProductEditO::TFormProductEditO(TComponent* Owner, int itemId) : TForm(Owner), itemId(itemId)
{
	LoadProductData();
}
//---------------------------------------------------------------------------
void TFormProductEditO::LoadProductData()
{
	DataBase->ADOQuery->SQL->Text = "SELECT OrderItems.price, OrderItems.quantity AS itemQuantity, Warehouses.quantity AS productQuantity, Warehouses.id AS productId "
	  "FROM OrderItems "
	  "LEFT JOIN Orders ON OrderItems.order_id = Orders.id "
	  "LEFT JOIN Warehouses ON OrderItems.product_id = Warehouses.product_id AND Orders.office_id = Warehouses.office_id "
	"WHERE OrderItems.id = " + IntToStr(itemId);

	try {

		DataBase->ADOQuery->Open();

		if (!DataBase->ADOQuery->Eof) {

			itemQuantity = DataBase->ADOQuery->FieldByName("itemQuantity")->AsInteger;
			productId = DataBase->ADOQuery->FieldByName("productId")->AsInteger;
			productQuantity = DataBase->ADOQuery->FieldByName("productQuantity")->AsInteger;

			LabeledEditQuantity->Text = itemQuantity;
			LabeledEditPrice->Text = DataBase->ADOQuery->FieldByName("price")->AsString;
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні даних продукту: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormProductEditO::ButtonAddClick(TObject *Sender)
{
	float price;
	String priceStr;
	int quantity;

	if (LabeledEditQuantity->Text.Trim().IsEmpty()) { MessageDlg("Будь ласка, введіть кількість для товару!", mtWarning, TMsgDlgButtons() << mbOK, 0); return;
	} else {

		try {
			quantity = StrToInt(LabeledEditQuantity->Text);

			if (quantity <= 0 || quantity > (itemQuantity + productQuantity)) { MessageDlg("Недопустима кількість товару (мін. = 0, макс. = " + IntToStr(itemQuantity + productQuantity) + ")!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

		} catch (...) {
			MessageDlg("Будь ласка, введіть коректне числове значення для кількості!", mtWarning, TMsgDlgButtons() << mbOK, 0);
			return;
		}
	}

	if (LabeledEditPrice->Text.Trim().IsEmpty()) { MessageDlg("Будь ласка, введіть ціну для товару!", mtWarning, TMsgDlgButtons() << mbOK, 0); return;
	} else {

		try {
			price = StrToFloat(LabeledEditPrice->Text);

			if (price <= 0.0) { MessageDlg("Ціна для товару повинна бути більше нуля!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }
			priceStr = StringReplace(LabeledEditPrice->Text, ",", ".", TReplaceFlags() << rfReplaceAll);

		} catch (...) {
			MessageDlg("Будь ласка, введіть коректне числове значення для ціни!", mtWarning, TMsgDlgButtons() << mbOK, 0);
			return;
		}
	}

	DataBase->ADOConnection->BeginTrans();

	try {

    	DataBase->ADOQuery->SQL->Text = "UPDATE OrderItems SET "
			"quantity = '" + IntToStr(quantity) + "', price = '" + priceStr + "' WHERE id = " + IntToStr(itemId);
		DataBase->ADOQuery->ExecSQL();

		DataBase->ADOQuery->SQL->Text = "UPDATE Warehouses SET "
			"quantity = '" + IntToStr((itemQuantity + productQuantity) - quantity) + "' WHERE id = " + IntToStr(productId);
		DataBase->ADOQuery->ExecSQL();

		DataBase->ADOConnection->CommitTrans();
		MessageDlg("Дані продукту успішно оновлено!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

		ModalResult = mrOk;

	} catch (const Exception &E) {
		DataBase->ADOConnection->RollbackTrans();
		MessageDlg("Помилка при збереженні даних продукту: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}

void __fastcall TFormProductEditO::ButtonCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

