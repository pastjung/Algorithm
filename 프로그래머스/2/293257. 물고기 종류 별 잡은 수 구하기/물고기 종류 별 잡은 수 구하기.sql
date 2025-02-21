-- 코드를 작성해주세요
SELECT
    COUNT(*) AS FISH_COUNT,
    FISH_NAME
FROM
    FISH_INFO
    LEFT JOIN FISH_NAME_INFO
    ON FISH_INFO.FISH_TYPE = FISH_NAME_INFO.FISH_TYPE
GROUP BY
    2
ORDER BY
    1 DESC;