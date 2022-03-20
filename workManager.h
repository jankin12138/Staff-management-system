#pragma once
#include <string.h>
#include "employee.h"
using namespace std;

#define  FILENAME   "´æ´¢.txt"

class workManager 
{
public:
	workManager();

	void showmenu();

	void exitSystem();

	void Add_massage();

	void showmember();

	void deletemember();

	void write_file();

	void read_file();

	void change_member();

	void search_member();
	
	void sort_member();

	void delete_file();

	int get_Num();
	
	void input_info(int&id, string& name);

	bool m_Isempty;
	
	int total_Num;

	Worker** total_Array;
	
	~workManager();

};