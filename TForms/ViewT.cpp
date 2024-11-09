//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ViewT.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormViewT *FormViewT;
//---------------------------------------------------------------------------
__fastcall TFormViewT::TFormViewT(TComponent* Owner, int orderId, int emplId) : TForm(Owner), orderId(orderId), emplId(emplId)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormViewT::FormShow(TObject *Sender)
{
	this->Caption = "Обробка замовлення: №" + IntToStr(orderId);
	LoadOrder();
}
//---------------------------------------------------------------------------
void TFormViewT::LoadOrder()
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

			DatePicker->Date = DataBase->ADOQuery->FieldByName("order_date")->AsDateTime;
			StartTimePicker->Time = DataBase->ADOQuery->FieldByName("start_time")->AsDateTime;
			EndTimePicker->Time = DataBase->ADOQuery->FieldByName("end_time")->AsDateTime;

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

//---------------------------------------------------------------------------
void __fastcall TFormViewT::ButtonConfirmClick(TObject *Sender)
{
	comment = MemoCallComment->Text;
	int selectedState = ComboBoxCallState->ItemIndex;

	String status;
	if (selectedState == 0) { status = "Збирається"; }
	else if (selectedState == 1) { status = "На допрацюванні"; }
	else { ShowMessage("Будь ласка, оберіть коректний стан обробки!"); return; }

	DataBase->ADOQuery->SQL->Text = "UPDATE Orders SET status = '" + status + "', address = '" + MemoAddress->Text + "', "
	  "order_date = '" + FormatDateTime("yyyy-mm-dd", DatePicker->Date) + "', start_time = '" + FormatDateTime("hh:nn:ss", StartTimePicker->Time) + "', end_time = '" + FormatDateTime("hh:nn:ss", EndTimePicker->Time) + "' "
	"WHERE id = " + IntToStr(orderId);

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

void __fastcall TFormViewT::ButtonNotesClick(TObject *Sender)
{
	TFormNotes *formNotes = new TFormNotes(this, orderId, emplId);
	formNotes->ShowModal();
	delete formNotes;
}
//---------------------------------------------------------------------------
