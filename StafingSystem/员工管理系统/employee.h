/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
* 1.创建普通员工类，实现以下功能
*
*
*/

#pragma once

#include<iostream>
#include<string>
#include"worker.h"

using namespace std;

class Employee :public Worker
{
public:


	//操作菜单   纯虚函数
	void WorkeroperMenu();

	Employee();

	Employee(int WorkerId, string WorkerPassWord, string WorkerName, string WorkerGender,
		string WorkerEmile, string WorkerPhone, int WorkerDepartment,int WorkerRole);



};