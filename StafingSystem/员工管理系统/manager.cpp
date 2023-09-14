/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
* 1.创建管理员子菜单
* 2.修改普通员工权限
* 3.修改部门信息
* 4.添加用户
*
*
*/
#include <iostream>
#include <string>
#include"manager.h"
#include<vector>


using namespace std;


//操作菜单   纯虚函数
void Manager::WorkeroperMenu()
{
	cout << "===   欢迎部门管理员：" << this->mWorkerName << "登录    ====" << endl;
	cout << "=======================================================" << endl;
	cout << "=================    1.修改部门信息        ============" << endl;
	cout << "=================    2.注册用户            ============" << endl;
	cout << "=================    3.修改普通用户权限    ============" << endl;
	cout << "=======================================================" << endl;
	cout << "请输入您的操作：" << endl;
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

//3.修改部门信息    
string Manager::AmendDepartmentInformation()
{
	cout << "请输入修改部门的编号：" << endl;
	int id;
	cin >> id;

	int newId = 0;
	string newName = "";
	int newDescribe = 0;

	vector<Department>::iterator it = find(vDep.begin(),vDep.end(), id);
	cout << "查到： " << id << "号部门，请输入新的部门编号：" << endl;
	cin >> newId;
	cout << "请输入新的名称：" << endl;
	cin >> newName;
	cout << "请输入新的部门描述" << endl;
	cin >> newDescribe;

	cout << "部门描述：" << endl;
	cout << "1.研究所" << endl;
	cout << "2.计科" << endl;
	cout << "3.自动化" << endl;

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
	//修改文件信息
	ofstream ofs;
	ofs.open(DEPARTMENT_FILE, ios::out | ios::trunc);
	ofs << newId << " " << newName << " " << newDescribe << endl;

	//初始化容器
	this->ManagerInitVector();
}


//4.注册用户   
string Manager::RegisterWorker()
{
	cout << "注册普通用户" << endl;
	string fileName;//操作文件名
	string tip;//提示id号
	string errorTip;//重复错误提示
	ofstream ofs;//文件操作对象

	int select = 0;
	cin >> select;//接受超户选项

	
	
	//注册普通员工
	fileName = EMPLOYEE_FILE;
	tip = "请输入普通员工编号：";
	errorTip = "普通员工编号重复，请重新输入：";


	//利用追加的方式 写文件
	ofs.open(fileName, ios::out | ios::app);

	int id;//管理员编号  普通员工编号
	string name;//姓名
	string pwd;//密码

	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret = CheckRepeatWorker(id);
		if (ret)//有重复
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//调用初始化容器接口，重新获取文件的数据
	this->ManagerInitVector();

}


//6.修改普通用户权限  
string Manager::AmendEmpoyleeLimit()
{
	cout << "请输入要修改的普通员工的编号：" << endl;
	int id;
	cin >> id;


	int newWorkerRole = 0;

	vector<Manager>::iterator it = find(vMan.begin(), vMan.end(), id);
	cout << "查到：" << id << "号普通员工，请输入新的角色信息：" << endl;
	cout << "1.管理员" << endl;

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

	//向文件中修改数据
	ofstream ofs;
	ofs.open(ROLE_FILE, ios::out | ios::trunc);
	ofs << this->mWorkerId << " " << this->mWorkerPassWord << " " << this->mWorkerName << " "
		<< this->mWorkerGender << " " << this->mWorkerEmile << " " << this->mWorkerPhone << " "
		<< this->mWorkerDepartment << " " << newWorkerRole;


	//初始化容器
	this->ManagerInitVector();
}



//检测注册员工是否有重复
bool Manager::CheckRepeatWorker(int id)
{
		//检测普通员工
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


//初始化容器
void Manager::ManagerInitVector()
{
	//读取普通员工信息
	ifstream ifs;
	ifs.open(EMPLOYEE_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
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