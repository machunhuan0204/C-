/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
* 1.�������࣬��������
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

	//�����˵�   ���麯��
	virtual void WorkeroperMenu() = 0;


	
	
};
