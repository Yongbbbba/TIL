# chapter4 02 ABI와 표준

![image-20220122221349593](../../AppData/Roaming/Typora/typora-user-images/image-20220122221349593.png)

## ABI(Application Binary Interface)

- 응용 프로그램 바이너리 인터페이스
- 함수 실행 방식, 레지스터 활용, 시스템 콜 실행, 라이브러리 링크 방식 등
  - 쉽게 말해서 예를 들면, 응용 프로그램과 라이브러리 사이에서 연결/통신을 어떻게 할 것인지 방식을 정하는 것
  - 윈도우 실행 프로그램을 리눅스에서 돌리지 못하는 이유 -> ABI가 다르고, 라이브러리가 다르기 때문에.. 
- ABI와 호환되면 재컴파일없이 동작
- 컴파일러, 링커(라이브러리 링크), 툴체인(컴파일러를 만드는 프로그램)에서 제공



## POSIX

- 유닉스 시스템 프로그래밍 인터페이스 표준
- IEEE(Institute of Eletronic and Eletronics Engineers)에서 표준화 시도
- 리차드 스톨만(자유 소프트웨어 재단)이 POSIX를 표준안 이름으로 제안



## C 언어 표준

- 다양한 C 언어 변종 존재

- ANSI(American National Standards Institute)에서 ANSI C 표준 정립

  > 리눅스는 POSIX와 ANSI C 지원



## 시스템 프로그래밍과 버전

- 끊임없는 POSIX, C, C++ 표준 업데이트

- 끊임없는 소프트웨어 업데이트

- 프로그래밍 트렌드와 상관없이 시스템 레벨단 기술은 유지되고, 필요함

  > 상위 레벨 프로그래밍을 할지라도, 하위 시스템 레벨을 알고 있으면, 더 나은 또는 성능이 개선된 소프트웨어 개발 가능

