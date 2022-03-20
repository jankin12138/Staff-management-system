#include <iostream>
#include<fstream>
using namespace std;

#include "workManager.h"
#include"employee.h"


workManager::workManager()
{
	this->total_Num = 0;
	this->total_Array = NULL;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在!" << endl;
		m_Isempty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件存在但无数据" << endl;
		m_Isempty = true;
		ifs.close();
		return;
	}
	ifs.close();
	read_file();
}

workManager::~workManager()
{
	if (this->total_Array != NULL)
	{
		delete[] this->total_Array;
	}
}

void workManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(1);
}
void workManager::showmenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void workManager::input_info(int& id, string& name)
{
	int k = 1;
	cout << "请输入职员编号" << endl;
	while (k)
	{
		cin >> id;
		if (m_Isempty == true)
		{
			k=0;
		}
		else
		{
			k = 0;
			for (int i = 0; i < total_Num; i++)
			{
				if (id == total_Array[i]->m_Id)
				{
					cout << "输入有误请重新输入" << endl;
					k = 1;
				}
			}
		}
	}
	cout << "请输入职员姓名" << endl;
	cin >> name;
}

void workManager::Add_massage()//添加信息
{
	int choice;
	int id;
	string name;
	int count=0;
	//ofstream ofs;
	system("cls");
	cout << "请输入需要创建的员工数量" << endl;
	cin >> count;
	if (count > 0)
	{
		int new_Num = this->total_Num + count;
		Worker** newspace = new Worker * [new_Num];
		if (total_Array != NULL)
		{
			for (int i = 0; i < this->total_Num; i++)
			{
				newspace[i] = this->total_Array[i];
			}
		}
		for (int i = 0; i < count; i++)
		{
			cout << "正在创建第" << i+1 << "个员工" << endl;
			input_info(id, name);
			cout << "请选择创建员工类型" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			while (1)
			{
				cin >> choice;
				if (choice < 4 && choice>0)
				{
					break;
				}
				cout << "输入有误请重新输入" << endl;
			}
			Worker* worker = NULL;
			switch (choice)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			}
			newspace[this->total_Num + i] = worker;
		}
		if (total_Array != NULL)
		{
			delete[] this->total_Array;
		}
		this->total_Array = newspace;
		this->total_Num = new_Num;
		this->m_Isempty = false;
		cout << count << "名职员添加成功" << endl;
		write_file();
	}
}

void workManager::write_file()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < total_Num; i++)
	{
		ofs << total_Array[i]->m_Id << " "
			<<total_Array[i]->m_name << " "
			<<total_Array[i]->m_DeptId << endl;
	}
	ofs.close();
}

void workManager::read_file()
{
	int count = get_Num();
	int id;
	int i = 0;
	string name;
	int deptid;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	this->total_Array = new Worker * [count];
	cout << this->total_Array << endl;
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		Worker* worker = NULL;
		switch (deptid)
		{
		case 1:
			worker = new employee(id, name, 1);
			break;
		case 2:
			worker = new manager(id, name, 2);
			break;
		case 3:
			worker = new boss(id, name, 3);
			break;
		}
		this->total_Array[i] = worker;
		i++;
	}
	this->total_Num = count;
	cout << this->total_Array<<"\t" << this->total_Num << "成功读取" << endl;
	ifs.close();
	m_Isempty = false;
}



int workManager::get_Num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int deptid;
	int i = 0;
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		i++;
	}
	return i;
}

void workManager::showmember()
{
	if (!m_Isempty)
	{
		for (int i = 0; i < this->total_Num; i++)
		{
			cout << "职工编号" << total_Array[i]->m_Id
				<< "\t职工姓名" << total_Array[i]->m_name
				<< "\t职工岗位" << total_Array[i]->getdeptname();
			switch (total_Array[i]->m_DeptId)
			{
			case 1:
				cout << "\t职工职责：完成经理的任务" << endl;
				break;
			case 2:
				cout << "\t职工职责：完成老板任务，发任务给员工" << endl;
				break;
			case 3:
				cout << "\t职工职责：统筹管理" << endl;
				break;
			}

		}
	}
	else
	{
		system("cls");
		cout << "文件不存在或为空!" << endl;
	}
	system("pause");
}

void workManager::deletemember()
{
	if (!m_Isempty)
	{
		int Delete_Number;
		int Isfound = 1;
		cout << "请输入需要删除的人员编号" << endl;
		cin >> Delete_Number;
		for (int i = 0; i < this->total_Num; i++)
		{
			if (Delete_Number == total_Array[i]->m_Id)
			{
				for (int j = i; j < this->total_Num - 1; j++)
				{
					total_Array[j] = total_Array[j + 1];
				}
				total_Array[this->total_Num - 1] = NULL;
				this->total_Num--;
				Isfound = 0;
				cout << "删除成功" << endl;
				write_file();
			}
		}
		if (Isfound)
		{
			cout << "未找到删除人员" << endl;
		}
	}
	else
	{
		system("cls");
		cout << "文件不存在或为空!" << endl;
	}
	system("pause");
}


