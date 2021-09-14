#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9+7




int main(){
    string S;
    cin >> S;
    ll an=0;
    ll bn=0;
    ll cn=0;
    ll N = S.size();
    for(int i=0; i<N; i++){
        if(S.at(i) == 'a' ) an++;
        if(S.at(i) == 'b' ) bn++;
        if(S.at(i) == 'c' ) cn++;
    }
    bool ans;

    if( abs(an-bn)<=1 && abs(an-cn)<=1 && abs(bn-cn)<=1 ){
        ans = true;
    }else{
        ans = false;
    }

    if(ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
}