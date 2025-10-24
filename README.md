# Dormitory Management System

The **Dormitory Management System** is a robust C++ console-based application designed to streamline dormitory operations for university or residential administrators. Below is a comprehensive list of all features, including detailed descriptions of each management screen and their options.

## Features

### Student Management
- **Add New Students**: Create new student records with unique IDs, personal details, academic information, and dormitory assignments.
- **Update Student Records**: Modify student details such as dorm building, room number, bed number, status, and meal plan.
- **View Student Records**: Display student information, including ID, name, dorm building, room number, bed number, status, meal plan, university, faculty, department, year, section, check-in/check-out dates, and contact details.
- **Track Student Complaints**: Record and view complaints (e.g., food or electricity issues) with status tracking.
- **Manage Academic Details**: Store and update university, faculty, department, year, and section information.
- **Check-In/Check-Out Management**: Track student move-in and move-out dates.
- **Data Persistence**: Save student data to `StudentsDormData.txt` with `#//#` separators.

**Update Dorm Student Screen (`clsUpdateDormStudentScreen.h`)**
- **Purpose**: Update student dormitory records by ID.
- **Menu Options**:
  - [1] **Dorm Building**: Update the dormitory building (e.g., OceanView, CoralBay).
  - [2] **Room Number**: Change the room number.
  - [3] **Bed Number**: Update the bed number within the room.
  - [4] **Status**: Modify student status (Checked_out, Active, Suspended, Transferred, Pending, NoStatus).
  - [5] **Meal Plan**: Update meal plan (NoMeal, Full, Half).
  - [6] **Update All**: Update all fields at once.
- **Features**:
  - Validates student ID existence.
  - Supports "skip" input to retain existing data.
  - Saves changes to `StudentsDormData.txt`.

### Employee Management
- **Add New Employees**: Register employees with details like ID, name, department, job title, salary, shift, and status.
- **Update Employee Records**: Modify employee details such as residence name, department, job title, salary, shift, and status.
- **View Employee Records**: Display employee information, including residence name, department, job title, salary, shift, status, and contact details.
- **Manage Shift Schedules**: Assign and track employee shifts via `ShiftsSchedulesData.txt`.
- **Security Assignments**: Link employees to security roles and track via `SecuritiesData.txt`.
- **Data Persistence**: Save employee data to `DormEmployeeData.txt`.

**Update Employee Info Screen (`clsUpdateEmployeeInfoScreen.h`)**
- **Purpose**: Update employee records by ID.
- **Menu Options**:
  - [1] **Residence Name**: Update the dormitory residence (e.g., OceanView, Seaside Hall).
  - [2] **Residence Department**: Change the department (e.g., Maintenance, Security).
  - [3] **Job Title**: Modify job title (e.g., Maintenance Worker, Security Supervisor).
  - [4] **Salary**: Update salary amount.
  - [5] **Shift**: Change shift details.
  - [6] **Status**: Update employee status (e.g., Active, Inactive).
  - [7] **Update All**: Update all fields at once.
- **Features**:
  - Validates employee ID existence.
  - Saves changes to `DormEmployeeData.txt`.

### Visitor Tracking
- **Add New Visitors**: Register visitors with ID, name, visit purpose, department, room, security ID, status, and visit/exit times.
- **Update Visitor Records**: Modify visitor details, including status (Inside/Exited).
- **View Visitor Logs**: Display all visitor records in a table format.
- **Filter Visitors**: Filter by name, department, or today’s visits.
- **Track Visit/Exit Times**: Record and update entry and exit timestamps.
- **Data Persistence**: Save visitor data to `VisitorsData.txt`.

**Update Visitor Information Screen (`clsUpdateVisitorInfoScreen.h`)**
- **Purpose**: Update visitor records by ID.
- **Menu Options**:
  - [1] **First Name**: Update visitor’s first name.
  - [2] **Last Name**: Update visitor’s last name.
  - [3] **Visit Purpose**: Change purpose (e.g., Meeting, Delivery, Interview).
  - [4] **Visited Department**: Update department (e.g., Administration, HR).
  - [5] **Visited Room**: Change room number.
  - [6] **Visitor Status**: Update status (Inside, Exited).
  - [7] **Update All**: Update all fields at once.
- **Features**:
  - Validates visitor ID existence.
  - Allows selective or full updates with input validation.
  - Saves changes to `VisitorsData.txt`.

**Visitor Log List Screen (`clsVisitorLogListScreen.h`)**
- **Purpose**: Display all visitor logs in a table.
- **Table Columns**:
  - Visitor ID
  - Full Name
  - Visit Purpose
  - Department
  - Room
  - Status
  - Visit Time
  - Exit Time
- **Features**:
  - Loads data from `VisitorsData.txt`.
  - Displays formatted table with color-coded headers (Green, White).

### Patrol Scheduling
- **Add Patrol Schedules**: Create schedules with patrol ID, security ID, location, start/end times, and status.
- **View Patrol Schedules**: Display all schedules in a table.
- **Filter Completed Patrols**: Show only completed patrols separately.
- **Update Patrol Status**: Modify status (e.g., Scheduled, In Progress, Completed, Cancelled).
- **Data Persistence**: Save schedules to `PatrolSchedules.txt`.

