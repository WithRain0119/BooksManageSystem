#include "FUNCTION.h"

int is_input_error = 0;

void showStartScreen()
{
	cout << setw(58) << "欢迎进入图书管理系统" << endl;
	Sleep(1000);
	cout << setw(58) << "三秒后将进入主界面 " << endl;
	
	for (int i = 3;i >= 1;i--)
	{
		Sleep(1000);//延迟一秒
		cout <<setw(48)<< i << "..." << endl;
		
	}
	Sleep(1000);
	system("cls");



	return;
}

void endFunction(int Function)
{
	is_input_error = 0;
	cout << "操作" << Function << "已完成！" << endl;
	Sleep(SleepTime * 1000);
	/*system("pause");*/
	system("cls");
}

void initList(SqList* L, int initCapacity)
{
	if(L->Books == NULL)
		L->Books = (Book*)malloc(initCapacity * sizeof(Book));
	L->length = 0;
	
	L->Capacity = initCapacity;
}

void addBooks(SqList* L)
{
	if (L->Books == NULL)
	{
		cout << "请先进行初始化" << endl;
		return;
	}
	if (L->length == L->Capacity)
	{
		cout << "书满了，无法添加" << endl;
		return;
	}
	cout << "添加几本书 ? " << endl;
	int addsize = 0;
	cin >> addsize;
	cout << "请输入"<< addsize<<"本书的ISBN和name和price" << endl;
	if ((L->length) + addsize > L->Capacity)
	{
		cout << "超过总容量无法添加" << endl;
		return;
	}
	for (int i = L->length;i < L->length + addsize;i++)
	{
		cin >> L->Books[i].ISBN >> L->Books[i].name >> L->Books[i].money;
	}
	L->length += addsize;

}

void showBooks(SqList L)
{
	/*cout << "ISBN\tname\tprice" << endl;*/

	cout << "ISBN" << setw(50) << "name" << setw(40) << "price" << endl;
	cout << string(100, '-') << endl;

	if (L.length == 0)
		cout << setw(58) << "暂无任何书籍" << endl;

	for (int i = 0;i < L.length;i++)
	{

		cout << L.Books[i].ISBN << setw(50) << L.Books[i].name << setw(30) << (double)(L.Books[i].money) << endl;
	}
	if (getLength(L) != 0)
		cout << endl << setw(90) << "共计" << getLength(L) << "本书籍" << endl;
	cout << endl;
}

int ListInsert(SqList* L)
{
	if (L->length == L->Capacity)
	{
		cout << "容量已满，无法插入" << endl;
		return -1;
	}
	cout << "请输入在哪里插入：";
	int index = 0;
	cin >> index;
	int i = index;
	if (i < 1 || i > L->length + 1)
	{
		cout << "超出范围" << endl;
		return -1;
	}

	cout << "请输入ISBN和name和price" << endl;
	Book book;
	cin >> book.ISBN >> book.name >> book.money;

	for (int j = L->length - 1;j >= i - 1;j--)
	{
		L->Books[j + 1] = L->Books[j];
	}
	L->Books[i - 1] = book;
	L->length++;
	return 0;
}

void deleteList(SqList* L)
{
	free(L->Books);
	L->Books = NULL;
	L->length = 0;
	L->Capacity = 0;
}

int getLength(SqList L)
{
	return (L.length);
}

void showFunctionChoices(SqList L)
{
	showBooks(L);
	cout << "请选择功能 ：" << endl;
	vector<string> F =
	{
		"退出",
		"添加书籍",
		"初始化图书管理系统",
		"删除图书管理系统",
		"插入新书籍",
		"删除某个书籍",
		"查询书籍",
		"查询该图书系统是否为空"

	};
	//int cnt = 0;
	for (int i = 0;i < F.size();i++)
	{
		/*if (cnt != 0 && cnt % 5 == 0)
		{
			cout << endl;
			i--;
		}*/
			
		cout << "[" << i << "]:" << F[i] << "  " <<endl;
		//cnt++;
	}
	cout << endl;
}

void deleteABook(SqList* L)
{
	int index = 0;
	cout << "请输入删除第几个" << endl;
	cin >> index;
	if (index < 1 || index >L->length)
	{
		cout << "输入不在范围内" << endl;
		return;
	}
	index--;

	for (int i = index;i <= L->length - 1;i++)
	{
		L->Books[i] = L->Books[i + 1];
	}
	L->length--;	
}

void LocateBook(SqList L)
{
	if (IsEmpty(L) == true)
	{
		cout << "当前书库为空，无法查询" << endl;
		return;
	}
	cout << "请输入ISBN 和 name 和 price" << endl;
	Book book;
	cin >> book.ISBN >> book.name >> book.money;

	int index = -1;
	for (int i = 0;i < L.length;i++)
	{
		if (strcmp(L.Books[i].ISBN,book.ISBN) == 0 && strcmp(L.Books[i].name,book.name) == 0 && L.Books[i].money == book.money)
		{
			index = i + 1;
			break;
		}
	}
	if (index == -1)
		cout << "未查询到这本书" << endl;
	else
	{
		cout << "这是第" << index << "本书" << endl;
	}
}

bool IsEmpty(SqList L) 
{
	if (getLength(L) == 0)
	{
		
		return true;
	}
	else
	{
		
		return false;
	}
}

