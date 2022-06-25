#include "Order.h"

Order::Order(string name, int id, int week, int time, int room, Status status)
{
	this->name = name;
	this->id = id;
	this->week = week;
	this->time = time;
	this->room = room;
	this->status = status;
}

Order::Order()
{
	this->name = "";
	this->id = 0;
	this->week = 0;
	this->time = 0;
	this->room = 0;
	this->status = Status::CANCEL;
}

string Order::StatusToString(Status s)
{
	switch (s)
	{
	case Order::Status::IN_REVIEW:
		return string("审核中");
	case Order::Status::PASS:
		return string("审核通过");
	case Order::Status::FAIL:
		return string("未通过");
	case Order::Status::CANCEL:
		return string("已取消");
	default:
		return string("");
	}
}