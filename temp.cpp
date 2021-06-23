/*
 *
 ********************************************************************************************
 * AUTHOR : Vijju123                                                                        *
 * Language: C++14                                                                          *
 * Purpose: -                                                                               *
 * IDE used: Codechef IDE.                                                                  *
 ********************************************************************************************
 *
 Comments will be included in practice problems if it helps ^^
 */
 
 
 
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
//I never understand why people put useless functions at top of code. Makes it so unreadable ughhhh.
 
long long readInt(long long l,long long r,char endd){
	long long x=0;
	int cnt=0;
	int fi=-1;
	bool is_neg=false;
	while(true){
		char g=getchar();
		if(g=='-'){
			assert(fi==-1);
			is_neg=true;
			continue;
		}
		if('0'<=g && g<='9'){
			x*=10;
			x+=g-'0';
			if(cnt==0){
				fi=g-'0';
			}
			cnt++;
			assert(fi!=0 || cnt==1);
			assert(fi!=0 || is_neg==false);
 
			assert(!(cnt>19 || ( cnt==19 && fi>1) ));
		} else if(g==endd){
			if(is_neg){
				x= -x;
			}
			if(!(l<=x && x<=r))cerr<<l<<"<="<<x<<"<="<<r<<endl;
			assert(l<=x && x<=r);
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(int l,int r,char endd){
	string ret="";
	int cnt=0;
	while(true){
		char g=getchar();
		assert(g!=-1);
		if(g==endd){
			break;
		}
		cnt++;
		ret+=g;
	}
	assert(l<=cnt && cnt<=r);
	return ret;
}
long long readIntSp(long long l,long long r){
	return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
	return readInt(l,r,'\n');
}
string readStringLn(int l,int r){
	return readString(l,r,'\n');
}
string readStringSp(int l,int r){
	return readString(l,r,' ');
}
 
 
 
int main() {
	// your code goes here
#ifdef JUDGE
	string in,out;
	cin>>in>>out;
	in+=".in";
	if(in!="z.in")
		out+=".out";
	else out+=".in";
	if(in!="z.in")
		freopen(in.c_str(), "rt", stdin);
	freopen(out.c_str(), "wt", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	srand(time(NULL));
	//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	int t=readIntLn(1,10);
	while(t--)
		{
			int n=readIntLn(1,1000);
	    
			//Decl and Init
			int score[100];
			memset(score,0,sizeof(score));
			int p,s;
	    
			while(n--)
				{
					p=readIntSp(1,11);
					s=readIntLn(0,100);
					score[p]=max(score[p],s);
				}
	    
			int ans=0;
			for(int i=1;i<=8;i++)ans+=score[i];
			cout<<t<<"\n";
			cout<<ans<<endl;
		}
	cout<<"over"<<"\n";
	//assert(getchar()==-1);
	return 0;
}
 
