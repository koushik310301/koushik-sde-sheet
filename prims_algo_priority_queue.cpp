#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;
    for(auto ls : g){
        adj[ls.first.first].push_back({ls.first.second,ls.second});
        adj[ls.first.second].push_back({ls.first.first,ls.second});
    }
    
//     for(auto ls : adj){
//         cout<<ls.first<<"-->";
//         for(auto ls2 : ls.second){
//             cout<<ls2.first<<","<<ls2.second<<" ";
//         }cout<<endl;
//     }
    
    
    vector<int> key(n+1,INT_MAX);
    vector<int> mst(n+1,false);
    vector<int> par(n+1,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    key[1]=0;
    pq.push({0,1});
    for(int k=0;k<n;k++){
//         int ind;
//         int dis=INT_MAX;
        
        
//         //finding the minimum
//         for(int i=1;i<=n;i++){
//             if(mst[i]==false && key[i]<dis){
//                 ind=i;
//                 dis=key[i];
//             }
//         }
        auto top=pq.top();
        while(pq.empty()==false && mst[pq.top().second]==true){
            pq.pop();
        }
        top=pq.top();
        pq.pop();
        
        //visiting the vertex
        int ind=top.second;
        mst[ind]=true;
        for(auto it : adj[ind]){
            if(mst[it.first]==false && key[it.first]>it.second){
                par[it.first]=ind;
                key[it.first]=it.second;
                pq.push({key[it.first],it.first});
            }
        }
       
        
    }
    
    
    vector<pair<pair<int,int>,int>> ans;
    
    for(int i=2;i<=n;i++){
        pair<int,int> p;
        p={i,par[i]};
        int d=key[i];
        ans.push_back({p,d});
    }
    return ans;
    
    
    
}
