# lc 680 valid palindrome 2

- 백트래킹으로 풀이했는데 속도가 좋지 못함
- anotherChecker에서 string 레퍼런스로 받지 않으면 속도가 현저히 느려짐

```c++
class Solution {
public:
    bool result = false;
    bool validPalindrome(string s) {
        anotherChecker(s, 0, s.length()-1, false);
        return result;
    }
    void anotherChecker(string& s, int left, int right, bool flag)
    {
        if (left >= right)
        {
            result = true;
            return;
        }
        if (s[left] == s[right])
            anotherChecker(s, left+1, right-1, flag);
        else
        {
            if (flag)
                return;
            anotherChecker(s, left + 1, right, true);
            anotherChecker(s, left, right-1, true);
        }
    }
};

```

##  iter로 다시 풀이

- 아래 코드가 문제의 요구사항인 delete at most one을 어떻게 충족하는건지 한참을 고민했었다. 만약 `s[left] != s[right]`의 상황에서 left+1을 하거나 right-1을 해서 checkPelindrome을 하기 때문에 자연스럽게 at most one을 충족할 수 있게 되는 것이었다. 위에 백트래킹 코드에서는 flag를 둬서 at most one을 해결하려 했는데 훨씬 간단하게 할 수 있었다. 그리고 at flag문제 때문에 나는 iter로 짜지 못하고 백트래킹으로 짰었다.

```c++
class Solution {
public:
   
    bool validPalindrome(string s) {
        
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right)
        {
            if (s[left] != s[right])
                return checkPalindrome(s, left+1, right) || checkPalindrome(s, left, right-1);
            left++;
            right--;
        }
        return true;
    }
    bool checkPalindrome(string s, int left, int right)
    {
        while (left < right)
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

