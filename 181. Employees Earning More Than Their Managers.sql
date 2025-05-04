/*181. Employees Earning More Than Their Managers
Write a solution to find the employees who earn more than their managers.
Return the result table in any order.
The result format is in the following example.
 */

 SELECT a.name FROM Employee a JOIN Employee b
 ON a.managerid = b.id WHERE a.salary > b.salary;