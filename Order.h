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
	Status status;	// 预约状态

	Order(string name, int id, int week, int time, Status status);
	Order();
};