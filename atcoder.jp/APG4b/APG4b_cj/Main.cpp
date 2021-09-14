#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 0;
  vector<int> vec(N);
  for (int i = 0; i < N; i++){
    cin >> vec.at(i);
    sum += vec.at(i);
  }
  int ave = sum/N;
  for (int i = 0; i < N; i++){
    if((ave - vec.at(i)) > 0){
      cout << ave - vec.at(i) << endl;
    }
    else{
      cout << -(ave - vec.at(i)) << endl;
    }
  }
  
}