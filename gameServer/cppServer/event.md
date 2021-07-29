```c++
#include "pch.h"
#include <iostream>

#include <Windows.h>
#include <mutex>
#include <Lock.h>

mutex m;
queue<int32> q;
HANDLE handle;

void Producer()
{
	while (true)
	{
		{
			unique_lock<mutex> lock(m);
			q.push(100);

		}

		::SetEvent(handle);  // -> signal 상태로 바꿔주세요
		this_thread::sleep_for(10s);
	}
}

void Consumer()
{
	while (true)
	{
		::WaitForSingleObject(handle, INFINITE);  // auto reset으로 설정해두면, signal ->  non-signal로 자동으로 바꿔줌
		unique_lock<mutex> lock(m);
		if (!q.empty())
		{
			int32 data = q.front();
			q.pop();
			cout << data << endl;
		}
	}
}

int main()
{
	// 커널 오브젝트
	// Usage Count
	// Signal / Non-Signal << bool 
	// Auto / Manual  << bool
	handle = ::CreateEvent(NULL/*보안속성*/, FALSE/*bManualReset*/, FALSE/*bInitialState*/, NULL);

	thread t1(Producer);
	thread t2(Consumer);

	t1.join();
	t2.join();

	::CloseHandle(handle);
}
```

