#include "Student.h"

// 将预约写入文件中    [week  time  id  name  room  status]
void Student::WriteOrderFile(vector<Room>& rooms, int i, int week, int time)
{
	ofstream ofs(ORDER_FILE, ios::out | ios::app);
	ofs << week << " "
		<< time << " "
		<< this->id << " "
		<< this->name << " "
		<< rooms[i].id << " "
		<< (int)Status::IN_REVIEW << endl;
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
	return this->id < stu.id;
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
		cout << "- 机房" << itor->id << "剩余机位：" << (itor->capcity - itor->size) << endl;
	// 获取用户选择
	cout << "> ";
	int iptRoom = 0;
	do
	{
		cin >> iptRoom;
		// 符合预约条件
		if (rooms[iptRoom - 1].size < rooms[iptRoom - 1].capcity)
		{
			// 将预约信息写入文件中
			WriteOrderFile(rooms, iptRoom, iptWeek, iptTime);
			cout << "预约已提交，请等待审核" << endl;
			system("pause");
			system("cls");
			return;
		}
		// 不符合预约条件
		else
			cout << "该房间已满员！" << endl;
	} while (iptRoom);

	cout << "已退出预约！" << endl;
	system("pause");
	system("cls");
}

void Student::ShowMyOrder()
{
}

void Student::ShowAllOrder()
{
}

void Student::CancelOrder()
{
}
