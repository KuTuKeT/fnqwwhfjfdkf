//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EmployeesView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEmployeesView *FormEmployeesView;
//---------------------------------------------------------------------------
__fastcall TFormEmployeesView::TFormEmployeesView(TComponent* Owner) : TForm(Owner)
{
    FillRoles();
	FillEmployees();

	count = GetEmployeesCount();
	LabelCount->Caption = "Загальна кількість співробітників - " + IntToStr(count);
}
//---------------------------------------------------------------------------
void TFormEmployeesView::FillRoles()
{
	ComboBoxChoiceRole->Items->Clear();

	int allIndex = ComboBoxChoiceRole->Items->Add("Усі");
	ComboBoxChoiceRole->Items->Objects[allIndex] = reinterpret_cast<TObject*>(0);

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
		this->Close();
	}

	ComboBoxChoiceRole->ItemIndex = 0;
}

void TFormEmployeesView::FillEmployees()
{
	ListViewItems->Items->Clear();

	String sqlText = "SELECT Employees.id, Employees.name, Roles.title "
		"FROM Employees LEFT JOIN Roles ON Employees.role_id = Roles.id";

	int roleId = GetRoleID();
	if (roleId > 0) {
        sqlText += " WHERE Employees.role_id = " + IntToStr(roleId);
    }

	DataBase->ADOQuery->SQL->Text = sqlText;

	try {

        DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof)
		{
			TListItem *item = ListViewItems->Items->Add();

            item->Caption = DataBase->ADOQuery->FieldByName("id")->AsString;
            item->SubItems->Add(DataBase->ADOQuery->FieldByName("name")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("title")->AsString);

            DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні списку співробітників: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}

int TFormEmployeesView::GetRoleID()
{
	int index = ComboBoxChoiceRole->ItemIndex;

	if (index != -1) {
		return reinterpret_cast<int>(ComboBoxChoiceRole->Items->Objects[index]);
	}

	return -1;
}

int TFormEmployeesView::GetEmployeesCount()
{
	int totalCount = 0;

    DataBase->ADOQuery->SQL->Text = "SELECT COUNT(*) AS TotalCount FROM Employees";

    try {

		DataBase->ADOQuery->Open();

		totalCount = DataBase->ADOQuery->FieldByName("TotalCount")->AsInteger;

		DataBase->ADOQuery->Close();

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні кількості співробітників: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
    }

    return totalCount;
}

bool TFormEmployeesView::ShowConfirmationDialog(String message, String caption)
{
	TForm* dialog = CreateMessageDialog(message, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo);

	dialog->Caption = caption;
    TButton* yesButton = static_cast<TButton*>(dialog->FindComponent("Yes"));
    TButton* noButton = static_cast<TButton*>(dialog->FindComponent("No"));

	if (yesButton) yesButton->Caption = "Так";
	if (noButton) noButton->Caption = "Ні";

    return (dialog->ShowModal() == mrYes);
}
//---------------------------------------------------------------------------
void __fastcall TFormEmployeesView::ComboBoxChoiceRoleChange(TObject *Sender)
{
	FillEmployees();
}
//---------------------------------------------------------------------------
void __fastcall TFormEmployeesView::ButtonAddClick(TObject *Sender)
{
	TFormEmployeesActions *addForm = new TFormEmployeesActions(this, TEmployeesFormMode::Add);
	if (addForm->ShowModal() == mrOk)
	{
		FillEmployees();
        count = count + 1;
		LabelCount->Caption = "Загальна кількість співробітників - " + IntToStr(count);
	}
	delete addForm;
}

void __fastcall TFormEmployeesView::ListViewItemsDblClick(TObject *Sender)
{
	try {

		int employeeId = StrToInt(ListViewItems->Selected->Caption);

		TFormEmployeesActions *editForm = new TFormEmployeesActions(this, TEmployeesFormMode::Edit, employeeId);
		if (editForm->ShowModal() == mrOk)
		{
			FillEmployees();
		}
		delete editForm;

	} catch (...) {
		return;
	}
}

void __fastcall TFormEmployeesView::ButtonDelClick(TObject *Sender)
{
	TListItem *selectedItem = ListViewItems->Selected;

	if (selectedItem == nullptr) { MessageDlg("Будь ласка, виберіть співробітника для видалення!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	int employeeId = StrToIntDef(selectedItem->Caption, -1);
	if (employeeId == -1) { MessageDlg("Неможливо визначити ID співробітника!", mtError, TMsgDlgButtons() << mbOK, 0); return; }

	if (ShowConfirmationDialog("Ви впевнені, що хочете видалити співробітника - '" +  selectedItem->SubItems->Strings[0] + "'?", "Підтвердження видалення")) {

		DataBase->ADOQuery->SQL->Text = "DELETE FROM Employees WHERE id = " + IntToStr(employeeId);

		try {

			DataBase->ADOQuery->ExecSQL();
			MessageDlg("Співробітника успішно видалено!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

			FillEmployees();

			count = count - 1;
			LabelCount->Caption = "Загальна кількість співробітників - " + IntToStr(count);

		} catch (const Exception &E) {
			MessageDlg("Помилка при видаленні співробітника: " + E.Message, mtInformation, TMsgDlgButtons() << mbOK, 0);
		}
	}
}
//---------------------------------------------------------------------------
