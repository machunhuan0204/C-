/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
* 1.超户菜单的编辑
* 2.新建部门
* 3.修改部门
* 4.删除部门
* 5.注册用户
* 6.修改管理员权限
* 7.修改普通用户权限
* 
*
*/

#include <iostream>
#include <string>
#include"admin.h"



using namespace std;


Admin::Admin()
{

}

Admin::Admin(int WorkerId, string WorkerPassWord, string WorkerName, string WorkerGender,
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


	//初始化容器 获取到文件中超户信息
	this->InitVector();

	//初始化部门信息
	ifstream ifs;
	ifs.open(DEPARTMENT_FILE, ios::in);

	Department dep;
	while (ifs >> dep.mDepartmrntId && ifs >> dep.mDepartmentName
		&& ifs >> dep.mDepartmentDescribe)
	{
		vDepartment.push_back(dep);
	}
	ifs.close();




}


//操作菜单   纯虚函数
void Admin::WorkeroperMenu()
{
	cout << "===   欢迎超户：" << this->mWorkerName << "登录    ====" << endl;
	cout << "=======================================================" << endl;
	cout << "=================    1.新建部门            ============" << endl;
	cout << "=================    2.删除部门            ============" << endl;
	cout << "=================    3.修改部门信息        ============" << endl;
	cout << "=================    4.注册用户            ============" << endl;
	cout << "=================    5.修改管理员权限      ============" << endl;
	cout << "=================    6.修改普通用户权限    ============" << endl;
	cout << "=================    7.判断员工ID是否过期  ============" << endl;
	cout << "=======================================================" << endl;
	cout << "请输入您的操作：" << endl;

}

//1.新建部门   
string Admin::NewDepartment()
{
	string fileName;//操作文件名
	string tip;//提示id号
	string errorTip;//重复错误提示

	ofstream ofs;//文件操作对象
	//新建部门
	fileName = DEPARTMENT_FILE;
	tip = "请输入部门编号：";
	errorTip = "部门编号重复，请重新输入：";

	//利用追加的方式写文件
	ofs.open(fileName, ios::out | ios::app);

	int id;//部门id
	string name;//部门名称
	int describe;//部门描述

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = CheckRepeatDepartment(id);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入部门名称：" << endl;
	cin >> name;

	cout << "请输入部门描述：" << endl;
	cout << "1.C++" << endl;
	cout << "2.基地" << endl;
	cout << "3.计科" << endl;
	cin >> describe;

	//向文件中添加数据
	ofs << id << " " << name << " " << describe << endl;
	cout << "添加成功" << endl;
	 
	system("pause");
	system("cls");

	ofs.close();

	//调用初始化容器接口，重新文件中的数据
	this->InitVector();
}

//2.删除部门    
string Admin::DeletDepartment()
{
	ofstream ofs(DEPARTMENT_FILE,ios::trunc);
	ofs.close();

	return "删除成功！";
	
}

//3.修改部门信息    
string Admin::AmendDepartmentInformation()
{
	cout << "请输入修改部门的编号：" << endl;
	int id;
	cin >> id;

	int newId = 0;
	string newName = "";
	int newDescribe = 0;

	vector<Department>::iterator it = find(vDepartment.begin(), vDepartment.end(), id);
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
	this->InitVector();
}

//4.注册用户   
string Admin::RegisterWorker()
{
	cout << "请输入添加用户类型" << endl;
	cout << "1.注册管理员" << endl;
	cout << "2.注册普通用户" << endl;


	string fileName;//操作文件名
	string tip;//提示id号
	string errorTip;//重复错误提示

	ofstream ofs;//文件操作对象

	int select = 0;
	cin >> select;//接受超户选项

	if (select == 1)
	{
		//注册管理员
		fileName = MANAGER_FILE;
		tip = "请输入管理员编号：";
		errorTip = "管理员编号重复，请重新输入：";

	}
	else 
	{
		//注册普通员工
		fileName = EMPLOYEE_FILE;
		tip = "请输入普通员工编号：";
		errorTip = "普通员工编号重复，请重新输入：";

	}

	//利用追加的方式 写文件
	ofs.open(fileName, ios::out | ios::app);

	int id;//管理员编号  普通员工编号
	string name;//姓名
	string pwd;//密码

	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret = CheckRepeatWorker(id, select);
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
	this->InitVector();
	
}

