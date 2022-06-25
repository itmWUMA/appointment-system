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

   // �鿴����ԤԼ
   virtual void ShowAllOrder();

   // ���ԤԼ
   void ValidOrder();
};

