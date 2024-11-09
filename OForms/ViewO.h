//---------------------------------------------------------------------------

#ifndef ViewOH
#define ViewOH
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

#include "OForms\RecipientsAddO.h"
#include "OForms\ProductAddO.h"
#include "OForms\ProductEditO.h"
//---------------------------------------------------------------------------
class TFormViewO : public TForm
{
__published:	// IDE-managed Components

	TBevel *Bevel_1;
    TGroupBox *GroupBoxInfo;
	TLabeledEdit *LabeledEditID;
	TLabeledEdit *LabeledEditStatus;
	TLabel *LabelDatePicker;
	TLabel *LabelTimePicker;
	TDateTimePicker *DatePicker;
	TDateTimePicker *StartTimePicker;
	TDateTimePicker *EndTimePicker;

	TGroupBox *GroupBoxCustomer;
	TLabeledEdit *LabeledEditCustomerName;
	TLabeledEdit *LabeledEditCustomerPhone;
	TLabeledEdit *LabeledEditCustomerBalance;

	TGroupBox *GroupBoxRecipient;
	TLabel *LabelChoiceRecipient;
	TComboBox *ComboBoxChoiceRecipient;
	TButton *ButtonAddRecipient;

	TGroupBox *GroupBoxComment;
	TMemo *MemoComment;
	TGroupBox *GroupBoxAddress;
	TMemo *MemoAddress;
	TGroupBox *GroupBoxCallComment;
	TMemo *MemoCallComment;

	TLabel *LabelProducts;
	TListView *ListViewProducts;

	TLabel *LabeCallState;
	TComboBox *ComboBoxCallState;

	TButton *ButtonConfirm;
	TButton *ButtonAddProduct;
	TButton *ButtonDelProduct;
	TButton *ButtonNotes;

	void __fastcall FormShow(TObject *Sender);

	void __fastcall ButtonAddRecipientClick(TObject *Sender);
	void __fastcall ButtonDelProductClick(TObject *Sender);
	void __fastcall ListViewProductsDblClick(TObject *Sender);

	void __fastcall ButtonConfirmClick(TObject *Sender);
	void __fastcall ButtonNotesClick(TObject *Sender);
	void __fastcall ButtonAddProductClick(TObject *Sender);

private:	// User declarations

	int orderId, emplId, recipientId, officeId;

	void LoadOrder();
	void LoadProducts();

	void FillRecipients();
	int GetRecipientID();
	void SetRecipientID(int recipientId);

public:		// User declarations
	String comment;
	__fastcall TFormViewO(TComponent* Owner, int orderId, int emplId);
	bool ShowConfirmationDialog(String message, String caption);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormViewO *FormViewO;
//---------------------------------------------------------------------------
#endif
