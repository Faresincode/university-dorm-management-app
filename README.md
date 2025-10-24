# university-dorm-management-app
Welcome to the 👉  Dormitory Management System, a robust C++ application designed to streamline the management of dormitory operations  🔥 , including student records, employee data, visitor logs, patrol schedules, incident reports, and maintenance requests
The Dormitory Management System is a powerful C++ console-based application designed to streamline dormitory operations for university or residential administrators. It manages student records, employee data, visitor logs, patrol schedules, incident reports, maintenance requests, and more, with a user-friendly menu-driven interface, robust input validation, and file-based data persistence.
Table of Contents

Project Overview
Features
Screen Structure
System Requirements
Installation
File Structure
Usage
Key Components
Contributing
License
Contact

Project Overview
This C++ application provides a comprehensive solution for managing dormitory operations. It supports various administrative tasks through a modular design, using text files for data storage and a colorful console interface for enhanced user experience. The system is built with maintainability and data integrity in mind, leveraging classes like clsInputValidate and clsUtil for robust functionality.
Features

Student Management:
Add, update, and view student records (e.g., ID, name, dorm building, room number, bed number, status, meal plan).
Track academic details (university, faculty, department, year, section).
Manage check-in/check-out dates and student complaints.


Employee Management:
Manage employee details (residence name, department, job title, salary, shift, status).
Handle shift schedules and security assignments.


Visitor Tracking:
Log and update visitor information (ID, name, visit purpose, department, room, status: Inside/Exited, visit/exit times).
Filter visitors by name, department, or today’s visits.


Patrol Scheduling:
View and manage security patrol schedules (patrol ID, security ID, location, start/end times, status).
Display completed patrols separately.


Incident Reporting:
Record and update incident reports (ID, type, description, severity, status, security ID, date).
Support for severity levels (Low, Medium, High) and statuses (Open, In Progress, Resolved, Closed).


Maintenance Requests:
Track maintenance requests (ID, dorm building, room, issue type, priority, status, assigned staff, request date).
Display requests with priority and status details.


Login System:
Role-based access with usernames and passwords (e.g., admin, securitychief, financemanager).
Track login sessions with timestamps.


Data Persistence:
Store all data in text files (e.g., StudentsDormData.txt, VisitorsData.txt) with #//# separators.
Support for loading, saving, and updating records.


Input Validation:
Robust validation for strings, numbers, and enums to ensure data integrity.
Option to skip fields during updates to retain existing data.


Console UI:
Color-coded outputs (Green, White, Blue, Yellow, Red) for better readability.
Structured menus with clear headers and tables for data display.



Screen Structure
The application uses a menu-driven interface with the following screens, each implemented as a class inheriting from clsBase for consistent header display and navigation:

Update Visitor Information Screen (clsUpdateVisitorInfoScreen.h)

Purpose: Update visitor records by ID.
Menu Options:
[1] First Name
[2] Last Name
[3] Visit Purpose
[4] Visited Department
[5] Visited Room
[6] Visitor Status (Inside/Exited)
[7] Update All


Features:
Prompts for visitor ID and validates existence.
Allows selective or full updates with input validation.
Saves changes to VisitorsData.txt.




Update Dorm Student Screen (clsUpdateDormStudentScreen.h)

Purpose: Update student dormitory records by ID.
Menu Options:
[1] Dorm Building
[2] Room Number
[3] Bed Number
[4] Status (Checked_out, Active, Suspended, Transferred, Pending, NoStatus)
[5] Meal Plan (NoMeal, Full, Half)
[6] Update All


Features:
Supports skipping fields with "skip" input.
Validates inputs and saves to StudentsDormData.txt.




Update Employee Info Screen (clsUpdateEmployeeInfoScreen.h)

Purpose: Update employee records by ID.
Menu Options:
[1] Residence Name
[2] Residence Department
[3] Job Title
[4] Salary
[5] Shift
[6] Status
[7] Update All


Features:
Validates employee ID existence.
Saves changes to DormEmployeeData.txt.




Update Incident Screen (clsUpdateIncidentScreen.h)

Purpose: Update incident reports by ID.
Menu Options:
[1] Incident Type
[2] Description
[3] Severity (Low, Medium, High)
[4] Status (Open, In Progress, Resolved, Closed)
[5] Security ID
[6] Update All
[7] Exit


Features:
Validates incident ID and saves to IncidentReports.txt.
Supports detailed incident updates.




View All Patrol Schedules Screen (clsViewAllPatrolSchedulesScreen.h)

Purpose: Display all patrol schedules in a table.
Table Columns:
Patrol ID
Security ID
Start Time
End Time
Patrol Status
Patrol Location


Features:
Loads data from PatrolSchedules.txt.
Displays a formatted table with color-coded headers.




View Patrol Logs Screen (clsViewPatrolLogsScreen.h)

