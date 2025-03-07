-- 코드를 작성해주세요
SELECT
    COUNT(ID) AS FISH_COUNT
    , MAX(LENGTH) AS MAX_LENGTH
    , FISH_TYPE
FROM
    FISH_INFO
WHERE
    FISH_TYPE IN(
        SELECT
            FISH_TYPE
        FROM
            FISH_INFO
        GROUP BY
            1
        HAVING
            AVG(IFNULL(LENGTH, 10)) >= 33)
GROUP BY
    3
ORDER BY
    3 ASC;