```mssql
-- Index
-- Index는 clustered와 non-clustered가 있다

-- primary key = 대부분 clustered
	-- 테이블당 1개만 존재
	-- 제일 좋고 빠르다
	-- 실제 데이터가 키에 따라 정렬된 상태로 저장(마치 영한사전)
	-- 물리적인 데이터 저장 순서의 기준

-- 나머지 = non-clustered index
	-- 별다른 제한 없다
	-- 따로 관리하는 일종의 LookUp 테이블
	-- 책 후반에 나오는 색인
	

```

