#include<iostream>
#include<vector>

#define ll long long

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, temp;
        cin>>n;
        vector <ll> boxes;
        for(int i = 0; i<n; i++){
            cin>>temp;
            boxes.push_back(temp);
        }
        ll minval = boxes[0], tottokens = boxes[0];
        for (int i = 1; i < n; i++)
        {
            if(minval>boxes[i]){
                minval = boxes[i];
            }
            tottokens += minval;
        }
        cout<<tottokens<<endl;
        
    }
    return 0;
}