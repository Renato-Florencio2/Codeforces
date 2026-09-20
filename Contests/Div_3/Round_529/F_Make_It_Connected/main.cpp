// https://codeforces.com/contest/1095/problem/F

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

struct DSU {
    vector<int> uf, peso;

    DSU(int quant){
        for(int i = 0 ; i <= quant ; i++){
            uf.push_back(i);
            peso.push_back(1);
        }
    }

    int find(int x){
        return (x == uf[x]) ? x : uf[x] = find(uf[x]);
    }
    bool same(int a, int b){
        return find(a) == find(b);
    }
    void unite(int a, int b){
        a = find(a); b = find(b);

        if(a == b) return ;

        if(peso[a] < peso[b]) swap(a, b);

        uf[b] = a;
        peso[a] += peso[b];
    }
};

struct Edge{
    int v1, v2;
    ll cust;

    bool operator<(const Edge &other) const {
        return cust < other.cust;
    }
};

int vertices, arestas_especiais;
vector<Edge> lista_arestas;

vector<pair<ll, int>> lista_vertices;
void make_arestas(){
    for(int p1 = 1 ; p1 < vertices ; p1++){
        ll soma = lista_vertices[0].first + lista_vertices[p1].first;
        lista_arestas.push_back(
            {lista_vertices[p1].second, lista_vertices[0].second, soma}
        );
    }
}

ll kruskal(){
    DSU dsu(vertices);
    ll soma = 0;
    for(auto i : lista_arestas){
        if(!dsu.same(i.v1, i.v2)){
            dsu.unite(i.v1, i.v2);
            soma += i.cust;
        }
    }
    return soma;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>vertices>>arestas_especiais;

    for(int i = 1 ; i <= vertices ; i++){
        ll custo; cin>>custo;
        lista_vertices.push_back({custo, i});
    }

    for(int i = 1 ; i <= arestas_especiais ; i++){
        int v1, v2; ll cust; cin>>v1>>v2>>cust;
        lista_arestas.push_back({v1, v2, cust});
    }

    sort(lista_vertices.begin(), lista_vertices.end());
    make_arestas();
    sort(lista_arestas.begin(), lista_arestas.end());
    cout<<kruskal()<<endl;

    return 0;
}
