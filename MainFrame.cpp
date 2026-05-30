#include "MainFrame.h" 
#include <wx/wx.h> 
#include <wx/simplebook.h>
#include <wx/listctrl.h>
#include "CreateTaskDialogue.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <string>
#include "TaskDescriptionDialogue.h"
#include "SignUpDialogue.h"
#include "LoginDialogue.h"
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{ 
	//u1.setContactNo("03331778227");

	// master panels and master sizer.
	wxPanel* root = new wxPanel(this);
	wxBoxSizer* rootsizer = new wxBoxSizer(wxVERTICAL);



	// -- Upper Panel content
	wxPanel* upper_panel = new wxPanel(root);
	upper_panel->SetBackgroundColour(wxColor(35, 35, 35)); 

	welcome_txt = new wxStaticText(upper_panel, wxID_ANY, "", wxDefaultPosition); 
	welcome_txt->SetForegroundColour(wxColor(*wxWHITE)); 
	welcome_txt->SetFont(heading_font); 


	wxString path = wxStandardPaths::Get().GetExecutablePath();
	wxFileName file(path);
	file.SetFullName("Hustle X Logo.png");
	wxBitmap bitmap(file.GetFullPath(), wxBITMAP_TYPE_PNG);

	wxBitmapButton* hustleX = new wxBitmapButton(upper_panel, wxID_ANY, bitmap, wxDefaultPosition, wxDefaultSize);
	hustleX->SetOwnForegroundColour(wxColor(*wxWHITE));
	hustleX->SetOwnBackgroundColour(wxColor(35, 35, 35));
	hustleX->SetFont(button_font); 
	hustleX->Refresh();
	hustleX->SetWindowStyle(wxBORDER_NONE);
	wxBoxSizer* box_sizer = new wxBoxSizer(wxHORIZONTAL); 
	box_sizer->Add(welcome_txt,1, wxLEFT | wxRIGHT, 50); 
	box_sizer->Add(hustleX);
	upper_panel->SetSizer(box_sizer);
	box_sizer->SetSizeHints(this);

	rootsizer->Add(upper_panel, 0, wxEXPAND);
	//  Upper Panel content   --


	// configuring main content_panel
	wxPanel* content_panel = new wxPanel(root);
	wxBoxSizer* contentSizer = new wxBoxSizer(wxHORIZONTAL);
	rootsizer->Add(content_panel, 1, wxEXPAND);

	// navbar setup 
	wxPanel* navbar = new wxPanel(content_panel);
	navbar->SetBackgroundColour(wxColor(30, 30, 30));
	navbar->SetMinSize(wxSize(180, -1)); 

	wxBoxSizer* navSizer = new wxBoxSizer(wxVERTICAL);


	// buttons for navbar , btn1, btn2, btn3 and lastly btn4
	wxButton* btn1 = new wxButton(navbar, wxID_ANY, "Task Search");
	btn1->SetOwnForegroundColour(wxColor(*wxWHITE));
	btn1->SetOwnBackgroundColour(wxColor(98, 255, 100));
	btn1->SetFont(button_font); 
	btn1->Refresh();
	btn1->SetWindowStyle(wxBORDER_NONE);

	wxButton* btn2 = new wxButton(navbar, wxID_ANY, "Stats");
	btn2->SetOwnForegroundColour(wxColor(*wxWHITE));
	btn2->SetOwnBackgroundColour(wxColor(98, 255, 100));
	btn2->SetFont(button_font); 
	btn2->Refresh();
	btn2->SetWindowStyle(wxBORDER_NONE);

	wxButton* btn3 = new wxButton(navbar, wxID_ANY, "Profile");
	btn3->SetOwnForegroundColour(wxColor(*wxWHITE));
	btn3->SetOwnBackgroundColour(wxColor(98, 255, 100));
	btn3->SetFont(button_font); 
	btn3->Refresh();
	btn3->SetWindowStyle(wxBORDER_NONE);

	wxButton* btn4 = new wxButton(navbar, wxID_ANY, "Create a Task");
	btn4->SetOwnForegroundColour(wxColor(*wxWHITE));
	btn4->SetOwnBackgroundColour(wxColor(98, 255, 100));
	btn4->SetFont(button_font); 
	btn4->Refresh();
	btn4->SetWindowStyle(wxBORDER_NONE);


	navSizer->Add(btn1, 0, wxEXPAND | wxALL, 5);
	navSizer->AddSpacer(10);
	navSizer->Add(btn2, 0, wxEXPAND | wxALL, 5);
	navSizer->AddSpacer(10);
	navSizer->Add(btn3, 0, wxEXPAND | wxALL, 5);
	navSizer->AddSpacer(10);
	navSizer->Add(btn4, 0, wxEXPAND | wxALL, 5);
	navSizer->AddSpacer(10);

	navbar->SetSizer(navSizer);


	wxPanel* view_panel = new wxPanel(content_panel);
	view_panel->SetBackgroundColour(wxColor(45, 45, 45));

	contentSizer->Add(navbar, 0, wxEXPAND);
	contentSizer->Add(view_panel, 1, wxEXPAND);

	content_panel->SetSizer(contentSizer);

	root->SetSizer(rootsizer);
	rootsizer->SetSizeHints(this);

	// -- navbar setup
	wxSimplebook* book = new wxSimplebook(view_panel, wxID_ANY);

	wxPanel* page1 = new wxPanel(book);
		
		// later turn page1 code into function.
		wxStaticText* task_find_heading = new wxStaticText(page1, wxID_ANY, "Find Task : ", wxPoint(30, 30));
		task_find_heading->SetFont(heading_font);
		task_find_heading->SetForegroundColour(wxColor(*wxWHITE)); 


		task_display = new wxListCtrl(page1, wxID_ANY, wxPoint(30,70), wxSize(1300, 500), wxLC_REPORT | wxLC_SINGLE_SEL | wxLB_NEEDED_SB);
		task_display->InsertColumn(0, "Task Title", wxLIST_FORMAT_LEFT, 200);
		task_display->InsertColumn(1, "Task Description:", wxLIST_FORMAT_LEFT, 700);
		task_display->InsertColumn(2, "Task Reward : ", wxLIST_FORMAT_LEFT, 200);
		task_display->InsertColumn(3, "Address : (Location)", wxLIST_FORMAT_LEFT, 200);


		wxButton* refreshButton = new wxButton(page1, wxID_ANY, "Refresh Tasks",  wxPoint(30, 600), wxSize(200, 100));
		refreshButton->SetFont(button_font);
		wxButton* task_description_button = new wxButton(page1, wxID_ANY, "Task Description", wxPoint(270, 600), wxSize(200, 100));
		task_description_button->SetFont(button_font);
		task_description_button->Bind(wxEVT_BUTTON, &MainFrame::descibe_task, this);

	wxPanel* page2 = new wxPanel(book);

	wxPanel* page3 = new wxPanel(book);
		
		 notlogged = new wxPanel(page3, wxID_ANY, wxPoint(10,0), wxSize(1800, 1000));

			notlogged->SetBackgroundColour(wxColor(45, 45, 45));
			wxButton* sign_up = new wxButton(notlogged, wxID_ANY, "Sign Up", wxPoint(550,400), wxSize(200,100));
			sign_up->SetFont(button_font);
			sign_up->Bind(wxEVT_BUTTON, &MainFrame::sign_up, this);
			wxButton* login = new wxButton(notlogged, wxID_ANY , "Login", wxPoint(850,400), wxSize(200, 100));
			login->SetFont(button_font);
			login->Bind(wxEVT_BUTTON, &MainFrame::login, this);

		 logged = new wxPanel(page3, wxID_ANY, wxPoint(10, 0), wxSize(1800, 1000));

			logged->SetBackgroundColour(wxColor(45, 45, 45));
			wxStaticText* USERNAME_LABEL = new wxStaticText(logged, wxID_ANY, "USERNAME :", wxPoint(200, 100), wxDefaultSize);
			USERNAME_LABEL->SetFont(heading_font);
			USERNAME_LABEL->SetForegroundColour(wxColor(255, 255, 255));
			wxStaticText* CONTACT_LABEL = new wxStaticText(logged, wxID_ANY, "Contact : ", wxPoint(500, 100), wxDefaultSize);
			CONTACT_LABEL->SetFont(heading_font);
			CONTACT_LABEL->SetForegroundColour(wxColor(255, 255, 255));

			logged_user_name = new wxStaticText(logged, wxID_ANY, "", wxPoint(200, 150), wxDefaultSize);
			logged_user_name->SetFont(heading_font);
			logged_user_name->SetForegroundColour(wxColor(255, 255, 255));

			logged_contact = new wxStaticText(logged, wxID_ANY, "", wxPoint(500, 150), wxDefaultSize);
			logged_contact->SetFont(heading_font);
			logged_contact->SetForegroundColour(wxColor(255, 255, 255));


			wxButton* loogin = new wxButton(logged, wxID_ANY, "Switch account", wxPoint(850, 400), wxSize(200, 100));
			loogin->SetFont(button_font);
			loogin->Bind(wxEVT_BUTTON, &MainFrame::login, this);

			logged->Hide();
			notlogged->Hide();

		if (this->isLogged == false)
		{
			logged->Hide();
			notlogged->Show();
				
		}
		else
		{
			notlogged->Hide();
			logged->Show();
		}
		page3->Layout();



	wxPanel* page4 = new wxPanel(book);
		// later convert into function.
	wxButton* create_task = new wxButton(page4, wxID_ANY, "Create a task", wxPoint(200, 200), wxSize(100, 100));
	create_task->Bind(wxEVT_BUTTON, &MainFrame::create_task, this);

	book->AddPage(page1, "Task Search");
	book->AddPage(page2, "Stats");
	book->AddPage(page3, "Profile");
	book->AddPage(page4, "Create a Task");

	wxBoxSizer* viewSizer = new wxBoxSizer(wxVERTICAL);
	viewSizer->Add(book, 1, wxEXPAND);
	view_panel->SetSizer(viewSizer);


	btn1->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		book->ChangeSelection(0);
		});
	btn2->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		book->ChangeSelection(1);
		});
	btn3->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		book->ChangeSelection(2);
		});
	btn4->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		book->ChangeSelection(3);
		});
}

