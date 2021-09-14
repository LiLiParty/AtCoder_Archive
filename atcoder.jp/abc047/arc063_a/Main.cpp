#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7



int main(){
    string S;
    cin >> S;
    char a = 'X';
    ll ans = 0;
    for(int i=0; i<S.size(); i++){
        if(a!=S.at(i)) ans++;
        a = S.at(i);
    }

    cout << ans-1 << endl;
}
