-- 코드를 작성해주세요
SELECT
    T1.ID AS ID,
    COUNT(T2.ID) AS CHILD_COUNT     # COALESCE(COUNT(T2.ID), 0) AS CHILD_COUNT
FROM
    ECOLI_DATA AS T1
    LEFT JOIN ECOLI_DATA AS T2
    ON T1.ID = T2.PARENT_ID
GROUP BY
    1
ORDER BY
    1 ASC
;