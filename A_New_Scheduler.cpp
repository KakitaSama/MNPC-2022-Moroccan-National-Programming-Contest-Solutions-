#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T> using ordered_set = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
const long long MAX0 = 3e5+2;
void setIO(string name = "") {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
} 
void setIO0(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if ((name.size())) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

long long pow2(long long a,long long b,long long MOD){
    long long res = 1;
    while(b>0){
        if(b&1)
            res = (res*a)%MOD;
        a = a*a;
        a%= MOD;
        b>>=1;
    }
    return res;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    setIO();
    #endif
    string s;
    cin>>s;
    int a = 0,max0 = 0,id = 0;
    for(int k = 1; k < s.size() ; k++){
        a = 0;
        for(int j = 0; j < s.size()-k ; j++){
            if(s[j] == s[j+k]){
                a++;
            }
        }
        if(a>max0){
            max0 = a;
            id = k;
        }
    }
    cout<<max0<<" "<<id<<endl;
}
