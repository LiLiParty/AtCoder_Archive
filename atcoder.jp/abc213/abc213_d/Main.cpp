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
    G.resize(N+1);
    for(int i=0;i<N-1;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1;i<=N;i++){
        sort(G[i].begin(), G[i].end());
    }

    dfs(1,-1);
}