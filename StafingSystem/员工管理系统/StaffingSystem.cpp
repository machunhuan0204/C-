/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
* 1.main函数所在位置，程序入口，主逻辑的是实现，
* 2.主要包含登录功能及
* 3.各个角色的子菜单的选择
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
			cout << "注销成功" << endl;
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
		//调用子菜单
		manager->WorkeroperMenu();

		Manager* man = (Manager*)manager;
		int ManagerSelect = 0;
		if (ManagerSelect == 1)
		{
			man->AmendDepartmentInformation();//修改部门信息
		}
		else if (ManagerSelect == 2)
		{
			man->RegisterWorker();//注册用户
		}
		else if(ManagerSelect == 3)
		{
			man->AmendEmpoyleeLimit();//修改普通用户权限
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
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
		//调用超户子菜单
		admin->WorkeroperMenu();

		//将父类指针转为子类指针，使其可以调用子类的方法
		Admin* adm = (Admin*)admin;

		int AdminSelect = 0;
		cin >> AdminSelect;

		if (AdminSelect == 1)
		{
			adm->NewDepartment();//新建部门
		}
		else if (AdminSelect == 2)
		{
			adm->DeletDepartment();//删除部门
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
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		
	}
}



//登录功能
string LoginIn(string fileName, int type)
{
	//创建父类指针，指向子类对象
	Worker* worker = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//准备接收信息
	int   Id=0;
	string   PassWord="";
	string   Name="";
	string   Gender="";
	string   Emile="";
	string   Phone="";
	int   Department=0;
	int Role=0;
	//判断身份
	if (type == 2)
	{
		cout << "请输入管理员的编号：" << endl;
		cin >> Id;
	}
	else if (type == 3)
	{
		cout << "请输入员工的编号：" << endl;
		cin >> Id;
	}
	
	cout << "请输入用户名：" << endl;
	cin >> Name;

	cout << "请输入密码：" << endl;
	cin >> PassWord;

	if (type == 1)//超户
	{
		//从文件中获取姓名密码
		string fName;
		string fPwd;

		while (ifs>>fName && ifs >>fPwd)
		{
			if (Name == fName && PassWord == fPwd)
			{
				cout << "超户登录成功！" << endl;
				system("pause");
				system("cls");

				worker = new Admin(Id, PassWord, Name,Gender,
					Emile, Phone, Department,Role);

				//进入超户子菜单
				AdminMenu(worker);
			}
			else
			{
				return "超户登录失败！";
			}
		}

	}
	else if (type == 2)//部门管理员
	{
		//从文件中获取编号、姓名、密码
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (Id == fId && Name == fName && PassWord == fPwd)
			{
				cout << "部门管理员登录成功！" << endl;
				system("pause");
				system("cls");

				worker = new Manager(Id, PassWord, Name, Gender,
					Emile, Phone, Department,Role);

				//进入部门管理员子菜单
				ManagerMenu(worker);
			}
			else
			{
				return "部门管理员登录失败！";
			}
		}

	}
	else if (type == 3)//员工
	{
		//从文件中获取编号、姓名、密码
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (Id == fId && Name == fName && PassWord == fPwd)
			{
				cout << "普通员工登录成功！" << endl;
				system("pause");
				system("cls");

				worker = new Employee(Id, PassWord, Name, Gender,
					Emile, Phone, Department,Role);

				//进入员工子菜单
				EmployeeMenu(worker);
			}
			else
			{
				return "普通员工登录失败！";
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
		cout << "===========     欢迎您的到来！    ===========" << endl;
		cout << "===========     请输入您的身份：  ===========" << endl;
		cout << "=============================================" << endl;
		cout << "===========     1.超户            ===========" << endl;
		cout << "===========     2.部门管理员      ===========" << endl;
		cout << "===========     3.普通员          ===========" << endl;
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