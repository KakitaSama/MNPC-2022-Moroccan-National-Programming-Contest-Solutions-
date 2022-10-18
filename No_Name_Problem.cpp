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
    long long n,k;
    cin>>n>>k;
    vector<long long> v(n);
    for(long long i = 0; i < n ; i++)cin>>v[i];
    long long i = 0,j = 0;
    multiset<long long> mul;
    mul.insert(v[j]);
    j++;
    map<long long,long long> mp;
    mp[v[0]]++;
    long long max0 = 1;
    while(j <= n){
        if(*(mul.rbegin())-(*mul.begin())<=k){
            max0 = max(max0,(long long)mul.size());
            if(j == n)
                break;
            mul.insert(v[j]);
            mp[v[j]]++;
            j++;
        }
        else{
            mp[v[i]]--;
            if(mp[v[i]] == 0){
                mul.erase(mul.lower_bound(v[i]));
            }
            i++;
        }
    }
    cout<<max0<<endl;
}
