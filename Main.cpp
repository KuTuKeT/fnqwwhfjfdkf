//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormShow(TObject *Sender)
{
	TFormLogin *loginForm = new TFormLogin(this);
	if (loginForm->ShowModal() != mrOk) {
		this->Close();
	} else {
		user = loginForm->user;
		LabelUser->Caption = "Співробітник - " + user.name;
		LabelRole->Caption = "Роль - " + user.role_name;
	}
	delete loginForm;

	switch (user.access) {

		case 1:  // A
			TabSheetO->TabVisible = true;
			TabSheetT->TabVisible = true;
			TabSheetF->TabVisible = true;
			TabSheetC->TabVisible = true;
			TabSheetA->TabVisible = true;
			break;

		case 2: // O
			TabSheetO->TabVisible = true;
			break;

		case 3: //T
			TabSheetT->TabVisible = true;
			break;

		case 4: //F
			TabSheetF->TabVisible = true;
			break;

		case 5: //C
			TabSheetC->TabVisible = true;
			break;

		default:
			break;
	}

	PageControl->ActivePage = TabSheetOR;
	Reset(this->PageControl->ActivePage);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ButtonFAQClick(TObject *Sender)
{
	TFormFAQ *FAQForm = new TFormFAQ(this);
	FAQForm->ShowModal();
	delete FAQForm;
}

void __fastcall TFormMain::ButtonExitClick(TObject *Sender)
{
	this->Close();
}

void __fastcall TFormMain::ButtonConfirmClick(TObject *Sender)
{
	Fill(this->PageControl->ActivePage);
}

void __fastcall TFormMain::ButtonClearClick(TObject *Sender)
{
	Reset(this->PageControl->ActivePage);
	Fill(this->PageControl->ActivePage);
}

void __fastcall TFormMain::PageControlChange(TObject *Sender)
{
	Reset(this->PageControl->ActivePage);
	Fill(this->PageControl->ActivePage);
}

void __fastcall TFormMain::ListViewClick(TObject *Sender)
{
	TTabSheet *activeTab = PageControl->ActivePage;
	TListItem *item = (activeTab == TabSheetOR) ? ListViewOrdersOR->Selected : ListViewCallsF->Selected;
	TListView *list = (activeTab == TabSheetOR) ? ListViewProductsOR : ListViewProductsF;

	if (item != nullptr)
	{
		int orderId = (activeTab == TabSheetOR) ? StrToInt(item->Caption) : StrToInt(item->SubItems->Strings[0]);

		DataBase->ADOQuery->SQL->Text = "SELECT OrderItems.id, Products.name AS product_name, ProductTypes.name AS group_name, "
		  "Products.price, OrderItems.quantity "
		  "FROM OrderItems "
		  "LEFT JOIN Products ON OrderItems.product_id = Products.id "
		  "LEFT JOIN ProductTypes ON Products.type_id = ProductTypes.id "
		"WHERE OrderItems.order_id = " + IntToStr(orderId) + " ORDER BY ProductTypes.id ASC, Products.id ASC";

		try {
			DataBase->ADOQuery->Open();

			list->Items->Clear();

			while (!DataBase->ADOQuery->Eof)
			{
				TListItem *item = list->Items->Add();

				item->Caption = DataBase->ADOQuery->FieldByName("product_name")->AsString;
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("group_name")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("price")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("quantity")->AsString);

				DataBase->ADOQuery->Next();
			}

			DataBase->ADOQuery->Close();

		} catch (const Exception &E) {
			MessageDlg("Помилка при отриманні списку товарів до замовлення: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		}
	}
}

void __fastcall TFormMain::ListViewDblClick(TObject *Sender)
{
	auto CheckCall = [&](int callId, String orderStatus) -> bool {
		DataBase->ADOQuery->SQL->Text = "SELECT employee_id, status FROM Calls WHERE id = " + IntToStr(callId) + " AND order_status = '" + orderStatus + "'";
		DataBase->ADOQuery->Open();

		bool assigned = DataBase->ADOQuery->FieldByName("employee_id")->IsNull;
		bool notClosed = DataBase->ADOQuery->FieldByName("status")->AsString != "Закритий" && DataBase->ADOQuery->FieldByName("status")->AsString != "В роботі";

		DataBase->ADOQuery->Close();
	 	return assigned && notClosed;
	};

	auto AcceptCall = [&](int callId, String orderStatus) {
		DataBase->ADOQuery->SQL->Text = "UPDATE Calls SET status = 'В роботі', employee_id = " + IntToStr(user.id) + " WHERE id = " + IntToStr(callId) + " AND order_status = '" + orderStatus + "'";
		DataBase->ADOQuery->ExecSQL();
	};

	auto CloseCall = [&](int callId, String comment, String orderStatus) {
		DataBase->ADOQuery->SQL->Text = "UPDATE Calls SET status = 'Закритий', comment = '" + comment + "' WHERE id = " + IntToStr(callId) + " AND order_status = '" + orderStatus + "'";
		DataBase->ADOQuery->ExecSQL();
	};

	auto CreateCall = [&](int orderId, String orderStatus) {
		DataBase->ADOQuery->SQL->Text = "INSERT INTO Calls (order_id, status, order_status) VALUES (" + IntToStr(orderId) + ", 'Новий', '" + orderStatus + "')";
		DataBase->ADOQuery->ExecSQL();
	};

	auto DropCall = [&](int callId, String orderStatus) {
		DataBase->ADOQuery->SQL->Text = "UPDATE Calls SET status = 'Новий', employee_id = NULL WHERE id = " + IntToStr(callId) + " AND order_status = '" + orderStatus + "'";
		DataBase->ADOQuery->ExecSQL();
	};

	auto ShowNote = [&](int orderId, int emplId) {
		TFormNotes *formNotes = new TFormNotes(this, orderId, emplId);
		formNotes->ShowModal();
		delete formNotes;
	};

	auto AddNote = [&](int orderId, int emplId, String text) {
		TDateTime currentDate = Date();
		TDateTime currentTime = Time();

		DataBase->ADOQuery->SQL->Text = "INSERT INTO Notes (order_id, empl_id, note_date, note_time, note) VALUES "
			"('" + IntToStr(orderId) + "', '" + IntToStr(emplId) + "', '" + FormatDateTime("yyyy-mm-dd", currentDate) + "', '" + FormatDateTime("hh:nn:ss", currentTime) + "', '" + text + "')";

		DataBase->ADOQuery->ExecSQL();
	};

	TTabSheet *activeTab = PageControl->ActivePage;

	if (activeTab == TabSheetOR) // OR
	{
		if (Sender == ListViewOrdersOR) // OR
		{
			TListItem *item = ListViewOrdersOR->Selected;
			if (item == nullptr) { return; }

			TFormViewOR *formOR = new TFormViewOR(this, StrToInt(item->Caption), user.id);
			formOR->ShowModal();
			delete formOR;
		}
	}
	else if (activeTab == TabSheetO) // O
	{
		TListItem *item = ListViewCallsO->Selected;
		if (item == nullptr) { return; }

		int callId = StrToInt(item->Caption);
		if (CheckCall(callId, "На допрацюванні")) {
			AcceptCall(callId, "На допрацюванні");
		} else {
			ShowNote(StrToInt(item->SubItems->Strings[0]), user.id);
			return;
		}

		int orderId = StrToInt(item->SubItems->Strings[0]);
		TFormViewO *formO = new TFormViewO(this, orderId, user.id);

		int result = formO->ShowModal();
		if (result == mrOk) {

			CloseCall(callId, formO->comment, "На допрацюванні");
			CreateCall(orderId, "У телефонії");
			AddNote(orderId, user.id, "Дзвінок №" + IntToStr(callId) + " закритий: Допрацьовано | Статус замовлення - У телефонії\r\nКоментар: " + formO->comment);
			Fill(this->PageControl->ActivePage);

		} else if (result == mrRetry) {

			CloseCall(callId, formO->comment, "На допрацюванні");
			CreateCall(orderId, "Збирається");
			AddNote(orderId, user.id, "Дзвінок №" + IntToStr(callId) + " закритий: Допрацьовано | Статус замовлення - Збирається\r\nКоментар: " + formO->comment);
			Fill(this->PageControl->ActivePage);

		} else if (result == mrCancel) {

			DropCall(callId, "На допрацюванні");
		}

		delete formO;
	}
    else if (activeTab == TabSheetT) // T
	{
		TListItem *item = ListViewCallsT->Selected;
		if (item == nullptr) { return; }

		int callId = StrToInt(item->Caption);
		if (CheckCall(callId, "У телефонії")) {
			AcceptCall(callId, "У телефонії");
		} else {
			ShowNote(StrToInt(item->SubItems->Strings[0]), user.id);
            return;
		}

		int orderId = StrToInt(item->SubItems->Strings[0]);
		TFormViewT *formT = new TFormViewT(this, orderId, user.id);

		int result = formT->ShowModal();
		if (result == mrOk) {

			CloseCall(callId, formT->comment, "У телефонії");
			CreateCall(orderId, "Збирається");
			AddNote(orderId, user.id, "Дзвінок №" + IntToStr(callId) + " закритий: Замовлення підтвердженно | Статус замовлення - Збирається\r\nКоментар: " + formT->comment);
			Fill(this->PageControl->ActivePage);

		} else if (result == mrRetry) {

			CloseCall(callId, formT->comment, "У телефонії");
			CreateCall(orderId, "На допрацюванні");
			AddNote(orderId, user.id, "Дзвінок №" + IntToStr(callId) + " закритий: Замовлення відправлено на допрацювання | Статус замовлення - На допрацюванні\r\nКоментар: " + formT->comment);
			Fill(this->PageControl->ActivePage);

		} else if (result == mrCancel) {

			DropCall(callId, "У телефонії");
		}

		delete formT;
	}
	else if (activeTab == TabSheetF) // F
	{
		TListItem *item = ListViewCallsF->Selected;
		if (item == nullptr) { return; }

		int callId = StrToInt(item->Caption);
		if (CheckCall(callId, "Збирається")) {
			AcceptCall(callId, "Збирається");
		} else {
			ShowNote(StrToInt(item->SubItems->Strings[0]), user.id);
            return;
		}

		int orderId = StrToInt(item->SubItems->Strings[0]);
		TFormViewF *formF = new TFormViewF(this, orderId, user.id);

		int result = formF->ShowModal();
		if (result == mrOk) {

			CloseCall(callId, formF->comment, "Збирається");
			CreateCall(orderId, "На доставці");
			AddNote(orderId, user.id, "Дзвінок №" + IntToStr(callId) + " закритий: Замовлення зібрано | Статус замовлення - На доставці\r\nКоментар: " + formF->comment);
			Fill(this->PageControl->ActivePage);

		} else if (result == mrRetry) {

			CloseCall(callId, formF->comment, "Збирається");
			CreateCall(orderId, "На допрацюванні");
			AddNote(orderId, user.id, "Дзвінок №" + IntToStr(callId) + " закритий: Замовлення відправлено на допрацювання | Статус замовлення - На допрацюванні\r\nКоментар: " + formF->comment);
			Fill(this->PageControl->ActivePage);

		} else if (result == mrCancel) {

			DropCall(callId, "Збирається");
		}

		delete formF;
	}
	else if (activeTab == TabSheetC) // C
	{
		TListItem *item = ListViewCallsC->Selected;
		if (item == nullptr) { return; }

		int callId = StrToInt(item->Caption);
		if (CheckCall(callId, "На доставці")) {
			AcceptCall(callId, "На доставці");
		} else {
			ShowNote(StrToInt(item->SubItems->Strings[0]), user.id);
            return;
		}

		int orderId = StrToInt(item->SubItems->Strings[0]);
		TFormViewC *formC = new TFormViewC(this, orderId, user.id);

		int result = formC->ShowModal();
		if (result == mrOk) {

			CloseCall(callId, formC->comment, "На доставці");
			AddNote(orderId, user.id, "Дзвінок №" + IntToStr(callId) + " закритий: Доставка підтверджена | Статус замовлення - Виконаний\r\nКоментар: " + formC->comment);
			Fill(this->PageControl->ActivePage);

		} else if (result == mrRetry) {

			CloseCall(callId, formC->comment, "На доставці");
			CreateCall(orderId, "На допрацюванні");
			AddNote(orderId, user.id, "Дзвінок №" + IntToStr(callId) + " закритий: Доставка не підтверджена | Статус замовлення - На допрацюванні\r\nКоментар: " + formC->comment);
			Fill(this->PageControl->ActivePage);

		} else if (result == mrCancel) {

			DropCall(callId, "На доставці");
		}

		delete formC;
	}
}
//---------------------------------------------------------------------------
void TFormMain::Reset(TTabSheet *activeTab)
{
	if (activeTab == TabSheetOR) // OR
	{
		DateTimePicker_1OR->Date = Date();
		DateTimePicker_2OR->Date = Date();
		DateTimePicker_3OR->Time = TTime(0, 0, 0, 0);
		DateTimePicker_4OR->Time = TTime(23, 59, 0, 0);

		ComboBoxOrderStateOR->ItemIndex = 0;

		EditSearchOR->Text = "";
		ComboBoxSearchOR->ItemIndex = 0;

		FillOffices(ComboBoxChoiceOfficeOR);
	}
	else if (activeTab == TabSheetO) // O
	{
		DateTimePicker_1O->Date = Date();
		DateTimePicker_2O->Date = Date();
		DateTimePicker_3O->Time = TTime(0, 0, 0, 0);
		DateTimePicker_4O->Time = TTime(23, 59, 0, 0);

		ComboBoxCallStateO->ItemIndex = 0;

		EditSearchO->Text = "";
		ComboBoxSearchO->ItemIndex = 0;
	}
	else if (activeTab == TabSheetT) // T
	{
		DateTimePicker_1T->Date = Date();
		DateTimePicker_2T->Date = Date();
		DateTimePicker_3T->Time = TTime(0, 0, 0, 0);
		DateTimePicker_4T->Time = TTime(23, 59, 0, 0);

		ComboBoxCallStateT->ItemIndex = 0;

		EditSearchT->Text = "";
		ComboBoxSearchT->ItemIndex = 0;
	}
	else if (activeTab == TabSheetF) // F
	{
		DateTimePicker_1F->Date = Date();
		DateTimePicker_2F->Date = Date();

		FillOffices(ComboBoxChoiceOfficeF);
	}
	else if (activeTab == TabSheetC) // C
	{
		DateTimePicker_1C->Date = Date();
		DateTimePicker_2C->Date = Date();

		FillOffices(ComboBoxChoiceOfficeC);
	}
}

void TFormMain::Fill(TTabSheet *activeTab)
{
	if (activeTab == TabSheetOR) // OR
	{
		String sqlQuery = "SELECT Orders.id, Orders.status, "
		  "Orders.order_date, Orders.start_time, Orders.end_time, Offices.name AS office_name "
		  "FROM Orders "
		  "LEFT JOIN Offices ON Orders.office_id = Offices.id "
		"WHERE 1 = 1 ";

		// date
		String dateFrom = FormatDateTime("yyyy-mm-dd",  DateTimePicker_1OR->Date);
		String dateTo = FormatDateTime("yyyy-mm-dd", DateTimePicker_2OR->Date);
		sqlQuery += "AND Orders.order_date >= '" + dateFrom + "' AND Orders.order_date <= '" + dateTo + "' ";

		// time
		String timeFrom = FormatDateTime("hh:nn:ss", DateTimePicker_3OR->Time);
		String timeTo = FormatDateTime("hh:nn:ss", DateTimePicker_4OR->Time);
		sqlQuery += "AND Orders.start_time >= '" + timeFrom + "' AND Orders.end_time <= '" + timeTo + "' ";

		// office
		int officeId = GetOfficeID(ComboBoxChoiceOfficeOR);
		if (officeId > 0) { sqlQuery += "AND Orders.office_id = '" + IntToStr(officeId) + "' "; }

		// state
		int orderState = ComboBoxOrderStateOR->ItemIndex;
		if (orderState > 0) { sqlQuery += "AND Orders.status = '" + ComboBoxOrderStateOR->Text + "' "; }

		// search
		int searchFilterIndex = ComboBoxSearchOR->ItemIndex;
		String searchValue = EditSearchOR->Text.Trim();

		if (!searchValue.IsEmpty()) {
			switch (searchFilterIndex) {

				case 0: // Усі
					break;

				case 1: // ID замовлення
					int orderId;
					if (TryStrToInt(searchValue, orderId)) {
						sqlQuery += "AND Orders.id = '" + searchValue + "' ";
					} else {
						MessageDlg("Будь ласка, введіть коректний ID замовлення.", mtWarning, TMsgDlgButtons() << mbOK, 0);
						return;
					}
					break;

				case 2: // Тел. замовника
					sqlQuery += "AND Orders.customer_id IN (SELECT id FROM Customers WHERE phone LIKE '%" + searchValue + "%') ";
					break;

				case 3: // Тел. отримувача
					sqlQuery += "AND Orders.recipient_id IN (SELECT id FROM Recipients WHERE phone LIKE '%" + searchValue + "%') ";
					break;

				default:
					break;
			}
		}

		DataBase->ADOQuery->SQL->Text = sqlQuery += "ORDER BY Orders.order_date DESC, Orders.start_time DESC, Orders.id DESC";

		try {
			DataBase->ADOQuery->Open();

			ListViewOrdersOR->Items->Clear();

			while (!DataBase->ADOQuery->Eof)
			{
				TListItem *item = ListViewOrdersOR->Items->Add();

				item->Caption = DataBase->ADOQuery->FieldByName("id")->AsString;
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("order_date")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("start_time")->AsDateTime.FormatString("hh:nn") + " - " + DataBase->ADOQuery->FieldByName("end_time")->AsDateTime.FormatString("hh:nn"));
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("office_name")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("status")->AsString);

				DataBase->ADOQuery->Next();
			}

			DataBase->ADOQuery->Close();

		} catch (const Exception &E) {
			MessageDlg("Помилка при отриманні замовлень: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
			this->Close();
		}

        ListViewProductsOR->Clear();
	}
	else if (activeTab == TabSheetO) // O
	{
        String sqlQuery = "SELECT Calls.id, Calls.status, "
		  "Orders.id AS order_id, Orders.order_date, Orders.start_time, Orders.end_time, Offices.name AS office_name, "
		  "Recipients.name AS recipient_name, Customers.name AS customer_name "
		  "FROM Calls "
		  "LEFT JOIN Orders ON Calls.order_id = Orders.id "
		  "LEFT JOIN Offices ON Orders.office_id = Offices.id "
		  "LEFT JOIN Recipients ON Orders.recipient_id = Recipients.id "
		  "LEFT JOIN Customers ON Orders.customer_id = Customers.id "
		"WHERE Calls.order_status = 'На допрацюванні' ";

		// date
		String dateFrom = FormatDateTime("yyyy-mm-dd",  DateTimePicker_1O->Date);
		String dateTo = FormatDateTime("yyyy-mm-dd", DateTimePicker_2O->Date);
		sqlQuery += "AND Orders.order_date >= '" + dateFrom + "' AND Orders.order_date <= '" + dateTo + "' ";

		// time
		String timeFrom = FormatDateTime("hh:nn:ss", DateTimePicker_3O->Time);
		String timeTo = FormatDateTime("hh:nn:ss", DateTimePicker_4O->Time);
		sqlQuery += "AND Orders.start_time >= '" + timeFrom + "' AND Orders.end_time <= '" + timeTo + "' ";

		// status
		int callStatus = ComboBoxCallStateO->ItemIndex;
		if (callStatus > 0) { sqlQuery += "AND Calls.status = '" + ComboBoxCallStateO->Text + "' "; }

		// search
		int searchFilterIndex = ComboBoxSearchO->ItemIndex;
		String searchValue = EditSearchO->Text.Trim();

		if (!searchValue.IsEmpty()) {
			switch (searchFilterIndex) {

				case 0: // Усі
					break;

				case 1: // ID
					int callId;
					if (TryStrToInt(searchValue, callId)) {
						sqlQuery += "AND Calls.id = '" + searchValue + "' ";
					} else {
						MessageDlg("Будь ласка, введіть коректний ID дзвінка.", mtWarning, TMsgDlgButtons() << mbOK, 0);
						return;
					}
					break;

				case 2: // ID замовлення
					int orderId;
					if (TryStrToInt(searchValue, orderId)) {
						sqlQuery += "AND Orders.id = '" + searchValue + "' ";
					} else {
						MessageDlg("Будь ласка, введіть коректний ID замовлення.", mtWarning, TMsgDlgButtons() << mbOK, 0);
						return;
					}
					break;

				case 3: // Офіс
					sqlQuery += "AND Offices.name LIKE '%" + searchValue + "%' ";
					break;

				default:
					break;
			}
		}

		DataBase->ADOQuery->SQL->Text = sqlQuery += "ORDER BY Orders.order_date DESC, Orders.start_time DESC, Orders.id DESC";

		try {
			DataBase->ADOQuery->Open();

			ListViewCallsO->Items->Clear();

			while (!DataBase->ADOQuery->Eof)
			{
				TListItem *item = ListViewCallsO->Items->Add();

				item->Caption = DataBase->ADOQuery->FieldByName("id")->AsString;
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("order_id")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("order_date")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("start_time")->AsDateTime.FormatString("hh:nn") + " - " + DataBase->ADOQuery->FieldByName("end_time")->AsDateTime.FormatString("hh:nn"));
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("office_name")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("recipient_name")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("customer_name")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("status")->AsString);

				DataBase->ADOQuery->Next();
			}

			DataBase->ADOQuery->Close();

		} catch (const Exception &E) {
			MessageDlg("Помилка при отриманні дзвінків: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
			this->Close();
		}
	}
    else if (activeTab == TabSheetT) // T
	{
		String sqlQuery = "SELECT Calls.id, Calls.status, "
		  "Orders.id AS order_id, Orders.order_date, Orders.start_time, Orders.end_time, Offices.name AS office_name, "
		  "Recipients.name AS recipient_name, Customers.name AS customer_name "
		  "FROM Calls "
		  "LEFT JOIN Orders ON Calls.order_id = Orders.id "
		  "LEFT JOIN Offices ON Orders.office_id = Offices.id "
		  "LEFT JOIN Recipients ON Orders.recipient_id = Recipients.id "
		  "LEFT JOIN Customers ON Orders.customer_id = Customers.id "
		"WHERE Calls.order_status = 'У телефонії' ";

		// date
		String dateFrom = FormatDateTime("yyyy-mm-dd",  DateTimePicker_1T->Date);
		String dateTo = FormatDateTime("yyyy-mm-dd", DateTimePicker_2T->Date);
		sqlQuery += "AND Orders.order_date >= '" + dateFrom + "' AND Orders.order_date <= '" + dateTo + "' ";

		// time
		String timeFrom = FormatDateTime("hh:nn:ss", DateTimePicker_3T->Time);
		String timeTo = FormatDateTime("hh:nn:ss", DateTimePicker_4T->Time);
		sqlQuery += "AND Orders.start_time >= '" + timeFrom + "' AND Orders.end_time <= '" + timeTo + "' ";

		// status
		int callStatus = ComboBoxCallStateT->ItemIndex;
		if (callStatus > 0) { sqlQuery += "AND Calls.status = '" + ComboBoxCallStateT->Text + "' "; }

		// search
		int searchFilterIndex = ComboBoxSearchT->ItemIndex;
		String searchValue = EditSearchT->Text.Trim();

		if (!searchValue.IsEmpty()) {
			switch (searchFilterIndex) {

				case 0: // Усі
					break;

				case 1: // ID
					int callId;
					if (TryStrToInt(searchValue, callId)) {
						sqlQuery += "AND Calls.id = '" + searchValue + "' ";
					} else {
						MessageDlg("Будь ласка, введіть коректний ID дзвінка.", mtWarning, TMsgDlgButtons() << mbOK, 0);
						return;
					}
					break;

				case 2: // ID замовлення
					int orderId;
					if (TryStrToInt(searchValue, orderId)) {
						sqlQuery += "AND Orders.id = '" + searchValue + "' ";
					} else {
						MessageDlg("Будь ласка, введіть коректний ID замовлення.", mtWarning, TMsgDlgButtons() << mbOK, 0);
						return;
					}
					break;

				case 3: // Офіс
					sqlQuery += "AND Offices.name LIKE '%" + searchValue + "%' ";
					break;

				default:
					break;
			}
		}

		DataBase->ADOQuery->SQL->Text = sqlQuery += "ORDER BY Orders.order_date DESC, Orders.start_time DESC, Orders.id DESC";

		try {
			DataBase->ADOQuery->Open();

			ListViewCallsT->Items->Clear();

			while (!DataBase->ADOQuery->Eof)
			{
				TListItem *item = ListViewCallsT->Items->Add();

				item->Caption = DataBase->ADOQuery->FieldByName("id")->AsString;
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("order_id")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("order_date")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("start_time")->AsDateTime.FormatString("hh:nn") + " - " + DataBase->ADOQuery->FieldByName("end_time")->AsDateTime.FormatString("hh:nn"));
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("office_name")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("recipient_name")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("customer_name")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("status")->AsString);

				DataBase->ADOQuery->Next();
			}

			DataBase->ADOQuery->Close();

		} catch (const Exception &E) {
			MessageDlg("Помилка при отриманні дзвінків: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
			this->Close();
		}
	}
	else if (activeTab == TabSheetF) // F
	{
		String sqlQuery = "SELECT Calls.id, Calls.status, "
		  "Orders.id AS order_id, Offices.name AS office_name, Orders.order_date, Orders.start_time, Orders.end_time "
		  "FROM Calls "
		  "LEFT JOIN Orders ON Calls.order_id = Orders.id "
		  "LEFT JOIN Offices ON Orders.office_id = Offices.id "
		"WHERE Calls.order_status = 'Збирається' ";

		// office
		int officeId = GetOfficeID(ComboBoxChoiceOfficeF);
		if (officeId > 0) { sqlQuery += "AND Orders.office_id = '" + IntToStr(officeId) + "' "; }

		// date
		String dateFrom = FormatDateTime("yyyy-mm-dd",  DateTimePicker_1F->Date);
		String dateTo = FormatDateTime("yyyy-mm-dd", DateTimePicker_2F->Date);
		sqlQuery += "AND Orders.order_date >= '" + dateFrom + "' AND Orders.order_date <= '" + dateTo + "' ";

		// status
		int callStatus = ComboBoxCallStateF->ItemIndex;
		if (callStatus > 0) { sqlQuery += "AND Calls.status = '" + ComboBoxCallStateF->Text + "' "; }

		DataBase->ADOQuery->SQL->Text = sqlQuery += "ORDER BY Orders.order_date DESC, Orders.start_time DESC, Calls.id DESC";

		try {
			DataBase->ADOQuery->Open();

			ListViewCallsF->Items->Clear();

			while (!DataBase->ADOQuery->Eof)
			{
				TListItem *item = ListViewCallsF->Items->Add();

				item->Caption = DataBase->ADOQuery->FieldByName("id")->AsString;
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("order_id")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("order_date")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("start_time")->AsDateTime.FormatString("hh:nn") + " - " + DataBase->ADOQuery->FieldByName("end_time")->AsDateTime.FormatString("hh:nn"));
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("office_name")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("status")->AsString);

				DataBase->ADOQuery->Next();
			}

			DataBase->ADOQuery->Close();

		} catch (const Exception &E) {
			MessageDlg("Помилка при отриманні дзвінків: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
			this->Close();
		}

        ListViewProductsF->Clear();
	}
	else if (activeTab == TabSheetC) // C
	{
		String sqlQuery = "SELECT Calls.id, Calls.status, "
		  "Orders.id AS order_id, Orders.order_date, Orders.start_time, Orders.end_time, Orders.address, Recipients.name AS recipient_name "
		  "FROM Calls "
		  "LEFT JOIN Orders ON Calls.order_id = Orders.id "
		  "LEFT JOIN Recipients ON Orders.recipient_id = Recipients.id "
		"WHERE Calls.order_status = 'На доставці' ";

		// office
		int officeId = GetOfficeID(ComboBoxChoiceOfficeC);
		if (officeId > 0) { sqlQuery += "AND Orders.office_id = '" + IntToStr(officeId) + "' "; }

		// date
		String dateFrom = FormatDateTime("yyyy-mm-dd",  DateTimePicker_1C->Date);
		String dateTo = FormatDateTime("yyyy-mm-dd", DateTimePicker_2C->Date);
		sqlQuery += "AND Orders.order_date >= '" + dateFrom + "' AND Orders.order_date <= '" + dateTo + "' ";

		// status
		int callStatus = ComboBoxCallStateC->ItemIndex;
		if (callStatus > 0) { sqlQuery += "AND Calls.status = '" + ComboBoxCallStateC->Text + "' "; }

		DataBase->ADOQuery->SQL->Text = sqlQuery += "ORDER BY Orders.order_date DESC, Orders.start_time DESC, Calls.id DESC";

		try {
			DataBase->ADOQuery->Open();

			ListViewCallsC->Items->Clear();

			while (!DataBase->ADOQuery->Eof)
			{
				TListItem *item = ListViewCallsC->Items->Add();

				item->Caption = DataBase->ADOQuery->FieldByName("id")->AsString;
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("order_id")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("order_date")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("start_time")->AsDateTime.FormatString("hh:nn") + " - " + DataBase->ADOQuery->FieldByName("end_time")->AsDateTime.FormatString("hh:nn"));
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("status")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("recipient_name")->AsString);
				item->SubItems->Add(DataBase->ADOQuery->FieldByName("address")->AsString);

				DataBase->ADOQuery->Next();
			}

			DataBase->ADOQuery->Close();

		} catch (const Exception &E) {
			MessageDlg("Помилка при отриманні дзвінків: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
			this->Close();
		}
	}
}

