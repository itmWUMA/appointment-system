#include "Controller.h"

void Controller::ParseStudent()
{
	// 读取文件
	ifstream ifs(STU_FILE, ios::in);
	// 文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	// 将解析的数据重新添加至stus中
	this->stus.clear();
	Student stu;
	while (ifs >> stu.id && ifs >> stu.name && ifs >> stu.pwd)
		this->stus.insert(stu);

	// 关闭文件
	ifs.close();
}

void Controller::ParseTeacher()
{
	// 读取文件
	ifstream ifs(TEACHER_FILE, ios::in);
	// 文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	// 将解析的数据重新添加至teachers中
	this->teachers.clear();
	Teacher t;
	while (ifs >> t.id && ifs >> t.name && ifs >> t.pwd)
		this->teachers.insert(t);

	// 关闭文件
	ifs.close();
}

void Controller::ParseAdmin()
{
	// 读取文件
	ifstream ifs(ADMIN_FILE, ios::in);
	// 文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	// 将解析的数据重新添加至stus中
	this->admins.clear();
	Admin admin;
	while (ifs >> admin.name && ifs >> admin.pwd)
		this->admins.insert(admin);

	// 关闭文件
	ifs.close();
}

void Controller::ParseRoom()
{
	// 读取room文件
	ifstream ifs(ROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	// 解析
	rooms.clear();
	Room room;
	while (ifs >> room.id && ifs >> room.capcity)
		rooms.push_back(room);

	// 关闭文件
	ifs.close();
}

void Controller::ParseOrder()
{
	// 读取文件
	ifstream ifs(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	// 解析
	this->orders.clear();
	Order o;
	string name;
	int id, room, week, time, n_status;
	while (ifs >> week && ifs >> time && ifs >> id && ifs >> name && ifs >> room && ifs >> n_status)
	{
		o = Order(name, id, week, time, room, (Order::Status)n_status);
		this->orders.insert(make_pair(id, o));
	}

	// 关闭文件
	ifs.close();
}

void Controller::StartStudent(Student& stu)
{
	int ipt = 0;
	do
	{
		// 显示页面
		stu.OpenMenu();
		cin >> ipt;
		switch (ipt)
		{
		case 1:	// 申请预约
			stu.ApplyOrder(this->rooms);
			// 刷新容器orders
			ParseOrder();
			break;

		case 2:	// 查看我的预约
			stu.ShowMyOrder(this->orders);
			break;

		case 3:	// 查看所有预约
			stu.ShowAllOrder(this->orders);
			break;

		case 4:	// 取消预约
			stu.CancelOrder(this->orders);
			// 刷新容器orders
			ParseOrder();
			break;

		case 0:	// 注销登录
			Logout();
			break;

		default:
			break;
		}
	} while (ipt);
}

void Controller::StartTeacher(Teacher& teacher)
{
	int ipt = 0;
	vector<Order> v;
	do
	{
		// 显示页面
		teacher.OpenMenu();
		cin >> ipt;
		switch (ipt)
		{
		case 0:	// 注销账号
			Logout();
			break;
			
		case 1:	// 查看所有预约
			teacher.ShowAllOrder(this->orders);
			break;

		case 2:	// 审核预约
			v = ToVector(this->orders);
			teacher.ValidOrder(v);
			ParseOrder();
			break;

		default:
			break;
		}
	} while (ipt);
}

void Controller::StartAdmin(Admin& admin)
{
	int ipt = 0;
	do
	{
		// 显示页面
		admin.OpenMenu();

		// 获取输入
		cin >> ipt;
		switch (ipt)
		{
		case 0: // 注销
			Logout();
			break;

		case 1: // 添加账号
			admin.AddPerson();
			// 刷新容器
			ParseStudent();
			ParseTeacher();
			break;

		case 2: // 查看账号
			admin.ShowPerson(this->stus, this->teachers);
			break;

		case 3: // 查看机房
			admin.ShowRoomInfo(this->rooms);
			break;

		case 4: // 清空预约
			admin.ClearFile();
			// 刷新容器orders
			ParseOrder();
			break;

		default:
			break;
		}
	} while (ipt);
}

void Controller::Logout()
{
	cout << "注销成功！" << endl;
	CleanAndPause();
}

vector<Order> Controller::ToVector(multimap<int, Order>& orders)
{
	vector<Order> res;
	for (multimap<int, Order>::const_iterator itor = orders.begin(); itor != orders.end(); itor++)
		res.push_back(itor->second);
	return res;
}

Controller::Controller()
{
	// 解析现有数据
	ParseAdmin();
	ParseStudent();
	ParseTeacher();
	ParseRoom();
	ParseOrder();
}

void Controller::PrintMenu()
{
	cout << "============== 机房预约系统 ==============" << endl;
	cout << "              [1] 学生代表" << endl;
	cout << "              [2] 教   师" << endl;
	cout << "              [3] 管 理 员" << endl;
	cout << "              [0] 退   出" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

void Controller::CleanAndPause()
{
	system("pause");
	system("cls");
}

void Controller::Login(Identity::IdentityType type)
{
	Student stu;
	Admin admin;
	Teacher teacher;

	// 获取用户输入
	int id = 0;
	string name, pwd;
	switch (type)
	{
		// 学生身份
	case Identity::IdentityType::STU:
		cout << "请输入学号：> ";
		cin >> id;
		cout << "请输入姓名：> ";
		cin >> name;
		cout << "请输入密码：> ";
		cin >> pwd;
		// 学生验证身份
		stu = Student(id, name, pwd);
		if (stus.find(stu) != stus.end())
		{
			// 进入学生操作
			StartStudent(stu);
			return;
		}
		break;

		// 教师身份
	case Identity::IdentityType::TEACHER:
		cout << "请输入职工号：> ";
		cin >> id;
		cout << "请输入姓名：> ";
		cin >> name;
		cout << "请输入密码：> ";
		cin >> pwd;
		// 教师身份验证
		teacher = Teacher(id, name, pwd);
		if (teachers.find(teacher) != teachers.end())
		{
			// 进入教师操作
			StartTeacher(teacher);
			return;
		}
		break;

		// 管理员身份
	case Identity::IdentityType::ADMIN:
		cout << "请输入管理员姓名：> ";
		cin >> name;
		cout << "请输入密码：> ";
		cin >> pwd;
		// 管理员身份验证
		admin = Admin(name, pwd);
		if (admins.find(admin) != admins.end())
		{
			// 进入管理员操作
			StartAdmin(admin);
			return;
		}
		break;

	default:
		break;
	}

	// 验证失败
	cout << "验证登录失败！" << endl;
	CleanAndPause();
}
