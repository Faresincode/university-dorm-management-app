# Dormitory Management System

The **Dormitory Management System** is a powerful C++ console-based application designed to streamline dormitory operations for university or residential administrators. It provides comprehensive management of students, employees, visitors, patrols, incidents, maintenance requests, payments, and rooms, with a modular design, robust input validation, and file-based data persistence using `#//#` separators. The system features a colorful, menu-driven console interface for enhanced usability.

## Features
<img width="500" height="400" alt="client-list-screnn" src="https://github.com/Faresincode/university-dorm-management-app/blob/d2049f91475ffceae871bcfd9fc891601503b8df/images/admin-panel-screen.png" />



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

Manage Student Menu Screen
<img width="800" height="400" alt="client-list-screnn" src="https://github.com/Faresincode/university-dorm-management-app/blob/2a690497a33dae7ba3204db0b2641b27dd528d90/images/manage-student-menu-screen.png" />

Manage Employee Menu Screen
<img width="800" height="400" alt="client-list-screnn" src="https://github.com/Faresincode/university-dorm-management-app/blob/262d68e1149603f9bfc73b0d4c0edd67b893ceb1/images/manage-employee-menu-screen.png" />

Manage Finance Menu Screen
<img width="800" height="400" alt="client-list-screnn" src="https://github.com/Faresincode/university-dorm-management-app/blob/262d68e1149603f9bfc73b0d4c0edd67b893ceb1/images/manage-finance-menu-screen.png" />

Manage Rooms Menu Screen 
<img width="800" height="400" alt="client-list-screnn" src="https://github.com/Faresincode/university-dorm-management-app/blob/262d68e1149603f9bfc73b0d4c0edd67b893ceb1/images/manage-rooms-menu-screen.png" />


Manage Security Menu Screen
<img width="800" height="400" alt="client-list-screnn" src="https://github.com/Faresincode/university-dorm-management-app/blob/262d68e1149603f9bfc73b0d4c0edd67b893ceb1/images/manage-security-menu-screen.png" />

Manage Incident Reports Screen 
<img width="800" height="400" alt="client-list-screnn" src="https://github.com/Faresincode/university-dorm-management-app/blob/262d68e1149603f9bfc73b0d4c0edd67b893ceb1/images/manage-incident-reports-screen.png" />

Manage Patroles Schedules Screen 
<img width="800" height="400" alt="client-list-screnn" src="https://github.com/Faresincode/university-dorm-management-app/blob/262d68e1149603f9bfc73b0d4c0edd67b893ceb1/images/manage-patroles-schedules-screen.png" />

Manage Visitor Log Screen
<img width="800" height="400" alt="client-list-screnn" src="https://github.com/Faresincode/university-dorm-management-app/blob/262d68e1149603f9bfc73b0d4c0edd67b893ceb1/images/manage-visitor-log-screen.png" />

Manage Maintenance Menu Screen 
<img width="800" height="400" alt="client-list-screnn" src="https://github.com/Faresincode/university-dorm-management-app/blob/262d68e1149603f9bfc73b0d4c0edd67b893ceb1/images/manage-maintenance-menu-screen.png" />

Full Reports Menu Screen
<img width="800" height="400" alt="client-list-screnn" src="https://github.com/Faresincode/university-dorm-management-app/blob/262d68e1149603f9bfc73b0d4c0edd67b893ceb1/images/full-reports-menu-screen.png" />

Login Registers Screen
<img width="800" height="400" alt="client-list-screnn" src="https://github.com/Faresincode/university-dorm-management-app/blob/262d68e1149603f9bfc73b0d4c0edd67b893ceb1/images/login-registers-screen.png" />


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

<img width="400" height="500" alt="client-list-screnn" src="https://github.com/Faresincode/university-dorm-management-app/blob/262d68e1149603f9bfc73b0d4c0edd67b893ceb1/images/filter-visitor-logs-screen.png" />


## Application Structure (Tree)

