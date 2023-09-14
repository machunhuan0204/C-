/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
* 1.main��������λ�ã�������ڣ����߼�����ʵ�֣�
* 2.��Ҫ������¼���ܼ�
* 3.������ɫ���Ӳ˵���ѡ��
*
*
*
*/

#include<iostream>
#include<string>
#include"worker.h"
#include"admin.h"
#include"employee.h"
#include "manager.h"
#include"globalFile.h"
#include"department.h"
#include<fstream>

using namespace std;

void EmployeeMenu(Worker*& employee)
{
	while (true)

	{
		employee->WorkeroperMenu();
		Employee* emp = (Employee*)employee;
		int EmployeeSelect = 0;
		if (EmployeeSelect == 1)
		{
			emp->WorkeroperMenu();

		}
		else
		{
			delete employee;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void ManagerMenu(Worker*& manager)
{
	while (true)
	{
		//�����Ӳ˵�
		manager->WorkeroperMenu();

		Manager* man = (Manager*)manager;
		int ManagerSelect = 0;
		if (ManagerSelect == 1)
		{
			man->AmendDepartmentInformation();//�޸Ĳ�����Ϣ
		}
		else if (ManagerSelect == 2)
		{
			man->RegisterWorker();//ע���û�
		}
		else if(ManagerSelect == 3)
		{
			man->AmendEmpoyleeLimit();//�޸���ͨ�û�Ȩ��
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void AdminMenu(Worker*& admin)
{
	while (true)
	{
		//���ó����Ӳ˵�
		admin->WorkeroperMenu();

		//������ָ��תΪ����ָ�룬ʹ����Ե�������ķ���
		Admin* adm = (Admin*)admin;

		int AdminSelect = 0;
		cin >> AdminSelect;

		if (AdminSelect == 1)
		{
			adm->NewDepartment();//�½�����
		}
		else if (AdminSelect == 2)
		{
			adm->DeletDepartment();//ɾ������
		}
		else if (AdminSelect == 3)
		{
			adm->AmendDepartmentInformation();
		}
		else if (AdminSelect == 4)
		{
			adm->RegisterWorker();
		}
		else if (AdminSelect == 5)
		{
			adm->AmendManagerLimit();
		}
		else if (AdminSelect == 6)
		{
			adm->AmendEmpoyleeLimit();
		}
		else
		{
			delete admin;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		
	}
}



//��¼����
string LoginIn(string fileName, int type)
{
	//��������ָ�룬ָ���������
	Worker* worker = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//׼��������Ϣ
	int   Id=0;
	string   PassWord="";
	string   Name="";
	string   Gender="";
	string   Emile="";
	string   Phone="";
	int   Department=0;
	int Role=0;
	//�ж����
	if (type == 2)
	{
		cout << "���������Ա�ı�ţ�" << endl;
		cin >> Id;
	}
	else if (type == 3)
	{
		cout << "������Ա���ı�ţ�" << endl;
		cin >> Id;
	}
	
	cout << "�������û�����" << endl;
	cin >> Name;

	cout << "���������룺" << endl;
	cin >> PassWord;

	if (type == 1)//����
	{
		//���ļ��л�ȡ��������
		string fName;
		string fPwd;

		while (ifs>>fName && ifs >>fPwd)
		{
			if (Name == fName && PassWord == fPwd)
			{
				cout << "������¼�ɹ���" << endl;
				system("pause");
				system("cls");

				worker = new Admin(Id, PassWord, Name,Gender,
					Emile, Phone, Department,Role);

				//���볬���Ӳ˵�
				AdminMenu(worker);
			}
			else
			{
				return "������¼ʧ�ܣ�";
			}
		}

	}
	else if (type == 2)//���Ź���Ա
	{
		//���ļ��л�ȡ��š�����������
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (Id == fId && Name == fName && PassWord == fPwd)
			{
				cout << "���Ź���Ա��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				worker = new Manager(Id, PassWord, Name, Gender,
					Emile, Phone, Department,Role);

				//���벿�Ź���Ա�Ӳ˵�
				ManagerMenu(worker);
			}
			else
			{
				return "���Ź���Ա��¼ʧ�ܣ�";
			}
		}

	}
	else if (type == 3)//Ա��
	{
		//���ļ��л�ȡ��š�����������
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (Id == fId && Name == fName && PassWord == fPwd)
			{
				cout << "��ͨԱ����¼�ɹ���" << endl;
				system("pause");
				system("cls");

				worker = new Employee(Id, PassWord, Name, Gender,
					Emile, Phone, Department,Role);

				//����Ա���Ӳ˵�
				EmployeeMenu(worker);
			}
			else
			{
				return "��ͨԱ����¼ʧ�ܣ�";
			}
		}
	}
}

//

int main()
{
	int Worker_Select = 0;

	while (true)
	{
		cout << "===========     ��ӭ���ĵ�����    ===========" << endl;
		cout << "===========     ������������ݣ�  ===========" << endl;
		cout << "=============================================" << endl;
		cout << "===========     1.����            ===========" << endl;
		cout << "===========     2.���Ź���Ա      ===========" << endl;
		cout << "===========     3.��ͨԱ          ===========" << endl;
		cout << "=============================================" << endl;

		cin >> Worker_Select;
		switch (Worker_Select)
		{
		case 1:
			LoginIn(ADMIN_FILE, 1);
			break;
		case 2:
			LoginIn(MANAGER_FILE, 2);
			break;
		case 3:
			LoginIn(EMPLOYEE_FILE, 3);
			break;
		}
	}

	system("pause");
	return 0;
}