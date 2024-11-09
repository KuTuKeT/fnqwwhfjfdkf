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
		ButtonAction->Caption = "Додати";
		this->Caption = "Додавання";
    } else {
		ButtonAction->Caption = "Редагувати";
		this->Caption = "Редагування";
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
		MessageDlg("Помилка при отриманні даних групи товарів: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormGroupsActions::ButtonActionClick(TObject *Sender)
{
	String name = LabeledEditName->Text;

	if (name.Trim().IsEmpty()) { MessageDlg("Будь ласка, введіть назву групи!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	if (mode == TGroupsFormMode::Add) {
        DataBase->ADOQuery->SQL->Text = "INSERT INTO ProductTypes (name) VALUES "
			"('" + name + "')";
    } else {
        DataBase->ADOQuery->SQL->Text = "UPDATE ProductTypes SET "
			"name = '" + name + "' WHERE id = " + IntToStr(groupId);
	}

	try {

		DataBase->ADOQuery->ExecSQL();

		MessageDlg(mode == TGroupsFormMode::Add ? "Група товарів успішно додана!" : "Дані групи товарів успішно оновлено!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrOk;

	} catch (const Exception &E) {
		MessageDlg((mode == TGroupsFormMode::Add ? "Помилка при додаванні групи товарів: " : "Помилка при збереженні даних групи товарів: ") + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}

void __fastcall TFormGroupsActions::ButtonCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
