#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int sum = 1;
  for (int i = 1; i < S.size(); i+=2){
    if(S.at(i) == '+'){
      sum += 1;
    }
    else if(S.at(i) == '-'){
      sum -= 1;    
    }
  }
  cout << sum << endl;
}
