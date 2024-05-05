#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  void deleteNode(ListNode *node)
  {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};

int main()
{

  return 0;
}

// question link: https://leetcode.com/problems/delete-node-in-a-linked-list/