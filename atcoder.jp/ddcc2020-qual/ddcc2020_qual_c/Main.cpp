#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9+7

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
    int H,W,K;
    cin >> H >> W >> K;
    vector<string> S(H);
    vector<vector<int>> num(H,vector<int>(W,-1));

    vector<bool> line(H,false);
    for(int i=0; i<H; i++){
        cin >> S.at(i);
        for(int j=0; j<W; j++){
            if(S.at(i).at(j) == '#') line.at(i) = true;
        }
    }

    ll number=1;
    for(int i=0; i<H; i++){
        if(line.at(i)){//いちごあり
            ll count=0;
            for(int k=0; k<W; k++){
                if(S.at(i).at(k) == '#') count++;
                if(S.at(i).at(k) == '#' && count>1) number++;
                num.at(i).at(k) = number;
            }
            for(int k=i+1; k<H; k++){
                if(line.at(k)) break;
                num.at(k) = num.at(i);

            }
            for(int k=i-1; k>=0; k--){
                if(line.at(k)) break;
                num.at(k) = num.at(i);
            }
            number++;
        }
    }


    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << num.at(i).at(j) << " ";
        }
        cout << endl;
    }
}