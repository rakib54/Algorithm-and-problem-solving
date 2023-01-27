#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>wt,vector<int>val,int bag_wt,int n){
    //base case
    if(bag_wt  == 0 || n == 0){
        return 0;
    }

    // choices
    if(wt[n-1] <= bag_wt){ // if bag has space
        int nibo = val[n-1] + knapsack(wt,val,bag_wt-wt[n-1],n-1);
        int nibo_na = knapsack(wt,val,bag_wt,n-1);
        return max(nibo,nibo_na);
    }
    else {
        return knapsack(wt,val,bag_wt,n-1);
    }
}

int main(){
    vector<int>wt{1,3,4,5};
    vector<int>val{10,4,2,3};
    int bag_wt = 10;

    cout<<knapsack(wt,val,bag_wt,4);

    return 0;
}
