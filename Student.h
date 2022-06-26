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
private:
   // ��ԤԼд���ļ���    [week  time  id  name  room  status]
   void WriteOrderFile(vector<Room>& rooms, int i, int week, int time);

   // �ж��Ƿ��ظ�ԤԼ
   bool IsRepeatOrder(const Order& order);

   // ��ȡ��ǰѧ����ԤԼ��¼
   vector<Order> GetMyOrder(const multimap<int, Order>& orders);

   // ��ӡ�ҵ�ԤԼ
   void PrintMyOrder(const vector<Order> myOrders);

   // ��ȡ��ǰѧ����ȡ��ԤԼ�ļ�¼
   vector<Order> GetCanBeCanceledOrder(const multimap<int, Order>& orders);

   // ����д���ļ�
   void RewriteOrderFile(const multimap<int, Order>& orders);

   // ȡ��ԤԼ��ӡ������
   class CancelOrderPrintHandler
   {
   public:
      int count;

      void operator()(const Order& o);
   };

public:
   // ѧ��ID
   int id;

    Student();
    Student(int id, string name, string pwd);

    // ���رȽ������
    virtual bool operator==(const Student& stu);

    // ����С�������
    bool operator<(const Student& stu) const;

    // �˵�����
    virtual void OpenMenu();

    // ����ԤԼ
    void ApplyOrder(vector<Room>& rooms);

    // �鿴����ԤԼ
    void ShowMyOrder(const multimap<int, Order>& orders);

    // ȡ��ԤԼ
    void CancelOrder(multimap<int, Order>& orders);
};