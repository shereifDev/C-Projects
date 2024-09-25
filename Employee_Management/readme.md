
# Employee Management System

## Overview
This project is an Employee Management System built using C programming language. It allows organizations to manage their employees by adding, viewing, and updating employee information. The system also supports handling employee vacations, salary modifications (deductions, bonuses, and updates), and provides detailed statistics about the company's workforce.

## Features
1. **Add Employee**: Register a new employee with ID, name, position, and salary.
2. **Display Employee**: Retrieve and display the details of a specific employee by ID.
3. **Company Statistics**:
   - View the number of employees in each role (e.g., Developer, DevOps, Web Developer, etc.).
   - Show the number of active employees and those on vacation.
   - Calculate and display the total salary, highest salary, and lowest salary within the company.
4. **Handle Employee Vacations**: Create vacation records for employees, including the reason, number of days off, and start date. Deduct 12% of their salary for each vacation day.
5. **Update Employee Salary**:
   - Deduct an amount from the salary.
   - Add a bonus to the salary.
   - Directly update the salary to a new value.
6. **List Employees on Vacation**: Display employees who are currently on leave, along with the reason, duration, and start date of their vacation.

## Employee Positions
When adding an employee, the following positions can be selected:
- Developer
- DevOps
- Data Analyst
- Web Developer
- Embedded Systems Engineer
- Content Creator
- Video Editor

## Project Structure
- **typedef.h**: Contains type definitions and enumerations used for employee and vacation status.
- **Main Program**: Includes functions to manage the employee database, vacations, and salary updates.

## Usage
### Adding an Employee
Run the `addEmployee()` function to register a new employee. You will be prompted to enter the employee’s ID, name, position, and salary.

![Alt text](https://github.com/shereifDev/Employee-Management-Project-/blob/main/shots/shot_2.png)

### Displaying Employee Information
Use `displayEmployee()` to search for an employee by their ID and display their information.

![Alt text](https://github.com/shereifDev/Employee-Management-Project-/blob/main/shots/shot_5.png)
### Viewing Company Statistics
Call `statistics()` to view a summary of the company’s employees, including their positions, active/on-vacation status, and salary information.

![Alt text](https://github.com/shereifDev/Employee-Management-Project-/blob/main/shots/shot_7.png)
### Managing Vacations
The `take_avacation()` function allows you to assign a vacation to an employee by entering their ID, the vacation reason, number of days off, and start date. The employee's salary is automatically adjusted based on the vacation period.

![Alt text](https://github.com/shereifDev/Employee-Management-Project-/blob/main/shots/shot_9.png)
### Modifying Employee Salary
Use the `employeeServices()` function to:
- Deduct a certain amount from the salary.
- Add a bonus to the salary.
- Update the salary to a new value.
- 
![Alt text](https://github.com/shereifDev/Employee-Management-Project-/blob/main/shots/shot_11.png)

### Listing Employees on Vacation
The `display_vacations()` function will show all employees currently on vacation, including their vacation details.

![Alt text](https://github.com/shereifDev/Employee-Management-Project-/blob/main/shots/shot_14.png)
