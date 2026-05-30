#include "User.h"
#include <iostream>
#include "Task.h"


User::User(std::string userName, std::string address,
	std::string email, std::string contactNo)
	:userName(userName),
	email(email), contactNo(contactNo) {
};

std::string User::getUserName()
{
	return this->userName;
}


std::string User::getEmail()
{
	return this->email;
}
std::string User::getContactNo()
{
	return this->contactNo;
}
void User::setUserName(std::string userN)
{
	this->userName = userN;
}


void User::setEmail(std::string email)
{
	this->email = email;
}
void User::setContactNo(std::string contNo)
{
	this->contactNo = contNo;
}


void User::create_task(int index, std::string title, std::string desc, std::string address, int reward)
{
	this->tasks[index].setTitle(title);
	this->tasks[index].setDescription(desc);
	this->tasks[index].setAddress(address);
	this->tasks[index].setReward(reward);
	
}

size_t User::give_INDEX_TASKNAME(std::string target) // we use this function later in taskdescriptiondialogue
{
	size_t index = 0;

	for (int i = 0; i < 5; i++)
	{
		if (this->tasks[i].getTitle() == target)
		{
			index = i;
			break;
		}
	}
	return index;
}


std::string User::get_US_task_title(int index)
{
	return this->tasks[index].getTitle();
}

std::string User::get_US_task_desc(int index)
{
	return this->tasks[index].getDescription();
}

int User::get_US_task_rew(int index)
{
	return this->tasks[index].Get_task_reward();
}

std::string User::get_US_task_address(int index)
{
	return this->tasks[index].getAddress();
}

void User::setUSER_US(int index, User* user)
{
	this->tasks[index].setUser(user);
}

std::string User::getUSER_CONTACT(int index)
{
	return this->tasks[index].give_phoneNum();
}

void User::setTaskPhone(int index)
{
	this->tasks[index].set_phoneNum();
}