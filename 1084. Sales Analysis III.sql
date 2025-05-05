/*1084. Sales Analysis III
Write a solution to report the products that were only sold in the first quarter of 2019. That is, between 2019-01-01 and 2019-03-31 inclusive.

Return the result table in any order.
*/

SELECT Product.product_id,Product.product_name FROM Product
JOIN Sales ON Product.product_id = Sales.product_id
GROUP BY Product.product_id,Product.product_name
HAVING SUM(CASE WHEN Sales.sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31' THEN 1
       ELSE 0
       END) = 0;

