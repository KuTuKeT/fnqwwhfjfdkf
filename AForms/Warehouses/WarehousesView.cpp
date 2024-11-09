//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "WarehousesView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormWarehousesView *FormWarehousesView;
//---------------------------------------------------------------------------
__fastcall TFormWarehousesView::TFormWarehousesView(TComponent* Owner) : TForm(Owner)
{
	FillOffices();
	FillWarehouses();
}
//---------------------------------------------------------------------------
void TFormWarehousesView::FillOffices()
{
	ComboBoxChoiceOffice->Items->Clear();

	DataBase->ADOQuery->SQL->Text = "SELECT id, name FROM Offices";

	try {

		DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof) {

			int office_id = DataBase->ADOQuery->FieldByName("id")->AsInteger;
			String office_title = DataBase->ADOQuery->FieldByName("name")->AsString;

			int index = ComboBoxChoiceOffice->Items->Add(office_title);
			ComboBoxChoiceOffice->Items->Objects[index] = reinterpret_cast<TObject*>(office_id);

			DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("������� ��� �������� �����: " + E.Message, mtInformation, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}

	ComboBoxChoiceOffice->ItemIndex = 0;
}

void TFormWarehousesView::FillWarehouses()
{
	ListViewItems->Items->Clear();

	String sqlText = "SELECT Warehouses.id, Warehouses.quantity, Products.name AS product_name, Products.price AS product_price, ProductTypes.name AS group_name "
	  "FROM Warehouses LEFT JOIN Products ON Warehouses.product_id = Products.id LEFT JOIN ProductTypes ON Products.type_id = ProductTypes.id";

	int officeId = GetOfficeID();
	if (officeId > 0) {
		sqlText += " WHERE Warehouses.office_id = " + IntToStr(officeId);
	}

	DataBase->ADOQuery->SQL->Text = sqlText;

	try {

        DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof)
		{
			TListItem *item = ListViewItems->Items->Add();

            item->Caption = DataBase->ADOQuery->FieldByName("id")->AsString;
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("product_name")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("group_name")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("product_price")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("quantity")->AsString);

            DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("������� ��� �������� ������ ������ ������: " + E.Message, mtInformation, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}

int TFormWarehousesView::GetOfficeID()
{
	int index = ComboBoxChoiceOffice->ItemIndex;

	if (index != -1) {
		return reinterpret_cast<int>(ComboBoxChoiceOffice->Items->Objects[index]);
	}

	return -1;
}

bool TFormWarehousesView::ShowConfirmationDialog(String message, String caption)
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
void __fastcall TFormWarehousesView::ComboBoxChoiceOfficeChange(TObject *Sender)
{
	FillWarehouses();
}
//---------------------------------------------------------------------------
void __fastcall TFormWarehousesView::ButtonAddClick(TObject *Sender)
{
	TFormWarehousesActions *addForm = new TFormWarehousesActions(this, TWarehousesFormMode::Add);
	if (addForm->ShowModal() == mrOk)
	{
		FillWarehouses();
	}
	delete addForm;
}

void __fastcall TFormWarehousesView::ListViewItemsDblClick(TObject *Sender)
{
	try {

		int productId = StrToInt(ListViewItems->Selected->Caption);

		TFormWarehousesActions *editForm = new TFormWarehousesActions(this, TWarehousesFormMode::Edit, productId);
		if (editForm->ShowModal() == mrOk)
		{
			FillWarehouses();
		}
		delete editForm;

	} catch (...) {
		return;
	}
}

void __fastcall TFormWarehousesView::ButtonDelClick(TObject *Sender)
{
	TListItem *selectedItem = ListViewItems->Selected;

	if (selectedItem == nullptr) { MessageDlg("���� �����, ������� ����� ��� ���������!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	int productId = StrToIntDef(selectedItem->Caption, -1);
	if (productId == -1) { MessageDlg("��������� ��������� ID ������!", mtError, TMsgDlgButtons() << mbOK, 0); return; }

	if (ShowConfirmationDialog("�� �������, �� ������ �������� ����� - '" +  selectedItem->SubItems->Strings[0] + "' � ������?", "ϳ����������� ���������")) {

		DataBase->ADOQuery->SQL->Text = "DELETE FROM Warehouses WHERE id = " + IntToStr(productId);

		try {

			DataBase->ADOQuery->ExecSQL();
			MessageDlg("������� ������ �������� � ������!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

			FillWarehouses();

		} catch (const Exception &E) {
			MessageDlg("������� ��� �������� �������� � ������: " + E.Message, mtInformation, TMsgDlgButtons() << mbOK, 0);
		}
	}
}
//---------------------------------------------------------------------------
