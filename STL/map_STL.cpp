#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    set<string> names;
    string tmp;
    while(n--){
        cin >> tmp;
        names.insert(tmp);
    }
    for(string s: names)
        cout << s << endl;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}