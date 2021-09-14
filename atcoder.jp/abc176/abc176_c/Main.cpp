#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7






int main(){
    ll N;
    cin >> N;
    
    vector<ll> A(N);
    for(ll i=0; i<N; i++){
        cin >> A.at(i);
    }

    ll ans=0;
    for(ll i=1; i<N; i++){
        if(A.at(i-1) > A.at(i)){
            ans += A.at(i-1) - A.at(i);
            A.at(i) = A.at(i-1);
        }else{
            continue;
        }
    }

    cout << ans << endl;

}
