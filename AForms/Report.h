//---------------------------------------------------------------------------

#ifndef ReportH
#define ReportH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <SysUtils.hpp>
#include <ComObj.hpp>
#include <vector>
#include <map>
#include <set>

#include "DB.h"
//---------------------------------------------------------------------------

using namespace std;
enum class TFillItemsType { Offices, Groups, Customers, Recipients, Roles };

struct OrderData {
	String id;
	String status;
	String order_date;
	String start_time;
	String end_time;
	String office_name;
	String recipient_name;
	String customer_name;
	String address;
	String comment;
};

struct CallData {
	String id;
	String status;
    String order_id;
	String order_date;
    String start_time;
	String end_time;
	String employee_name;
	String comment;
};

class TFormReport : public TForm
{
__published:	// IDE-managed Components

	TSaveDialog *SaveDialog;
	TPageControl *PageControl;
	TTabSheet *TabSheetOrders;
	TTabSheet *TabSheetCalls;

	// OR
	TButton *ButtonSaveOR;
	TButton *ButtonClearOR;
	TGroupBox *GroupBoxFitersOR;
	TGroupBox *GroupBoxChoiceUsersOR;
	TGroupBox *GroupBoxChoiceProductOR;

	TLabel *LabeOrderStateOR;
	TLabel *LabelChoiceOfficeOR;
	TLabel *LabelChoiceDate_1OR;
	TLabel *LabelChoiceDate_2OR;
	TLabel *LabelChoiceTime_1OR;
	TLabel *LabelChoiceTime_2OR;
	TLabel *LabelChoiceProductOR;
	TLabel *LabelChoiceProductGroupOR;
	TLabel *LabelChoiceProductFilterOR;
	TLabel *LabelChoiceCustomerOR;
	TLabel *LabelChoiceRecipientOR;

	TDateTimePicker *DateTimePicker_1OR;
	TDateTimePicker *DateTimePicker_2OR;
	TDateTimePicker *DateTimePicker_3OR;
	TDateTimePicker *DateTimePicker_4OR;

	TComboBox *ComboBoxOrderStateOR;
	TComboBox *ComboBoxChoiceOfficeOR;
	TComboBox *ComboBoxChoiceProductOR;
	TComboBox *ComboBoxChoiceProductGroupOR;
	TComboBox *ComboBoxChoiceProductFilterOR;
	TComboBox *ComboBoxChoiceCustomerOR;
	TComboBox *ComboBoxChoiceRecipientOR;

	// C
	TButton *ButtonSaveC;
	TButton *ButtonClearC;
	TGroupBox *GroupBoxFitersC;
	TGroupBox *GroupBoxChoiceEmplC;

	TLabel *Label—allStateO;
	TLabel *LabelChoiceOfficeC;
	TLabel *LabelChoiceDate_1C;
	TLabel *LabelChoiceDate_2C;
	TLabel *LabelChoiceTime_1C;
	TLabel *LabelChoiceTime_2C;
	TLabel *LabelChoiceEmplC;
	TLabel *LabelChoiceEmplRoleC;
	TLabel *LabelChoiceEmplFilterC;
	TComboBox *ComboBoxChoiceEmplFilterC;
	TComboBox *ComboBoxChoiceEmplRoleC;
	TComboBox *ComboBoxChoiceEmplC;
	TComboBox *ComboBoxCallStateC;

	TDateTimePicker *DateTimePicker_1C;
	TDateTimePicker *DateTimePicker_2C;
	TDateTimePicker *DateTimePicker_4C;
	TDateTimePicker *DateTimePicker_3C;

	TComboBox *ComboBoxChoiceOfficeC;

	//--
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonClearClick(TObject *Sender);
	void __fastcall PageControlChange(TObject *Sender);
	void __fastcall ButtonSaveORClick(TObject *Sender);
	void __fastcall ButtonSaveCClick(TObject *Sender);
	void __fastcall ComboBoxChoiceProductGroupORChange(TObject *Sender);
	void __fastcall ComboBoxChoiceEmplRoleCChange(TObject *Sender);

private:	// User declarations

	//--
	void Reset(TTabSheet *activeTab);
	void FillItems(TComboBox *comboBox, TFillItemsType type);
	int GetItemID(TComboBox *comboBox);

	void CreateExcelReportOrders(const vector<OrderData>& orders);
	void CreateExcelReportCalls(const vector<CallData>& calls);

public:		// User declarations
	__fastcall TFormReport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormReport *FormReport;
//---------------------------------------------------------------------------
#endif
