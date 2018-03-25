#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define mod 1000000007
#define pb push_back
using namespace std;

class Tree{
public:
	vector<ll> s;
	ll ans=0;
}tree[400010];

vll a(100010);


bool isTriangle(ll x , ll y  ,ll z)
{
	return (y+z)>x;
}

Tree combine(Tree &n1, Tree &n2 ){
	Tree temp;
	
	int i = 0 ,j = 0;

	while(i<n1.s.size() and j<n2.s.size() and temp.s.size() <=45 ){
		if(n1.s[i] > n2.s[j]){
			temp.s.push_back(n1.s[i]);
			i++;
		}else{
			temp.s.push_back(n2.s[j]);
			j++;
		}
	}

	while(temp.s.size()<=45 and i<n1.s.size()){
		temp.s.push_back(n1.s[i]);
		i++;
	}
	while(temp.s.size()<=45 and j<n2.s.size()){
		temp.s.push_back(n2.s[j]);
		j++;
	}
	for(int i = 0 ; i+2 < temp.s.size(); i++){
		if(isTriangle(temp.s[i] , temp.s[i+1] , temp.s[i+2])){
			temp.ans = temp.s[i] + temp.s[i+1] + temp.s[i+2];
			break;
		}
	}
	return temp;
}

void build(int node,int start,int end)  
{
	if( start== end ){
	    tree[node].s.insert(tree[node].s.end(),a[start]);
	    tree[node].ans = 0;
	    return ;
	}		   
	
	ll mid =(start+end)/2;
	build( node*2, start, mid);
	build( node*2+1, mid+1, end);

	tree[node] = combine(tree[2*node] , tree[2*node+1]);
}

void modify(int node, int start, int end, int idx, int val)
{
	if( start == end){			
	   tree[node].s.clear();
	   tree[node].s.push_back(val);
	   tree[node].ans =0;          
	   return ;		
	}
	ll mid =(start+end)/2;
	if( start<=idx and idx <= mid )	modify(2*node , start , mid , idx , val);
	else	modify(2*node +1 , mid +1 ,end , idx , val);
	tree[node] = combine(tree[2*node], tree[2*node+1]) ;
}

Tree query(int node,int start,int end,int l,int r){
	if(	r<start or end<l)	return Tree();
	if( l<=start and end<=r)  return tree[node];
	ll mid = (start+end)/2;
	Tree p1= query(2*node, start ,mid, l ,r );
	Tree p2 = query(2*node+1 , mid+1 ,end , l,r);
	return combine(p1 , p2);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;

	for(int i = 0; i <n ;i++)
		cin>>a[i+1];
	build(1,1,n);

	for(int i = 0 ;i <q ; i++){
		int choice;
		cin>>choice;
		if(choice==1){
			int j , val;
			cin>>j>>val;
			modify(1 , 1, n , j , val);
		}
		else{
			int l ,r ;
			cin>>l>>r;
			Tree ans  = query(1, 1, n , l ,r);
			cout<<ans.ans<<endl;
		}
	}
}