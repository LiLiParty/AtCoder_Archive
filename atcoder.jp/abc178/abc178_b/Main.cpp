#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807



int main(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll ans= -1*INF64;
    ans = max(ans,a*c );
    ans = max(ans,a*d );
    ans = max(ans,b*c );
    ans = max(ans,b*d );
    cout << ans << endl;
}
