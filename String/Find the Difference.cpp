#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  char findTheDifference(string s, string t)
  {
    unordered_map<char, int> mp;
    for (int i = 0; i < t.size(); i++)
    {
      mp[t[i]]++;
    }

    for (int i = 0; i < s.size(); i++)
    {
      if (mp.find(s[i]) != mp.end())
      {
        mp[s[i]]--;
        if (mp[s[i]] == 0)
        {
          mp.erase(s[i]);
        }
      }
    }

    return mp.begin()->first;
  }
};

int main()
{
  Solution s;
  s.findTheDifference("abcd", "abcde");

  return 0;
}
/*
approach 2 --> sum the char
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;

        for(auto &ch: t){
            sum += ch;
        }

        for(auto &ch: s){
            sum -= ch;
        }

        return char(sum);

    }
};


approach 3 --->  XOR

same char xor value is 0;
a^a = 0;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int Xor = 0;

        for(auto &ch: t){
            Xor ^=  ch;
        }
        for(auto &ch: s){
            Xor ^=  ch;
        }

        return (char)Xor;
    }
};
*/
