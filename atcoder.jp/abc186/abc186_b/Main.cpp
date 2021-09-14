#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    int H,W;
    cin >> H >> W;
    vector<int > A(H*W);
    int amin=10000;
    for(int i=0; i<H*W; i++){
        cin >> A.at(i);
        amin = min(amin,A.at(i));
    }
    int ans=0;
    for(int i=0; i<H*W; i++){
        ans += A.at(i) - amin;
    }

    cout << ans << endl;
}
