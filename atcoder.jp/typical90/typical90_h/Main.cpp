#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pp pair<ll,ll>
#define ll long long
#define ld long double
#define mk make_pair
#define INF32 2147483647 
#define INF64 9223372036854775807
#define rep(i, n) for(int i = 0; i < n; i++)
const ll MOD = 1000000007;//10^9+7
const ll mod = 998244353;

int main() {
    ll a=0,t=0,c=0,o=0,d=0,e=0,r=0;
    int N; cin >> N;
    string S; cin >> S;

    for(int i=S.size()-1; i>=0; i--){
        if(S[i] == 'r'){
            r++;
            r%=MOD;
        }
        if(S[i] == 'e'){
            e+=r;
            e%=MOD;
        }
        if(S[i] == 'd'){
            d+=e;
            d%=MOD;
        }
        if(S[i] == 'o'){
            o+=d;
            o%=MOD;
        }
        if(S[i] == 'c'){
            c+=o;
            c%=MOD;
        }
        if(S[i] == 't'){
            t+=c;
            t%=MOD;
        }
        if(S[i] == 'a'){
            a+=t;
            a%=MOD;
        }
    }

    cout << a << endl;
}
