#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch){
    if(ch>= 97 && ch<= 122){
        return true;
    }
    return false;
}

bool isOperator(char ch){
    if(ch == '+'||ch == '-'||ch == '*'||ch == '/'){
        return true;
    }
}
int getWeight(char ch){
    switch(ch){
        case '+':
        case '-': return 1;
        case '*':
        case '/':return 2;
    }
    return 0;
}

bool hasHighPre(char op1, char op2){
    int a = getWeight(op1);
    int b = getWeight(op2);
    if(a>b){
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> s;
    string exp,postfix;
    cout<<"Enter Infix expression"<<endl;
    cin>>exp;
    for(int i=0;i<exp.length();i++){
        if(isOperand(exp[i])){
            postfix+=exp[i];
        }else if(isOperator(exp[i])){
            while(!s.empty() && hasHighPre(exp[i],s.top())){
                postfix+=s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
    }
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    cout<<"\nPostfix expression is "<<postfix; 
    return 0;
}