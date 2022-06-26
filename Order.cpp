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
		return string("�����");
	case Order::Status::PASS:
		return string("���ͨ��");
	case Order::Status::FAIL:
		return string("δͨ��");
	case Order::Status::CANCEL:
		return string("��ȡ��");
	default:
		return string("");
	}
}

bool Order::operator==(const Order& o) const
{
	return (this->id == o.id && this->name == o.name && this->room == o.room
		&& this->time == o.time && this->week == o.week && this->status == o.status);
}
