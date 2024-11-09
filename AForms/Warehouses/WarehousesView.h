//---------------------------------------------------------------------------

#ifndef WarehousesViewH
#define WarehousesViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>

#include "DB.h"

#include "AForms\Warehouses\WarehousesActions.h"
//---------------------------------------------------------------------------
class TFormWarehousesView : public TForm
{
__published:	// IDE-managed Components

	TLabel *LabelChoiceOffice;
	TComboBox *ComboBoxChoiceOffice;
	TListView *ListViewItems;
	TButton *ButtonAdd;
	TButton *ButtonDel;
	void __fastcall ComboBoxChoiceOfficeChange(TObject *Sender);
	void __fastcall ButtonDelClick(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ListViewItemsDblClick(TObject *Sender);

private:	// User declarations

	void FillOffices();
	void FillWarehouses();
	int GetOfficeID();

public:		// User declarations
	__fastcall TFormWarehousesView(TComponent* Owner);
	bool ShowConfirmationDialog(String message, String caption);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormWarehousesView *FormWarehousesView;
//---------------------------------------------------------------------------
#endif
