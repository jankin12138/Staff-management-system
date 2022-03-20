#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
	virtual void show() = 0;//œ‘ æ–≈œ¢

	virtual string getdeptname() = 0;

	int m_Id;
	string m_name;
	int m_DeptId;
};

class employee :public Worker
{
public:
	employee(int m_Id, string m_name, int m_DeptId);

	virtual void show();

	virtual string getdeptname();
};

class manager :public Worker
{
public:
	manager(int m_Id, string m_name, int m_DeptId);

	virtual void show();

	virtual string getdeptname();
};

class boss :public Worker
{
public:
	boss(int m_Id, string m_name, int m_DeptId);

	virtual void show();

	virtual string getdeptname();
};