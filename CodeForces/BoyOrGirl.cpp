#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    set<char> unique;
    for(char ch : str){
        unique.insert(ch);
    }
    int count=unique.size();
    
    if(count%2==0){
        cout<<"CHAT WITH HER!\n";
    }
    else{
        cout<<"IGNORE HIM!\n";
    }
}