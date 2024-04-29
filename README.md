# solid-principles
SOLID principles are a set of design principles for writing maintainable and scalable code. These principles were introduced by Robert C. Martin and are fundamental to software development best practices. "SOLID" is an acronym formed from the first letters of five specific principles.

These principles promote cohesion, flexibility, and code reusability, making the software easier to understand, maintain, and extend over time.

Violations in "violated.cpp":
**Single Responsibility Principle (SRP):** The Employee class is responsible for both defining the interface for calculating pay (calculatePay) and the actual implementation of calculating pay for both hourly and salaried employees. Ideally, these responsibilities should be separated into different classes.

**Open/Closed Principle (OCP):** If new types of employees are added, such as commission-based employees, the Payroll class would need to be modified to accommodate the changes. This violates the principle of being closed for modification but open for extension.

**Liskov Substitution Principle (LSP):** The Payroll class depends on concrete implementations of the Employee interface (HourlyEmployee and SalariedEmployee) rather than abstractions. Also, there's no guarantee that a subtype of Employee could be substituted for an Employee object without affecting the correctness of the program.

**Interface Segregation Principle (ISP):** All concrete subclasses of Employee are forced to implement the calculatePay method, even if they don't need it. This violates the principle of segregating interfaces to meet the specific needs of clients.
