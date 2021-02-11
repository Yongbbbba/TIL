# 코드

```cpp
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    
    cin >> T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        bool run = false;
        bool trip = false;
		int nums[6];
        int num;
        cin >> num;
        for (int i=0; i<6; i++) {
            nums[i] = num % 10;
            num = num / 10;
        }
        // 카운팅
        int count[10]= {0,};
        for (int i=0; i<6; i++) {
            count[nums[i]]++;
        }
        //run 체크
        for (int i=0; i<10; i++ ) {
            if (count[i] >=3 ) {
                run = true;
                count[i] -= 3;
            }
        }
        // triplet 체크
        for (int i=0; i<8; i++) {
            if (count[i] && count[i+1] && count[i+2]) trip = true;
        }
		
        if (run &&  trip) cout << "#" << test_case << ' ' << "Baby Gin"<< '\n';
        else cout << "#" << test_case << ' ' << "Lose"<< '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```



- 한 시간 넘게 붙잡고 있었는데 도저히 모르겠어서(수업을 열심히 안들음) 검색을 해보니까 카운팅을 사용하는 것을 발견하였다. 힌트를 얻어서 구현해볼 수 있었다..
- 처음에는 트리를 써야하나 싶기도 하고(하지만 구현할 줄 모름), 한 번 셌던 숫자는 어떻게 빼줘야하나 고민을 했으나 답을 못 찾았다. 그리고 처음에는 주어진 숫자 정렬 그대로 체크하는 줄 알았는데 정렬해야되는 것을 나중에 알았다.
- 처음에 계속 런타임 에러도 나고 시간 초과도 나고 그랬다. 그 이유는 인풋을 잘못 받아서였다. '456789' 이런 식으로 들어왔는데 이게 띄어쓰기가 된 것도 아니고 캐리지 리턴도 있던게 아니라서 그냥 통으로 입력 받아서 나눠가면서 배열에 입력해줬어야 했다. 이걸 안해서 삽질을 하고 있었다.
- 탐욕 알고리즘과 정렬 알고리즘을 선행해서 공부해야겠다.