-- 코드를 입력하세요
SELECT
    ANIMAL_ID
    , NAME
FROM
    ANIMAL_INS
    JOIN ANIMAL_OUTS
    USING(ANIMAL_ID, ANIMAL_TYPE, NAME)
WHERE
    ANIMAL_OUTS.DATETIME IS NOT NULL
ORDER BY
    DATEDIFF(ANIMAL_OUTS.DATETIME, ANIMAL_INS.DATETIME) DESC
LIMIT 2