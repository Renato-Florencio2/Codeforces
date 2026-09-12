// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/E

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

struct Edge{
    int v1;
    int v2;
    int weight;

    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

vector<int> uf, peso;
int find_uf(int x){
    return (x == uf[x]) ? x : uf[x] = find_uf(uf[x]);
}
bool same_uf(int a, int b){
    return find_uf(a) == find_uf(b);
}
void union_uf(int a, int b){
    a = find_uf(a); b = find_uf(b);

    if(a == b) return ;

    if(peso[a] < peso[b]) swap(a, b);

    uf[b] = a;
    peso[a] += peso[b];
}

int vertices, arestas;
vector<Edge> grafo;

ll kruskal(){
    ll soma = 0;
    for(auto &i : grafo){
        if(!same_uf(i.v1, i.v2)){
            soma += i.weight;
            union_uf(i.v1, i.v2);
        }
    }
    return soma;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>vertices>>arestas;

    for(int i = 0 ; i <= vertices ; i++){
        uf.push_back(i);
        peso.push_back(1);
    }

    for(int i = 0 ; i < arestas ; i++){
        int v1, v2, weight; cin>>v1>>v2>>weight;
        grafo.push_back({v1, v2, weight});
    }

    sort(grafo.begin(), grafo.end());

    cout<<kruskal()<<endl;

    return 0;
}
