//---------------------------------------------------------------------------

#ifndef NotesH
#define NotesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>

#include "DB.h"
//---------------------------------------------------------------------------
class TFormNotes : public TForm
{
__published:	// IDE-managed Components

	TLabel *LabelNote;
	TButton *ButtonConfirm;
	TMemo *MemoText;
	TRichEdit *RichEditNotes;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonConfirmClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);

private:	// User declarations

	int orderId, emplId;
	void LoadNotes();

public:		// User declarations
	__fastcall TFormNotes(TComponent* Owner, int orderId, int emplId);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNotes *FormNotes;
//---------------------------------------------------------------------------
#endif
