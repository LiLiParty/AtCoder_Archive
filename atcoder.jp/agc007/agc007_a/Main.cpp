#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9+7

vector<int> dh = {0,1};
vector<int> dw = {1,0};
int H,W;

void dfs(int h, int w, vector<string> &A, vector<vector<int>> &seen ){
    seen.at(h).at(w) = 1;

    for(int i=0; i<2; i++){
        if( h+dh[i] < 0 || h+dh[i] >= H || w+dw[i] <0 || w+dw[i] >= W) continue;
        if( A.at(h+dh[i]).at(w+dw[i]) == '#' ){
            dfs(h+dh[i],w+dw[i],A,seen);
            break;
        } 
    }
}


int main(){
    cin >> H >> W;

    vector<string> A(H);
    for(int i=0; i<H; i++){
        cin >> A.at(i);
    }

    vector<vector<int>> seen(H,vector<int>(W,-1));

    dfs(0,0,A,seen);

    bool ans = true;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(A.at(i).at(j) == '#' && seen.at(i).at(j) == -1){
                ans = false;
            }
        }
    }

    if(ans){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }

}