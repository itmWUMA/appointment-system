#include "Teacher.h"

void Teacher::RewriteOrderFile(const vector<Order>& orders)
{
	ofstream ofs(ORDER_FILE, ios::out);
	for (vector<Order>::const_iterator itor = orders.begin(); itor != orders.end(); itor++)
	{
		ofs << itor->week << " " << itor->time << " " << itor->id << " "
			<< itor->name << " " << itor->room << " " << (int)itor->status << endl;
	}
	ofs.close();
}

Teacher::Teacher()
{
	this->id = 0;
	this->name = "";
	this->pwd = "";
}

Teacher::Teacher(int id, string name, string pwd)
{
	this->id = id;
	this->name = name;
	this->pwd = pwd;
}

bool Teacher::operator==(const Teacher& t)
{
	return (this->id == t.id && this->name == t.name && this->pwd == t.pwd);
}

bool Teacher::operator<(const Teacher& t) const
{
	return (this->id != t.id) ? (this->id < t.id) :
		(this->name != t.name ? this->name < t.name :
			this->pwd < t.pwd);
}

void Teacher::OpenMenu()
{
	system("cls");

	cout << "你好，" << this->name << "老师" << endl;
	cout << "============== 教师操作系统 ==============" << endl;
	cout << "              [1] 查看所有预约" << endl;
	cout << "              [2] 审核预约" << endl;
	cout << "              [0] 注销登录" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

void Teacher::ValidOrder(vector<Order>& orders)
{
	vector<Order> availableOrders;	// 用于存放可审核的预约
	map<int, int> posTable;	// <availableOrders下标, orders下标>

	// 获得可审核的预约
	int oi = 0, aoi = 0;
	for (vector<Order>::iterator itor = orders.begin();
		itor != orders.end(); itor++, oi++)
	{
		if (itor->status == Order::Status::IN_REVIEW)
		{
			availableOrders.push_back(*itor);
			posTable.insert(pair<int, int>(aoi, oi));
			aoi++;
		}
	}

	// 显示可审核的预约
	cout << "您可审核如下预约：" << endl;
	for (size_t i = 0; i < availableOrders.size(); i++)
	{
		cout << "[" << i + 1 << "] " << "机房" << availableOrders[i].room << " "
			<< "星期" << (availableOrders[i].week) << " "
			<< (availableOrders[i].time == 1 ? "上午" : "下午") << " "
			<< Order::StatusToString(availableOrders[i].status) << endl;
	}

	// 选择预约给予审核结果
	cout << "请选择需要审核的预约(退出审核请输入0): > ";
	int ipt = 0;
	while (true)
	{
		cin >> ipt;
		if (ipt == 0)
		{
			cout << "您已取消选择！" << endl;
			break;
		}
		else if (ipt < 0 || ipt >(int)availableOrders.size())
			cout << "选择错误，请重新选择！" << endl;
		else
		{
			// 给予审核
			cout << "您是否给予通过？(Y:1 | N:0) > ";
			int res = 0;
			cin >> res;
			orders[posTable[ipt - 1]].status = (res) ? Order::Status::PASS : Order::Status::FAIL;

			// 重新写入文件
			RewriteOrderFile(orders);

			cout << "已完成审核！" << endl;
			break;
		}
	}

	system("pause");
	system("cls");
}
