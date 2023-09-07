#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Definition for singly-linked list.
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
  ListNode *reverseBetween(ListNode *head, int left, int right)
  {
    if (head == NULL || head->next == NULL)
    {
      return head;
    }

    ListNode *dummy = new ListNode(0);

    dummy->next = head;
    ListNode *prev = dummy;

    for (int i = 1; i < left; i++)
    {
      prev = prev->next;
    }
    ListNode *curr = prev->next;

    for (int i = 1; i <= right - left; i++)
    {
      ListNode *tmp = prev->next;
      prev->next = curr->next;
      curr->next = curr->next->next;
      prev->next->next = tmp;
    }

    return dummy->next;
  }
};

int main()
{

  int left = 2, right = 4;
  ListNode *head = new ListNode(1);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(4);
  ListNode *l5 = new ListNode(5);

  head->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;
  l5->next = NULL;

  Solution s;
  s.reverseBetween(head, left, right);

  return 0;
}
