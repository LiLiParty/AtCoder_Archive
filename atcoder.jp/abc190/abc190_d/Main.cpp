#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807

/*  divisor(n)
    入力：整数 n
    出力：nのすべての約数
    計算量：O(√n)
*/
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main() {
    ll N;
    cin >> N;

    vector<ll> div = divisor(2*N);

    ll ans=0;
    for(ll d: div){
        if( (2*N/d)%2 == 0 && d%2==1 ){
            ans++;
        }else if( (2*N/d)%2 == 1 && d%2==0 ){
            ans ++;
        }
    }

    cout << ans << endl;
}