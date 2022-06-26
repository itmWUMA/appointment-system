#pragma once
#include <string>
using namespace std;

/*	预约类
	用以存储预约数据
*/
class Order
{
public:
	// 审核状态
	enum class Status
	{
		IN_REVIEW,	// 审核中
		PASS,	// 通过
		FAIL,	// 未通过
		CANCEL,	// 取消
	};

	string name;  // 学生姓名
	int id;  // 学号
	int week;	// 预约时间
	int time;	// 预约时间段
	int room;	// 机房编号
	Status status;	// 预约状态

	Order(string name, int id, int week, int time, int room, Status status);
	Order();

	// 将Status转化字符串
	static string StatusToString(Status s);

	// 重载==操作符
	bool operator==(const Order& o) const;
};