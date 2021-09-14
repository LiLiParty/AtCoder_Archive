#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807

int main() {
    int N,M; //皿N枚、条件M個
    cin >> N >> M;

    vector<pair<int,int>> m(M+1);
    for(int i=1; i<=M; i++){
        int a,b;
        cin >> a >> b;
        m.at(i) = make_pair(a,b);
    }

    int K;
    cin >> K;
    vector<pair<int,int>> k(K+1);
    for(int i=1; i<=K; i++){
        int c,d;
        cin >> c >> d;
        k.at(i) = make_pair(c,d);
    }

    int ans=0;

    for(int bit=0; bit < (1<<K); bit++){
        vector<bool> n(N+1,false);
        int ans_p=0;

        for(int i=0; i<K; i++){
            int put;
            if(bit & (1<<i)){
                put = k.at(i+1).first;
            }else{
                put = k.at(i+1).second;
            }
            n.at(put) = true;
        }

        for(int i=1; i<=M; i++){
            if( n.at(m.at(i).first) && n.at(m.at(i).second) ) ans_p++;
        }

        ans = max(ans,ans_p);
    }

    cout << ans << endl;
}