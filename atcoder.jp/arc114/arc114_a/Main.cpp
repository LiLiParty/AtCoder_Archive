#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf

ll gcd(ll x, ll y) {
    if(x < y) swap(x, y); 

    while (y > 0) {
        ll r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> X(N);
    for(ll i=0; i<N; i++){
        cin >> X.at(i);
    }
    vector<ll> sos={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    
    ll ans=1;
    for(ll z:sos){
        ans*=z;
    }
    for(int bit=0; bit<(1<<15); ++bit){
        ll a=1;
        for(int i=0; i<15; i++){
        if (bit & (1<<i)) { // i が bit に入るかどうか
            a *= sos.at(i);
        }
        }

        bool flag=false;
        for(auto x: X){
            if (gcd(x,a) == 1){
                flag = true;
                break;
            }
        }
        if(flag) continue;
        ans = min(a,ans);

    }

    cout << ans << endl;



}
