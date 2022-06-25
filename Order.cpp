#include "Order.h"

Order::Order(string name, int id, int week, int time, Status status)
{
	this->name = name;
	this->id = id;
	this->week = week;
	this->time = time;
	this->status = status;
}

Order::Order()
{
	this->name = "";
	this->id = 0;
	this->week = 0;
	this->time = 0;
	this->status = Status::CANCEL;
}
