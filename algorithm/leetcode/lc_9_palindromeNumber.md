# lc 9 palindrome number

##  int to string 으로 convert해서 풀이 

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        // 음수면 팰린드롬일 수 없음
        if (x < 0)
            return false;
        // 일단 convert to string method
        string s = to_string(x);
        int left = 0;
        int right = s.length() - 1;
        while(left <= right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
```



## convert 없이 풀이

- 꽤 헤맸음

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        // 음수면 팰린드롬일 수 없음
        if (x < 0)
            return false;
        if ((x / 10) == 0)
            return true;
        // integer의 자릿수 구하기
        int n = 0;
        int temp = x;
        while (temp > 0)
        {
            n++;
            temp /= 10;
        }
        int left = pow(10, n-1);
        int right = 10;
        while (left > 0)
        {
          
            int one = x / left;
            int another = x % right;
          
            if (one != another)
                return false;
            x %= left;
            x /= 10;
            left /= 100;
            cout << endl;
        }
        return true;
    }
};
```

