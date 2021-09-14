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
    int X,Y;
    cin >> X >> Y;
    if( Y%2==0 && 2*X<=Y && 4*X>=Y){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

