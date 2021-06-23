#include<bits/stdc++.h>

#define DEBUG

using namespace std;

class queue
{
    private:
    int a[1000];
    int size=1000;
    int start=0;
    int end=0;
    public:
    bool empty(){
        if(start==end) return true;
        else return false;
    }
    void push(int val)
    {
        a[end]=val;
        end=(end+1)%n;
    }
    void pop()
    {
        start = (start+1)%n;
    }
    int front()
    {
        return a[start];
    }
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in","r",stdin);
    freopen("/home/pavan/cp_problems/a.out","w",stdout);
    #endif

    int t{};
    cin>>t;

    while(t--)
    {
        
    }


    return 0;
}