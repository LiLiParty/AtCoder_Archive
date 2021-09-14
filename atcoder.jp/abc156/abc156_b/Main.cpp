#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin >> N >> K;
  int max=1;
  for(int i=1;i<1000;i++){
    if(N/std::pow(K,i) >= 1)max=i+1;
  }
  cout << max;
}