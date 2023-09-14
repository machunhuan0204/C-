/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
* 1.创建管理员类实现以下功能
*
*
*/

#pragma once

#include<iostream>
#include<string>
#include"worker.h"
#include<vector>
#include"admin.h"
#include"employee.h"
#include"department.h"

using namespace std;

class Manager :public Worker
{
public:


	//操作菜单   纯虚函数
	void WorkeroperMenu();

	Manager();

	Manager(int WorkerId,  string WorkerPassWord, string WorkerName, string WorkerGender,
		string WorkerEmile, string WorkerPhone, int WorkerDepartment,int WorkerRole);

	//3.修改部门信息    
	string AmendDepartmentInformation();


	//4.注册用户   
	string RegisterWorker();


	//6.修改普通用户权限  
	string AmendEmpoyleeLimit();

	//初始化容器
	void ManagerInitVector();


	//检测注册员工是否有重复
	bool CheckRepeatWorker(int id);

	//部门容器
	vector<Department>vDep;

	//管理员容器
	vector<Manager>vMan;

	//用户容器
	vector<Employee>vEmp;

	//超户容器
	vector<Admin>vAdm;
};