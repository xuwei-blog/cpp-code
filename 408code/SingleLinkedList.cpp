#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    LNode *next;
} LNode, *LinkList;

//初始化一个单链表（带头结点） L指向的是头结点！
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); //头指针指向的结点    头结点（不存储数据）
    if (L == NULL)                      //内存不足，分配失败
        return false;
    L->next = NULL; //头结点之后暂时还没有结点
    return true;
}

//判断单链表是否为空（带头结点）
bool IsEmpty(LinkList L)
{
    if (L->next == NULL)
        return true;
    else
        return false;
}

//在第i个位置插入元素e（带头结点）
bool ListInsert(LinkList &L, int i, ElemType e)
{
    // 1.找到第i-1个结点p
    // 2.p结点后插元素e

    // 1.找到第i-1个结点p
    //判断i的合法性, i是位序号(从1开始)   i=0是头结点的下标
    if (i < 1)
        return false;
    LNode *p;  //指针p指向当前扫描到的结点
    int j = 0; //当前p指向的是第几个结点
    p = L;     // L指向头结点，头结点是第0个结点（不存数据）

    //循环找到第i-1个结点
    while (p != NULL && j < i - 1)
    {                //找第i-1个结点   如果超出了总结点数p->NULL就退出了
        p = p->next; // p指向下一个结点
        j++;
    }

    // 2.p结点后插元素e
    if (p == NULL) // i值不合法
        return false;
    //在第i-1个结点后插入新结点
    LNode *s = (LNode *)malloc(sizeof(LNode)); //申请一个结点
    s->data = e;
    s->next = p->next;
    p->next = s; //将结点s连到p后,后两步千万不能颠倒qwq

    return true;
}

//指定删除（带头结点）
bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if (i < 1)
        return false;

    LNode *p;  //指针p指向当前扫描到的结点
    int j = 0; //当前p指向的是第几个结点
    p = L;     // L指向头结点，头结点是第0个结点（不存数据）

    //循环找到第i-1个结点
    while (p != NULL && j < i - 1) //如果i>lengh, p最后会等于NULL
    {
        p = p->next; // p指向下一个结点
        j++;
    }
    if (p == NULL)
        return false;

    if (p->next == NULL) //第i-1个结点之后已无其他结点
        return false;

    LNode *q = p->next; //令q指向被删除的结点
                        //以下3步是必须的  上面一步只是便于理解
    e = q->data;        //用e返回被删除元素的值
    p->next = q->next;  //将*q结点从链中“断开”
    free(q);            //释放结点的存储空间

    return true;
}

//指定结点删除
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;

    LNode *q = p->next; //令q指向*p的后继结点
    p->data = q->data;  //删除p前 p的后继结点的数据前移
    p->next = q->next;  //将*q结点从链中“断开”
    free(q);
    return true;
} //时间复杂度 = O(1)

//按位查找
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;

    LNode *p;                  //指针p指向当前扫描到的结点
    int j = 0;                 //当前p指向的是第几个结点
    p = L;                     // L指向头结点,头结点是第0个结点(不存数据)
    while (p != NULL && j < i) //循环找到第i个结点
    {
        p = p->next;
        j++;
    }

    return p; //返回p指针指向的值
}

//按值查找
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next; // p指向第一个结点
    //从第一个结点开始查找数据域为e的结点
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p; //找到后返回该结点指针，否则返回NULL
}

//求表长
int Length(LinkList L)
{
    int len = 0; //统计表长
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//头插法建立单链表（平均时间复杂度O(n)）
LinkList List_HeadInsert(LinkList &L)
{ //逆向建立单链表
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode)); //建立头结点
    L->next = NULL;                      //初始为空链表,这步不能少！ 清空脏数据

    scanf("%d", &x); //输入要插入的结点的值
    while (x != 9999)
    {                                       //输入9999表结束
        s = (LNode *)malloc(sizeof(LNode)); //创建新结点
        s->data = x;
        s->next = L->next;                //如果没有清除脏数据  插入第一个结点可能出错
        L->next = s;                   //s作为第一个结点
        scanf("%d", &x);
    }
    return L;
}

//尾插法（用到尾指针）
LinkList List_TailInsert(LinkList &L)    //正向建立单链表
{                                        
    int x; 
    L = (LinkList)malloc(sizeof(LNode)); 
    LNode *s ,*r = L;                    //r是尾指针

    scanf("%d", &x);                     //输入要插入的结点的值
    while (x != 9999)
    { //输入9999表结束
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;    //尾结点指向s
        r = s;          //s作为尾结点
        scanf("%d", &x);
    }
    r->next = NULL; //尾结点指针置空
    return L;
}

//链表逆置
LinkList Inverse(LinkList &L)
{
	LNode *p, *q;
	p = L->next;     //p指针指向第一个结点
	L->next = NULL;  //头结点指向NULL

	while (p != NULL){
		q = p;
		p = p->next;
		q->next = L->next;  
		L->next = q;
	}
	return L;
}


int main()
{
    LinkList L; //声明一个指向单链表的指针: 头指针
    List_HeadInsert(L);
    for (int i = 1; i < Length(L); i++)
    {
        printf("data[%d]=%d\n", i, L->data);
    }

    return 0;
}
