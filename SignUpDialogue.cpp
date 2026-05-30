#include "SignUpDialogue.h"
#include <fstream>


SignUpDialogue::SignUpDialogue(const wxString& title) : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(500, 500))
{

	/// --------------- GUI STUFF -------------------------------------
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 500));
	panel->SetBackgroundColour(wxColour(7, 42, 11));

	wxStaticText* sign_up_label = new wxStaticText(panel, wxID_ANY, "Sign Up", wxPoint(175, 25));
	sign_up_label->SetFont(this->heading_font);
	sign_up_label->SetForegroundColour(wxColor(255, 255, 255));


	wxStaticText* user_name_label = new wxStaticText(panel, wxID_ANY, "Enter Username", wxPoint(25, 75));
	user_name_label->SetForegroundColour(wxColor(255, 255, 255));
	wxStaticText* password_label = new wxStaticText(panel, wxID_ANY, "Enter Password", wxPoint(225, 75));
	password_label->SetForegroundColour(wxColor(255, 255, 255));
	wxStaticText* contact_label = new wxStaticText(panel, wxID_ANY, "Enter Contact No", wxPoint(25, 150));
	contact_label->SetForegroundColour(wxColor(255, 255, 255));
	 user_name = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(25, 100));
	 password = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(225, 100), wxDefaultSize, wxTE_PASSWORD);
	 contact = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(25, 175), wxDefaultSize);

	wxButton* create_acc = new wxButton(panel, wxID_ANY, "Create Account", wxPoint(175, 400));
	create_acc->Bind(wxEVT_BUTTON, &SignUpDialogue::save_account, this);
	/// ---------------   -------------------------------------

}

void SignUpDialogue::save_account(wxCommandEvent& evt)
{



	std::string name = this->user_name->GetValue().ToStdString();
	std::string pass = this->password->GetValue().ToStdString();
	std::string contact = this->contact->GetValue().ToStdString();

	if (name == "")
	{
		wxLogError("Enter a User Name!");
	}

	if (pass == "")
	{
		wxLogError("Enter a password.");
	}

	if (contact == "")
	{
		wxLogError("Enter a contact. You cannot keep this empty.");
	}

	if (name != "" && pass != "" && contact != "")
	{
		// now we are writing...,
		std::ofstream file;
		file.open("User.txt", std::ios::app);
		file << "----" << "\n";
		file << name << "\n";
		file << pass << "\n";
		file << contact << "\n";
		
		file.close();
		this->Destroy();
	}
	else
	{
		wxLogMessage("Something is wrong, Try again.");
	}




}
