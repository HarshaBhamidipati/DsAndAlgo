#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            st.push(s[i]);
        }else if(s[i]=='}' || s[i]==')' || s[i]==']'){
            if(st.empty()){
                return false;
            }
            char popped = st.top();
            st.pop();
            if(popped == '{'){
                if(s[i]==']' || s[i]==')'){
                    return false;
                }
            }else if(popped == '['){
                if(s[i]=='}' || s[i]==')'){
                    return false;
                }
            }else if(popped == '('){
                if(s[i]==']' || s[i]=='}'){
                    return false;
                }
            }
        }
    }
    return st.empty();
}

int main(){
    string s ;
    cout<<"String: ";
    cin>>s;
    cout<<endl<<s;
    isBalanced(s)?cout<<" is balanced":cout<<" is not balanced";
    return 0;
}