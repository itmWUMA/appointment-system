#include "Student.h"

// ��ԤԼд���ļ���    [week  time  id  name  room  status]
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
	// ��ȡOrder�ļ�
	ifstream ifs(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return false;
	}

	Order curOrder;
	string name;
	int id, room, week, time, n_status;
	while (ifs >> week && ifs >> time && ifs >> id && ifs >> name && ifs >> room && ifs >> n_status)
	{
		curOrder = Order(name, id, week, time, room, (Order::Status)n_status);
		// �Ƚ�����order�Ƿ�һ��
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
		cout << "����" << myOrders[i].room << " "
			<< "����" << (myOrders[i].week) << " "
			<< (myOrders[i].time == 1 ? "����" : "����") << " "
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
		cout << "- ����" << itor->id << "����" << itor->capcity << endl;
	// ��ȡ�û�ѡ��
	cout << "> ";
	int iptRoom = 0;

	while (true)
	{
		cin >> iptRoom;
		if (iptRoom >= 1 && iptRoom <= 3)
		{
			// �ж��Ƿ��ظ�ԤԼ
			if (IsRepeatOrder(Order(this->name, this->id, iptWeek, iptTime, iptRoom, Order::Status::IN_REVIEW)))
			{
				cout << "��ԤԼ�Ѽ�¼�������ظ�ԤԼ��" << endl;
				system("pause");
				system("cls");
				return;
			}
			// ��ԤԼ��Ϣд���ļ���
			WriteOrderFile(rooms, iptRoom, iptWeek, iptTime);
			cout << "ԤԼ���ύ����ȴ����" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "�������" << endl;
	}

	system("pause");
	system("cls");
}

void Student::ShowMyOrder(const multimap<int, Order>& orders)
{
	// ��ȡԤԼ��Ϣ
	vector<Order> myOrders = GetMyOrder(orders);
	int count = myOrders.size();
	if (count == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	// ������ӡ����ԤԼ��¼
	cout << "ԤԼ��¼����(������� ԤԼʱ�� ԤԼʱ��� ��ǰ״̬)��" << endl;
	PrintMyOrder(myOrders);

	system("pause");
	system("cls");
}

void Student::CancelOrder(multimap<int, Order>& orders)
{
	// ��ȡ�ҵ�ԤԼ��¼
	vector<Order> myOrders = GetMyOrder(orders);
	if (myOrders.size() == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	// ��ӡ���е�ǰԤԼ
	cout << "��������ԤԼ����ȡ����" << endl;
	vector<Order> cbcOrders = GetCanBeCanceledOrder(orders);
	for_each(cbcOrders.begin(), cbcOrders.end(), CancelOrderPrintHandler());
	cout << "��ѡ����Ҫȡ����ԤԼ(ȡ��������0)��> ";

	// ��ȡ����
	int ipt = 0;
	while (true)
	{
		cin >> ipt;
		if (ipt == 0)
		{
			cout << "����ȡ��ѡ��" << endl;
			break;
		}
		else if (ipt < 0 || ipt > (int)cbcOrders.size())
			cout << "ѡ�����������ѡ��" << endl;
		else
		{
			// �޸�orders�е�����
			int count = orders.count(this->id);
			multimap<int, Order>::iterator itor = orders.find(this->id);
			for (int i = 0; i < count; i++, itor++)
			{
				if (itor->second == cbcOrders[ipt - 1])
					itor->second.status = Order::Status::CANCEL;
			}
			// ����д���ļ�
			RewriteOrderFile(orders);
			cout << "��ȡ��ԤԼ��" << endl;
			break;
		}
	}

	system("pause");
	system("cls");
}

void Student::CancelOrderPrintHandler::operator()(const Order& o)
{
	cout << "[" << this->count + 1 << "] "
		<< "����" << o.room << " "
		<< "����" << (o.week) << " "
		<< (o.time == 1 ? "����" : "����") << " "
		<< Order::StatusToString(o.status) << endl;
	this->count++;
}
