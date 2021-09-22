- select할 때 top 100만 보는 방법(mssql에만 있음. 다른 db에는 limit 등으로 사용)

  ```mssql
  select top 1000 *
  from players
  where birtyCity is not null
  ```

- 상위 100 ~ 200위를 보고 싶을 때 - offset을 사용. 사실 잘 사용하지는 않음

  ```mssql
  select *
  from players
  where birthCity is not null
  order by birthYear asc
  offset 100 rows fetch next 100 rows only;
  ```

  

