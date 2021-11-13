```mssql
-- 날짜를 문자열로 저장할 수도 있지만, 날짜를 비교한다던가, 날짜에 며칠을 더한다던가 하는 연산을 하는 경우 등에서 큰 불편함을 가져온다. 그래서 date, time, datetime 등의 type을 사용할 필요가 있다.

-- DATE 연/월/일
-- TIME 시/분/초
-- DATETIME 연/월/일/시/분/초

-- 포멧
 -- YYYYMMDD
 -- YYYYMMDD hh:mm:ss.nnn
 -- YYYY-MM-DDThh:mm

use BaseballData;

 select cast('20200425' as datetime);  -- 캐스팅 안해주고 문자열 넣어도 알아서 인식히가는 함

 select getdate();  -- T-SQL
 select CURRENT_TIMESTAMP; -- 표준

 -- GMT(Greenwich Mean Time) 기준
 -- 각 서버의 위치가 다른 나라일 수 있기 때문에 시간을 통일시키는 것이 좋음
 select GETUTCDATE();  -- 현재의 UTC 시간을 반환

 select *
 from datetiemTest
 where time >= '20100101' -- 캐스팅해줘도 됨

 select dateadd(year, 1, '20200426')
 select dateadd(day, 5, '20200426')
 select dateadd(second, 12323, '20200426')  -- 마이너스를 하면 과거로 역행 가능

 select datediff(second, '20200426', '20200503')
 select datediff(day, '20200426', '20200503')

select datepart(day, '20200826')
select day('20200826')



```

