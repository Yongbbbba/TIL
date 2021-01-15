# git command

> git 기초 명령어 정리



## 설정

### init

- `git init` 

- 폴더를 git으로 관리하기 위해 `.git` 폴더를 생성하는 명령어

- 최초에 한 번만 실행하면 된다.

  

### status

- `git status`

- 현재 git의 상태를 출력

  

### log

- `git log`

- 현재 쌓여있는 commit history를 출력

  

### diff

- `git diff`
- 마지막 commit과 지금 working directory의 상태를 비교해서 출력



### remote add

- `git remote add <별명> <주소>`
- 원격 저장소 주소를 등록하는 명령어



## 조작

### add

- `git add <파일이름>`
  - `<파일이름>`에 `.`을 입력하면 전체 파일이 추가된다. ex) `git add .` 
- working directory에 있는 파일을 staging area(INDEX)에 올림



### commit

- `git commit -m "커밋 메시지"` 
  - `-m` 은 메시지 옵션
- staging area에 올라간 파일들을 스냅샷으로 저장



### push

- `git push <원격 저장소 이름>  <올릴 브랜치 이름>`
  - `git push origin master`
- commit history를 원격 저장소에 업로드하는 명령어



