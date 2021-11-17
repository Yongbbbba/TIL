```mssql
-- 인덱스 접근 방식 (Access)

-- Index Scan vs Index Seek



CREATE TABLE TestAccess

(

 id INT NOT NULL,

 name NCHAR(50) NOT NULL,

 dummy NCHAR(1000) NULL  -- 고정길이로 varchar은 다르게 크기가 고정됨

);

GO



CREATE CLUSTERED INDEX TestAccess_CI

ON TestAccess(id);

GO 



CREATE NONCLUSTERED INDEX TestAccess_NCI

ON TestAccess(name);

GO



DECLARE @i INT;

SET @i = 1;

WHILE (@i <= 500)

BEGIN 

 INSERT INTO TestAccess

 VALUES (@i, 'Name' + CONVERT(VARCHAR, @i), 'Hello World' + CONVERT(VARCHAR, @i));

 SET @i = @i + 1;

END



SELECT *

FROM TestAccess;

-- 인덱스 정보

EXEC sp_helpindex 'TestAccess';

-- 인덱스 번호

SELECT index_id, name

FROM sys.indexes

WHERE object_id = object_id('TestAccess');

-- 조회

DBCC IND('Northwind', 'TestAccess', 1);

DBCC IND('Northwind', 'TestAccess', 2);



-- CLUSTERED(1) : id



-- 논리적 읽기 -> 실제 데이터를 찾기 위해 읽은 페이지 수

SET STATISTICS TIME ON;

SET STATISTICS IO ON;



-- INDEX SCAN  = LEAF PAGE 순차적으로 검색

SELECT *

FROM TestAccess;



-- INDEX SEEK

SELECT *

FROM TestAccess

WHERE id=104;



-- INDEX SEEK + KEY LOOKUP

SELECT *

FROM TestAccess

WHERE name='name5';



-- INDEX SCAN + KEY LOOKUP

-- INDEX SCAN이 무조건 나쁜 것은 아닌데 바로 이 경우를 말한다.

-- TOP과 ORDER BY 때문. name를 키로 index를 잡고 있었기 때문에.

-- 리프 노드부터 순차적으로 탐색을 하기는 하지만, 이미 정렬이 되어있고 5개만 확인하면 되기 때문에 추출이 오래 걸리지 않는다.

SELECT TOP 5 *

FROM TESTACCESS

ORDER BY NAME;



-- 대부분의 경우에 INDEX SEEK 좋다. 하지만 케바케.


```

