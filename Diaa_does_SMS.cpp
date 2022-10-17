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
pair<string,string> rd(string s){
    pair<string,string> p;
    int k = 0;
    for(int i = 0;s[i] ; i++){
        if(s[i] == ','){
            k = 1;
            continue;
        }
        if(k == 0)
            p.first  += s[i];
        else
            p.second += s[i];
    }
    return p;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    setIO();
    #endif
    int n,q;
    cin>>n;
    map<string,string> mp;
    string s;
    pair<string,string> p;
    for(int i = 0; i < n ; i++){
        cin>>s;
        p = rd(s);
        mp[p.first] = p.second;
    }
    cin>>q;
    vector<string> v;
    while(q--){
        cin>>s;
        p = rd(s);
        if(mp[p.second] != ""){
            v.push_back(p.second+","+mp[p.second]+","+p.first);
        }
    }
    sort(v.begin(),v.end());
    if(v.size() == 0){
        cout<<"nomatch"<<endl;
    }
    else
        for(int i = 0; i < v.size() ; i++){
            cout<<v[i]<<endl;
        }
}
