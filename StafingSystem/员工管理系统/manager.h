/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
* 1.��������Ա��ʵ�����¹���
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


	//�����˵�   ���麯��
	void WorkeroperMenu();

	Manager();

	Manager(int WorkerId,  string WorkerPassWord, string WorkerName, string WorkerGender,
		string WorkerEmile, string WorkerPhone, int WorkerDepartment,int WorkerRole);

	//3.�޸Ĳ�����Ϣ    
	string AmendDepartmentInformation();


	//4.ע���û�   
	string RegisterWorker();


	//6.�޸���ͨ�û�Ȩ��  
	string AmendEmpoyleeLimit();

	//��ʼ������
	void ManagerInitVector();


	//���ע��Ա���Ƿ����ظ�
	bool CheckRepeatWorker(int id);

	//��������
	vector<Department>vDep;

	//����Ա����
	vector<Manager>vMan;

	//�û�����
	vector<Employee>vEmp;

	//��������
	vector<Admin>vAdm;
};