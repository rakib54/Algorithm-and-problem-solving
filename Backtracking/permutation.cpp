#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>ans;

bool solution_found(int id,vector<int>state){
  if(id == n){
    return true;
  }
  else return false;
}

vector<int>getCandidates(vector<int>state){
  map<int,int>taken;
  for(int i: state){
    taken[i] = 1;
  }
  vector<int>candidates;
  for(int i=1;i<=n;i++){
    if(taken.count(i) == 0){
      candidates.push_back(i);
    }
  }
  return candidates;
}

void backTrack(int id,vector<int>state){
  // base case handling
  if(solution_found(id,state)){ 
    ans.push_back(state);
    return;
  }
  // loop over the candidates
  vector<int>candidates = getCandidates(state);

  for(int candidate: candidates){
    state[id] = candidate; // add candidate to state
    backTrack(id + 1, state); // backtrack (id+1,state)
    state[id] = 0; // remove candidate from state
  }

}


int main(){
  cin>>n;
  vector<int>initial_state(n);
  backTrack(0, initial_state);
  
  for(vector<int>permutation : ans){
    for(int i:permutation){
      cout<<i<<" "; 
    }
    cout<<endl;
  }

  return 0;
}