#include <iostream>
#include <string>
using namespace std;

struct Student {
    int studentID;
    string studentName;
    Student* nextStudent;

    Student(int id, string name) { 
        studentID = id; 
        studentName = name; 
        nextStudent = nullptr; 
    }
};

struct Course {
    int courseID;
    string courseName;
    Course* nextCourse;
    Student* students;

    Course(int id, string name) {
        courseID = id; 
        courseName = name; 
        nextCourse = nullptr;
        students = nullptr;
    
    }  
};

Course* courseHead = nullptr;

void addCourse(int id, string name) {
    Course* newCourse = new Course(id, name);
    newCourse->nextCourse = courseHead;
    courseHead = newCourse;
    cout << "Course added: " << name << endl;
}
void deleteCourse(int id) {
    Course* temp = courseHead;
    Course* prev = nullptr;

    while (temp && temp->courseID != id) {
        prev = temp;
        temp = temp->nextCourse;
    }

    if (!temp) {
        cout << "Course not found\n";
        return;
    }
    if (prev) {
        prev->nextCourse = temp->nextCourse;
    }
    else {
        courseHead = temp->nextCourse;
    }

    delete temp;
    cout << "Course deleted\n";
}
Course* searchCourse(int id) {
    Course* temp = courseHead;
    while (temp) {
        if (temp->courseID == id) return temp;
        temp = temp->nextCourse;
    }
    return nullptr;
}
void printCourses() {
    Course* temp = courseHead;
    if (!temp) {
        cout << "No courses available.\n";
        return;
    }
    while (temp) {
        cout << "Course ID: " << temp->courseID << ", Name: " << temp->courseName << endl;
        temp = temp->nextCourse;
    }
}
void addStudentToCourse(int courseID, int studentID, string studentName) {
    Course* course = searchCourse(courseID);
    if (!course) {
        cout << "Course not found\n";
        return;
    }

    Student* newStudent = new Student(studentID, studentName);
    newStudent->nextStudent = course->students;
    course->students = newStudent;
    cout << "Student added to course\n";
}

void deleteStudentFromCourse(int courseID, int studentID) {
    Course* course = searchCourse(courseID);
    if (!course) {
        cout << "Course not found\n";
        return;
    }

    Student* temp = course->students, * prev = nullptr;
    while (temp && temp->studentID != studentID) {
        prev = temp;
        temp = temp->nextStudent;
    }

    if (!temp) {
        cout << "Student not found in course\n";
        return;
    }

    if (prev) {
        prev->nextStudent = temp->nextStudent;
    }
    else {
        course->students = temp->nextStudent;
    }

    delete temp;
    cout << "Student removed from course\n";
}
void deleteStudent(int studentID) {
    Course* course = courseHead;
    while (course) {
        deleteStudentFromCourse(course->courseID, studentID);
        course = course->nextCourse;
    }
    cout << "Student deleted from all couruse";
}

void printStudentsInCourse(int courseID) {
    Course* course = searchCourse(courseID);
    if (!course) {
        cout << "Course not found\n";
        return;
    }

    Student* temp = course->students;
    if (!temp) {
        cout << "No students enrolled in this course.\n";
        return;
    }

    cout << "Students in " << course->courseName << ":\n";
    int i = 1;
    while (temp) {
        
        cout <<i<< ")" << temp->studentName << " (ID: " << temp->studentID << ")\n";
        temp = temp->nextStudent;
        i++;
    }
}
void searchStudent(int studentID) {
    Course* course = courseHead;
    bool found = false;

    while (course) {
        Student* temp = course->students;
        while (temp) {
            if (temp->studentID == studentID) {
                cout << "Student found in course: " << course->courseName << endl;
                found = true;
            }
            temp = temp->nextStudent;
        }
        course = course->nextCourse;
    }

    if (!found) {
        cout << "Student not found in any course.\n";
    }
}
bool searchStudentInCourse(int courseID, int studentID) {
    Course* course = searchCourse(courseID);
    if (!course) {
        cout << "Course not found\n";
        return false;
    }

    Student* temp = course->students;
    while (temp) {
        if (temp->studentID == studentID) {
            cout << "Student found: " << temp->studentName << endl;
            return true;
        }
        temp = temp->nextStudent;
    }
    cout << "Student not found in this course\n";
    return false;
}

int main() {
    addCourse(313, "DSA");
    addCourse(354, "OOP");
    addCourse(342, "AI");

    addStudentToCourse(313, 1, "fatima");
    addStudentToCourse(313, 2, "rida");
    addStudentToCourse(313, 3, "ali");
    addStudentToCourse(354, 4, "hamna");
    addStudentToCourse(354, 5, "aisha");
    addStudentToCourse(354, 6, "omer");
    addStudentToCourse(342, 7, "ahmed");
    addStudentToCourse(342, 8, "Amna");
    addStudentToCourse(342, 9, "Hadi");

    cout << "All Courses"<<endl;
    printCourses();

    cout <<endl << "Students in DSA "<<endl;
    printStudentsInCourse(313);

    cout << endl << "Searching Student 1 in DSA"<< endl;
    searchStudentInCourse(313, 1);

    cout <<endl << "Deleting Student 1 from DSA"<<endl;
    deleteStudentFromCourse(313, 1);
    printStudentsInCourse(313);

    cout <<endl << "Searching Student 1 in All Courses"<< endl;
    searchStudent(1);

    cout <<endl << "Deleting Course AI"<< endl;
    deleteCourse(342);
    printCourses();

    return 0;
}