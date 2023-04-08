#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void dfs(Node *curr, Node *node, vector<Node *>&visited){
  visited[node->val] = node;

  for(auto ele: curr->neighbors){
      if(visited[ele->val] == NULL){
          Node *newNode = new Node(ele->val);
          
          (node->neighbors).push_back(newNode);
          dfs(ele,newNode,visited);
      }
      else {
          (node->neighbors).push_back(visited[ele->val]); 
      }
  }
}

Node* cloneGraph(Node* node) {
  if(node == NULL) return NULL;
  Node *clone = new Node(node->val);
  vector<Node *>visited(1000,NULL);

  dfs(node,clone,visited);

  return clone;
}

void solve(){
  

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}




