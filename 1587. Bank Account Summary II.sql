/*1587. Bank Account Summary II
Write a solution to report the name and balance of users with a balance higher than 10000. The balance of an account is equal to the sum of the amounts of all transactions involving that account.

Return the result table in any order.

The result format is in the following example.
 */

WITH user_balances AS(
    SELECT users.name, SUM(amount) OVER(PARTITION BY transactions.account) as balance
    FROM users JOIN transactions on users.account = transactions.account
)
SELECT DISTINCT name AS NAME, balance AS BALANCE FROM user_balances WHERE balance > 10000;



