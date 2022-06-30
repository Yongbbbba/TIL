# leetcode 1249 minimum remove to make vlid parenthese

- 못풀어서 인터넷에서 풀이를 보았다.
- 짝 안맞는 경우는 지워버리는 방법을 사용



## 풀이

```c++
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result = "";
        stack<int> st;
        
        // 짝이 안맞는 괄호는 s에서 지워버린다.
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    s[i] = '*'; // 지워버리기
                }
                else
                {
                    st.pop();
                }
            }
        }
        while (!st.empty())
        {
            int idx = st.top();
            s[idx] = '*';
            st.pop();
        }
        for (auto& c : s)
        {
            if (c == '*')
                continue;
            else
            {
                result += c;
            }
        }
        return result;
    }
};
```

