# Dormitory Management System

The **Dormitory Management System** is a powerful C++ console-based application designed to streamline dormitory operations for university or residential administrators. It provides comprehensive management of students, employees, visitors, patrols, incidents, maintenance requests, payments, and rooms, with a modular design, robust input validation, and file-based data persistence using `#//#` separators. The system features a colorful, menu-driven console interface for enhanced usability.

## Features

Below is a detailed breakdown of all features, organized in tables for clarity, including each management screen and its options. The application uses structured data handling and a user-friendly interface to manage dormitory operations efficiently.

| **Feature Category** | **Description** | **Key Details** | **Related Screen** | **Data File** |
|----------------------|-----------------|-----------------|---------------------|---------------|
| **Student Management** | Manage student records, academic details, complaints, and check-in/check-out dates. | - Add, update, view records<br>- Track university, faculty, dept, year, section<br>- Status: Checked_out, Active, Suspended, Transferred, Pending, NoStatus<br>- Meal plans: NoMeal, Full, Half | Update Dorm Student Screen | `StudentsDormData.txt`, `StudentsDormComplaints.txt` |
| **Employee Management** | Handle employee details, shifts, and security assignments. | - Add, update, view records<br>- Track residence, dept, job title, salary, shift, status | Update Employee Info Screen | `DormEmployeeData.txt`, `ShiftsSchedulesData.txt`, `SecuritiesData.txt` |
| **Visitor Tracking** | Log and track visitor information, filter by name/dept/date. | - Add, update, view records<br>- Track purpose, dept, room, status (Inside/Exited), visit/exit times | Update Visitor Information Screen, Visitor Log List Screen | `VisitorsData.txt` |
| **Patrol Scheduling** | Manage security patrol schedules and filter completed patrols. | - Add, view schedules<br>- Track patrol ID, security ID, location, start/end times, status | View All Patrol Schedules Screen, View Patrol Logs Screen | `PatrolSchedules.txt` |
| **Incident Reporting** | Record and manage incident reports with severity and status. | - Add, update, view reports<br>- Severity: Low, Medium, High<br>- Status: Open, In Progress, Resolved, Closed | Update Incident Screen | `IncidentReports.txt` |
| **Maintenance Requests** | Track maintenance requests with priority and status. | - Add, update, view requests<br>- Track dorm, room, issue type, priority, assigned staff, date | View All Requests Screen | `MaintenanceRequests.txt` |
| **Login System** | Role-based access with session tracking. | - Roles: admin, securitychief, financemanager, etc.<br>- Track login sessions | N/A | `LoginData.txt`, `RegisterLogins.txt` |
| **Payment Management** | Record and track payment details. | - Track payment ID, dorm ID, date, amount, purpose, status, method | N/A | `DormPaymentsData.txt` |
| **Room Management** | Manage room assignments and details. | - Track dorm, floor, room number, capacity, occupants, status | N/A | `RoomsData.txt` |
| **Utility Features** | Support functions for ID generation, validation, and UI. | - Random ID generation<br>- Input validation for strings, numbers, enums<br>- Color-coded UI (Green, White, Blue, Yellow, Red)<br>- File operations<br>- Screen reset | N/A | N/A |

## Screen Structure

The application uses a menu-driven interface with screens inheriting from `clsBase` for consistent headers and navigation. Each screen is detailed below with its purpose, menu options, and features, presented in a structured table format.

