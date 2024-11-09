//---------------------------------------------------------------------------

#ifndef ViewFH
#define ViewFH
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
class TFormViewF : public TForm
{
__published:	// IDE-managed Components

    TBevel *Bevel_1;
	TGroupBox *GroupBoxInfo;
	TLabeledEdit *LabeledEditID;
	TLabeledEdit *LabeledEditStatus;
	TLabeledEdit *LabeledEditDateTime;

	TListView *ListViewProducts;
	TLabel *LabelProducts;

	TComboBox *ComboBoxCallState;
	TLabel *LabeCallState;

	TButton *ButtonNotes;
	TButton *ButtonConfirm;

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
	__fastcall TFormViewF(TComponent* Owner, int orderId, int emplId);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormViewF *FormViewF;
//---------------------------------------------------------------------------
#endif
