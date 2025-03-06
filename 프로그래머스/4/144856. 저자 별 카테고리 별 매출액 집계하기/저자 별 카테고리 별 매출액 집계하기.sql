-- 코드를 입력하세요
SELECT
    AUTHOR_ID
    , AUTHOR_NAME
    , CATEGORY
    , SUM(SALES * PRICE) AS TOTAL_SALES
FROM
    BOOK
    JOIN BOOK_SALES
    USING(BOOK_ID)
    JOIN AUTHOR
    USING(AUTHOR_ID)
WHERE
    SALES_DATE LIKE '2022-01%'
GROUP BY
    1, 2, 3
ORDER BY
    1 ASC
    , 3 DESC
;