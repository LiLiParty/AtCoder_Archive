#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N;
    cin >> N;

    vector<ll> A;
    for(int i=0; i<N; i++){
        ll a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    if(A.at(0)==0){
        cout << 0 << endl;
        return 0;
    }

    ll ans=1;
    for(int i=0; i<N; i++){
        if(A.at(i) > 1000000000000000000/ans){
            cout << -1 << endl;
            return 0;
        }
        ans *= A.at(i);
    }

    cout << ans << endl;

}
