/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
*1.实现有参构造，可创建实例
*
*
*
*/


#include<iostream>
#include<string>
#include"department.h"

using namespace std;

Department::Department()
{

}

Department::Department(int DepartmrntId, string DepartmentName,
	int DepartmentDescribe)
{
	this->mDepartmrntId = DepartmrntId;
	this->mDepartmentName = DepartmentName;
	this->mDepartmentDescribe = DepartmentDescribe;
}