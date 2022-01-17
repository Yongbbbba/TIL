# chapter3 07 리눅스 파일 시스템

![image-20220118001303540](../../AppData/Roaming/Typora/typora-user-images/image-20220118001303540.png)

read, write, open, close를 이용한 인터페이스를 통해 다양한 device를 제어할 수 있음



## 리눅스와 파일 정리

- **모든 것은 파일**이라는 철학을 따름
  - 모든 인터렉션은 파일을 읽고, 쓰는 것처럼 이루어져 있음
  - 마우스, 키보드와 같은 모든 디바이스 관련된 기술도 파일과 같이 다루어짐
  - 모든 자원에 대한 추상화 인터페이스로 파일 인터페이스를 활용



## 가상 파일 시스템

- 파일 네임스페이스
  - A 드라이브(A:/), C드라이브(C:/windows) (x)
  - 전역 네임스페이스 사용
    - /media/floofy/dave.jpg
    - 예: cat tty
    - root 디렉토리가 최상단에 있으면서 서브 디렉토리로 나누어짐

![image-20220118002322695](../../AppData/Roaming/Typora/typora-user-images/image-20220118002322695.png)

![image-20220118002552209](../../AppData/Roaming/Typora/typora-user-images/image-20220118002552209.png)