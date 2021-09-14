#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf

ll nCr(ll n, ll r){
     __int128 ans = 1;
    for (ll i = n; i > n - r; --i) {
        ans = ans*i;
    }
    ll bunsi=1;
    for (ll i = 1 ; i < r + 1; ++i) {
        bunsi *= i;
    }
    ans = ans/bunsi;
    return ans;
}

int main(){
    ll L;
    cin >> L;
    cout << nCr(L-1,11) << endl;
}
