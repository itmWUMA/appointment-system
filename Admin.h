#pragma once
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"

/* 管理员类
   - 菜单界面
   - 添加账号
   - 查看账号
   - 查看机房信息
   - 清空预约记录
*/
class Admin :
    public Identity
{
public:
   Admin();
   Admin(string name, string pwd);

   // 重载比较操作符
   virtual bool operator==(const Admin& a);

   // 重载小于操作符
   bool operator<(const Admin& a) const;

   // 菜单界面
   virtual void OpenMenu();

   // 添加账号
   void AddPerson();

   // 查看账号
   void ShowPerson(const set<Student>& stus, const set<Teacher>& teachers);

   // 查看机房信息
   void ShowRoomInfo(const vector<Room>& rooms);

   // 清空预约记录
   void ClearFile();
};

