```mssql
-- Merge(병합) 조인 -> Sort Merge(정렬 병합) 조인

-- one-to-many일 때 효율적이다. merge작업이 O(n) + O(m)

-- many-to-many일 때는 비효율적일 수 있다. O(n*m)



Select *

from players as p 

inner join salaries as s

on p.playerID = s.playerID;



-- one-to-many(outer가 unique해야 함=> PK, unique)일 때 가장 빠르다.

-- Merge 조인도 조건이 붙는다 

-- 일일히 Random Access -> clustered Scan 후 정렬(리프 페이지가 해당 키로 정렬이 되어있지 않은 경우)



 -- 오늘의 결론 

 -- Merge -> Sort Merge 조인 

 -- 1) 양쪽 집합을 Sort(정렬)하고 merge(병합)한다.

 -- 이미 정렬된 상태라면 sort는 생략 가능. 특히 clustered로 물리적 정렬된 상태라면 Best)

 -- 정렬할 데이터가 너무 많으면 GG -> hash 

 -- 2) Random Access 위주로 수행되진 않는다.

 -- 3) Many-to Many(다대다)보다는 One-to-Many(일대다) 조인에 효과적 

 -- pk, unique인 칼럼에 대한 조인일 때 효과적. 


```

