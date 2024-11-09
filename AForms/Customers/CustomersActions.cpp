//---------------------------------------------------------------------------

#include <vcl.h>
#include <SysUtils.hpp>
#pragma hdrstop

#include "CustomersActions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCustomersActions *FormCustomersActions;
//---------------------------------------------------------------------------
__fastcall TFormCustomersActions::TFormCustomersActions(TComponent* Owner, TCustomerFormMode mode, int customerId)
	: TForm(Owner), mode(mode), customerId(customerId)
{
	if (mode == TCustomerFormMode::Add) {
		ButtonAction->Caption = "Додати";
		this->Caption = "Додавання";
    } else {
		ButtonAction->Caption = "Редагувати";
		this->Caption = "Редагування";
		LoadCustomerData();
	}
}
//---------------------------------------------------------------------------
void TFormCustomersActions::LoadCustomerData()
{
	DataBase->ADOQuery->SQL->Text = "SELECT * FROM Customers WHERE id = " + IntToStr(customerId);

	try {

		DataBase->ADOQuery->Open();

		if (!DataBase->ADOQuery->Eof) {

			LabeledEditName->Text = DataBase->ADOQuery->FieldByName("name")->AsString;
			LabeledEditPhone->Text = DataBase->ADOQuery->FieldByName("phone")->AsString;
			LabeledEditBalance->Text = DataBase->ADOQuery->FieldByName("balance")->AsString;
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні даних замовника: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormCustomersActions::ButtonActionClick(TObject *Sender)
{
	String name = LabeledEditName->Text;
	String phone = LabeledEditPhone->Text;
	String balanceStr = LabeledEditBalance->Text;
	double balance = 0.0;

	if (name.Trim().IsEmpty()) { MessageDlg("Будь ласка, введіть ім'я клієнта!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }
	if (phone.Trim().IsEmpty()) { MessageDlg("Будь ласка, введіть телефон клієнта!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	if (!balanceStr.IsEmpty()) {

		try {
			balance = StrToFloat(balanceStr);
			balanceStr = StringReplace(balanceStr, ",", ".", TReplaceFlags() << rfReplaceAll);
		} catch (...) {
			MessageDlg("Будь ласка, введіть коректне значення балансу!", mtWarning, TMsgDlgButtons() << mbOK, 0);
			return;
		}
	} else {
		balanceStr = "0.0";
	}

    if (mode == TCustomerFormMode::Add) {
        DataBase->ADOQuery->SQL->Text = "INSERT INTO Customers (name, phone, balance) VALUES "
			"('" + name + "', '" + phone + "', '" + balanceStr + "')";
    } else {
		DataBase->ADOQuery->SQL->Text = "UPDATE Customers SET "
			"name = '" + name + "', phone = '" + phone + "', balance = '" + balanceStr + "' WHERE id = " + IntToStr(customerId);
	}

	try {

		DataBase->ADOQuery->ExecSQL();

		MessageDlg(mode == TCustomerFormMode::Add ? "Замовник успішно доданий!" : "Дані замовника успішно оновлено!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrOk;

	} catch (const Exception &E) {
		MessageDlg((mode == TCustomerFormMode::Add ? "Помилка при додаванні замовника: " : "Помилка при збереженні даних замовника: ") + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}

void __fastcall TFormCustomersActions::ButtonCancelClick(TObject *Sender)
{
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
