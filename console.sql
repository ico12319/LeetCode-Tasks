/*1211. Queries Quality and Percentage
We define query quality as:

The average of the ratio between query rating and its position.

We also define poor query percentage as:

The percentage of all queries with rating less than 3.

Write a solution to find each query_name, the quality and poor_query_percentage.

Both quality and poor_query_percentage should be rounded to 2 decimal places.

Return the result table in any order.

The result format is in the following example.
 */

WITH cte_bad_queries AS(
    SELECT query_name,COUNT(*) AS bad_queries_count
    FROM Queries WHERE rating < 3
    GROUP BY query_name
)

SELECT q.query_name, ROUND(SUM(q.rating::numeric / position) / COUNT(*),2) AS quality,
COALESCE(ROUND((MAX(bad_queries_count)::numeric / COUNT(*)) * 100,2),0) AS poor_query_percentage FROM Queries q
LEFT JOIN cte_bad_queries c on q.query_name = c.query_name
GROUP BY q.query_name;


