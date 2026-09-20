// https://codeforces.com/contest/1245/problem/D

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

struct DSU{
    vector<int> uf, peso;

    DSU(int num){
        for(int i = 0 ; i <= num ; i++){
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

struct Edge {
    int v1, v2;
    ll cust;
    bool gen;

    bool operator<(const Edge &other) const {
        return cust < other.cust;
    }
};

struct Vertex {
    int id, x, y;
    ll k;
};

int num_cidades;
vector<Vertex> conjunto_vertices;
vector<Edge> conjunto_arestas;

void permuta(){
    for(int p1 = 1 ; p1 <= num_cidades ; p1++){
        for(int p2 = p1+1 ; p2 <= num_cidades ; p2++){
            ll custo_calc = 
            (abs(conjunto_vertices[p1].x - conjunto_vertices[p2].x) 
            + abs(conjunto_vertices[p1].y - conjunto_vertices[p2].y)) 
            * (conjunto_vertices[p1].k + conjunto_vertices[p2].k);

            conjunto_arestas.push_back({
                conjunto_vertices[p1].id, 
                conjunto_vertices[p2].id, 
                custo_calc, 
                false
            });
        }
    }
}

ll ienes = 0;
vector<int> cidades_geradoras;
vector<pair<int, int>> cidades_ligadas;

void kruskal(){
    DSU dsu = DSU(num_cidades);
    for(auto i : conjunto_arestas){
        if(!(dsu.same(i.v1, i.v2))){
            dsu.unite(i.v1, i.v2);
            ienes += i.cust;
            if(i.gen) cidades_geradoras.push_back(i.v2);
            else cidades_ligadas.push_back({i.v1, i.v2});
        }
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>num_cidades;

    conjunto_vertices.resize(num_cidades+1);
    for(int i = 1 ; i <= num_cidades ; i++){
        int x, y; cin>>x>>y;

        conjunto_vertices[i].id = i;
        conjunto_vertices[i].x = x;
        conjunto_vertices[i].y = y;
    }

    for(int i = 1 ; i <= num_cidades ; i++){
        int x; cin>>x;
        conjunto_arestas.push_back({0, i, x, true});
    }

    for(int i = 1 ; i <= num_cidades ; i++){
        int k; cin>>k;
        conjunto_vertices[i].k = k;
    }
    permuta();

    sort(conjunto_arestas.begin(), conjunto_arestas.end());
    kruskal();

    cout<<ienes<<endl;
    
    cout<<cidades_geradoras.size()<<endl;
    for(auto i : cidades_geradoras) cout<<i<<' ';
    cout<<endl;

    cout<<cidades_ligadas.size()<<endl;
    for(auto i : cidades_ligadas) cout<<i.first<<' '<<i.second<<endl;

    return 0;
}
