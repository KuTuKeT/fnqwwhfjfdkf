//---------------------------------------------------------------------------

#ifndef ProductsViewH
#define ProductsViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>

#include "DB.h"

#include "AForms\Products\ProductsActions.h"
//---------------------------------------------------------------------------
class TFormProductsView : public TForm
{
__published:	// IDE-managed Components

	TLabel *LabelChoiceGroup;
	TComboBox *ComboBoxChoiceGroup;
	TListView *ListViewItems;
	TButton *ButtonAdd;
	TButton *ButtonDel;
	void __fastcall ComboBoxChoiceGroupChange(TObject *Sender);
	void __fastcall ButtonDelClick(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ListViewItemsDblClick(TObject *Sender);

private:	// User declarations

	void FillGroups();
	void FillProducts();
	int GetGroupID();

public:		// User declarations
	__fastcall TFormProductsView(TComponent* Owner);
	bool ShowConfirmationDialog(String message, String caption);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormProductsView *FormProductsView;
//---------------------------------------------------------------------------
#endif
