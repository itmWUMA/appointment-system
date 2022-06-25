#pragma once
#include "Identity.h"

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

   // 菜单界面
   virtual void OpenMenu();

   // 添加账号
   void AddPerson();

   // 查看账号
   void ShowPerson();

   // 查看机房信息
   void ShowRoomInfo();

   // 清空预约记录
   void ClearFile();
};

