-- 코드를 입력하세요
SELECT
    HISTORY_ID
    , FLOOR(
        (DATEDIFF(END_DATE, START_DATE) + 1) 
        * DAILY_FEE 
        * IFNULL(100 - PLAN.DISCOUNT_RATE, 100) / 100) AS FEE
FROM
    CAR_RENTAL_COMPANY_RENTAL_HISTORY AS HISTORY
JOIN CAR_RENTAL_COMPANY_CAR  AS CAR
    USING(CAR_ID)
LEFT JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN AS PLAN
    ON PLAN.CAR_TYPE = CAR.CAR_TYPE
        AND PLAN.DURATION_TYPE = CASE
            WHEN DATEDIFF(END_DATE, START_DATE) + 1 >= 90 THEN '90일 이상'
            WHEN DATEDIFF(END_DATE, START_DATE) + 1 >= 30 THEN '30일 이상'
            WHEN DATEDIFF(END_DATE, START_DATE) + 1 >= 7 THEN '7일 이상'
        END
WHERE
    CAR.CAR_TYPE = '트럭'
GROUP BY
    1
ORDER BY
    2 DESC,
    1 DESC;