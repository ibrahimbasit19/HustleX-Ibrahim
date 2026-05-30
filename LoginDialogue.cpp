#include "LoginDialogue.h"
#include <wx/wx.h>
#include <wx/dialog.h>
#include <fstream>
#include <string>
#include <vector>
LoginDialogue::LoginDialogue(const wxString& title) : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(500, 500))
{
	/// --------------- GUI STUFF -------------------------------------
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 500));
	panel->SetBackgroundColour(wxColour(7, 42, 11));

	wxStaticText* sign_up_label = new wxStaticText(panel, wxID_ANY, "Sign In", wxPoint(175, 25));
	sign_up_label->SetFont(this->heading_font);
	sign_up_label->SetForegroundColour(wxColor(255, 255, 255));


	wxStaticText* user_name_label = new wxStaticText(panel, wxID_ANY, "Enter Username", wxPoint(25, 75));
	user_name_label->SetForegroundColour(wxColor(255, 255, 255));
	wxStaticText* password_label = new wxStaticText(panel, wxID_ANY, "Enter Password", wxPoint(225, 75));
	password_label->SetForegroundColour(wxColor(255, 255, 255));
	

	user_name = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(25, 100));
	password = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(225, 100), wxDefaultSize, wxTE_PASSWORD);
	

	wxButton* login_button = new wxButton(panel, wxID_ANY, "Login", wxPoint(175, 400));
	login_button->Bind(wxEVT_BUTTON, &LoginDialogue::login_account, this);
	/// ---------------   -------------------------------------
}

void LoginDialogue::login_account(wxCommandEvent& evt)
{

	std::string user_name_entered = user_name->GetValue().ToStdString();
	std::string password_entered = password->GetValue().ToStdString();

	if (user_name_entered == "")
	{
		wxLogError("Enter a Username to login!");
	}

	if (password_entered == "")
	{
		wxLogError("Enter a password!");
	}

	if (user_name_entered != "" && password_entered != "")
	{
		std::ifstream file{ "User.txt" };
		std::string str_input{};
		std::string name;

		//capturing all the items from User.txt and storing them in inputs vector for comparison.
		std::vector <std::string> inputs;
		while (std::getline(file, str_input))
		{
			inputs.push_back(str_input);
		}




		int index = give_index(user_name_entered, inputs);
		std::string user_name_actual = inputs[index];
		std::string password_actual = inputs[index + 1];
		std::string contact = inputs[index + 2];

		if (password_actual == password_entered)
		{
			 wxLogMessage("You have logged in.");
			 this->USER_NAME_APPROVED = user_name_actual;
			 this->USER_CONTACT_APPROVED = contact;
			 //now we will give all these details to mainframe.cpp and we will use getters from this class and 
			 // use setters from user class to set the user in mainframe.cpp


			this->Destroy();
		}
		else
		{
			wxLogMessage("Wrong Password , Try again");
		}

	}

	
	
	
	
}

int LoginDialogue::give_index(std::string username, std::vector <std::string>& input_vect)
{
	int index = 0;
	
	for (int i = 0; i < input_vect.size(); i += 4)
	{
		
		if (username == input_vect[i])
		{
			index = i;
			break;
		}
		
	}

	return index;
}


std::string LoginDialogue::give_final_username()
{
	return this->USER_NAME_APPROVED;
}
std::string LoginDialogue::give_final_contact()
{
	return this->USER_CONTACT_APPROVED;
}