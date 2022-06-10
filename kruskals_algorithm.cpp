#include<bits/stdc++.h>

int findParent(int u, vector<int>& parent){
    if(u==parent[u]) return u;
    
    return parent[u]=findParent(parent[u],parent);
}


void makeUnion(int u, int v, vector<int>& parent, vector<int>& rank){
    u=findParent(u,parent);
    v=findParent(v,parent);
    
    if(rank[u]>rank[v]){
        parent[v]=u;
        rank[u]++;
    }
    else{
        parent[u]=v;
        rank[v]++;
    }
}

bool cmp(vector<int>& a, vector<int>& b){
    return a[2]<b[2];
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
    vector<int> parent(n+1,0);
    vector<int> rank(n+1,0);
    
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
     
    int ans=0;
    sort(graph.begin(),graph.end(),cmp);
   for(auto it : graph){
       int u=findParent(it[0],parent);
       int v=findParent(it[1],parent);
       int w=it[2];
       
       if(u!=v){
           makeUnion(u,v,parent,rank);
           ans+=w;
       }
       
   }
   
    
    return ans;
}