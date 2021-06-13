# leetcode 36 valid sudoku

- 스도쿠를 만드는 문제가 아니라서 간단한 구현 문제라고 봐도 될 것 같다.
- 보드가 크지 않기 때문에 완전 탐색으로 해도 크게 무리가 없음



## 코드

```python
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # 행 체크
        for i in range(9):
            isChecked = [0] * 10
            for j in range(9):
                if board[i][j].isdigit():
                    isChecked[int(board[i][j])] += 1
            
            if max(isChecked) >= 2:
                return False
            
        # 열 체크
        for j in range(9):
            isChecked = [0] * 10
            for i in range(9):
                if board[i][j].isdigit():
                    isChecked[int(board[i][j])] += 1
            
            if max(isChecked) >= 2:
                return False
            
        # 3*3 체크
        
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                isChecked = [0] * 10
                for r in range(i, i+3):
                    for c in range(j, j+3):
                        if board[r][c].isdigit():
                            isChecked[int(board[r][c])] += 1
                if max(isChecked) >= 2:
                    return False
        
        return True
```

