#include <bits/stdc++.h>
using namespace std;
#include "FUNCTION.h"

int main()
{

	showStartScreen();

	SqList List1 = {NULL,0,0};
	initList(&List1, CAPACITY_MAXSIZE);

	while (1)
	{
		if (is_input_error == 0)
		{
			showFunctionChoices(List1);
		}

		int Function = 0;
		cin >> Function;

		switch (Function)
		{
		case 0:
			if (List1.Books != NULL)
				deleteList(&List1);
			cout << "已退出" << endl;
			return 0;
		case 1:
			addBooks(&List1);
			endFunction(Function);
			break;
		case 2:
			initList(&List1, CAPACITY_MAXSIZE);
			endFunction(Function);
			break;
		case 3:
			deleteList(&List1);
			endFunction(Function);
			break;
		case 4:
			ListInsert(&List1);
			endFunction(Function);
			break;
		case 5:
			deleteABook(&List1);
			endFunction(Function);
			break;
		case 6:
			LocateBook(List1);
			endFunction(Function);
			break;
		case 7:
			if (IsEmpty(List1) == true)
				cout << "当前为空" << endl;
			else
				cout << "当前不为空" << endl;
			endFunction(Function);
			break;
		default:
			cout << "请输入正确的功能代号" << endl;
			is_input_error = 1;
		}
	}




	return 0;
}
