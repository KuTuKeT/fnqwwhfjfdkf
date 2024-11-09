//---------------------------------------------------------------------------

#ifndef ViewTH
#define ViewTH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>


#include "DB.h"
#include "Notes.h"
//---------------------------------------------------------------------------
class TFormViewT : public TForm
{
__published:	// IDE-managed Components

	TBevel *Bevel_1;
	TGroupBox *GroupBoxInfo;
	TLabel *LabelTimePicker;
	TLabel *LabelDatePicker;
	TLabeledEdit *LabeledEditID;
	TLabeledEdit *LabeledEditStatus;

	TDateTimePicker *DatePicker;
	TDateTimePicker *StartTimePicker;
	TDateTimePicker *EndTimePicker;

	TGroupBox *GroupBoxRecipient;
	TLabeledEdit *LabeledEditRecipientName;
	TLabeledEdit *LabeledEditRecipientPhone;

	TGroupBox *GroupBoxAddress;
	TMemo *MemoAddress;
	TGroupBox *GroupBoxCallComment;
	TMemo *MemoCallComment;

	TComboBox *ComboBoxCallState;
	TLabel *LabeCallState;

	TButton *ButtonNotes;
	TButton *ButtonConfirm;

	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonConfirmClick(TObject *Sender);
	void __fastcall ButtonNotesClick(TObject *Sender);

private:	// User declarations

	int orderId, emplId;
	void LoadOrder();

public:		// User declarations
	String comment;
	__fastcall TFormViewT(TComponent* Owner, int orderId, int emplId);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormViewT *FormViewT;
//---------------------------------------------------------------------------
#endif
