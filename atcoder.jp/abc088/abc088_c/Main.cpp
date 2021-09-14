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
    vector< vector<int> > C(4,vector<int>(4));
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cin >> C.at(i).at(j);
        }
    }

    bool ans = true;
    if(C[1][1]-C[1][2]!=C[2][1]-C[2][2] || C[1][1]-C[1][2]!=C[3][1]-C[3][2] ) ans = false;
    if(C[1][2]-C[1][3]!=C[2][2]-C[2][3] || C[1][2]-C[1][3]!=C[3][2]-C[3][3] ) ans = false;

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

