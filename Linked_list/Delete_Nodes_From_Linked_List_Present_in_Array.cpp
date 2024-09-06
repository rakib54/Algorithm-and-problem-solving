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
    unordered_set<int> st;

    for (int num : nums)
    {
      st.insert(num);
    }

    ListNode *tmp = head;

    while (tmp != NULL)
    {
      if (st.count(tmp->val))
      {
        ListNode *curr = tmp;
        tmp = curr->next;
        delete (curr); // delete the hanging node
      }
      else
      {
        break;
      }
    }

    ListNode *newHead = tmp;

    while (tmp != NULL && tmp->next != NULL)
    {
      if (st.count(tmp->next->val))
      {
        tmp->next = tmp->next->next;
      }
      else
      {
        tmp = tmp->next;
      }
    }

    return newHead;
  }
};

int main()
{
  Solution s;
  ListNode *head = new ListNode(1);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(9);
  head->next = node1;
  node1->next = node2;

  vector<int> nums{1};
  ListNode *node = s.modifiedList(nums, head);
  while (node)
  {
    cout << node->val << "->";
    if (node->next == NULL)
    {
      cout << "NULL";
    }
    node = node->next;
  }
  return 0;
}
