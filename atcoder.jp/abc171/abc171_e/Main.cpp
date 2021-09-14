#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7

ll divisor_num(ll a){ //aの約数の個数,O(√a)
    ll ans = 1;
    for (ll i = 2; i <= sqrt(a); i++) {
        ll cnt = 0;
        while (a % i == 0) {
            cnt++;
            a /= i;
        }
        ans *= (cnt + 1);
        if (a == 1) break;
    }
    if (a != 1) ans *= 2;
    return ans;
}


int main(){
    ll N;
    cin >> N;
    vector<ll>  a(N);
    ll B=0;
    for(ll i=0; i<N; i++){
        cin >> a.at(i);
        B ^= a.at(i);
    }
    for(ll i=0; i<N; i++){
        cout << (B^a.at(i)) << " ";
    }
    
}

