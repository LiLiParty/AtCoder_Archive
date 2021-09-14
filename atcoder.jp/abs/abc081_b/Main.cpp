#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> vecA(N);
    for(int i=0; i<N ; i++){
        cin >> vecA.at(i); 
    }

    int count=0;
    bool op = true;
    while(op){
        for(int i=0; i<N ; i++){
            if( vecA.at(i)%2 == 0){
                vecA.at(i) /= 2;
            }else{
                op = false;
                break;
            }
        }
        if(op) count++;
    }

    cout << count << endl;
}
