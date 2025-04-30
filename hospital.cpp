#include "hospital.h"
#include<iostream>
#include <cstring>
#include<fstream>
Doctor::Doctor() {
    Name[0] = Specialization[0] = Hospital[0] = '\0';
    ContactNo = 0;
}

void Doctor::inputDoctorDetails() {
    cout << "Enter doctor's name: ";
    cin.ignore();
    cin.getline(Name, 40);
    cout << "Enter specialization: ";
    cin.getline(Specialization, 40);
    cout << "Enter hospital name: ";
    cin.getline(Hospital, 40);
    cout << "Enter contact number: ";
    cin >> ContactNo;
}

void Doctor::displayDoctorDetails() {
    cout << "Doctor Name: " << Name << "\nSpecialization: " << Specialization
        << "\nHospital: " << Hospital << "\nContact No: " << ContactNo << endl;
}

Patient::Patient() {
    Name[0] = Disease[0] = '\0';
    ContactNo = 0;
    Age = 0;
}

void Patient::inputPatientDetails() {
    cout << "Enter patient's name: ";
    cin.ignore();
    cin.getline(Name, 40);
    cout << "Enter patient's age: ";
    cin >> Age;
    cin.ignore();
    cout << "Enter disease: ";
    cin.getline(Disease, 40);
    cout << "Enter contact number: ";
    cin >> ContactNo;
}

void Patient::displayPatientDetails() {
    cout << "Patient Name: " << Name << "\nAge: " << Age
        << "\nDisease: " << Disease << "\nContact No: " << ContactNo << endl;
}

Admin::Admin() {
    Username[0] = Password[0] = '\0';
}

void Admin::inputAdminDetails() {
    cout << "Enter admin username: ";
    cin.ignore();
    cin.getline(Username, 40);
    cout << "Enter admin password: ";
    cin.getline(Password, 40);
}

void Admin::displayAdminDetails() {
    cout << "Admin Username: " << Username << "\nAdmin Password: " << Password << endl;
}

// Authentication functions
bool verifyAdmin(Admin& admin) {
    string user, pass;
    cout << "Enter admin username: ";
    cin >> user;
    cout << "Enter admin password: ";
    cin >> pass;
    return user == admin.Username && pass == admin.Password;
}

bool verifyPatient(Patient& patient) {
    string name;
    cout << "Enter patient's name: ";
    cin >> name;
    return name == patient.Name;
}

bool verifyDoctor(Doctor& doctor) {
    string name;
    cout << "Enter doctor's name: ";
    cin >> name;
    return name == doctor.Name;
}

// Menu
void MainMenu(Admin& admin, Patient& patient, Doctor& doctor) {
    int choice;
    while (true) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Admin Login\n2. Patient Login\n3. Doctor Login\n";
        cout << "4. Register Admin\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (verifyAdmin(admin)) {
                cout << "Admin login successful!\n";
                admin.displayAdminDetails();
            }
            else {
                cout << "Invalid admin credentials!\n";
            }
            break;
        case 2:
            if (verifyPatient(patient)) {
                cout << "Patient login successful!\n";
                patient.displayPatientDetails();
            }
            else {
                cout << "Patient not found!\n";
            }
            break;
        case 3:
            if (verifyDoctor(doctor)) {
                cout << "Doctor login successful!\n";
                doctor.displayDoctorDetails();
            }
            else {
                cout << "Doctor not found!\n";
            }
            break;
        case 4:
            admin.inputAdminDetails();
            break;
        case 5:
            cout << "Exiting program...\n";
            return;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }
}

int main() {
    Admin admin;
    Patient patient;
    Doctor doctor;

    admin.inputAdminDetails(); // Initial registration
    patient.inputPatientDetails();
    doctor.inputDoctorDetails();

    MainMenu(admin, patient, doctor);
    return 0;
}
