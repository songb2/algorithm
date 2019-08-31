// ReverseList.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include "stdafx.h"
#include "..\Utilities\List.h"

ListNode* ReverseList(ListNode* pHead)
{
    ListNode* pReversedHead = NULL;
    ListNode* pNode = pHead;
    ListNode* pPrev = NULL;
    while(pNode != NULL)
    {
        ListNode* pNext = pNode->m_pNext;

        if(pNext == NULL)
            pReversedHead = pNode;

        pNode->m_pNext = pPrev;

        pPrev = pNode;
        pNode = pNext;
    }

    return pReversedHead;
}

ListNode* ReverseList1(ListNode* pHead)
{
	ListNode* pre = NULL;
	ListNode* cur = pHead;
	ListNode* tmp = cur;
	while (tmp != NULL)
	{
		tmp = cur->m_pNext;
		cur->m_pNext = pre;
		pre = cur;
		cur = tmp;
	}

	return pre;
}

ListNode * reverseNonrecurisve(ListNode * head) {
	if (head == NULL) return head;
	ListNode * current = head;
	ListNode * previous = NULL;
	//while (current->m_pNext != NULL) {
	//	ListNode* tmp = current->m_pNext;
	//	current->m_pNext = previous;
	//	previous = current;
	//	current = tmp;
	//}
	ListNode* tmp = current->m_pNext;
	while (tmp != NULL) {		
		current->m_pNext = previous;
		previous = current;
		current = tmp;
		tmp = tmp-> m_pNext;
	}
	current->m_pNext = previous;
	return current;
}

ListNode * reverseRecursive(ListNode * head) {
	if (head == NULL) return head;
	if (head->m_pNext == NULL) return head;
	ListNode * ph = reverseRecursive(head->m_pNext);
	head->m_pNext->m_pNext = head;
	head->m_pNext = NULL;
	return ph;
}



// ====================测试代码====================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = reverseRecursive(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入空链表
void Test3()
{
    Test(NULL);
}

int _tmain(int argc, _TCHAR* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}

