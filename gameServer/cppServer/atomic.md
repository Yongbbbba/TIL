```c++
#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>

// atomic atom(원자) : All-Or-Nothing
// atomic을 사용하면 연산이 생각보다 느리기 때문에 atomic으로 범벅하면 안되고 꼭 필요한 경우에 이렇게 해야한다.
atomic<int32> sum = 0;

void Add()
{
	for (int32 i = 0; i < 100'000; i++)
	{
		sum.fetch_add(1);
		//sum++;
	}
}

void Sub()
{
	for (int32 i = 0; i < 100'000; i++)
	{
		sum.fetch_add(-1);
		//sum--;
	}

}

int main()
{
	Add();
	Sub();
	cout << sum << endl;

	std::thread t1(Add);
	std::thread t2(Sub);
	t1.join();
	t2.join();

	cout << sum << endl; 

}

```

