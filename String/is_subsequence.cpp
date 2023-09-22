#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool isSubsequence(string s, string t)
  {
    map<char, vector<int>> mp;

    for (int i = 0; i < t.size(); i++)
    {
      mp[t[i]].push_back(i);
    }

    int prev = -1;

    for (int i = 0; i < s.size(); i++)
    {
      char ch = s[i];

      if (mp.find(ch) == mp.end())
      {
        return false;
      }
      vector<int> indices = mp[ch];

      auto it = upper_bound(begin(indices), end(indices), prev); // it will return greater than prev element bound;

      if (it == indices.end())
      { // not found in indices
        return false;
      }

      prev = *it; // index
    }

    return true;
  }
};

int main()
{
  Solution solution;
  string s = "abc";
  string t = "ahbgdc";
  cout << solution.isSubsequence(s, t);
  return 0;
}

/**
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m  = t.size();
        int j = 0;

        for(int i=0; i<m;i++){
            if(t[i] == s[j]){
                j++;
            }
        }

        return j == n;
    }
};
**/
