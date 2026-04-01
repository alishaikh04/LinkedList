#include <iostream>
using namespace std;

struct SNode
{
    int data;
    SNode* snext;
};

struct CNode
{
    int data;
    CNode* cnext;
    SNode* slist;
};

CNode* clist = NULL;

void insertCourses(int courseNumber)
{
    CNode* temp = new CNode();
    temp->data = courseNumber;
    temp->cnext = NULL;
    temp->slist = NULL;

    if (clist == NULL)
        clist = temp;
    else
    {
        CNode* ccurrent = clist;
        while (ccurrent->cnext != NULL)
            ccurrent = ccurrent->cnext;
        ccurrent->cnext = temp;
    }
    cout << "Course " << courseNumber << " Inserted." << endl;
}

void enrollstudentincourse(int courseNumber, int studentNumber)
{
    if (clist == NULL)
    {
        cout << "Course List is Empty." << endl;
        return;
    }

    CNode* ccurrent = clist;
    bool found = false;

    while (ccurrent != NULL)
    {
        if (courseNumber == ccurrent->data)
        {
            found = true;
            SNode* temp = new SNode();
            temp->data = studentNumber;
            temp->snext = NULL;

            if (ccurrent->slist == NULL)
                ccurrent->slist = temp;
            else
            {
                SNode* scurrent = ccurrent->slist;
                while (scurrent->snext != NULL)
                    scurrent = scurrent->snext;
                scurrent->snext = temp;
            }
            cout << "Student " << studentNumber << " Enrolled in Course " << courseNumber << endl;
        }
        ccurrent = ccurrent->cnext;
    }

    if (!found)
        cout << "Course Not Found." << endl;
}

void searchfortheCourse(int courseNumber)
{
    if (clist == NULL)
    {
        cout << "Course List is Empty." << endl;
        return;
    }

    CNode* ccurrent = clist;
    bool found = false;
    int position = 0;

    while (ccurrent != NULL)
    {
        position++;
        if (ccurrent->data == courseNumber)
        {
            cout << "Course " << courseNumber << " found at position " << position << endl;
            found = true;
            return;
        }
        ccurrent = ccurrent->cnext;
    }

    if (!found)
        cout << "Course Not Found." << endl;
}

void searchforstudentinstudentlist(int studentNumber)
{
    if (clist == NULL)
    {
        cout << "Course List is Empty." << endl;
        return;
    }

    CNode* ccurrent = clist;
    bool found = false;

    while (ccurrent != NULL)
    {
        SNode* scurrent = ccurrent->slist;
        while (scurrent != NULL)
        {
            if (scurrent->data == studentNumber)
            {
                cout << "Student " << studentNumber << " found in Course " << ccurrent->data << endl;
                found = true;
            }
            scurrent = scurrent->snext;
        }
        ccurrent = ccurrent->cnext;
    }

    if (!found)
        cout << "Student Not Found." << endl;
}

void searchStudentinCourse(int courseNumber, int studentNumber)
{
    if (clist == NULL)
    {
        cout << "Course List is Empty." << endl;
        return;
    }

    CNode* ccurrent = clist;

    while (ccurrent != NULL)
    {
        if (ccurrent->data == courseNumber)
        {
            SNode* scurrent = ccurrent->slist;
            while (scurrent != NULL)
            {
                if (scurrent->data == studentNumber)
                {
                    cout << "Student " << studentNumber << " found in Course " << courseNumber << endl;
                    return;
                }
                scurrent = scurrent->snext;
            }
        }
        ccurrent = ccurrent->cnext;
    }

    cout << "Course or Student Not Found." << endl;
}

void deleteCourse(int courseNumber)
{
    if (clist == NULL)
    {
        cout << "Course List is Empty." << endl;
        return;
    }

    CNode* ccurrent = clist;

    if (ccurrent->data == courseNumber)
    {
        clist = ccurrent->cnext;
        delete ccurrent;
        cout << "Course " << courseNumber << " Deleted." << endl;
        return;
    }

    CNode* previous = ccurrent;
    ccurrent = ccurrent->cnext;

    while (ccurrent != NULL)
    {
        if (ccurrent->data == courseNumber)
        {
            previous->cnext = ccurrent->cnext;
            delete ccurrent;
            cout << "Course " << courseNumber << " Deleted." << endl;
            return;
        }
        previous = ccurrent;
        ccurrent = ccurrent->cnext;
    }

    cout << "Course Not Found." << endl;
}

void deleteStudent(int studentNumber)
{
    if (clist == NULL)
    {
        cout << "Course List is Empty." << endl;
        return;
    }

    CNode* ccurrent = clist;
    bool found = false;

    while (ccurrent != NULL)
    {
        SNode* scurrent = ccurrent->slist;
        SNode* previous = NULL;

        while (scurrent != NULL)
        {
            if (scurrent->data == studentNumber)
            {
                if (previous == NULL)
                    ccurrent->slist = scurrent->snext;
                else
                    previous->snext = scurrent->snext;

                delete scurrent;
                found = true;
                cout << "Student " << studentNumber << " deleted from Course " << ccurrent->data << endl;
                break;
            }
            previous = scurrent;
            scurrent = scurrent->snext;
        }
        ccurrent = ccurrent->cnext;
    }

    if (!found)
        cout << "Student Not Found." << endl;
}

