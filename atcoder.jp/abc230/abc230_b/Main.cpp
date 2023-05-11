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

ll get_digit(ll num){
    ll digit = 0;
    while(num != 0){
        num /= 10;
        digit++;
    }
    
    return digit;
}



int main() {
    bool ans = true;
    string S;
    cin >> S;

    if(S.size()==1){
        cout << "Yes" << endl;
        return 0;
    }

    if(S[0]=='o'){
        for(int i=0; i<S.size(); i++){ //oxx
            if(i%3 == 0){
                if(!(S[i]=='o')){
                    cout << "No" << endl;
                    return 0;
                }
            }else{
                if(!(S[i]=='x')){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
        cout << "Yes" << endl;
        return 0;
    }

    if(S[0]=='x' and S[1]=='x'){
        for(int i=0; i<S.size(); i++){ //oxx
            if(i%3 == 0 or i%3 == 1){
                //cout << i;
                if(!(S[i]=='x')){
                    cout << "No" << endl;
                    return 0;
                }
            }else{
                if(!(S[i]=='o')){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
        cout << "Yes" << endl;
        return 0;
    }
    
    if(S[0]=='x' and S[1]=='o'){
        for(int i=0; i<S.size(); i++){ //oxx
            if(i%3 == 0 or i%3==2){
                if(!S[i]=='x'){
                    cout << "No" << endl;
                    return 0;
                }
            }else{
                if(!S[i]=='o'){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
        cout << "Yes" << endl;
        return 0;
    }
}
