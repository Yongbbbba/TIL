lock based queue

```c++
#pragma once
#include <mutex>

template<typename T>
class LockQueue
{
public:
	LockQueue() {}
	LockQueue(const LockQueue&) = delete;
	LockQueue& operator=(const LockQueue&) = delete;

	void Push(T value)
	{
		lock_guard<mutex> lock(_mutex);
		_queue.push(std::move(value));
		_condVar.notify_one();
	}

	bool TryPop(T& value)
	{
		lock_guard<mutex> lock(_mutex);
		if (_queue.empty())
			return false;
		value = std::move(_queue.front());
		_queue.pop();
		return true;
	}

	void WaitPop(T& value)
	{
		unique_lock<mutex> lock(_mutex);
		_condVar.wait(lock, [this] {return _queue.empty() == false;});
		value = std::move(_queue.front());
		_queue.pop();
	}

private:
	queue<T> _queue;
	mutex _mutex;
	condition_variable _condVar;
};
```



lock based stack

```c++
#pragma once
#include <mutex>

template<typename T>
class LockStack
{
public:
	LockStack() {}
	LockStack(const LockStack&) = delete;  // 복사생성자 시도하면 막아버리기
	LockStack& operator=(const LockStack&) = delete;

	void Push(T value)
	{
		lock_guard<mutex> lock(_mutex);
		_stack.push(std::move(value));  // 더 빠른 연산을 위해서. move를 쓴다는거는 value를 rvalue로 만드는 것.
		_condVar.notify_one();  // 데이터 들어오면 스레드 하나 꺠운다.
	}

	bool TryPop(T& value)
	{
		// 기존의 방법에서는 stack이 비어있는지 확인한 후에 pop을 해주는데, 멀티스레드 환경에서는 empty를 확인 후에 pop을 하는 것이 의미가 없다. 진짜 empty인지 정확하지 않기 때문에.
		lock_guard<mutex> lock(_mutex);
		if (_stack.empty())
			return false;
		// empty -> top -> pop
		value = std::move(_stack.top());
		_stack.pop();
		return true;
	}

	void WaitPop(T& value)
	{
		unique_lock<mutex> lock(_mutex);
		_condVar.wait(lock, [this] {return _stack.empty() == false;});  // 데이터가 들어와서 notify_one을 호출하면 조건 체크해서 스택에 데이터가 들어온 것을 확인한 후에 일어나서 lock을 걸고 작업한다.
		value = std::move(_stack.top());
		_stack.pop();
	}


private:
	stack<T> _stack; 
	mutex _mutex;
	condition_variable _condVar;
};
```


main.cpp

```c++
#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <Windows.h>
#include <future>
#include "ConcurrentQueue.h"
#include "ConcurrentStack.h"

//queue<int32> q;  // 게임만들 때 스택보다 큐를 정말 많이 쓴다. 먼저 도착한 패킷을 먼저 처리해주는 것이 일반적이기 때문에.
//stack<int32> s;
LockQueue<int32> q;
LockStack<int32> s;

void Push()
{
	while (true)
	{
		int32 value = rand() % 100;
		q.Push(value);

		this_thread::sleep_for(10ms);
	}
}

void Pop()
{
	while (true)
	{
		int32 data = 0;
		if (q.TryPop(OUT data))
			cout << data << endl;
		
	}
}

int main()
{
	thread t1(Push);
	thread t2(Pop);

	t1.join();
	t2.join();
	
}

```