void deleteStudentInTheCourse(int courseNumber, int studentNumber)
{
    if (clist == NULL)
    {
        cout << "Course List is Empty." << endl;
        return;
    }

    CNode* ccurrent = clist;

    while (ccurrent != NULL)
    {
        if (ccurrent->data == courseNumber)
        {
            SNode* previous = NULL;
            SNode* scurrent = ccurrent->slist;

            while (scurrent != NULL)
            {
                if (scurrent->data == studentNumber)
                {
                    if (previous == NULL)
                        ccurrent->slist = scurrent->snext;
                    else
                        previous->snext = scurrent->snext;

                    delete scurrent;
                    cout << "Student " << studentNumber << " Deleted From Course " << courseNumber << endl;
                    return;
                }
                previous = scurrent;
                scurrent = scurrent->snext;
            }
        }
        ccurrent = ccurrent->cnext;
    }

    cout << "Course or Student Not Found." << endl;
}

void displayCourses()
{
    if (clist == NULL)
    {
        cout << "Course List is Empty." << endl;
        return;
    }

    CNode* ccurrent = clist;
    while (ccurrent != NULL)
    {
        cout << ccurrent->data << " -> ";
        ccurrent = ccurrent->cnext;
    }
    cout << "NULL" << endl;
}

void displaystudents()
{
    if (clist == NULL)
    {
        cout << "Course List is Empty." << endl;
        return;
    }

    CNode* ccurrent = clist;
    while (ccurrent != NULL)
    {
        cout << "Course " << ccurrent->data << " -> Students: ";
        SNode* scurrent = ccurrent->slist;
        while (scurrent != NULL)
        {
            cout << scurrent->data << " -> ";
            scurrent = scurrent->snext;
        }
        cout << "NULL" << endl;
        ccurrent = ccurrent->cnext;
    }
}

void displayCoursesandstudents()
{
    if (clist == NULL)
    {
        cout << "Course List is Empty." << endl;
        return;
    }

    CNode* ccurrent = clist;
    while (ccurrent != NULL)
    {
        cout << "Course: " << ccurrent->data << endl;
        SNode* scurrent = ccurrent->slist;
        while (scurrent != NULL)
        {
            cout << scurrent->data << " -> ";
            scurrent = scurrent->snext;
        }
        cout << "NULL" << endl;
        ccurrent = ccurrent->cnext;
    }
}

int main()
{
    int choice, studentNumber, courseNumber;

    while (true)
    {
        cout << endl;
        cout << "1.  Insert Course."               << endl;
        cout << "2.  Enroll Student in Course."    << endl;
        cout << "3.  Search Course."               << endl;
        cout << "4.  Search Student."              << endl;
        cout << "5.  Search Student in Course."    << endl;
        cout << "6.  Delete Course."               << endl;
        cout << "7.  Delete Student."              << endl;
        cout << "8.  Delete Student in Course."    << endl;
        cout << "9.  Display Courses and Students."<< endl;
        cout << "10. Display Courses Only."        << endl;
        cout << "11. Display Students Only."       << endl;
        cout << "12. Exit."                        << endl << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter Course Number: ";
            cin >> courseNumber;
            insertCourses(courseNumber);
        }
        else if (choice == 2)
        {
            cout << "Enter Course Number: ";
            cin >> courseNumber;
            cout << "Enter Student Number: ";
            cin >> studentNumber;
            enrollstudentincourse(courseNumber, studentNumber);
        }
        else if (choice == 3)
        {
            cout << "Enter Course Number: ";
            cin >> courseNumber;
            searchfortheCourse(courseNumber);
        }
        else if (choice == 4)
        {
            cout << "Enter Student Number: ";
            cin >> studentNumber;
            searchforstudentinstudentlist(studentNumber);
        }
        else if (choice == 5)
        {
            cout << "Enter Course Number: ";
            cin >> courseNumber;
            cout << "Enter Student Number: ";
            cin >> studentNumber;
            searchStudentinCourse(courseNumber, studentNumber);
        }
        else if (choice == 6)
        {
            cout << "Enter Course Number: ";
            cin >> courseNumber;
            deleteCourse(courseNumber);
        }
        else if (choice == 7)
        {
            cout << "Enter Student Number: ";
            cin >> studentNumber;
            deleteStudent(studentNumber);
        }
        else if (choice == 8)
        {
            cout << "Enter Course Number: ";
            cin >> courseNumber;
            cout << "Enter Student Number: ";
            cin >> studentNumber;
            deleteStudentInTheCourse(courseNumber, studentNumber);
        }
        else if (choice == 9)
        {
            displayCoursesandstudents();
        }
        else if (choice == 10)
        {
            displayCourses();
        }
        else if (choice == 11)
        {
            displaystudents();
        }
        else if (choice == 12)
        {
            cout << "Exiting Program." << endl;
            break;
        }
        else
        {
            cout << "Invalid Choice." << endl;
        }
    }

    return 0;
}