void MainFrame::create_task(wxCommandEvent& evt)
{

	if (this->count_task < 30 && this->isLogged == true)
	{
		CreateTaskDialogue* task_dialogue = new CreateTaskDialogue("Create a task");
		task_dialogue->ShowModal();


		this->u1.create_task(this->count_task, task_dialogue->get_entered_task_title(), task_dialogue->get_entered_task_desc(),
			task_dialogue->get_entered_address(), task_dialogue->get_entered_task_price());

		this->u1.setUSER_US(this->count_task, &this->u1);
		this->u1.setTaskPhone(this->count_task);
		long index = this->task_display->InsertItem(this->task_display->GetItemCount(), this->u1.get_US_task_title(this->count_task));

		//wxString formatted_reward = wxString::Format("",)); // basically for display purposes our task_display 
		// can only output strings so we are formatting price as string because it is integer.


		this->task_display->SetItem(index, 1, this->u1.get_US_task_desc(this->count_task));
		this->task_display->SetItem(index, 2, std::to_string(this->u1.get_US_task_rew(this->count_task)));
		this->task_display->SetItem(index, 3, this->u1.get_US_task_address(this->count_task));

		this->count_task++; // later make this count_task variable user dependent not independant.
		task_dialogue->Destroy();
	}


	else

	{
		wxLogMessage("Login Required!");
	}



}

