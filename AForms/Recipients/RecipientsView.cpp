//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RecipientsView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRecipientsView *FormRecipientsView;
//---------------------------------------------------------------------------
__fastcall TFormRecipientsView::TFormRecipientsView(TComponent* Owner) : TForm(Owner)
{
	FillRecipients();
}
//---------------------------------------------------------------------------
void TFormRecipientsView::FillRecipients()
{
	ListViewItems->Items->Clear();

	DataBase->ADOQuery->SQL->Text = "SELECT * FROM Recipients";

	try {

        DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof)
		{
			TListItem *item = ListViewItems->Items->Add();

            item->Caption = DataBase->ADOQuery->FieldByName("id")->AsString;
            item->SubItems->Add(DataBase->ADOQuery->FieldByName("name")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("phone")->AsString);

            DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні списку отримувачів: " + E.Message, mtInformation, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}

bool TFormRecipientsView::ShowConfirmationDialog(String message, String caption)
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
void __fastcall TFormRecipientsView::ButtonAddClick(TObject *Sender)
{
	TFormRecipientsActions *addForm = new TFormRecipientsActions(this, TRecipientsFormMode::Add);
	if (addForm->ShowModal() == mrOk)
	{
		FillRecipients();
	}
	delete addForm;
}

void __fastcall TFormRecipientsView::ListViewItemsDblClick(TObject *Sender)
{
	try {

		int recipientId = StrToInt(ListViewItems->Selected->Caption);

		TFormRecipientsActions *editForm = new TFormRecipientsActions(this, TRecipientsFormMode::Edit, recipientId);
		if (editForm->ShowModal() == mrOk)
		{
			FillRecipients();
		}
		delete editForm;

	} catch (...) {
		return;
	}
}

void __fastcall TFormRecipientsView::ButtonDelClick(TObject *Sender)
{
	TListItem *selectedItem = ListViewItems->Selected;

	if (selectedItem == nullptr) { MessageDlg("Будь ласка, виберіть отримувача для видалення!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	int recipientId = StrToIntDef(selectedItem->Caption, -1);
	if (recipientId == -1) { MessageDlg("Неможливо визначити ID отримувача!", mtError, TMsgDlgButtons() << mbOK, 0); return; }

	if (ShowConfirmationDialog("Ви впевнені, що хочете видалити отримувача - '" +  selectedItem->SubItems->Strings[0] + "'?", "Підтвердження видалення")) {

		DataBase->ADOQuery->SQL->Text = "DELETE FROM Recipients WHERE id = " + IntToStr(recipientId);

		try {

			DataBase->ADOQuery->ExecSQL();
			MessageDlg("Отримувача успішно видалено!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

			FillRecipients();

		} catch (const Exception &E) {
			MessageDlg("Помилка при видаленні отримувача: " + E.Message, mtInformation, TMsgDlgButtons() << mbOK, 0);
		}
	}
}
//---------------------------------------------------------------------------
