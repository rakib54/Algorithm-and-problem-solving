#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string getRoot(string &word, unordered_set<string> &st)
  {
    for (int i = 1; i < word.size(); i++)
    {
      string s = word.substr(0, i);
      if (st.find(s) != st.end())
      {
        return s;
      }
    }
    return word;
  }
  string replaceWords(vector<string> &dictionary, string sentence)
  {
    unordered_set<string> st(begin(dictionary), end(dictionary));

    stringstream ss(sentence);
    string word;
    string result;

    while (getline(ss, word, ' '))
    {
      result += getRoot(word, st);
      result += " ";
    }
    result.pop_back();
    return result;
  }
};

int main()
{
  Solution solution;
  vector<string> dictionary{};
  string sentence = "the cattle was rattled by the battery";
  solution.replaceWords(dictionary, sentence);
  return 0;
}
