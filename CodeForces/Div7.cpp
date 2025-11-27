#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<=9; i++){
            int number=((n/10)*10)+i;
            if(number%7==0){
                cout<<number<<"\n";
                break;
            }
        }
    }
}