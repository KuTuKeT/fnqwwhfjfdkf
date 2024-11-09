//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RecipientsActions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRecipientsActions *FormRecipientsActions;
//---------------------------------------------------------------------------
__fastcall TFormRecipientsActions::TFormRecipientsActions(TComponent* Owner, TRecipientsFormMode mode, int recipientId)
	: TForm(Owner), mode(mode), recipientId(recipientId)
{
	if (mode == TRecipientsFormMode::Add) {
		ButtonAction->Caption = "������";
		this->Caption = "���������";
    } else {
		ButtonAction->Caption = "����������";
		this->Caption = "�����������";
		LoadRecipientData();
	}
}
//---------------------------------------------------------------------------
void TFormRecipientsActions::LoadRecipientData()
{
	DataBase->ADOQuery->SQL->Text = "SELECT * FROM Recipients WHERE id = " + IntToStr(recipientId);

	try {

		DataBase->ADOQuery->Open();

		if (!DataBase->ADOQuery->Eof) {

			LabeledEditName->Text = DataBase->ADOQuery->FieldByName("name")->AsString;
			LabeledEditPhone->Text = DataBase->ADOQuery->FieldByName("phone")->AsString;
		}

	} catch (const Exception &E) {
		MessageDlg("������� ��� �������� ����� ����������: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormRecipientsActions::ButtonActionClick(TObject *Sender)
{
	String name = LabeledEditName->Text;
	String phone = LabeledEditPhone->Text;

	if (name.Trim().IsEmpty()) { MessageDlg("���� �����, ������ ��'� ����������!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }
	if (phone.Trim().IsEmpty()) { MessageDlg("���� �����, ������ ������� ����������!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	if (mode == TRecipientsFormMode::Add) {
		DataBase->ADOQuery->SQL->Text = "INSERT INTO Recipients (name, phone) VALUES "
			"('" + name + "', '" + phone + "')";
	} else {
		DataBase->ADOQuery->SQL->Text = "UPDATE Recipients SET "
			"name = '" + name + "', phone = '" + phone + "' WHERE id = " + IntToStr(recipientId);
	}

	try {

		DataBase->ADOQuery->ExecSQL();

		MessageDlg(mode == TRecipientsFormMode::Add ? "��������� ������ �������!" : "��� ���������� ������ ��������!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrOk;

	} catch (const Exception &E) {
		MessageDlg((mode == TRecipientsFormMode::Add ? "������� ��� �������� ����������: " : "������� ��� ��������� ����� ����������: ") + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}

void __fastcall TFormRecipientsActions::ButtonCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
