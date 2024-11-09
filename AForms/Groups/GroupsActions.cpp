//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GroupsActions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormGroupsActions *FormGroupsActions;
//---------------------------------------------------------------------------
__fastcall TFormGroupsActions::TFormGroupsActions(TComponent* Owner, TGroupsFormMode mode, int groupId)
	: TForm(Owner), mode(mode), groupId(groupId)
{
	if (mode == TGroupsFormMode::Add) {
		ButtonAction->Caption = "������";
		this->Caption = "���������";
    } else {
		ButtonAction->Caption = "����������";
		this->Caption = "�����������";
		LoadGroupData();
	}
}
//---------------------------------------------------------------------------
void TFormGroupsActions::LoadGroupData()
{
	DataBase->ADOQuery->SQL->Text = "SELECT * FROM ProductTypes WHERE id = " + IntToStr(groupId);

	try {

		DataBase->ADOQuery->Open();

		if (!DataBase->ADOQuery->Eof) {

			LabeledEditName->Text = DataBase->ADOQuery->FieldByName("name")->AsString;
		}

	} catch (const Exception &E) {
		MessageDlg("������� ��� �������� ����� ����� ������: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormGroupsActions::ButtonActionClick(TObject *Sender)
{
	String name = LabeledEditName->Text;

	if (name.Trim().IsEmpty()) { MessageDlg("���� �����, ������ ����� �����!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	if (mode == TGroupsFormMode::Add) {
        DataBase->ADOQuery->SQL->Text = "INSERT INTO ProductTypes (name) VALUES "
			"('" + name + "')";
    } else {
        DataBase->ADOQuery->SQL->Text = "UPDATE ProductTypes SET "
			"name = '" + name + "' WHERE id = " + IntToStr(groupId);
	}

	try {

		DataBase->ADOQuery->ExecSQL();

		MessageDlg(mode == TGroupsFormMode::Add ? "����� ������ ������ ������!" : "��� ����� ������ ������ ��������!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrOk;

	} catch (const Exception &E) {
		MessageDlg((mode == TGroupsFormMode::Add ? "������� ��� �������� ����� ������: " : "������� ��� ��������� ����� ����� ������: ") + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}

void __fastcall TFormGroupsActions::ButtonCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
