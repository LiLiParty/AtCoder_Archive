#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807

int main() {
    int N,S,D;
    cin >> N >> S >> D; 
    bool ans=false;
    for(int i=0; i<N; i++){
        int x,y;
        cin >> x >> y;
        if(S>x && D<y) ans = true;
    }

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    } 
}