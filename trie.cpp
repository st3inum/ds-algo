#include <bits/stdc++.h>
using namespace std;

class trie
{
	const static int mx=26;
	struct node
	{
		bool endmark;
		node *next[mx];
		node()
		{
			endmark=false;
			for(int i=0;i<mx;i++)next[i]=NULL;
		}
	}*root;

	void del(node* cur)
	{
	    for (int i = 0; i < mx; i++)
	        if (cur->next[i])
	            del(cur->next[i]);
	    delete (cur);
	}
public:
	trie()
	{
		root=new node();
	}
	~trie()
	{
		del(root);
	}
	void insert(string s)
	{
		node *curr=root;
		for(auto a:s)
		{
			int k=a-'a';
			if(curr->next[k]==NULL)
				curr->next[k]=new node();
			curr=curr->next[k];
		}
		curr->endmark=true;
	}
	bool search(string s)
	{
		node *curr=root;
		for(auto a:s)
		{
			int k=a-'a';
			if(curr->next[k]==NULL)
				return false;
			curr=curr->next[k];
		}
		return curr->endmark;
	}
};


int main()
{
	trie t;
	string s;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>s;
		t.insert(s);
	}
	cin>>n;
	while(n--)
	{
		cin>>s;
		cout<<t.search(s)<<endl;
	}
}