#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MOD = 1000000007;

int main(){
    ll N,K;
    cin >> N >> K;
    if(N>K){
        ll a=N/K;
        ll ans1 = min( abs(N-(K*a)), abs(N-(K*(a+1))) );
        cout << min(N,ans1);
    }else if(N<K){
        cout << min(N,abs(N-K));
    }else if(N==K){
        cout << 0;
    }
}