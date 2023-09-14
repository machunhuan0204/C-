/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
* 1.创建基类，工作者类
*
*
*/

#pragma once

#include<iostream>
#include<string>
#include <vector>

using namespace std;

class Worker
{
public:
	int   mWorkerId;
	string   mWorkerPassWord;
	string   mWorkerName;
	string   mWorkerGender;
	string   mWorkerEmile;
	string   mWorkerPhone;
	int   mWorkerDepartment;
	int mWorkerRole;

	//操作菜单   纯虚函数
	virtual void WorkeroperMenu() = 0;


	
	
};
