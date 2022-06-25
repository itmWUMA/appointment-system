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
    void ApplyOrder();

    // 查看自身预约
    void ShowMyOrder();

    // 查看所有人预约
    virtual void ShowAllOrder();

    // 取消预约
    void CancelOrder();
};