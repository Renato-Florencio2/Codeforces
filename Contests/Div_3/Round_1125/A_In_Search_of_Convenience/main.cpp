// https://codeforces.com/contest/2275/problem/A

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Point{
    int x;
    int y;
};

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int casos; cin>>casos;

    while(casos--){
        Point o1;
        int tam; cin>>o1.x>>o1.y>>tam;

        cout<<o1.x-tam<<" "<<o1.y<<endl;
    }

    return 0;
}
