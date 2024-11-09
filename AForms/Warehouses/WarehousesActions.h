//---------------------------------------------------------------------------

#ifndef WarehousesActionsH
#define WarehousesActionsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>

#include "DB.h"
//---------------------------------------------------------------------------

enum class TWarehousesFormMode { Add, Edit };
enum class TWarehousesFillItemsType { Offices, Products };

class TFormWarehousesActions : public TForm
{
__published:	// IDE-managed Components

	TLabel *LabelChoiceProduct;
	TLabel *LabelChoiceOffice;
	TComboBox *ComboBoxChoiceProduct;
	TComboBox *ComboBoxChoiceOffice;
	TLabeledEdit *LabeledEditQuantity;
	TButton *ButtonAction;
	TButton *ButtonCancel;
	void __fastcall ButtonActionClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);

private:	// User declarations

	int itemId;
	TWarehousesFormMode mode;
	void LoadItemsData();

	void FillItems(TComboBox *comboBox, TWarehousesFillItemsType type);
	int GetItemID(TComboBox *comboBox);

public:		// User declarations
	__fastcall TFormWarehousesActions(TComponent* Owner, TWarehousesFormMode mode, int itemId = -1);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormWarehousesActions *FormWarehousesActions;
//---------------------------------------------------------------------------
#endif
