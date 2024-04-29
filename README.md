# Solid Principles
## Overview
SOLID principles are a set of design principles for writing maintainable and scalable code. These principles were introduced by Robert C. Martin and are fundamental to software development best practices. "SOLID" is an acronym formed from the first letters of five specific principles.

These principles promote cohesion, flexibility, and code reusability, making the software easier to understand, maintain, and extend over time.

## Violations in "violated.cpp":

### Single Responsibility Principle (SRP):
The Employee class is responsible for both defining the interface for calculating pay (calculatePay) and the actual implementation of calculating pay for both hourly and salaried employees. Ideally, these responsibilities should be separated into different classes.

### Open/Closed Principle (OCP):
If new types of employees are added, such as commission-based employees, the Payroll class would need to be modified to accommodate the changes. This violates the principle of being closed for modification but open for extension.

### Liskov Substitution Principle (LSP):
The Payroll class depends on concrete implementations of the Employee interface (HourlyEmployee and SalariedEmployee) rather than abstractions. Also, there's no guarantee that a subtype of Employee could be substituted for an Employee object without affecting the correctness of the program.

### Interface Segregation Principle (ISP):
All concrete subclasses of Employee are forced to implement the calculatePay method, even if they don't need it. This violates the principle of segregating interfaces to meet the specific needs of clients.

## Solving the problems in "solid.cpp":

By defining the Employee class with a pure virtual function calculatePay(), the code separates the responsibility of defining the interface for calculating pay from the actual implementation. This adheres to the SRP, as each class now has a single responsibility: either defining the interface or implementing the pay calculation logic.

The Employee interface is open for extension by allowing new types of employees to be derived from it (e.g., HourlyEmployee and SalariedEmployee). At the same time, the Payroll class is closed for modification because it depends only on the abstract Employee interface, not on specific implementations. This adherence to the OCP allows for easy extension without modifying existing code.

The Payroll class now depends on the Employee interface rather than concrete implementations. This ensures that any subtype of Employee, such as HourlyEmployee or SalariedEmployee, can be substituted for an Employee object without affecting the correctness of the program. Thus, the code adheres to the LSP.

The Employee interface defines only one method, calculatePay(), which all concrete subclasses must implement. This ensures that each class implements only the methods it needs, adhering to the ISP and avoiding unnecessary dependencies between classes.
