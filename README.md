# Dormitory Management System

The **Dormitory Management System** is a powerful C++ console-based application designed to streamline dormitory operations for university or residential administrators. It provides comprehensive management of students, employees, visitors, patrols, incidents, maintenance requests, payments, and rooms, with a modular design, robust input validation, and file-based data persistence using `#//#` separators. The system features a colorful, menu-driven console interface for enhanced usability.

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


# Dormitory Management System

## Application Structure (Tree)

```plaintext
Dormitory Management System
├── Header Files (Classes and Utilities)
│   ├── clsBase.h
│   │   └── ShowHeader(): Displays screen title with color formatting
│   ├── clsInputValidate.h
│   │   ├── ReadString(): Reads and validates string input
│   │   ├── ReadNumber(): Reads and validates numeric input
│   │   ├── ReadNumberInRange(): Ensures number within range
│   │   ├── ReadEnum(): Validates enum inputs (e.g., status, meal plan)
│   ├── clsString.h
│   │   ├── Split(): Splits strings by `#//#` delimiter
│   │   ├── Join(): Combines strings with `#//#` delimiter
│   │   ├── Trim(): Removes leading/trailing whitespace
│   ├── clsUtil.h
│   │   ├── GenerateRandomID(): Creates unique IDs
│   │   ├── ReadFileLines(): Reads text file into vector
│   │   ├── WriteFileLines(): Writes vector to text file
│   │   ├── ResetScreen(): Clears console and sets default colors
│   │   ├── SetColor(): Applies color to console output (Green, White, Blue, Yellow, Red)
│   ├── clsVisitor.h
│   │   ├── SetFirstName(), GetFirstName(): Manage first name
│   │   ├── SetLastName(), GetLastName(): Manage last name
│   │   ├── SetVisitPurpose(), GetVisitPurpose(): Manage visit purpose
│   │   ├── SetVisitedDepartment(), GetVisitedDepartment(): Manage department
│   │   ├── SetVisitedRoom(), GetVisitedRoom(): Manage room number
│   │   ├── SetVisitorStatus(), GetVisitorStatus(): Manage status (Inside/Exited)
│   │   ├── SetVisitTime(), GetVisitTime(): Manage visit timestamp
│   │   ├── SetExitTime(), GetExitTime(): Manage exit timestamp
│   │   ├── Save(): Saves visitor data
│   │   ├── Find(): Retrieves visitor by ID
│   │   ├── FilterByName(): Filters visitors by name
│   │   ├── FilterByDepartment(): Filters by department
│   │   ├── FilterByDate(): Filters by visit date
│   ├── clsUpdateVisitorInfoScreen.h
│   │   ├── ShowUpdateVisitorScreen(): Displays update menu
│   │   ├── UpdateField(): Updates specific field
│   │   ├── UpdateAll(): Updates all fields
│   ├── clsUpdateDormStudentScreen.h
│   │   ├── ShowUpdateDormStudentScreen(): Displays update menu
│   │   ├── UpdateField(): Updates specific field
│   │   ├── UpdateAll(): Updates all fields
│   ├── clsUpdateEmployeeInfoScreen.h
│   │   ├── ShowUpdateEmployeeScreen(): Displays update menu
│   │   ├── UpdateField(): Updates specific field
│   │   ├── UpdateAll(): Updates all fields
│   ├── clsUpdateIncidentScreen.h
│   │   ├── ShowUpdateIncidentScreen(): Displays update menu
│   │   ├── UpdateField(): Updates specific field
│   │   ├── UpdateAll(): Updates all fields
│   ├── clsViewAllPatrolSchedulesScreen.h
│   │   ├── ShowPatrolSchedulesScreen(): Displays all schedules
│   │   ├── PrintTable(): Formats table with headers
│   ├── clsViewPatrolLogsScreen.h
│   │   ├── ShowPatrolLogsScreen(): Displays all patrols
│   │   ├── ShowCompletedPatrols(): Filters completed patrols
│   │   ├── PrintTable(): Formats table
│   ├── clsViewAllRequestsScreen.h
│   │   ├── ShowRequestsScreen(): Displays all requests
│   │   ├── PrintTable(): Formats table with headers
│   ├── clsVisitorLogListScreen.h
│   │   ├── ShowVisitorLogListScreen(): Displays all visitor logs
│   │   ├── PrintTable(): Formats table with headers
│   ├── clsLogin.h
│   │   ├── Find(): Authenticates user
│   │   ├── SaveLoginSession(): Logs session
│   ├── Global.h
│   │   ├── Colors: Defines Green, White, Blue, Yellow, Red
│   ├── GlobalLogin.h
│   │   ├── CurrentUser: Tracks current logged-in user
├── Source Files
│   ├── main.cpp: Entry point, initializes main menu
│   ├── Other *.cpp: Implement header file functions
├── Data Files
│   ├── StudentsDormData.txt: Student records (ID, name, dorm, room, bed, status, meal plan, academic details)
│   ├── DormEmployeeData.txt: Employee records (ID, residence, dept, job title, salary, shift, status)
│   ├── VisitorsData.txt: Visitor logs (ID, name, purpose, dept, room, status, times)
│   ├── PatrolSchedules.txt: Patrol schedules (ID, security ID, location, start/end times, status)
│   ├── IncidentReports.txt: Incident reports (ID, type, description, severity, status, security ID, date)
│   ├── MaintenanceRequests.txt: Maintenance requests (ID, dorm, room, issue type, priority, status, staff, date)
│   ├── LoginData.txt: User credentials (username, password, role ID)
│   ├── RegisterLogins.txt: Login sessions (timestamp, username, password, role ID, logout time)
│   ├── StudentsDormComplaints.txt: Complaints (ID, dorm ID, date, room, issue, priority, status)
│   ├── RoomsData.txt: Room details (dorm, floor, room number, capacity, occupants, status)
│   ├── ShiftsSchedulesData.txt: Shift schedules (employee ID, residence, shift, date)
│   ├── SecuritiesData.txt: Security assignments (ID, employee ID, building, status, supervisor ID, date)
│   ├── DormPaymentsData.txt: Payments (ID, dorm ID, date, amount, purpose, status, method)
└── README.md