| **Screen Name** | **File** | **Purpose** | **Menu Options** | **Features** |
|------------------|----------|-------------|------------------|--------------|
| **Update Visitor Information** | `clsUpdateVisitorInfoScreen.h` | Update visitor records by ID | 1. First Name<br>2. Last Name<br>3. Visit Purpose<br>4. Visited Department<br>5. Visited Room<br>6. Visitor Status (Inside/Exited)<br>7. Update All | - Validates visitor ID<br>- Selective/full updates<br>- "skip" option to retain data<br>- Saves to `VisitorsData.txt` |
| **Update Dorm Student** | `clsUpdateDormStudentScreen.h` | Update student dormitory records by ID | 1. Dorm Building<br>2. Room Number<br>3. Bed Number<br>4. Status (Checked_out, Active, Suspended, Transferred, Pending, NoStatus)<br>5. Meal Plan (NoMeal, Full, Half)<br>6. Update All | - Validates student ID<br>- "skip" option<br>- Saves to `StudentsDormData.txt` |
| **Update Employee Info** | `clsUpdateEmployeeInfoScreen.h` | Update employee records by ID | 1. Residence Name<br>2. Residence Department<br>3. Job Title<br>4. Salary<br>5. Shift<br>6. Status<br>7. Update All | - Validates employee ID<br>- Saves to `DormEmployeeData.txt` |
| **Update Incident** | `clsUpdateIncidentScreen.h` | Update incident reports by ID | 1. Incident Type<br>2. Description<br>3. Severity (Low, Medium, High)<br>4. Status (Open, In Progress, Resolved, Closed)<br>5. Security ID<br>6. Update All<br>7. Exit | - Validates incident ID<br>- Saves to `IncidentReports.txt` |
| **View All Patrol Schedules** | `clsViewAllPatrolSchedulesScreen.h` | Display all patrol schedules | N/A (Table Display) | - Columns: Patrol ID, Security ID, Start Time, End Time, Patrol Status, Location<br>- Loads from `PatrolSchedules.txt`<br>- Color-coded table |
| **View Patrol Logs** | `clsViewPatrolLogsScreen.h` | Display all and completed patrol logs | N/A (Table Display) | - Same columns as Patrol Schedules<br>- Filters completed patrols<br>- Loads from `PatrolSchedules.txt` |
| **View All Requests** | `clsViewAllRequestsScreen.h` | Display all maintenance requests | N/A (Table Display) | - Columns: Request ID, Dorm Building, Room, Issue Type, Priority, Status, Assigned Staff ID, Request Date<br>- Loads from `MaintenanceRequests.txt`<br>- Color-coded table |
| **Visitor Log List** | `clsVisitorLogListScreen.h` | Display all visitor logs | N/A (Table Display) | - Columns: Visitor ID, Full Name, Visit Purpose, Department, Room, Status, Visit Time, Exit Time<br>- Loads from `VisitorsData.txt`<br>- Color-coded table |

## System Requirements
| **Requirement** | **Details** |
|-----------------|-------------|
| Operating System | Windows, Linux, macOS |
| Compiler | C++11 or later (e.g., g++, MSVC) |
| Dependencies | Standard C++ libraries (`iostream`, `vector`, `fstream`, `iomanip`, etc.) |
| Disk Space | Minimal (text-based data files) |
| Console/Terminal | Required for running the application |




dormitory-management-system/
│
├── *.h                # Header files (e.g., clsVisitor.h)
├── *.cpp              # Source files for implementation
├── *.txt              # Data files (e.g., StudentsDormData.txt)
├── README.md          # This file

