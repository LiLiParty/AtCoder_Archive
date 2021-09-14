#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    int N;
    cin >> N;

    vector<ll> AB(N);
    ll X=0;

    for(int i=0; i<N; i++){
        ll a,b;
        cin >> a >> b;
        X -= a;
        AB.at(i) = a+a+b;
    }


    sort(AB.begin(), AB.end());
    ll ans = 0;
    while(X <= 0){
        X += AB.back();
        AB.pop_back();
        ans++;
    }

    cout << ans << endl;


}