void MainFrame::descibe_task(wxCommandEvent& evt)
{

	long selected_Row = this->task_display->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

	if (selected_Row != -1)
	{
		// DEBUG FOR CHECKING
	//wxLogMessage("Name : %s", this->task_display->GetItemText(selected_Row, 0));

	//wxLogMessage("Description : %s", this->task_display->GetItemText(selected_Row, 1));

	//wxLogMessage("Reward : %s", this->task_display->GetItemText(selected_Row, 2));

		wxString task_name = this->task_display->GetItemText(selected_Row, 0);
		wxString task_desc = this->task_display->GetItemText(selected_Row, 1);
		wxString task_reward = this->task_display->GetItemText(selected_Row, 2);
		wxString task_address = this->task_display->GetItemText(selected_Row, 3);


		// finding contact number 

		std::string target;

		std::string task_name_str = task_name.ToStdString();

		size_t index = this->u1.give_INDEX_TASKNAME(task_name_str);
		std::string contact = this->u1.getUSER_CONTACT(index);

		wxLogMessage(contact);

		wxString task_contact = contact;

		//TaskDescriptionDialogue dialogue("Task Description", task_name, task_desc, task_reward);
		TaskDescriptionDialogue dialogue("Task", task_name, task_desc, task_reward, task_address, task_contact);
		dialogue.ShowModal();
		dialogue.Destroy();
	}
	else
	{
		wxLogMessage("Select a task!");
	}
	
	
}


void MainFrame::sign_up(wxCommandEvent& evt)
{
	SignUpDialogue* s = new SignUpDialogue("Sign UP");
	s->ShowModal();
	s->Destroy();
}


void MainFrame::login(wxCommandEvent& evt)
{
	LoginDialogue* ld = new LoginDialogue("Login");
	ld->ShowModal();
	this->u1.setUserName(ld->give_final_username());

	wxLogMessage(this->u1.getUserName());


	this->u1.setContactNo(ld->give_final_contact());
	this->welcome_txt->SetLabelText("Welcome " + wxString::Format("%s", this->u1.getUserName()));
	this->welcome_txt->Update();
	this->isLogged = true;
	this->logged_user_name->SetLabel(wxString::Format("%s", this->u1.getUserName()));
	this->logged_contact->SetLabel(wxString::Format("%s", this->u1.getContactNo()));


	logged->Show();
	notlogged->Hide();
	ld->Destroy();
}