#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7



int main(){
    int H,W,K;
    cin >> H >> W >> K;
    vector<string> field(H);
    for(int i=0; i<H; i++){
        cin >> field.at(i);
    }

    int ans=0;

    for(int h=0; h < (1<<H); h++){
        for(int w=0; w < (1<<W); w++){
            int count = 0;
            for(int i=0; i<H; i++){
                for(int j=0; j<W; j++){
                    if( h&(1<<i) && w&(1<<j) ){
                        if(field.at(i).at(j) == '#') count++; 
                    }
                }
            }
            if(count==K) ans++;
        }
    }

    cout << ans << endl;
}
