#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,n,m;
        string s;
        cin>>a>>b;
        while(a<=b){
            m= (a+b)/2;
            cout<<m<<endl;
            cin>>s;
            if(s=="CORRECT"){
                break;
            }
            else if(s=="WRONG_ANSWER"){
                return 0;
            }
            else if(s=="TOO_SMALL"){
                a=m+1;
            }
            else b=m;
        }
    }
    return 0;
}