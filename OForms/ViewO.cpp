//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ViewO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormViewO *FormViewO;
//---------------------------------------------------------------------------
__fastcall TFormViewO::TFormViewO(TComponent* Owner, int orderId, int emplId) : TForm(Owner), orderId(orderId), emplId(emplId)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormViewO::FormShow(TObject *Sender)
{
	this->Caption = "Обробка амовлення: №" + IntToStr(orderId);

	FillRecipients();
	LoadOrder();
	LoadProducts();
}
//---------------------------------------------------------------------------
void TFormViewO::LoadOrder()
{
	DataBase->ADOQuery->SQL->Text = "SELECT Orders.id, Orders.status, Orders.order_date, Orders.start_time, Orders.end_time, Orders.office_id, Orders.comment, Orders.address, "
	  "Customers.name AS customer_name, Customers.phone AS customer_phone, Customers.balance AS customer_balance, "
	  "Recipients.id AS recipient_id "
	  "FROM Orders "
	  "LEFT JOIN Customers ON Orders.customer_id = Customers.id "
	  "LEFT JOIN Recipients ON Orders.recipient_id = Recipients.id "
	"WHERE Orders.id = " + IntToStr(orderId);

	try {
		DataBase->ADOQuery->Open();

		if (!DataBase->ADOQuery->IsEmpty())
		{
			LabeledEditID->Text = orderId;
			LabeledEditStatus->Text = DataBase->ADOQuery->FieldByName("status")->AsString;

			DatePicker->Date = DataBase->ADOQuery->FieldByName("order_date")->AsDateTime;
			StartTimePicker->Time = DataBase->ADOQuery->FieldByName("start_time")->AsDateTime;
			EndTimePicker->Time = DataBase->ADOQuery->FieldByName("end_time")->AsDateTime;

			MemoComment->Text = DataBase->ADOQuery->FieldByName("comment")->AsString;
			MemoAddress->Text = DataBase->ADOQuery->FieldByName("address")->AsString;

			LabeledEditCustomerName->Text = DataBase->ADOQuery->FieldByName("customer_name")->AsString;
			LabeledEditCustomerPhone->Text = DataBase->ADOQuery->FieldByName("customer_phone")->AsString;
			LabeledEditCustomerBalance->Text = DataBase->ADOQuery->FieldByName("customer_balance")->AsString;

			recipientId = DataBase->ADOQuery->FieldByName("recipient_id")->AsInteger;
			officeId =  DataBase->ADOQuery->FieldByName("office_id")->AsInteger;
			SetRecipientID(recipientId);
		}

		DataBase->ADOQuery->Close();

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні інформації замовлення: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}

void TFormViewO::LoadProducts()
{
	ListViewProducts->Clear();

	DataBase->ADOQuery->SQL->Text = "SELECT OrderItems.id, Products.name AS product_name, ProductTypes.name AS group_name, "
	  "OrderItems.price, OrderItems.quantity "
	  "FROM OrderItems "
	  "LEFT JOIN Products ON OrderItems.product_id = Products.id "
	  "LEFT JOIN ProductTypes ON Products.type_id = ProductTypes.id "
	"WHERE OrderItems.order_id = " + IntToStr(orderId) + " "
	"ORDER BY ProductTypes.id ASC, Products.id ASC";

	try {
		DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof)
		{
			TListItem *item = ListViewProducts->Items->Add();

			item->Caption = DataBase->ADOQuery->FieldByName("id")->AsString;
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("product_name")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("group_name")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("price")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("quantity")->AsString);

			DataBase->ADOQuery->Next();
		}

		DataBase->ADOQuery->Close();

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні списку товарів до замовлення: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}
//---------------------------------------------------------------------------
void TFormViewO::FillRecipients()
{
	ComboBoxChoiceRecipient->Items->Clear();

	DataBase->ADOQuery->SQL->Text = "SELECT id, name, phone FROM Recipients";

	try {

		DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof) {

			int id = DataBase->ADOQuery->FieldByName("id")->AsInteger;
			String str = DataBase->ADOQuery->FieldByName("phone")->AsString + " | " + DataBase->ADOQuery->FieldByName("name")->AsString;

			int index = ComboBoxChoiceRecipient->Items->Add(str);
			ComboBoxChoiceRecipient->Items->Objects[index] = reinterpret_cast<TObject*>(id);

			DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні списку отримувачів: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}

	ComboBoxChoiceRecipient->ItemIndex = 0;
}

int TFormViewO::GetRecipientID()
{
	int index = ComboBoxChoiceRecipient->ItemIndex;

    if (index != -1) {
		return reinterpret_cast<int>(ComboBoxChoiceRecipient->Items->Objects[index]);
	}

	return -1;
}

void TFormViewO::SetRecipientID(int recipientId)
{
	for (int i = 0; i < ComboBoxChoiceRecipient->Items->Count; i++) {
		if (reinterpret_cast<int>(ComboBoxChoiceRecipient->Items->Objects[i]) == recipientId) {
			ComboBoxChoiceRecipient->ItemIndex = i;
			return;
		}
	}

	ComboBoxChoiceRecipient->ItemIndex = -1;
}

