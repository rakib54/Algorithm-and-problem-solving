#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
  list<int> dll;
  map<int, pair<list<int>::iterator, int>> mp;
  int n;
  LRUCache(int capacity)
  {
    n = capacity;
  }

  void makeRecentUsed(int key)
  {
    dll.erase(mp[key].first);
    dll.push_front(key);

    mp[key].first = dll.begin();
  }

  int get(int key)
  {
    if (mp.find(key) == mp.end())
    {
      return -1;
    }
    makeRecentUsed(key);

    return mp[key].second;
  }

  void put(int key, int value)
  {
    if (mp.find(key) != mp.end())
    {
      mp[key].second = value;
      makeRecentUsed(key);
    }
    else
    {
      dll.push_front(key);
      mp[key] = {dll.begin(), value};
      n--;
    }

    if (n < 0)
    {
      int key_to_be_delete = dll.back();
      mp.erase(key_to_be_delete);
      dll.pop_back();
      n++;
    }
  }
};

int main()
{
  LRUCache mycache(2);
  mycache.put(1, 1);
  mycache.put(2, 2);
  cout << mycache.get(1);
  mycache.put(3, 3);
  cout << mycache.get(2);
  mycache.put(4, 4);
  cout << mycache.get(1);
  cout << mycache.get(3);
  cout << mycache.get(4);

  return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */