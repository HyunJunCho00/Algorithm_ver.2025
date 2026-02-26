WITH cf AS (
    SELECT 
        user_id, 
        ROUND(
            SUM(CASE WHEN action = 'confirmed' THEN 1 ELSE 0 END) / COUNT(*), 
            2
        ) AS coon
    FROM confirmations
    GROUP BY user_id
)
SELECT 
    DISTINCT c.user_id, 
    IFNULL(cc.coon, 0) AS confirmation_rate 
FROM signups AS c 
LEFT JOIN cf AS cc ON cc.user_id = c.user_id
order by confirmation_rate asc, c.user_id desc;
