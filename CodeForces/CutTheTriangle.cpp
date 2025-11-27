#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        bool samex=(x1==x2)||(x2==x3)||(x3==x1);
        bool samey=(y1==y2)||(y2==y3)||(y3==y1);

        if(samex && samey){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}