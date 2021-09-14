#include <bits/stdc++.h>
#include <math.h>
using namespace std;
 
int main() {
  int A;
  cin >> A;
  int z = A % 2;
  int x = floor(A / 100);
  int y = (A - x*100 - z)/10;
  cout << z+x+y << endl;   
}