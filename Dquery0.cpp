#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define mod 1000000007
using namespace std;

vector<int> v;
vector<int> cnt(1000010,0);
int q;
int BLOCK ;
int answer = 0;

class node
{
public:	
	int i,l,r;
	node(int left , int right, int index )
	{
		i = index;//ORIGINAL INDEX OF QUERY
		l = left ;
		r = right;
	}
	friend ostream& operator<<(ostream &out , node &a)
	{
		out<<a.l<<" "<<a.r<<" "<<a.i<<" "<<endl;
	}

};

//******************COMPARISON FOR SORT*****************
bool mycomparison(node& a, node& b)
{
	if(a.l/BLOCK ==b.l/BLOCK)
	{
		return a.r<b.r;
	}
	else
	{
		return a.l/BLOCK<b.l/BLOCK;
	}
}
//*****************************************************


void add(int index)
{
	cnt[v[index]]++;
	if(cnt[v[index]]==1)
	{
		answer++;
	}
}
void rem(int index)
{
	cnt[v[index]]--;
	if(cnt[v[index]]==0)
	{
		answer--;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	scanf("%i",&n);


	
	for (int i = 0; i <n; ++i)
	{
		int k;
		scanf("%i",&k);
		v.push_back(k);
	}
	

	scanf("%i",&q);
	BLOCK = sqrt(q);
//********* QUERY RE-ARRANGEMENT PART MOH'S ALGORITHM *********
	vector<node> query;
	for(int i = 0; i<q;i++)
	{
		int a, b;
		scanf("%i%i",&a,&b);
		query.push_back(node(a-1,b-1,i));
	}

	sort(query.begin() , query.end(),mycomparison);

//**************************************************************

	int left_move = 0;
	int right_move = 0;

	int ans[q] ;
	for(auto x : query)
	{
		int left = x.l;
		int right = x.r;

		while(left_move < left)
		{
			rem(left_move);
			left_move++;
		}
		while(left_move > left)
		{
			add(left_move-1);
			left_move--;
		}
		while(right_move <= right)
		{
			add(right_move);
			right_move++;
		}
		while(right_move > right+1)
		{
			rem(right_move-1);
			right_move--;
		}
		ans[x.i] = answer;
	}
	
	for (auto p : ans)
		printf("%i\n",p);
}