void workManager::change_member()
{
	if (!m_Isempty)
	{
		int Change_Number;
		int Isfound = 1;
		int id;
		string name;
		int deptid;
		cout << "请输入需要修改的人员编号" << endl;
		cin >> Change_Number;
		for (int i = 0; i < this->total_Num; i++)
		{
			if (Change_Number == total_Array[i]->m_Id)
			{
				Isfound = 0;
				cout << "请输入修改后员工编号：" << endl;
				cin >> id;
				//total_Array[i]->m_Id = id;
				cout << "请输入修改后员工姓名：" << endl;
				cin >> name;
				//total_Array[i]->m_name = name;
				cout << "请输入修改后部门编号：" << endl;
				cin >> deptid;
				//total_Array[i]->m_DeptId = deptid;
				switch (deptid)
				{
				case 1:
					total_Array[i] = new employee(id, name, 1);
					break;
				case 2:
					total_Array[i] = new manager(id, name, 2);
					break;
				case 3:
					total_Array[i] = new boss(id, name, 3);
					break;
				}
				write_file();
			}
		}
		if (Isfound)
		{
			cout << "未找到修改人员" << endl;
		}
	}
	else
	{
		system("cls");
		cout << "文件不存在或为空!" << endl;
	}
	system("pause");
}

void workManager::search_member()
{
	if (!m_Isempty)
	{
		int Search_Number;
		int Isfound = 1;
		cout << "请输入需要查找的人员编号" << endl;
		cin >> Search_Number;
		for (int i = 0; i < this->total_Num; i++)
		{
			if (Search_Number == total_Array[i]->m_Id)
			{
				cout << "职工编号" << total_Array[i]->m_Id
					<< "\t职工姓名" << total_Array[i]->m_name
					<< "\t职工岗位" << total_Array[i]->getdeptname();
				switch (total_Array[i]->m_DeptId)
				{
				case 1:
					cout << "\t职工职责：完成经理的任务" << endl;
					break;
				case 2:
					cout << "\t职工职责：完成老板任务，发任务给员工" << endl;
					break;
				case 3:
					cout << "\t职工职责：统筹管理" << endl;
					break;
				}
				Isfound = 0;
			}
		}
		if (Isfound)
		{
			cout << "未找到需要查找的人员" << endl;
		}
	}
	else
	{
		system("cls");
		cout << "文件不存在或为空!" << endl;
	}
	system("pause");
}

void workManager::sort_member()
{
	if (!m_Isempty)
	{
		int sort_number;
		cout << "请选择输入排序：" << endl;
		cout << "1.升序排序" << endl;
		cout << "2.降序排序" << endl;
		cin >> sort_number;
		Worker* temp = NULL;
		if (sort_number == 1)
		{
			for (int j = 0; j < total_Num - 1; j++)
			{
				for (int i = 0; i < total_Num - 1; i++)
				{
					if (total_Array[i]->m_Id > total_Array[i + 1]->m_Id)
					{
						temp = total_Array[i];
						total_Array[i] = total_Array[i + 1];
						total_Array[i + 1] = temp;
					}
				}
			}
			write_file();
		}
		else if (sort_number == 2)
		{
			for (int j = 0; j < total_Num - 1; j++)
			{
				for (int i = 0; i < total_Num - 1; i++)
				{
					if (total_Array[i]->m_Id < total_Array[i + 1]->m_Id)
					{
						temp = total_Array[i];
						total_Array[i] = total_Array[i + 1];
						total_Array[i + 1] = temp;
					}
				}
			}
			write_file();
		}
		cout << "操作成功" << endl;
	}
	else
	{
		system("cls");
		cout << "文件不存在或为空!" << endl;
	}
	system("pause");
}

void workManager::delete_file()
{
	if (!m_Isempty)
	{
		ofstream ofs;
		string a;
		cout << "请按y确认是否清除" << endl;
		cin >> a;
		if (a == "y")
		{
			ofs.open(FILENAME, ios::trunc);
			ofs.close();
			delete[] total_Array;
			this->total_Array = NULL;
			this->total_Num = 0;
			this->m_Isempty = true;
		}
		else
		{
			cout << "操作取消" << endl;
		}
	}
	else
	{
		system("cls");
		cout << "文件不存在或为空!" << endl;
	}
	system("pause");
}

