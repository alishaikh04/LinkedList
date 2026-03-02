
#include <iostream>
#include <cstdlib>   // For malloc and free

using namespace std;

struct SNode {
    int SNo;
    SNode* snext;
};

struct CNode {
    int CNo;
    CNode* cnext;
    SNode* slist;
};

CNode* clist = NULL;

/* ================= INSERT COURSE ================= */

void Insertcourse(int CNo) {

    CNode* temp = (CNode*)malloc(sizeof(CNode));

    temp->CNo = CNo;
    temp->cnext = NULL;
    temp->slist = NULL;

    if (clist == NULL) {
        clist = temp;
    }
    else {
        CNode* current = clist;

        while (current->cnext != NULL) {
            current = current->cnext;
        }

        current->cnext = temp;
    }
}

/* ================= ENROLL STUDENT ================= */

void enrollingStudent(int CNo, int SNo) {

    if (clist == NULL) {
        cout << "Course list is empty." << endl;
        return;
    }

    CNode* ccurrent = clist;

    while (ccurrent != NULL) {

        if (ccurrent->CNo == CNo) {

            SNode* temp = (SNode*)malloc(sizeof(SNode));

            temp->SNo = SNo;
            temp->snext = NULL;

            if (ccurrent->slist == NULL) {
                ccurrent->slist = temp;
            }
            else {

                SNode* scurrent = ccurrent->slist;

                while (scurrent->snext != NULL) {
                    scurrent = scurrent->snext;
                }

                scurrent->snext = temp;
            }

            cout << "Student enrolled successfully." << endl;
            return;
        }

        ccurrent = ccurrent->cnext;
    }

    cout << "Course not found." << endl;
}

/* ================= SEARCH COURSE ================= */

void searchingCourse(int CNo) {

    if (clist == NULL) {
        cout << "Course list is empty." << endl;
        return;
    }

    CNode* ccurrent = clist;

    while (ccurrent != NULL) {

        if (ccurrent->CNo == CNo) {
            cout << "Course found." << endl;
            return;
        }

        ccurrent = ccurrent->cnext;
    }

    cout << "Course not found." << endl;
}

/* ================= SEARCH STUDENT IN COURSE ================= */

void searchStudentInCourse(int CNo) {

    if (clist == NULL) {
        cout << "Course list is empty." << endl;
        return;
    }

    CNode* ccurrent = clist;

    while (ccurrent != NULL) {

        if (ccurrent->CNo == CNo) {

            SNode* scurrent = ccurrent->slist;

            if (scurrent == NULL) {
                cout << "No students in this course." << endl;
                return;
            }

            cout << "Students in course " << CNo << ": " << endl;

            while (scurrent != NULL) {
                cout << scurrent->SNo << " ";
                scurrent = scurrent->snext;
            }

            cout << endl;
            return;
        }

        ccurrent = ccurrent->cnext;
    }

    cout << "Course not found." << endl;
}

/* ================= STUDENT ENROLLED IN WHICH COURSE ================= */

void studentEnrolledInwhichCourse(int SNo) {

    if (clist == NULL) {
        cout << "No course list." << endl;
        return;
    }

    bool found = false;

    CNode* ccurrent = clist;

    while (ccurrent != NULL) {

        SNode* scurrent = ccurrent->slist;

        while (scurrent != NULL) {

            if (scurrent->SNo == SNo) {
                cout << "Student enrolled in course: " << ccurrent->CNo << endl;
                found = true;
            }

            scurrent = scurrent->snext;
        }

        ccurrent = ccurrent->cnext;
    }

    if (!found) {
        cout << "Student not enrolled in any course." << endl;
    }
}

/* ================= DELETE COURSE ================= */

