-- 코드를 작성해주세요
SELECT COUNT(*) AS COUNT
FROM ECOLI_DATA
WHERE (GENOTYPE & 2 = 0) -- 2번 형질이 없는 대장균
  AND (GENOTYPE & 5 > 0); -- 1번 또는 3번 형질을 보유한 대장균 (1 + 4)