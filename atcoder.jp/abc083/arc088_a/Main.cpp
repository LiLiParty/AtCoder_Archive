#include <bits/stdc++.h>
using namespace std;



int main() {
    long long X,Y;
    cin >> X >> Y;

    long long ans=1;
    long long X_next=X;
    while(true){
        if(X_next*2 <=Y){
            ans++;
            X_next *= 2;
        }else{
            break;
        }
    }
    
    cout << ans << endl;


}

