#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<long long int>a(N);
    for(int i=0; i<N; i++){
        cin >> a.at(i);
    }
    ll ans=0;
    ll sum=0;
    int j=0; //ｊは後端
    for(int i=0; i<N; i++){
        while(sum < K){
            if(j==N) break;
            sum += a.at(j);
            j++;
        }
        if(sum<K) break;
        ans += N-j+1;
        sum -= a.at(i);
    }
    cout << ans;
}