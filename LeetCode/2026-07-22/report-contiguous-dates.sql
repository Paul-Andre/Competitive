# Write your MySQL query statement below
with
united as (
    select "failed" as period_state, fail_date as date FROM Failed
    UNION ALL
    select "succeeded" as period_state, success_date as date FROM succeeded
),
filtered as (
    select * from united
    where date between '2019-01-01' and '2019-12-31'
),
marked as (
    select
        *,
        # I am assuming that there is exactly one entry for every day, which is in the task description
        CASE WHEN period_state = LAG(period_state) OVER(ORDER BY date)
            THEN 0
            ELSE 1
        END as mark
    FROM filtered
),
grouped as (
    select
        *,
        SUM(mark) OVER(ORDER BY date) as group_id
    FROM marked
)
select
    period_state,
    MIN(date) as start_date,
    MAX(date) as end_date
FROM grouped group by group_id
ORDER BY MIN(date);
