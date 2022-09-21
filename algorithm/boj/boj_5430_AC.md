# boj 5430 AC

- 처음에는 시간초과가 났다. R이 나오면 deque을 실제로 reverse해서 나오는 문제였다. 현재 상태가 reverse상태인지 아닌지 체크하는 flag를 두고 reverse이면 pop_back()을, 아니면 pop_front()를 하고, 마지막에  reverse 상태일 때 실제 reverse를 한다. 
- 그리고 계속 해서 오답이 나와서 한참 반례를 찾았는데, error를 ERROR로 출력해서 오답이 나왔다. 어이가 없다. 문제를 잘 읽고 요구사항에 맞게 구현하자.



## 코드

```c++
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;

	cin >> t; 
	while (t--)
	{
		deque<int> dq;
		string op;
		int n;
		string arr;
		cin >> op;
		cin >> n;
		cin >> arr;

		string temp = "";

		int rev = 0; // 0 이면 원래 방향 

		for (auto& c : arr)
		{
			if (c == ',' || c == '[' || c == ']')
			{
				if (temp.length() != 0)
				{
					int num = stoi(temp);
					dq.push_back(num);
					temp = "";
				}
				continue;
			}
			temp += c;
		}

		bool isError = false;

		for (auto& c : op)
		{
			if (c == 'R')
			{
				rev = 1 - rev; // 1은 reverse상태 
			}
			else
			{
				if (dq.empty())
				{
					cout << "error" << endl;
					isError = true;
					break;
				}
				else
				{
					if (rev == 0)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}
		if (isError)
			continue;
		if (rev)
			reverse(dq.begin(), dq.end());

		cout << "[";
		for (auto it = dq.begin(); it != dq.end(); it++)
		{
			if (it != dq.begin())
			{
				cout << ",";
			}
			cout << *it;
		}
		cout << "]" << endl;
	}

	return 0;
}
```

