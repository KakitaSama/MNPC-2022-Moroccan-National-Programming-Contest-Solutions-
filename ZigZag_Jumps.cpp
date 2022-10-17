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
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n ; i++){
        cin>>v[i];
    }
    vector<pair<bool,bool>> dp(n);
    dp[n-1].first = true;
    dp[n-1].second = true;
    multiset<pair<int,int>> mul;
    mul.insert({v[n-1],n-1});
    int k = 0;
    int cnt = 1;
    pair<int,int> p;
    for(int i = n-2 ; i >= 0 ; i--){
        p = {v[i],0};
        auto iu = mul.lower_bound(p);
        if(iu != mul.end() && iu->first == v[i]){
            mul.erase(iu);
        }
        auto it = mul.upper_bound(p);
        if(it != mul.end()){
            k = it->second;
            if(dp[k].second){
                dp[i].first = true;
                cnt++;
            }
        }
        auto i0 = mul.lower_bound(p);
        if(i0 != mul.begin()){
            i0--;
            k = i0->second;
            if(dp[k].first){
                dp[i].second = true;
            }
        }
        mul.insert({v[i],i});
    }
    cout<<cnt<<endl;
}
