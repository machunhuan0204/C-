/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
*1.ʵ���вι��죬�ɴ���ʵ��
*
*
*/

#include<iostream>
#include<string>
#include"employee.h"

using namespace std;



//�����˵�   ���麯��
void Employee::WorkeroperMenu()
{
	cout << "===   ��ӭԱ����" << this->mWorkerName << "��¼    ====" << endl;
	cout << "=======================================================" << endl;
	cout << "=======================================================" << endl;
	cout << "���������Ĳ�����" << endl;
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