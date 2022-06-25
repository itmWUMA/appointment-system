#include "Identity.h"

void Identity::ShowAllOrder(const multimap<int, Order>& orders)
{
	for (multimap<int, Order>::const_iterator itor = orders.begin(); itor != orders.end(); itor++)
	{
		cout << itor->second.name << " "
			<< "����" << itor->second.room << " "
			<< "����" << (itor->second.week) << " "
			<< (itor->second.time == 1 ? "����" : "����") << " "
			<< Order::StatusToString(itor->second.status) << endl;
	}

	system("pause");
	system("cls");	
}