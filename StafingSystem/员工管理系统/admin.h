/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
* 1.����������ʵ�����¹���
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
	 //�����˵�   ���麯��
	 void WorkeroperMenu();

	
	 Admin();

	 Admin(int WorkerId, string WorkerPassWord, string WorkerName, string WorkerGender,
		 string WorkerEmile, string WorkerPhone, int WorkerDepartment,int WorkerRole);


	 
	

	 //1.�½�����   
	 string NewDepartment();

	 //2.ɾ������    
	 string DeletDepartment();

	 //3.�޸Ĳ�����Ϣ    
	 string AmendDepartmentInformation();

	 //4.ע���û�   
	 string RegisterWorker();

	 //5.�޸Ĺ���ԱȨ��   
	 string AmendManagerLimit();

	 //6.�޸���ͨ�û�Ȩ��  
	 string AmendEmpoyleeLimit();


	 //��ʼ������
	 void InitVector();

	 //����ǲ��ŷ����ظ�
	 bool CheckRepeatDepartment(int id);

	 //���ע��Ա���Ƿ����ظ�
	 bool CheckRepeatWorker(int id,int type);

	 //��������
	 vector<Department>vDepartment;

	 //����Ա����
	 vector<Manager>vManager;

	 //�û�����
	 vector<Employee>vEmployee;

	 //��������
	 vector<Admin>vAdmin;
	



	
};





