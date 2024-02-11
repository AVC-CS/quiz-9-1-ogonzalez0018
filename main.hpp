#include <iostream>
#include <fstream>
#include <sstream>
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
#define struct Student Student;
// typedef struct Student Student;

Student *makeStudent(int N);
void printStudent(Student *head);
int getLength(Student *head);
Student *sortStudent(Student *head, int asc);
Student *swapStudent(Student *prev, Student *ptr);
int compareStudent(Student *ptr, int asc);

Student *makeStudent(int N)
{
    ifstream ifs;
    string line, buf;
    stringstream ss;
    Student *head, *last;
    int first = 1;
    ifs.open("students.txt", ios::in);
    if (!ifs)
    {
        cerr << "File Open Error\n";
        exit(0);
    }
    while (getline(ifs, line))
    {
        int fcnt = 0;
        ss.clear();
        ss << line;
        Student *tmp = (Student *)malloc(sizeof(Student));
        while (ss >> buf)
        {
            switch (fcnt)
            {
            case 0:
                tmp->id = stoi(buf);
                break;
            case 1:
                tmp->name = buf;
                break;
            case 2:
                tmp->score[0] = stoi(buf);
                break;
            case 3:
                tmp->score[1] = stoi(buf);
                break;
            default:
                cerr << "Field count Error\n";
                exit(0);
            }
            fcnt++;
        }
        tmp->sum = tmp->score[0] + tmp->score[1];
        tmp->avg = tmp->sum / NUMCOURSE;
        tmp->next = NULL;
        if (first)
        {
            head = last = tmp;
            first = 0;
        }
        last->next = tmp;
        last = tmp;
    }
    return head;
    /*******************************
     * Code your program here
     *******************************/
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
    /*******************************
     * Code your program here
     *******************************/
}
int getLength(Student *head)
{
    int cnt = 0;
    Student *ptr = head;
    while (ptr != NULL)
    {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
    /*******************************
     * Code your program here
     *******************************/
}
Student *sortStudent(Student *head, int asc)
{
    Student *prev, *ptr;
    int first, length;

    length = getLength(head);
    for (int i = 0; i < length - 1; i++)
    {
        ptr = prev = head;
        first = 1;
        while (ptr->next != NULL)
        {
            // if (ptr->sum > ptr->next->sum)
            if (compareStudent(ptr, asc))
                ptr = swapStudent(prev, ptr);
            if (first)
                head = ptr;
            first = 0;
            prev = ptr;
            ptr = ptr->next;
        }
    }
    /*******************************
     * Code your program here
     *******************************/
    return head;
}

Student *swapStudent(Student *prev, Student *ptr)
{
    Student *next;
    next = ptr->next;
    prev->next = ptr->next;
    ptr->next = next->next;
    next->next = ptr;
    return next;
    /*******************************
     * Code your program here
     *******************************/
}
int compareStudent(Student *ptr, int asc)
{
    if (asc)
    {
        if (ptr->sum > ptr->next->sum)
            return 1;
    }
    else
    {
        if (ptr->sum < ptr->next->sum)
            return 1;
    }
    return 0;
}