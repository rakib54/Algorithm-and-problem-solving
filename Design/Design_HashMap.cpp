#include <bits/stdc++.h>
using namespace std;
#define ll long long

class MyHashMap
{
public:
  vector<int> ans;

  MyHashMap()
  {
    ans.resize(1000001, -1);
  }

  void put(int key, int value)
  {
    ans[key] = value;
  }

  int get(int key)
  {
    return ans[key];
  }

  void remove(int key)
  {
    ans[key] = -1;
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main()
{

  MyHashMap myHashMap;
  myHashMap.put(1, 1); // The map is now [[1,1]]
  myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
  myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
  myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
  myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
  myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
  myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
  myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]

  return 0;
}
