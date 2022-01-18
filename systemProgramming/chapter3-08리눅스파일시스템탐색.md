# chapter3 08 리눅스 파일 시스템 탐색

## 리눅스 파일 시스템과 관련 쉘 명령어

### 추상화

- 복잡한 소프트웨어 시스템을 효율적으로 설계하고 구현할 수 있는 방법
- 뒷편 시스템의 기술적 복잡함을 단순한 API 뒤에 숨길 수 있다
- 예를 들어 read, write의 기능을 사용자 또는 프로그래머가 사용할 때, 그 뒷편에서 어떤 일들이 일어나는지 모르더라도 파일 입출력, 화면 입출력 등에 동일한 인터페이스로 편리하게 사용할 수 있다.


## 파일과 inode

- 리눅스 파일 탐색 : 예) /home/ubuntu/link.txt
  - 각 디렉토리 엔트리(directory entries, dentry)를 탐색
  - 각 엔트리는 해당 디렉토리 파일/디렉토리 정보를 가지고 있음
  - `'/'` dentry에서 'home'을 찾고, 'home'에서 'ubuntu'를 찾고, 'ubuntu'에서 link.txt 파일 이름에 해당하는 inode를 얻음
  - dentry에 들어가는 정보(파일, 서브디렉토리 등)는 각각 모두  indoe를 가지고 있음

![image-20220119010047262](../../AppData/Roaming/Typora/typora-user-images/image-20220119010047262.png)

