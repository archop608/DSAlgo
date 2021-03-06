//
// LinkedListAddTwoNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// You are given two non - empty linked lists representing two non - negative integers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//

#include "pch.h"
#include <iostream>

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode *curr = new ListNode(0);
		ListNode *head = curr;
		//ListNode *iterl1 = l1;
		//ListNode *iterl2 = l2;
		
		//
		// Another point to note here is that you can directly use the values l1, l2 passed to the method.
		// A single pointer is passed here, so even if you change the pointer by doing l1 = l1->next; the actual value 
		// of l1 at the calling point won't change. If change l1->value to something else that will definitely reflect outside
		// the method. To change the pointer itself we need to pass **ptr instead of just *ptr.
		//

		long sum = 0, carry = 0;

		while (l1 != NULL || l2 != NULL)
		{
			int val1 = (l1 != NULL) ? l1->val : 0;
			int val2 = (l2 != NULL) ? l2->val : 0;
			sum = val1 + val2 + carry;
			carry = sum / 10;
			ListNode *newNode = new ListNode(sum % 10);
			curr->next = newNode;
			curr = curr->next;
			if(l1 != NULL) l1 = l1->next;
			if(l2 != NULL) l2 = l2->next;
		}

		if (carry > 0)
		{
			ListNode *newNode = new ListNode(carry);
			curr->next = newNode;
			curr = curr->next;
		}

		//
		// Important point to note here is that you cannot do delete(curr) here.
		// Because curr points to the last node of the linked list. One might think that only the pointer will be deleted 
		// when we do delete but since that memory is released the memory manager garbages the value present in that address.
		// One should never use the value present at the address that is already released. Since, we have to use the value later
		// we cannot delete curr here.
		//

		return head->next;
	}

	ListNode* CreateListWithRandomValues(long ListSize)
	{
		ListNode *curr = new ListNode(0);
		ListNode *head = curr;
		while (ListSize-- > 0)
		{
			ListNode *newNode = new ListNode(rand() % 10);
			curr->next = newNode;
			curr = curr->next;
		}
		PrintOutput(head->next);
		return head->next;
	}

	void PrintOutput(ListNode* output)
	{
		ListNode *outIter = output;
		while (outIter != NULL)
		{
			std::cout << outIter->val <<" ";
			outIter = outIter->next;
		}

		std::cout << "\n";
	}
};

int main()
{
	Solution sol1;
	ListNode* l1 = sol1.CreateListWithRandomValues(3);
	ListNode* l2 = sol1.CreateListWithRandomValues(3);
	ListNode* out = sol1.AddTwoNumbers(l1, l2);
	sol1.PrintOutput(out);
}
