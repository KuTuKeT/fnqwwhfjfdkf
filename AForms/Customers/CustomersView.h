//---------------------------------------------------------------------------

#ifndef CustomersViewH
#define CustomersViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>

#include "DB.h"

#include "AForms\Customers\CustomersActions.h"
//---------------------------------------------------------------------------
class TFormCustomersView : public TForm
{
__published:	// IDE-managed Components

	TListView *ListViewItems;
	TButton *ButtonAdd;
	TButton *ButtonDel;
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonDelClick(TObject *Sender);
	void __fastcall ListViewItemsDblClick(TObject *Sender);

private:	// User declarations

	void FillCustomers();

public:		// User declarations
	__fastcall TFormCustomersView(TComponent* Owner);
	bool ShowConfirmationDialog(String message, String caption);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCustomersView *FormCustomersView;
//---------------------------------------------------------------------------
#endif
