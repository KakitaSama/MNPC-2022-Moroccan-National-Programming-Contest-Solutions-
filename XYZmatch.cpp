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
    vector<vector<int>> v(3);
    for(int i = 0; s[i] ; i++){
        v[s[i]-'x'].push_back(i);
    }
    vector<int> moves(1001);
    vector<vector<int>> dif(3);
    for(int i = 0; i < 3 ; i++){
        for(int j = 1; j < v[i].size() ; j++){
            dif[i].push_back(v[i][j]-v[i][j-1]);
        }
    }
    int max0 = 0;
    int a = 0;
    for(int i = 1; i <= 700 ; i++){
        long long S = 0;
        vector<int> w(100001);
        w[0] = 1;
        for(int j = 0; j < 3 ; j++){
            S = 0;
            w[0] = 1;
            for(int u = 0; u < dif[j].size() ; u++){
                S += dif[j][u];
                if(S-i>=0 && w[S-i] >0){
                    moves[i]++;
                }
                w[S]++;
            }
            w[S]--;
            for(int l = dif[j].size()-1 ; l >= 1 ; l--){
                S -= dif[j][l];
                w[S]--;
            }
            
        }
        if(moves[i] > max0){
            max0 = moves[i];
            a = i;
        }
    }
    cout<<max0<<" "<<a<<endl;
}
