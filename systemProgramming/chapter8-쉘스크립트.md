# chapter08 쉘스크립트

## 01 이해와 변수

### 쉘 스크립트

- 쉘을 사용해서 프로그래밍을 할 수 있음
- 서버 작업 자동화 및 운영(DevOps)를 위해 기본적으로는 익혀둘 필요가 있음
- 쉘 명령어를 기본으로 하되, 몇 가지 문법이 추가된 형태
- 시스템 프로그래밍에서 꼭 익히는 내용 중 하나



#### 쉘 스크립트 예

##### 문제점

> 서버가 어느 날 다운되었다.
>
> 확인해보니 서버 저장공간이 하나도 남지 않음
>
> 로그 파일 업데이트가 안되어 관련 프로그램 비정상 종료
>
> 이유는 로그 파일이 많이 쌓여있음
>
> 어떻게 하면 자동으로 오래된 로그 파일을 삭제할까?

##### 해결

> 간단한 쉘스크립트 생성 및 주기적 실행



#### 기본 문법

- 쉘 스크립트는 파일로 작성 후, 파일을 실행
- 파일의 가장 위의 첫 라인은 `#!/bin/bash`로 시작
- 쉘 스크립트 파일은 실행 권한을 가지고 있어야 함
- 일반적으로 `파일이름.sh`와 같은 형태로 파일 이름을 작성함



#### 실습

- bash쉘에서 제공하는 echo 함수를 이용하여 화면에 "Hello bash!"를 출력할 수 있도록 스크립트 작성

  ```sh
  #!/bin/bash
  
  echo "Hello bash!"
  ```

  

#### 주석

```
# 기호로 시작하는 라인은 주석처리
예)
# This is comment
```



#### 변수

- 선언

  - 변수명=데이터
  - 변수명=데이터 사이에 띄어쓰기는 허용되지 않음

- 사용

  - $변수명으로 사용됨

  ```
  예)
  #!/bin/bash
  
  mysql_id='root'
  mysql_directory='/etc/mysql'
  
  echo $mysql_id
  echo $mysql_directory
  ```

#### 실습

- 아이디 관련 정보 변수 만들기
  - 실제 이름
  - 나이
  - 직업



#### 리스트 변수(배열)

- 선언

  - 변수명=(데이터1 데이터2 데이터3 ...)

- 사용

  - ${변수명[인덱스번호]}

  ```sh
  daemons=("httpd" "mysqld" "vsftpd")
  echo ${daemons[1]} #daemons 배열의 두 번째 인덱스에 해당하는 mysqld 출력
  echo ${daemons[@]} #daemons 배열의 모든 데이터 출력
  echo ${daemons[*]} #daemons 배열의 모든 데이터 출력
  echo ${#daemons[@]} #damons 배열의 크기 출력
  
  filelist=( $(ls) ) # 해당 쉘스크립트 실행 디렉토리의 파일 리스트를 배열로 $filelist 변수에 저장
  echo ${filelist[*]} # $filelist 모든 데이터 출력
  ```

#### 실습

- 아이디 관련 정보 리스트 변수로 만들고 ,각 정보 출력하기

  - 실제 이름(0번 인덱스)

  - 나이(1번 인덱스)

  - 직업(2번 인덱스)

    ```
    #!/bin/bash
    infos=("Hoony" "30" "Software Engineer")
    echo ${infos[0]}
    echo ${infos[1]}
    echo ${infos[2]}
    ```

![image-20220122235621240](../../AppData/Roaming/Typora/typora-user-images/image-20220122235621240.png)

#### 연산자

