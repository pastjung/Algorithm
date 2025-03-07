-- 코드를 입력하세요
SELECT
    FOOD_TYPE
    , REST_ID
    , REST_NAME
    , FAVORITES
FROM
    REST_INFO
WHERE
    (FOOD_TYPE, FAVORITES) IN(
        SELECT
            FOOD_TYPE,
            MAX(FAVORITES)
        FROM
            REST_INFO
        GROUP BY
            1)
GROUP BY
    1
ORDER BY
    1 DESC;