//---------------------------------------------------------------------------

#ifndef GroupsActionsH
#define GroupsActionsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>

#include "DB.h"
//---------------------------------------------------------------------------

enum class TGroupsFormMode { Add, Edit };

class TFormGroupsActions : public TForm
{
__published:	// IDE-managed Components

	TButton *ButtonAction;
	TButton *ButtonCancel;
	TLabeledEdit *LabeledEditName;
	void __fastcall ButtonActionClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);

private:	// User declarations

	int groupId;
	TGroupsFormMode mode;
	void LoadGroupData();

public:		// User declarations
	__fastcall TFormGroupsActions(TComponent* Owner, TGroupsFormMode mode, int groupId = -1);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGroupsActions *FormGroupsActions;
//---------------------------------------------------------------------------
#endif
