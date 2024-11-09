//---------------------------------------------------------------------------

#ifndef ViewCH
#define ViewCH
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
class TFormViewC : public TForm
{
__published:	// IDE-managed Components

	TBevel *Bevel_1;
	TGroupBox *GroupBoxInfo;
	TLabeledEdit *LabeledEditID;
	TLabeledEdit *LabeledEditStatus;
	TLabeledEdit *LabeledEditDateTime;

	TGroupBox *GroupBoxRecipient;
	TLabeledEdit *LabeledEditRecipientName;
	TLabeledEdit *LabeledEditRecipientPhone;

	TLabel *LabelProducts;
	TListView *ListViewProducts;

	TLabel *LabeCallState;
	TComboBox *ComboBoxCallState;

	TButton *ButtonNotes;
	TButton *ButtonConfirm;

	TGroupBox *GroupBoxAddress;
	TMemo *MemoAddress;
	TGroupBox *GroupBoxCallComment;
	TMemo *MemoCallComment;

	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonConfirmClick(TObject *Sender);
	void __fastcall ButtonNotesClick(TObject *Sender);

private:	// User declarations

	int orderId, emplId;

	void LoadOrder();
	void LoadProducts();

public:		// User declarations
	String comment;
	__fastcall TFormViewC(TComponent* Owner, int orderId, int emplId);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormViewC *FormViewC;
//---------------------------------------------------------------------------
#endif
