#pragma once
#include <wx/wx.h>
#include <wx/font.h>
#include "User.h"
#include <wx/listctrl.h>
class MainFrame : public wxFrame
{
	public:
		MainFrame(const wxString& title);
      
        wxStaticText* welcome_txt;
        wxFont heading_font = wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        wxFont button_font = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        void create_task(wxCommandEvent& evt);
        void descibe_task(wxCommandEvent& evt);
        wxPanel* logged;
        wxPanel* notlogged;
        bool isLogged = false;

        wxStaticText* logged_user_name;
        wxStaticText* logged_contact;

    private:
        User u1;
        int count_task{}; //acts as a index for creating tasks.
        wxListCtrl* task_display;
        void sign_up(wxCommandEvent& evt);
        void login(wxCommandEvent& evt);
};

