#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;

int main(){
    string S,T;
    cin >> S >> T;
    int ans=10000;
    for(int i=0; i<=S.size()-T.size(); i++){
        int count=0;
        for(int k=0; k<T.size(); k++){
            if( S.at(i+k) != T.at(k) ){
                count++;
            } 
        }
        ans = min(ans,count);
    }
    
    cout << ans << endl;
}
