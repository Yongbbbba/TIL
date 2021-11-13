```mssql
-- CASE

select *
	case birthMonth
		when 1 then N'겨울'
		when 2 then N'겨울'
		      ...
		else N'몰라요'
    end as birthSeason
from players;

select *
	case 
		when birthMonth <= 2 then N'겨울'
		when birthMonth <= 5 then N'봄'
		when birhtMonth <= 8 then N'여름'
		when birthMonth <= 11 then N'가을'
		else N'겨울'
    end as birthSeason
from players;

-- 만약에 else문을 만들지 않았을 때 when으로 분기처리한 값이 들어오지 않을 경우엔 null값이 들어오게 된다.
```

