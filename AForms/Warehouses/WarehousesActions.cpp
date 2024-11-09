//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "WarehousesActions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormWarehousesActions *FormWarehousesActions;
//---------------------------------------------------------------------------
__fastcall TFormWarehousesActions::TFormWarehousesActions(TComponent* Owner, TWarehousesFormMode mode, int itemId)
	: TForm(Owner), mode(mode), itemId(itemId)
{
	FillItems(ComboBoxChoiceProduct, TWarehousesFillItemsType::Products);
	FillItems(ComboBoxChoiceOffice, TWarehousesFillItemsType::Offices);

	if (mode == TWarehousesFormMode::Add) {
		ButtonAction->Caption = "Додати";
		this->Caption = "Додавання";
    } else {
		ButtonAction->Caption = "Редагувати";
		this->Caption = "Редагування";
		LoadItemsData();
	}
}
//---------------------------------------------------------------------------
void TFormWarehousesActions::LoadItemsData()
{
	DataBase->ADOQuery->SQL->Text = "SELECT * FROM Warehouses WHERE id = " + IntToStr(itemId);

	try {

		DataBase->ADOQuery->Open();

		if (!DataBase->ADOQuery->Eof) {

			ComboBoxChoiceProduct->ItemIndex = DataBase->ADOQuery->FieldByName("product_id")->AsInteger - 1;
			ComboBoxChoiceOffice->ItemIndex = DataBase->ADOQuery->FieldByName("office_id")->AsInteger - 1;
			LabeledEditQuantity->Text = DataBase->ADOQuery->FieldByName("quantity")->AsString;
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні даних продукту зі складу: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}

void TFormWarehousesActions::FillItems(TComboBox *comboBox, TWarehousesFillItemsType type)
{
	comboBox->Items->Clear();

	switch (type) {

		case TWarehousesFillItemsType::Offices:
			DataBase->ADOQuery->SQL->Text = "SELECT id, name FROM Offices";
			break;

		case TWarehousesFillItemsType::Products:
			DataBase->ADOQuery->SQL->Text = "SELECT id, name FROM Products";
			break;
	}

	try {

		DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof) {

			int group_id = DataBase->ADOQuery->FieldByName("id")->AsInteger;
			String group_title = DataBase->ADOQuery->FieldByName("name")->AsString;

			int index = comboBox->Items->Add(group_title);
			comboBox->Items->Objects[index] = reinterpret_cast<TObject*>(group_id);

			DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при заповненні даних: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrNone;
	}

	comboBox->ItemIndex = 0;
}

int TFormWarehousesActions::GetItemID(TComboBox *comboBox)
{
	int index = comboBox->ItemIndex;

	if (index != -1) {
		return reinterpret_cast<int>(comboBox->Items->Objects[index]);
	}

	return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormWarehousesActions::ButtonActionClick(TObject *Sender)
{
	int officeId = -1;
	if (ComboBoxChoiceOffice->ItemIndex != -1) { officeId = reinterpret_cast<int>(ComboBoxChoiceOffice->Items->Objects[ComboBoxChoiceOffice->ItemIndex]); }
	if (officeId == 0 || officeId == -1) { MessageDlg("Будь ласка, оберіть офіс.", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	int productId = -1;
	if (ComboBoxChoiceProduct->ItemIndex != -1) { productId = reinterpret_cast<int>(ComboBoxChoiceProduct->Items->Objects[ComboBoxChoiceProduct->ItemIndex]); }
	if (productId == 0 || productId == -1) { MessageDlg("Будь ласка, оберіть товар.", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	String quantity = LabeledEditQuantity->Text;
	if (quantity.Trim().IsEmpty()) { MessageDlg("Будь ласка, введіть кількість товару на складі!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	DataBase->ADOQuery->SQL->Text = "SELECT COUNT(*) AS count FROM Warehouses WHERE office_id = " + IntToStr(officeId) + " AND product_id = " + IntToStr(productId);
	DataBase->ADOQuery->Open();
	int count = DataBase->ADOQuery->FieldByName("count")->AsInteger;
	DataBase->ADOQuery->Close();
	if (count > 0 && mode == TWarehousesFormMode::Add) { MessageDlg("Товар вже доданий на склад для вибраного офісу.", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	if (mode == TWarehousesFormMode::Add) {
		DataBase->ADOQuery->SQL->Text = "INSERT INTO Warehouses (quantity, office_id, product_id) VALUES "
			"('" + quantity + "', '" + IntToStr(officeId) + "', '" + IntToStr(productId) + "')";
	} else {
		DataBase->ADOQuery->SQL->Text = "UPDATE Warehouses SET "
			"quantity = '" + quantity + "', office_id = '" + IntToStr(officeId) + "', product_id = '" + IntToStr(productId) + "' WHERE id = " + IntToStr(itemId);
	}

	try {

		DataBase->ADOQuery->ExecSQL();

		MessageDlg(mode == TWarehousesFormMode::Add ? "Товар успішно доданий на склад!" : "Дані товару на складі успішно оновлено!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrOk;

	} catch (const Exception &E) {
		MessageDlg((mode == TWarehousesFormMode::Add ? "Помилка при додаванні товару на склад: " : "Помилка при збереженні даних товару на складі: ") + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}

void __fastcall TFormWarehousesActions::ButtonCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
