//---------------------------------------------------------------------------

#ifndef EmployeesViewH
#define EmployeesViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ComCtrls.hpp>

#include "DB.h"

#include "AForms\Employees\EmployeesActions.h"
//---------------------------------------------------------------------------
class TFormEmployeesView : public TForm
{
__published:	// IDE-managed Components

	TLabel *LabelCount;
	TLabel *LabelChoiceRole;
	TComboBox *ComboBoxChoiceRole;
	TListView *ListViewItems;
	TButton *ButtonAdd;
	TButton *ButtonDel;
	void __fastcall ComboBoxChoiceRoleChange(TObject *Sender);
	void __fastcall ButtonDelClick(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ListViewItemsDblClick(TObject *Sender);

private:	// User declarations

    int count;

	void FillRoles();
	void FillEmployees();
	int GetRoleID();
	int GetEmployeesCount();

public:		// User declarations
	__fastcall TFormEmployeesView(TComponent* Owner);
	bool ShowConfirmationDialog(String message, String caption);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEmployeesView *FormEmployeesView;
//---------------------------------------------------------------------------
#endif
