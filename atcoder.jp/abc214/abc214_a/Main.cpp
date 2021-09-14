#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>G;
vector<int>ans;

void dfs(int crr,int pre){
    cout << crr << " ";
    for(int nxt:G[crr]){
        if(nxt!=pre){
            dfs(nxt,crr);
            cout << crr << " ";
        }
    }
}

int main(){
    int N;
    cin >> N;
    if(N<=125){
        cout << 4 << endl;
    }else if(N<=211){
        cout << 6 << endl;
    }else{
        cout << 8 << endl;
    }

}