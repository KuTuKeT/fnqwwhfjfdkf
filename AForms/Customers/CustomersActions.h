//---------------------------------------------------------------------------

#ifndef CustomersActionsH
#define CustomersActionsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>

#include "DB.h"
//---------------------------------------------------------------------------

enum class TCustomerFormMode { Add, Edit };

class TFormCustomersActions : public TForm
{
__published:	// IDE-managed Components

	TButton *ButtonAction;
	TButton *ButtonCancel;
	TLabeledEdit *LabeledEditName;
	TLabeledEdit *LabeledEditPhone;
	TLabeledEdit *LabeledEditBalance;
	void __fastcall ButtonActionClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);

private:	// User declarations

	int customerId;
	TCustomerFormMode mode;
	void LoadCustomerData();

public:		// User declarations
	__fastcall TFormCustomersActions(TComponent* Owner, TCustomerFormMode mode, int customerId = -1);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCustomersActions *FormCustomersActions;
//---------------------------------------------------------------------------
#endif
