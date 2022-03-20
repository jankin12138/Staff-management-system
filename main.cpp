#include <iostream>

#include "workManager.h"
#include"employee.h"
using namespace std;


int main()
{
	workManager wk;
	int control_number = 0;
	while (1) 
	{
		system("cls");
		wk.showmenu();
		cin >>  control_number;
		switch (control_number)
		{		
		case 1://增加信息
			wk.Add_massage();
			break;
		case 2://显示信息
			wk.showmember();
			break;
		case 3://删除离职职工
			wk.deletemember();
			break;
		case 4://修改职工信息
			wk.change_member();
			break;
		case 5://查找职工信息
			wk.search_member();
			break;
		case 6://编号排序
			wk.sort_member();
			break;
		case 7://清空文档
			wk.delete_file();
			break;
		case 0://退出
			wk.exitSystem();
		}
	}
	system("pause");
	return 0;
}