# chapter3 04 리다이렉션과 파이프



## Standard Stream (표준입출력)

- command로 실행되는 프로세스는 세 가지 스트림을 가지고 있음
  - 표준 입력 스트림(standard input stream) - stdin
  - 표준 출력 스트림(standard output stream) - stdout
  - 오류 출력 스트림(standard error stream) - stderr
- 모든 스트림은 일반적인 plain text로 console에 출력하도록 되어 있음



## 리다이렉션(redirection)

- 출력의 방향성을 바꿀 수 있다 -> 표준 스트림 흐름을 바꿔줄 수 있다
  - `>`, `<` 을 사용함
  - 주로 명령어 표준 출력을 화면이 아닌 파일에 쓸 때 많이 사용
- 예
  - ls > files.txt
    - ls로 출력되는 표준 출력 스트림의 방향을 files.txt로 바꿔줌(files.txt에 ls로 출력되는 결과가 저장됨)
  - head < files.txt
    - files.txt의 파일 내용이 head라는 파일의 처음부터 10라인까지 출력해주는 명령으로 넣어짐(files.txt의 앞 10라인이 출력됨)
  - head < files.txt > files2.txt
    - files.txt의 파일 내용이 head로 들어가서, files.txt의 앞 10라인을 출력
    - head의 출력 스트림은 다시 files2.txt로 들어감
    - head는 files.txt 내용을 출력하지 않고, 해당 출력 내용이 다시 files2.txt에 저장됨 (결과적으로 files.txt의 앞 10라인이 files2.txt에 저장됨)
- 기존 파일에 추가는 `>>` 또는 `<<` 사용
  - ls >> files.txt
  - 기존에 있는 files.txt 파일 끝에, ls 출력 결과를 추가해줌



## 파이프(pipe)

- 두 프로세스 사이에서 한 프로세스의 출력 스트림을 또다른 프로세스의 입력 스트림으로 사용할 때 사용됨
- 유닉스 철학의 핵심
- `|`로 사용
- 파이프 사용의 예
  - ls | grep files.txt
    - ls 명령을 통한 출력 내용이 grep 명령의 입력 스트림으로 들어감
    - grep files.txt는 grep 명령의 입력 스트림을 검색해서 files.txt가 들어있는 입력 내용만 출력해줌 
    - 따라서 ls 명령으로 해당 디렉토리/파일 중에 files.txt 파일이 있는지를 출력해줌

![image-20220116165229077](../../AppData/Roaming/Typora/typora-user-images/image-20220116165229077.png)

