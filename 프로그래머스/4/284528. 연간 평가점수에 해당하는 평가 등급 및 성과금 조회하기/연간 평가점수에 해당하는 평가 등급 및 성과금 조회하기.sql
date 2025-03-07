-- 코드를 작성해주세요
SELECT
    EMP_NO
    , EMP_NAME
    , CASE
        WHEN AVG(SCORE) >= 96 THEN 'S'
        WHEN AVG(SCORE) >= 90 THEN 'A'
        WHEN AVG(SCORE) >= 80 THEN 'B'
        ELSE 'C'
    END AS GRADE
    , CASE
        WHEN AVG(SCORE) >= 96 THEN SAL * 0.2
        WHEN AVG(SCORE) >= 90 THEN SAL * 0.15
        WHEN AVG(SCORE) >= 80 THEN SAL * 0.1
        ELSE 0
    END AS BONUS
FROM
    HR_GRADE
    JOIN HR_EMPLOYEES
    USING(EMP_NO)
GROUP BY
    1
ORDER BY
    1 ASC;