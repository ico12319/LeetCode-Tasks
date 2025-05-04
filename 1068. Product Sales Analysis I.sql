/*1068. Product Sales Analysis I
Write a solution to report the product_name, year, and price for each sale_id in the Sales table.

Return the resulting table in any order.
 */

SELECT Product.product_name, Sales.year,Sales.price FROM Sales
JOIN Product on Sales.product_id = Product.product_id;