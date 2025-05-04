/*1075. Project Employees I
Write an SQL query that reports the average experience years of all the employees for each project, rounded to 2 digits.

Return the result table in any order.
 */

SELECT Project.project_id,ROUND(AVG(experience_years),2) FROM Project
JOIN Employee on Project.employee_id =  Employee.employee_id
GROUP BY Project.project_id;