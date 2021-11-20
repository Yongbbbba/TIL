```mssql
USE BaseballData;



-- SORTING(정렬)을 줄이자. 



-- o(NlogN) -> DB는 데이터가 어머어마하게 많아질 수 있기에 이것 또한 부하다. 

-- 너무 용량이 커서 가용 메모리로 커버가 안되면 -> 디스크까지 찾아간다. 이 경우에 정렬까지 한다면..? 

-- 메모리와 디스크 접근 속도는 어마어마하게 차이가 있다.



-- sorting이 언제 일어나는지 파악하고 있어야 함 .



-- soritng이 일어날 때 

-- 1) sort merge join 

-- 원인) 알고리즘 특성상 merge하기 전에 sort를 해야함(정렬된 데이터가 없는 경우에만 sort)

-- 2) order by

-- 3) group by

-- 4) distinct 

-- 5) union 

-- 6) ranking windows fucntion 

-- 7) min max



-- 1) 생략 

-- 2) order by

-- 원인) order by 순서로 정렬을 해야 하니까 sort



select *

from players

order by college;  -- sort비용 75% !!



-- 3) group by

-- 원인) 집계를 위해 

select college, count(college)

from players

where college like 'C%'

group by college;



-- 4) DISTINCT

-- 원인) 중복 제거

select DISTINCT college

from players

where college like 'C%'



-- 5) union 

-- 원인) 중복제거

select college

from players

where college like 'B%'



union 



select college

from players

where college like 'C%';



-- 6) 순위 윈도우 함수 

select college, ROW_NUMBER() over (order by college)

from players;



-- index를 잘 활용하면, sorting을 굳이 하지 않아도 되는 상황을 만들 수 있다. 



-- 오늘의 결론

-- sorting을 줄이자. 특히 데이터가 많아지면 속도가 어마무시하게 느려질 수 있다. 

-- index를 잘 걸자.


```

