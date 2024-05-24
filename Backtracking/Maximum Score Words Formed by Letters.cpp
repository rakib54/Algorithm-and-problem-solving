#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int maxScore;
  int n;

  void solve(int i, vector<string> &words, int currScore, vector<int> &score, vector<int> &freq)
  {
    maxScore = max(maxScore, currScore);

    if (i >= n)
    {
      return;
    }

    // check if we able to take it
    int j = 0;
    vector<int> tempFreq = freq;
    int tempScore = 0;
    while (j < words[i].size())
    {
      char ch = words[i][j];
      tempFreq[ch - 'a']--;

      tempScore += score[ch - 'a'];

      if (tempFreq[ch - 'a'] < 0)
      {
        break;
      }
      j++;
    }

    if (j == words[i].size())
    { // now we able to take it
      solve(i + 1, words, currScore + tempScore, score, tempFreq);
    }

    // not take
    solve(i + 1, words, currScore, score, freq);
  }

  int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
  {
    n = words.size();
    maxScore = INT_MIN;

    vector<int> freq(26, 0);

    for (char &ch : letters)
    {
      freq[ch - 'a']++;
    }

    solve(0, words, 0, score, freq);

    return maxScore;
  }
};

int main()
{
  Solution s;
  vector<string> words{"dog", "cat", "dad", "good"};
  vector<char> letters{'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
  vector<int> score{1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  s.maxScoreWords(words, letters, score);
  return 0;
}
