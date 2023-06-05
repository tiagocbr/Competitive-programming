#include <bits/stdc++.h>
using namespace std;
const int maxn=510;
vector<pair<long long,long long>> peia[maxn];
 
long long dp[50001][510];
 
long long majestosidade(long long peso,long long idx,const vector<pair<long long,long long>>& vetor){
     if(vetor.size()==0)return 0;
     if(peso==0)return 0;
     if(idx>=vetor.size())return 0;
     if(dp[peso][idx]!=-1)return dp[peso][idx];
 
     if(peso-vetor[idx].first<0){
          return dp[peso][idx]=majestosidade(peso,idx+1,vetor);
     }
    
     return dp[peso][idx]=max(vetor[idx].second+majestosidade(peso-vetor[idx].first,idx+1,vetor),majestosidade(peso,idx+1,vetor));
     
 
}
 
 
 
 
 
int main(){
     long long n,t;cin>>n>>t;
     long long res=0;
 
     for(long long i=0;i<n;i++){
          long long k,h,m;cin>>k>>h>>m;
          peia[h].push_back({k/2,m});
          
     }
     for(long long i=1;i<=t;i++){
          long long e,d;cin>>e>>d;
          long long sapato=min(e,d);
          for(int k=0;k<50001;k++){
               for(int j=0;j<peia[i].size();j++){
                    dp[k][j]=-1;
               }
          }
          res+=majestosidade(sapato,0,peia[i]);
 
     }
     cout<<res;
     
    
}
 