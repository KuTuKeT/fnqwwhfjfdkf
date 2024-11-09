//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProductAddO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormProductAddO *FormProductAddO;
//---------------------------------------------------------------------------
__fastcall TFormProductAddO::TFormProductAddO(TComponent* Owner, int orderId, int officeId) : TForm(Owner), orderId(orderId), officeId(officeId)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormProductAddO::FormShow(TObject *Sender)
{
	DataBase->ADOQuery->SQL->Text = "SELECT name FROM Offices WHERE id = " + IntToStr(officeId);
	DataBase->ADOQuery->Open();
	LabelChoiceOffice->Caption = "Офіс - " + DataBase->ADOQuery->FieldByName("name")->AsString;
	DataBase->ADOQuery->Close();

	FillWarehouses();
}
//---------------------------------------------------------------------------
 void TFormProductAddO::FillWarehouses()
{
	ListViewItems->Items->Clear();

	DataBase->ADOQuery->SQL->Text = "SELECT Warehouses.id, Warehouses.quantity, Products.name AS product_name, Products.price AS product_price, ProductTypes.name AS group_name "
	  "FROM Warehouses "
	  "LEFT JOIN Products ON Warehouses.product_id = Products.id "
	  "LEFT JOIN ProductTypes ON Products.type_id = ProductTypes.id "
	"WHERE Warehouses.quantity != 0 AND Warehouses.office_id = " + IntToStr(officeId);

	try {

        DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof)
		{
			TListItem *item = ListViewItems->Items->Add();

            item->Caption = DataBase->ADOQuery->FieldByName("id")->AsString;
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("product_name")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("group_name")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("product_price")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("quantity")->AsString);

            DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні списку товарів складу: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormProductAddO::ListViewItemsClick(TObject *Sender)
{
	TListItem *selectedItem = ListViewItems->Selected;

	if (selectedItem != nullptr)
	{
		int recordId = StrToInt(selectedItem->Caption);

		DataBase->ADOQuery->SQL->Text = "SELECT Warehouses.quantity, Products.id, Products.price "
		  "FROM Warehouses "
		  "LEFT JOIN Products ON Warehouses.product_id = Products.id "
		"WHERE Warehouses.id = " + IntToStr(recordId);

		try {
			DataBase->ADOQuery->Open();

			productId = DataBase->ADOQuery->FieldByName("id")->AsInteger;
			productQuantity = DataBase->ADOQuery->FieldByName("quantity")->AsInteger;

			LabeledEditPrice->Text = DataBase->ADOQuery->FieldByName("price")->AsString;
			LabeledEditQuantity->Text = productQuantity;

			DataBase->ADOQuery->Close();

		} catch (const Exception &E) {
			MessageDlg("Помилка при отриманні даних товару: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormProductAddO::ButtonAddClick(TObject *Sender)
{
	TListItem *selectedItem = ListViewItems->Selected;

	if (selectedItem == nullptr) { MessageDlg("Будь ласка, виберіть продукт для додавання!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	int recordId = StrToIntDef(selectedItem->Caption, -1);
	if (recordId == -1) { MessageDlg("Неможливо визначити ID продукту!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	float price;
	String priceStr;
	int quantity;

	if (LabeledEditQuantity->Text.Trim().IsEmpty()) { MessageDlg("Будь ласка, введіть кількість для товару!", mtWarning, TMsgDlgButtons() << mbOK, 0); return;
	} else {

		try {
			quantity = StrToInt(LabeledEditQuantity->Text);

			if (quantity <= 0 || quantity > productQuantity) { MessageDlg("Недопустима кількість товару (мін. = 0, макс. = " + IntToStr(productQuantity) + ")!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

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

	DataBase->ADOQuery->SQL->Text = "SELECT COUNT(*) AS count FROM OrderItems WHERE product_id = " + IntToStr(productId) + " AND order_id = " + IntToStr(orderId);
	DataBase->ADOQuery->Open();
	int count = DataBase->ADOQuery->FieldByName("count")->AsInteger;
	DataBase->ADOQuery->Close();
	if (count > 0)  { MessageDlg("Товар вже доданий до замовлення.", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	DataBase->ADOConnection->BeginTrans();

	try {

		DataBase->ADOQuery->SQL->Text = "INSERT INTO OrderItems (order_id, product_id, quantity, price) VALUES "
			"('" + IntToStr(orderId) + "', '" +  IntToStr(productId) + "', '" +  IntToStr(quantity) + "', '" + priceStr + "')";
		DataBase->ADOQuery->ExecSQL();

		DataBase->ADOQuery->SQL->Text = "UPDATE Warehouses SET quantity = quantity - " + IntToStr(quantity) + " WHERE id = " + IntToStr(recordId);
		DataBase->ADOQuery->ExecSQL();

		DataBase->ADOConnection->CommitTrans();
		MessageDlg("Продукт успішно додано, кількість на складі оновлено!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

        ModalResult = mrOk;

	} catch (const Exception &E) {
		DataBase->ADOConnection->RollbackTrans();
		MessageDlg("Помилка при додаванні продукту: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}

void __fastcall TFormProductAddO::ButtonCancelClick(TObject *Sender)
{
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

