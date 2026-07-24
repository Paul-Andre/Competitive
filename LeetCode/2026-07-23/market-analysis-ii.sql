# Write your MySQL query statement below
# Acceptable solution using correlated subquery:
-- select user_id as seller_id,
-- CASE WHEN
-- (select item_brand from orders join items using(item_id) where orders.seller_id = user_id order by order_date limit 1 offset 1) = favorite_brand
-- THEN 'yes'
-- ELSE 'no'
-- END as "2nd_item_fav_brand"
--  from users
--  order by user_id;


# Solution using window function
WITH
numbered_orders as (
    SELECT
        *,
        ROW_NUMBER() OVER(PARTITION BY seller_id order by order_date, order_id) as rn
    FROM orders JOIN items USING(item_id)
)
SELECT
    -- *,
    user_id as seller_id,
    CASE
        WHEN numbered_orders.item_brand = favorite_brand
        THEN 'yes'
        ELSE 'no'
    END as `2nd_item_fav_brand`
    from users left join numbered_orders
        ON users.user_id = numbered_orders.seller_id AND numbered_orders.rn = 2
        # Note: it is important that the  numbered_orders.rn = 2 is part of the `ON` clause of the LEFT JOIN,
        # because otherwise those rows will be removed completely, rather than populated by NULLs, as I want.
order by user_id
