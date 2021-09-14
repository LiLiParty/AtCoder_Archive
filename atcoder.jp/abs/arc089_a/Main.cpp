#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int tb=0;
    int xb=0;
    int yb=0;
    int ta,xa,ya;
    cin >> ta >> xa >> ya;

    for(int i=0; i<N; i++){
        
        int d = abs(xa-xb) + abs(ya-yb);
        if( (ta-tb)%2 == 0 ){ //時間差が偶数の時
            if( d<=(ta-tb) and d%2==0 ){
                tb = ta;
                xb = xa;
                yb = ya;
                cin >> ta >> xa >> ya; 
                continue;
            }else{
                cout << "No" << endl;
                return(0);
            }
        }else{ //奇数の時
            if( d<=(ta-tb) and d%2==1 ){
                tb = ta;
                xb = xa;
                yb = ya;
                cin >> ta >> xa >> ya; 
                continue;
            }else{
                cout << "No" << endl;
                return(0);
            }
        }
    }
    cout << "Yes" << endl;
}
