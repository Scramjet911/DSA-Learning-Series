#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, numa = 0, numb = 0, res;
        string goals;
        cin>>n>>goals;
        res = 2*n;
        for(int i = 0; i<goals.size(); i++){
            if(goals[i] == '1'){
                if(i%2 == 0)
                    numa++;
                else
                    numb++;
            }
            if((n-(i/2+i%2))<(numa-numb) || (n-(i/2+1))<(numb-numa)){
                res = i+1;
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}