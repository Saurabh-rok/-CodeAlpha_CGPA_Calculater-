#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct Course {
    string name;
    double gradePoint{};
    double credits{};
};

struct Semester {
    string name;
    vector<Course> courses;
    double totalCredits{};
    double totalGradePoints{};

    double gpa() const {
        return totalCredits > 0 ? totalGradePoints / totalCredits : 0.0;
    }
};

double readPositiveNumber(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0) return value;
        cout << "Please enter a number greater than zero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int readIntInRange(const string& prompt, int minimum, int maximum) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minimum && value <= maximum) return value;
        cout << "Please enter a whole number between " << minimum
             << " and " << maximum << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    cout << "=====================================\n";
    cout << "          CGPA CALCULATOR\n";
    cout << "=====================================\n";
    cout << "Grade points should follow your college's grading scale.\n\n";

    const int semesterCount = readIntInRange("Enter number of semesters (1-12): ", 1, 12);
    vector<Semester> semesters;
    double allGradePoints = 0.0;
    double allCredits = 0.0;

    for (int s = 0; s < semesterCount; ++s) {
        Semester semester;
        cout << "\n--- Semester " << s + 1 << " ---\n";
        cout << "Enter semester name (e.g. Semester 1): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, semester.name);
        if (semester.name.empty()) semester.name = "Semester " + to_string(s + 1);

        int courseCount = readIntInRange("Number of courses (1-20): ", 1, 20);
        for (int c = 0; c < courseCount; ++c) {
            Course course;
            cout << "\nCourse " << c + 1 << " name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, course.name);
            if (course.name.empty()) course.name = "Course " + to_string(c + 1);

            course.gradePoint = readPositiveNumber("Grade point (e.g. 8.5): ");
            while (course.gradePoint > 10.0) {
                cout << "This calculator uses a 10-point scale. Enter 0-10.\n";
                course.gradePoint = readPositiveNumber("Grade point: ");
            }
            course.credits = readPositiveNumber("Credit hours: ");

            semester.totalGradePoints += course.gradePoint * course.credits;
            semester.totalCredits += course.credits;
            semester.courses.push_back(course);
        }
        allGradePoints += semester.totalGradePoints;
        allCredits += semester.totalCredits;
        semesters.push_back(semester);
    }

    cout << "\n\n================ RESULT ================\n";
    cout << fixed << setprecision(2);
    for (const auto& semester : semesters) {
        cout << "\n" << semester.name << "\n";
        cout << left << setw(28) << "Course"
             << right << setw(12) << "Grade"
             << setw(12) << "Credits" << "\n";
        cout << string(52, '-') << "\n";
        for (const auto& course : semester.courses) {
            cout << left << setw(28) << course.name
                 << right << setw(12) << course.gradePoint
                 << setw(12) << course.credits << "\n";
        }
        cout << "Semester GPA: " << semester.gpa() << "\n";
        cout << "Total credits: " << semester.totalCredits << "\n";
    }

    cout << "\nOverall CGPA: " << (allCredits > 0 ? allGradePoints / allCredits : 0.0) << "\n";
    cout << "Total credits completed: " << allCredits << "\n";
    cout << "========================================\n";
    cout << "Note: Enter all completed semesters for an accurate cumulative CGPA.\n";
    return 0;
}
