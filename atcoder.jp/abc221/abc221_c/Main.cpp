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

ll ctoi(char c)
{
    switch (c)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    default:
        return 0;
    }
}

ll sumV(vector<ll> &A){
    ll ten = 1;
    ll ans = 0;
    for(int i=0; i<A.size(); i++){
        ans += A[i] * ten;
        ten *= 10;
    }
    return ans;
}

int main() {
    string N; cin >> N;
    vector<ll> Nv;
    for(int i=0; i<N.size(); i++){
        Nv.push_back(ctoi(N[i]));
    }
    ll ans = -1;

    for(int bit=1; bit<(1<<Nv.size())-1; bit++){
        vector<ll> L,R;
        for(int i=0; i<Nv.size(); i++){
            if(bit & (1<<i)){
                L.push_back(Nv[i]);
            }else{
                R.push_back(Nv[i]);
            }
        }
        sort(L.begin(),L.end());
        sort(R.begin(),R.end());
        ll sumL = sumV(L);
        ll sumR = sumV(R);
        ans = max(ans,sumL*sumR);
    }
    cout << ans << endl;
    
}
