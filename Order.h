#pragma once
#include <string>
using namespace std;

/*	ԤԼ��
	���Դ洢ԤԼ����
*/
class Order
{
public:
	// ���״̬
	enum class Status
	{
		IN_REVIEW,	// �����
		PASS,	// ͨ��
		FAIL,	// δͨ��
		CANCEL,	// ȡ��
	};

	string name;  // ѧ������
	int id;  // ѧ��
	int week;	// ԤԼʱ��
	int time;	// ԤԼʱ���
	Status status;	// ԤԼ״̬

	Order(string name, int id, int week, int time, Status status);
	Order();
};