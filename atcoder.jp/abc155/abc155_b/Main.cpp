#include <bits/stdc++.h>
using namespace std;

int main() {
  int j = 0;
  int N;
  cin >> N;
  vector<int> file(N);
  for(int i = 0; i < N; i++){
    cin >> file.at(i);
  }
  for(int i = 0; i < N; i++){
    if(file.at(i) % 2 == 0){
       if(file.at(i) % 6 == 0 or file.at(i) % 10 == 0){
       }
      else{
        j ++;
    }
  }
  }
  if(j > 0){
    cout << "DENIED";
  }
  else{
    cout << "APPROVED";
  }
}

