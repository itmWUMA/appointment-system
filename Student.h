#pragma once
#include "Identity.h"

/* 学生类
   - 学生的界面操作
   - 申请预约
   - 查看自身预约
   - 查看所有预约
   - 取消预约
*/
class Student :
    public Identity
{
private:
   // 将预约写入文件中    [week  time  id  name  room  status]
   void WriteOrderFile(vector<Room>& rooms, int i, int week, int time);

   // 判断是否重复预约
   bool IsRepeatOrder(const Order& order);

public:
   // 学生ID
   int id;

    Student();
    Student(int id, string name, string pwd);

    // 重载比较运算符
    virtual bool operator==(const Student& stu);

    // 重载小于运算符
    bool operator<(const Student& stu) const;

    // 菜单界面
    virtual void OpenMenu();

    // 申请预约
    void ApplyOrder(vector<Room>& rooms);

    // 查看自身预约
    void ShowMyOrder(const multimap<int, Order>& orders);

    // 取消预约
    void CancelOrder();
};