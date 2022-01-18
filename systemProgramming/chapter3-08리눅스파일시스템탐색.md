# chapter3 08 리눅스 파일 시스템 탐색

## 리눅스 파일 시스템과 관련 쉘 명령어

### 추상화

- 복잡한 기능/데이터/자료구조 등에서 핵심 개념 및 기능을 간추려내는 것



## 파일과 inode

- 리눅스 파일 탐색 : 예) /home/ubuntu/link.txt
  - 각 디렉토리 엔트리(directory entries, dentry)를 탐색
  - 각 엔트리는 해당 디렉토리 파일/디렉토리 정보를 가지고 있음
  - `'/'` dentry에서 'home'을 찾고, 'home'에서 'ubuntu'를 찾고, 'ubuntu'에서 link.txt 파일 이름에 해당하는 inode를 얻음
  - dentry에 들어가는 정보(파일, 서브디렉토리 등)는 각각 모두  indoe를 가지고 있음

![image-20220119010047262](../../AppData/Roaming/Typora/typora-user-images/image-20220119010047262.png)