void deleteCourse(int CNo) {

    if (clist == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    CNode* current = clist;
    CNode* previous = NULL;

    while (current != NULL) {

        if (current->CNo == CNo) {

            if (previous == NULL) {
                clist = current->cnext;
            }
            else {
                previous->cnext = current->cnext;
            }

            // Delete students
            SNode* scurrent = current->slist;

            while (scurrent != NULL) {

                SNode* temp = scurrent;
                scurrent = scurrent->snext;
                free(temp);
            }

            free(current);

            cout << "Course deleted successfully." << endl;
            return;
        }

        previous = current;
        current = current->cnext;
    }

    cout << "Course not found." << endl;
}

/* ================= DELETE STUDENT FROM ALL COURSES ================= */

void deleteStudent(int SNo) {

    if (clist == NULL) {
        cout << "No courses available." << endl;
        return;
    }

    bool found = false;

    CNode* ccurrent = clist;

    while (ccurrent != NULL) {

        SNode* scurrent = ccurrent->slist;
        SNode* previous = NULL;

        while (scurrent != NULL) {

            if (scurrent->SNo == SNo) {

                if (previous == NULL) {
                    ccurrent->slist = scurrent->snext;
                }
                else {
                    previous->snext = scurrent->snext;
                }

                SNode* temp = scurrent;
                scurrent = scurrent->snext;

                free(temp);

                cout << "Student removed from course " << ccurrent->CNo << endl;

                found = true;
                continue;
            }

            previous = scurrent;
            scurrent = scurrent->snext;
        }

        ccurrent = ccurrent->cnext;
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

/* ================= DELETE STUDENT FROM SPECIFIC COURSE ================= */

void deleteStudentFromCourse(int CNo, int SNo) {

    if (clist == NULL) {
        cout << "Course list empty." << endl;
        return;
    }

    CNode* ccurrent = clist;

    while (ccurrent != NULL) {

        if (ccurrent->CNo == CNo) {

            SNode* scurrent = ccurrent->slist;
            SNode* previous = NULL;

            while (scurrent != NULL) {

                if (scurrent->SNo == SNo) {

                    if (previous == NULL) {
                        ccurrent->slist = scurrent->snext;
                    }
                    else {
                        previous->snext = scurrent->snext;
                    }

                    free(scurrent);

                    cout << "Student removed from course." << endl;
                    return;
                }

                previous = scurrent;
                scurrent = scurrent->snext;
            }

            cout << "Student not found in this course." << endl;
            return;
        }

        ccurrent = ccurrent->cnext;
    }

    cout << "Course not found." << endl;
}

/* ================= DISPLAY COURSES ================= */

void displayCourse() {

    if (clist == NULL) {
        cout << "Course list empty." << endl;
        return;
    }

    CNode* current = clist;

    cout << "Courses:" << endl;

    while (current != NULL) {
        cout << current->CNo << " ";
        current = current->cnext;
    }

    cout << endl;
}

/* ================= DISPLAY ALL ================= */

void displayAll() {

    CNode* ccurrent = clist;

    if (ccurrent == NULL) {
        cout << "No data." << endl;
        return;
    }

    while (ccurrent != NULL) {

        cout << "Course " << ccurrent->CNo << " -> ";

        SNode* scurrent = ccurrent->slist;

        while (scurrent != NULL) {
            cout << scurrent->SNo << " ";
            scurrent = scurrent->snext;
        }

        cout << endl;

        ccurrent = ccurrent->cnext;
    }
}

/* ================= MAIN ================= */

int main() {

    int cnumber, scode, num;

    while (true) {

        cout << "\n1. Insert Course." << endl;
        cout << "2. Enroll Student." << endl;
        cout << "3. Search Course." << endl;
        cout << "4. Search Students in Course." << endl;
        cout << "5. Student Courses." << endl;
        cout << "6. Delete Course." << endl;
        cout << "7. Delete Student (All Courses)." << endl;
        cout << "8. Delete Student From Course." << endl;
        cout << "9. Display Courses." << endl;
        cout << "10. Display Course Students." << endl;
        cout << "11. Display All." << endl;
        cout << "12. Exit." << endl;

        cin >> num;

        if (num == 1) {
            cin >> cnumber;
            Insertcourse(cnumber);
        }

        else if (num == 2) {
            cin >> cnumber >> scode;
            enrollingStudent(cnumber, scode);
        }

        else if (num == 3) {
            cin >> cnumber;
            searchingCourse(cnumber);
        }

        else if (num == 4) {
            cin >> cnumber;
            searchStudentInCourse(cnumber);
        }

        else if (num == 5) {
            cin >> scode;
            studentEnrolledInwhichCourse(scode);
        }

        else if (num == 6) {
            cin >> cnumber;
            deleteCourse(cnumber);
        }

        else if (num == 7) {
            cin >> scode;
            deleteStudent(scode);
        }

        else if (num == 8) {
            cin >> cnumber >> scode;
            deleteStudentFromCourse(cnumber, scode);
        }

        else if (num == 9) {
            displayCourse();
        }

        else if (num == 11) {
            displayAll();
        }

        else if (num == 12) {
            break;
        }
    }

    return 0;
}