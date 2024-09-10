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
    int GCD(int a, int b)
    {
        int result = min(a, b);

        while (result > 0)
        {
            if (a % result == 0 && b % result == 0)
            {
                break;
            }
            result--;
        }

        return result;
    }
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *tmp = head;

        while (tmp != NULL && tmp->next != NULL)
        {
            int a = tmp->val;
            int b = tmp->next->val;

            int gcd = GCD(a, b);

            ListNode *newNode = new ListNode(gcd); // 2
            // 6 10
            newNode->next = tmp->next; // 2->10
            tmp->next = newNode;       // 6->2
            tmp = tmp->next->next;     // 10 = next node
        }

        return head;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(18);
    ListNode *l2 = new ListNode(6);
    ListNode *l3 = new ListNode(10);
    ListNode *l4 = new ListNode(3);
    head->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l2;

    s.insertGreatestCommonDivisors(head);

    return 0;
}
