#include <bits/stdc++.h>
using namespace std;
#define ll long long

//  Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *mergeNodes(ListNode *head)
  {
    ListNode *newHead = new ListNode(0);
    ListNode *curr = newHead;
    int sum = 0;
    head = head->next; // first element is 0

    while (head != NULL)
    {
      if (head->val == 0)
      {
        curr->next = new ListNode(sum);
        curr = curr->next;
        sum = 0;
      }
      sum += head->val;
      head = head->next;
    }

    return newHead->next;
  }
};

int main()
{
  ListNode *l1 = new ListNode(0);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(0);
  ListNode *l4 = new ListNode(4);
  ListNode *l5 = new ListNode(0);
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;
  l5->next = nullptr;
  return 0;
}
