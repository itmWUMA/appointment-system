#pragma once
#include "Identity.h"

/* ��ʦ��
   - ��ʦ�Ĳ�������
   - �鿴����ԤԼ
   - ���ԤԼ
*/
class Teacher :
    public Identity
{
private:
   // ����д���ļ�
   void RewriteOrderFile(const vector<Order>& orders);

public:
   // ��ʦID
   int id;

   Teacher();
   Teacher(int id, string name, string pwd);

   // ���رȽϲ�����
   virtual bool operator==(const Teacher& t);

   // ����С�ڲ�����
   bool operator<(const Teacher& t) const;

   // �˵�����
   virtual void OpenMenu();

   // ���ԤԼ
   void ValidOrder(vector<Order>& orders);
};

