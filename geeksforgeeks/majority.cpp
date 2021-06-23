#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in","r",stdin);
    freopen("/home/pavan/cp_problems/a.out","w",stdout);
    #endif

	//code
	int t{};
	cin>>t;
	while(t--){
	    int n,res{-1},a;
	    cin>>n;
	    unordered_map <int,int> m;
	    for(int i=0;i<n;i++){
	        cin>>a;
	        m[a]+=1;
	        if(m[a]> n/2) {
	            res=a;
	        }
	    }
	    cout<<res<<"\n";
	}
	return 0;
}