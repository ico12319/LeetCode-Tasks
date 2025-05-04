/*1965. Employees With Missing Information
Write a solution to report the IDs of all the employees with missing information. The information of an employee is missing if:

The employee's name is missing, or
The employee's salary is missing.
Return the result table ordered by employee_id in ascending order.
*/

(SELECT employee_id FROM Employees
EXCEPT
SELECT employee_id FROM Salaries)

UNION ALL /* here it is better to use union all instead of union
             because we are sure that we won't have any duplicates and union all is way faster
             than union because it doesn't do any unnecessary checks to validate the uniqueness
             of the data */

(SELECT employee_id FROM Salaries
EXCEPT
SELECT employee_id FROM Employees)

ORDER BY employee_id;