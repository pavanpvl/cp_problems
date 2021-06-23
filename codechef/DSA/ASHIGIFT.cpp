#include <iostream>
#include <climits>
bool reach(int *x, long long *y, int *p, long long *q, long long *r, int C, int B, int X, long long start)
{
    int j = 0;
    long long pop = start;
    for (int i = 0; i < B; i++)
    {
        while (p[j] < x[i] && j < C)
        {
            if (pop >= q[j])
                pop += r[j];
            j++;
        }
        //std::cout<<pop<<" "<<y[i]<<"\n";
        if (pop <= y[i])
            return false;
        else
        {
            pop = pop - y[i];
        }
    }
    return true;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    int t;
    std::cin >> t;
    while (t--)
    {
        int X, B;
        std::cin >> X >> B;
        int x[B];
        long long y[B];
        for (int i = 0; i < B; i++)
            std::cin >> x[i] >> y[i];
        int C;
        std::cin >> C;
        int p[C];
        long long q[C], r[C];
        for (int i = 0; i < C; i++)
            std::cin >> p[i] >> q[i] >> r[i];
        long long left = 0, right = LLONG_MAX, m;
        bool rh;
        while (left < right)
        {
            m=left+((right-left)/2);
            rh=reach(x,y,p,q,r,C,B,X,m);
            if(rh) right=m;
            else left=m+1;
            //std::cout<<left<<" "<<right<<"\n";
        }
        std::cout<<left<<"\n";
        /*
        int res=reach(x,y,p,q,r,C,B,X,0);
        std::cout<<res;
        std::cout<<X<<" "<<B<<"\n";
        for(int i=0;i<C;i++) std::cout<<p[i]<<q[i]<<r[i]<<" ";
        std::cout<<"\n";  
        */
    }
}