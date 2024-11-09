//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Tabs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <DateUtils.hpp>

#include "DB.h"
#include "Login.h"
#include "Notes.h"
#include "FAQ.h"

#include "ORForms\ViewOR.h"
#include "TForms\ViewT.h"
#include "OForms\ViewO.h"
#include "FForms\ViewF.h"
#include "CForms\ViewC.h"

#include "AForms\Employees\EmployeesView.h"
#include "AForms\Customers\CustomersView.h"
#include "AForms\Recipients\RecipientsView.h"
#include "AForms\Groups\GroupsView.h"
#include "AForms\Products\ProductsView.h"
#include "AForms\Offices\OfficesView.h"
#include "AForms\Warehouses\WarehousesView.h"

#include "AForms\Report.h"
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components

	TPageControl *PageControl;
	TTabSheet *TabSheetOR;
	TTabSheet *TabSheetO;
	TTabSheet *TabSheetT;
	TTabSheet *TabSheetF;
	TTabSheet *TabSheetC;
	TTabSheet *TabSheetA;

	TLabel *LabelUser;
	TLabel *LabelRole;
	TButton *ButtonFAQ;
	TButton *ButtonExit;

	// T
	TBevel *Bevel_1T;
	TDateTimePicker *DateTimePicker_3T;
	TDateTimePicker *DateTimePicker_4T;
	TLabel *LabelChoiceTime_1T;
	TLabel *LabelChoiceTime_2T;
	TGroupBox *GroupBoxFitersT;
	TComboBox *ComboBoxCallStateT;
	TLabel *LabeCallStateT;
	TDateTimePicker *DateTimePicker_2T;
	TLabel *LabelChoiceDate_2T;
	TDateTimePicker *DateTimePicker_1T;
	TLabel *LabelChoiceDate_1T;
	TButton *ButtonClearT;
	TGroupBox *GroupBoxSearchT;
	TButton *ButtonConfirmT;
	TEdit *EditSearchT;
	TLabel *LabelSearchChoiceT;
	TComboBox *ComboBoxSearchT;
	TLabel *LabelSearchT;
    TListView *ListViewCallsT;

	// O
	TGroupBox *GroupBoxFitersO;
	TLabel *LabelChoiceTime_1O;
	TLabel *LabelChoiceTime_2O;
	TLabel *LabeCallStateO;
	TLabel *LabelChoiceDate_2O;
	TLabel *LabelChoiceDate_1O;
	TDateTimePicker *DateTimePicker_4O;
	TDateTimePicker *DateTimePicker_3O;
	TComboBox *ComboBoxCallStateO;
	TDateTimePicker *DateTimePicker_2O;
	TDateTimePicker *DateTimePicker_1O;
	TButton *ButtonClearO;
	TGroupBox *GroupBoxSearchO;
	TLabel *LabelSearchChoiceO;
	TLabel *LabelSearchO;
	TButton *ButtonConfirmO;
	TEdit *EditSearchO;
	TComboBox *ComboBoxSearchO;
	TBevel *Bevel_1O;
	TListView *ListViewCallsO;

	// OR
	TGroupBox *GroupBoxFitersOR;
	TLabel *LabelChoiceTime_1OR;
	TLabel *LabelChoiceTime_2OR;
	TLabel *LabeOrderStateOR;
	TLabel *LabelChoiceDate_2OR;
	TLabel *LabelChoiceDate_1OR;
	TDateTimePicker *DateTimePicker_4OR;
	TDateTimePicker *DateTimePicker_3OR;
	TComboBox *ComboBoxChoiceOfficeOR;
	TDateTimePicker *DateTimePicker_2OR;
	TDateTimePicker *DateTimePicker_1OR;
	TButton *ButtonClearOR;
	TGroupBox *GroupBoxSearchOR;
	TLabel *LabelSearchChoiceOR;
	TLabel *LabelSearchOR;
	TButton *ButtonConfirmOR;
	TEdit *EditSearchOR;
	TComboBox *ComboBoxSearchOR;
	TBevel *Bevel_1OR;
	TListView *ListViewOrdersOR;
	TComboBox *ComboBoxOrderStateOR;
	TLabel *LabelChoiceOfficeOR;
    TListView *ListViewProductsOR;

	//F
	TBevel *Bevel_1F;
	TComboBox *ComboBoxChoiceOfficeF;
	TLabel *LabelChoiceOfficeF;
	TLabel *LabelChoiceDate_2F;
	TDateTimePicker *DateTimePicker_1F;
	TLabel *LabelChoiceDate_1F;
	TDateTimePicker *DateTimePicker_2F;
	TComboBox *ComboBoxCallStateF;
	TLabel *Label—allStateF;
	TListView *ListViewCallsF;
	TListView *ListViewProductsF;
	TButton *ButtonConfirmF;

	//C
	TComboBox *ComboBoxChoiceOfficeC;
	TLabel *LabelChoiceOfficeC;
	TBevel *Bevel_1C;
	TListView *ListViewCallsC;
	TLabel *LabelChoiceDate_1C;
	TDateTimePicker *DateTimePicker_1C;
	TLabel *LabelChoiceDate_2C;
	TDateTimePicker *DateTimePicker_2C;
	TLabel *Label—allStateC;
	TComboBox *ComboBoxCallStateC;
	TButton *ButtonConfirmC;

	//A
	TGroupBox *GroupBoxUsers;
	TGroupBox *GroupBoxProducts;
	TGroupBox *GroupBoxReports;

	TButton *ButtonEmpls;
	TButton *ButtonCustomers;
	TButton *ButtonRecipients;
	TButton *ButtonGroups;
	TButton *ButtonProducts;
	TButton *ButtonOffices;
	TButton *ButtonWarehouses;
	TButton *ButtonReport;

	//--
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonFAQClick(TObject *Sender);
	void __fastcall ButtonExitClick(TObject *Sender);
	void __fastcall ButtonConfirmClick(TObject *Sender);
	void __fastcall ButtonClearClick(TObject *Sender);
	void __fastcall PageControlChange(TObject *Sender);
	void __fastcall ListViewClick(TObject *Sender);
    void __fastcall ListViewDblClick(TObject *Sender);

	void __fastcall ButtonEmplsClick(TObject *Sender);
	void __fastcall ButtonCustomersClick(TObject *Sender);
	void __fastcall ButtonRecipientsClick(TObject *Sender);
	void __fastcall ButtonGroupsClick(TObject *Sender);
	void __fastcall ButtonProductsClick(TObject *Sender);
	void __fastcall ButtonOfficesClick(TObject *Sender);
	void __fastcall ButtonWarehousesClick(TObject *Sender);
	void __fastcall ButtonReportClick(TObject *Sender);

private:	// User declarations

	User user;

	void Reset(TTabSheet *activeTab);
	void Fill(TTabSheet *activeTab);
	void FillOffices(TComboBox *comboBox);
	int GetOfficeID(TComboBox *comboBox);

public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
