#include <bits/stdc++.h>
using namespace std;


int main(){
    string S;
    cin >> S;
    bool judge=true;
    if(S.size()%2 ==1) judge=false;
    for(int i=0;i<S.size();i++){
        if(i%2==0){
            if(S.at(i)!='h'){
                judge = false;
            }
        }else{
            if(S.at(i)!='i'){
                judge = false;
            }
        }
    }
    if(judge){
        cout << "Yes";
    }else{
        cout << "No";
    }
    }
    