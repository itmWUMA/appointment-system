# 机房预约系统

#### 1. 简介
机房预约系统，管理学生的预约，设定人员的使用权限等相关操作



#### 2. 软件架构
> │  Admin.h	--- 管理员类
>
> │  Controller.h	--- 控制器类（用以控制程序流程）
>
> │  Global.h	--- 全局参数文件（用以声明预定义和宏）
>
> │  Identity.h	--- 身份接口
>
> │  main.cpp	--- 程序入口
>
> │  Student.h	--- 学生类
>
> │  Teacher.h	--- 教师类
>
> │  Order.h	--- 预约信息类
> 
> │  Room.h	--- 机房类

#### 3. 功能介绍

##### 3.1 身份简介

共有3种身份使用该程序：

- 学生代表：申请使用机房
- 教师：审核学生的预约申请
- 管理员：为学生、教师创建账号

##### 3.2 机房介绍

共有3个机房：

- 1号机房：最大容量20人
- 2号机房：最大容量50人
- 3号机房：最大容量100人

机房信息：机房编号、最大容量

##### 3.3 申请流程

- 申请的订单每周由管理员负责清空
- 学生可预约未来一周的机房使用，预约时间为周一至周五，预约时选预约时间段（上午、下午）
- 教师审核预约，根据实际情况反馈通过或不通过

##### 3.4 预约状态

- 审核中
- 预约成功
- 预约失败
- 取消的预约

##### 3.5 系统具体流程

- 登录界面，可选择3种身份（学生代表、老师、管理员）
- 选择身份后，进行身份验证
  - 学生需要输入：学号、姓名、密码
  - 老师需要输入：职工号、姓名、密码
  - 管理员需要输入：管理员姓名、密码
- 学生具体功能
  - 申请预约	
  - 查看自身的预约状态
  - 查看所有预约   ---  *查看所有预约信息以及预约状态*
  - 取消预约
  - 注销登录   ---  *退出登录*
- 教师具体功能
  - 查看所有预约  ---  *查看所有预约信息以及预约状态*
  - 审核预约
  - 注销登录
- 管理员具体功能
  - 添加账号  ---  *添加学生和老师的账号，需要检测账号是否存在*
  - 查看账号  ---  *查看学生和老师所有的信息*
  - 查看机房  ---  *查看所有的机房信息*
  - 清空预约  ---  *清空所有的预约记录*
  - 注销登录



#### 4. 使用说明

自行使用编译器进行编译并运行可执行文件



#### 5. 参与贡献

***itmWuma***

https://github.com/itmWUMA/

https://gitee.com/itmwuma



#### 6. 参考

https://www.bilibili.com/video/BV1et411b73Z?p=282&share_source=copy_web
