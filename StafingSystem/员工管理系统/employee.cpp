/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
*1.实现有参构造，可创建实例
*
*
*/

#include<iostream>
#include<string>
#include"employee.h"

using namespace std;



//操作菜单   纯虚函数
void Employee::WorkeroperMenu()
{
	cout << "===   欢迎员工：" << this->mWorkerName << "登录    ====" << endl;
	cout << "=======================================================" << endl;
	cout << "=======================================================" << endl;
	cout << "请输入您的操作：" << endl;
}

Employee::Employee()
{

}

Employee::Employee(int WorkerId, string WorkerPassWord, string WorkerName, string WorkerGender,
	string WorkerEmile, string WorkerPhone, int WorkerDepartment,int WorkerRole)
{
	this->mWorkerId = WorkerId;
	this->mWorkerPassWord = WorkerPassWord;
	this->mWorkerName = WorkerName;
	this->mWorkerGender = WorkerGender;
	this->mWorkerEmile = WorkerEmile;
	this->mWorkerPhone = WorkerPhone;
	this->mWorkerDepartment = WorkerDepartment;
	this->mWorkerRole = WorkerRole;
}