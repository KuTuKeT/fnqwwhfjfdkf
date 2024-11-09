//---------------------------------------------------------------------------

#ifndef EmployeesActionsH
#define EmployeesActionsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>

#include "DB.h"
//---------------------------------------------------------------------------

enum class TEmployeesFormMode { Add, Edit };

class TFormEmployeesActions : public TForm
{
__published:	// IDE-managed Components

	TLabel *LabelChoiceRole;
	TComboBox *ComboBoxChoiceRole;
	TLabeledEdit *LabeledEditName;
	TLabeledEdit *LabeledEditPass;
	TLabeledEdit *LabeledEditLogin;
	TButton *ButtonAction;
	TButton *ButtonCancel;
	void __fastcall ButtonActionClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);

private:	// User declarations

	int employeeId;
	TEmployeesFormMode mode;
	void LoadEmployeeData();

	void FillRoles();
	int GetRoleID();

public:		// User declarations
	__fastcall TFormEmployeesActions(TComponent* Owner, TEmployeesFormMode mode, int employeeId = -1);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEmployeesActions *FormEmployeesActions;
//---------------------------------------------------------------------------
#endif
