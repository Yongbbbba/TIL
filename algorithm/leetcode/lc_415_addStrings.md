# lc 415 add strings

- 이게 뭐라고 거의 한 시간을 소모해서 푼 것일까.. 처참하다

```c++
class Solution {
public:
    string addStrings(string num1, string num2) {
        int idx1 = num1.length() - 1;
        int idx2 = num2.length() - 1;
        int carry = 0; 
        vector<char> sum;
        string result;

        while (idx1 != -1 && idx2 != -1)
        {
            int tempSum = charToNum(num1[idx1]) + charToNum(num2[idx2]) + carry;
            carry = tempSum / 10;
            sum.push_back(numToChar(tempSum % 10));
            idx1--;
            idx2--;
        }
        
        if (idx1 > idx2)
        {
            while (idx1 != -1)
            {
                int tempSum = charToNum(num1[idx1]) + carry;
                carry = tempSum / 10;
                sum.push_back(numToChar(tempSum % 10));
                idx1--;
            }
        }
        else if (idx1 < idx2)
        {
            while (idx2 != -1)
            {
                int tempSum = charToNum(num2[idx2]) + carry;
                carry = tempSum / 10;
                sum.push_back(numToChar(tempSum % 10));
                idx2--;
            }
        }
        if (carry == 1)
        {
            sum.push_back(numToChar(carry));
        }
        
        for (int i = sum.size() -1; i != -1; i--)
        {
            result += sum[i];
        }
        
        return result;
    }

    int charToNum(char num)
    {
        return num - '0';
    }
    char numToChar(int num)
    {
        return num + '0';
    }
};

```

