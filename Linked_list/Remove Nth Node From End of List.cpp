#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *tmp = head;
    int totalNode = 0;

    while (tmp != NULL)
    {
      tmp = tmp->next;
      totalNode++;
    }
    int deleteNodeidx = totalNode - n;
    tmp = head;
    while (tmp != NULL && deleteNodeidx > 1)
    {
      tmp = tmp->next;
      deleteNodeidx--;
    }
    if (deleteNodeidx == 0)
    { // deleteNodeidx == 0 means head node need to deleted
      return head->next;
    }
    if (tmp->next->next)
    {
      tmp->next = tmp->next->next;
    }
    else
    {
      tmp->next = NULL;
    }

    return head;
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(4);
  ListNode *l5 = new ListNode(5);

  Solution s;
  s.removeNthFromEnd(head, 4);
}
