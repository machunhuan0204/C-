/*
*@Author:machunhuan
*@Data:2023/9/13
*@FilePath:
*
*@Description:
*1.ʵ���вι��죬�ɴ���ʵ��
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