#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807

int main() {
    int V,T,S,D;
    cin >> V >> T >> S >> D;
    if(V*T <= D && V*S >=D){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}