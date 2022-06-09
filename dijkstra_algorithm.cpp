#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;
    for(auto ls : vec){
        adj[ls[0]].push_back({ls[1],ls[2]});
        adj[ls[1]].push_back({ls[0],ls[2]});
    }
    int n=vertices;
    vector<int> dis(n,INT_MAX);
    dis[source]=0;
    
    set<pair<int,int>> st;
    st.insert({0,source});
    
    while(st.empty()==false){
        
        auto top=*(st.begin());
        st.erase(st.begin());
        
        int nodeDistance=top.first;
        int node=top.second;
        
        for(auto it : adj[node]){
            if(nodeDistance+it.second<dis[it.first]){
                
                //checking whether the record already exists
                auto record=st.find({dis[it.first],it.first});
                
                //deleting the record if it already exists
                if(record!=st.end()){
                    st.erase(record);
                }
                
                //minimizing the distance
                dis[it.first]=nodeDistance+it.second;
                
                //inserting the updated pair
                st.insert({dis[it.first],it.first});
                
                
                
            }
        }
        
        
        
    }
    
    return dis;
    
}
