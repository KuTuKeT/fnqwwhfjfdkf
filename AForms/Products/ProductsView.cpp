//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProductsView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormProductsView *FormProductsView;
//---------------------------------------------------------------------------
__fastcall TFormProductsView::TFormProductsView(TComponent* Owner) : TForm(Owner)
{
	FillGroups();
	FillProducts();
}
//---------------------------------------------------------------------------
void TFormProductsView::FillGroups()
{
	ComboBoxChoiceGroup->Items->Clear();

	int allIndex = ComboBoxChoiceGroup->Items->Add("��");
	ComboBoxChoiceGroup->Items->Objects[allIndex] = reinterpret_cast<TObject*>(0);

	DataBase->ADOQuery->SQL->Text = "SELECT id, name FROM ProductTypes";

	try {

		DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof) {

			int group_id = DataBase->ADOQuery->FieldByName("id")->AsInteger;
			String group_title = DataBase->ADOQuery->FieldByName("name")->AsString;

			int index = ComboBoxChoiceGroup->Items->Add(group_title);
			ComboBoxChoiceGroup->Items->Objects[index] = reinterpret_cast<TObject*>(group_id);

			DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("������� ��� �������� ���� ������: " + E.Message, mtInformation, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}

	ComboBoxChoiceGroup->ItemIndex = 0;
}

void TFormProductsView::FillProducts()
{
	ListViewItems->Items->Clear();

	String sqlText = "SELECT Products.id, Products.name, Products.price, ProductTypes.name AS group_name "
		"FROM Products LEFT JOIN ProductTypes ON Products.type_id = ProductTypes.id";

	int groupId = GetGroupID();
	if (groupId > 0) {
		sqlText += " WHERE Products.type_id = " + IntToStr(groupId);
	}

	DataBase->ADOQuery->SQL->Text = sqlText;

	try {

        DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof)
		{
			TListItem *item = ListViewItems->Items->Add();

            item->Caption = DataBase->ADOQuery->FieldByName("id")->AsString;
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("name")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("group_name")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("price")->AsString);

            DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("������� ��� �������� ������ ������: " + E.Message, mtInformation, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}

int TFormProductsView::GetGroupID()
{
	int index = ComboBoxChoiceGroup->ItemIndex;

	if (index != -1) {
		return reinterpret_cast<int>(ComboBoxChoiceGroup->Items->Objects[index]);
	}

	return -1;
}

bool TFormProductsView::ShowConfirmationDialog(String message, String caption)
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
void __fastcall TFormProductsView::ComboBoxChoiceGroupChange(TObject *Sender)
{
	FillProducts();
}
//---------------------------------------------------------------------------
void __fastcall TFormProductsView::ButtonAddClick(TObject *Sender)
{
	TFormProductsActions *addForm = new TFormProductsActions(this, TProductsFormMode::Add);
	if (addForm->ShowModal() == mrOk)
	{
		FillProducts();
	}
	delete addForm;
}

void __fastcall TFormProductsView::ListViewItemsDblClick(TObject *Sender)
{
	try {

		int productId = StrToInt(ListViewItems->Selected->Caption);

		TFormProductsActions *editForm = new TFormProductsActions(this, TProductsFormMode::Edit, productId);
		if (editForm->ShowModal() == mrOk)
		{
			FillProducts();
		}
		delete editForm;

	} catch (...) {
		return;
	}
}

void __fastcall TFormProductsView::ButtonDelClick(TObject *Sender)
{
	TListItem *selectedItem = ListViewItems->Selected;

	if (selectedItem == nullptr) { MessageDlg("���� �����, ������� ����� ��� ���������!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	int productId = StrToIntDef(selectedItem->Caption, -1);
	if (productId == -1) { MessageDlg("��������� ��������� ID ������!", mtError, TMsgDlgButtons() << mbOK, 0); return; }

	if (ShowConfirmationDialog("�� �������, �� ������ �������� ����� - '" +  selectedItem->SubItems->Strings[0] + "'?", "ϳ����������� ���������")) {

		DataBase->ADOQuery->SQL->Text = "DELETE FROM Products WHERE id = " + IntToStr(productId);

		try {

			DataBase->ADOQuery->ExecSQL();
			MessageDlg("������� ������ ��������!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

			FillProducts();

		} catch (const Exception &E) {
			MessageDlg("������� ��� �������� ��������: " + E.Message, mtInformation, TMsgDlgButtons() << mbOK, 0);
		}
	}
}
//---------------------------------------------------------------------------
