//---------------------------------------------------------------------------

#ifndef FAQH
#define FAQH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormFAQ : public TForm
{
__published:	// IDE-managed Components

	TLabel *LabelInfo_1;
	TLabel *LabelInfo_2;
	TLabel *LabelInfo_3;
	TLabel *LabelInfo_4;
	TLabel *LabelInfo_6;
	TLabel *LabelInfo_5;
	TLabel *LabelInfo_8;
	TLabel *LabelInfo_7;

private:	// User declarations
public:		// User declarations
	__fastcall TFormFAQ(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormFAQ *FormFAQ;
//---------------------------------------------------------------------------
#endif
