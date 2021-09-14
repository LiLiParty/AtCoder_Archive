#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

int main(){
    ll A,B,C,D;
    cin >> A >> B >> C >> D;
    ll Bc = B/C; //Cで割り切れる
    ll Bd = B/D;
    ll Bcd = B/lcm(C,D);
    ll Ac = (A-1)/C; //Cで割り切れる
    ll Ad = (A-1)/D;
    ll Acd = (A-1)/lcm(C,D);
    ll Bwarikire = Bc + Bd - Bcd;
    ll Awarikire = Ac + Ad - Acd;
    cout << B-A+1-(Bwarikire-Awarikire);
}
