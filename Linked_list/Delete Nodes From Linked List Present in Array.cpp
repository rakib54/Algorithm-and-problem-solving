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
  ListNode *modifiedList(vector<int> &nums, ListNode *head)
  {
    unordered_set<int> set;

    for (int num : nums)
    {
      set.insert(num);
    }

    while (head && set.count(head->val))
    {
      head = head->next;
    }

    ListNode *tmp = head;

    while (tmp && tmp->next)
    {

      while (tmp->next && set.count(tmp->next->val))
      {
        tmp->next = tmp->next->next;
      }

      tmp = tmp->next;
    }

    return head;
  }
};

int main()
{

  return 0;
}
