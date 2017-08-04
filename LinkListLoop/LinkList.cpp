#include "LinkList.h"
using namespace std;
LinkList::LinkList()
{
	head = new Node();
	head->next = NULL;
}

void LinkList::Create()//尾插法生成链表
{
	Node *p, *q;
	p = head;
	q = new Node();
	cout << "请输入值(按ctrl+z停止): " << endl;
	while (cin >> q->data)
	{
		p->next = q;
		p = q;
		q = new Node();
	}
}

void LinkList::Display() const             //显示链表  
{
	Node *p;
	p = head->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

LinkList::~LinkList()
{
	Node *p;
	while (head)
	{
		p = head->next;
		delete head;
		head = p;
	}
}

int LinkList::getlen() const
{
	int length = 0;
	Node *p = head->next;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}

bool LinkList::isEmpty() const
{
	return (head->next == NULL);
}

bool LinkList::Find(const int e) const
{
	Node* p = head->next;
	while (p)
	{
		if (p->data == e)
			return true;
		p = p->next;
	}
	return false;
}

Node* LinkList::GetNode(int i) const
{
	if (i<0 || i>getlen())                         //i不在链表范围内时，抛出异常  
	{
		throw i;
	}
	Node* p = head;
	while (p&&i)
	{
		p = p->next;
		i--;
	}
	return p;
}

void LinkList::Insert(int i, const int e)
{
	Node *p;
	Node *node = new Node();
	node->data = e;
	if (i == 1)                                       //在第一个位置插入节点  
	{
		node->next = head->next;
		head->next = node;
	}
	else
	{
		p = GetNode(i - 1);
		if (i == getlen())                         //在链表末位插入节点  
			p->next = node;
		else
		{
			node->next = p->next;
			p->next = node;
		}
	}
}

void LinkList::Delete(const int e)
{
	if (!Find(e))
	{
		cout << "链表不包含值为" << e << "的节点!" << endl;
		return;
	}
	Node *p = head;
	Node *q = head->next;
	while (q)
	{
		if (q->data == e)
		{
			break;
		}
		p = p->next;
		q = q->next;
	}
	p->next = q->next;
	return;
}

void LinkList::Reverse()
{
	if (isEmpty())
	{
		cout << "链表为空" << endl;
		return;
	}
	Node *p, *q;
	int len = getlen();
	int i = 1;
	int j = len;
	while (i<j)
	{
		p = GetNode(i);
		q = GetNode(j);
		int temp = p->data;
		p->data = q->data;
		q->data = temp;
		++i;
		--j;
	}
}