Dormitory Management System
├── Header Files (Classes and Utilities)
│   ├── clsBase.h
│   │   └── Purpose: Base class for all screens, providing consistent header display
│   │       ├── ShowHeader(): Displays screen title with color formatting
│   ├── clsInputValidate.h
│   │   └── Purpose: Validates user inputs for data integrity
│   │       ├── ReadString(): Reads and validates string input
│   │       ├── ReadNumber(): Reads and validates numeric input
│   │       ├── ReadNumberInRange(): Ensures number is within a specified range
│   │       ├── ReadEnum(): Validates enum inputs (e.g., status, meal plan)
│   ├── clsString.h
│   │   └── Purpose: Handles string operations for file parsing
│   │       ├── Split(): Splits strings by #//# delimiter
│   │       ├── Join(): Combines strings with #//# delimiter
│   │       ├── Trim(): Removes leading/trailing whitespace
│   ├── clsUtil.h
│   │   └── Purpose: Provides utility functions for random IDs, file I/O, and console formatting
│   │       ├── GenerateRandomID(): Creates unique IDs
│   │       ├── ReadFileLines(): Reads text file into vector
│   │       ├── WriteFileLines(): Writes vector to text file
│   │       ├── ResetScreen(): Clears console and sets default colors
│   │       ├── SetColor(): Applies color to console output (Green, White, Blue, Yellow, Red)
│   ├── clsVisitor.h
│   │   └── Purpose: Manages visitor data and operations
│   │       ├── SetFirstName(), GetFirstName(): Manage first name
│   │       ├── SetLastName(), GetLastName(): Manage last name
│   │       ├── SetVisitPurpose(), GetVisitPurpose(): Manage visit purpose
│   │       ├── SetVisitedDepartment(), GetVisitedDepartment(): Manage department
│   │       ├── SetVisitedRoom(), GetVisitedRoom(): Manage room number
│   │       ├── SetVisitorStatus(), GetVisitorStatus(): Manage status (Inside/Exited)
│   │       ├── SetVisitTime(), GetVisitTime(): Manage visit timestamp
│   │       ├── SetExitTime(), GetExitTime(): Manage exit timestamp
│   │       ├── Save(): Saves visitor data to VisitorsData.txt
│   │       ├── Find(): Retrieves visitor by ID
│   ├── clsUpdateVisitorInfoScreen.h
│   │   └── Purpose: Updates visitor records via menu
│   │       ├── ShowUpdateVisitorScreen(): Displays menu for updating visitor details
│   │       ├── UpdateField(): Updates specific field with validation
│   │       ├── UpdateAll(): Updates all fields
│   ├── clsUpdateDormStudentScreen.h
│   │   └── Purpose: Updates student dormitory records via menu
│   │       ├── ShowUpdateDormStudentScreen(): Displays menu for updating student details
│   │       ├── UpdateField(): Updates specific field (e.g., dorm, room, status)
│   │       ├── UpdateAll(): Updates all fields
│   ├── clsUpdateEmployeeInfoScreen.h
│   │   └── Purpose: Updates employee records via menu
│   │       ├── ShowUpdateEmployeeScreen(): Displays menu for updating employee details
│   │       ├── UpdateField(): Updates specific field (e.g., job title, salary)
│   │       ├── UpdateAll(): Updates all fields
│   ├── clsUpdateIncidentScreen.h
│   │   └── Purpose: Updates incident reports via menu
│   │       ├── ShowUpdateIncidentScreen(): Displays menu for updating incident details
│   │       ├── UpdateField(): Updates specific field (e.g., type, severity)
│   │       ├── UpdateAll(): Updates all fields
│   ├── clsViewAllPatrolSchedulesScreen.h
│   │   └── Purpose: Displays all patrol schedules in a table
│   │       ├── ShowPatrolSchedulesScreen(): Loads and displays data from PatrolSchedules.txt
│   │       ├── PrintTable(): Formats table with color-coded headers
│   ├── clsViewPatrolLogsScreen.h
│   │   └── Purpose: Displays all and completed patrol logs
│   │       ├── ShowPatrolLogsScreen(): Displays all patrols
│   │       ├── ShowCompletedPatrols(): Filters and displays completed patrols
│   │       ├── PrintTable(): Reuses table formatting
│   ├── clsViewAllRequestsScreen.h
│   │   └── Purpose: Displays all maintenance requests in a table
│   │       ├── ShowRequestsScreen(): Loads and displays data from MaintenanceRequests.txt
│   │       ├── PrintTable(): Formats table with color-coded headers
│   ├── clsVisitorLogListScreen.h
│   │   └── Purpose: Displays all visitor logs in a table
│   │       ├── ShowVisitorLogListScreen(): Loads and displays data from VisitorsData.txt
│   │       ├── PrintTable(): Formats table with color-coded headers
│   ├── clsLogin.h
│   │   └── Purpose: Manages user login and authentication
│   │       ├── Find(): Authenticates user by username and password
│   │       ├── SaveLoginSession(): Logs session to RegisterLogins.txt
│   ├── Global.h
│   │   └── Purpose: Defines global constants and color codes
│   │       ├── Colors: Green, White, Blue, Yellow, Red
│   ├── GlobalLogin.h
│   │   └── Purpose: Tracks current logged-in user
│   │       ├── CurrentUser: Global clsLogin object
│
├── Source Files
│   └── *.cpp: Implementation of classes and main program logic
│       ├── main.cpp: Entry point, initializes main menu
│       ├── Other *.cpp: Implement respective header file functions
│
├── Data Files
│   ├── StudentsDormData.txt: Student records (ID, name, dorm, room, bed, status, meal plan, etc.)
│   ├── DormEmployeeData.txt: Employee records (ID, residence, dept, job title, salary, shift, status)
│   ├── VisitorsData.txt: Visitor logs (ID, name, purpose, dept, room, status, times)
│   ├── PatrolSchedules.txt: Patrol schedules (ID, security ID, location, start/end times, status)
│   ├── IncidentReports.txt: Incident reports (ID, type, description, severity, status, security ID, date)
│   ├── MaintenanceRequests.txt: Maintenance requests (ID, dorm, room, issue type, priority, status, staff, date)
│   ├── LoginData.txt: User credentials (username, password, role ID)
│   ├── RegisterLogins.txt: Login session logs (timestamp, username, password, role ID, logout time)
│   ├── StudentsDormComplaints.txt: Student complaints (ID, dorm ID, date, room, issue, priority, status)
│   ├── RoomsData.txt: Room details (dorm, floor, room number, capacity, occupants, status)
│   ├── ShiftsSchedulesData.txt: Employee shift schedules (employee ID, residence, shift, date)
│   ├── SecuritiesData.txt: Security personnel assignments (ID, employee ID, building, status, supervisor ID, date)
│   ├── DormPaymentsData.txt: Payment records (ID, dorm ID, date, amount, purpose, status, method)
│
└── README.md: This file


