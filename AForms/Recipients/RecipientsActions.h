//---------------------------------------------------------------------------

#ifndef RecipientsActionsH
#define RecipientsActionsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>

#include "DB.h"
//---------------------------------------------------------------------------

enum class TRecipientsFormMode { Add, Edit };

class TFormRecipientsActions : public TForm
{
__published:	// IDE-managed Components

	TButton *ButtonCancel;
	TButton *ButtonAction;
	TLabeledEdit *LabeledEditPhone;
	TLabeledEdit *LabeledEditName;
	void __fastcall ButtonActionClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);

private:	// User declarations

	int recipientId;
	TRecipientsFormMode mode;
	void LoadRecipientData();

public:		// User declarations
	__fastcall TFormRecipientsActions(TComponent* Owner, TRecipientsFormMode mode, int recipientId = -1);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRecipientsActions *FormRecipientsActions;
//---------------------------------------------------------------------------
#endif
