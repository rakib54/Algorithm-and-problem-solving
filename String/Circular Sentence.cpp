#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool isCircularSentence(string sentence)
  {
    int n = sentence.size();

    for (int i = 0; i < n; i++)
    {
      if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
      {
        return false;
      }
    }

    return sentence[0] == sentence[sentence.size() - 1];
  }
};

class Solution2
{
public:
  bool isCircularSentence(string sentence)
  {
    vector<string> v;
    stringstream ss(sentence);
    string word;
    while (ss >> word)
    {
      v.push_back(word);
    }
    int n = v.size();
    char firstChar = v[0][0];
    string lastWord = v[n - 1];
    char lastChar = lastWord[lastWord.size() - 1];

    bool isEqual = true;

    for (int i = 0; i < n - 1; i++)
    {
      string first = v[i];
      string next = v[i + 1];

      if (first[first.size() - 1] != next[0])
      {
        isEqual = false;
      }
    }

    if (!isEqual)
    {
      return false;
    }

    return firstChar == lastChar;
  }
};

int main()
{
  Solution2 solution;
  string sentence = "leetcode exercises sound delightful";
  solution.isCircularSentence(sentence);

  return 0;
}
