#include <bits/stdc++.h>
using namespace std;

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
  vector<ListNode *> splitListToParts(ListNode *head, int k)
  {
    ListNode *tmp = head;
    int total = 0;

    while (tmp)
    {
      total++;
      tmp = tmp->next;
    }
    vector<ListNode *> ans(k, NULL);

    int eachBucketNodes = total / k;
    int rem = total % k;

    ListNode *curr = head;
    ListNode *prev = NULL;

    for (int i = 0; curr && i < k; i++)
    {
      ans[i] = curr;

      for (int j = 0; j < eachBucketNodes + (rem > 0 ? 1 : 0); j++)
      {
        prev = curr;
        curr = curr->next;
      }
      prev->next = NULL;
      rem--;
    }

    return ans;
  }
};

int main()
{

  ListNode *l1 = new ListNode(1);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(4);
  ListNode *l5 = new ListNode(5);

  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;

  int k = 2;

  Solution s;
  s.splitListToParts(l1, k);

  return 0;
}
