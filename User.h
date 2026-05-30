#pragma once
#include <iostream>
#include "Task.h"

class Task;

class User
{
private:
	std::string userName;
	Task tasks[30];
	std::string email;
	std::string contactNo;
public:
	User() = default;
	User(std::string userName, std::string address,
		std::string email, std::string contactNo);

	std::string getUserName();
	void setUSER_US(int index, User* user);
	std::string getUSER_CONTACT(int index);
	std::string getTasks();

	std::string getEmail();

	std::string getContactNo();

	void setUserName(std::string userN);

	size_t give_INDEX_TASKNAME(std::string target); // finds index of task by taking it's name.
	void setTasks(std::string tasks); // discard me later.

	void setEmail(std::string email);

	void setContactNo(std::string contNo);

	void create_task(int index, std::string title, std::string desc, std::string address, int reward);
	std::string get_US_task_address(int index);

	void setTaskPhone(int index);
	std::string get_US_task_title(int index); // these functions are called from user and they give title of the task at certain index.
	std::string get_US_task_desc(int index);
	int get_US_task_rew(int index);

};

