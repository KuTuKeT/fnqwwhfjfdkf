//---------------------------------------------------------------------------

#ifndef RecipientsAddOH
#define RecipientsAddOH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>

#include "DB.h"
//---------------------------------------------------------------------------
class TFormRecipientsAddO : public TForm
{
__published:	// IDE-managed Components

	TButton *ButtonCancel;
	TButton *ButtonAdd;
	TLabeledEdit *LabeledEditPhone;
	TLabeledEdit *LabeledEditName;
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);

private:	// User declarations

public:		// User declarations
	__fastcall TFormRecipientsAddO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRecipientsAddO *FormRecipientsAddO;
//---------------------------------------------------------------------------
#endif
