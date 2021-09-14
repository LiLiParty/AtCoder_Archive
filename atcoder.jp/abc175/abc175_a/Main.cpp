#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7



int main(){
    string S;
    cin >> S;
    int rain=0;
    for(int i=0; i<3; i++){
        if(S.at(i)=='R') rain++; 
    }
    if(rain==0){
        cout << 0 << endl;
    }else if(rain == 1){
        cout << 1 << endl;
    }else if(rain == 2 && S=="RSR"){
        cout << 1 << endl;
    }else if(rain == 2){
        cout << 2 << endl;
    }else{
        cout << 3 << endl;
    }
}
