#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int number;
        cin>>number;
        int crop=0;
        int a[number];
        for(int i=0; i<number; i++){
            cin>>a[i];
        }
        int l,r;
        cin>>l>>r;
        for(int i=0; i<r; i++){
            if(a[i]==a[i+1]){
                crop=i;
            }
        }
        cout<<crop<<"\n";   
    }
}