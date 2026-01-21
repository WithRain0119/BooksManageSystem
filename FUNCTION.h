#ifndef FUNCTION_H
#define FUNCTION_H

#include <bits/stdc++.h>
#include <windows.h>

using namespace std;
#define CAPACITY_MAXSIZE 100
#define SleepTime 2  //µ¥Î»ÎªÃë

extern int is_input_error;

typedef struct {
	char ISBN[20];
	char name[50];
	double money;
}Book;

typedef struct {
	Book* Books;
	int length;
	int Capacity;
}SqList;

void showStartScreen();
void initList(SqList* L, int initCapacity);
void addBooks(SqList* L);
void showBooks(SqList L);
int ListInsert(SqList* L);
void deleteList(SqList* L);
void endFunction(int Function);
int getLength(SqList L);
void showFunctionChoices(SqList L);
void deleteABook(SqList* L);
void LocateBook(SqList L);
bool IsEmpty(SqList L);

#endif 