void TFormMain::FillOffices(TComboBox *comboBox)
{
	comboBox->Items->Clear();

	int allIndex = comboBox->Items->Add("Усі");
	comboBox->Items->Objects[allIndex] = reinterpret_cast<TObject*>(0);

	DataBase->ADOQuery->SQL->Text = "SELECT id, name FROM Offices";

	try {

		DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof) {

			int office_id = DataBase->ADOQuery->FieldByName("id")->AsInteger;
            String office_name = DataBase->ADOQuery->FieldByName("name")->AsString;

			int index = comboBox->Items->Add(office_name);
            comboBox->Items->Objects[index] = reinterpret_cast<TObject*>(office_id);

			DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні офісів: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}

	comboBox->ItemIndex = 0;
}

int TFormMain::GetOfficeID(TComboBox *comboBox)
{
	int index = comboBox->ItemIndex;

    if (index != -1) {
		return reinterpret_cast<int>(comboBox->Items->Objects[index]);
	}

	return -1;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TFormMain::ButtonEmplsClick(TObject *Sender)
{
	TFormEmployeesView *emplsForm = new TFormEmployeesView(this);
	emplsForm->ShowModal();
	delete emplsForm;
}

void __fastcall TFormMain::ButtonCustomersClick(TObject *Sender)
{
	TFormCustomersView *customersForm = new TFormCustomersView(this);
	customersForm->ShowModal();
	delete customersForm;
}

void __fastcall TFormMain::ButtonRecipientsClick(TObject *Sender)
{
	TFormRecipientsView *recipientsForm = new TFormRecipientsView(this);
	recipientsForm->ShowModal();
	delete recipientsForm;
}

void __fastcall TFormMain::ButtonGroupsClick(TObject *Sender)
{
	TFormGroupsView *groupsForm = new TFormGroupsView(this);
	groupsForm->ShowModal();
	delete groupsForm;
}

void __fastcall TFormMain::ButtonProductsClick(TObject *Sender)
{
	TFormProductsView *groupsForm = new TFormProductsView(this);
	groupsForm->ShowModal();
	delete groupsForm;
}

void __fastcall TFormMain::ButtonOfficesClick(TObject *Sender)
{
	TFormOfficesView *officesForm = new TFormOfficesView(this);
	officesForm->ShowModal();
	delete officesForm;
}

void __fastcall TFormMain::ButtonWarehousesClick(TObject *Sender)
{
	TFormWarehousesView *warehousesForm = new TFormWarehousesView(this);
	warehousesForm->ShowModal();
	delete warehousesForm;
}
//-----------------------------------------------------------------------
void __fastcall TFormMain::ButtonReportClick(TObject *Sender)
{
	TFormReport *reportForm = new TFormReport(this);
	reportForm->ShowModal();
	delete reportForm;
}
//---------------------------------------------------------------------------