- expr: 숫자 계산
- expr를 사용하는 경우 역작은 따옴표(`)를 사용해야함(작은 따옴표가 아님)
- 연산자 *와 괄호() 앞에는 역슬래시(\\)와 같이 사용
- 연산자와 숫자, 변수, 기호 사이에는 space를 넣어야함

```
예)
num=`expr \( 3 \* 5 \) / 4 + 7`
echo $num
```

#### 실습

- expr 명령으로 (12+20)/8 - 8 계산해보기

  ```
  #!/bin/bash
  
  num=`expr \( 12 + 20 \) / 8 - 8`
  echo $num
  ```

  

## 02 조건문

### 조건문 문법

- 기본 if 구문

  - 명령문을 꼭 탭으로 띄워야 하는 것은 아님(then과 fi안에만 들어가 있으면 됨)

    ```
    if [ 조건 ]
    then
    	명령문
    fi
    ```

    > python이 얼마나 가독성이 좋은지 이해할 수 있음

- 기본 if/else 구문

  ```
  if [ 조건 ]
  then
  	명령문
  else
  	명령문
  fi
  ```

  

### 실습: 쉘 스크립트 조건문

- 두 인자값을 받아서 두 인자값이 다르면 `different values`를 출력하라

  ```
  num1=$1
  num2=$2
  
  if [ $num1 != $num2 ]
  then
          echo "different values"
  fi
  ```



### 조건

- 조건 작성이 다른 프로그래밍 언어와 달리 가독성이 현저히 떨어짐. 필요할 때마다 참조하면 됨!

- 문자 비교

  ```
  문자1 == 문자2 # 문자1 과 문자2가 일치
  문자1 != 문자2 # 문자1 과 문자2가 일치하지 않음
  -z 문자 # 문자가 null이면 참
  -n 문자 # 문자가 null이 아니면 참
  ```

  ![image-20220123001342365](../../AppData/Roaming/Typora/typora-user-images/image-20220123001342365.png)

### 실습: 쉘스크립트 조건문

- 첫 번재 인자값이 두 번째 인가값보다 크면, 이를 출력하는 코드 작성해보기

   ```
   #!/bin/bash
   
   if [ $1 -gt $2 ]
   then
           echo $1
   fi
   ```

- 두 인자값을 받아서, 두 인자값이 같으면 'same values'를 출력하고, 그렇지 않으면 'different values'를 출력

  ```
  #!/bin/bash
  
  if [ $1 != $2 ]
  then
          echo "different value"
  else
          echo "same value"
  fi
  ```

  

  ![image-20220123101940242](../../AppData/Roaming/Typora/typora-user-images/image-20220123101940242.png)

![image-20220123102211976](../../AppData/Roaming/Typora/typora-user-images/image-20220123102211976.png)

### 실습: 쉘 스크립트 해석하기

- 명령 해석
  - ping -c 1 192.168.0.1 1> /dev/null
    - 0: 표준입력, 1: 표준출력, 2: 표준에러
  - 1>/dev/null: 표준 출력 내용은 버려라(출력하지 말아라)
  - -c 1은 1번만 체크해봐라



## 03  반복문과 실제 예제

### 반복문 문법

- 기본 for 구문

  ```
  for 변수 in 변수값1 변수값2 ...
  do
  	명령문
  done
  ```

- 기본 while 구문

  ````
  while [ 조건문 ]
  do
  	명령문
  done
  ````

  

### 실습: 쉘 스크립트 해석하기 

- 현재 디렉토리에 있는 파일과 디렉토리를 출력하라

  ```sh
  #!/bin/bash
  
  files=( $(ls) )
  for i in ${files[*]}
  do
          echo $i
  done
  
  for i in $(ls)
  do
  	echo $i
  done
  ```



## 04 현업 예제 및 정리

### 쉘 스크립트 해석하고, 맛보기 1

- 백업하기

  ```
  #!/bin/bash
  
  if [ -z $1 ] || [ -z $2 ]; then
  	echo usage: $0 sourcedir targetdir
  else
  	SRCDIR=$1
  	DSTDIR=$2
  	BACKUPFILE=backup.$(date +%y%m%d%H%M%S).tar.gz
  	if [ -d $DSTDIR ]; then
  		tar -cvzf $DSTDIR/$BACKUPFILE $SRCDIR
  	else
  		mkdir $DSTDIR
  		tar -cvzf $DSTDIR/$BACKUPFILE $SRCDIR
  	fi
  fi
  ```

  ![image-20220123111606442](../../AppData/Roaming/Typora/typora-user-images/image-20220123111606442.png)

### 수레 스크립트 해석하고, 맛보기2

- 로그 파일 정리하기

  ```sh
  find . -type f -name '파일명검색어' -exec bash -c "명령어1; 명령어2; 명령어3;" \;
  # -type f: 파일 타입 지정해서 검색(f는 일반 파일)
  ```

  ```sh
  #!/bin/bash
  
  LOGDIR=/var/log
  GZIPDAY=1
  DELDAY=2
  cd $LOGDIR
  echo "cd $LOGDIR"
  
  sudo find . -type f -name '*log.?' -mtime +$GZIPDAY -exec bash -c "gzip {}" \; 2> 
  sudo find . -type f -name '*.gz' -mtime +$DELDAY -exec bash -c "rm -f {}" \; 2>
  ```

  

