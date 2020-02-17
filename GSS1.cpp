#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    ll s, bl,br,bs;

    node(ll set = LONG_LONG_MIN){
        s = bl = br = bs = set;
    }
    void set(ll ss = LONG_LONG_MIN){
        s = bl = br = bs = ss;
    }

    void mod(node& a, node& b){
        s = a.s+b.s;
        bl = max(a.bl, (a.s+b.bl));
        br = max(b.br, (b.s+a.br));
        bs = max(max(a.bs, a.br+b.bl), b.bs);
    }
};

node* query(vector<node>& tree,ll idX, ll Qs, ll Qf, ll l, ll r){
    if(r<Qs || Qf < l){
        return new node(); 
    }
    if(l>=Qs && r<=Qf){
        return &tree[idX]; 
    }

    ll mid = (l+r)/2;

    node *temp1 = query(tree, 2*idX, Qs, Qf, l, mid);
    node *temp2 = query(tree, 2*idX+1, Qs, Qf, mid+1, r);

    node* temp3 = new node();

    temp3->mod(*temp1, *temp2);

    if(Qf <= mid) return temp1;
    if(Qs > mid) return temp2;
    else
    return temp3;
}

void buildTree(vector<ll>& arr, vector<node>& tree, ll idX, ll s, ll e){
    if(s == e){
        tree[idX].set(arr[s]);
        return;
    }

    ll mid = (s+e)/2;

    buildTree(arr, tree, 2*idX, s, mid);
    buildTree(arr, tree, 2*idX+1, mid+1, e);

    tree[idX].mod(tree[2*idX],tree[2*idX+1]);

}
int main(){
    ll N;
    cin >> N;
    vector<ll> arr(N+1);
    vector<node> tree(4*N+1);

    for(ll i = 1; i <= N; i++){
        cin >> arr[i];
    }

    buildTree(arr, tree, 1, 1, N);

    /*for(ll i = 1; i <= 2*N; i++){
        cout << i << " "<< tree[i].s <<" "<< tree[i].bl <<" "<< tree[i].br <<" "<< tree[i].bs << endl;
    }*/

    ll Q;
    cin >> Q;
    while(Q--){
        ll x1, x2;
        cin >> x1 >> x2;

        node* t = query(tree, 1, x1, x2, 1, N);

        cout << t->bs<< endl;
    }

}
