#pragma once
#include <iostream>
#include <string>
#include"employee.h"

employee::employee(int m_Id, string m_name, int m_DeptId) 
{
	this->m_Id = m_Id;
	this->m_name = m_name;
	this->m_DeptId = m_DeptId;
}

void employee::show()
{
	cout << "职工编号" << this->m_Id
		<< "\t职工姓名" << this->m_name
		<< "\t职工岗位" << this->getdeptname()
		<< "\t职工职责：完成经理的任务" << endl;
	system("pause");
}

string employee::getdeptname()
{
	return "员工";
}



manager::manager(int m_Id, string m_name, int m_DeptId)
{
	this->m_Id = m_Id;
	this->m_name = m_name;
	this->m_DeptId = m_DeptId;
}

void manager::show()
{
	cout << "职工编号： " << this->m_Id
		<< "\t职工姓名： " << this->m_name
		<< "\t部门编号" << this->m_DeptId
		<< "\t职工岗位： " << this->getdeptname()
		<< "\t职工职责：完成老板任务，发任务给员工" << endl;
	system("pause");
}

string manager::getdeptname()
{
	return "经理";
}



boss::boss(int m_Id, string m_name, int m_DeptId)
{
	this->m_Id = m_Id;
	this->m_name = m_name;
	this->m_DeptId = m_DeptId;
}

void boss::show()
{
	cout << "职工编号" << this->m_Id
		<< "\t职工姓名" << this->m_name
		<< "\t职工岗位" << this->getdeptname()
		<< "\t职工职责：统筹管理" << endl;
	system("pause");
}

string boss::getdeptname()
{
	return "老板";
}