//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Report.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormReport *FormReport;
//---------------------------------------------------------------------------
__fastcall TFormReport::TFormReport(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormReport::FormShow(TObject *Sender)
{
	PageControl->ActivePage = TabSheetOrders;
	Reset(this->PageControl->ActivePage);
}
//---------------------------------------------------------------------------
void __fastcall TFormReport::ButtonClearClick(TObject *Sender)
{
	Reset(this->PageControl->ActivePage);
}

void __fastcall TFormReport::PageControlChange(TObject *Sender)
{
	Reset(this->PageControl->ActivePage);
}
//---------------------------------------------------------------------------
void TFormReport::Reset(TTabSheet *activeTab)
{
	if (activeTab == TabSheetOrders) // OR
	{
		DateTimePicker_1OR->Time = TTime(0, 0, 0, 0);
		DateTimePicker_2OR->Time = TTime(23, 59, 0, 0);
		DateTimePicker_3OR->Date = Date();
		DateTimePicker_4OR->Date = Date();

		ComboBoxChoiceOfficeOR->ItemIndex = 0;
		ComboBoxOrderStateOR->ItemIndex = 0;

		ComboBoxChoiceProductOR->ItemIndex = -1;
		ComboBoxChoiceProductGroupOR->ItemIndex = 0;
		ComboBoxChoiceCustomerOR->ItemIndex = 0;
		ComboBoxChoiceRecipientOR->ItemIndex = 0;
		ComboBoxChoiceProductFilterOR->ItemIndex = 0;
		ComboBoxChoiceProductOR->Items->Clear();

		FillItems(ComboBoxChoiceOfficeOR, TFillItemsType::Offices);
		FillItems(ComboBoxChoiceProductGroupOR, TFillItemsType::Groups);
		FillItems(ComboBoxChoiceCustomerOR, TFillItemsType::Customers);
		FillItems(ComboBoxChoiceRecipientOR, TFillItemsType::Recipients);
	}
	else if (activeTab == TabSheetCalls) // T
	{
		DateTimePicker_1C->Time = TTime(0, 0, 0, 0);
		DateTimePicker_2C->Time = TTime(23, 59, 0, 0);
		DateTimePicker_3C->Date = Date();
		DateTimePicker_4C->Date = Date();

		ComboBoxChoiceOfficeC->ItemIndex = 0;
		ComboBoxCallStateC->ItemIndex = 0;

		ComboBoxChoiceEmplC->ItemIndex = -1;
		ComboBoxChoiceEmplRoleC->ItemIndex = 0;
		ComboBoxChoiceEmplFilterC->ItemIndex = 0;
		ComboBoxChoiceEmplC->Items->Clear();

		FillItems(ComboBoxChoiceOfficeC, TFillItemsType::Offices);
		FillItems(ComboBoxChoiceEmplRoleC, TFillItemsType::Roles);
	}
}

void TFormReport::FillItems(TComboBox *comboBox, TFillItemsType type)
{
	comboBox->Items->Clear();

	int allIndex = comboBox->Items->Add("Усі");
	comboBox->Items->Objects[allIndex] = reinterpret_cast<TObject*>(0);

	switch (type) {

		case TFillItemsType::Offices:
			DataBase->ADOQuery->SQL->Text = "SELECT id, name FROM Offices";
			break;

		case TFillItemsType::Groups:
			DataBase->ADOQuery->SQL->Text = "SELECT id, name FROM ProductTypes";
			break;

		case TFillItemsType::Customers:
			DataBase->ADOQuery->SQL->Text = "SELECT id, name, phone FROM Customers";
			break;

		case TFillItemsType::Recipients:
			DataBase->ADOQuery->SQL->Text = "SELECT id, name, phone FROM Recipients";
			break;

		case TFillItemsType::Roles:
			DataBase->ADOQuery->SQL->Text = "SELECT id, title AS name FROM Roles";
			break;
	}

	try {

		DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof) {

			int id = DataBase->ADOQuery->FieldByName("id")->AsInteger;

			String str;
			if (type == TFillItemsType::Customers || type == TFillItemsType::Recipients) {
				str = DataBase->ADOQuery->FieldByName("phone")->AsString + " | " + DataBase->ADOQuery->FieldByName("name")->AsString;
			} else {
				str = DataBase->ADOQuery->FieldByName("name")->AsString;
			}

			int index = comboBox->Items->Add(str);
			comboBox->Items->Objects[index] = reinterpret_cast<TObject*>(id);

			DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при заповненні даних: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
        this->Close();
	}

	comboBox->ItemIndex = 0;
}

int TFormReport::GetItemID(TComboBox *comboBox)
{
	int index = comboBox->ItemIndex;

	if (index != -1) {
		return reinterpret_cast<int>(comboBox->Items->Objects[index]);
	}

	return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormReport::ComboBoxChoiceProductGroupORChange(TObject *Sender)
{
    int groupId = GetItemID(ComboBoxChoiceProductGroupOR);

	if (groupId == 0 || groupId == -1) {
        ComboBoxChoiceProductOR->Items->Clear();
        ComboBoxChoiceProductOR->Items->Add("Усі");
        ComboBoxChoiceProductOR->ItemIndex = 0;
        return;
    }

	ComboBoxChoiceProductOR->Items->Clear();
	int allIndex = ComboBoxChoiceProductOR->Items->Add("Усі");
	ComboBoxChoiceProductOR->Items->Objects[allIndex] = reinterpret_cast<TObject*>(0);

	DataBase->ADOQuery->SQL->Text = "SELECT id, name FROM Products WHERE type_id = " + IntToStr(groupId);

	try {

		DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof) {

			int id = DataBase->ADOQuery->FieldByName("id")->AsInteger;
			String name = DataBase->ADOQuery->FieldByName("name")->AsString;

			int index = ComboBoxChoiceProductOR->Items->Add(name);
			ComboBoxChoiceProductOR->Items->Objects[index] = reinterpret_cast<TObject*>(id);

            DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при заповненні товарів: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
	}

    ComboBoxChoiceProductOR->ItemIndex = 0;
}

void __fastcall TFormReport::ComboBoxChoiceEmplRoleCChange(TObject *Sender)
{
    int roleId = GetItemID(ComboBoxChoiceEmplRoleC);

	if (roleId == 0 || roleId == -1) {
        ComboBoxChoiceEmplC->Items->Clear();
        ComboBoxChoiceEmplC->Items->Add("Усі");
        ComboBoxChoiceEmplC->ItemIndex = 0;
        return;
    }

	ComboBoxChoiceEmplC->Items->Clear();
	int allIndex = ComboBoxChoiceEmplC->Items->Add("Усі");
	ComboBoxChoiceEmplC->Items->Objects[allIndex] = reinterpret_cast<TObject*>(0);

	DataBase->ADOQuery->SQL->Text = "SELECT id, name FROM Employees WHERE role_id = " + IntToStr(roleId);

	try {

		DataBase->ADOQuery->Open();

		while (!DataBase->ADOQuery->Eof) {

			int id = DataBase->ADOQuery->FieldByName("id")->AsInteger;
			String name = DataBase->ADOQuery->FieldByName("name")->AsString;

			int index = ComboBoxChoiceEmplC->Items->Add(name);
			ComboBoxChoiceEmplC->Items->Objects[index] = reinterpret_cast<TObject*>(id);

			DataBase->ADOQuery->Next();
		}

	} catch (const Exception &E) {
		MessageDlg("Помилка при заповненні співробітників: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		this->Close();
    }

	ComboBoxChoiceEmplC->ItemIndex = 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TFormReport::ButtonSaveORClick(TObject *Sender)
{
	String sqlQuery = "SELECT DISTINCT Orders.id, Orders.status, "
	  "Orders.order_date, Orders.start_time, Orders.end_time, Orders.address, Orders.comment, "
	  "Offices.name AS office_name, Recipients.name AS recipient_name, Customers.name AS customer_name "
	  "FROM Orders "
	  "LEFT JOIN Offices ON Orders.office_id = Offices.id "
	  "LEFT JOIN Recipients ON Orders.recipient_id = Recipients.id "
	  "LEFT JOIN Customers ON Orders.customer_id = Customers.id "
	  "LEFT JOIN OrderItems ON Orders.id = OrderItems.order_id "
	  "LEFT JOIN Products ON OrderItems.product_id = Products.id "
	"WHERE 1 = 1 ";

	// time
	String timeFrom = FormatDateTime("hh:nn:ss", DateTimePicker_1OR->Time);
	String timeTo = FormatDateTime("hh:nn:ss", DateTimePicker_2OR->Time);
	sqlQuery += "AND Orders.start_time >= '" + timeFrom + "' AND Orders.end_time <= '" + timeTo + "' ";

	// date
	String dateFrom = FormatDateTime("yyyy-mm-dd",  DateTimePicker_3OR->Date);
	String dateTo = FormatDateTime("yyyy-mm-dd", DateTimePicker_4OR->Date);
	sqlQuery += "AND Orders.order_date >= '" + dateFrom + "' AND Orders.order_date <= '" + dateTo + "' ";

	// office
	int officeId = GetItemID(ComboBoxChoiceOfficeOR);
	if (officeId > 0) { sqlQuery += "AND Orders.office_id = '" + IntToStr(officeId) + "' "; }

	// state
	int orderStatus = ComboBoxOrderStateOR->ItemIndex;
	if (orderStatus > 0) { sqlQuery += "AND Orders.status = '" + ComboBoxOrderStateOR->Text + "' "; }

	// product
	int productId = GetItemID(ComboBoxChoiceProductOR);
	int productGroupId = GetItemID(ComboBoxChoiceProductGroupOR);
	int productFilter = ComboBoxChoiceProductFilterOR->ItemIndex;

	if (productId > 0) {
		if (productFilter == 0) {
			sqlQuery += "AND Orders.id IN (SELECT order_id FROM OrderItems WHERE product_id = " + IntToStr(productId) + ") ";
		} else if (productFilter == 1) {
			sqlQuery += "AND Orders.id NOT IN (SELECT order_id FROM OrderItems WHERE product_id = " + IntToStr(productId) + ") ";
		}
	} else {
		if (productGroupId > 0) {
			if (productFilter == 0) {
				sqlQuery += "AND Orders.id IN (SELECT order_id FROM OrderItems WHERE product_id IN "
							"(SELECT id FROM Products WHERE type_id = " + IntToStr(productGroupId) + ")) ";
			} else if (productFilter == 1) {
				sqlQuery += "AND Orders.id NOT IN (SELECT order_id FROM OrderItems WHERE product_id IN "
							"(SELECT id FROM Products WHERE type_id = " + IntToStr(productGroupId) + ")) ";
			}
		}
	}

	// recipient
	int recipientId = GetItemID(ComboBoxChoiceRecipientOR);
	if (recipientId > 0) { sqlQuery += "AND Orders.recipient_id = '" + IntToStr(recipientId) + "' "; }

	// customer
	int customerId = GetItemID(ComboBoxChoiceCustomerOR);
	if (customerId > 0) { sqlQuery += "AND Orders.customer_id = '" + IntToStr(customerId) + "' "; }

	DataBase->ADOQuery->SQL->Text = sqlQuery;

	try {

		DataBase->ADOQuery->Open();

		vector<OrderData> orders;
		while (!DataBase->ADOQuery->Eof)
		{
			OrderData order;

			order.id = DataBase->ADOQuery->FieldByName("id")->AsInteger;
			order.status = DataBase->ADOQuery->FieldByName("status")->AsString;
			order.order_date = FormatDateTime("yyyy-mm-dd", DataBase->ADOQuery->FieldByName("order_date")->AsDateTime);
			order.start_time = FormatDateTime("hh:nn", DataBase->ADOQuery->FieldByName("start_time")->AsDateTime);
			order.end_time = FormatDateTime("hh:nn", DataBase->ADOQuery->FieldByName("end_time")->AsDateTime);
			order.office_name = DataBase->ADOQuery->FieldByName("office_name")->AsString;
			order.recipient_name = DataBase->ADOQuery->FieldByName("recipient_name")->AsString;
			order.customer_name = DataBase->ADOQuery->FieldByName("customer_name")->AsString;
			order.address = DataBase->ADOQuery->FieldByName("address")->AsString;
			order.comment = DataBase->ADOQuery->FieldByName("comment")->AsString;

			orders.push_back(order);
			DataBase->ADOQuery->Next();
		}

		DataBase->ADOQuery->Close();
		CreateExcelReportOrders(orders);

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні даних про замовлення: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}

void __fastcall TFormReport::ButtonSaveCClick(TObject *Sender)
{
	String sqlQuery = "SELECT Calls.id, Calls.status, Calls.comment, "
	  "Orders.id AS order_id, Orders.order_date, Orders.start_time, Orders.end_time, "
	  "Offices.name AS office_name, Employees.name AS employee_name "
	  "FROM Calls "
	  "LEFT JOIN Orders ON Calls.order_id = Orders.id "
	  "LEFT JOIN Offices ON Orders.office_id = Offices.id "
	  "LEFT JOIN Employees ON Calls.employee_id = Employees.id "
	"WHERE 1 = 1 ";

	// time
	String timeFrom = FormatDateTime("hh:nn:ss", DateTimePicker_1C->Time);
	String timeTo = FormatDateTime("hh:nn:ss", DateTimePicker_2C->Time);
	sqlQuery += "AND Orders.start_time >= '" + timeFrom + "' AND Orders.end_time <= '" + timeTo + "' ";

	// date
	String dateFrom = FormatDateTime("yyyy-mm-dd",  DateTimePicker_3C->Date);
	String dateTo = FormatDateTime("yyyy-mm-dd", DateTimePicker_4C->Date);
	sqlQuery += "AND Orders.order_date >= '" + dateFrom + "' AND Orders.order_date <= '" + dateTo + "' ";

	// office
	int officeId = GetItemID(ComboBoxChoiceOfficeC);
	if (officeId > 0) { sqlQuery += "AND Orders.office_id = '" + IntToStr(officeId) + "' "; }

	// state
	int orderStatus = ComboBoxCallStateC->ItemIndex;
	if (orderStatus > 0) { sqlQuery += "AND Calls.status = '" + ComboBoxCallStateC->Text + "' "; }

	// product
	int employeeId = GetItemID(ComboBoxChoiceEmplC);
	int roleId = GetItemID(ComboBoxChoiceEmplRoleC);
	int employeeFilter = ComboBoxChoiceEmplFilterC->ItemIndex;

	if (employeeId > 0) {
		if (employeeFilter == 0) {
			sqlQuery += "AND Calls.id IN (SELECT id FROM Calls WHERE employee_id = " + IntToStr(employeeId) + ") ";
		} else if (employeeFilter == 1) {
			sqlQuery += "AND Calls.id NOT IN (SELECT id FROM Calls WHERE employee_id = " + IntToStr(employeeId) + ") ";
		}
	} else {
		if (roleId > 0) {
			if (employeeFilter == 0) {
				sqlQuery += "AND Calls.id IN (SELECT id FROM Calls WHERE employee_id IN "
							"(SELECT id FROM Employees WHERE role_id = " + IntToStr(roleId) + ")) ";
			} else if (employeeFilter == 1) {
				sqlQuery += "AND Calls.id NOT IN (SELECT id FROM Calls WHERE employee_id IN "
							"(SELECT id FROM Employees WHERE role_id = " + IntToStr(roleId) + ")) ";
			}
		}
	}

	DataBase->ADOQuery->SQL->Text = sqlQuery;

	try {

		DataBase->ADOQuery->Open();

		vector<CallData> calls;
		while (!DataBase->ADOQuery->Eof) {

			CallData call;

            call.id = DataBase->ADOQuery->FieldByName("id")->AsString;
			call.status = DataBase->ADOQuery->FieldByName("status")->AsString;
			call.order_id = DataBase->ADOQuery->FieldByName("order_id")->AsString;
			call.order_date = DataBase->ADOQuery->FieldByName("order_date")->AsString;
            call.start_time = DataBase->ADOQuery->FieldByName("start_time")->AsString;
			call.end_time = DataBase->ADOQuery->FieldByName("end_time")->AsString;
			call.employee_name = DataBase->ADOQuery->FieldByName("employee_name")->AsString;
			call.comment = DataBase->ADOQuery->FieldByName("comment")->AsString;

			calls.push_back(call);
            DataBase->ADOQuery->Next();
		}

		DataBase->ADOQuery->Close();
		CreateExcelReportCalls(calls);


	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні даних про дзвінки: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}
//---------------------------------------------------------------------------
void TFormReport::CreateExcelReportOrders(const vector<OrderData>& orders)
{
	Variant ExcelApp, Workbook, SheetOrders, SheetList;

	try {

		// excel run
		ExcelApp = CreateOleObject("Excel.Application");
		ExcelApp.OlePropertySet("Visible", false);
		Workbook = ExcelApp.OlePropertyGet("Workbooks").OleFunction("Add");

		// SheetOrders
		SheetOrders = Workbook.OlePropertyGet("Sheets", 1);
		SheetOrders.OlePropertySet("Name", "Список замовлень");

		// cols
		SheetOrders.OlePropertyGet("Cells", 1, 1).OlePropertySet("Value", "ID");
		SheetOrders.OlePropertyGet("Cells", 1, 2).OlePropertySet("Value", "Статус");
		SheetOrders.OlePropertyGet("Cells", 1, 3).OlePropertySet("Value", "Дата доставки");
		SheetOrders.OlePropertyGet("Cells", 1, 4).OlePropertySet("Value", "Проміжок доставки");
		SheetOrders.OlePropertyGet("Cells", 1, 5).OlePropertySet("Value", "Офіс");
		SheetOrders.OlePropertyGet("Cells", 1, 6).OlePropertySet("Value", "Отримувач");
		SheetOrders.OlePropertyGet("Cells", 1, 7).OlePropertySet("Value", "Замовник");
		SheetOrders.OlePropertyGet("Cells", 1, 8).OlePropertySet("Value", "Адресса");
		SheetOrders.OlePropertyGet("Cells", 1, 9).OlePropertySet("Value", "Коментар");

		// fill
		for (int i = 0; i < orders.size(); i++) {

			int row = i + 2;

			SheetOrders.OlePropertyGet("Cells", row, 1).OlePropertySet("Value", orders[i].id);
			SheetOrders.OlePropertyGet("Cells", row, 2).OlePropertySet("Value", orders[i].status);
			SheetOrders.OlePropertyGet("Cells", row, 3).OlePropertySet("Value", orders[i].order_date);
			SheetOrders.OlePropertyGet("Cells", row, 4).OlePropertySet("Value", orders[i].start_time + " - " + orders[i].end_time);
			SheetOrders.OlePropertyGet("Cells", row, 5).OlePropertySet("Value", orders[i].office_name);
			SheetOrders.OlePropertyGet("Cells", row, 6).OlePropertySet("Value", orders[i].recipient_name);
			SheetOrders.OlePropertyGet("Cells", row, 7).OlePropertySet("Value", orders[i].customer_name);
			SheetOrders.OlePropertyGet("Cells", row, 8).OlePropertySet("Value", orders[i].address);
			SheetOrders.OlePropertyGet("Cells", row, 9).OlePropertySet("Value", orders[i].comment);
		}

		// SheetList
		Workbook.OlePropertyGet("Sheets").OleProcedure("Add");
		SheetList = Workbook.OlePropertyGet("Sheets", 1);
		SheetList.OlePropertySet("Name", "Кількість замовлень");

		// office | (date | count)
		map<String, map<String, int>> summaryData;
		for (auto &order : orders) {
			summaryData[order.office_name][order.order_date]++;
		}

		// cols
		int row = 1;
		int col = 2;
		SheetList.OlePropertyGet("Cells", row, 1).OlePropertySet("Value", "Офіс/Дата");
		set<String> dates;
		for (const auto& [office, dateData] : summaryData) {
			for (const auto& [date, count] : dateData) {
				dates.insert(date);
			}
		}
		for (const auto& date : dates) {
			SheetList.OlePropertyGet("Cells", row, col).OlePropertySet("Value", date);
			col++;
		}

		// fill
		row = 2;
		for (const auto& [office, dateData] : summaryData) {
			SheetList.OlePropertyGet("Cells", row, 1).OlePropertySet("Value", office);
			col = 2;
			for (const auto& date : dates) {
				int count = dateData.count(date) ? dateData.at(date) : 0;
				SheetList.OlePropertyGet("Cells", row, col).OlePropertySet("Value", count);
				col++;
			}
			row++;
		}

		// save
		Workbook.OleProcedure("SaveAs", ".\\report.xlsx");
		ExcelApp.OleProcedure("Quit");

		ShowMessage("Звіт успішно збережений!");

	} catch (const Exception &E) {
		ShowMessage("Помилка при збереженні звіту: " + E.Message);
	}
}

void TFormReport::CreateExcelReportCalls(const vector<CallData>& calls)
{
	Variant ExcelApp, Workbook, SheetCalls, SheetList;

	try {

		// excel run
		ExcelApp = CreateOleObject("Excel.Application");
		ExcelApp.OlePropertySet("Visible", false);
		Workbook = ExcelApp.OlePropertyGet("Workbooks").OleFunction("Add");

		// SheetCalls
		SheetCalls = Workbook.OlePropertyGet("Sheets", 1);
		SheetCalls.OlePropertySet("Name", "Список дзвінків");

		// cols
		SheetCalls.OlePropertyGet("Cells", 1, 1).OlePropertySet("Value", "ID");
		SheetCalls.OlePropertyGet("Cells", 1, 2).OlePropertySet("Value", "Статус");
		SheetCalls.OlePropertyGet("Cells", 1, 3).OlePropertySet("Value", "ID замовлення");
		SheetCalls.OlePropertyGet("Cells", 1, 4).OlePropertySet("Value", "Дата доставки");
		SheetCalls.OlePropertyGet("Cells", 1, 5).OlePropertySet("Value", "Проміжок доставки");
		SheetCalls.OlePropertyGet("Cells", 1, 6).OlePropertySet("Value", "Співробітник");
		SheetCalls.OlePropertyGet("Cells", 1, 7).OlePropertySet("Value", "Коментар");

		// fill
		for (int i = 0; i < calls.size(); i++) {

			int row = i + 2;

			SheetCalls.OlePropertyGet("Cells", row, 1).OlePropertySet("Value", calls[i].id);
			SheetCalls.OlePropertyGet("Cells", row, 2).OlePropertySet("Value", calls[i].status);
			SheetCalls.OlePropertyGet("Cells", row, 3).OlePropertySet("Value", calls[i].order_id);
			SheetCalls.OlePropertyGet("Cells", row, 4).OlePropertySet("Value", calls[i].order_date);
			SheetCalls.OlePropertyGet("Cells", row, 5).OlePropertySet("Value", calls[i].start_time + " - " + calls[i].end_time);
			SheetCalls.OlePropertyGet("Cells", row, 6).OlePropertySet("Value", calls[i].employee_name);
			SheetCalls.OlePropertyGet("Cells", row, 7).OlePropertySet("Value", calls[i].comment);
		}

		// SheetList
		Workbook.OlePropertyGet("Sheets").OleProcedure("Add");
		SheetList = Workbook.OlePropertyGet("Sheets", 1);
		SheetList.OlePropertySet("Name", "Кількість дзвінків");

		// office | (date | count)
		map<String, map<String, int>> summaryData;
		for (auto &call : calls) {
			summaryData[call.employee_name][call.order_date]++;
		}

		// cols
		int row = 1;
		int col = 2;
		SheetList.OlePropertyGet("Cells", row, 1).OlePropertySet("Value", "Співробітник/Дата");
		set<String> dates;
		for (const auto& [employee, dateData] : summaryData) {
			for (const auto& [date, count] : dateData) {
				dates.insert(date);
			}
		}
		for (const auto& date : dates) {
			SheetList.OlePropertyGet("Cells", row, col).OlePropertySet("Value", date);
			col++;
		}
        SheetList.OlePropertyGet("Cells", row, col).OlePropertySet("Value", "Всього");

		// fill
		row = 2;
		for (const auto& [employee, dateData] : summaryData) {
			SheetList.OlePropertyGet("Cells", row, 1).OlePropertySet("Value", employee);
			col = 2;
			int totalCalls = 0;
			for (const auto& date : dates) {
				int count = dateData.count(date) ? dateData.at(date) : 0;
				SheetList.OlePropertyGet("Cells", row, col).OlePropertySet("Value", count);
				totalCalls += count;
				col++;
			}
			SheetList.OlePropertyGet("Cells", row, col).OlePropertySet("Value", totalCalls);
			row++;
		}

		// total_cols
		SheetList.OlePropertyGet("Cells", row, 1).OlePropertySet("Value", "Всього");
		col = 2;
		for (const auto& date : dates) {
			int totalByDate = 0;
			for (const auto& [employee, dateData] : summaryData) {
				if (dateData.count(date)) {
					totalByDate += dateData.at(date);
				}
			}
			SheetList.OlePropertyGet("Cells", row, col).OlePropertySet("Value", totalByDate);
			col++;
		}

		// total_fill
		int grandTotal = 0;
		for (const auto& [employee, dateData] : summaryData) {
			for (const auto& [date, count] : dateData) {
				grandTotal += count;
			}
		}
		SheetList.OlePropertyGet("Cells", row, col).OlePropertySet("Value", grandTotal);

		// save
		Workbook.OleProcedure("SaveAs", ".\\report.xlsx");
		ExcelApp.OleProcedure("Quit");

		ShowMessage("Звіт успішно збережений!");

	} catch (const Exception &E) {
		ShowMessage("Помилка при збереженні звіту: " + E.Message);
	}
}
//---------------------------------------------------------------------------
