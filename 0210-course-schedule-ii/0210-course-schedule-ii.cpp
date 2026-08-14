#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    void TopologicalOrder(int src, vector<bool> &vis, stack <int>& s,vector<vector<int>>& edges){
        vis[src] = true ;

        for(int i=0 ; i<edges.size() ; i++){
            int v = edges[i][0] ;
            int u = edges[i][1] ;

            if(u == src){
                if(!vis[v]) TopologicalOrder(v,vis,s,edges) ;
            }
        }
        s.push(src) ;
    }

    bool isCycleDFS(int src , vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& edges ){
        vis[src] = true ;
        recPath[src] = true ;

        for(int i=0 ; i<edges.size() ; i++){
            int v = edges[i][0] ;
            int u = edges[i][1] ;

            if( u == src ){
                if(!vis[v]){
                    if(isCycleDFS(v,vis,recPath,edges)) return true ;
                }else if(recPath[v]) return true ;
            }
        }

        recPath[src] = false ;
        return false ;
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector <bool> vis(n,false) ;
        vector <bool> recPath(n,false) ;
        vector <int> ans ;

        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                if(isCycleDFS(i,vis,recPath,edges)) return ans ; // return empty vector as answer if a cycle exists in the graph
            }
        }

        // Topological Sorting
        stack <int> s ;
        vis.assign(n,false) ;

        for(int i=0 ; i<n ; i++){
            if(!vis[i]) TopologicalOrder(i,vis,s,edges) ;
        }
        
        while(s.size() > 0){
            ans.push_back(s.top()) ;
            s.pop() ;
        }

        return ans ;
    }
};