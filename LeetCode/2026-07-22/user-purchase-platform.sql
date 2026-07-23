# Write your MySQL query statement below
with
has_both as (
    select user_id,
    spend_date,
    s1.amount + s2.amount amount,
    "both" as platform

    FROM (select * from spending where platform = 'mobile') s1
        JOIN (select * from spending where platform = 'desktop') s2
        USING(user_id, spend_date)
),
only_desktop as (
    SELECT user_id,
    spend_date,
    amount,
    platform
    FROM spending
    where platform = 'desktop'
        AND ((user_id, spend_date) IN (
            SELECT user_id, spend_date
            FROM spending
            WHERE platform = 'mobile'
        )) IS NOT TRUE # Doing this bizarre thing to invert the result while correctly handling UNKNOWN that may come up if some rows have NULL values.
),
only_mobile as (
    SELECT user_id,
    spend_date,
    amount,
    platform
    FROM spending
    where platform = 'mobile'
        AND ((user_id, spend_date) IN (
            SELECT user_id, spend_date
            FROM spending
            WHERE platform = 'desktop'
        )) IS NOT TRUE
),
recombined as (
    SELECT * FROM has_both UNION ALL SELECT * FROM only_desktop UNION ALL SELECT * FROM only_mobile
),
dates as (
    select DISTINCT spend_date from recombined
),
platforms as (
    select DISTINCT platform from recombined
)
select spend_date, platform, coalesce(sum(amount),0) as total_amount, count(user_id) as total_users
from (dates CROSS JOIN platforms) LEFT JOIN recombined using(spend_date, platform)
GROUP BY spend_date, platform
-- ORDER BY CASE platform
-- WHEN 'desktop' then 1
-- when 'mobile' then 2
-- when 'both' then 3 end, spend_date;
