#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define pp pair<ll,ll>
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
constexpr int inf=1000001000;
constexpr ll INF=2e18;
constexpr ll MOD=1000000007;
constexpr ll mod=998244353;
int dx[9]={1,-1,0,0},dy[9]={0,0,1,-1};
 
#include <atcoder/all>
typedef atcoder::modint1000000007 mint;
// typedef atcoder::modint998244353 mint;
 
int main() {
    int n,m;
    cin >> n >> m;
    n*=2;
    vector<pair<int,int>> a(n);
    rep(i,n) a[i]=mk(0,n-i-1);
    vector<vector<char>> b(n,vector<char>(m));
    rep(i,n){
        rep(j,m) cin >> b[i][j];
    }
    reverse(all(b));
    sort(all(a));
    reverse(all(a));
    rep(i,m){
        rep(j,n/2){
            // cout << b[a[j*2].second][i] << " " << b[a[j*2+1].second][i] << endl;
            char t=b[a[j*2].second][i],tt=b[a[j*2+1].second][i];
            if ((t=='G' && tt=='C') || (t=='C' && tt=='P') || (t=='P' && tt=='G')) a[j*2].first++;
            else if ((tt=='G' && t=='C') || (tt=='C' && t=='P') || (tt=='P' && t=='G')) a[j*2+1].first++;
        }
        sort(all(a));
        reverse(all(a));
    }
    rep(i,n){
        cout << n-a[i].second << endl;
    }
}