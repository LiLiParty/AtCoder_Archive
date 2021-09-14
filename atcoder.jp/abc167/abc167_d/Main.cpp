#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7



int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> G(N+1);
    for(ll i=1; i<=N; i++){
        cin >> G.at(i);
    }
    vector<ll> seen(N+1,-1);

    ll next = 1;
    seen.at(1) = 1;
    ll cycle;//サイクルの大きさ
    ll cycle_out;//サイクル外の大きさ
    ll start;//サイクルが始まる数
    ll N_size=1;
    while(true){
        ll now = next;
        next = G.at(next);
        if(seen.at(next) != -1){
            start = seen.at(next);
            cycle = seen.at(now) - seen.at(next) + 1;
            cycle_out = N_size-cycle;
            break;
        }else{
            seen.at(next) = 1 + seen.at(now);
            N_size++;
        }
    }

    ll ans;
    if( cycle_out >= K){
        ans = K+1;
    }else{
        ans = start+(K-cycle_out)%cycle;
    }

    for(int i=1; i<=N; i++){
        if(seen.at(i) == ans){
            cout << i << endl;
            break;
        }
    }
    
    //cout <<"cycle_out :" << cycle_out << " cycle: " << cycle << " start: " << start;
    
}
