#pragma once
#include<iostream>
#include<string>

using namespace std;

class Department
{
public:
	friend class Admin;
	friend class Manager;
	//���ű��  
	int mDepartmrntId;
	//��������  
	string mDepartmentName;
	//��������   
	int mDepartmentDescribe;

	Department();

	Department(int DepartmrntId, string DepartmentName, int DepartmentDescribe);
	

};
