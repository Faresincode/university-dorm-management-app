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

File,Purpose
clsVisitor.h,Manages visitor data and operations
clsUpdateVisitorInfoScreen.h,Updates visitor records
clsUpdateDormStudentScreen.h,Updates student records
clsUpdateEmployeeInfoScreen.h,Updates employee records
clsUpdateIncidentScreen.h,Updates incident reports
clsViewAllPatrolSchedulesScreen.h,Displays patrol schedules
clsViewPatrolLogsScreen.h,Displays patrol logs
clsViewAllRequestsScreen.h,Displays maintenance requests
clsVisitorLogListScreen.h,Displays visitor logs
clsUtil.h,"Utility functions (random IDs, file I/O, formatting)"
Global.h,Global constants and color definitions
GlobalLogin.h,Manages current user login

File,Content
StudentsDormData.txt,Student information
DormEmployeeData.txt,Employee information
VisitorsData.txt,Visitor logs
PatrolSchedules.txt,Patrol schedules
IncidentReports.txt,Incident reports
MaintenanceRequests.txt,Maintenance requests
LoginData.txt,User credentials
RegisterLogins.txt,Login session tracking
StudentsDormComplaints.txt,Student complaints
RoomsData.txt,Room details
ShiftsSchedulesData.txt,Employee shift schedules
SecuritiesData.txt,Security personnel data
DormPaymentsData.txt,Payment records

Component,Purpose
clsBase,Provides screen header functionality
clsInputValidate,Ensures valid user inputs
clsString,Handles string operations for file parsing
clsUtil,"Supports random ID generation, file I/O, console formatting"
Data Persistence,Uses text files with #//# separators

