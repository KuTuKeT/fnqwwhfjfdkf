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
		ButtonAction->Caption = "Додати";
		this->Caption = "Додавання";
    } else {
		ButtonAction->Caption = "Редагувати";
		this->Caption = "Редагування";
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
		MessageDlg("Помилка при отриманні даних офісу: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormOfficesActions::ButtonActionClick(TObject *Sender)
{
	String name = LabeledEditName->Text;

	if (name.Trim().IsEmpty()) { MessageDlg("Будь ласка, введіть назву офісу!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	if (mode == TOfficesFormMode::Add) {
		DataBase->ADOQuery->SQL->Text = "INSERT INTO Offices (name) VALUES "
			"('" + name + "')";
	} else {
		DataBase->ADOQuery->SQL->Text = "UPDATE Offices SET "
			"name = '" + name + "' WHERE id = " + IntToStr(officeId);
	}

	try {

		DataBase->ADOQuery->ExecSQL();

		MessageDlg(mode == TOfficesFormMode::Add ? "Офіс успішно доданий!" : "Дані офісу успішно оновлено!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrOk;

	} catch (const Exception &E) {
		MessageDlg((mode == TOfficesFormMode::Add ? "Помилка при додаванні офісу: " : "Помилка при збереженні даних офісу: ") + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}

void __fastcall TFormOfficesActions::ButtonCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
