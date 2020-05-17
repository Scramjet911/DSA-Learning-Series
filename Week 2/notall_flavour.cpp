#include<iostream>

using namespace std;

int main(){
    int t; 
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int flavlist[n+1], flavcount[k+1]={0}, numunique = 0, segstart = 0, segend = 0, maxlen = 1;
        for (int i = 0; i < n; i++)
        {
            cin>>flavlist[i];
        }
        for (segend = 0; segend < n; segend++)
        {
            if(flavcount[flavlist[segend]]==0)
                numunique++;
            flavcount[flavlist[segend]]++;

            if(maxlen < (segend-segstart))
                maxlen = segend-segstart;   

            if(numunique >= k){
                while(segstart < segend && numunique >= k){
                    flavcount[flavlist[segstart]]--;
                    if(flavcount[flavlist[segstart]]==0)
                        numunique--;
                    segstart++;
                }
            }
        }
        if(maxlen < (segend-segstart) && numunique<k)
            maxlen = segend-segstart;  
        cout<<maxlen<<endl;        
    }
    return 0;
}