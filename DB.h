//---------------------------------------------------------------------------

#ifndef DBH
#define DBH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDataBase : public TDataModule
{
__published:	// IDE-managed Components

	TADOConnection *ADOConnection;
	TADOQuery *ADOQuery;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);

private:	// User declarations

public:		// User declarations
	__fastcall TDataBase(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataBase *DataBase;
//---------------------------------------------------------------------------
#endif
