//顺序表的实现--静态分配

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10 //定义表的最大长度
typedef struct
{
	int data[MaxSize]; //用静态的"数组"存放数据元素
	int length;		   //顺序表的当前长度
} SqList;			   //顺序表的类型定义（静态分配方式）
void InitList(SqList &L)
{
	for (int i = 0; i < MaxSize; i++)
	{
		L.data[i] = 0; //将所有数据元素设置为默认初始值
	}
	L.length = 0;
}

//插入操作
bool ListInsert(SqList &L, int i, int e)
{
	//判断i的范围是否有效
	if (i < 1 || i > L.length + 1)
		return false;
	if (L.length > MaxSize) //当前存储空间已满，不能插入
		return false;

	for (int j = L.length; j >= i; j--)
	{ //从数组右边开始 右移
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e; //在位置i处放入e
	L.length++;		   //长度加1
	return true;
}

//删除操作
bool ListDelete(SqList &L, int i, int &e)
{ // e用引用型参数
	//判断i的范围是否有效
	if (i < 1 || i > L.length) //删除操作比插入操作长度小1
		return false;

	e = L.data[i - 1]; //将被删除的元素赋值给e

	for (int j = i; j < L.length; j++)
	{ //将第i个后的元素前移
		L.data[j - 1] = L.data[j];
	}
	L.length--; //长度减1
	return true;
}

//按位查找(获取L表中第i个位置的值)
int GetElem(SqList L, int i)
{
	//判断i的范围是否有效
	if (i < 1 || i > L.length) //比插入操作长度小1
		return false;          //无效范围

	return L.data[i - 1];     //注意是i-1
}

//在顺序表L中查找第一个元素值等于e的元素，并返回其位序
int LocateElem(SqList L, int e){
    for(int i=0; i<L.length;i++)
        if(L.data[i] == e)  
            return i+1;     //数组下标为i的元素值等于e，返回其位序i+1
    return false;               //推出循环，说明查找失败
}

//销毁 清空 是否为空  动态数组才能使用
// bool SqlDestroy(SqList &L)
// {
// 	if (!L.data)
// 		return false;
// 	else
// 	{
// 		free(L.data);
// 		return true;
// 	}
// }
// void SqlClear(SqList &L) 
// {
// 	 L.length = 0; 
// }
// bool SqlIsEmpty(SqList L)
// {
// 	if (0 == L.length)
// 		return true;
// 	else
// 		return false;
// }

int main()
{
	SqList L;	 //声明一个顺序表
	InitList(L); //初始化顺序表
	for (int i = 0; i < 5; i++)
	{
		L.data[i] = i + 10;
		L.length++;
	}

	//插入 删除  验证通过
	//ListInsert(L, 3, 5); //在第三个位置插入5
	//int temp;			 //存储返回删除的元素
	//ListDelete(L, 3, temp);
	// for (int i = 0; i < L.length; i++)
	// {
	// 	printf("data[%d] = %d\n", i, L.data[i]);
	// }


	//按位查找元素 按元素查找位  验证通过
	//printf("%d",GetElem(L,3));
	//printf("%d",LocateElem(L,11));
	
	




	return 0;
}