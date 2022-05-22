#include <stack>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

class Queue
{
	stack<pair<int, int>> s1;
	stack<pair<int, int>> s2;

	void move()
	{
		while (s1.size())
		{
			int elem = s1.top().first;
			s1.pop();
			int mn = elem;

			if (s2.size())
			{
				mn = min(elem, s2.top().second);
			}

			s2.push(make_pair(elem, mn));
		}
	}

public:
	void enq(int n)
	{
		int mn = n;

		if (s1.size()){
			mn = min(mn, s1.top().second);
		}

		s1.push(make_pair(n, mn));
		
		cout << "ok";
	}
	void deq()
	{
		if (!s2.size())
		{
			move();
		}

		if (s2.size())
		{
			int val = s2.top().first;
			cout << val;
			s2.pop();
		}
		else
		{
			cout << "error";
		}
	}
	void front()
	{
		if (!s2.size())
		{
			move();
		}

		if (s2.size())
		{
			int val = s2.top().first;
			cout << val;
		}
		else
		{
			cout << "error";
		}
	}
	void sz()
	{
		cout << s2.size() + s1.size();
	}
	void clear()
	{
		while (!s1.empty()){
			s1.pop();
		}
		while (!s2.empty()){
			s2.pop();
		}

		cout << "ok";
	}
	void mn()
	{

		if ((s1.size() + s2.size()) == 0){
			cout << "error";
			return;
		}

		int mn1 = INT_MAX;
		int mn2 = INT_MAX;

		if (s1.size()){
			mn1 = s1.top().second;
		}
		if (s2.size()){
			mn2 = s2.top().second;
		}

		cout << min(mn1, mn2);
	}
};

int main(){
	int64_t n;
	Queue q;
	cin >> n;
	while (n){
		string s;
		cin >> s;
		if (s == "enqueue"){
			int k;
			cin >> k;
			q.enq(k);
		} else if (s == "dequeue"){
			q.deq();
		} else if (s == "front"){
			q.front();
		} else if (s == "size"){
			q.sz();
		} else if (s == "clear"){
			q.clear();
		} else if (s == "min"){
			q.mn();
		}
		cout << '\n';
		n--;
	}
	return 0;
}