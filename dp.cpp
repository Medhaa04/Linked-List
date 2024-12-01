#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>>adj;
    void addEdge(int u,int v,bool bidir=true){
        adj[u].push_back(v);
        if(bidir==true) adj[v].push_back(u);

    }
    void print(){
        for(auto p:adj){
            cout<<p.first<<":";
            for(auto n:p.second) cout<<n<<",";
        }
        cout<<endl;
    }
    void bfs(int src){
        unordered_map<int,bool>visited;
        queue<int>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto p:adj[front]){
                if(!visited[p]){
                    visited[p]=true;
                    q.push(p);
                }
            }
        }

    }
    void dfshelper(int src,unordered_map<int,bool>&visited){
        visited[src]=true;
        for(auto ch:adj[src]){
            if(!visited[ch]) dfshelper(ch,visited);
        }
    }
    void dfs(int src){
        unordered_map<int,bool>visited;
         dfshelper(src,visited);
        }

    
    bool iscyclicbfs(int src){
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        visited[src]=true;
        parent[src]=-1;
        queue<pair<int,int>>q;
        q.push({src,-1}); //node,parent
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto ch:adj[node]){
                if(!visited[ch]){
                    visited[ch]=true;
                    q.push({ch,node});
                }
                else if(parent!=ch){
                    return true;
                }

                }
            }
return false;

        }
    bool check(int v,int color[],int start){

    }
    bool isBipartbfs(int v){
        int color[v];
        for(int i=0;i<v;++i) color[i]=-1;
        for(int i=0;i<v;++i){
            if(color[i]==-1){
                if(check(v,color,i)==false) return false;

            }
        }
        return true;

    }
    void dfstopo(int node,vector<int>visited,unordered_map<int,list<int>>adj,stack<int>&st){
        visited[node]=1;
        for(auto ch:adj[node]){
            if(!visited[ch]){
                dfstopo(ch,visited,adj,st);

            }
        }
        st.push(node);

    }

    vector<int> toodfs(int v){
        stack<int>st;
        vector<int>visited(v,0);
        for(int i=0;i<v;++i){
            if(!visited[i]){
                dfstopo(i,visited,adj,st);
            }

        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }

    vector<int>topobfs(int v){
        //s1 cal inde
    }


};