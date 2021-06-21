접근하려고 하는 데이터에 lock이 걸려있다면 어떻게 할 것인가?

- 풀릴 때까지 자리에서 기다리는 방법 : spinlock
  - 왔다갔다(컨텍스트 스위치)하는 비용이 없어짐.
  - 컨텍스트 스위칭이 일어나서 비용이 든다.
    - 유저레벨에서 커널레벨로 권한이 왔다갔다 하는 것을 말함.
- 다른 할 일 하다가 일정 주기 또는 랜덤으로 다시 확인하는 방법 : sleep
- 다른 도구(리소스)를 활용해서 lock이 풀렸다는 소식을 듣고 오는 방법 : event



# spinlock

면접 단골 질문임, 멀티스레드를 잘 알고있는지 체크해볼 수 있는 질문이라고 볼 수 있다.

```c++
#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>

// spinlock 직접 구현해보기 
class SpinLock
{
public:
	void lock()
	{
		// CAS (Compare-And-Swap)
		// 변수의 예상값과 실제 값을 비교하여 둘의 값이 일치하면 실제값을 새로운 값으로 교체한다. 동시성 알고리즘을 설계할 때 사용하는 기술이다.
		bool expected = false;
		bool desired = true;


		// lock 획득에 실패했다면, 획득할 때까지 계속 루프
		// 계속 루프를 돌기 때문에 CPU 점유율이 높아지게된다. 다른 스레드에 CPU 소유권을 넘겨주지 않기 때문이다. 양날의 검을 가지고 있음.
		while(_locked.compare_exchange_strong(expected, desired) == false)
		{
			expected = false;  // 성공실패 여부와 관계없이 expected = locked를 실행하기 때문에 바꿔줘야함.
		}

		// lock 여부 체크와 lock하는 것이 atomic하게 일어나지 않기 때문에 원하는 결과를 얻지 못함.

		//while (_locked)
		//{

		//}
		//_locked = true;
	}

	void unlock()
	{
		//_locked = false;
		_locked.store(false);
	}

private:
	//volatile bool _locked = false;  // 컴파일러 최적화를 막는다. 사실 거의 활용할 일이 없음.
	atomic<bool> _locked = false;
};

int32 sum = 0;
mutex m;
SpinLock spinLock;

void Add()
{
	for (int32 i = 0; i < 10'0000; i++)
	{
		lock_guard<SpinLock> guard(spinLock);
		sum++;
	}
}

void Sub()
{
	for (int32 i = 0; i < 10'0000; i++)
	{
		lock_guard<SpinLock> guard(spinLock);
		sum--;
	}
}

int main()
{
	
	thread t1(Add);
	thread t2(Sub);

	t1.join();
	t2.join();

	cout << sum << endl;
	
}

```



# sleep

sleep을 사용해서 해당 스레드가 현재 time slice에 lock을 획득하지 못한다면 커널에 cpu 점유를 번환함. 이를 통해 cpu 점유가 쓸데없이 높아지는 것을 막을 수 있음.

하지만 컨텍스트 스위칭에 따른 비용이 증가하기 때문에 상황에 맞춰서 사용을 해야한다.

```c++
#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>

// spinlock 직접 구현해보기 
class SpinLock
{
public:
	void lock()
	{
		// CAS (Compare-And-Swap)
		// 변수의 예상값과 실제 값을 비교하여 둘의 값이 일치하면 실제값을 새로운 값으로 교체한다. 동시성 알고리즘을 설계할 때 사용하는 기술이다.
		bool expected = false;
		bool desired = true;


		// lock 획득에 실패했다면, 획득할 때까지 계속 루프
		// 계속 루프를 돌기 때문에 CPU 점유율이 높아지게된다. 다른 스레드에 CPU 소유권을 넘겨주지 않기 때문이다. 양날의 검을 가지고 있음.
		while(_locked.compare_exchange_strong(expected, desired) == false)
		{
			expected = false;  // 성공실패 여부와 관계없이 expected = locked를 실행하기 때문에 바꿔줘야함.

			// this_thread::sleep_for(std::chrono::milliseconds(100));
			this_thread::sleep_for(100ms);
			//this_thread::yield(); // 자기가 받은 time slice를 양보하겠다.
		}

		// lock 여부 체크와 lock하는 것이 atomic하게 일어나지 않기 때문에 원하는 결과를 얻지 못함.

		//while (_locked)
		//{

		//}
		//_locked = true;
	}

	void unlock()
	{
		//_locked = false;
		_locked.store(false);
	}

private:
	//volatile bool _locked = false;  // 컴파일러 최적화를 막는다. 사실 거의 활용할 일이 없음.
	atomic<bool> _locked = false;
};

int32 sum = 0;
mutex m;
SpinLock spinLock;

void Add()
{
	for (int32 i = 0; i < 10'0000; i++)
	{
		lock_guard<SpinLock> guard(spinLock);
		sum++;
	}
}

void Sub()
{
	for (int32 i = 0; i < 10'0000; i++)
	{
		lock_guard<SpinLock> guard(spinLock);
		sum--;
	}
}

int main()
{
	
	thread t1(Add);
	thread t2(Sub);

	t1.join();
	t2.join();

	cout << sum << endl;
	
}

```



