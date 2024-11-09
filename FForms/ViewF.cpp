//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ViewF.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormViewF *FormViewF;
//---------------------------------------------------------------------------
__fastcall TFormViewF::TFormViewF(TComponent* Owner, int orderId, int emplId) : TForm(Owner), orderId(orderId), emplId(emplId)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormViewF::FormShow(TObject *Sender)
{
	this->Caption = "Обробка замовлення: №" + IntToStr(orderId);

	LoadOrder();
	LoadProducts();
}
//---------------------------------------------------------------------------
void TFormViewF::LoadOrder()
{
	DataBase->ADOQuery->SQL->Text = "SELECT Orders.id, Orders.status, Orders.order_date, Orders.start_time, Orders.end_time, Orders.comment "
	  "FROM Orders "
	"WHERE Orders.id = " + IntToStr(orderId);

	try {
		DataBase->ADOQuery->Open();

		if (!DataBase->ADOQuery->IsEmpty())
		{
			LabeledEditID->Text = orderId;
			LabeledEditStatus->Text = DataBase->ADOQuery->FieldByName("status")->AsString;
			LabeledEditDateTime->Text = FormatDateTime("dd-mm-yyyy", DataBase->ADOQuery->FieldByName("order_date")->AsDateTime) + " | " +
				FormatDateTime("hh:nn", DataBase->ADOQuery->FieldByName("start_time")->AsDateTime) + "-" + FormatDateTime("hh:nn", DataBase->ADOQuery->FieldByName("end_time")->AsDateTime);
		}

		DataBase->ADOQuery->Close();

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні інформації замовлення: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}

void TFormViewF::LoadProducts()
{
	DataBase->ADOQuery->SQL->Text = "SELECT Products.name AS product_name, ProductTypes.name AS group_name, Products.price, OrderItems.quantity "
	  "FROM OrderItems "
	  "LEFT JOIN Products ON OrderItems.product_id = Products.id "
	  "LEFT JOIN ProductTypes ON Products.type_id = ProductTypes.id "
	"WHERE OrderItems.order_id = " + IntToStr(orderId) + " "
	"ORDER BY ProductTypes.id ASC, Products.id ASC;";

	try {
		DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof)
		{
			TListItem *item = ListViewProducts->Items->Add();

			item->Caption = DataBase->ADOQuery->FieldByName("product_name")->AsString;
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("group_name")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("price")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("quantity")->AsString);

			DataBase->ADOQuery->Next();
		}

		DataBase->ADOQuery->Close();

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні списку товарів до замовлення: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormViewF::ButtonConfirmClick(TObject *Sender)
{
	comment = MemoCallComment->Text;
	int selectedState = ComboBoxCallState->ItemIndex;

	String status;
	if (selectedState == 0) { status = "На доставці"; }
	else if (selectedState == 1) { status = "На допрацюванні"; }
	else { ShowMessage("Будь ласка, оберіть коректний стан обробки!"); return; }

	DataBase->ADOQuery->SQL->Text = "UPDATE Orders SET status = '" + status + "' WHERE id = " + IntToStr(orderId);

	try {
        DataBase->ADOQuery->ExecSQL();
		MessageDlg("Статус замовлення успішно оновлено!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

		if (selectedState == 0) { ModalResult = mrOk; }
		else if (selectedState == 1) { ModalResult = mrRetry; }

    } catch (const Exception &E) {
		MessageDlg("Помилка при оновленні статусу замовлення: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrClose;
	}
}

void __fastcall TFormViewF::ButtonNotesClick(TObject *Sender)
{
	TFormNotes *formNotes = new TFormNotes(this, orderId, emplId);
	formNotes->ShowModal();
	delete formNotes;
}
//---------------------------------------------------------------------------


