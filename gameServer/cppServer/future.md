```c++
#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <Windows.h>
#include <future>

// 여러 스레드에서 통신을 할 때 조건변수는 유용하게 사용된다는 것을 살펴보았다.
// 하지만 경우에 따라 좀더 가벼운 상황, 단발성 이벤트 상황에서는 조건 변수까지 사용안하고 더 가벼운 방법이 존재하는데 그것이 future
// 활용도가 좀 떨어지는 부분이긴 하지만 c++11에 추가된 내용이기 때문에 짚고 넘어간다.

int64 result;

int64 Calculate()
{
	int64 sum = 0;
	for (int32 i = 0; i < 100'0000; i++)
		sum += i;

	result = sum;

	return sum;
}

void PromiseWorker(std::promise<string>&& promise)
{
	promise.set_value("Secret Message");
}

void TaskWorker(std::packaged_task <int64(void)>&& task)
{
	task();
}

int main()
{
	// 동기(synchronous)실행
	// 만약 Calculate 작업이 엄청 오래 걸리는 작업이라면 이것이 계산될 때까지 main 함수는 다른 작업을 못하고 여기서 멈추게 된다.
	//int64 sum = Calculate();
	//cout << sum << endl;

	// std::future
	{
		// 1) deferred  -> lazy evaluation 지연해서 실행하세요
		// 2) async -> 별도의 스레드를 만들어서 실행하세요
		// 3) deferred | async  -> 둘 중 알아서 골라주세요
		std::future<int64> future = std::async(std::launch::async, Calculate); // async를 활용하면 사실상 멀티스레드 환경이 된다.
		// 결과물을 바로 받을 필요가 없는 상황이라고 가정하고 nonblock으로 todo를 실행하게 된다.
		// TODO
		//std::future_status status = future.wait_for(1ms);  // future 작업이 완료됐는지 확인하는 기능
		//if (status == future_status::ready)
		//{

		//}
		
		int64 sum = future.get(); //  결과물이 이제서야 필요하다!

		// future: 언젠가 미래에 결과물을 뱉어줄거야!

	}

	// std::promise    -> future 객체를 만드는 두 번쨰 방법
	{
		// 미래에(std::future) 결과물을 반환해줄거라 약속(std::promise)해줘 ~ (계약서? )
		std::promise<string> promise;
		std::future<string> future = promise.get_future();  // 무전기 같이 promise와 future가 연동된 상태 같이 됨.

		thread t(PromiseWorker, std::move(promise));  // 메인->새로만든 스레드로promise의 소유권을 넘김
		string message = future.get();
		cout << message << endl;
		t.join();
		
		// 스레드끼리 데이터를 주고받을 때 전역변수를 사용하는 방법보다는 promise와 future가 더 깔끔하다. 
	}

	// std::packaged_task
	{
		std::packaged_task<int64(void)> task(Calculate);
		std::future<int64> future = task.get_future();

		std::thread t(TaskWorker, std::move(task));

		int64 sum = future.get();
		cout << sum << endl; 

		t.join(); 
	}

	// 결론)
	// mutex, condition_variable 까지 가지 않고 단순한 애들을 처리할 수 있는 방법
	// 특히나, 한 번 발생하는 이벤트에 유용하다
	// 1) async
	// 원하는 함수를 비동기적으로 실행한다
	// 2) promise
	// 결과물을 promise를 통해 future로 받아줌
	// 3) packaged_task
	// 원하는 함수의 실행결과를 packaged_task를 통해 future로 받아줌

	// 실무에서 promise, packaged_task를 사용하는 경우 본 적이 없음. async를 유용하게 쓸 수 있음.

}

```

