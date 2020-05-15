#include<iostream>
#include<vector>
#include<cctype>

using namespace std;
void printarr(vector <char> arr){
    cout<<"#";
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i];
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string infix, postfix;
        cin>>infix;
        vector <char> stack;
        for(int i = 0; i<n; i++){
            printarr(stack);
            if(infix[i]=='('){
                stack.push_back(infix[i]);
                continue;
            }
            else if(isalpha(infix[i])){
                postfix += infix[i]; 
                continue;
            }
            else if(infix[i]==')'){
                while(stack.back() != '('){
                    postfix += stack.back();
                    stack.pop_back();
                }
                stack.pop_back();       //popping last (
                continue;
            }
            else if(infix[i] == '+' || infix[i] == '-'){
                if(stack.size()>0){
                    char temp = stack.back();
                    if(temp == '*' || temp == '/' || temp == '^'){
                        postfix += temp;
                        stack.pop_back();
                        stack.push_back(infix[i]);
                        continue;
                    }
                    stack.push_back(infix[i]);
                }
                else
                    stack.push_back(infix[i]);
            }
            else if(infix[i] == '*' || infix[i] == '/'){
                if(stack.size()>0){
                    char temp = stack.back();
                    if(temp == '^'){
                        postfix += temp;
                        stack.pop_back();
                        stack.push_back(infix[i]);
                        continue;
                    }
                    stack.push_back(infix[i]);
                }
                else
                    stack.push_back(infix[i]);
            }
            
        }
        // cout<<"Exited loop1 : "<<endl;
        while(stack.size()!=0){
            char temp = stack.back();
            if(temp != '(' || temp != ')'){
                postfix += temp;
                stack.pop_back();
            }
            else
                stack.pop_back();
            // cout<<"Exited loop2 : "<<temp<<endl;

        }
        cout<<postfix<<endl;
    }
    return 0;
}