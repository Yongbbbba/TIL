# leetcode 125 valid Palindrome

- 매우 화나고 자괴감이 든 문제..  이거 푸는데 한 시간 걸린거 같다.
- 문제를 제대로 읽지 않았다.. 알파벳 뿐만 아니라 숫자인 경우도 고려했어야 했는데 알파벳만 고려해서 자꾸 오답이 나왔다.
- 몇 번을 풀어봤던 팰린드롬인데 허우적거려서 매우 큰 자괴감..



## 코드

```python
class Solution(object):
    def isPalindrome(self, s):
        target = ''
        for c in s:
            if c.isalpha() or c.isdigit():
                target += c
        if len(target) <= 1:
            return True
        start = 0
        end = len(target) -1
        while (start < end):
            if target[start].lower() != target[end].lower():
                return False
            else:
                start += 1
                end -= 1
        return True
```

