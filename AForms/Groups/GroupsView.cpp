//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GroupsView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormGroupsView *FormGroupsView;
//---------------------------------------------------------------------------
__fastcall TFormGroupsView::TFormGroupsView(TComponent* Owner) : TForm(Owner)
{
	FillGroups();
}
//---------------------------------------------------------------------------
void TFormGroupsView::FillGroups()
{
	ListViewItems->Items->Clear();

	DataBase->ADOQuery->SQL->Text = "SELECT * FROM ProductTypes";

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
		MessageDlg("������� ��� �������� ������ ���� ������: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}

bool TFormGroupsView::ShowConfirmationDialog(String message, String caption)
{
	TForm* dialog = CreateMessageDialog(message, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo);

	dialog->Caption = caption;
	TButton* yesButton = static_cast<TButton*>(dialog->FindComponent("Yes"));
	TButton* noButton = static_cast<TButton*>(dialog->FindComponent("No"));

	if (yesButton) yesButton->Caption = "���";
	if (noButton) noButton->Caption = "ͳ";

    return (dialog->ShowModal() == mrYes);
}
//---------------------------------------------------------------------------
void __fastcall TFormGroupsView::ButtonAddClick(TObject *Sender)
{
	TFormGroupsActions *addForm = new TFormGroupsActions(this, TGroupsFormMode::Add);
	if (addForm->ShowModal() == mrOk)
	{
		FillGroups();
	}
	delete addForm;
}

void __fastcall TFormGroupsView::ListViewItemsDblClick(TObject *Sender)
{
	try {

		int groupId = StrToInt(ListViewItems->Selected->Caption);

		TFormGroupsActions *editForm = new TFormGroupsActions(this, TGroupsFormMode::Edit, groupId);
		if (editForm->ShowModal() == mrOk)
		{
			FillGroups();
		}
		delete editForm;

	} catch (...) {
		return;
	}
}

void __fastcall TFormGroupsView::ButtonDelClick(TObject *Sender)
{
	TListItem *selectedItem = ListViewItems->Selected;

	if (selectedItem == nullptr) { MessageDlg("���� �����, ������� ����� ������ ��� ���������!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	int groupId = StrToIntDef(selectedItem->Caption, -1);
	if (groupId == -1) { MessageDlg("��������� ��������� ID ����� ������!", mtError, TMsgDlgButtons() << mbOK, 0); return; }

	if (ShowConfirmationDialog("�� �������, �� ������ �������� ����� ������ - '" +  selectedItem->SubItems->Strings[0] + "'?", "ϳ����������� ���������")) {

		DataBase->ADOQuery->SQL->Text = "DELETE FROM ProductTypes WHERE id = " + IntToStr(groupId);

		try {

			DataBase->ADOQuery->ExecSQL();
			MessageDlg("����� ������ ������ ��������!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

			FillGroups();

		} catch (const Exception &E) {
			MessageDlg("������� ��� �������� ����� ������: " + E.Message, mtInformation, TMsgDlgButtons() << mbOK, 0);
		}
	}
}
//---------------------------------------------------------------------------
