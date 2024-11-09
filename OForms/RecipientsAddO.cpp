//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RecipientsAddO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRecipientsAddO *FormRecipientsAddO;
//---------------------------------------------------------------------------
__fastcall TFormRecipientsAddO::TFormRecipientsAddO(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormRecipientsAddO::ButtonAddClick(TObject *Sender)
{
	String name = LabeledEditName->Text;
	String phone = LabeledEditPhone->Text;

	if (name.Trim().IsEmpty()) { MessageDlg("���� �����, ������ ��'� ����������!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }
	if (phone.Trim().IsEmpty()) { MessageDlg("���� �����, ������ ������� ����������!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	DataBase->ADOQuery->SQL->Text = "INSERT INTO Recipients (name, phone) VALUES "
		"('" + name + "', '" + phone + "')";

	try {

		DataBase->ADOQuery->ExecSQL();

		MessageDlg("��������� ������ �������!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrOk;

	} catch (const Exception &E) {
		MessageDlg("������� ��� �������� ����������: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormRecipientsAddO::ButtonCancelClick(TObject *Sender)
{
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
