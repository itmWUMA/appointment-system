#pragma once
#include "Identity.h"

/* ѧ����
   - ѧ���Ľ������
   - ����ԤԼ
   - �鿴����ԤԼ
   - �鿴����ԤԼ
   - ȡ��ԤԼ
*/
class Student :
    public Identity
{
public:
   // ѧ��ID
   int id;

    Student();
    Student(int id, string name, string pwd);

    // �˵�����
    virtual void OpenMenu();

    // ����ԤԼ
    void ApplyOrder();

    // �鿴����ԤԼ
    void ShowMyOrder();

    // �鿴������ԤԼ
    virtual void ShowAllOrder();

    // ȡ��ԤԼ
    void CancelOrder();
};