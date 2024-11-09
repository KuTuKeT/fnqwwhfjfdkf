//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "OfficesActions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormOfficesActions *FormOfficesActions;
//---------------------------------------------------------------------------
__fastcall TFormOfficesActions::TFormOfficesActions(TComponent* Owner, TOfficesFormMode mode, int officeId)
	: TForm(Owner), mode(mode), officeId(officeId)
{
	if (mode == TOfficesFormMode::Add) {
		ButtonAction->Caption = "������";
		this->Caption = "���������";
    } else {
		ButtonAction->Caption = "����������";
		this->Caption = "�����������";
		LoadOfficeData();
	}
}
//---------------------------------------------------------------------------
void TFormOfficesActions::LoadOfficeData()
{
	DataBase->ADOQuery->SQL->Text = "SELECT * FROM Offices WHERE id = " + IntToStr(officeId);

	try {

		DataBase->ADOQuery->Open();

		if (!DataBase->ADOQuery->Eof) {

			LabeledEditName->Text = DataBase->ADOQuery->FieldByName("name")->AsString;
		}

	} catch (const Exception &E) {
		MessageDlg("������� ��� �������� ����� �����: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormOfficesActions::ButtonActionClick(TObject *Sender)
{
	String name = LabeledEditName->Text;

	if (name.Trim().IsEmpty()) { MessageDlg("���� �����, ������ ����� �����!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	if (mode == TOfficesFormMode::Add) {
		DataBase->ADOQuery->SQL->Text = "INSERT INTO Offices (name) VALUES "
			"('" + name + "')";
	} else {
		DataBase->ADOQuery->SQL->Text = "UPDATE Offices SET "
			"name = '" + name + "' WHERE id = " + IntToStr(officeId);
	}

	try {

		DataBase->ADOQuery->ExecSQL();

		MessageDlg(mode == TOfficesFormMode::Add ? "���� ������ �������!" : "��� ����� ������ ��������!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrOk;

	} catch (const Exception &E) {
		MessageDlg((mode == TOfficesFormMode::Add ? "������� ��� �������� �����: " : "������� ��� ��������� ����� �����: ") + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}

void __fastcall TFormOfficesActions::ButtonCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