## Features

The following tables detail all features, including management screens, their menu options, and associated functions, ensuring a comprehensive overview of the application's capabilities.

| **Feature Category** | **Description** | **Key Functions** | **Related Screen** | **Data File** |
|----------------------|-----------------|-------------------|---------------------|---------------|
| **Student Management** | Manage student records, academic details, complaints, and residency status | - AddStudent(): Creates new student record<br>- UpdateStudent(): Modifies existing record<br>- FindStudent(): Retrieves by ID<br>- Save(): Writes to file<br>- ReadComplaint(): Loads complaints | Update Dorm Student Screen | `StudentsDormData.txt`, `StudentsDormComplaints.txt` |
| **Employee Management** | Handle employee details, shifts, and security roles | - AddEmployee(): Creates new employee<br>- UpdateEmployee(): Modifies record<br>- FindEmployee(): Retrieves by ID<br>- Save(): Writes to file<br>- AssignShift(): Manages shifts | Update Employee Info Screen | `DormEmployeeData.txt`, `ShiftsSchedulesData.txt`, `SecuritiesData.txt` |
| **Visitor Tracking** | Log and track visitor information, filter by criteria | - AddVisitor(): Creates new visitor<br>- UpdateVisitor(): Modifies record<br>- FindVisitor(): Retrieves by ID<br>- FilterByName/Dept/Date(): Filters logs<br>- Save(): Writes to file | Update Visitor Information Screen, Visitor Log List Screen | `VisitorsData.txt` |
| **Patrol Scheduling** | Manage security patrol schedules, filter completed patrols | - AddPatrol(): Creates new schedule<br>- UpdatePatrol(): Modifies schedule<br>- FindPatrol(): Retrieves by ID<br>- FilterCompleted(): Shows completed patrols<br>- Save(): Writes to file | View All Patrol Schedules Screen, View Patrol Logs Screen | `PatrolSchedules.txt` |
| **Incident Reporting** | Record and manage incident reports with severity/status | - AddIncident(): Creates new report<br>- UpdateIncident(): Modifies report<br>- FindIncident(): Retrieves by ID<br>- Save(): Writes to file | Update Incident Screen | `IncidentReports.txt` |
| **Maintenance Requests** | Track maintenance requests with priority/status | - AddRequest(): Creates new request<br>- UpdateRequest(): Modifies request<br>- FindRequest(): Retrieves by ID<br>- Save(): Writes to file | View All Requests Screen | `MaintenanceRequests.txt` |
| **Login System** | Role-based access with session tracking | - Authenticate(): Verifies credentials<br>- SaveLoginSession(): Logs session<br>- FindUser(): Retrieves user by username/password | N/A | `LoginData.txt`, `RegisterLogins.txt` |
| **Payment Management** | Record and track payment details | - AddPayment(): Creates new payment<br>- FindPayment(): Retrieves by ID<br>- Save(): Writes to file | N/A | `DormPaymentsData.txt` |
| **Room Management** | Manage room assignments and details | - AddRoom(): Creates new room<br>- UpdateRoom(): Modifies room details<br>- FindRoom(): Retrieves by dorm/floor/room<br>- Save(): Writes to file | N/A | `RoomsData.txt` |
| **Utility Features** | Support functions for ID generation, validation, UI | - GenerateRandomID(): Creates unique IDs<br>- ReadFileLines(): Reads file data<br>- WriteFileLines(): Writes to file<br>- ResetScreen(): Clears console<br>- SetColor(): Applies colors (Green, White, Blue, Yellow, Red)<br>- ValidateInput(): Ensures valid inputs | N/A | N/A |

