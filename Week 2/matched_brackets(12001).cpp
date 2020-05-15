#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int brackets[n+1];
    for(int i = 0; i<n; i++){
        cin>>brackets[i];
    }
    int maxdepth = 0, maxdepthpos = 0, maxseqlen = 0, maxseqpos = 0;
    int numlt = 0, currdepthpos = 0, currseqlen = 0;
    
    for(int i = 0; i<n; i++){
        if(brackets[i]==1)
            numlt++;
        else if(brackets[i]==2)
            numlt--;
        if(numlt > maxdepth){
            maxdepth = numlt;
            maxdepthpos = i+1;
        }
        if(numlt == 0)
            currdepthpos = i;
    }
    numlt = 0;
    for(int i = 0; i<n; i++){
        if(brackets[i] == 1)
            numlt++;
        else if(brackets[i] == 2)
            numlt--;
        currseqlen++;
        if(numlt == 0){
            if(maxseqlen < currseqlen){
                maxseqlen = currseqlen;
                maxseqpos = i - maxseqlen + 1;
            }
            currseqlen = 0;
        }
    }
    printf("%d %d %d %d\n", maxdepth, maxdepthpos, maxseqlen, maxseqpos + 1);
    return 0;
}