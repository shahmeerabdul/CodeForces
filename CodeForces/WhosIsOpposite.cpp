#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int circle=2*abs(a-b);
        if(a>circle || b>circle || c>circle){
            cout<<-1<<"\n";
        }
        else{
            if(c + circle/2 > circle){
                cout<<(c + circle/2) - circle<<"\n";
            }
            else{
                cout<<c+circle/2<<"\n";
            }
        }
    }
}