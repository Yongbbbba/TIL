# chapter4 01 시스템콜과 API



## 시스템 프로그래밍의 기반 요소

- 시스템 콜(system call)
- C 라이브러리
- C 컴파일러

> 사용자 영역에서의 시스템 프로그래밍



## 시스템 콜

- 시스템 콜: 운영체제 리소스나 서비스 요청을 위해, 사용자 영역에서 커널 영역으로 들어가는 함수
- 주요 시스템 콜: read(), write(), open() 등

> 리눅스/유닉스는 C언어로 만들어져있으므로, 시스템콜도 C언어로 구현



### 시스템 콜은 어떻게 구현? 

- eax 레지스터에 시스템 콜 번호를 넣고,

- ebx 레지스터에는 시스템 콜에 해당하는 인자값을 넣고,

- 소프트웨어 인터럽트 명령을 호출하면서 0x80값을 넘겨줌

  - CPU는 사용자 모드를 커널 모드로 바꿔줌
  - IDT(Interrupt Descriptor Table)에서 0x80에 해당하는 주소(함수)를 찾아서 실행함(Program Counter에 주소를 넣어줘서 거기서부터 시작)
  - system_call() 함수에서 eax로부터 시스템 콜 번호를 찾아서, 해당 번호에 맞는 시스템콜 함수로 이동
  - 해당 시스템콜 함수 실행 후, 다시 커널 모드에서 사용자 모드로 변경하고, 다시 해당 프로세스 다음 코드 실행

  ```assembly
  mov eax, 1
  mov ebx, 0 // (시스템 콜도 결국 함수니까 인자를 넣어줘야함)
  int 0x80 // 소프트웨어 인터럽트 명령 (instruction code -> cpu가 제공)
  ```

  ![image-20220122215356003](../../AppData/Roaming/Typora/typora-user-images/image-20220122215356003.png)

## C 라이브러리

- 유닉스 C 라이브러리 - libc
- 리눅스 C 라이브러리 - GNU libc- glibc(지립씨, 글립씨)
  - 시스템콜, 시스템콜 래퍼, 기본 응용 프로그램 기능 포함



## C 컴파일러 

- 유닉스 C 컴파일러 - cc
- 리눅스 C 컴파일러 - GNU cc- gcc(지씨씨)
- 우분투 리눅스에 gcc 설치

```shell
sudo apt-get install gcc
gcc --version
gcc -o test.c test
```



## API

- 응용 프로그램과 분리된 하위 호환 인터페이스
  - 예: 시스템 콜 래퍼, 입출력 라이브러리 등등

