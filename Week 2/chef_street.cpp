#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n; 
        cin>>n;
        int S[n+1], P[n+1], V[n+1];
        for (int i = 0; i < n; i++)
        {
            cin>>S[i]>>P[i]>>V[i];
        }
        int maxval = 0;
        for (int i = 0; i < n; i++)
        {
            int currval = ((int)P[i]/(S[i]+1))*V[i];
            if(currval > maxval)
                maxval = currval;
        }
        cout<<maxval<<endl;
        
    }
    return 0;
}