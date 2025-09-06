SELECT ed.id, COUNT(eed.id) AS child_count
FROM ecoli_data AS ed
LEFT JOIN ecoli_data AS eed ON ed.id = eed.parent_id
GROUP BY ed.id
ORDER BY ed.id;
