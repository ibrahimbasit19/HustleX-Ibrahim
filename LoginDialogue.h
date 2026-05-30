#pragma once
#include <wx/wx.h>
#include <wx/dialog.h>
class LoginDialogue : public wxDialog
{
private:
	wxTextCtrl* user_name;
	wxTextCtrl* password;
	std::string USER_NAME_APPROVED;
	std::string USER_CONTACT_APPROVED;


	int give_index(std::string username, std::vector <std::string>& input_vect); // gives the index of the user details by searching it's username.
public:
	LoginDialogue(const wxString& title);
	wxFont heading_font = wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont label_font = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	void login_account(wxCommandEvent& evt); // open the  file.
	

	std::string give_final_username();
	std::string give_final_contact();
};

