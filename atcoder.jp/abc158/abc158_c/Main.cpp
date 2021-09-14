#include <bits/stdc++.h>
using namespace std;


int main(){
    int A,B;
    cin >> A >> B;
    int Atax,Btax;
    int ans=1001;
    for(int i=13;i<1001;i++){
        Atax=int(i*0.08);
        Btax=int(i*0.1);
        if(Atax == A && Btax == B ){
            if(ans > i){
                ans = i;
            }
        }
    }
  if(ans != 1001){
  cout << ans;
  }else{
    cout << -1;
  }
}