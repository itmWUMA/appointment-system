#include "Controller.h"

void Controller::ParseStudent()
{
	// 读取文件
	ifstream ifs(STU_FILE, ios::in | ios::binary);
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
	while (ifs.read((char*)(&stu), sizeof(Student)))
		this->stus.insert(stu);

	// 关闭文件
	ifs.close();
}

void Controller::ParseTeacher()
{
	// 读取文件
	ifstream ifs(TEACHER_FILE, ios::in | ios::binary);
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
	while (ifs.read((char*)(&t), sizeof(Teacher)))
		this->teachers.insert(t);

	// 关闭文件
	ifs.close();
}

void Controller::ParseAdmin()
{
	// 读取文件
	ifstream ifs(ADMIN_FILE, ios::in | ios::binary);
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
	while (ifs.read((char*)(&admin), sizeof(Admin)))
		this->admins.insert(admin);

	// 关闭文件
	ifs.close();
}

Controller::Controller()
{
	// 解析现有数据
	ParseAdmin();
	ParseStudent();
	ParseTeacher();
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

void Controller::Login(string fileName, Identity::IdentityType type)
{
	// 读取文件
	ifstream ifs(fileName, ios::in | ios::binary);

	// 文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	// 获取用户输入
	int id = 0;
	string name, pwd;
	switch (type)
	{
	case Identity::IdentityType::STU:	// 学生身份
		cout << "请输入学号：> ";
		cin >> id;
		cout << "请输入密码：> ";
		cin >> pwd;
		// 解析学生身份
		

		break;
	case Identity::IdentityType::TEACHER:	// 教师身份
		cout << "请输入职工号：> ";
		cin >> id;
		cout << "请输入密码：> ";
		cin >> pwd;
		// 教师身份验证

		break;
	case Identity::IdentityType::ADMIN:	// 管理员身份
		cout << "请输入管理员姓名：> ";
		cin >> name;
		cout << "请输入密码：> ";
		cin >> pwd;
		// 管理员身份验证

		break;
	default:
		break;
	}

	// 验证失败
	cout << "验证登录失败！" << endl;
	CleanAndPause();
}
