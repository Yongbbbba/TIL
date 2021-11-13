```mssql
USE BaseballData;


-- RDBMS (Relational 관계형)

-- 데이터를 집합으로 간주

-- 복수의 테이블을 다루는 방법

-- 커리어 평균 연봉이 3백만 이상인 선수들의 playerID 

SELECT playerID, AVG(salary)

FROM salaries

GROUP BY playerID

HAVING AVG(salary) >= 3000000;


-- 12월에 태어난 선수들의 playerID

SELECT playerID, birthMonth

FROM players

WHERE birthMonth = 12;



-- [커리어 평균 연봉이 3000000 이상] 이거나 [12월에 태어난] 선수

-- UNION (중복 제거), UNION ALL(중복 허용)

SELECT playerID

FROM salaries

GROUP BY playerID

HAVING AVG(salary) >= 3000000


UNION


SELECT playerID

FROM players

WHERE birthMonth = 12

ORDER BY playerID;



-- [커리어 평균 연봉이 3000000 이상] && [12월에 태어난] 선수 (교집합)

-- INTERSECT


-- [커리어 평균 연봉이 3000000 이상] - [12월에 태어난] 선수 (차집합)

-- EXCEPT
```

