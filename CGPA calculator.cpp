#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Function to calculate GPA for the semester
double calculateGPA(const vector<double>& grades, const vector<int>& credits) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (size_t i = 0; i < grades.size(); ++i) {
        totalGradePoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }

    return totalGradePoints / totalCredits;
}

// Function to calculate CGPA
double calculateCGPA(const vector<double>& semesterGPAs) {
    double totalGPA = 0;

    for (double gpa : semesterGPAs) {
        totalGPA += gpa;
    }

    return totalGPA / semesterGPAs.size();
}

// Function to convert letter grades to grade points
double getGradePoint(const string& grade) {
    map<string, double> gradeMap = {
        {"A", 4.0}, {"A-", 3.7}, {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7},
        {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7}, {"D+", 1.3}, {"D", 1.0},
        {"F", 0.0}
    };
    return gradeMap[grade];
}

int main() {
    int numberOfSemesters;
    cout << "Enter the number of semesters: ";
    cin >> numberOfSemesters;

    vector<double> semesterGPAs;

    for (int sem = 1; sem <= numberOfSemesters; ++sem) {
        int numberOfCourses;
        vector<double> grades;
        vector<int> credits;

        cout << "\nSemester " << sem << ":\n";
        cout << "Enter the number of courses taken: ";
        cin >> numberOfCourses;

        grades.resize(numberOfCourses);
        credits.resize(numberOfCourses);

        for (int i = 0; i < numberOfCourses; ++i) {
            string grade;
            cout << "Enter the letter grade for course " << i + 1 << " (A, B, C, etc.): ";
            cin >> grade;
            grades[i] = getGradePoint(grade);
            cout << "Enter the credits for course " << i + 1 << ": ";
            cin >> credits[i];
        }

        double semesterGPA = calculateGPA(grades, credits);
        semesterGPAs.push_back(semesterGPA);

        cout << "\nIndividual Grades for Semester " << sem << ":\n";
        for (int i = 0; i < numberOfCourses; ++i) {
            cout << "Course " << i + 1 << ": Grade = " << grades[i] << ", Credits = " << credits[i] << endl;
        }

        int totalCredits = 0;
        double totalGradePoints = 0;
        for (int i = 0; i < numberOfCourses; ++i) {
            totalCredits += credits[i];
            totalGradePoints += grades[i] * credits[i];
        }

        cout << "\nTotal Credits for Semester " << sem << ": " << totalCredits << endl;
        cout << "Total Grade Points for Semester " << sem << ": " << totalGradePoints << endl;
        cout << "Semester GPA for Semester " << sem << ": " << semesterGPA << endl;
    }

    double cgpa = calculateCGPA(semesterGPAs);

    cout << "\nCGPA after " << numberOfSemesters << " semesters: " << cgpa << endl;

    return 0;
}
