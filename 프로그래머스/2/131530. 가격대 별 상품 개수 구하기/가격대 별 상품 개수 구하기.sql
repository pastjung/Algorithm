-- 코드를 입력하세요
SELECT
    TRUNCATE(PRICE, -4) AS PRICE_GROUP,
    COUNT(*) AS PRODUCTS
FROM
    PRODUCT
GROUP BY
    1
ORDER BY
    1;