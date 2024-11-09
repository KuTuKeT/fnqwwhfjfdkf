//---------------------------------------------------------------------------

#ifndef ProductsActionsH
#define ProductsActionsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>

#include "DB.h"
//---------------------------------------------------------------------------

enum class TProductsFormMode { Add, Edit };

class TFormProductsActions : public TForm
{
__published:	// IDE-managed Components

	TLabel *LabelChoiceGroup;
	TComboBox *ComboBoxChoiceGroup;
	TLabeledEdit *LabeledEditName;
	TLabeledEdit *LabeledEditPrice;
	TButton *ButtonAction;
	TButton *ButtonCancel;
	void __fastcall ButtonActionClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);

private:	// User declarations

	int productId;
	TProductsFormMode mode;
	void LoadProductData();

	void FillGroups();
	int GetGroupID();

public:		// User declarations
	__fastcall TFormProductsActions(TComponent* Owner, TProductsFormMode mode, int productId = -1);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormProductsActions *FormProductsActions;
//---------------------------------------------------------------------------
#endif