bool TFormViewO::ShowConfirmationDialog(String message, String caption)
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
void __fastcall TFormViewO::ButtonAddRecipientClick(TObject *Sender)
{
	TFormRecipientsAddO *addForm = new TFormRecipientsAddO(this);
	if (addForm->ShowModal() == mrOk)
	{
		FillRecipients();
		SetRecipientID(recipientId);
	}
	delete addForm;
}

void __fastcall TFormViewO::ButtonAddProductClick(TObject *Sender)
{
	TFormProductAddO *addForm = new TFormProductAddO(this, orderId, officeId);
	if (addForm->ShowModal() == mrOk)
	{
		LoadProducts();
	}
	delete addForm;
}

void __fastcall TFormViewO::ButtonDelProductClick(TObject *Sender)
{
	TListItem *selectedItem = ListViewProducts->Selected;

	if (selectedItem == nullptr) { MessageDlg("Будь ласка, виберіть продукт для видалення!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	int itemId = StrToIntDef(selectedItem->Caption, -1);
	if (itemId == -1) { MessageDlg("Неможливо визначити ID продукту!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	int quantity = StrToIntDef(selectedItem->SubItems->Strings[3], -1);
	if (quantity == -1) { MessageDlg("Неможливо визначити кількість продукту для відновлення на склад!", mtWarning, TMsgDlgButtons() << mbOK, 0); return; }

	if (ShowConfirmationDialog("Ви впевнені, що хочете видалити продукт - '" +  selectedItem->SubItems->Strings[0] + "'?", "Підтвердження видалення")) {

		DataBase->ADOConnection->BeginTrans();

		try {

			DataBase->ADOQuery->SQL->Text = "SELECT office_id FROM Orders WHERE id = " + IntToStr(orderId);
			DataBase->ADOQuery->Open();
			int officeId = DataBase->ADOQuery->FieldByName("office_id")->AsInteger;
			DataBase->ADOQuery->Close();

			DataBase->ADOQuery->SQL->Text = "SELECT product_id FROM OrderItems WHERE id = " + IntToStr(itemId);
			DataBase->ADOQuery->Open();
			int productId = DataBase->ADOQuery->FieldByName("product_id")->AsInteger;
			DataBase->ADOQuery->Close();

			DataBase->ADOQuery->SQL->Text = "DELETE FROM OrderItems WHERE id = " + IntToStr(itemId);
			DataBase->ADOQuery->ExecSQL();

			DataBase->ADOQuery->SQL->Text = "UPDATE Warehouses SET quantity = quantity + " + IntToStr(quantity) + " WHERE product_id = " + IntToStr(productId) + " AND office_id = " + IntToStr(officeId);
			DataBase->ADOQuery->ExecSQL();

			DataBase->ADOConnection->CommitTrans();
			MessageDlg("Продукт успішно видалено, кількість на складі оновлено!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

			LoadProducts();

		} catch (const Exception &E) {
			DataBase->ADOConnection->RollbackTrans();
			MessageDlg("Помилка при видаленні продукту: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		}
	}
}

void __fastcall TFormViewO::ListViewProductsDblClick(TObject *Sender)
{
	try {

		int itemId = StrToInt(ListViewProducts->Selected->Caption);

		TFormProductEditO *editForm = new TFormProductEditO(this, itemId);
		if (editForm->ShowModal() == mrOk)
		{
			LoadProducts();
		}
		delete editForm;

	} catch (...) {
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormViewO::ButtonConfirmClick(TObject *Sender)
{
	comment = MemoCallComment->Text;
	int selectedState = ComboBoxCallState->ItemIndex;

	String status;
	if (selectedState == 0) { status = "У телефонії"; }
	else if (selectedState == 1) { status = "Збирається"; }
	else { ShowMessage("Будь ласка, оберіть коректний стан обробки!"); return; }

	DataBase->ADOQuery->SQL->Text = "UPDATE Orders SET status = '" + status + "', address = '" + MemoAddress->Text + "', recipient_id = '" + IntToStr(GetRecipientID()) + "', "
	  "order_date = '" + FormatDateTime("yyyy-mm-dd", DatePicker->Date) + "', start_time = '" + FormatDateTime("hh:nn:ss", StartTimePicker->Time) + "', end_time = '" + FormatDateTime("hh:nn:ss", EndTimePicker->Time) + "' "
	"WHERE id = " + IntToStr(orderId);

	try {
		DataBase->ADOQuery->ExecSQL();
		MessageDlg("Статус замовлення успішно оновлено!", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

		if (selectedState == 0) { ModalResult = mrOk; }
		else if (selectedState == 1) { ModalResult = mrRetry; }

    } catch (const Exception &E) {
		MessageDlg("Помилка при оновленні статусу замовлення: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		ModalResult = mrClose;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormViewO::ButtonNotesClick(TObject *Sender)
{
	TFormNotes *formNotes = new TFormNotes(this, orderId, emplId);
	formNotes->ShowModal();
	delete formNotes;
}
//---------------------------------------------------------------------------