Main Menu
├── [1] Update Visitor Information
│   ├── Features: Update visitor records by ID
│   │   ├── Sub-Features
│   │   │   ├── Update First Name
│   │   │   ├── Update Last Name
│   │   │   ├── Update Visit Purpose (e.g., Meeting, Delivery, Interview)
│   │   │   ├── Update Visited Department (e.g., Administration, HR)
│   │   │   ├── Update Visited Room
│   │   │   ├── Update Visitor Status (Inside, Exited)
│   │   │   ├── Update All Fields
│   │   ├── Functions
│   │   │   ├── ShowUpdateVisitorScreen(): Displays menu (clsUpdateVisitorInfoScreen.h)
│   │   │   ├── UpdateField(): Updates specific field
│   │   │   ├── UpdateAll(): Updates all fields
│   │   │   ├── Save(): Writes to VisitorsData.txt (clsVisitor.h)
│   │   │   ├── Find(): Validates visitor ID (clsVisitor.h)
│   │   ├── Validation: Checks ID existence, valid inputs via clsInputValidate
│   │   ├── File: VisitorsData.txt
├── [2] Update Dorm Student
│   ├── Features: Update student dormitory records by ID
│   │   ├── Sub-Features
│   │   │   ├── Update Dorm Building (e.g., OceanView, CoralBay)
│   │   │   ├── Update Room Number
│   │   │   ├── Update Bed Number
│   │   │   ├── Update Status (Checked_out, Active, Suspended, Transferred, Pending, NoStatus)
│   │   │   ├── Update Meal Plan (NoMeal, Full, Half)
│   │   │   ├── Update All Fields
│   │   ├── Functions
│   │   │   ├── ShowUpdateDormStudentScreen(): Displays menu (clsUpdateDormStudentScreen.h)
│   │   │   ├── UpdateField(): Updates specific field
│   │   │   ├── UpdateAll(): Updates all fields
│   │   │   ├── Save(): Writes to StudentsDormData.txt
│   │   │   ├── Find(): Validates student ID
│   │   ├── Validation: Checks ID, uses "skip" to retain data (clsInputValidate)
│   │   ├── File: StudentsDormData.txt
├── [3] Update Employee Info
│   ├── Features: Update employee records by ID
│   │   ├── Sub-Features
│   │   │   ├── Update Residence Name (e.g., OceanView, Seaside)
│   │   │   ├── Update Residence Department (e.g., Maintenance, Security)
│   │   │   ├── Update Job Title (e.g., Security Supervisor, Cleaner)
│   │   │   ├── Update Salary
│   │   │   ├── Update Shift
│   │   │   ├── Update Status (Active, Inactive)
│   │   │   ├── Update All Fields
│   │   ├── Functions
│   │   │   ├── ShowUpdateEmployeeScreen(): Displays menu (clsUpdateEmployeeInfoScreen.h)
│   │   │   ├── UpdateField(): Updates specific field
│   │   │   ├── UpdateAll(): Updates all fields
│   │   │   ├── Save(): Writes to DormEmployeeData.txt
│   │   │   ├── Find(): Validates employee ID
│   │   ├── Validation: Checks ID, valid inputs (clsInputValidate)
│   │   ├── File: DormEmployeeData.txt
├── [4] Update Incident
│   ├── Features: Update incident reports by ID
│   │   ├── Sub-Features
│   │   │   ├── Update Incident Type (e.g., Unauthorized Access, Fire Alarm)
│   │   │   ├── Update Description
│   │   │   ├── Update Severity (Low, Medium, High)
│   │   │   ├── Update Status (Open, In Progress, Resolved, Closed)
│   │   │   ├── Update Security ID
│   │   │   ├── Update All Fields
│   │   │   ├── Exit
│   │   ├── Functions
│   │   │   ├── ShowUpdateIncidentScreen(): Displays menu (clsUpdateIncidentScreen.h)
│   │   │   ├── UpdateField(): Updates specific field
│   │   │   ├── UpdateAll(): Updates all fields
│   │   │   ├── Save(): Writes to IncidentReports.txt
│   │   │   ├── Find(): Validates incident ID
│   │   ├── Validation: Checks ID, valid inputs (clsInputValidate)
│   │   ├── File: IncidentReports.txt
├── [5] View All Patrol Schedules
│   ├── Features: Display all patrol schedules in a table
│   │   ├── Sub-Features
│   │   │   ├── View Patrol ID
│   │   │   ├── View Security ID
│   │   │   ├── View Start Time
│   │   │   ├── View End Time
│   │   │   ├── View Patrol Status (Scheduled, In Progress, Completed, Cancelled)
│   │   │   ├── View Patrol Location
│   │   ├── Functions
│   │   │   ├── ShowPatrolSchedulesScreen(): Loads data (clsViewAllPatrolSchedulesScreen.h)
│   │   │   ├── PrintTable(): Formats table with color-coded headers
│   │   ├── File: PatrolSchedules.txt
├── [6] View Patrol Logs
│   ├── Features: Display all and completed patrol logs
│   │   ├── Sub-Features
│   │   │   ├── View All Patrols (same columns as schedules)
│   │   │   ├── View Completed Patrols Only
│   │   ├── Functions
│   │   │   ├── ShowPatrolLogsScreen(): Displays all patrols (clsViewPatrolLogsScreen.h)
│   │   │   ├── ShowCompletedPatrols(): Filters completed patrols
│   │   │   ├── PrintTable(): Formats table
│   │   ├── File: PatrolSchedules.txt
├── [7] View All Requests
│   ├── Features: Display all maintenance requests in a table
│   │   ├── Sub-Features
│   │   │   ├── View Request ID
│   │   │   ├── View Dorm Building
│   │   │   ├── View Room
│   │   │   ├── View Issue Type
│   │   │   ├── View Priority
│   │   │   ├── View Status
│   │   │   ├── View Assigned Staff ID
│   │   │   ├── View Request Date
│   │   ├── Functions
│   │   │   ├── ShowRequestsScreen(): Loads data (clsViewAllRequestsScreen.h)
│   │   │   ├── PrintTable(): Formats table with color-coded headers
│   │   ├── File: MaintenanceRequests.txt
├── [8] View Visitor Log List
│   ├── Features: Display all visitor logs in a table
│   │   ├── Sub-Features
│   │   │   ├── View Visitor ID
│   │   │   ├── View Full Name
│   │   │   ├── View Visit Purpose
│   │   │   ├── View Department
│   │   │   ├── View Room
│   │   │   ├── View Status
│   │   │   ├── View Visit Time
│   │   │   ├── View Exit Time
│   │   ├── Functions
│   │   │   ├── ShowVisitorLogListScreen(): Loads data (clsVisitorLogListScreen.h)
│   │   │   ├── PrintTable(): Formats table with color-coded headers
│   │   ├── File: VisitorsData.txt
├── [9] Add New Student
│   ├── Features: Create new student record
│   │   ├── Sub-Features
│   │   │   ├── Set ID, Name, Contact Details
│   │   │   ├── Set Dorm Building, Room, Bed
│   │   │   ├── Set Status, Meal Plan
│   │   │   ├── Set Academic Details (university, faculty, dept, year, section)
│   │   │   ├── Set Check-In/Check-Out Dates
│   │   ├── Functions
│   │   │   ├── AddStudent(): Creates record
│   │   │   ├── Save(): Writes to StudentsDormData.txt
│   │   │   ├── GenerateRandomID(): Creates unique ID (clsUtil.h)
│   │   ├── Validation: Ensures unique ID, valid inputs (clsInputValidate)
│   │   ├── File: StudentsDormData.txt
├── [10] Add New Employee
│   ├── Features: Create new employee record
│   │   ├── Sub-Features
│   │   │   ├── Set ID, Name, Contact Details
│   │   │   ├── Set Residence, Department, Job Title
│   │   │   ├── Set Salary, Shift, Status
│   │   ├── Functions
│   │   │   ├── AddEmployee(): Creates record
│   │   │   ├── Save(): Writes to DormEmployeeData.txt
│   │   │   ├── GenerateRandomID(): Creates unique ID (clsUtil.h)
│   │   ├── Validation: Ensures unique ID, valid inputs (clsInputValidate)
│   │   ├── File: DormEmployeeData.txt
├── [11] Add New Visitor
│   ├── Features: Create new visitor record
│   │   ├── Sub-Features
│   │   │   ├── Set ID, Name
│   │   │   ├── Set Visit Purpose, Department, Room
│   │   │   ├── Set Status, Visit/Exit Times
│   │   ├── Functions
│   │   │   ├── AddVisitor(): Creates record (clsVisitor.h)
│   │   │   ├── Save(): Writes to VisitorsData.txt
│   │   │   ├── GenerateRandomID(): Creates unique ID (clsUtil.h)
│   │   ├── Validation: Ensures unique ID, valid inputs (clsInputValidate)
│   │   ├── File: VisitorsData.txt
├── [12] Add New Incident
│   ├── Features: Create new incident report
│   │   ├── Sub-Features
│   │   │   ├── Set ID, Type, Description
│   │   │   ├── Set Severity, Status, Security ID
│   │   │   ├── Set Date
│   │   ├── Functions
│   │   │   ├── AddIncident(): Creates report
│   │   │   ├── Save(): Writes to IncidentReports.txt
│   │   │   ├── GenerateRandomID(): Creates unique ID (clsUtil.h)
│   │   ├── Validation: Ensures unique ID, valid inputs (clsInputValidate)
│   │   ├── File: IncidentReports.txt
├── [13] Add New Maintenance Request
│   ├── Features: Create new maintenance request
│   │   ├── Sub-Features
│   │   │   ├── Set ID, Dorm Building, Room
│   │   │   ├── Set Issue Type, Priority, Status
│   │   │   ├── Set Assigned Staff ID, Request Date
│   │   ├── Functions
│   │   │   ├── AddRequest(): Creates request
│   │   │   ├── Save(): Writes to MaintenanceRequests.txt
│   │   │   ├── GenerateRandomID(): Creates unique ID (clsUtil.h)
│   │   ├── Validation: Ensures unique ID, valid inputs (clsInputValidate)
│   │   ├── File: MaintenanceRequests.txt
├── [14] Add New Payment
│   ├── Features: Record new payment
│   │   ├── Sub-Features
│   │   │   ├── Set ID, Dorm ID, Amount
│   │   │   ├── Set Purpose, Status, Payment Method
│   │   │   ├── Set Date
│   │   ├── Functions
│   │   │   ├── AddPayment(): Creates payment record
│   │   │   ├── Save(): Writes to DormPaymentsData.txt
│   │   │   ├── GenerateRandomID(): Creates unique ID (clsUtil.h)
│   │   ├── Validation: Ensures unique ID, valid inputs (clsInputValidate)
│   │   ├── File: DormPaymentsData.txt
├── [15] Add New Room
│   ├── Features: Create new room record
│   │   ├── Sub-Features
│   │   │   ├── Set Dorm, Floor, Room Number
│   │   │   ├── Set Capacity, Occupants, Status
│   │   ├── Functions
│   │   │   ├── AddRoom(): Creates room record
│   │   │   ├── Save(): Writes to RoomsData.txt
│   │   │   ├── GenerateRandomID(): Creates unique ID (clsUtil.h)
│   │   ├── Validation: Ensures valid inputs (clsInputValidate)
│   │   ├── File: RoomsData.txt
├── [16] Add New Complaint
│   ├── Features: Record new student complaint
│   │   ├── Sub-Features
│   │   │   ├── Set ID, Dorm ID, Room
│   │   │   ├── Set Issue, Priority, Status
│   │   │   ├── Set Date
│   │   ├── Functions
│   │   │   ├── AddComplaint(): Creates complaint record
│   │   │   ├── Save(): Writes to StudentsDormComplaints.txt
│   │   │   ├── GenerateRandomID(): Creates unique ID (clsUtil.h)
│   │   ├── Validation: Ensures valid inputs (clsInputValidate)
│   │   ├── File: StudentsDormComplaints.txt
├── [17] Login
│   ├── Features: Authenticate users with role-based access
│   │   ├── Sub-Features
│   │   │   ├── Enter Username/Password
│   │   │   ├── Assign Role (admin, securitychief, financemanager, studentofficer)
│   │   │   ├── Track Login Session
│   │   ├── Functions
│   │   │   ├── Find(): Authenticates user (clsLogin.h)
│   │   │   ├── SaveLoginSession(): Logs to RegisterLogins.txt
│   │   ├── Validation: Checks credentials (clsInputValidate)
│   │   ├── File: LoginData.txt, RegisterLogins.txt
├── [18] Logout
│   ├── Features: End user session
│   │   ├── Sub-Features
│   │   │   ├── Record Logout Time
│   │   │   ├── Clear CurrentUser
│   │   ├── Functions
│   │   │   ├── SaveLoginSession(): Updates RegisterLogins.txt (clsLogin.h)
│   │   ├── File: RegisterLogins.txt
└── [19] Exit
    ├── Features: Save changes and exit program
    │   ├── Sub-Features
    │   │   ├── Save all modified records
    │   │   ├── Clear console
    │   ├── Functions
    │   │   ├── Save(): Writes to respective data files
    │   │   ├── ResetScreen(): Clears console (clsUtil.h)
    │   ├── Files: All data files (*.txt)


