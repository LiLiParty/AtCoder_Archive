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
#include <cassert>
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
    int N,K;
    cin >> N >> K;

    vector<int> T(1201, 0);
    vector<int> P(N, 0);
    for(int i=0; i<N; i++){
        int p1,p2,p3;
        cin >> p1 >> p2 >> p3;
        int p = p1 + p2 + p3;
        P.at(i) = p;
        T.at(p) += 1;
    }

    
    vector<int> rank(1201,0);
    int sum = 0;
    for(int p=1200; p>=0; p--){
        rank[p] += sum + 1;
        sum += T[p]; 
    }

    
    for(int i=0; i<N; i++){
        int ideal = P[i] + 300;
        if(rank[ideal] <= K){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    
}
