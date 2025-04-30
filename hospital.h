#include <iostream>
#include <cstring>
using namespace std;

class Doctor {
public:
    char Name[40];
    char Specialization[40];
    char Hospital[40];
    long long ContactNo;

    Doctor();
    void inputDoctorDetails();
    void displayDoctorDetails();
};

class Patient {
public:
    char Name[40];
    int Age;
    char Disease[40];
    long long ContactNo;

    Patient();
    void inputPatientDetails();
    void displayPatientDetails();
};

class Admin {
public:
    char Username[40];
    char Password[40];

    Admin();
    void inputAdminDetails();
    void displayAdminDetails();
};

// Utility functions
bool verifyAdmin(Admin& admin);
bool verifyPatient(Patient& patient);
bool verifyDoctor(Doctor& doctor);
void MainMenu(Admin& admin, Patient& patient, Doctor& doctor);
