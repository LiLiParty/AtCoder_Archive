#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7






int main(){
    int N,X,T;
    cin >> N >> X >> T;
    if(N%X==0){
        cout << N/X*T << endl;
    }else{
        cout << (N/X+1)*T << endl;
    }
}
