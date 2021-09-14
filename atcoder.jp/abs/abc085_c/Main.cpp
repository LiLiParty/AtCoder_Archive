#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,Y;
    cin >> N >> Y;
    for(int i=N; i>=0; i--){
        if(i*10000 > Y) continue;
        for(int j=N-i; j>=0; j--){
            if(i*10000+j*5000 > Y) continue;
            if(i*10000 + j*5000 + (N-i-j)*1000 == Y){
                cout << i << " " << j << " " << N-i-j << endl;
                return(0);
            }
        }
    }

    cout << "-1 -1 -1" << endl;
}
