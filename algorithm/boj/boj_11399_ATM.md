# boj 11399 ATM 

- 그리디 방법으로, 오름차순으로 정렬 후 이 순서대로 ATM을 이용하는 것이 최적해



```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <typeinfo>
#include <sstream>

using namespace std;

int N;
vector<int> v;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());


	for (int i = 1; i < N; i++)
	{
		v[i] = v[i] + v[i - 1];
	}

	int result = 0;
	for (auto num : v) result += num;

	cout << result;
	
	return 0;

}
```

