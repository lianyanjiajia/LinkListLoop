#pragma once
#include <iostream>  
#include <iomanip> 
class Node
{
public:
	int data;
	Node *next;
	Node()
	{
		next = NULL;
	}
};


class LinkList
{
private:
	
public:
	Node *head;
	LinkList();
	void Create();                                                     //创建链表  
	void Display()const;                                           //显示链表  
	~LinkList();                                                            //销毁链表  
	int getlen() const;                                              //获取链表长度  
	bool isEmpty() const;                                         //判断链表是否为空  
	bool Find(const int e) const;                              //在链表中查找某个值  
	Node* GetNode(int i) const;                            //返回第i个节点  
	void Insert(int i, const int e);                               //在第i个位置插入元素e  
	void Delete(const int e);                                     //删除一个元素e   
	void Reverse();                                                   //链表逆置 
};
