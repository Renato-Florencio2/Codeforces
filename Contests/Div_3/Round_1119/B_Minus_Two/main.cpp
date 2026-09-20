// https://codeforces.com/contest/2259/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 
int solv(){
    vector<int> conj;

    int impares = 0;
    pair<int, int> pares(0, 0);

    int n; cin>>n;

    for(int i = 0 ; i < n ; i++){
        int x; cin>>x;
        if(x % 2 == 0){
            if((x / 2) % 2 == 0) pares.first++;
            else pares.second++;
        } else impares++;
    }

    return max( max(pares.first, pares.second), impares);
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int casos; cin>>casos;
    for(int i = 0 ; i < casos ; i++) cout<<solv()<<endl;

    return 0;
}
