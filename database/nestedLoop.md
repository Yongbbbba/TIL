```mssql
USE BaseballData;



-- 조인 원리

-- 원리를 알고 있어야지 나중에 실행 계획을 보고 쿼리 분석이 가능하다.

-- 1) Nested Loop (NL) 조인

-- 2) Merge(해시) 조인

-- 3) Hash(해시) 조인



-- NonClustered

--   1

-- 2 3 4

-- Clustered

--   1

-- 2 3 4



-- Merge

SELECT *

FROM players AS p

INNER JOIN salaries AS s

ON p.playerID = s.playerID;



-- NL

SELECT TOP 5 *

FROM players AS p

INNER JOIN salaries AS s

ON p.playerID = s.playerID;



-- HASH

SELECT *

FROM salaries AS s

INNER JOIN teams AS t

ON s.teamID = t.teamID;



-- NL

SELECT *

FROM players AS p

INNER JOIN salaries AS s

ON p.playerID = s.playerID

OPTION(LOOP JOIN);





-- 오늘의 결론

-- NL 특징 

-- 먼저 액세스한 (OUTER) 테이블의 로우를 차례차례 확인 후 -> (INNER)테이블에 랜덤 액세스

-- (INNER) 테이블에 인덱스가 없으면 노답 -> 이런 경우 애초에 NL을 쓰면 안되는 경우

-- 부분범위 처리에 좋다( ex. TOP 5), 조건만족 후 루프 탈출하면 끝나기 때문에.

-- 이중 for문에서 안쪽 반복문 돌 때 인덱스 걸려있어야지 좋은 성능을 발휘할 수 있다
```

