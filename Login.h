//---------------------------------------------------------------------------

#ifndef LoginH
#define LoginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>

#include "DB.h"
//---------------------------------------------------------------------------

struct User {
	int id;
	int role_id;
	String name;
	String role_name;
	String login;
	String pass;
	int access;
};

class TFormLogin : public TForm
{
__published:	// IDE-managed Components

	TLabeledEdit *LabeledEditLogin;
	TLabeledEdit *LabeledEditPass;
	TButton *ButtonEnter;
	void __fastcall ButtonEnterClick(TObject *Sender);

private:	// User declaration
	bool CheckCredentials(String login, String password, User &user);

public:		// User declarations
	User user;
	__fastcall TFormLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLogin *FormLogin;
//---------------------------------------------------------------------------
#endif
