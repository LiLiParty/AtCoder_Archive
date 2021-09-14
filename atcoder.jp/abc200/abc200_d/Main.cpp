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
//const ll mod = 998244353;



int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++){
        ll a;
        cin >>a;
        a %= 200;
        A[i] = a;
    }
    map<int,vector<int>> M;
    if(N > 8) N=8;
    for(int bit=1; bit<(1<<N); bit++){
        ll sum=0;
        vector<int> B;
        for(int i=0; i<8; i++){
            if(bit & (1<<i)){
                sum += A[i];
                B.push_back(i+1);
            }
        }
        sum %= 200;
        if(M.count(sum)){
            vector<int> C = M[sum];
            cout << "Yes" << endl;
            cout << B.size() << " ";
            for(auto b: B){
                cout << b << " ";
            }
            cout << endl;
            cout << C.size() << " ";
            for(auto c: C){
                cout << c << " ";
            }
            return 0;
        }else{
            M[sum] = B;
        }
    }
    cout << "No" << endl;
}

