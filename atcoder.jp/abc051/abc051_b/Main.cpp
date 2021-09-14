#include <bits/stdc++.h>
using namespace std;

int main(){
    int K,S;
    cin >> K >> S;

    int counter = 0;
    for(int x=0; x<=K; x++){
        for(int y=0; y<=K; y++){
            if(S-x-y <= K and 0<= S-x-y) {
                counter++;
            }
        }
    }

    cout << counter << endl;
    
}
