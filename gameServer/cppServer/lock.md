```c++
#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>

vector<int32> v;  // STL 자료구조는 멀티스레드 환경에서 제대로 동작하지 않는다고 기본적으로 생각해줘함. 

// Mutual Exclusive (상호배타적)
mutex m;

// RAII (Resource Acquisition is Initialization)
// 생성자에서 잠그고 소멸자에서 풀어주는 패턴
template<typename T>
class LockGuard
{
public:
	LockGuard(T& m)
	{
		_mutex = &m;
		_mutex->lock();
	}

	~LockGuard(T& m)
	{
		_mutex->unlock();
	}
private:
	T* _mutex;
};

void Push()
{
	// lock을 여기다 걸 수도 있는데, 락 범위에 따라 기능이 많이 달라진다. 이런 것을 상황에 맞게 평가해서 범위를 정해야한다. 
	for (int32 i = 0; i < 10000; i++)
	{
		// 자물쇠 잠그기
		// m.lock();  // 재귀적 호출 불가

		// LockGuard<std::mutex> lockGuard(m); // 객체를 만드는 부하가 있을 수는 있지만 더 안전한 코드를 만들 수 있게 된다. 
		std::lock_guard<std::mutex> lockGuard(m);  // lock_quard 내장되어있음 
		std::unique_lock<std::mutex> uniqueLock(m, std::defer_lock);  // loack_guard와 같은 기능을 하고 있지만 defer 옵션을 줘서 lock하는 시점을 정할 수 있음.

		uniqueLock.lock();

		v.push_back(i);

		if (i == 5000)
		{
			break;
		}



		// 자물쇠 풀기
		// m.unlock();  // 재귀적 호출 불가

		// lock을 하면 다른 스레드에서 접근을 못하기 때문에 싱글 스레드처럼 동작하게 된다.
	}
}

int main()
{
	// Double free 문제 발생!
	std::thread t1(Push); 
	std::thread t2(Push);

	t1.join();
	t2.join();

	cout << v.size() << endl; 
}

```

