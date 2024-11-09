//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Login.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormLogin *FormLogin;
//---------------------------------------------------------------------------
__fastcall TFormLogin::TFormLogin(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool TFormLogin::CheckCredentials(String login, String password, User &user)
{
	DataBase->ADOQuery->SQL->Text = "SELECT Employees.id, Employees.name, Roles.id AS role_id, Roles.title AS role_name, Roles.access "
	  "FROM Employees "
	  "INNER JOIN Roles ON Employees.role_id = Roles.id "
	"WHERE login = '" + login + "' AND password = '" + password + "'";

	try {

		DataBase->ADOQuery->Open();

		if (!DataBase->ADOQuery->Eof)
		{
			user.id = DataBase->ADOQuery->FieldByName("id")->AsInteger;
			user.role_id = DataBase->ADOQuery->FieldByName("role_id")->AsInteger;
			user.name = DataBase->ADOQuery->FieldByName("name")->AsString;
			user.role_name = DataBase->ADOQuery->FieldByName("role_name")->AsString;
			user.access = DataBase->ADOQuery->FieldByName("access")->AsInteger;

			DataBase->ADOQuery->Close();
			return true;
		}
		else
		{
			DataBase->ADOQuery->Close();
			return false;
        }
    }
	catch (...) {
		return false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormLogin::ButtonEnterClick(TObject *Sender)
{
	if (LabeledEditPass->Text.IsEmpty() || LabeledEditLogin->Text.IsEmpty())
	{ MessageDlgPos("Введіть логін і пароль!", mtError, TMsgDlgButtons() << mbOK, 0, -1, -1); return; }

	String login = LabeledEditLogin->Text;
	String password = LabeledEditPass->Text;

	if (CheckCredentials(login, password, user)) {
		ModalResult = mrOk;
	} else {
		MessageDlg("Невірний логін чи пароль!", mtError, TMsgDlgButtons() << mbOK, 0);
	}
}
//---------------------------------------------------------------------------

