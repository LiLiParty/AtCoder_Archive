#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t H,W;
    cin >> H >> W;
    int64_t h,w;

    
    if(H%2==1){
        h = H/2 + 1;
    }else{
        h = H/2;
    }
    
    if(W%2==1){
        w = W/2 + 1;
    }else{
        w = W/2;
    }

    
    if(W == 0){
        cout << 0;
        exit(0);
    }else if(H==1 or W==1){
        cout << 1;
        exit(0);
    }
    
    
    if(H%2 == 1 and W%2 == 0){
        cout << h*w + (h-1)*w;
    }else if(W%2 == 1 and H%2 == 0){
        cout << h*w + (w-1)*h;
    }else if(H%2 == 1 and W%2 == 1){
        cout << h*w + (h-1)*(w-1);
    }else{
        cout << h*w + h*w;
    }
}