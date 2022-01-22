# chapter3 10 소프트링크

## 하드 링크와 소프트 링크

- 하드링크: ln A B

  - ls -i(파일 inode 확인하기)
  - ls -al(완전 동일한 파일)
  - rm A로 A를 삭제하면?  B는 그래도 해당 파일 접근 가능
    - 'A:해당 inode'이 정보만 삭제되고, inode를 가진 실제 파일은 그대로 남음

- 소프트(심볼릭) 링크: ln -s A B

  - Windows OS의 바로가기와 동일

  - ls -al하면, 소프트 링크 확인 가능 (softLink.txt -> test.txt)

  - rm A로 A를 삭제하면?  B는 해당 파일 접근 불가

    - redirected path가 있는 것이 하드 링크와의 차이

    ![image-20220122132702463](../../AppData/Roaming/Typora/typora-user-images/image-20220122132702463.png)

## 특수 파일

- 디바이스

  - 블록 디바이스(Block Device)

    : HDD, CD/DVD와 같이 블록 또는 섹터 등 정해진 단위로 데이터 전송, IO 송수신 속도가 높음

  - 캐릭터 디바이스(Character Device)

    : 키보드, 마우스 등 byte 단위 데이터 전송, IO 송수신 속도가 낮음

  - cd /dev, cat tty

