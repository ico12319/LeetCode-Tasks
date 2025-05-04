/*1251. Average Selling Price
Write a solution to find the average selling price for each product. average_price should be rounded to 2 decimal places. If a product does not have any sold units, its average selling price is assumed to be 0.

Return the result table in any order.
*/

SELECT Prices.product_id,COALESCE(ROUND(SUM(Prices.price * UnitsSold.units) * 1.0 / SUM(units),2),0)
AS average_price
FROM Prices LEFT JOIN UnitsSold ON Prices.product_id = UnitsSold.product_id
AND UnitsSold.purchase_date BETWEEN Prices.start_date
AND Prices.end_date GROUP BY Prices.product_id;