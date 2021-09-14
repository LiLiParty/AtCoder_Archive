#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N;
    cin >> N;
    
    vector<ll> A(N);
    ll sum=0;
    for(int i=0; i<N; i++){
        cin >> A.at(i);
        sum += A.at(i);
    }
    sort(A.begin(),A.end());
    
    ll ans=0;
    for(int i=0; i<N-1; i++){
        sum -= A.at(i);
        ll minus= (N-i-1)*A.at(i);
        ans += sum-minus;
    }

    cout << ans << endl;
    
}
