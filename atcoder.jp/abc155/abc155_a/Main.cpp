#include <bits/stdc++.h>
using namespace std;

int main() {
  int A;
  int B;
  int C;
  cin >> A >> B >> C;
  if(A==B and A !=C){
    cout << "Yes";
  }
  else if(C==B and A != C){
    cout << "Yes";
  }
  else if(A==C and A != B){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
  
}

