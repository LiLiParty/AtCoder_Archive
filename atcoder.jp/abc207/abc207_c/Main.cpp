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
    vector<pair<double,double>> A;
    for(int i=0; i<N; i++){
        int t;
        cin >> t;
        double l,r;
        cin >> l >> r;
        if(t==1){
            A.push_back(mk(l,r));
        }else if(t==2){
            A.push_back(mk(l,r-0.1));
        }else if(t==3){
            A.push_back(mk(l+0.1,r));
        }else{
            A.push_back(mk(l+0.1,r-0.1));
        }
    }
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            double a = A[i].first;
            double b = A[i].second;
            double c = A[j].first;
            double d = A[j].second;

            if((a<=d && c<=b)|| (d<=a && b<=c)){
                ans ++;
            }
        }
    }

    cout << ans << endl;
}
