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
int a[100001];

class Tree
{
public:
	int num = 0;
	Tree* left = nullptr;
	Tree* right=nullptr;
	Tree* clone(){
		Tree* temp = new Tree();
		if(this!=nullptr){
			temp->left = this->left;
			temp->right = this->right;
			temp->num = this->num;
		}
		return temp;
	}
};


void build(Tree* &node,int start, int end)
{
	if(start==end){
		node->num = a[start];
		return;
	}
	int mid = (start+end)>>1;
	node->left = node->left->clone();
	node->right = node->right->clone();
	build(node->left , start , mid);
	build(node->right , mid+1 , end);
	node->num = node->left->num + node->right->num;
}

void update(Tree* &node , int start  , int end , int idx , int val)
{
	if(start == end){
		node->num = val;
		return;
	}
	int mid = (start+end)/2;
	if(start<=idx and idx <=mid){
		node->left = node->left->clone();
		update(node->left , start , mid , idx,val);
	}
	else{
		node->right = node->right->clone();
		update(node->right , mid+1 ,end , idx,val);
	}
	node->num = node->left->num + node->right->num ;
}

int query(Tree* &node , int start , int end , int l ,int r)
{
	if(r<start or end<l) return 0;
	if(l<=start and end<=r) return node->num;
	int mid = (start +end)>>1;
	return query(node->left , start ,  mid , l ,r )+ query(node->right , mid+1 , end,l ,r);
}

int main()
{
	int n;
	cin>>n;
	
	for(int i = 0 ; i< n ;i++)
		cin>>a[i+1];

	Tree* root[100001];

	root[0] = new Tree();
	build(root[0] , 1 , n);

	int q;
	cin>>q;
	int updates = 1;
	while(q--)
	{
		int type ;
		cin>>type;
		if(type==1)
		{
			int idx ,val;
			cin>>idx>>val;
			cout<<"UPDATE DONE : "<<updates<<" at "<<idx<<" : "<<val<<endl;
			root[updates] = root[updates-1]->clone();
			cout<<"UPDATE : "<<updates<<" "<<idx<<" : "<<val<<endl;
			update(root[updates] , 1 , n , idx , val);
			updates++;
		}
		else
		{
			cout<<"Enter the time : ";
			int ti,l,r;
			cin>>ti;
			if(ti>=updates)
			{
				cout<<"Can't Move Ahead of time ;) "<<endl;
				return 1;
			}
			cout<<"Enter left right :";
			cin>>l>>r;
			int ans = query(root[ti] , 1 , n ,l ,r);
			cout<<ans<<endl;
		}
	}


}