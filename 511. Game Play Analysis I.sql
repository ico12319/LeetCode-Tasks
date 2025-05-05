/*178. Rank Scores
Write a solution to find the rank of the scores. The ranking should be calculated according to the following rules:

The scores should be ranked from the highest to the lowest.
If there is a tie between two scores, both should have the same ranking.
After a tie, the next ranking number should be the next consecutive integer value. In other words, there should be no holes between ranks.
Return the result table ordered by score in descending order.
*/

SELECT player_id,MIN(event_date) AS first_login FROM activity GROUP BY player_id
ORDER BY player_id;