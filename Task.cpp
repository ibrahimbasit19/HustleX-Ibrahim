#include "Task.h"
#include "User.h"
Task::Task()
{

}

void Task::setUser(User* user)
{
	this->user = user;
}


std::string Task::get_contact_USER()
{
	return this->user->getContactNo();
}

Task::Task(std::string title, std::string description) :
	title(title), description(description) {
}

void Task::setTitle(std::string title)
{
	this->title = title;
}

void Task::setDescription(std::string description)
{
	this->description = description;
}

void Task::setAddress(std::string address)
{
	this->address = address;
}

void Task::setReward(int value)
{
	this->task_reward = value;
}

std::string Task::getAddress()
{
	return this->address;
}

std::string Task::getTitle()
{
	return this->title;
}

std::string Task::getDescription()
{
	return this->description;
}

int Task::Get_task_reward()
{
	return this->task_reward;
}

bool Task::getState()
{
	return this->isDone;

}

std::string Task::give_phoneNum()
{
	return this->phone_number;
}

void Task::set_phoneNum()
{
	this->phone_number = this->user->getContactNo();
}

