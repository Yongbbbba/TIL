// [바킹독의 실전 알고리즘] 0x03강 - 배열
// insert와 erase 구현해보기
// insert를 temp를 복사해서 사용했는데 메모리랑 연산 낭비임.

#include <bits/stdc++.h>
using namespace std;

void insert(int idx, int num, int arr[], int& len){
    int temp_size = len-1 - idx;
    int temp[temp_size];
    for (int i=idx, j=0; i<len; i++, j++)  temp[j] = arr[i];
    arr[idx] = num;
    len++;
    for (int i=idx+1, j=0; i<len; i++, j++) arr[i] = temp[j];
}

void erase(int idx, int arr[], int& len){
  for (int i=idx+1; i<len; i++) arr[i-1] = arr[i];
  len--;
}

void printArr(int arr[], int& len){
  for(int i = 0; i < len; i++) cout << arr[i] << ' ';
  cout << "\n\n";
}

void insert_test(){
  cout << "***** insert_test *****\n";
  int arr[10] = {10, 20, 30};
  int len = 3;
  insert(3, 40, arr, len); // 10 20 30 40
  printArr(arr, len);
  insert(1, 50, arr, len); // 10 50 20 30 40
  printArr(arr, len);
  insert(0, 15, arr, len); // 15 10 50 20 30 40
  printArr(arr, len);
}

void erase_test(){
  cout << "***** erase_test *****\n";
  int arr[10] = {10, 50, 40, 30, 70, 20};
  int len = 6;
  erase(4, arr, len); // 10 50 40 30 20
  printArr(arr, len);
  erase(1, arr, len); // 10 40 30 20
  printArr(arr, len);
  erase(3, arr, len); // 10 40 30
  printArr(arr, len);
}

int main(void) {
  insert_test();
  erase_test();
}