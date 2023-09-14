#pragma once
#include<iostream>
#include<string>

using namespace std;

class Department
{
public:
	friend class Admin;
	friend class Manager;
	//部门编号  
	int mDepartmrntId;
	//部门名称  
	string mDepartmentName;
	//部门描述   
	int mDepartmentDescribe;

	Department();

	Department(int DepartmrntId, string DepartmentName, int DepartmentDescribe);
	

};
