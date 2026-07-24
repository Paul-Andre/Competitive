WITH
install_dates as (
    SELECT
        player_id,
        MIN(event_date) as install_date
    FROM activity
    GROUP BY player_id
),
install_dates_with_has_second as (
    SELECT 
        d1.player_id,
        d1.install_date,
        MAX(d2.player_id IS NOT NULL) as has_second
    FROM install_dates d1 LEFT JOIN activity d2
    ON d1.player_id = d2.player_id AND d2.event_date = d1.install_date + 1
    GROUP BY d1.player_id, d1.install_date

    # The GROUP BY is in order to enforce uniqueness and to avoid double-couting in case
    # a user has logged in from multiple devices on the same day.
    # With the current instructions, it's unnecessary, since it's stated that (player_id, event_date) is PK,
    # however based on the problem domain of the schema, the PK should probably really be (player_id, event_date, device_id).
)
SELECT
    install_date as install_dt,
    COUNT(*) as installs,
    ROUND(SUM(has_second) / COUNT(*),2) as `Day1_retention`
FROM install_dates_with_has_second
GROUP BY install_date;
