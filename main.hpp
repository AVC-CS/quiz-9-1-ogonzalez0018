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
int getLength(Student *head)
{
    int length = 0;
    Student *ptr = head;
    while (ptr != NULL)
    {
        length++;
        ptr = ptr->next;
    }
    return length;
}
Student *sortStudent(Student *head, int asc)
{
    Student *ptr1, *ptr2;
    int temp;
    double tempd;

    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
    {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if (asc)
            {
                if (ptr1->sum > ptr2->sum)
                {
                    temp = ptr1->id;
                    ptr1->id = ptr2->id;
                    ptr2->id = temp;

                    ptr1->name.swap(ptr2->name);

                    temp = ptr1->score[0];
                    ptr1->score[0] = ptr2->score[0];
                    ptr2->score[0] = temp;

                    temp = ptr1->score[1];
                    ptr1->score[1] = ptr2->score[1];
                    ptr2->score[1] = temp;

                    tempd = ptr1->sum;
                    ptr1->sum = ptr2->sum;
                    ptr2->sum = tempd;

                    tempd = ptr1->avg;
                    ptr1->avg = ptr2->avg;
                    ptr2->avg = tempd;
                }
            }
            else
            {
                if (ptr1->sum < ptr2->sum)
                {
                    temp = ptr1->id;
                    ptr1->id = ptr2->id;
                    ptr2->id = temp;

                    ptr1->name.swap(ptr2->name);

                    temp = ptr1->score[0];
                    ptr1->score[0] = ptr2->score[0];
                    ptr2->score[0] = temp;

                    temp = ptr1->score[1];
                    ptr1->score[1] = ptr2->score[1];
                    ptr2->score[1] = temp;

                    tempd = ptr1->sum;
                    ptr1->sum = ptr2->sum;
                    ptr2->sum = tempd;

                    tempd = ptr1->avg;
                    ptr1->avg = ptr2->avg;
                    ptr2->avg = tempd;
                }
            }
        }
    }

    return head;
}
