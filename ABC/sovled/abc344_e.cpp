// Problem: E - Insert or Erase
// Contest: AtCoder - 	Toyota Programming Contest 2024#3（AtCoder Beginner Contest 344）
// URL: https://atcoder.jp/contests/abc344/tasks/abc344_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;

const int N = 81;

class Node
{
	public:
	Node(int val=-1, Node* pre=nullptr, Node* post=nullptr) 
	: m_val(val), m_pre(pre), m_post(post) {}
	void InsertAfter(Node* pNode)
	{
		Node* oldPost = m_post;
		m_post->m_pre = pNode;
		m_post = pNode;
		pNode->m_pre = this;
		pNode->m_post = oldPost;
	}
	void InsertBefore(Node* pNode)
	{
		Node* oldPre = m_pre;
		m_pre->m_post = pNode;
		m_pre = pNode;
		pNode->m_pre = oldPre;
		pNode->m_post = this;
	}
	void DeleteThis()
	{
		m_pre->m_post = m_post;
		m_post->m_pre = m_pre;
		m_pre = nullptr;
		m_post = nullptr;
	}
	Node* m_pre{nullptr};
	Node* m_post{nullptr};
	int m_val{-1};
};

void coutAll(Node* pHead, Node* pTail)
{
	Node* cur = pHead->m_post;
	while (cur != pTail) 
	{
		cout << cur->m_val << ' ';
		cur = cur->m_post;
	}
	cout << endl;
}
int main()
{
	Node* pHead = new Node();
	Node* pTail = new Node();
	pHead->m_post = pTail;
	pTail->m_pre = pHead;
	int n; cin >> n;
	unordered_map<int, Node*> val2node;
	
	for (int i = 0; i < n; i++)
	{
		Node* pNew = new Node();
		cin >> pNew->m_val;
		pTail->InsertBefore(pNew);
		val2node.emplace(pNew->m_val, pNew);
	}
//coutAll(pHead, pTail);
	int q; cin >> q;
	while (q--)
	{
		int t, x, y;
		cin >> t >> x; //cout << x << ' ';
		if (t == 1) cin >> y;
		if (t == 2)
		{
			val2node[x]->DeleteThis();
			val2node.erase(x);
		}
		else
		{
			Node* pNew = new Node(y);
			val2node[x]->InsertAfter(pNew);
			val2node[y] = pNew;
		}
		//coutAll(pHead, pTail);
	}
	coutAll(pHead, pTail);
}