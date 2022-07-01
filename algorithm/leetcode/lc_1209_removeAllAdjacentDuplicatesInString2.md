# leetcode 1209. Remove All Adjacent Duplicates in String II

- 그 문자가 연속해서 나온 숫자를 넣어주는 stack을 하나 더 사용



## 코드

```c++
class Solution {
public:
    string removeDuplicates(string s, int k) {
        string temp = "";
        string result = "";
        stack<char> cs;
        stack<int> is;
        
        for (auto& c : s)
        {
            if (cs.empty() || cs.top() != c)
            {
                cs.push(c);
                is.push(1);
            }
            else if (is.top() < k - 1)
            {
                int tmp  = is.top();
                is.pop();
                is.push(tmp+1);
                cs.push(c);
            }
            else
            {
                while (!cs.empty() && cs.top() == c && is.top() >= k - 1)
                {
                    cs.pop();
                }
                if (is.top() == k - 1)
                {
                    is.pop();
                }
                else
                {
                    int tmp = is.top() - k;
                    is.pop();
                    is.push(tmp);
                    cs.push(c);
                }
            }
        }
        while(!cs.empty())
        {
            temp += cs.top();
            cs.pop();
        }
        for (int i=temp.length()-1; i >= 0; i--)
        {
            result += temp[i];
        }
        return result;
    }
};
```

