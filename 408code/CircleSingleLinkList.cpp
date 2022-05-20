#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} DNode, *LinkList;
//循环单链表 最后一个结点的指针不是NULL,而是指向头结点
//单链表和循环单链表的比较：
//**单链表：**从一个结点出发只能找到该结点后续的各个结点；对链表的操作大多都在头部或者尾部；设立头指针，
//从头结点找到尾部的时间复杂度=O(n)，即对表尾进行操作需要O(n)的时间复杂度;
//**循环单链表：**从一个结点出发，可以找到其他任何一个结点；设立尾指针，从尾部找到头部的时间复杂度为O(1)，
//即对表头和表尾进行操作都只需要O(1)的时间复杂度;

//==优点：==从表中任一节点出发均可找到表中其他结点。

// 初始化一个循环单链表 
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); //分配一个头结点
    if (L == NULL)                      //内存不足，分配失败
        return false;
    L->next = L;                         //头结点next指针指向头结点      关键点
    return true;
}

//判断循环单链表是否为空（终止条件为p或p->next是否等于头指针）
bool Empty(LinkList L)
{
    if (L->next == L)
        return true; //为空
    else
        return false;
}

//判断结点p是否为循环单链表的表尾结点
bool isTail(LinkList L, LNode *p)
{
    if (p->next == L)
        return true;
    else
        return false;
}
