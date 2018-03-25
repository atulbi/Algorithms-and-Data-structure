#include <bits/stdc++.h>

#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 0x7fffffff;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y) 
#define mem(a,val) memset(a,val,sizeof(a))
#define f first
#define s second
#define pb push_back

using namespace std;


void subsequence(string s){	
	int len = s.length();
    for (int i = 1; i < 1<<len ; i++) { 
        string sub = "";
        for (int j = 0; j < len; j++){
        	if (i & (1 << j))
        		sub += s[j];
        }
        cout<<sub<<endl;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str= "abc";
	subsequence(str);
}