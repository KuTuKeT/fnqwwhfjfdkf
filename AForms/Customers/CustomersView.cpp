//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CustomersView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCustomersView *FormCustomersView;
//---------------------------------------------------------------------------
__fastcall TFormCustomersView::TFormCustomersView(TComponent* Owner) : TForm(Owner)
{
	FillCustomers();
}
//---------------------------------------------------------------------------
void TFormCustomersView::FillCustomers()
{
	ListViewItems->Items->Clear();

	DataBase->ADOQuery->SQL->Text = "SELECT * FROM Customers";

	try {

        DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof)
		{
			TListItem *item = ListViewItems->Items->Add();

            item->Caption = DataBase->ADOQuery->FieldByName("id")->AsString;
            item->SubItems->Add(DataBase->ADOQuery->FieldByName("name")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("phone")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("balance")->AsString);

            DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні списку замовників: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}

bool TFormCustomersView::ShowConfirmationDialog(String message, String caption)
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
void __fastcall TFormCustomersView::ButtonAddClick(TObject *Sender)
{
	TFormCustomersActions *addForm = new TFormCustomersActions(this, TCustomerFormMode::Add);
	if (addForm->ShowModal() == mrOk)
	{
		FillCustomers();
	}
	delete addForm;
}

void __fastcall TFormCustomersView::ListViewItemsDblClick(TObject *Sender)
{
	try {

		int customerId = StrToInt(ListViewItems->Selected->Caption);

		TFormCustomersActions *editForm = new TFormCustomersActions(this, TCustomerFormMode::Edit, customerId);
		if (editForm->ShowModal() == mrOk)
		{
			FillCustomers();
		}
		delete editForm;

	} catch (...) {
		return;
	}
}

void __fastcall TFormCustomersView::ButtonDelClick(TObject *Sender)
{
	TListItem *selectedItem = ListViewItems->Selected;

	if (selectedItem == nullptr) { MessageDlg("Будь ласка, виберіть замовника для видалення!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	int customerId = StrToIntDef(selectedItem->Caption, -1);
	if (customerId == -1) { MessageDlg("Неможливо визначити ID замовника!", mtError, TMsgDlgButtons() << mbOK, 0); return; }

	if (ShowConfirmationDialog("Ви впевнені, що хочете видалити замовника - '" +  selectedItem->SubItems->Strings[0] + "'?", "Підтвердження видалення")) {

		DataBase->ADOQuery->SQL->Text = "DELETE FROM Customers WHERE id = " + IntToStr(customerId);

		try {

			DataBase->ADOQuery->ExecSQL();
			MessageDlg("Замовника успішно видалено!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

			FillCustomers();

		} catch (const Exception &E) {
			MessageDlg("Помилка при видаленні замовника: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		}
	}
}
//---------------------------------------------------------------------------
