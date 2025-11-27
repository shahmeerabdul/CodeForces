#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, x, y;
        cin>>a>>x>>y;
        int Ad1=abs(a-x);
        int Ad2=abs(a-y);
        if(((abs(y-x)<Ad1) || (abs(x-y)<Ad2))){
            cout<<"YES\n";
        }
        
        else{
            cout<<"NO\n";
        }
    }
    }
