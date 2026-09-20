// https://codeforces.com/contest/2259/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Segment{
    int p1;
    int p2; 
    int t;

    bool operator>(const Segment &other) const{
        return t > other.t;
    }
};

void solv(){

    vector<int> conj;
    vector<Segment> possi;

    int tam; cin>>tam;

    bool veri = false;
    int cont = 0;
    int p1=1;
    for(int i = 0 ; i < tam ; i++){
        int x; cin>>x;
        conj.push_back(x);


        if(!veri && x == 0) continue;
        else{
            cont++;
            if(!veri){
                p1 = i;
                possi.push_back({p1, i, cont});
                veri = true;
            } else if(x != 0){
                possi.push_back({p1, i, cont});
            }
        }
    }
    
    possi.push_back({-1, -1, 0});
    sort(possi.begin(), possi.end(), greater());

    for(int i = 0 ; i < tam ; i++){
        if(i != possi[0].p1 && i != possi[0].p2 && conj[i] != 1) cout<<'0';
        else cout<<'1';
        if((i+1) != tam) cout<<' ';
    } cout<<endl;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int casos; cin>>casos;

    for(int i = 0 ; i < casos ; i++) solv();

    return 0;
}
