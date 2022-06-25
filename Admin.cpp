#include "Admin.h"

Admin::Admin()
{
	this->name = "";
	this->pwd = "";
}

Admin::Admin(string name, string pwd)
{
	this->name = name;
	this->pwd = pwd;
}

bool Admin::operator==(const Admin& a)
{
	return (this->name == a.name && this->pwd == a.pwd);
}

bool Admin::operator<(const Admin& a) const
{
	return this->name < a.name;
}

void Admin::OpenMenu()
{
	system("cls");

	cout << "你好，" << this->name << endl;
	cout << "============== 管理员操作系统 ==============" << endl;
	cout << "              [1] 添加账号" << endl;
	cout << "              [2] 查看账号" << endl;
	cout << "              [3] 查看机房" << endl;
	cout << "              [4] 清空预约" << endl;
	cout << "              [0] 注销登录" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

void Admin::AddPerson()
{
	ofstream ofs;
	string fileName, idName;

	cout << "请输入添加账号的类型([1]学生 | [2]老师) > ";
	int ipt = 0;
	cin >> ipt;


	// 选项的配置
	if (ipt == 1)
	{
		fileName = STU_FILE;
		idName = "学号";
	}
	else if (ipt == 2)
	{
		fileName = TEACHER_FILE;
		idName = "职工号";
	}
	else
	{
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
		return;
	}

	// 录入信息
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name, pwd;
	cout << "请输入" << idName << "> ";
	cin >> id;
	cout << "请输入姓名：> ";
	cin >> name;
	cout << "请输入密码：> ";
	cin >> pwd;
	ofs << id << ' ' << name << ' ' << pwd << endl;
	ofs.close();
	cout << "录入成功！" << endl;

	system("pause");
	system("cls");
}

void Admin::ShowPerson(const set<Student>& stus, const set<Teacher>& teachers)
{
	cout << "请输入需要查找的账号类型([1]学生 | [2]老师)：> ";
	int ipt = 0;
	cin >> ipt;
	if (ipt == 1)
	{
		for (set<Student>::iterator itor = stus.begin(); itor != stus.end(); itor++)
			cout << itor->id << " " << itor->name << " " << itor->pwd << endl;
	}
	else if (ipt == 2)
	{
		for (set<Teacher>::iterator itor = teachers.begin(); itor != teachers.end(); itor++)
			cout << itor->id << " " << itor->name << " " << itor->pwd << endl;
	}
	else
	{
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
		return;
	}

	system("pause");
	system("cls");
}

void Admin::ShowRoomInfo(const vector<Room>& rooms)
{
	cout << "机房信息如下：(机房编号  最大容量  当前已占用数量)" << endl;
	for (vector<Room>::const_iterator itor = rooms.begin(); itor != rooms.end(); itor++)
		cout << itor->id << " " << itor->capcity << " " << itor->size << endl;

	system("pause");
	system("cls");
}

void Admin::ClearFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "预约已清空！" << endl;
	system("pause");
	system("cls");
}
