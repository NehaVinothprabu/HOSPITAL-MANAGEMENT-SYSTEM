#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 50
#define MAX_APPOINTMENTS 500

struct Patient {
    char name[50];
    int age;
    char gender;
    char address[100];
    char disease[100];
};

struct Doctor {
    char name[50];
    char specialization[50];
};

struct Appointment {
    struct Patient patient;
    struct Doctor doctor;
    char date[20];
    char time[20];
};

struct Patient patients[MAX_PATIENTS];
struct Doctor doctors[MAX_DOCTORS];
struct Appointment appointments[MAX_APPOINTMENTS];

int numPatients = 0;
int numDoctors = 0;
int numAppointments = 0;

void addPatient() {
    if (numPatients < MAX_PATIENTS) {
        struct Patient newPatient;
        printf("Enter patient name: ");
        scanf("%s", newPatient.name);
        printf("Enter patient age: ");
        scanf("%d", &newPatient.age);
        printf("Enter patient gender (M/F): ");
        scanf(" %c", &newPatient.gender);
        printf("Enter patient address: ");
        scanf("%s", newPatient.address);
        printf("Enter patient disease: ");
        scanf("%s", newPatient.disease);

        patients[numPatients++] = newPatient;
        printf("Patient added successfully!\n");
    } else {
        printf("Patient database is full!\n");
    }
}

void addDoctor() {
    if (numDoctors < MAX_DOCTORS) {
        struct Doctor newDoctor;
        printf("Enter doctor name: ");
        scanf("%s", newDoctor.name);
        printf("Enter doctor specialization: ");
        scanf("%s", newDoctor.specialization);

        doctors[numDoctors++] = newDoctor;
        printf("Doctor added successfully!\n");
    } else {
        printf("Doctor database is full!\n");
    }
}

void scheduleAppointment() {
    if (numAppointments < MAX_APPOINTMENTS) {
        struct Appointment newAppointment;
        printf("Enter patient name: ");
        scanf("%s", newAppointment.patient.name);
        printf("Enter doctor name: ");
        scanf("%s", newAppointment.doctor.name);
        printf("Enter appointment date (DD/MM/YYYY): ");
        scanf("%s", newAppointment.date);
        printf("Enter appointment time (HH:MM): ");
        scanf("%s", newAppointment.time);

        appointments[numAppointments++] = newAppointment;
        printf("Appointment scheduled successfully!\n");
    } else {
        printf("Appointment database is full!\n");
    }
}

void displayAppointments() {
    printf("Appointments:\n");
    printf("Patient Name\tDoctor Name\tDate\tTime\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s\t%s\t%s\t%s\n", appointments[i].patient.name,
               appointments[i].doctor.name, appointments[i].date,
               appointments[i].time);
    }
}

int main() {
    int choice;
    printf("\nHospital Management System\n");
    do {
        printf("1. Add Patient\n");
        printf("2. Add Doctor\n");
        printf("3. Schedule Appointment\n");
        printf("4. Display Appointments\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                addDoctor();
                break;
            case 3:
                scheduleAppointment();
                break;
            case 4:
                displayAppointments();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
