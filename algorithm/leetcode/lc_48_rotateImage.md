# lc 48 rotate image

- 요구사항에서는 임시 배열을 선언하지 말고 in-place로 rotate하라고 했는데 그렇게 이행하지 못함

## 첫 번째 코드 

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp;
        temp.reserve(matrix.size());
        for (int j=0; j < matrix.size(); j++)
        {
            vector<int> row;
            for (int i=matrix.size()-1; i>=0; i--)
            {
                row.push_back(matrix[i][j]);
            }
            temp.push_back(row);
        }
        matrix = temp;
        return;
    }
};
```



## in-place 코드

- 설명을 계속 봤는데 이해하는데 한참 걸렸다. 기존 행과 열과 새로운 행과 열 사이의 규칙을 뽑아내기가 어려웠다. 180도, 270도는 어떻게 규칙을 뽑아낼 것인지 생각할 필요가 있다.

```c++
class Solution {
public:
    pair<int,int> NewCoord(vector<vector<int>>& matrix, int x, int y)
    {
        pair<int,int> result;
        int newX = y;
        int newY = -x + matrix.size() - 1;
        result.first = newX;
        result.second = newY;

        return result;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        
        for (int i=0; i<matrix.size()/2; i++)
        {
            for (int j=0; j<(matrix.size()+1)/2; j++)
            {
                pair<int,int> new_1 = NewCoord(matrix, i, j);
                pair<int,int> new_2 = NewCoord(matrix, new_1.first, new_1.second);
                pair<int,int> new_3 = NewCoord(matrix, new_2.first, new_2.second);
                
                
                int tempValue = matrix[i][j];
                matrix[i][j] = matrix[new_3.first][new_3.second];
                matrix[new_3.first][new_3.second] =  matrix[new_2.first][new_2.second];
                matrix[new_2.first][new_2.second] = matrix[new_1.first][new_1.second];
                matrix[new_1.first][new_1.second] = tempValue;
                
            }
        }
        
        return;
    }
};
```

