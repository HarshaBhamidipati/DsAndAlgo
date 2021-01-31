#include<bits/stdc++.h>
using namespace std;
int a[]={5,4,2,3,5,6,1};
stack<int> s,mins;
int getMinimum(){
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        if(s.empty()&&mins.empty()){
            s.push(a[i]);
            mins.push(a[i]);
        }else{
            if(mins.top()>a[i]){
                mins.push(a[i]);
            }
            s.push(a[i]);
        }
    }
    return mins.top();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<getMinimum();
    return 0;
}