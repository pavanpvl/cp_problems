#include<fstream>
#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#define FIT(a,b) for(vector<int>::iterator a=b.begin();a!=b.end();a++)
#include<stack>
#define ROF(a,b,c) for(int a=b;a>=c;--a)
#include<vector>    
#include<algorithm>
#define FOR(a,b,c) for(int a=b;a<=c;++a)
#define REP(a,b) for(int a=0;a<b;++a)
#include<cstring>
#include<bitset>
#include<cmath>
#include<iomanip>
#include<queue>
#define debug cerr<<"OK";
#define pii pair<int,int>
#define f cin
#define g cout
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define N 3010
using namespace std;
/*ifstream f("a.in");
ofstream g("a.out");*/
/*int dx[]={0,0,0,1,-1};
int dy[]={0,1,-1,0,0};*/
int D[N][N],a[N],b[N],n,m;
 
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    #endif
    f>>n;
    FOR(i,1,n)
    f>>a[i];
    f>>m;
    FOR(i,1,m)
    f>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    //g<<D[0][0]<<'\n';
    FOR(i,1,n)
    FOR(j,1,m)
    {
        D[i][j]=D[i-1][j-1];
        if(abs(a[i]-b[j])<=1)
            D[i][j]++;
        D[i][j]=max(D[i][j],max(D[i-1][j],D[i][j-1]));
    }
    g<<D[n][m];
    return 0;
}   