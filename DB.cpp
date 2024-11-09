//---------------------------------------------------------------------------
#pragma hdrstop

#include "DB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDataBase *DataBase;
//---------------------------------------------------------------------------
__fastcall TDataBase::TDataBase(TComponent* Owner) : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDataBase::DataModuleCreate(TObject *Sender)
{
    try {
		ADOConnection->Connected = true;
    }
	catch (Exception &E) {
		MessageDlg("Помилка при заванатаженні БД: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TDataBase::DataModuleDestroy(TObject *Sender)
{
	ADOConnection->Connected = false;
}
//---------------------------------------------------------------------------

