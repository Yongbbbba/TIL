```mssql
-- 인덱스 종류



-- Clustered(영한 사전) vs Non-Clustered(색인)



-- Clustered

 -- Leaf Page = Data Page

 -- 데이터는 Clustered Index 키 순서로 정렬



--  Non-Clustered ? (사실 Clustered Index 유무에 따라서 다르게 동작)

-- 1) Clustered Index가 없는 경우 

 -- Clustered Index가 없으면 데이터는 Heap Table이라는 곳에 저장

 -- 원본 데이터를 저장할 공간이 필요해짐.

 -- Heap RID를 활용하여 --> Heap Table에 접근해서 데이터 추출

-- 2) Clustered Index가 있는 경우 

 -- Heap Table이 없는 상태. Leaf Table에 실제 데이터가 있다.

 -- Heap RID라는 것도 없음. Clustered Index의 실제 키 값을 들고 있어서 이걸 이용해서 추출.



-- 임시 테스트 테이블을 만들고 데이터 복사

SELECT * 

INTO TestOrderDetails

FROM [Order Details];



SELECT *

FROM TestOrderDetails;



-- 인데스 추가

CREATE INDEX Index_OrderDetails

ON TestOrderDetails(OrderID, ProductID);



-- 인덱스 정보

EXEC sp_helpindex 'TestOrderDetails';

-- 인덱스 번호 찾기

SELECT index_id, name

FROM sys.indexes

WHERE object_id=object_id('TestOrderDetails')

-- 조회

DBCC IND('Northwind', 'TestOrderDetails', 2);



DBCC PAGE('Northwind', 1, 824, 3);

-- HEAP RID([페이지 주소(4)] [파일ID(2)][슬롯(2)] ROW)

-- HEAP TABLE[ {PAGE} {PAGE} {PAGE} {PAGE} ]

-- HEAP RID를 이용해서 실제 데이터가 있는 힙 테이블에서 데이터를 추출한다.



-- PAGETYPE 1(DATA PAGE) 2(INDEX PAGE)

-- Non-Clustered의 경우에는 페이지 타입이 다 2번이다. 

-- Clustered의 경우에는 리프 페이지가 데이터 페이지이기 때문에 1번.



-- Clustered 인덱스 추가

CREATE Clustered INDEX Index_OrderDetail_Clustered

ON TestOrderDetails(OrderID);





DBCC IND('Northwind', 'TestOrderDetails', 1);

DBCC IND('Northwind', 'TestOrderDetails', 2);



-- Clustered index가 설정되면 Non-Clustered index에도 영향을 준다. heap table의 존재 때문에 
```

