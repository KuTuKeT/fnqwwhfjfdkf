//---------------------------------------------------------------------------

#ifndef ViewORH
#define ViewORH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ComCtrls.hpp>

#include "DB.h"
#include "Notes.h"
//---------------------------------------------------------------------------
class TFormViewOR : public TForm
{
__published:	// IDE-managed Components

	TGroupBox *GroupBoxInfo;
	TLabeledEdit *LabeledEditID;
	TLabeledEdit *LabeledEditStatus;
	TLabeledEdit *LabeledEditDateTime;
	TButton *ButtonNotes;

	TGroupBox *GroupBoxCustomer;
	TLabeledEdit *LabeledEditCustomerName;
	TLabeledEdit *LabeledEditCustomerPhone;
	TLabeledEdit *LabeledEditCustomerBalance;

	TGroupBox *GroupBoxRecipient;
	TLabeledEdit *LabeledEditRecipientName;
	TLabeledEdit *LabeledEditRecipientPhone;

	TListView *ListViewProducts;
	TListView *ListViewCalls;

	TMemo *MemoComment;
	TMemo *MemoAddress;
	TGroupBox *GroupBoxComment;
	TGroupBox *GroupBoxAddress;
	TLabel *LabelProducts;
	TLabel *LabelCalls;

	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonNotesClick(TObject *Sender);

private:	// User declarations

	int orderId, emplId;
	void LoadOrder();

public:		// User declarations
	__fastcall TFormViewOR(TComponent* Owner, int orderId, int emplId);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormViewOR *FormViewOR;
//---------------------------------------------------------------------------
#endif
