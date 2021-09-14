#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7

int sum=0;

void dfs(int i,vector<vector<int>> &G, vector<int> &seen){
    //cout << i << endl;
    //cout << seen.at(i) << "~";
    seen.at(i) = 1;
    //cout << seen.at(i) << endl;
    sum++;

    for(int g: G.at(i)){
        //cout << seen.at(g) << endl;
        if(seen.at(g)==-1){
            dfs(g,G,seen);
        }else{
            continue;
        }
    }

}





int main(){

    int N,M;
    cin >> N >> M;

    vector<int> seen(N+1,-1);
    vector<vector<int>> G(N+1);

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    int ans=0;
    for(int i=1; i<=N; i++){
        if(seen.at(i)==-1){
            //cout << i << endl;
            dfs(i,G,seen);
            ans = max(sum,ans);
            sum=0;
        }else{
            continue;
        }
    }
    cout << ans << endl;
}
