#include <bits/stdc++.h>
using namespace std;



int main() {
    int yen;
    cin >> yen;
    yen = 1000-yen;

    int ans=0;
    
    while(yen>=500){
        yen -= 500;
        ans++;
    }
    
    while(yen>=100){
        yen -= 100;
        ans++;
    }

    while(yen>=50){
        yen -= 50;
        ans++;
    }

    while(yen>=10){
        yen -= 10;
        ans++;
    }

    while(yen>=5){
        yen -= 5;
        ans++;
    }

    while(yen>0){
        yen -= 1;
        ans++;
    }



    cout << ans << endl;
}

