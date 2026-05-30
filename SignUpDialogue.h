#pragma once
#include <wx/wx.h>
#include <wx/dialog.h>



class SignUpDialogue : public wxDialog
{
private:
	wxTextCtrl* user_name;
	wxTextCtrl* password;
	wxTextCtrl* contact;

public:
	SignUpDialogue(const wxString& title);
	wxFont heading_font = wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont label_font = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	void save_account(wxCommandEvent& evt); // create and save the account in file.

};

