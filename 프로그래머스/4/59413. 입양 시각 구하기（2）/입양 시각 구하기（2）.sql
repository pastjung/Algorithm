-- 코드를 입력하세요
WITH RECURSIVE HOUR_CTE AS (
    SELECT 0 AS HOUR
    UNION ALL
    SELECT HOUR + 1
    FROM HOUR_CTE
    WHERE HOUR < 23
)
SELECT
    HOUR_CTE.HOUR AS HOUR
    , IFNULL(COUNT(ANIMAL_ID), 0) AS 'COUNT'
FROM
    HOUR_CTE
LEFT JOIN ANIMAL_OUTS
    ON HOUR_CTE.HOUR = HOUR(ANIMAL_OUTS.DATETIME)
GROUP BY
    HOUR_CTE.HOUR
ORDER BY
    HOUR_CTE.HOUR ASC;