# chapter3 06 프로세스 관리 및 제어



## foreground process 제어하기

- ctrl + z : foreground 프로세스를 실행 중지 상태(suspend 모드)로 변경
- 맨 마지막 ctrl + z로 중지된 프로세스는 bg 명령으로 background 프로세스로 실행될 수 있음
- jobs 명령어: 백그라운드로 진행 또는 중지된 상태로 있는 프로세스를 보여줌
- ctrl + c : 프로세스 작업 취소(해당 프로세스는 완전히 종료됩니다)
  - 운영체제 소프트웨어 인터럽트가 해당 프로세스에 보내짐 - 그래서 프로세스 제어가 가능함



## 프로세스 상태 확인 - ps 명령어

![image-20220117235713089](../../AppData/Roaming/Typora/typora-user-images/image-20220117235713089.png)

- `ps aux`를 많이 사용함



## 프로세스 중지시키기

- kill 명령어
  - 사용법
    - kill %작업번호(job number)
    - kill 프로세스 ID(pid)
    - 작업 강제 종료 옵션 -9