#pragma once
#include "Identity.h"
//#include "Student.h"
//#include "Teacher.h"

/* ����Ա��
   - �˵�����
   - ����˺�
   - �鿴�˺�
   - �鿴������Ϣ
   - ���ԤԼ��¼
*/
class Admin :
    public Identity
{
public:
   Admin();
   Admin(string name, string pwd);

   // ���رȽϲ�����
   virtual bool operator==(const Admin& a);

   // ����С�ڲ�����
   bool operator<(const Admin& a) const;

   // �˵�����
   virtual void OpenMenu();

   // ����˺�
   void AddPerson();

   // �鿴�˺�
   void ShowPerson();

   // �鿴������Ϣ
   void ShowRoomInfo();

   // ���ԤԼ��¼
   void ClearFile();
};

