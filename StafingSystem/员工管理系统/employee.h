/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
* 1.������ͨԱ���࣬ʵ�����¹���
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


	//�����˵�   ���麯��
	void WorkeroperMenu();

	Employee();

	Employee(int WorkerId, string WorkerPassWord, string WorkerName, string WorkerGender,
		string WorkerEmile, string WorkerPhone, int WorkerDepartment,int WorkerRole);



};