**View All Patrol Schedules Screen (`clsViewAllPatrolSchedulesScreen.h`)**
- **Purpose**: Display all patrol schedules in a table.
- **Table Columns**:
  - Patrol ID
  - Security ID
  - Start Time
  - End Time
  - Patrol Status
  - Patrol Location
- **Features**:
  - Loads data from `PatrolSchedules.txt`.
  - Displays formatted table with color-coded headers.

**View Patrol Logs Screen (`clsViewPatrolLogsScreen.h`)**
- **Purpose**: Display all patrol logs and completed patrols separately.
- **Table Columns**: Same as View All Patrol Schedules.
- **Features**:
  - Filters and displays completed patrols.
  - Reuses table formatting from `clsViewAllPatrolSchedulesScreen`.

### Incident Reporting
- **Add Incident Reports**: Record incidents with ID, type, description, severity, status, security ID, and date.
- **Update Incident Reports**: Modify incident details, including type, description, severity, and status.
- **View Incident Reports**: Display incidents in a table format.
- **Severity and Status Tracking**: Support for severity levels (Low, Medium, High) and statuses (Open, In Progress, Resolved, Closed).
- **Data Persistence**: Save incidents to `IncidentReports.txt`.

**Update Incident Screen (`clsUpdateIncidentScreen.h`)**
- **Purpose**: Update incident reports by ID.
- **Menu Options**:
  - [1] **Incident Type**: Update type (e.g., Unauthorized Access, Fire Alarm).
  - [2] **Description**: Modify incident description.
  - [3] **Severity**: Change severity (Low, Medium, High).
  - [4] **Status**: Update status (Open, In Progress, Resolved, Closed).
  - [5] **Security ID**: Change assigned security ID.
  - [6] **Update All**: Update all fields at once.
  - [7] **Exit**: Return to main menu.
- **Features**:
  - Validates incident ID.
  - Saves changes to `IncidentReports.txt`.

### Maintenance Requests
- **Add Maintenance Requests**: Record requests with ID, dorm building, room, issue type, priority, status, assigned staff, and request date.
- **Update Maintenance Requests**: Modify request details.
- **View Maintenance Requests**: Display all requests in a table.
- **Priority and Status Tracking**: Support for priority levels and statuses.
- **Data Persistence**: Save requests to `MaintenanceRequests.txt`.

**View All Requests Screen (`clsViewAllRequestsScreen.h`)**
- **Purpose**: Display all maintenance requests in a table.
- **Table Columns**:
  - Request ID
  - Dorm Building
  - Room
  - Issue Type
  - Priority
  - Status
  - Assigned Staff ID
  - Request Date
- **Features**:
  - Loads data from `MaintenanceRequests.txt`.
  - Displays formatted table with color-coded headers.

### Login System
- **Role-Based Access**: Supports multiple roles (e.g., admin, securitychief, financemanager, studentofficer).
- **Login Tracking**: Records login sessions with timestamps in `RegisterLogins.txt`.
- **Credential Management**: Stores usernames and passwords in `LoginData.txt`.
- **Data Persistence**: Saves login data securely.

### Payment Management
- **Track Payments**: Record payment details (ID, dorm ID, date, amount, purpose, status, payment method).
- **View Payments**: Access payment records from `DormPaymentsData.txt`.
- **Data Persistence**: Save payment data with `#//#` separators.

### Room Management
- **Manage Room Details**: Track room assignments (dorm building, floor, room number, capacity, occupants, status).
- **Data Persistence**: Save room data to `RoomsData.txt`.

### Utility Features
- **Random ID Generation**: Generate unique IDs for students, employees, visitors, patrols, incidents, and requests.
- **Input Validation**: Robust validation for strings, numbers, and enums using `clsInputValidate`.
- **File Operations**: Load, save, and update data in text files with `#//#` separators.
- **Console Formatting**: Color-coded outputs (Green, White, Blue, Yellow, Red) for readability.
- **Screen Reset**: Clear console and set default colors using `clsUtil::ResetScreen`.
- **Data Filtering**: Filter records (e.g., visitors by department, patrols by status).

## Screen Structure
The application uses a menu-driven interface with the following screens, each inheriting from `clsBase` for consistent headers and navigation:

1. **Update Visitor Information Screen (`clsUpdateVisitorInfoScreen.h`)**
   - As described in Visitor Tracking.

2. **Update Dorm Student Screen (`clsUpdateDormStudentScreen.h`)**
   - As described in Student Management.

3. **Update Employee Info Screen (`clsUpdateEmployeeInfoScreen.h`)**
   - As described in Employee Management.

4. **Update Incident Screen (`clsUpdateIncidentScreen.h`)**
   - As described in Incident Reporting.

5. **View All Patrol Schedules Screen (`clsViewAllPatrolSchedulesScreen.h`)**
   - As described in Patrol Scheduling.

6. **View Patrol Logs Screen (`clsViewPatrolLogsScreen.h`)**
   - As described in Patrol Scheduling.

7. **View All Requests Screen (`clsViewAllRequestsScreen.h`)**
   - As described in Maintenance Requests.

8. **Visitor Log List Screen (`clsVisitorLogListScreen.h`)**
   - As described in Visitor Tracking.
