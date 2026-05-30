#include "TaskDescriptionDialogue.h"
#include <wx/wx.h>
#include <iostream>
#include <wx/spinctrl.h>


TaskDescriptionDialogue::TaskDescriptionDialogue(const wxString& title, wxString task_title,
	wxString task_des, wxString task_reward, wxString task_address, wxString contact) : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(500, 500)) ,
	task_title(task_title) , task_desc(task_des), task_reward(task_reward), task_address(task_address)
{
	wxStaticText* task_title_txt = new wxStaticText(this, wxID_ANY, "Task Title",
		wxPoint(10, 0), wxDefaultSize);


	wxStaticText* TaskTitle = new wxStaticText(this, wxID_ANY, task_title, wxPoint(10, 30), wxDefaultSize);

	wxStaticText* task_desc_txt = new wxStaticText(this, wxID_ANY, "Task Description:", wxPoint(200, 0), wxDefaultSize);
	wxTextCtrl* task_desc = new wxTextCtrl(this, wxID_ANY, this->task_desc, wxPoint(200, 100), wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);

	wxStaticText* task_reward_txt = new wxStaticText(this, wxID_ANY, "Task Reward :", wxPoint(10, 70), wxDefaultSize);
	wxStaticText* task_rew = new wxStaticText(this, wxID_ANY, this->task_reward, wxPoint(10, 100));

	wxStaticText* user_address_txt = new wxStaticText(this, wxID_ANY, "Task Address:", wxPoint(10, 130),
		wxDefaultSize);
	wxTextCtrl *user_address = new wxTextCtrl(this, wxID_ANY, this->task_address , wxPoint(10, 160),
		wxSize(200, 100), wxTE_MULTILINE | wxTE_READONLY);

	wxStaticText* user_contact_label = new wxStaticText(this, wxID_ANY, "User Contact : ", wxPoint(10, 300), wxDefaultSize);
	wxStaticText* user_contact = new wxStaticText(this, wxID_ANY, contact, wxPoint(10, 350), wxDefaultSize);


	wxButton* close = new wxButton(this, wxID_ANY, "Close", wxPoint(400, 300), wxDefaultSize);
	close->Bind(wxEVT_BUTTON, &TaskDescriptionDialogue::close, this);


}


void TaskDescriptionDialogue::close(wxCommandEvent& evt)
{
	this->Destroy();
}