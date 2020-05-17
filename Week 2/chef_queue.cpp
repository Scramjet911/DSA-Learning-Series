//Gives partial correct, TLE for others
#include<iostream>

#define MOD 1000000007
#define ll long long

using namespace std;

ll arr[1000001], fear[1000001];


int main(){
    ll n, k;
    cin>>n>>k;
    for(ll i = 0; i<n; i++){
        cin>>arr[i];
    }
    fear[n-1] = -1;
    for(ll i = n-2; i>=0; i--){
        if(arr[i]>arr[i+1]){
            fear[i] = i+1;
        }
        else{
            fear[i] = -1;
            ll j = i+1;
            while(j<n){
                if(fear[j] != -1 && arr[fear[j]] < arr[i]){
                    fear[i] = fear[j];
                    break;
                }
                else if(fear[j] != -1){
                    j = fear[j];
                }
                else if(fear[j] == -1 && arr[i] < arr[j]){
                    fear[i]=-1;
                    break;
                }
                else{
                    j++;
                }
            }
        }
    }
    ll totfear = 1;
    for (ll i = 0; i < n; i++)
    {
        totfear = (totfear * ((fear[i] == -1) ? 1 : (fear[i]-i+1)))%MOD;
    }
    cout<<totfear<<endl;
    
    return 0;
}