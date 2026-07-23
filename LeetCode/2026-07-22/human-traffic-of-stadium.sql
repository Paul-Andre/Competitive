
# Write your MySQL query statement below
with
filtered as (
    select * from stadium
    where people >= 100),
marked as (
    select
        *,
        CASE WHEN id = LAG(id) OVER(ORDER BY id) + 1
            THEN 0
            ELSE 1
        END as tag
    from filtered),
tagged as (
    select
        *,
        SUM(tag) OVER(ORDER BY id) as mark
    FROM  marked
),
counted as (
    select
        *,
        COUNT(1) OVER(PARTITION BY mark) as cnt
    FROM tagged
)
SELECT
    id,
    visit_date,
    people
FROM counted
WHERE cnt >= 3
ORDER BY visit_date ASC;
