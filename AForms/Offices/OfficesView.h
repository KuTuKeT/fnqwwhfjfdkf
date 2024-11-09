//---------------------------------------------------------------------------

#ifndef OfficesViewH
#define OfficesViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>

#include "DB.h"

#include "AForms\Offices\OfficesActions.h"
//---------------------------------------------------------------------------
class TFormOfficesView : public TForm
{
__published:	// IDE-managed Components

	TListView *ListViewItems;
	TButton *ButtonAdd;
	TButton *ButtonDel;
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonDelClick(TObject *Sender);
	void __fastcall ListViewItemsDblClick(TObject *Sender);

private:	// User declarations

	void FillOffices();

public:		// User declarations
	__fastcall TFormOfficesView(TComponent* Owner);
	bool ShowConfirmationDialog(String message, String caption);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormOfficesView *FormOfficesView;
//---------------------------------------------------------------------------
#endif
