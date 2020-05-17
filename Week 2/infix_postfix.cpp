#include<iostream>
#include<vector>
#include<cctype>

using namespace std;

int preced(char op){
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        string infix, postfix = "";
        cin>>infix;

        vector<char>stack;
        for(int i = 0; i<infix.size(); i++){
            if(infix[i]=='(')
                stack.push_back(infix[i]);
            else if(isalpha(infix[i]))
                postfix += infix[i];
            else if(infix[i] == ')'){
                while(stack.size()>0 && stack.back() != '('){
                    postfix += stack.back();
                    stack.pop_back();
                }
                stack.pop_back();
            }
            else{
                while(stack.size()>0 && preced(infix[i])<=preced(stack.back())){
                    postfix += stack.back();
                    stack.pop_back();
                }
                stack.push_back(infix[i]);
            }
        }
        while(stack.size()>0){
            postfix += stack.back();
            stack.pop_back();
        }
        cout<<postfix<<endl;
    }
    return 0;
}