```plaintext
Dormitory Management System
├── Main Menu
│   ├── [1] Update Visitor Information
│   │   ├── Features: Update visitor records by ID
│   │   │   ├── Sub-Menu
│   │   │   │   ├── [1] First Name: Update visitor's first name
│   │   │   │   ├── [2] Last Name: Update visitor's last name
│   │   │   │   ├── [3] Visit Purpose: Update purpose (e.g., Meeting, Delivery, Interview)
│   │   │   │   ├── [4] Visited Department: Update department (e.g., Administration, HR)
│   │   │   │   ├── [5] Visited Room: Update room number
│   │   │   │   ├── [6] Visitor Status: Update status (Inside, Exited)
│   │   │   │   ├── [7] Update All: Update all fields at once
│   │   │   ├── Validation: Checks ID existence, valid inputs, supports "skip" option
│   │   │   ├── File: VisitorsData.txt
│   ├── [2] Update Dorm Student
│   │   ├── Features: Update student dormitory records by ID
│   │   │   ├── Sub-Menu
│   │   │   │   ├── [1] Dorm Building: Update building (e.g., OceanView, CoralBay)
│   │   │   │   ├── [2] Room Number: Update room number
│   │   │   │   ├── [3] Bed Number: Update bed number
│   │   │   │   ├── [4] Status: Update status (Checked_out, Active, Suspended, Transferred, Pending, NoStatus)
│   │   │   │   ├── [5] Meal Plan: Update meal plan (NoMeal, Full, Half)
│   │   │   │   ├── [6] Update All: Update all fields at once
│   │   │   ├── Validation: Checks ID, supports "skip" option
│   │   │   ├── File: StudentsDormData.txt
│   ├── [3] Update Employee Info
│   │   ├── Features: Update employee records by ID
│   │   │   ├── Sub-Menu
│   │   │   │   ├── [1] Residence Name: Update residence (e.g., OceanView, Seaside)
│   │   │   │   ├── [2] Residence Department: Update department (e.g., Maintenance, Security)
│   │   │   │   ├── [3] Job Title: Update title (e.g., Security Supervisor, Cleaner)
│   │   │   │   ├── [4] Salary: Update salary amount
│   │   │   │   ├── [5] Shift: Update shift details
│   │   │   │   ├── [6] Status: Update status (Active, Inactive)
│   │   │   │   ├── [7] Update All: Update all fields at once
│   │   │   ├── Validation: Checks ID, valid inputs
│   │   │   ├── File: DormEmployeeData.txt
│   ├── [4] Update Incident
│   │   ├── Features: Update incident reports by ID
│   │   │   ├── Sub-Menu
│   │   │   │   ├── [1] Incident Type: Update type (e.g., Unauthorized Access, Fire Alarm)
│   │   │   │   ├── [2] Description: Update incident description
│   │   │   │   ├── [3] Severity: Update severity (Low, Medium, High)
│   │   │   │   ├── [4] Status: Update status (Open, In Progress, Resolved, Closed)
│   │   │   │   ├── [5] Security ID: Update assigned security ID
│   │   │   │   ├── [6] Update All: Update all fields at once
│   │   │   │   ├── [7] Exit: Return to main menu
│   │   │   ├── Validation: Checks ID, valid inputs
│   │   │   ├── File: IncidentReports.txt
│   ├── [5] View All Patrol Schedules
│   │   ├── Features: Display all patrol schedules in a table
│   │   │   ├── Sub-Features
│   │   │   │   ├── View Patrol ID
│   │   │   │   ├── View Security ID
│   │   │   │   ├── View Start Time
│   │   │   │   ├── View End Time
│   │   │   │   ├── View Patrol Status (Scheduled, In Progress, Completed, Cancelled)
│   │   │   │   ├── View Patrol Location
│   │   │   ├── Table Format: Color-coded headers (Green, White)
│   │   │   ├── File: PatrolSchedules.txt
│   ├── [6] View Patrol Logs
│   │   ├── Features: Display all and completed patrol logs
│   │   │   ├── Sub-Menu
│   │   │   │   ├── [1] View All Patrols: Show all patrols (same columns as schedules)
│   │   │   │   ├── [2] View Completed Patrols: Filter completed patrols only
│   │   │   ├── Table Format: Color-coded headers
│   │   │   ├── File: PatrolSchedules.txt
│   ├── [7] View All Requests
│   │   ├── Features: Display all maintenance requests in a table
│   │   │   ├── Sub-Features
│   │   │   │   ├── View Request ID
│   │   │   │   ├── View Dorm Building
│   │   │   │   ├── View Room
│   │   │   │   ├── View Issue Type
│   │   │   │   ├── View Priority
│   │   │   │   ├── View Status
│   │   │   │   ├── View Assigned Staff ID
│   │   │   │   ├── View Request Date
│   │   │   ├── Table Format: Color-coded headers
│   │   │   ├── File: MaintenanceRequests.txt
│   ├── [8] View Visitor Log List
│   │   ├── Features: Display all visitor logs in a table
│   │   │   ├── Sub-Features
│   │   │   │   ├── View Visitor ID
│   │   │   │   ├── View Full Name
│   │   │   │   ├── View Visit Purpose
│   │   │   │   ├── View Department
│   │   │   │   ├── View Room
│   │   │   │   ├── View Status
│   │   │   │   ├── View Visit Time
│   │   │   │   ├── View Exit Time
│   │   │   ├── Table Format: Color-coded headers
│   │   │   ├── File: VisitorsData.txt
│   ├── [9] Add New Student
│   │   ├── Features: Create new student record
│   │   │   ├── Sub-Features
│   │   │   │   ├── Set ID (auto-generated)
│   │   │   │   ├── Set Name, Contact Details
│   │   │   │   ├── Set Dorm Building, Room, Bed
│   │   │   │   ├── Set Status (Checked_out, Active, etc.)
│   │   │   │   ├── Set Meal Plan (NoMeal, Full, Half)
│   │   │   │   ├── Set Academic Details (university, faculty, dept, year, section)
│   │   │   │   ├── Set Check-In/Check-Out Dates
│   │   │   ├── Validation: Ensures unique ID, valid inputs
│   │   │   ├── File: StudentsDormData.txt
│   ├── [10] Add New Employee
│   │   ├── Features: Create new employee record
│   │   │   ├── Sub-Features
│   │   │   │   ├── Set ID (auto-generated)
│   │   │   │   ├── Set Name, Contact Details
│   │   │   │   ├── Set Residence, Department, Job Title
│   │   │   │   ├── Set Salary, Shift, Status
│   │   │   ├── Validation: Ensures unique ID, valid inputs
│   │   │   ├── File: DormEmployeeData.txt
│   ├── [11] Add New Visitor
│   │   ├── Features: Create new visitor record
│   │   │   ├── Sub-Features
│   │   │   │   ├── Set ID (auto-generated)
│   │   │   │   ├── Set Name
│   │   │   │   ├── Set Visit Purpose, Department, Room
│   │   │   │   ├── Set Status (Inside, Exited)
│   │   │   │   ├── Set Visit/Exit Times
│   │   │   ├── Validation: Ensures unique ID, valid inputs
│   │   │   ├── File: VisitorsData.txt
│   ├── [12] Add New Incident
│   │   ├── Features: Create new incident report
│   │   │   ├── Sub-Features
│   │   │   │   ├── Set ID (auto-generated)
│   │   │   │   ├── Set Type, Description
│   │   │   │   ├── Set Severity (Low, Medium, High)
│   │   │   │   ├── Set Status (Open, In Progress, Resolved, Closed)
│   │   │   │   ├── Set Security ID, Date
│   │   │   ├── Validation: Ensures unique ID, valid inputs
│   │   │   ├── File: IncidentReports.txt
│   ├── [13] Add New Maintenance Request
│   │   ├── Features: Create new maintenance request
│   │   │   ├── Sub-Features
│   │   │   │   ├── Set ID (auto-generated)
│   │   │   │   ├── Set Dorm Building, Room
│   │   │   │   ├── Set Issue Type, Priority, Status
│   │   │   │   ├── Set Assigned Staff ID, Request Date
│   │   │   ├── Validation: Ensures unique ID, valid inputs
│   │   │   ├── File: MaintenanceRequests.txt
│   ├── [14] Add New Payment
│   │   ├── Features: Record new payment
│   │   │   ├── Sub-Features
│   │   │   │   ├── Set ID (auto-generated)
│   │   │   │   ├── Set Dorm ID, Amount
│   │   │   │   ├── Set Purpose, Status, Payment Method
│   │   │   │   ├── Set Date
│   │   │   ├── Validation: Ensures unique ID, valid inputs
│   │   │   ├── File: DormPaymentsData.txt
│   ├── [15] Add New Room
│   │   ├── Features: Create new room record
│   │   │   ├── Sub-Features
│   │   │   │   ├── Set Dorm, Floor, Room Number
│   │   │   │   ├── Set Capacity, Occupants, Status
│   │   │   ├── Validation: Ensures valid inputs
│   │   │   ├── File: RoomsData.txt
│   ├── [16] Add New Complaint
│   │   ├── Features: Record new student complaint
│   │   │   ├── Sub-Features
│   │   │   │   ├── Set ID (auto-generated)
│   │   │   │   ├── Set Dorm ID, Room
│   │   │   │   ├── Set Issue, Priority, Status
│   │   │   │   ├── Set Date
│   │   │   ├── Validation: Ensures valid inputs
│   │   │   ├── File: StudentsDormComplaints.txt
│   ├── [17] View Student Complaints
│   │   ├── Features: Display all student complaints in a table
│   │   │   ├── Sub-Features
│   │   │   │   ├── View Complaint ID
│   │   │   │   ├── View Dorm ID
│   │   │   │   ├── View Room
│   │   │   │   ├── View Issue
│   │   │   │   ├── View Priority
│   │   │   │   ├── View Status
│   │   │   │   ├── View Date
│   │   │   ├── Table Format: Color-coded headers
│   │   │   ├── File: StudentsDormComplaints.txt
│   ├── [18] View Payments
│   │   ├── Features: Display all payment records in a table
│   │   │   ├── Sub-Features
│   │   │   │   ├── View Payment ID
│   │   │   │   ├── View Dorm ID
│   │   │   │   ├── View Amount
│   │   │   │   ├── View Purpose
│   │   │   │   ├── View Status
│   │   │   │   ├── View Payment Method
│   │   │   │   ├── View Date
│   │   │   ├── Table Format: Color-coded headers
│   │   │   ├── File: DormPaymentsData.txt
│   ├── [19] View Rooms
│   │   ├── Features: Display all room records in a table
│   │   │   ├── Sub-Features
│   │   │   │   ├── View Dorm
│   │   │   │   ├── View Floor
│   │   │   │   ├── View Room Number
│   │   │   │   ├── View Capacity
│   │   │   │   ├── View Occupants
│   │   │   │   ├── View Status
│   │   │   ├── Table Format: Color-coded headers
│   │   │   ├── File: RoomsData.txt
│   ├── [20] View Shift Schedules
│   │   ├── Features: Display all employee shift schedules in a table
│   │   │   ├── Sub-Features
│   │   │   │   ├── View Employee ID
│   │   │   │   ├── View Residence
│   │   │   │   ├── View Shift
│   │   │   │   ├── View Date
│   │   │   ├── Table Format: Color-coded headers
│   │   │   ├── File: ShiftsSchedulesData.txt
│   ├── [21] View Security Assignments
│   │   ├── Features: Display all security personnel assignments in a table
│   │   │   ├── Sub-Features
│   │   │   │   ├── View Security ID
│   │   │   │   ├── View Employee ID
│   │   │   │   ├── View Building
│   │   │   │   ├── View Status
│   │   │   │   ├── View Supervisor ID
│   │   │   │   ├── View Date
│   │   │   ├── Table Format: Color-coded headers
│   │   │   ├── File: SecuritiesData.txt
│   ├── [22] Login
│   │   ├── Features: Authenticate users with role-based access
│   │   │   ├── Sub-Features
│   │   │   │   ├── Enter Username
│   │   │   │   ├── Enter Password
│   │   │   │   ├── Assign Role (admin, securitychief, financemanager, studentofficer)
│   │   │   │   ├── Track Login Session with Timestamp
│   │   │   ├── Validation: Verifies credentials
│   │   │   ├── Files: LoginData.txt, RegisterLogins.txt
│   ├── [23] Logout
│   │   ├── Features: End user session
│   │   │   ├── Sub-Features
│   │   │   │   ├── Record Logout Time
│   │   │   │   ├── Clear Current User Session
│   │   │   ├── File: RegisterLogins.txt
│   ├── [24] Exit
│   │   ├── Features: Save changes and exit program
│   │   │   ├── Sub-Features
│   │   │   │   ├── Save all modified records to respective files
│   │   │   │   ├── Clear console
│   │   │   ├── Files: All data files (*.txt)
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