Purpose: Display all patrol logs and completed patrols separately.
Table Columns: Same as View All Patrol Schedules.
Features:
Filters and displays completed patrols.
Reuses table formatting from clsViewAllPatrolSchedulesScreen.




View All Requests Screen (clsViewAllRequestsScreen.h)

Purpose: Display all maintenance requests in a table.
Table Columns:
Request ID
Dorm Building
Room
Issue Type
Priority
Status
Assigned Staff ID
Request Date


Features:
Loads data from MaintenanceRequests.txt.
Displays a formatted table with color-coded headers.




Visitor Log List Screen (clsVisitorLogListScreen.h)

Purpose: Display all visitor logs in a table.
Table Columns:
Visitor ID
Full Name
Visit Purpose
Department
Room
Status
Visit Time
Exit Time


Features:
Loads data from VisitorsData.txt.
Displays a formatted table with color-coded headers.





System Requirements

Operating System: Windows, Linux, or macOS
Compiler: C++11 or later (e.g., g++, MSVC)
Dependencies: Standard C++ libraries (iostream, vector, fstream, iomanip, etc.)
Disk Space: Minimal (text-based data files)
Console/Terminal: For running the application

Installation
Here’s how to set up the project locally:

Clone the Repository:

Open a terminal and run:git clone https://github.com/your-username/dormitory-management-system.git


Or download the ZIP file from GitHub and extract it.


Navigate to the Project Directory:
cd dormitory-management-system


Compile the Code:

Ensure a C++ compiler is installed (e.g., g++).
Compile all .cpp files:g++ *.cpp -o DormitoryManagementSystem


For Windows (with MinGW):g++ *.cpp -o DormitoryManagementSystem.exe




Run the Application:

On Linux/macOS:./DormitoryManagementSystem


On Windows:DormitoryManagementSystem.exe




Ensure Data Files:

Ensure text files (e.g., StudentsDormData.txt, VisitorsData.txt) are in the same directory as the executable.



File Structure
dormitory-management-system/
│
├── *.h                # Header files for classes (e.g., clsVisitor.h)
├── *.cpp              # Source files for implementation
├── *.txt              # Data files (e.g., StudentsDormData.txt)
├── README.md          # This file

Key Header Files

clsVisitor.h: Manages visitor data and operations.
clsUpdateVisitorInfoScreen.h: Updates visitor records.
clsUpdateDormStudentScreen.h: Updates student records.
clsUpdateEmployeeInfoScreen.h: Updates employee records.
clsUpdateIncidentScreen.h: Updates incident reports.
clsViewAllPatrolSchedulesScreen.h: Displays patrol schedules.
clsViewPatrolLogsScreen.h: Displays patrol logs.
clsViewAllRequestsScreen.h: Displays maintenance requests.
clsVisitorLogListScreen.h: Displays visitor logs.
clsUtil.h: Utility functions for random IDs, file I/O, and formatting.
Global.h: Global constants and color definitions.
GlobalLogin.h: Manages current user login.

Key Data Files

StudentsDormData.txt: Student information.
DormEmployeeData.txt: Employee information.
VisitorsData.txt: Visitor logs.
PatrolSchedules.txt: Patrol schedules.
IncidentReports.txt: Incident reports.
MaintenanceRequests.txt: Maintenance requests.
LoginData.txt: User credentials.
RegisterLogins.txt: Login session tracking.
StudentsDormComplaints.txt: Student complaints.
RoomsData.txt: Room details.
ShiftsSchedulesData.txt: Employee shift schedules.
SecuritiesData.txt: Security personnel data.
DormPaymentsData.txt: Payment records.

Usage

Run the Program:
Launch the executable to access the main menu.


Login:
Use credentials from LoginData.txt (e.g., username: admin, password: 3456).


Navigate Menus:
Select options (e.g., 1-7) to update records or view logs.
Example: To update a student, enter their ID and choose fields to update.


Data Management:
Use skip to retain existing data during updates.
View records in formatted tables.


Exit:
Save changes and exit via menu prompts.



Key Components

clsBase: Provides screen header functionality.
clsInputValidate: Ensures valid user inputs.
clsString: Handles string operations for file parsing.
clsUtil: Supports random ID generation, file I/O, and console formatting.
Data Persistence: Uses text files with #//# separators.

Contributing

Fork the Repository:
Click “Fork” on the GitHub repository page.


Make Changes:
Clone your fork and create a branch:git checkout -b feature/your-feature




Commit and Push:git add .
git commit -m "Add your feature description"
git push origin feature/your-feature


Create a Pull Request:
Submit changes via GitHub for review.



Ensure code follows the existing style with clear comments.
License
This project is licensed under the MIT License. See the LICENSE file for details.
Contact

Email: [Your Email Address]
GitHub Issues: Open an issue on this repository.


Thank you for exploring the Dormitory Management System! This tool aims to simplify dormitory administration with a solid foundation for future enhancements.
