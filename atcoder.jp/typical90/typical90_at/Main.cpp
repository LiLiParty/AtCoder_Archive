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
    map<ll,ll> A,B,C;
    int N; cin >> N;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        if(a!=0) a %= 46;
        A[a]++;
    }
    for(int i=0; i<N; i++){
        int a; cin >> a;
        if(a!=0) a %= 46;
        B[a]++;
    }
    for(int i=0; i<N; i++){
        int a; cin >> a;
        if(a!=0) a %= 46;
        C[a]++;
    }
    ll ans = 0;
    for(int i=0; i<46; i++){
        for(int j=0; j<46; j++){
            for(int k=0; k<46; k++){
                int M = i+j+k;
                if(M==0){
                    ans += A[i] * B[j] * C[k];
                }else if(M % 46 == 0){
                    ans += A[i] * B[j] * C[k];
                }
            }
        }
    }
    cout << ans << endl;
}
