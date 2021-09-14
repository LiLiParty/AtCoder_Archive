#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++){
        cin >> A.at(i);
    }
    

    ll ans = 0;
    for(int l=0;l<N; l++){
        ll x = A.at(l);
        for(int r=l; r<N; r++){
            x = min( A.at(r), x);
            ans = max(ans,x*(r-l+1));
        }
    }

    cout << ans << endl;



}