## Screen Structure

Each screen is a class inheriting from `clsBase`, providing a consistent interface with color-coded headers and tables. Below are the management screens, their menu options, and associated functions.

| **Screen Name** | **File** | **Purpose** | **Menu Options** | **Key Functions** |
|------------------|----------|-------------|------------------|-------------------|
| **Update Visitor Information** | `clsUpdateVisitorInfoScreen.h` | Update visitor records by ID | 1. First Name<br>2. Last Name<br>3. Visit Purpose<br>4. Visited Department<br>5. Visited Room<br>6. Visitor Status (Inside/Exited)<br>7. Update All | - ShowUpdateVisitorScreen(): Displays menu<br>- UpdateField(): Updates specific field<br>- UpdateAll(): Updates all fields<br>- Save(): Writes to `VisitorsData.txt` |
| **Update Dorm Student** | `clsUpdateDormStudentScreen.h` | Update student dormitory records by ID | 1. Dorm Building<br>2. Room Number<br>3. Bed Number<br>4. Status (Checked_out, Active, Suspended, Transferred, Pending, NoStatus)<br>5. Meal Plan (NoMeal, Full, Half)<br>6. Update All | - ShowUpdateDormStudentScreen(): Displays menu<br>- UpdateField(): Updates specific field<br>- UpdateAll(): Updates all fields<br>- Save(): Writes to `StudentsDormData.txt` |
| **Update Employee Info** | `clsUpdateEmployeeInfoScreen.h` | Update employee records by ID | 1. Residence Name<br>2. Residence Department<br>3. Job Title<br>4. Salary<br>5. Shift<br>6. Status<br>7. Update All | - ShowUpdateEmployeeScreen(): Displays menu<br>- UpdateField(): Updates specific field<br>- UpdateAll(): Updates all fields<br>- Save(): Writes to `DormEmployeeData.txt` |
| **Update Incident** | `clsUpdateIncidentScreen.h` | Update incident reports by ID | 1. Incident Type<br>2. Description<br>3. Severity (Low, Medium, High)<br>4. Status (Open, In Progress, Resolved, Closed)<br>5. Security ID<br>6. Update All<br>7. Exit | - ShowUpdateIncidentScreen(): Displays menu<br>- UpdateField(): Updates specific field<br>- UpdateAll(): Updates all fields<br>- Save(): Writes to `IncidentReports.txt` |
| **View All Patrol Schedules** | `clsViewAllPatrolSchedulesScreen.h` | Display all patrol schedules | N/A (Table Display) | - ShowPatrolSchedulesScreen(): Loads data<br>- PrintTable(): Formats table (Patrol ID, Security ID, Start Time, End Time, Status, Location) |
| **View Patrol Logs** | `clsViewPatrolLogsScreen.h` | Display all and completed patrol logs | N/A (Table Display) | - ShowPatrolLogsScreen(): Displays all patrols<br>- ShowCompletedPatrols(): Filters completed patrols<br>- PrintTable(): Formats table |
| **View All Requests** | `clsViewAllRequestsScreen.h` | Display all maintenance requests | N/A (Table Display) | - ShowRequestsScreen(): Loads data<br>- PrintTable(): Formats table (Request ID, Dorm, Room, Issue Type, Priority, Status, Staff ID, Date) |
| **Visitor Log List** | `clsVisitorLogListScreen.h` | Display all visitor logs | N/A (Table Display) | - ShowVisitorLogListScreen(): Loads data<br>- PrintTable(): Formats table (Visitor ID, Name, Purpose, Dept, Room, Status, Visit/Exit Time) |




