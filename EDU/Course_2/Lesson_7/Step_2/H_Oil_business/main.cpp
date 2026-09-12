// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/H

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

struct Edge{
    int id;
    int v1;
    int v2;
    int weight;

    bool operator>(const Edge &other) const {
        return weight > other.weight;
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
ll custo_maximo;
vector<Edge> grafo, sobras, resp;

void kruskal(){
    for(auto i : grafo){
        if(!same_uf(i.v1, i.v2)){
            union_uf(i.v1, i.v2);
        }else sobras.push_back(i);
    }
}

void remove_edges(){
    ll custo_usado = 0;
    while(!sobras.empty()){
        if((sobras.back().weight + custo_usado) <= custo_maximo){
            custo_usado += sobras.back().weight;
            resp.push_back(sobras.back());
            sobras.pop_back();
        } else break;
    }
    sort(resp.begin(), resp.end(), [](const auto &e1, const auto &e2){
        return e1.id < e2.id;
    });
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin>>vertices>>arestas>>custo_maximo;

    for(int i = 0 ; i <= vertices ; i++){
        uf.push_back(i);
        peso.push_back(1);
    }

    for(int i = 1 ; i <= arestas ; i++){
        int v1, v2, weight; cin>>v1>>v2>>weight;
        grafo.push_back({i, v1, v2, weight});
    }

    sort(grafo.begin(), grafo.end(), greater());
    kruskal(); remove_edges();

    cout<<resp.size()<<endl;
    for(int i = 0 ; i < int(resp.size()) ; i++){
        cout<<resp[i].id;
        if(i+1 != int(resp.size())) cout<<' ';
    } cout<<endl;

    return 0;
}
