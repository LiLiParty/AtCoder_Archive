#include <bits/stdc++.h>
using namespace std;


int main(){
    int A,P;
    cin >> A >> P;
    int kakera=0;
    kakera += A*3;
    kakera += P;
	if(kakera<2){
      cout << 0;
    }else if(kakera%2==0){
    cout << kakera/2;
    }else if(kakera%2==1){
      cout << kakera/2;
    }
}
