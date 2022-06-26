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

	cout << "��ã�" << this->name << "��ʦ" << endl;
	cout << "============== ��ʦ����ϵͳ ==============" << endl;
	cout << "              [1] �鿴����ԤԼ" << endl;
	cout << "              [2] ���ԤԼ" << endl;
	cout << "              [0] ע����¼" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

void Teacher::ValidOrder(vector<Order>& orders)
{
	vector<Order> availableOrders;	// ���ڴ�ſ���˵�ԤԼ
	map<int, int> posTable;	// <availableOrders�±�, orders�±�>

	// ��ÿ���˵�ԤԼ
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

	// ��ʾ����˵�ԤԼ
	cout << "�����������ԤԼ��" << endl;
	for (size_t i = 0; i < availableOrders.size(); i++)
	{
		cout << "[" << i + 1 << "] " << "����" << availableOrders[i].room << " "
			<< "����" << (availableOrders[i].week) << " "
			<< (availableOrders[i].time == 1 ? "����" : "����") << " "
			<< Order::StatusToString(availableOrders[i].status) << endl;
	}

	// ѡ��ԤԼ������˽��
	cout << "��ѡ����Ҫ��˵�ԤԼ(�˳����������0): > ";
	int ipt = 0;
	while (true)
	{
		cin >> ipt;
		if (ipt == 0)
		{
			cout << "����ȡ��ѡ��" << endl;
			break;
		}
		else if (ipt < 0 || ipt >(int)availableOrders.size())
			cout << "ѡ�����������ѡ��" << endl;
		else
		{
			// �������
			cout << "���Ƿ����ͨ����(Y:1 | N:0) > ";
			int res = 0;
			cin >> res;
			orders[posTable[ipt - 1]].status = (res) ? Order::Status::PASS : Order::Status::FAIL;

			// ����д���ļ�
			RewriteOrderFile(orders);

			cout << "�������ˣ�" << endl;
			break;
		}
	}

	system("pause");
	system("cls");
}
