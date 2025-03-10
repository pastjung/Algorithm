-- 코드를 입력하세요
SELECT 
    PRODUCT_CODE, 
    SUM(SALES_AMOUNT * PRICE) AS SALES
FROM 
    OFFLINE_SALE
    LEFT JOIN PRODUCT
    USING (PRODUCT_ID)
GROUP BY 
    1
ORDER BY 
    2 DESC, 
    1 ASC;