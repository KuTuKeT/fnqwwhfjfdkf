//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "OfficesView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormOfficesView *FormOfficesView;
//---------------------------------------------------------------------------
__fastcall TFormOfficesView::TFormOfficesView(TComponent* Owner) : TForm(Owner)
{
	FillOffices();
}
//---------------------------------------------------------------------------
void TFormOfficesView::FillOffices()
{
	ListViewItems->Items->Clear();

	DataBase->ADOQuery->SQL->Text = "SELECT * FROM Offices";

	try {

		DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof)
		{
			TListItem *item = ListViewItems->Items->Add();

			item->Caption = DataBase->ADOQuery->FieldByName("id")->AsString;
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("name")->AsString);

			DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні списку офісів: " + E.Message, mtInformation, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}

bool TFormOfficesView::ShowConfirmationDialog(String message, String caption)
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
void __fastcall TFormOfficesView::ButtonAddClick(TObject *Sender)
{
	TFormOfficesActions *addForm = new TFormOfficesActions(this, TOfficesFormMode::Add);
	if (addForm->ShowModal() == mrOk)
	{
		FillOffices();
	}
	delete addForm;
}

void __fastcall TFormOfficesView::ListViewItemsDblClick(TObject *Sender)
{
	try {

		int officeId = StrToInt(ListViewItems->Selected->Caption);

		TFormOfficesActions *editForm = new TFormOfficesActions(this, TOfficesFormMode::Edit, officeId);
		if (editForm->ShowModal() == mrOk)
		{
			FillOffices();
		}
		delete editForm;

	} catch (...) {
		return;
	}
}

void __fastcall TFormOfficesView::ButtonDelClick(TObject *Sender)
{
	TListItem *selectedItem = ListViewItems->Selected;

	if (selectedItem == nullptr) { MessageDlg("Будь ласка, виберіть офіс для видалення!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	int officeId = StrToIntDef(selectedItem->Caption, -1);
	if (officeId == -1) { MessageDlg("Неможливо визначити ID офісу!", mtError, TMsgDlgButtons() << mbOK, 0); return; }

	if (ShowConfirmationDialog("Ви впевнені, що хочете видалити офіс - '" +  selectedItem->SubItems->Strings[0] + "'?", "Підтвердження видалення")) {

		DataBase->ADOQuery->SQL->Text = "DELETE FROM Offices WHERE id = " + IntToStr(officeId);

		try {

			DataBase->ADOQuery->ExecSQL();
			MessageDlg("Офіс успішно видалено!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

			FillOffices();

		} catch (const Exception &E) {
			MessageDlg("Помилка при видаленні офісу: " + E.Message, mtInformation, TMsgDlgButtons() << mbOK, 0);
		}
	}
}
//---------------------------------------------------------------------------
