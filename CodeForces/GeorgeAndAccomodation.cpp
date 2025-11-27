#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int yes=0;
    while(t>=1 && t<=100 && t--){
        int p,q;
        cin>>p>>q;
        if((q-p)>=2){
            yes++;
        }
    }
    cout<<yes;
}