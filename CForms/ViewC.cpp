//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ViewC.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormViewC *FormViewC;
//---------------------------------------------------------------------------
__fastcall TFormViewC::TFormViewC(TComponent* Owner, int orderId, int emplId) : TForm(Owner), orderId(orderId), emplId(emplId)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormViewC::FormShow(TObject *Sender)
{
	this->Caption = "Обробка замовлення: №" + IntToStr(orderId);

	LoadOrder();
	LoadProducts();
}
//---------------------------------------------------------------------------
void TFormViewC::LoadOrder()
{
	DataBase->ADOQuery->SQL->Text = "SELECT Orders.id, Orders.status, Orders.order_date, Orders.start_time, Orders.end_time, Orders.address, "
	  "Recipients.name AS recipient_name, Recipients.phone AS recipient_phone "
	  "FROM Orders "
	  "LEFT JOIN Recipients ON Orders.recipient_id = Recipients.id "
	"WHERE Orders.id = " + IntToStr(orderId);

	try {
		DataBase->ADOQuery->Open();

		if (!DataBase->ADOQuery->IsEmpty())
		{
			LabeledEditID->Text = orderId;
			LabeledEditStatus->Text = DataBase->ADOQuery->FieldByName("status")->AsString;
			LabeledEditDateTime->Text = FormatDateTime("dd-mm-yyyy", DataBase->ADOQuery->FieldByName("order_date")->AsDateTime) + " | " +
				FormatDateTime("hh:nn", DataBase->ADOQuery->FieldByName("start_time")->AsDateTime) + "-" + FormatDateTime("hh:nn", DataBase->ADOQuery->FieldByName("end_time")->AsDateTime);

			LabeledEditRecipientName->Text = DataBase->ADOQuery->FieldByName("recipient_name")->AsString;
			LabeledEditRecipientPhone->Text = DataBase->ADOQuery->FieldByName("recipient_phone")->AsString;

			MemoAddress->Text = DataBase->ADOQuery->FieldByName("address")->AsString;
		}

		DataBase->ADOQuery->Close();

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні інформації замовлення: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}

void TFormViewC::LoadProducts()
{
	DataBase->ADOQuery->SQL->Text = "SELECT Products.name AS product_name, ProductTypes.name AS group_name, Products.price, OrderItems.quantity "
	  "FROM OrderItems "
	  "LEFT JOIN Products ON OrderItems.product_id = Products.id "
	  "LEFT JOIN ProductTypes ON Products.type_id = ProductTypes.id "
	"WHERE OrderItems.order_id = " + IntToStr(orderId) + " "
	"ORDER BY ProductTypes.id ASC, Products.id ASC";

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
void __fastcall TFormViewC::ButtonConfirmClick(TObject *Sender)
{
	comment = MemoCallComment->Text;
	int selectedState = ComboBoxCallState->ItemIndex;

	String status;
	if (selectedState == 0) { status = "Виконаний"; }
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

void __fastcall TFormViewC::ButtonNotesClick(TObject *Sender)
{
	TFormNotes *formNotes = new TFormNotes(this, orderId, emplId);
	formNotes->ShowModal();
	delete formNotes;
}
//---------------------------------------------------------------------------

