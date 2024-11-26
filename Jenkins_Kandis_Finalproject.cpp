/*
Name: Kandis Jenkins
Lab # Fianl Project
Date: 11/23/2024
Description: Illness Symptoms Checker in C++. This program checks symptoms for COVID-19, Cold, and Flu.
File name: Jenkins_Kandis_labFinalProject
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Class for a sick human
class SickHuman {
    public:
        int fever;
        int cough;
        int shortness;
        int runnyNose;
        int headache;
        int sneezing;
        int fatigue;
        SickHuman(); // Constructor to set symptoms
};

// Class for checking symptoms
class SymptomChecker {
    public:
        void checkSymptoms(SickHuman); // Function to check symptoms
        void printSymptoms(); // Function to print results
        void printGuide(); // Function to print the guide
        int numPatients; // Number of patients to check
    private:
        int covid = 0; // For COVID-19
        int cold = 0; // For Cold
        int flu = 0; // For Flu
        int other = 0; // Other illnesses
};

int main() {
    srand(time(NULL)); // Seed random number generator
    SymptomChecker checker; // Create SymptomChecker object
    checker.printGuide(); // Print guide
    cout << "Enter number of patients: ";
    cin >> checker.numPatients; // Get number of patients from user
    cout << "Thank you..." << endl;
    for (int i = 0; i < checker.numPatients; i++) { // Loop through patients
        SickHuman patient; // Create a SickHuman object
        checker.checkSymptoms(patient); // Check symptoms for each patient
    }
    checker.printSymptoms(); // Print the results
    return 0; // End of program
}

// Constructor to randomly initialize symptoms
SickHuman::SickHuman() {
    fever = rand() % 2; // Randomly set fever
    cough = rand() % 2; // Randomly set cough
    shortness = rand() % 2; // Randomly set shortness of breath
    runnyNose = rand() % 2; // Randomly set runny nose
    headache = rand() % 2; // Randomly set headache
    sneezing = rand() % 2; // Randomly set sneezing
    fatigue = rand() % 2; // Randomly set fatigue
}

// Function to print the guide
void SymptomChecker::printGuide() {
    cout << "Welcome to Symptom Checker" << endl << endl;
    cout << "Guide: \t* Common \t+ Sometimes/Rarely \t- NO" << endl;
    cout << "=========================================================" << endl;
    cout << "Symptoms\t|\tCOVID-19  |   Cold   |   Flu    |" << endl;
    cout << "=========================================================" << endl;
    cout << "Fever\t\t|\t* \t  |    +     |   *      |" << endl;
    cout << "Cough\t\t|\t* \t  |    +     |   *      |" << endl;
    cout << "Shortness of Breath|\t* \t  |    -     |   -      |" << endl;
    cout << "Runny Nose\t|\t+ \t  |    *     |   +      |" << endl;
    cout << "Headaches\t|\t+ \t  |    +     |   *      |" << endl;
    cout << "Sneezing\t|\t- \t  |    *     |   -      |" << endl;    
    cout << "Fatigue\t\t|\t+ \t  |    +     |   *      |" << endl;
    cout << "=========================================================" << endl << endl;
}

// Function to check symptoms for each patient
void SymptomChecker::checkSymptoms(SickHuman patient) {
    int nope = 0; // Unmatched symptoms

    if (patient.fever == 1 && patient.cough == 1 && patient.headache == 1 && patient.fatigue == 1) {
        flu++; // Flu counter
    } else {
        nope++; // If not flu
    }

    if (patient.fever == 1 && patient.cough == 1 && patient.shortness == 1) {
        covid++; // COVID-19 counter
    } else {
        nope++; // If not COVID-19 
    }

    if (patient.runnyNose == 1 && patient.sneezing == 1) {
        cold++; // Cold counter 
    } else {
        nope++; // If not cold 
    }

    if (nope == 3) { // If no matches found, count as other illness 
        other++; 
     }
}

// Function to print the results 
void SymptomChecker::printSymptoms() { 
     cout<<"========================================================="<<endl; 
     cout<<"Symptoms Checker..."<<endl; 
     cout<<covid<<" patients have symptoms of COVID-19"<<endl; 
     cout<<cold<<" patients have symptoms of Cold"<<endl; 
     cout<<flu<<" patients have symptoms of Flu"<<endl; 
     cout<<other<<" patients may have some other illness"<<endl;

     if ((covid + cold + flu + other) > numPatients) { 
         cout<<"(Some patients have more than one illness)"<<endl; 
     }

     cout<<"========================================================="<<endl<<endl;

     cout<<"Percentage of each illness:"<<endl;

     cout<<"COVID-19:\t["<<((covid*1.0)/(numPatients*1.0))*100<<"%]"; 
     for(int i=0;i<((covid*1.0)/(numPatients*1.0))*100;i++){ 
         cout<<"+";// Print + for each percentage point 
     } 

     cout<<endl<<"Cold:\t\t["<<((cold*1.0)/(numPatients*1.0))*100<<"%]"; 
     for(int i=0;i<((cold*1.0)/(numPatients*1.0))*100;i++){ 
         cout<<"+";// Print + for each percentage point 
     } 

     cout<<endl<<"Flu:\t\t["<<((flu*1.0)/(numPatients*1.0))*100<<"%]"; 
     for(int i=0;i<((flu*1.0)/(numPatients*1.0))*100;i++){ 
         cout<<"+";// Print + for each percentage point 
     } 

     cout<<endl<<"Other:\t\t["<<((other*1.0)/(numPatients*1.0))*100<<"%]"; 
     for(int i=0;i<((other*1.0)/(numPatients*1.0))*100;i++){ 
         cout<<"+";// Print + for each percentage point 
     } 

     cout<<endl;
}