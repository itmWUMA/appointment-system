#pragma once
#include "Identity.h"

/* 教师类
   - 教师的操作界面
   - 查看所有预约
   - 审核预约
*/
class Teacher :
    public Identity
{
public:
   // 教师ID
   int id;

   Teacher();
   Teacher(int id, string name, string pwd);

   // 菜单界面
   virtual void OpenMenu();

   // 查看所有预约
   virtual void ShowAllOrder();

   // 审核预约
   void ValidOrder();
};

