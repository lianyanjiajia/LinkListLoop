#include"LinkList.h"
using namespace std;
int main()
{
	
}
//判断是否有环  
bool isLoop(Node* pHead)
{
	Node* fast = pHead;
	Node* slow = pHead;
	//如果无环，则fast先走到终点  
	//当链表长度为奇数时，fast->Next为空  
	//当链表长度为偶数时，fast为空  
	while (fast != NULL && fast->next != NULL)
	{

		fast = fast->next->next;
		slow = slow->next;
		//如果有环，则fast会超过slow一圈  
		if (fast == slow)
		{
			break;
		}
	}

	if (fast == NULL || fast->next == NULL)
		return false;
	else
		return true;
}

//计算环的长度  
int loopLength(Node* pHead)
{
	if (isLoop(pHead) == false)
		return 0;
	Node* fast = pHead;
	Node* slow = pHead;
	int length = 0;
	bool begin = false;
	bool agian = false;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		//超两圈后停止计数，挑出循环  
		if (fast == slow && agian == true)
			break;
		//超一圈后开始计数  
		if (fast == slow && agian == false)
		{
			begin = true;
			agian = true;
		}

		//计数  
		if (begin == true)
			++length;

	}
	return length;
}


//求出环的入口点  
Node* findLoopEntrance(Node* pHead)
{
	Node* fast = pHead;
	Node* slow = pHead;
	while (fast != NULL && fast->next != NULL)
	{

		fast = fast->next->next;
		slow = slow->next;
		//如果有环，则fast会超过slow一圈  
		if (fast == slow)
		{
			break;
		}
	}
	if (fast == NULL || fast->next == NULL)
		return NULL;
	slow = pHead;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}
Node* CreatlinkLoop()
//创建一个有环的链表
{
	Node* head = new Node;
	//head->data=0;
	head->next = NULL;
	int e;
	Node* q = head;
	int N = 0;
	cout << "input elems:";
	while (cin >> e)
	{
		Node* p = new Node;
		++N;
		p->data = e;
		p->next = q->next;
		q->next = p;
		q = p;
	}
	cin.clear();
	cin.sync();
	srand(time(0));
	q->next = Findnode(head, rand() % N);//随机产生环的接入点
	return head;
}
Node* Findnode(Node* head, int n)//找出链表中的第n个结点
{
	if (n <= 0)
		return head;
	Node* p = head->next;
	for (int i = 1;p&&i<n;++i)
		p = p->next;
	return p;
}