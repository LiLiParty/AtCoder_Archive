#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7



int main(){
    
    ll x;
    cin >> x;
    if(x%11 > 6){
        cout << x/11*2 + 2 << endl;
    }else if(x % 11 == 0){
        cout << x/11*2 << endl;
    }else{
        cout << x/11*2 + 1 << endl;
    }
}
