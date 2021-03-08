// Add two numbers stored in linklists

#include<iostream>
using namespace std;
 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *ptrl1 = l1;
		ListNode *ptrl2 = l2;
		ListNode *result, *ptrresult;
		int rem, div = 0;
		result = new ListNode;
		ptrresult = result;
		do
		{
			rem = (ptrl1->val + ptrl2->val + div) % 10;
			ptrresult->val = rem;
			div = (ptrl1->val + ptrl2->val+div) / 10;
			ptrl1 = ptrl1->next;
			ptrl2 = ptrl2->next;

			if (ptrl1 || ptrl2||div)
			{
				ptrresult->next = new ListNode;
				ptrresult = ptrresult->next;
			}

		} while (ptrl1 && ptrl2);

		while (ptrl1 && !ptrl2)
		{
			ptrresult->val = (ptrl1->val + div) % 10;
			div = (ptrl1->val + div) / 10;
			ptrl1 = ptrl1->next;
			if (ptrl1||div)
			{
				ptrresult->next = new ListNode;
				ptrresult = ptrresult->next;
			}
		}
		while (ptrl2 && !ptrl1)
		{
			ptrresult->val = (ptrl2->val + div) % 10;
			div = (ptrl2->val + div) / 10;
			ptrl2 = ptrl2->next;
			if (ptrl2||div)
			{
				ptrresult->next = new ListNode;
				ptrresult = ptrresult->next;
			}
		}
		if (div)
			ptrresult->val = div;
		return result;
	}
};
	
	int main()
	{
		ListNode* A, *B, *ptrA, * ptrB;
		A = new ListNode;
		B = new ListNode;
		ptrA = A;
		ptrB = B;
		cout << "Enter the length of A and B:";
		int lA, lB;
		cin >> lA >> lB;
		cout << endl<<"enter A:";

		for (int i = 0; i < lA; i++)
		{
			cin >> ptrA->val;
			if (i < lA - 1)
			{
				ptrA->next = new ListNode;
				ptrA = ptrA->next;
			}
		}
		cout << endl << "enter B:";
		for (int i = 0; i < lB; i++)
		{
			cin >> ptrB->val;
			if (i < lB - 1)
			{
				ptrB->next = new ListNode;
				ptrB = ptrB->next;
			}
		}


		Solution Test;
		ListNode *result = Test.addTwoNumbers(A, B);
		cout <<endl<< "result";
		while (result)
		{
			cout << result->val << " ";
			result = result->next;
		}

		return 0;
	}
