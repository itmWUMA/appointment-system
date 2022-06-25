#include "Student.h"

// ��ԤԼд���ļ���    [week  time  id  name  room  status]
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

	cout << "��ã�" << this->name << "ͬѧ" << endl;
	cout << "============== ѧ������ϵͳ ==============" << endl;
	cout << "              [1] ����ԤԼ" << endl;
	cout << "              [2] �鿴�ҵ�ԤԼ" << endl;
	cout << "              [3] �鿴����ԤԼ" << endl;
	cout << "              [4] ȡ��ԤԼ" << endl;
	cout << "              [0] ע����¼" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

void Student::ApplyOrder(vector<Room>& rooms)
{
	// ��ȡԤԼʱ��
	cout << "��ѡ��ԤԼ��ʱ��(��һ�����忪��): > ";
	int iptWeek = 0;
	while (true)
	{
		cin >> iptWeek;
		if (iptWeek > 0 && iptWeek <= 5)
			break;
		cout << "�������" << endl;
	}

	// ��ȡԤԼʱ���
	cout << "��ѡ��ԤԼ��ʱ���([1]���� | [2]����): > ";
	int iptTime = 0;
	while (true)
	{
		cin >> iptTime;
		if (iptTime == 1 || iptTime == 2)
			break;
		cout << "�������" << endl;
	}

	// ��ʾ������Ϣ
	cout << "��ѡ�����(������ѡ���˳�����0)��" << endl;
	for (vector<Room>::iterator itor = rooms.begin(); itor != rooms.end(); itor++)
		cout << "- ����" << itor->id << "ʣ���λ��" << (itor->capcity - itor->size) << endl;
	// ��ȡ�û�ѡ��
	cout << "> ";
	int iptRoom = 0;
	do
	{
		cin >> iptRoom;
		// ����ԤԼ����
		if (rooms[iptRoom - 1].size < rooms[iptRoom - 1].capcity)
		{
			// ��ԤԼ��Ϣд���ļ���
			WriteOrderFile(rooms, iptRoom, iptWeek, iptTime);
			cout << "ԤԼ���ύ����ȴ����" << endl;
			system("pause");
			system("cls");
			return;
		}
		// ������ԤԼ����
		else
			cout << "�÷�������Ա��" << endl;
	} while (iptRoom);

	cout << "���˳�ԤԼ��" << endl;
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
