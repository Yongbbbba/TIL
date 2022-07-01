# leetcode 1047 remove all adjacent duplicates in string

- 스스로 풀긴 했는데 좀 시간이 오래 걸림
- 문자열 뒤집기 말고 저번에 풀었던 것처럼 중복 문자열을 '*'과 같은 것으로 지워버리는 것도 방법이지 않을까

## 코드

```c++
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string temp = "";
        string result = "";
        
        for (auto& c : s)
        {
            if (st.empty() || st.top() != c)
            {
                st.push(c);
            }
            else
            {
                while(!st.empty() && st.top() == c)
                {
                    st.pop();
                }
            }
        }
        while (!st.empty())
        {
            temp += st.top();
            st.pop();
        }
        for (int i = temp.length()-1; i >= 0; i--)
        {
            result += temp[i];
        }
        return result;
    }
};
```

