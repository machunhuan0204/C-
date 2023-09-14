/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
* 1.创建超户类实现以下功能
*
*
*/

#pragma once

#include<iostream>
#include<string>
#include"worker.h"
#include"manager.h"
#include"employee.h"
#include<vector>
#include <fstream>
#include "globalFile.h"
#include "department.h"

using namespace std;

class Admin :public Worker
{
public:

	friend Manager;
	 //操作菜单   纯虚函数
	 void WorkeroperMenu();

	
	 Admin();

	 Admin(int WorkerId, string WorkerPassWord, string WorkerName, string WorkerGender,
		 string WorkerEmile, string WorkerPhone, int WorkerDepartment,int WorkerRole);


	 
	

	 //1.新建部门   
	 string NewDepartment();

	 //2.删除部门    
	 string DeletDepartment();

	 //3.修改部门信息    
	 string AmendDepartmentInformation();

	 //4.注册用户   
	 string RegisterWorker();

	 //5.修改管理员权限   
	 string AmendManagerLimit();

	 //6.修改普通用户权限  
	 string AmendEmpoyleeLimit();


	 //初始化容器
	 void InitVector();

	 //检测是部门否有重复
	 bool CheckRepeatDepartment(int id);

	 //检测注册员工是否有重复
	 bool CheckRepeatWorker(int id,int type);

	 //部门容器
	 vector<Department>vDepartment;

	 //管理员容器
	 vector<Manager>vManager;

	 //用户容器
	 vector<Employee>vEmployee;

	 //超户容器
	 vector<Admin>vAdmin;
	



	
};





