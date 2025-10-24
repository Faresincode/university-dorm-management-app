# university-dorm-management-app
Welcome to the 👉  Dormitory Management System, a robust C++ application designed to streamline the management of dormitory operations  🔥 , including student records, employee data, visitor logs, patrol schedules, incident reports, and maintenance requests

 This system is tailored for university or residential dormitory administrators to efficiently track and manage various aspects of dormitory operations.
Table of Contents

Project Overview
Features
System Requirements
Installation
File Structure
Usage
Key Components
Contributing
License
Contact

Project Overview
The Dormitory Management System is a console-based application built in C++ to manage dormitory-related data and operations. It provides a user-friendly interface for administrators to perform tasks such as updating student information, tracking visitor logs, scheduling security patrols, and handling maintenance requests. The system uses file-based storage to persist data and includes input validation, error handling, and a modular design for maintainability.
Features

Student Management: Add, update, and view dormitory student records, including dorm building, room number, bed number, status, and meal plans.
Employee Management: Manage employee details such as residence name, department, job title, salary, shift, and status.
Visitor Tracking: Log and update visitor information, including visit purpose, department, room, and status (Inside/Exited).
Patrol Scheduling: View and manage security patrol schedules, including start/end times, locations, and status.
Incident Reporting: Record and update incident reports with details like type, description, severity, and status.
Maintenance Requests: Track maintenance requests with issue types, priority, and assigned staff.
Data Persistence: Store data in text files (e.g., StudentsDormData.txt, VisitorsData.txt) for easy retrieval and updates.
Input Validation: Robust validation to ensure data integrity using the clsInputValidate class.
Colorful Console UI: Enhanced user experience with color-coded console outputs (Green, White, Blue, Yellow, Red).

System Requirements

Operating System: Windows, Linux, or macOS
Compiler: C++11 or later (e.g., g++, MSVC)
Dependencies: Standard C++ libraries (iostream, vector, fstream, iomanip, etc.)
Disk Space: Minimal (text-based data files)
Console/Terminal: For running the application

Installation
Since you're new to GitHub, here’s a step-by-step guide to set up the project locally:

Clone the Repository:

If you have Git installed, open a terminal and run:git clone https://github.com/your-username/dormitory-management-system.git


Alternatively, download the ZIP file from GitHub and extract it.


Navigate to the Project Directory:
cd dormitory-management-system


Compile the Code:

Ensure you have a C++ compiler installed (e.g., g++).
Compile all .cpp files (assuming main.cpp is the entry point):g++ *.cpp -o DormitoryManagementSystem


For Windows (with MinGW):g++ *.cpp -o DormitoryManagementSystem.exe




Run the Application:

On Linux/macOS:./DormitoryManagementSystem


On Windows:DormitoryManagementSystem.exe




Ensure Data Files:

The project uses text files (e.g., StudentsDormData.txt, VisitorsData.txt) for data storage. Ensure these files are in the same directory as the executable. They are included in the repository.



File Structure
Here’s an overview of the key files in the project:
dormitory-management-system/
│
├── *.h                # Header files for classes (e.g., clsVisitor.h, clsUpdateDormStudentScreen.h)
├── *.cpp              # Source files (implementation of classes and main program)
├── *.txt              # Data files for storing records (e.g., StudentsDormData.txt, VisitorsData.txt)
├── README.md          # This file

Key Header Files

clsVisitor.h: Manages visitor data and operations.
clsUpdateVisitorInfoScreen.h: Interface for updating visitor information.
clsUpdateDormStudentScreen.h: Interface for updating student dormitory records.
clsUpdateEmployeeInfoScreen.h: Interface for updating employee information.
clsUpdateIncidentScreen.h: Interface for updating incident reports.
clsViewAllPatrolSchedulesScreen.h: Displays all patrol schedules.
clsViewPatrolLogsScreen.h: Displays patrol logs filtered by status.
clsViewAllRequestsScreen.h: Displays all maintenance requests.
clsVisitorLogListScreen.h: Displays visitor logs.
clsUtil.h: Utility functions for random number generation, file operations, and console formatting.
Global.h: Global constants and color definitions.
GlobalLogin.h: Manages the current logged-in user.

Key Data Files

StudentsDormData.txt: Stores student information (e.g., ID, name, dorm details).
DormEmployeeData.txt: Stores employee information.
VisitorsData.txt: Stores visitor logs.
PatrolSchedules.txt: Stores patrol schedules.
IncidentReports.txt: Stores incident reports.
MaintenanceRequests.txt: Stores maintenance requests.
LoginData.txt: Stores user login credentials.
RegisterLogins.txt: Tracks login sessions.
StudentsDormComplaints.txt: Stores student complaints.
RoomsData.txt: Stores room information.
ShiftsSchedulesData.txt: Stores employee shift schedules.
SecuritiesData.txt: Stores security personnel data.
DormPaymentsData.txt: Stores payment records.

Usage

Run the Program:

Launch the compiled executable.
The console will display a menu-driven interface.


Login:

Use credentials from LoginData.txt (e.g., username: admin, password: 3456).
The system supports multiple roles (e.g., securitychief, financemanager).


Navigate Menus:

Use numeric inputs (e.g., 1-7) to select options for updating records, viewing logs, or managing schedules.
Example: To update a visitor’s info, select the “Update Visitor Information” option, enter the Visitor ID, and choose fields to update.


Data Management:

Add, update, or view records for students, employees, visitors, patrols, incidents, or maintenance requests.
Use the skip option in update screens to retain existing data.


Exit:

Follow prompts to save changes and exit the program.



Key Components

clsBase: Base class for screen interfaces, providing common functionality like screen headers.
clsInputValidate: Validates user inputs (strings, numbers, etc.) to ensure data integrity.
clsString: Utility for string manipulation (e.g., splitting data for file operations).
clsUtil: Provides utility functions like random ID generation, file I/O, and console formatting.
Data Persistence: All records are stored in text files with a #//# separator for easy parsing.

Contributing
Contributions are welcome! If you’re new to GitHub, here’s how you can contribute:

Fork the Repository:
Click the “Fork” button on the GitHub



