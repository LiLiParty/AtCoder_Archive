#include <bits/stdc++.h>
using namespace std;

int main() {
    int X;
    cin >> X;
    int ans=0;
    while(true){
        if(X%100==0 && ans!=0){
            break;
        }else{
            X++;
            ans++;
        }
    }
    cout << ans << endl;
}