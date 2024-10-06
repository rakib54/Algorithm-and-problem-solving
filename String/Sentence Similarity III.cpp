#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool areSentencesSimilar(string s1, string s2)
  {
    if (s1.size() < s2.size())
    {
      swap(s1, s2);
    }

    vector<string> v1, v2;

    stringstream ss1(s1), ss2(s2);
    string word;

    while (ss1 >> word)
    {
      v1.push_back(word);
    }
    while (ss2 >> word)
    {
      v2.push_back(word);
    }

    int i = 0, j = v1.size() - 1;
    int k = 0, l = v2.size() - 1;

    while (i < v1.size() && k < v2.size() && v1[i] == v2[k])
    {
      i++;
      k++;
    }
    while (l >= k && v1[j] == v2[l])
    {
      j--;
      l--;
    }

    return l < k;
  }
};

class Solution2
{
public:
  bool areSentencesSimilar(string s1, string s2)
  {
    if (s1.size() < s2.size())
    {
      swap(s1, s2);
    }

    deque<string> deq1, deq2;

    stringstream ss1(s1), ss2(s2);
    string word;

    while (ss1 >> word)
    {
      deq1.push_back(word);
    }
    while (ss2 >> word)
    {
      deq2.push_back(word);
    }

    while (!deq1.empty() && !deq2.empty() && deq1.front() == deq2.front())
    {
      deq1.pop_front();
      deq2.pop_front();
    }

    while (!deq1.empty() && !deq2.empty() && deq1.back() == deq2.back())
    {
      deq1.pop_back();
      deq2.pop_back();
    }

    return deq2.empty();
  }
};

int main()
{
  Solution2 s;
  string s1 = "My name is Haley", s2 = "My name";

  s.areSentencesSimilar(s1, s2);
  return 0;
}
