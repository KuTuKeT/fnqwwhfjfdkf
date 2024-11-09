//---------------------------------------------------------------------------

#ifndef ProductEditOH
#define ProductEditOH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>

#include "DB.h"
//---------------------------------------------------------------------------
class TFormProductEditO : public TForm
{
__published:	// IDE-managed Components

	TButton *ButtonAdd;
	TButton *ButtonCancel;
	TLabeledEdit *LabeledEditQuantity;
	TLabeledEdit *LabeledEditPrice;
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);

private:	// User declarations

	int itemId, itemQuantity, productId, productQuantity;
	void LoadProductData();

public:		// User declarations
	__fastcall TFormProductEditO(TComponent* Owner, int itemId);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormProductEditO *FormProductEditO;
//---------------------------------------------------------------------------
#endif
