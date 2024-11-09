//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("DB.cpp", DataBase); /* TDataModule: File Type */

USEFORM("Main.cpp", FormMain);
USEFORM("Notes.cpp", FormNotes);
USEFORM("Login.cpp", FormLogin);
USEFORM("FAQ.cpp", FormFAQ);

USEFORM("AForms\Employees\EmployeesView.cpp", FormEmployeesView);
USEFORM("AForms\Employees\EmployeesActions.cpp", FormEmployeesActions);
USEFORM("AForms\Customers\CustomersView.cpp", FormCustomersView);
USEFORM("AForms\Customers\CustomersActions.cpp", FormCustomersActions);
USEFORM("AForms\Recipients\RecipientsView.cpp", FormRecipientsView);
USEFORM("AForms\Recipients\RecipientsActions.cpp", FormRecipientsActions);
USEFORM("AForms\Groups\GroupsView.cpp", FormGroupsView);
USEFORM("AForms\Groups\GroupsActions.cpp", FormGroupsActions);
USEFORM("AForms\Products\ProductsView.cpp", FormProductsView);
USEFORM("AForms\Products\ProductsActions.cpp", FormProductsActions);
USEFORM("AForms\Offices\OfficesView.cpp", FormOfficesView);
USEFORM("AForms\Offices\OfficesActions.cpp", FormOfficesActions);
USEFORM("AForms\Warehouses\WarehousesView.cpp", FormWarehousesView);
USEFORM("AForms\Warehouses\WarehousesActions.cpp", FormWarehousesActions);
USEFORM("AForms\Report.cpp", FormReport);

USEFORM("ORForms\ViewOR.cpp", FormViewOR);
USEFORM("OForms\ViewO.cpp", FormViewO);
USEFORM("TForms\ViewT.cpp", FormViewT);
USEFORM("CForms\ViewC.cpp", FormViewC);
USEFORM("FForms\ViewF.cpp", FormViewF);

USEFORM("OForms\RecipientsAddO.cpp", FormRecipientsAddO);
USEFORM("OForms\ProductAddO.cpp", FormProductAddO);
USEFORM("OForms\ProductEditO.cpp", FormProductEditO);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFormMain), &FormMain);
		Application->CreateForm(__classid(TDataBase), &DataBase);
		Application->CreateForm(__classid(TFormLogin), &FormLogin);
		Application->CreateForm(__classid(TFormNotes), &FormNotes);
		Application->CreateForm(__classid(TFormFAQ), &FormFAQ);

		Application->CreateForm(__classid(TFormEmployeesView), &FormEmployeesView);
		Application->CreateForm(__classid(TFormEmployeesActions), &FormEmployeesActions);
		Application->CreateForm(__classid(TFormCustomersView), &FormCustomersView);
		Application->CreateForm(__classid(TFormCustomersActions), &FormCustomersActions);
		Application->CreateForm(__classid(TFormRecipientsView), &FormRecipientsView);
		Application->CreateForm(__classid(TFormRecipientsActions), &FormRecipientsActions);
		Application->CreateForm(__classid(TFormGroupsView), &FormGroupsView);
		Application->CreateForm(__classid(TFormGroupsActions), &FormGroupsActions);
		Application->CreateForm(__classid(TFormProductsView), &FormProductsView);
		Application->CreateForm(__classid(TFormProductsActions), &FormProductsActions);
		Application->CreateForm(__classid(TFormOfficesView), &FormOfficesView);
		Application->CreateForm(__classid(TFormOfficesActions), &FormOfficesActions);
 		Application->CreateForm(__classid(TFormWarehousesView), &FormWarehousesView);
		Application->CreateForm(__classid(TFormWarehousesActions), &FormWarehousesActions);
		Application->CreateForm(__classid(TFormReport), &FormReport);

		Application->CreateForm(__classid(TFormViewOR), &FormViewOR);
		Application->CreateForm(__classid(TFormViewO), &FormViewO);
		Application->CreateForm(__classid(TFormViewT), &FormViewT);
		Application->CreateForm(__classid(TFormViewF), &FormViewF);
		Application->CreateForm(__classid(TFormViewC), &FormViewC);
		Application->CreateForm(__classid(TFormRecipientsAddO), &FormRecipientsAddO);
		Application->CreateForm(__classid(TFormProductAddO), &FormProductAddO);
		Application->CreateForm(__classid(TFormProductEditO), &FormProductEditO);

		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
