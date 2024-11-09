//---------------------------------------------------------------------------

#ifndef ProductAddOH
#define ProductAddOH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ComCtrls.hpp>

#include "DB.h"
//---------------------------------------------------------------------------
class TFormProductAddO : public TForm
{
__published:	// IDE-managed Components

	TLabel *LabelChoiceOffice;
	TLabeledEdit *LabeledEditQuantity;
	TLabeledEdit *LabeledEditPrice;
	TListView *ListViewItems;
	TButton *ButtonAdd;
	TButton *ButtonCancel;

	void __fastcall FormShow(TObject *Sender);
	void __fastcall ListViewItemsClick(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);

private:	// User declarations

	int orderId, officeId, productId, productQuantity;
	void FillWarehouses();

public:		// User declarations
	__fastcall TFormProductAddO(TComponent* Owner, int orderId, int officeId);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormProductAddO *FormProductAddO;
//---------------------------------------------------------------------------
#endif
