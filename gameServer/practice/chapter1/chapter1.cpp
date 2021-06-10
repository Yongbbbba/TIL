#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <memory>
#include <mutex>
#include <Windows.h>
#include <process.h>


using namespace std;
const int MaxCount = 15000;
const int ThreadCount = 4;

//class CriticalSection
//{
//	CRITICAL_SECTION m_critSec;
//public:
//	CriticalSection();
//	~CriticalSection();
//
//	void Lock();
//	void Unlock();
//};
//
//class CriticalSectionLock
//{
//	CriticalSection* m_pCritSec;
//public:
//	CriticalSectionLock(CriticalSection& critsec);
//	~CriticalSectionLock();
//
//};
//
//CriticalSection::CriticalSection()
//{
//	InitializeCriticalSectionEx(&m_critSec, 0, 0);
//}
//
//CriticalSection::~CriticalSection()
//{
//	DeleteCriticalSection(&m_critSec);
//}
//
//void CriticalSection::Lock()
//{
//	EnterCriticalSection(&m_critSec);
//}
//
//void CriticalSection::Unlock()
//{
//	LeaveCriticalSection(&m_critSec);
//}
//
//CriticalSectionLock::CriticalSectionLock(CriticalSection& critSec)
//{
//	m_pCritSec = &critSec;
//	m_pCritSec->Lock();
//}
//
//CriticalSectionLock::~CriticalSectionLock()
//{
//	m_pCritSec->Unlock();
//}

bool IsPrimeNumber(int number)
{
	if (number == 1)
		return false;
	if (number == 2 || number == 3)
		return  true;
	for (int i = 2; i < number - 1; i++)
	{
		if ((number % i) == 0)
			return false;
	}
	return true;
}

void PrintNumbers(const vector<int>& primes)
{
	for (int v : primes)
	{
		cout << v << endl;
	}
}

int main()
{
	// 각 스레드는 여기서 값을 꺼내 온다.
	int num = 1;
	recursive_mutex num_mutex;

	vector<int> primes;
	recursive_mutex primes_mutex;

	auto t0 = chrono::system_clock::now();

	// 작동할 워커 스레드
	vector<shared_ptr<thread>> threads;

	for (int i = 0; i < ThreadCount; i++)
	{
		shared_ptr<thread> thread(new thread([&]() {
			// 각 스레드의 메인 함수
			// 값을 가져올 수 있으면 루프를 돈다.
			while (true)
			{
				int n;
				{
					lock_guard<recursive_mutex> num_lock(num_mutex);
					n = num;
					num++;
					// 작업을 마치면 자동으로 unlock
				}

				if (n >= MaxCount) break;

				if (IsPrimeNumber(n))
				{
					lock_guard<recursive_mutex> primes_lock(primes_mutex);
					primes.push_back(n);
				}
			}
		}));
		// 스레드 객체를 일단 갖고 있는다.
		threads.push_back(thread);
	}

	// 모든 스레드가 일을 마칠 때까지 기다린다.
	for (auto thread : threads)
	{
		thread->join();
	}

	// 끝

	auto t1 = chrono::system_clock::now();

	auto duration = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();
	cout << "Took " << duration << " milliseconds." << endl;

	return 0;
}
