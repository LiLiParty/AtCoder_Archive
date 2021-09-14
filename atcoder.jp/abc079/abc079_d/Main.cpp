#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod   = 1000000007;//10^9+7
//const ll mod_1 = 998244353;

//素因数分解 ex:{{2, 2}, {5, 1}, {101, 1}}
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数
        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        // その結果を push
        res.push_back({a, ex});
    }
    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}
//組み合わせ：nCr
ll Comb(ll n, ll r){
        ll num = 1;
        for(ll i = 1; i <= r; i++){
            num = num * (n - i + 1) / i;
        }
        return num;
    }
//約数全列挙(昇順)//計算量：O(√n)
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




int main(){
    ll H,W;
    cin >> H >> W;
    vector<vector<ll>> weight(10,vector<ll>(10));
    vector<vector<ll>> G(10);
    for(int i=0; i<=9; i++){
        for(int j=0; j<=9; j++){
            ll c;
            cin >> c;
            weight.at(i).at(j) = c;
            G.at(i).push_back(j);
        }
    }

    vector<vector<ll>> dist(10,vector<ll>(10,INF64));//始点、終点
    for(int i=0; i<=9; i++){
        dist[i][i] = 0;
        priority_queue<pair<ll,ll>> pq; //距離、番号
        pq.push( make_pair(0,i) );
        while(!pq.empty()){
            pair<ll,ll> p= pq.top();
            pq.pop();
            ll v = p.second;
            ll d = p.first;
            if(dist[i][v] < d) continue;

            for(ll nv: G.at(v)){
                if( dist[i][nv] > weight[v][nv] + d){
                    dist[i][nv] = weight[v][nv] + d;
                    pq.push(make_pair(dist[i][nv], nv));
                }
            }
        }
    }
    ll ans = 0;
    for(ll i=0; i<H; i++){
        for(ll j=0; j<W; j++){
            ll a;
            cin >> a;
            if(a==-1 || a==1) continue;
            ans += dist[a][1];
        }   
    }

    cout << ans << endl;


}