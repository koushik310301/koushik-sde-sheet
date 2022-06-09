#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
        unordered_map<int,list<pair<int,int>>> adj;

        void addEdge(int u,int v, int w){
            adj[u].push_back({v,w});
        }

        void display(){
            for(auto ls : adj){
                cout<<ls.first<<" : ";
                for(auto ls2 : ls.second){
                    cout<<ls2.first<<","<<ls2.second<<"  ";
                }cout<<endl;
            }
        }

        void topoSort(){

        }
};


void dfs(unordered_map<int,list<pair<int,int>>> &adj,vector<int>& vis,stack<int> & st,int n, int src){

    vis[src]=1;
    for(auto ls : adj[src]){
        if(vis[ls.first]==0) dfs(adj,vis,st,n,ls.first);
    }

    st.push(src);
}

int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    g.display();

    int n=6;
    vector<int> vis(n,0);
    stack<int> st;
    int src=1;
    unordered_map<int,list<pair<int,int>>> adl=g.adj;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(adl,vis,st,n,i);
        }
    }

   


    vector<int> dis(n,INT_MAX);
    dis[src]=0;
    while(st.empty()==false){
        int top=st.top();
        st.pop();
        if(dis[top]!=INT_MAX){
            for(auto i : adl[top]){
                dis[i.first]=min(dis[top]+i.second,dis[i.first]);
            }
        }
    }

    for(int i : dis) cout<<i<<" ";
    


    return 0;
}