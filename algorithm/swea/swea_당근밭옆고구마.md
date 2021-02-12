# 코드

- 스파게티 코드가 되어버림
- 내 머리에서 struct를 사용할 생각이 나왔다는게 참으로 기특.
- 로직을 생각하는데는 시간이 오래 걸리지 않았는데, 긴 줄기를 찾는 마지막 for문에서 실수가 나와서 오래걸림 + 마지막 항에서 예외처리를 해주지 않아서.

```c++
#include<iostream>
#include <vector>
 
using namespace std;
 
struct Sweat {
    int sweat_size;
    int stem_length;
};
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
     
    for(test_case = 1; test_case <= T; ++test_case)
    {
 
        int N;
        cin >> N;
        int sweat_guys[1000];
        for (auto i=0; i<N; i++) {
            cin >> sweat_guys[i];
        }
         
        int sweat_size = sweat_guys[0]; // 달린 고구마양
        int stem_length = 1 ; // 줄기 길이
         
        vector<Sweat> long_stem_arr;
         
        for (auto i=1; i<N; i++) {
            // 긴 줄기인지 체크
            // 이전 항보다 커졌으면 줄기 길이를 늘리고 줄기에 달린 고구마 양을 늘림
            
            if (sweat_guys[i] > sweat_guys[i-1]) {
                 
                stem_length++;
                sweat_size += sweat_guys[i];
            
            // else 문에서 long_stem_arr에 긴 줄기를 넣고 있는데 이렇게 되면 마지막항의 경우에는 포함할 수 없으므로 예외처리 해줌. -> 스파게티 코드...?  
                
                if ( i == N-1) {
                Sweat temp;
                temp.stem_length = stem_length;
                temp.sweat_size  =sweat_size;
                long_stem_arr.push_back(temp);
                }
                        // 긴 줄기가 아니라면 이전까지의 긴 줄기를 long_stem_arr에 넣는다. 애초에 이전 항이 긴 줄기가 아니었으면 넣지 않는다.
                // 그러고 stem_length와 sweat_size를 초기화
            } else {
                if (stem_length > 1) {
                Sweat temp;
                temp.stem_length = stem_length;
                temp.sweat_size  =sweat_size;
                long_stem_arr.push_back(temp);
                }    
                stem_length = 1;
                sweat_size = sweat_guys[i];   
            }
        }
         
        int max_stem_length = 0;
        int max_sweat_size = 0;
        for (auto stem : long_stem_arr) {
            // 가장 긴 줄기인지 체크
            if (stem.stem_length > max_stem_length) {
                max_stem_length = stem.stem_length;
                max_sweat_size = stem.sweat_size; // 이 부분을 max_sweat_size = sweat_size 라고 해놔서 계속 오답이 나옴. 이래놓고 자꾸 저 위에서 문제해결을 할라고 붙들고 있었음 
            } 
            // 만약 줄기 길이가 같으면 고구마 양 비교 
            else if (stem.stem_length == max_stem_length) {
                if (max_sweat_size < stem.sweat_size) max_sweat_size = stem.sweat_size;
            }
        }
    cout << "#" << test_case << ' ' << long_stem_arr.size() << ' ' << max_sweat_size << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

