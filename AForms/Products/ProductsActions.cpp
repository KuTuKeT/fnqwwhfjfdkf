//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProductsActions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormProductsActions *FormProductsActions;
//---------------------------------------------------------------------------
__fastcall TFormProductsActions::TFormProductsActions(TComponent* Owner, TProductsFormMode mode, int productId)
	: TForm(Owner), mode(mode), productId(productId)
{
	FillGroups();

	if (mode == TProductsFormMode::Add) {
		ButtonAction->Caption = "������";
		this->Caption = "���������";
    } else {
		ButtonAction->Caption = "����������";
		this->Caption = "�����������";
		LoadProductData();
	}
}
//---------------------------------------------------------------------------
void TFormProductsActions::LoadProductData()
{
	DataBase->ADOQuery->SQL->Text = "SELECT * FROM Products WHERE id = " + IntToStr(productId);

	try {

		DataBase->ADOQuery->Open();

		if (!DataBase->ADOQuery->Eof) {

			LabeledEditName->Text = DataBase->ADOQuery->FieldByName("name")->AsString;
			LabeledEditPrice->Text = DataBase->ADOQuery->FieldByName("price")->AsString;
			ComboBoxChoiceGroup->ItemIndex = DataBase->ADOQuery->FieldByName("type_id")->AsInteger - 1;
		}

	} catch (const Exception &E) {
		MessageDlg("������� ��� �������� ����� ��������: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}

void TFormProductsActions::FillGroups()
{
	ComboBoxChoiceGroup->Items->Clear();

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
		MessageDlg("������� ��� �������� ���� ������: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrNone;
	}

	ComboBoxChoiceGroup->ItemIndex = 0;
}

int TFormProductsActions::GetGroupID()
{
	int index = ComboBoxChoiceGroup->ItemIndex;

	if (index != -1) {
		return reinterpret_cast<int>(ComboBoxChoiceGroup->Items->Objects[index]);
	}

	return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormProductsActions::ButtonActionClick(TObject *Sender)
{
	String name = LabeledEditName->Text;
	String priceStr = LabeledEditPrice->Text;
	double price = 0.0;

	if (name.Trim().IsEmpty()) { MessageDlg("���� �����, ������ ����� ������!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	if (!priceStr.IsEmpty()) {

		try {
			price = StrToFloat(priceStr);
			priceStr = StringReplace(priceStr, ",", ".", TReplaceFlags() << rfReplaceAll);
		} catch (...) {
			MessageDlg("���� �����, ������ �������� �������� ����!", mtWarning, TMsgDlgButtons() << mbOK, 0);
            return;
		}
	} else {
		priceStr = "0.0";
	}

	int groupId = -1;
	if (ComboBoxChoiceGroup->ItemIndex != -1) { groupId = reinterpret_cast<int>(ComboBoxChoiceGroup->Items->Objects[ComboBoxChoiceGroup->ItemIndex]); }
	if (groupId == 0 || groupId == -1) { MessageDlg("���� �����, ������ ����� ������!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	if (mode == TProductsFormMode::Add) {
		DataBase->ADOQuery->SQL->Text = "INSERT INTO Products (name, price, type_id) VALUES "
			"('" + name + "', '" + priceStr + "', '" + IntToStr(groupId) + "')";
    } else {
        DataBase->ADOQuery->SQL->Text = "UPDATE Products SET "
			"name = '" + name + "', price = '" + priceStr + "', type_id = '" + IntToStr(GetGroupID()) + "' WHERE id = " + IntToStr(productId);
	}

	try {

		DataBase->ADOQuery->ExecSQL();

		MessageDlg(mode == TProductsFormMode::Add ? "����� ������ �������!" : "��� ������ ������ ��������!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrOk;

	} catch (const Exception &E) {
		MessageDlg((mode == TProductsFormMode::Add ? "������� ��� �������� ������: " : "������� ��� ��������� ����� ������: ") + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}

void __fastcall TFormProductsActions::ButtonCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
