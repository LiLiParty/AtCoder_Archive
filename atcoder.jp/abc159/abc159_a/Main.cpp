#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;
    int ans=0;
    if(N>=1){
        ans += N*(N-1)/2;
    }
    if(M>=1){
        ans += M*(M-1)/2;
    }
    cout << ans;
}