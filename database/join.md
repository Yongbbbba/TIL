

```mssql
-- JOIN(결합)

-- CROSS JOIN (교차 결합) -> 거의 사용은 하지 않음

---------------------------------------------

-- INNER JOIN (두 개의 테이블을 가로로 결합 + 결합기준을 ON으로)
-- playerID가 players, salaries 양쪽에 다 있고 일치하는 애들을 결합
use BaseballData;

select *
from players as p
	inner join salaries as s
	on p.playerID = s.playerID;
	
-- OUTER JOIN (외부 결합)
	-- LEFT / RIGHT
	-- 어느 한 쪽에만 존재하는 데이터 -> 어떻게 결합할 것인가?
-- LEFT JOIN (두 개의 테이블을 가로로 결합 + 결합기준을 ON으로)
-- plyaerID가 왼쪽(left)에 있으면 무조건 표시. 오른쪽(salaries)에 없으면 오른쪽 정보는 null로 채움

select * 
from players as p
	left join salaries as s
	on p.playerID = s.playerID;

```

