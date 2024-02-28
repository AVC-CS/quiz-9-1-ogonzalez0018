#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
using namespace std;

const int NUMCOURSE = 2;

struct Student
{
    int id;
    string name;
    int score[NUMCOURSE];
    double sum;
    double avg;
    struct Student *next;
};


Student *makeStudent(int N)
{
    Student *head = new Student;
    Student *ptr = head;

    for (int i = 1; i <= N; i++)
    {
        ptr->id = i;
        ptr->name = "Student" + to_string(i);
        ptr->score[0] = 10;
        ptr->score[1] = 20;
        ptr->sum = 200;

        ptr->avg = ptr->sum / NUMCOURSE;

        if (i < N)
        {
            ptr->next = new Student;
            ptr = ptr->next;
        }
        else
        {
            ptr->next = NULL;
        }
    }

    return head;
}

void printStudent(Student *head)
{
    Student *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->id << "\t";
        cout << ptr->name << "\t";
        cout << ptr->score[0] << "\t";
        cout << ptr->score[1] << "\t";
        cout << ptr->sum << "\t";
        cout << ptr->avg << "\n";
        ptr = ptr->next;
    }
    cout << endl;
}
