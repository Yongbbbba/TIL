# TIL (Today I Learned)

- 오늘 배우고 공부한 내용들을 차곡차곡 정리하는 공간입니다.
- 2021.01.15 ~ ing
- 일부 TIL은 [블로그](https://yongbbbba.github.io/)에 올리는 중입니다. (2021.01 ~ ing)
- 모든 TIL이 블로그에 다 올라가고 있지는 않습니다. 공부하며 작성한 코드의 일부는 이 repo에 올라옵니다.



## 디렉토리 구조

```sh
└─TIL/
   │
   ├─git/ 		// git 공부 내용
   │
   ├─cpp/ 		// c++ 공부 내용 
   │  └─ cppConquer/ 		// 모두의코드 블로그의 '씹어먹는 C++' 공부 코드
   │          ├─ dataCal/ 		// 날짜 계산기 실습
   │          └─ stringClass/     // stirng 클래스 만들어보기 실습
   │
   ├─algorithm/            // 알고리즘 풀이 코드 및 고민과 사투, 특이사항 정리
   │        ├─ boj // 백준 문제
   │        ├─ swea // sw expert academy 문제
   │        └─ leetcode // leetcode 문제
   │
   └─.gitignore 
```



## 씹어먹는 C++ (2021-01-29 ~ ing)

- 모두의 코드 블로그의 '씹어먹는 C++'를 보며 공부한 코드들의 모음.
- C++ 언어의 특징, 문법, CS의 공부와 문제해결력을 기르기 위해 해당 콘텐츠를 활용하고 있습니다.



### 생각해보기 실습

#### 개발환경

- ~~Ubuntu-20.04 (WSL2)~~
- ~~g++ -std=c++17~~
- ~~vim~~    
- Windows 10
- Visual Studio 2019

#### 실습 목록
- [날짜 계산기 만들기](https://yongbbbba.github.io/til/dateCalulator/) 
- [string 클래스 구현(~ing)](cpp/cppConquer/stringClass/string.md)
  - find의 경우 문자열 알고리즘을 적용해서 다시 구현해볼 예정입니다.
  - compare는 아직 쓰임새 자체를 몰라서 수업 코드만 클론해봤습니다. 나중에 다시 구현해볼 예정입니다.



## 알고리즘 문제 풀이 정리(2021-02 ~ ing )

- 백준, 삼성소프트웨어아카데미, leetcode 등에서 문제를 풀고 코드를 정리, 문제를 푸는 과정과 고민했던 부분, 특이사항, 배운 부분을 정리 중입니다.
- 주 사용 언어 : C++, Python
- 백준에서는 주로 C++,  SWEA에서는 PYthon으로 풀이중. 수업에서 python으로 문제를 풀기 때문... 그리고 IM형 테스트나 각종 내부 평가도 python으로 푸는게 맘 편할 것 같기 때문이다. 사실 요즘 C++를 코테용 주력으로 사용해도 되는건가 고민이긴 하다. 구현 속도가 아무래도 파이썬보다는 느리기 때문이고 아직 문법적인 이해도가 파이썬만큼 높지는 않기 때문이다.