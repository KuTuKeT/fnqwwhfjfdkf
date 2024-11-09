//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ViewOR.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormViewOR *FormViewOR;
//---------------------------------------------------------------------------
__fastcall TFormViewOR::TFormViewOR(TComponent* Owner, int orderId, int emplId) : TForm(Owner), orderId(orderId), emplId(emplId)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormViewOR::FormShow(TObject *Sender)
{
	this->Caption = "Замовлення: №" + IntToStr(orderId);
	LoadOrder();
}
//---------------------------------------------------------------------------
void TFormViewOR::LoadOrder()
{
	//info
	DataBase->ADOQuery->SQL->Text = "SELECT Orders.id, Orders.status, Orders.order_date, Orders.start_time, Orders.end_time, Orders.comment, Orders.address, "
	  "Customers.name AS customer_name, Customers.phone AS customer_phone, Customers.balance AS customer_balance, "
	  "Recipients.name AS recipient_name, Recipients.phone AS recipient_phone "
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
			LabeledEditDateTime->Text = FormatDateTime("dd-mm-yyyy", DataBase->ADOQuery->FieldByName("order_date")->AsDateTime) + " | " +
				FormatDateTime("hh:nn", DataBase->ADOQuery->FieldByName("start_time")->AsDateTime) + "-" + FormatDateTime("hh:nn", DataBase->ADOQuery->FieldByName("end_time")->AsDateTime);
			MemoComment->Text = DataBase->ADOQuery->FieldByName("comment")->AsString;
			MemoAddress->Text = DataBase->ADOQuery->FieldByName("address")->AsString;

			LabeledEditCustomerName->Text = DataBase->ADOQuery->FieldByName("customer_name")->AsString;
			LabeledEditCustomerPhone->Text = DataBase->ADOQuery->FieldByName("customer_phone")->AsString;
			LabeledEditCustomerBalance->Text = DataBase->ADOQuery->FieldByName("customer_balance")->AsString;

			LabeledEditRecipientName->Text = DataBase->ADOQuery->FieldByName("recipient_name")->AsString;
			LabeledEditRecipientPhone->Text = DataBase->ADOQuery->FieldByName("recipient_phone")->AsString;
		}

		DataBase->ADOQuery->Close();

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні інформації замовлення: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
        this->Close();
	}

	//products
	DataBase->ADOQuery->SQL->Text = "SELECT OrderItems.id, Products.name AS product_name, ProductTypes.name AS group_name, "
	  "Products.price, OrderItems.quantity "
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

			item->Caption = DataBase->ADOQuery->FieldByName("product_name")->AsString;
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

	//calls
	DataBase->ADOQuery->SQL->Text = "SELECT Calls.id, Calls.status, Calls.comment, "
	  "Employees.name AS employee_name "
	  "FROM Calls "
	  "LEFT JOIN Orders ON Calls.order_id = Orders.id "
	  "LEFT JOIN Employees ON Calls.employee_id = Employees.id "
	"WHERE Calls.order_id = " + IntToStr(orderId) + " "
	"ORDER BY Calls.status ASC";

	try {
		DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof)
		{
			TListItem *item = ListViewCalls->Items->Add();

			item->Caption = DataBase->ADOQuery->FieldByName("id")->AsString;
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("status")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("employee_name")->AsString);
			item->SubItems->Add(DataBase->ADOQuery->FieldByName("comment")->AsString);

			DataBase->ADOQuery->Next();
		}

		DataBase->ADOQuery->Close();

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні дзвінків замовлення: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormViewOR::ButtonNotesClick(TObject *Sender)
{
	TFormNotes *formNotes = new TFormNotes(this, orderId, emplId);
	formNotes->ShowModal();
	delete formNotes;
}
//---------------------------------------------------------------------------

