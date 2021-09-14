#include <bits/stdc++.h>
using namespace std;


int main(){
    int P,Q,R;
    cin >> P >> Q >> R;
    int minans=301;
    minans = min(minans,P+Q);
    minans = min(minans,P+R);
    minans = min(minans,R+Q);
    cout << minans;
}

