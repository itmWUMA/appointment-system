#include "Student.h"

// 将预约写入文件中    [week  time  id  name  room  status]
void Student::WriteOrderFile(vector<Room>& rooms, int i, int week, int time)
{
	ofstream ofs(ORDER_FILE, ios::out | ios::app);
	ofs << week << " "
		<< time << " "
		<< this->id << " "
		<< this->name << " "
		<< rooms[i - 1].id << " "
		<< (int)Order::Status::IN_REVIEW << endl;
	ofs.close();
}

bool Student::IsRepeatOrder(const Order& order)
{
	// 读取Order文件
	ifstream ifs(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return false;
	}

	Order curOrder;
	string name;
	int id, room, week, time, n_status;
	while (ifs >> week && ifs >> time && ifs >> id && ifs >> name && ifs >> room && ifs >> n_status)
	{
		curOrder = Order(name, id, week, time, room, (Order::Status)n_status);
		// 比较两个order是否一致
		if (order == curOrder)
		{
			ifs.close();
			return true;
		}
	}

	ifs.close();
	return false;
}

vector<Order> Student::GetMyOrder(const multimap<int, Order>& orders)
{
	vector<Order> v;
	multimap<int, Order>::const_iterator itor = orders.find(this->id);
	int count = orders.count(this->id);
	for (int i = 0; i < count; i++, itor++)
		v.push_back(itor->second);

	return v;
}

void Student::PrintMyOrder(const vector<Order> myOrders)
{
	for (size_t i = 0; i < myOrders.size(); i++)
	{
		cout << "机房" << myOrders[i].room << " "
			<< "星期" << (myOrders[i].week) << " "
			<< (myOrders[i].time == 1 ? "上午" : "下午") << " "
			<< Order::StatusToString(myOrders[i].status) << endl;
	}
}

vector<Order> Student::GetCanBeCanceledOrder(const multimap<int, Order>& orders)
{
	vector<Order> myOrders = GetMyOrder(orders);
	vector<Order> v;
	for (vector<Order>::iterator itor = myOrders.begin(); itor != myOrders.end(); itor++)
	{
		if (itor->status == Order::Status::PASS || itor->status == Order::Status::IN_REVIEW)
			v.push_back(*itor);
	}
	return v;
}

// [week  time  id  name  room  status]
void Student::RewriteOrderFile(const multimap<int, Order>& orders)
{
	ofstream ofs(ORDER_FILE, ios::out);
	for (multimap<int, Order>::const_iterator itor = orders.begin(); itor != orders.end(); itor++)
	{
		ofs << itor->second.week << " " << itor->second.time << " " << itor->second.id << " "
			<< itor->second.name << " " << itor->second.room << " " << (int)itor->second.status << endl;
	}
	ofs.close();
}

Student::Student()
{
	this->name = "";
	this->pwd = "";
	this->id = 0;
}

Student::Student(int id, string name, string pwd)
{
	this->id = id;
	this->name = name;
	this->pwd = pwd;
}

bool Student::operator==(const Student& stu)
{
	return (this->name == stu.name && this->pwd == stu.pwd && this->id == stu.id);
}

bool Student::operator<(const Student& stu) const
{
	return (this->id != stu.id) ? (this->id < stu.id) : 
		(this->name != stu.name ? this->name < stu.name : 
			this->pwd < stu.pwd);
}

void Student::OpenMenu()
{
	system("cls");

	cout << "你好，" << this->name << "同学" << endl;
	cout << "============== 学生操作系统 ==============" << endl;
	cout << "              [1] 申请预约" << endl;
	cout << "              [2] 查看我的预约" << endl;
	cout << "              [3] 查看所有预约" << endl;
	cout << "              [4] 取消预约" << endl;
	cout << "              [0] 注销登录" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

void Student::ApplyOrder(vector<Room>& rooms)
{
	// 获取预约时间
	cout << "请选择预约的时间(周一至周五开放): > ";
	int iptWeek = 0;
	while (true)
	{
		cin >> iptWeek;
		if (iptWeek > 0 && iptWeek <= 5)
			break;
		cout << "输入错误！" << endl;
	}

	// 获取预约时间段
	cout << "请选择预约的时间段([1]上午 | [2]下午): > ";
	int iptTime = 0;
	while (true)
	{
		cin >> iptTime;
		if (iptTime == 1 || iptTime == 2)
			break;
		cout << "输入错误！" << endl;
	}

	// 显示机房信息
	cout << "请选择机房(输入编号选择，退出输入0)：" << endl;
	for (vector<Room>::iterator itor = rooms.begin(); itor != rooms.end(); itor++)
		cout << "- 机房" << itor->id << "容量" << itor->capcity << endl;
	// 获取用户选择
	cout << "> ";
	int iptRoom = 0;

	while (true)
	{
		cin >> iptRoom;
		if (iptRoom >= 1 && iptRoom <= 3)
		{
			// 判断是否重复预约
			if (IsRepeatOrder(Order(this->name, this->id, iptWeek, iptTime, iptRoom, Order::Status::IN_REVIEW)))
			{
				cout << "该预约已记录，请勿重复预约！" << endl;
				system("pause");
				system("cls");
				return;
			}
			// 将预约信息写入文件中
			WriteOrderFile(rooms, iptRoom, iptWeek, iptTime);
			cout << "预约已提交，请等待审核" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "输入错误！" << endl;
	}

	system("pause");
	system("cls");
}

void Student::ShowMyOrder(const multimap<int, Order>& orders)
{
	// 获取预约信息
	vector<Order> myOrders = GetMyOrder(orders);
	int count = myOrders.size();
	if (count == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	// 遍历打印所有预约记录
	cout << "预约记录如下(机房编号 预约时间 预约时间段 当前状态)：" << endl;
	PrintMyOrder(myOrders);

	system("pause");
	system("cls");
}

void Student::CancelOrder(multimap<int, Order>& orders)
{
	// 获取我的预约记录
	vector<Order> myOrders = GetMyOrder(orders);
	if (myOrders.size() == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	// 打印所有当前预约
	cout << "您有如下预约可以取消：" << endl;
	vector<Order> cbcOrders = GetCanBeCanceledOrder(orders);
	for_each(cbcOrders.begin(), cbcOrders.end(), CancelOrderPrintHandler());
	cout << "请选择需要取消的预约(取消请输入0)：> ";

	// 获取输入
	int ipt = 0;
	while (true)
	{
		cin >> ipt;
		if (ipt == 0)
		{
			cout << "您已取消选择！" << endl;
			break;
		}
		else if (ipt < 0 || ipt > (int)cbcOrders.size())
			cout << "选择错误，请重新选择！" << endl;
		else
		{
			// 修改orders中的数据
			int count = orders.count(this->id);
			multimap<int, Order>::iterator itor = orders.find(this->id);
			for (int i = 0; i < count; i++, itor++)
			{
				if (itor->second == cbcOrders[ipt - 1])
					itor->second.status = Order::Status::CANCEL;
			}
			// 重新写入文件
			RewriteOrderFile(orders);
			cout << "已取消预约！" << endl;
			break;
		}
	}

	system("pause");
	system("cls");
}

void Student::CancelOrderPrintHandler::operator()(const Order& o)
{
	cout << "[" << this->count + 1 << "] "
		<< "机房" << o.room << " "
		<< "星期" << (o.week) << " "
		<< (o.time == 1 ? "上午" : "下午") << " "
		<< Order::StatusToString(o.status) << endl;
	this->count++;
}
