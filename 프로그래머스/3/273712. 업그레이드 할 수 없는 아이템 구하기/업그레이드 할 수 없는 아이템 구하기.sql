-- 코드를 작성해주세요
# -- LEFT JOIN을 사용한 방법
# SELECT
#     ITEM_INFO.ITEM_ID,
#     ITEM_INFO.ITEM_NAME,
#     ITEM_INFO.RARITY
# FROM
#     ITEM_INFO
#     LEFT JOIN ITEM_TREE
#     ON ITEM_INFO.ITEM_ID = ITEM_TREE.PARENT_ITEM_ID
# WHERE
#     ITEM_TREE.PARENT_ITEM_ID IS NULL
# ORDER BY
#     1 DESC;

# NOT EXISTS를 사용한 방법
SELECT
    ITEM_ID,
    ITEM_NAME,
    RARITY
FROM
    ITEM_INFO
WHERE
    NOT EXISTS(
        SELECT 
            1
        FROM 
            ITEM_TREE
        WHERE
            ITEM_INFO.ITEM_ID = ITEM_TREE.PARENT_ITEM_ID)
ORDER BY
    1 DESC;