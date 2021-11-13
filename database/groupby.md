```mssql
-- Group By
-- Q) 2004년도에 가장 많은 홈런을 날린 팀은?
select top 1 teamID, sum(HR)
from batting
where yearID=2004
group by teamID
order by sum(HR) desc;

-- Q) 2004년도에 200홈런 이상을 날린 팀의 목록
-- 이 경우에 where절에 homeRuns >= 200을 넣으면 에러가 난다. 로직상 select는 group by 밑에 존재하기 때문에 homeRuns가 뭔지 모르기 때문이다. 그리고 group by는 로직상 where 밑에 있기 때문에 그룹핑하기 전에 where에 조건을 넣으면 논리적으로 맞지가 않다. 그래서 having절을 사용한다. 그리고 마찬가지로 having 절에도 homeRuns를 쓰면 에러가 난다.
select teamID, sum(HR) as homeRuns
from batting
where yearID = 2004
group by teamID
having sum(HR) >= 200
order by sum(HR) desc;

-- 로직
-- 영문법에 따라 sql 문법이 구성되어있는데 이게 로직 순서와 같지는 않다. 
-- from
-- where
-- group by
-- having
-- select
-- order by

-- Q) 단일 년도에 가장 많은 홈런을 날린 팀은 어디일까?
select teamID, yearID, sum(HR) as homeruns
from batting
group by  teamID, yearID
order by homeruns desc;

```

