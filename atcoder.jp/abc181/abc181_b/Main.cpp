#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf


int main(){
    int N;
    cin >> N;

    ll ans=0;
    for(int i=0; i<N; i++){
        ll A,B;
        cin >> A >> B;
        ans += (B-A+1)*(A+B)/2;
    }
    cout << ans << endl;
}
