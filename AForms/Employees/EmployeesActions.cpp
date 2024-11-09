//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EmployeesActions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEmployeesActions *FormEmployeesActions;
//---------------------------------------------------------------------------
__fastcall TFormEmployeesActions::TFormEmployeesActions(TComponent* Owner, TEmployeesFormMode mode, int employeeId)
	: TForm(Owner), mode(mode), employeeId(employeeId)
{
	FillRoles();

	if (mode == TEmployeesFormMode::Add) {
		ButtonAction->Caption = "Додати";
		this->Caption = "Додавання";
    } else {
		ButtonAction->Caption = "Редагувати";
		this->Caption = "Редагування";
		LoadEmployeeData();
	}
}
//---------------------------------------------------------------------------
void TFormEmployeesActions::LoadEmployeeData()
{
	DataBase->ADOQuery->SQL->Text = "SELECT * FROM Employees WHERE id = " + IntToStr(employeeId);

	try {

		DataBase->ADOQuery->Open();

		if (!DataBase->ADOQuery->Eof) {

			LabeledEditName->Text = DataBase->ADOQuery->FieldByName("name")->AsString;
			LabeledEditLogin->Text = DataBase->ADOQuery->FieldByName("login")->AsString;
			LabeledEditPass->Text = DataBase->ADOQuery->FieldByName("password")->AsString;
			ComboBoxChoiceRole->ItemIndex = DataBase->ADOQuery->FieldByName("role_id")->AsInteger - 1;
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні даних співробітника: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}

void TFormEmployeesActions::FillRoles()
{
	ComboBoxChoiceRole->Items->Clear();

	DataBase->ADOQuery->SQL->Text = "SELECT id, title FROM Roles";

	try {

		DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof) {

			int role_id = DataBase->ADOQuery->FieldByName("id")->AsInteger;
			String role_title = DataBase->ADOQuery->FieldByName("title")->AsString;

			int index = ComboBoxChoiceRole->Items->Add(role_title);
			ComboBoxChoiceRole->Items->Objects[index] = reinterpret_cast<TObject*>(role_id);

			DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні ролей: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrNone;
	}

	ComboBoxChoiceRole->ItemIndex = 0;
}

int TFormEmployeesActions::GetRoleID()
{
	int index = ComboBoxChoiceRole->ItemIndex;

	if (index != -1) {
		return reinterpret_cast<int>(ComboBoxChoiceRole->Items->Objects[index]);
	}

	return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormEmployeesActions::ButtonActionClick(TObject *Sender)
{
	String name = LabeledEditName->Text;
	String login = LabeledEditLogin->Text;
	String pass = LabeledEditPass->Text;

	if (name.Trim().IsEmpty()) { MessageDlg("Будь ласка, введіть ім'я співробітника!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }
	if (login.Trim().IsEmpty()) { MessageDlg("Будь ласка, введіть логін!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }
	if (pass.Trim().IsEmpty()) { MessageDlg("Будь ласка, введіть пароль!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	int roleId = -1;
	if (ComboBoxChoiceRole->ItemIndex != -1) { roleId = reinterpret_cast<int>(ComboBoxChoiceRole->Items->Objects[ComboBoxChoiceRole->ItemIndex]); }
	if (roleId == 0 || roleId == -1) { MessageDlg("Будь ласка, оберіть роль.", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	if (mode == TEmployeesFormMode::Add) {
        DataBase->ADOQuery->SQL->Text = "INSERT INTO Employees (name, login, password, role_id) VALUES "
			"('" + name + "', '" + login + "', '" + pass + "', '" + roleId + "')";
    } else {
		DataBase->ADOQuery->SQL->Text = "UPDATE Employees SET "
		"name = '" + name + "', login = '" + login + "', password = '" + pass + "', role_id = '" + IntToStr(GetRoleID()) + "' WHERE id = " + IntToStr(employeeId);
	}

	try {

		DataBase->ADOQuery->ExecSQL();

		MessageDlg(mode == TEmployeesFormMode::Add ? "Співробітник успішно доданий!" : "Дані співробітника успішно оновлено!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrOk;

	} catch (const Exception &E) {
		MessageDlg((mode == TEmployeesFormMode::Add ? "Помилка при додаванні співробітника: " : "Помилка при збереженні даних співробітника: ") + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}

void __fastcall TFormEmployeesActions::ButtonCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
