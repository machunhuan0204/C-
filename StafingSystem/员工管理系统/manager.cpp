/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
* 1.��������Ա�Ӳ˵�
* 2.�޸���ͨԱ��Ȩ��
* 3.�޸Ĳ�����Ϣ
* 4.����û�
*
*
*/
#include <iostream>
#include <string>
#include"manager.h"
#include<vector>


using namespace std;


//�����˵�   ���麯��
void Manager::WorkeroperMenu()
{
	cout << "===   ��ӭ���Ź���Ա��" << this->mWorkerName << "��¼    ====" << endl;
	cout << "=======================================================" << endl;
	cout << "=================    1.�޸Ĳ�����Ϣ        ============" << endl;
	cout << "=================    2.ע���û�            ============" << endl;
	cout << "=================    3.�޸���ͨ�û�Ȩ��    ============" << endl;
	cout << "=======================================================" << endl;
	cout << "���������Ĳ�����" << endl;
}

Manager::Manager()
{

}

Manager::Manager(int WorkerId, string WorkerPassWord, string WorkerName, string WorkerGender,
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

//3.�޸Ĳ�����Ϣ    
string Manager::AmendDepartmentInformation()
{
	cout << "�������޸Ĳ��ŵı�ţ�" << endl;
	int id;
	cin >> id;

	int newId = 0;
	string newName = "";
	int newDescribe = 0;

	vector<Department>::iterator it = find(vDep.begin(),vDep.end(), id);
	cout << "�鵽�� " << id << "�Ų��ţ��������µĲ��ű�ţ�" << endl;
	cin >> newId;
	cout << "�������µ����ƣ�" << endl;
	cin >> newName;
	cout << "�������µĲ�������" << endl;
	cin >> newDescribe;

	cout << "����������" << endl;
	cout << "1.�о���" << endl;
	cout << "2.�ƿ�" << endl;
	cout << "3.�Զ���" << endl;

	cin >> newDescribe;
	Department* department = NULL;
	switch (newDescribe)
	{
	case 1:
		department = new Department(newId, newName, newDescribe);
		break;
	case 2:
		department = new Department(newId, newName, newDescribe);
		break;
	case 3:
		department = new Department(newId, newName, newDescribe);
		break;
	}
	//�޸��ļ���Ϣ
	ofstream ofs;
	ofs.open(DEPARTMENT_FILE, ios::out | ios::trunc);
	ofs << newId << " " << newName << " " << newDescribe << endl;

	//��ʼ������
	this->ManagerInitVector();
}


//4.ע���û�   
string Manager::RegisterWorker()
{
	cout << "ע����ͨ�û�" << endl;
	string fileName;//�����ļ���
	string tip;//��ʾid��
	string errorTip;//�ظ�������ʾ
	ofstream ofs;//�ļ���������

	int select = 0;
	cin >> select;//���ܳ���ѡ��

	
	
	//ע����ͨԱ��
	fileName = EMPLOYEE_FILE;
	tip = "��������ͨԱ����ţ�";
	errorTip = "��ͨԱ������ظ������������룺";


	//����׷�ӵķ�ʽ д�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id;//����Ա���  ��ͨԱ�����
	string name;//����
	string pwd;//����

	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret = CheckRepeatWorker(id);
		if (ret)//���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//���ó�ʼ�������ӿڣ����»�ȡ�ļ�������
	this->ManagerInitVector();

}


//6.�޸���ͨ�û�Ȩ��  
string Manager::AmendEmpoyleeLimit()
{
	cout << "������Ҫ�޸ĵ���ͨԱ���ı�ţ�" << endl;
	int id;
	cin >> id;


	int newWorkerRole = 0;

	vector<Manager>::iterator it = find(vMan.begin(), vMan.end(), id);
	cout << "�鵽��" << id << "����ͨԱ�����������µĽ�ɫ��Ϣ��" << endl;
	cout << "1.����Ա" << endl;

	cin >> newWorkerRole;
	Manager* manager = NULL;
	Admin* admin = NULL;
	switch (newWorkerRole)
	{
	case 1:
		manager = new Manager(this->mWorkerId, this->mWorkerPassWord, this->mWorkerName,
			this->mWorkerGender, this->mWorkerEmile, this->mWorkerPhone, this->mWorkerDepartment,
			newWorkerRole);
		break;
	
	}

	//���ļ����޸�����
	ofstream ofs;
	ofs.open(ROLE_FILE, ios::out | ios::trunc);
	ofs << this->mWorkerId << " " << this->mWorkerPassWord << " " << this->mWorkerName << " "
		<< this->mWorkerGender << " " << this->mWorkerEmile << " " << this->mWorkerPhone << " "
		<< this->mWorkerDepartment << " " << newWorkerRole;


	//��ʼ������
	this->ManagerInitVector();
}



//���ע��Ա���Ƿ����ظ�
bool Manager::CheckRepeatWorker(int id)
{
		//�����ͨԱ��
		for (vector<Employee>::iterator it = vEmp.begin();
			it != vEmp.end(); it++)
		{
			if (id == it->mWorkerId)
			{
				return true;
			}
		}
	return false;
}


//��ʼ������
void Manager::ManagerInitVector()
{
	//��ȡ��ͨԱ����Ϣ
	ifstream ifs;
	ifs.open(EMPLOYEE_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Employee e;
	while (ifs >> e.mWorkerId && ifs >> e.mWorkerPassWord && ifs >> e.mWorkerName
		&& ifs >> e.mWorkerGender && ifs >> e.mWorkerEmile && ifs >> e.mWorkerPhone
		&& ifs >> e.mWorkerDepartment)
	{
		vEmp.push_back(e);
	}
	ifs.close();

}