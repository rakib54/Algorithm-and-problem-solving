#include <bits/stdc++.h>
using namespace std;
#define ll long long

class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()){
            return false;
        }
        v.push_back(val);
        mp[val] = v.size()-1;

        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            return false;
        }
        int idx = mp[val];  // idx to remove
        int lastElement = v.back(); // store last element
        v.back() = val;  
        v[idx] = lastElement; //replace last ele with removal ele
        mp[lastElement] = idx;  // insert in map with updated idx
        v.pop_back(); //remove last ele
        mp.erase(val); 
        return true;
    }
    
    int getRandom() {
        int randomIdx = rand() % v.size();
        return v[randomIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
  
  return 0;
}
