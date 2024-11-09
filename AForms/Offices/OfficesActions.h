//---------------------------------------------------------------------------

#ifndef OfficesActionsH
#define OfficesActionsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>

#include "DB.h"
//---------------------------------------------------------------------------

enum class TOfficesFormMode { Add, Edit };

class TFormOfficesActions : public TForm
{
__published:	// IDE-managed Components

	TLabeledEdit *LabeledEditName;
	TButton *ButtonAction;
	TButton *ButtonCancel;
	void __fastcall ButtonActionClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);

private:	// User declarations

	int officeId;
	TOfficesFormMode mode;
	void LoadOfficeData();

public:		// User declarations
	__fastcall TFormOfficesActions(TComponent* Owner, TOfficesFormMode mode, int officeId = -1);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormOfficesActions *FormOfficesActions;
//---------------------------------------------------------------------------
#endif