//5.修改管理员权限   
string Admin::AmendManagerLimit()
{
	cout << "请输入要修改的管理员编号：" << endl;
	int id;
	cin >> id;

	
	int newWorkerRole = 0;

	vector<Manager>::iterator it = find(vManager.begin(),vManager.end(),id);
	cout << "查到：" << id << "号管理员，请输入新的角色信息：" << endl;
	cout << "3.超户" << endl;
	cout << "2.普通员工" << endl;

	cin >> newWorkerRole;
	Manager* manager = NULL;
	Employee* employee = NULL;
	switch (newWorkerRole)
	{
	case 1:
		manager = new Manager(this->mWorkerId, this->mWorkerPassWord, this->mWorkerName,
			this->mWorkerGender,this->mWorkerEmile, this->mWorkerPhone, this->mWorkerDepartment,  
			newWorkerRole);
		break;
	case 2:
		employee = new Employee(this->mWorkerId,this->mWorkerPassWord,this->mWorkerName,
			this->mWorkerGender,this->mWorkerEmile,this->mWorkerPhone,this->mWorkerDepartment,
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
	this->InitVector();
	
}


//6.修改普通用户权限  
string Admin::AmendEmpoyleeLimit()
{
	cout << "请输入要修改的普通员工的编号：" << endl;
	int id;
	cin >> id;


	int newWorkerRole = 0;

	vector<Manager>::iterator it = find(vManager.begin(), vManager.end(), id);
	cout << "查到：" << id << "号普通员工，请输入新的角色信息：" << endl;
	cout << "1.管理员" << endl;
	cout << "3.超户" << endl;

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
	case 2:
		admin = new Admin(this->mWorkerId, this->mWorkerPassWord, this->mWorkerName,
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
	this->InitVector();
}

//初始化容器
void Admin::InitVector()
{
	//确保容器清空状态
	vManager.clear();
	vEmployee.clear();
	vDepartment.clear();

	//读取管理员信息
	ifstream ifs;
	ifs.open(MANAGER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Manager m;
	while (ifs >> m.mWorkerId && ifs >> m.mWorkerPassWord && ifs >> m.mWorkerName
		&& ifs >> m.mWorkerGender && ifs >> m.mWorkerEmile && ifs >> m.mWorkerPhone
		&& ifs >> m.mWorkerDepartment)
	{
		vManager.push_back(m);
	}
	ifs.close();

	//读取员工信息
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
		vEmployee.push_back(e);
	}
	ifs.close();

	//读取部门信息
	ifs.open(DEPARTMENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Department d;
	while (ifs >> d.mDepartmrntId && ifs >> d.mDepartmentName && ifs >> d.mDepartmentDescribe)
	{
		vDepartment.push_back(d);
	}
	ifs.close();

	//读取更新文件信息
	ifs.open(ROLE_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	if (this->mWorkerRole == 1)
	{
		Manager m;
		while (ifs >> m.mWorkerId && ifs >> m.mWorkerPassWord && ifs >> m.mWorkerName
			&& ifs >> m.mWorkerGender && ifs >> m.mWorkerEmile && ifs >> m.mWorkerPhone
			&& ifs >> m.mWorkerDepartment && ifs >> m.mWorkerRole)
		{
			vManager.push_back(m);
		}
	}
	else if(this->mWorkerRole == 2)
	{
		Employee e;
		while (ifs >> e.mWorkerId && ifs >> e.mWorkerPassWord && ifs >> e.mWorkerName
			&& ifs >> e.mWorkerGender && ifs >> e.mWorkerEmile && ifs >> e.mWorkerPhone
			&& ifs >> e.mWorkerDepartment)
		{
			vEmployee.push_back(e);
		}
	}
	else
	{
		Admin a;
		while (ifs >> a.mWorkerId && ifs >> a.mWorkerPassWord && ifs >> a.mWorkerName
			&& ifs >> a.mWorkerGender && ifs >> a.mWorkerEmile && ifs >> a.mWorkerPhone
			&& ifs >> a.mWorkerDepartment)
		{
			vAdmin.push_back(a);
		}
	}
	

	ifs.close();

}

//检测部门是否有重复
bool Admin::CheckRepeatDepartment(int id)
{
	for (vector<Department>::iterator it = vDepartment.begin();
		it != vDepartment.end();it++)
	{
		if (id == it->mDepartmrntId)
		{
			return true;
		}
	}
}

//检测注册员工是否有重复
bool Admin::CheckRepeatWorker(int id,int type)
{
	if (type == 1)
	{
		//检测管理员
		for (vector<Manager>::iterator it = vManager.begin();
			it != vManager.end(); it++)
		{
			if (id == it->mWorkerId)
			{
				return true;
			}
		}
	}
	else
	{
		//检测普通员工
		for (vector<Employee>::iterator it = vEmployee.begin();
			it != vEmployee.end();it++)
		{
			if (id == it->mWorkerId)
			{
				return true;
			}
		}

	}
	
	return false;
}

