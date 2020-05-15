#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string brackets;
        cin>>brackets;
        int numlt = 0, maxpref = 0;
        for(int i = 0; i<brackets.size(); i++){
            if(brackets[i] == '<'){
                numlt ++;
                // maxpref++;
            }
            else if(brackets[i] == '>'){
                if(numlt == 0)
                    break;
                numlt--;
            }
            if(numlt == 0){
                maxpref = i+1;
            }
        }
        cout<<maxpref<<endl;
    }
    return 0;
}