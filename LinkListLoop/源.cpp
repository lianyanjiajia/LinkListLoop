#include"LinkList.h"
using namespace std;
int main()
{
	
}
//�ж��Ƿ��л�  
bool isLoop(Node* pHead)
{
	Node* fast = pHead;
	Node* slow = pHead;
	//����޻�����fast���ߵ��յ�  
	//��������Ϊ����ʱ��fast->NextΪ��  
	//��������Ϊż��ʱ��fastΪ��  
	while (fast != NULL && fast->next != NULL)
	{

		fast = fast->next->next;
		slow = slow->next;
		//����л�����fast�ᳬ��slowһȦ  
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

//���㻷�ĳ���  
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
		//����Ȧ��ֹͣ����������ѭ��  
		if (fast == slow && agian == true)
			break;
		//��һȦ��ʼ����  
		if (fast == slow && agian == false)
		{
			begin = true;
			agian = true;
		}

		//����  
		if (begin == true)
			++length;

	}
	return length;
}


//���������ڵ�  
Node* findLoopEntrance(Node* pHead)
{
	Node* fast = pHead;
	Node* slow = pHead;
	while (fast != NULL && fast->next != NULL)
	{

		fast = fast->next->next;
		slow = slow->next;
		//����л�����fast�ᳬ��slowһȦ  
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
//����һ���л�������
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
	q->next = Findnode(head, rand() % N);//����������Ľ����
	return head;
}
Node* Findnode(Node* head, int n)//�ҳ������еĵ�n�����
{
	if (n <= 0)
		return head;
	Node* p = head->next;
	for (int i = 1;p&&i<n;++i)
		p = p->next;
	return p;
}