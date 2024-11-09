//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Notes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormNotes *FormNotes;
//---------------------------------------------------------------------------
__fastcall TFormNotes::TFormNotes(TComponent* Owner, int orderId, int emplId) : TForm(Owner), orderId(orderId), emplId(emplId)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormNotes::FormShow(TObject *Sender)
{
	LabelNote->Caption = "Замітки до замовлення: №" + IntToStr(orderId);
	LoadNotes();
}
//---------------------------------------------------------------------------
void TFormNotes::LoadNotes()
{
	DataBase->ADOQuery->SQL->Text = "SELECT Roles.title, Employees.name, Notes.note_date, Notes.note_time, Notes.note "
	  "FROM Notes "
	  "JOIN Employees ON Notes.empl_id = Employees.id "
	  "JOIN Roles ON Employees.role_id = Roles.id "
	  "WHERE Notes.order_id = " + IntToStr(orderId) + " "
	"ORDER BY Notes.note_date ASC, Notes.note_time ASC";

	try {
		DataBase->ADOQuery->Open();

		RichEditNotes->Clear();

		while (!DataBase->ADOQuery->Eof)
		{
			String employeeRole = DataBase->ADOQuery->FieldByName("title")->AsString;
			String employeeName = DataBase->ADOQuery->FieldByName("name")->AsString;
			String noteDate = FormatDateTime("dd-mm-yyyy", DataBase->ADOQuery->FieldByName("note_date")->AsDateTime);
			String noteTime = FormatDateTime("hh:nn:ss", DataBase->ADOQuery->FieldByName("note_time")->AsDateTime);
			String noteText = DataBase->ADOQuery->FieldByName("note")->AsString;

			RichEditNotes->Lines->Add(employeeRole + " | " + employeeName + " [" + noteDate + " " + noteTime + "]");
			RichEditNotes->Lines->Add(noteText);
			RichEditNotes->Lines->Add("");

			DataBase->ADOQuery->Next();
		}

		DataBase->ADOQuery->Close();

	} catch (const Exception &E) {
		MessageDlg("Помилка при отриманні списку заміток: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
        this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormNotes::ButtonConfirmClick(TObject *Sender)
{
	if (MemoText->Text.IsEmpty()) { ShowMessage("Будь ласка, введіть текст замітки."); return; }

	String currentDate = FormatDateTime("yyyy-mm-dd", Now());
	String currentTime = FormatDateTime("hh:nn:ss", Now());

	DataBase->ADOQuery->SQL->Text = "INSERT INTO Notes (order_id, empl_id, note_date, note_time, note) "
		"VALUES ('" + IntToStr(orderId) + "', '" + IntToStr(emplId) + "', '" + currentDate + "', '" + currentTime + "', '" + MemoText->Text.Trim() + "')";

	try {
		DataBase->ADOQuery->ExecSQL();

		MemoText->Clear();
		LoadNotes();

	} catch (const Exception &E) {
		MessageDlg("Помилка при додаванні замітки: " + E.Message, mtError, TMsgDlgButtons() << mbOK, 0);
	}
}

void __fastcall TFormNotes::ButtonCancelClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
