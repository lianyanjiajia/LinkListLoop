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
	void Create();                                                     //��������  
	void Display()const;                                           //��ʾ����  
	~LinkList();                                                            //��������  
	int getlen() const;                                              //��ȡ������  
	bool isEmpty() const;                                         //�ж������Ƿ�Ϊ��  
	bool Find(const int e) const;                              //�������в���ĳ��ֵ  
	Node* GetNode(int i) const;                            //���ص�i���ڵ�  
	void Insert(int i, const int e);                               //�ڵ�i��λ�ò���Ԫ��e  
	void Delete(const int e);                                     //ɾ��һ��Ԫ��e   
	void Reverse();                                                   //�������� 
};
