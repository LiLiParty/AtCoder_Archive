#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807

int main() {
    int H,W;
    cin >> H >> W;

    vector<string> field(H);
    for(int i=0; i<H; i++){
        cin >> field.at(i);
    }

    
    vector<int> dh = {0,1,0,1};
    vector<int> dw = {0,0,1,1};

    int result=0;

    for(int i=0; i<H-1; i++){
        for(int j=0; j<W-1; j++){
            int count=0;
            for(int k=0; k<4; k++){
                if( field.at(i+dh.at(k)).at(j+dw.at(k)) == '#' ) count ++;
            }
            if(count == 1 || count == 3) result++;
            //cout << count <<endl;
        }
        
    }

    cout << result << endl;

}