#  event 

auto reset event : 문이 자동으로 잠긴다.

manual reset event : 문이 수동으로 잠긴다. 



## event가 필요한 상황 : 적용 전

```c++
#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>

mutex m;
queue<int32> q;

// 데이터 생산
void Producer()
{
	while (true)
	{
		{
			unique_lock<mutex> lock(m);
			q.push(100);
		}
		this_thread::sleep_for(100ms);
	}
}

// 데이터 소비(?)
void Consumer()
{
	// 만약 producer 쪽에서 데이터 생산 주기가 짧다면 이렇게 무한루프를 돌면서 기다리는게 매우 비효율적일 수 있다. 
	// 특히 아예 데이터를 넣는 일을 하지 않고 있다면 계속 루프 도는게 쓸데없이 CPU를 점유하게 된다.
    // 그렇기 때문에 데이터가 들어왔을 때 event를 사용해서 알려주는 방식으로 하면 효율적이게 된다.
	while (true)
	{
		unique_lock<mutex> lock(m);
		// 큐에 데이터가 있다면. 
		if (q.empty() == false)
		{
			int32 data = q.front();
			q.pop();
			cout << data << endl;
		}
	}
}

int main()
{
	thread t1(Producer);
	thread t2(Consumer);

	t1.join();
	t2.join();

	
}

```



## event 사용

 커널의 개입이 발생, 너무 빈번하게 일어나는 일이면 비효율적일 수 있음.

```c++
#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <Windows.h>

mutex m;
queue<int32> q;
HANDLE handle;

// 데이터 생산
void Producer()
{
	while (true)
	{
		{
			unique_lock<mutex> lock(m);
			q.push(100);
		}

		::SetEvent(handle);  // -> 시그널 상태를 바꿔줌. 데이터 들어왔다고 event로 알려주는 것임
		this_thread::sleep_for(100ms);
	}
}

// 데이터 소비(?)
void Consumer()
{
	// 만약 producer 쪽에서 데이터 생산 주기가 짧다면 이렇게 무한루프를 돌면서 기다리는게 매우 비효율적일 수 있다. 
	// 특히 아예 데이터를 넣는 일을 하지 않고 있다면 계속 루프 도는게 쓸데없이 CPU를 점유하게 된다.
	// 그렇기 때문에 데이터가 들어왔을 때 event를 사용해서 알려주는 방식으로 하면 효율적이게 된다.
	while (true)
	{
		::WaitForSingleObject(handle, INFINITE);  // 두 번째 인자로 대기시간. 만약 non-signal 상태라면 여기서 수면상태로 돌아가고, 시그널 상태면 이후의 코드를 실행하게 된다.
		unique_lock<mutex> lock(m);
		// 큐에 데이터가 있다면. 
		if (q.empty() == false)
		{
			int32 data = q.front();
			q.pop();
			cout << data << endl;
		}
	}
}

int main()
{
	// event 자체가 커널에서 만들어주는 오브젝트임
	// 일종의 번호표임. 이벤트가 한 두개가 아니니까.
	// 커널 오브젝트 : 커널에서 관리하는 오브젝트. 커널 객체를 관리하기 위해 할당되는 메모리가 있다.
	// Usage Count : 오브젝트를 몇 명이 사용하고 있는지 관리하는 상태
	// Signal(파란불) / Non-Signal(빨간불) << bool
	// Auto / Manual << bool

	handle = ::CreateEvent(NULL/*보안속성*/, FALSE/*bManualReset*/, FALSE/*bInitialState*/, NULL); // https://zadd.tistory.com/57

	thread t1(Producer);
	thread t2(Consumer);

	t1.join();
	t2.join();

	::CloseHandle(handle);
}

```



