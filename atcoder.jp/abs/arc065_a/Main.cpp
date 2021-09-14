#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    reverse(s.begin(), s.end());
    s += "0000000";

    bool a=true;
    int i=0;
    while(a){
        if( s.at(i)=='m' and s.at(i+1)=='a' and s.at(i+2)=='e' and s.at(i+3)=='r' and s.at(i+4)=='d'){
            i += 5;
            if( i == s.length()-7 ) break;
            continue;
        }else if( s.at(i)=='e' and s.at(i+1)=='s' and s.at(i+2)=='a' and s.at(i+3)=='r' and s.at(i+4)=='e'){
            i += 5;
            if( i == s.length()-7 ) break;
            continue;
        }else if( s.at(i)=='r' and s.at(i+1)=='e' and s.at(i+2)=='m' and s.at(i+3)=='a' and s.at(i+4)=='e' and s.at(i+5)=='r' and s.at(i+6)=='d' ){
            i += 7;
            if( i == s.length()-7 ) break;
            continue;
        }else if( s.at(i)=='r' and s.at(i+1)=='e' and s.at(i+2)=='s' and s.at(i+3)=='a' and s.at(i+4)=='r' and s.at(i+5)=='e'){
            i += 6;
            if( i == s.length()-7 ) break;
            continue;
        }else{
            a = false;
        }
    }

    if(a){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }




}
