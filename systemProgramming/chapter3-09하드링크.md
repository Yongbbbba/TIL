# chapter3 09 하드링크

## 하드링크와 소프트 링크

- cp 명령: 파일 복사

  - 1MB사이즈를 가지고 있는 A파일을 B파일로 복사
    - cp A B -> A와  B는 각각 물리적으로 10MB 파일로 저장

- 하드 링크: ln A B

  - A와 B는 동일한 10MB 파일을 가리킴
  - 즉, 동일한 파일을 가진 이름을 하나 더 만든 것일 뿐
    - 그래서, inode는 동일!
    - 전체 파일 용량은 달라지지 않음
    - & 내가 이해가기로는 inode structure를 복사하는 것은 cp, inode structure의 주소를 가지는 포인터를 만드는 것은 하드링크
    - & ls -i로 inode 값 확인 가능
  - 원본파일의 데이터를 변경하면 하드링크된 파일의 데이터도 변경됨

  ![image-20220122125235867](../../AppData/Roaming/Typora/typora-user-images/image-20220122125235867.png)

