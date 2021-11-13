```mssql
--- transaction

-- BEGIN TRAN;
-- COMMIT;
-- ROLLBACK;

-- ALL OR NOTHING

-- 거래
-- A의 인벤토리에서 아이템 제거 
-- B의 인벤토리에다가 아이템 추가
-- A의 골드 감소
-- => 아이템 제거는 실패했는데 B에게 추가는 됐다면? 아이템 복사가 되어버리는 문제. 원자성이 깨지는 것임

-- TRAN 명시하지 않으면, 자동으로 COMMIT
-- 명시한다면, 성공/실패 여부에 따라 COMMIT(=COMMIT을 수동으로 하겠다)

BEGIN TRAN;
	INSERT INTO acccounts VALUES(2, 'rookiss2', 100, GETUTCDATE());
ROLLBACK;

BEGIN TRAN;
	INSERT INTO accounts VALUES(2, 'rookiss2', 100, GETUTCDATE());
COMMIT;

-- 응용
BEGIN TRY
	BEGIN TRAN;
		INSERT INTO acccounts VALUES(1, 'rookiss2', 100, GETUTCDATE());
		INSERT INTO acccounts VALUES(2, 'rookiss2', 100, GETUTCDATE());
	COMMIT;
END TRY
BEGIN CATCH
	IF @@TRANCOUNT > 0 -- 현재 활성화된 트랜잭션 수를 반환
		ROLLBACK;
	-- PRINT('ROLLBACK 했음')
END CATCH

-- TRAN 사용할 때 주의할 점
-- TRAN 안에는 꼭!!! 원자적으로 실행될 애들만 넣자
-- 성능 문제가 발생하기 때문이다. lock을 잡고 다른 세션이 접근하는 것을 막기 때문에..

```

