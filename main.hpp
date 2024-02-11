#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node
{
    double value;
    struct Node *next;
};

struct Node *makeNumbers(int N);
void printNumbers(struct Node *head);
int getLength(struct Node *head);
struct Node *sortNumbers(struct Node *head);
struct Node *swapNode(struct Node *prev, struct Node *ptr);

struct Node *makeNumbers(int N)
{
    /*******************************
     * Code your program here
     *******************************/
}
void printNumbers(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->value << "\t";
        ptr = ptr->next;
    }
    cout << endl;
    /*******************************
     * Code your program here
     *******************************/
}
int getLength(struct Node *head)
{
    /*******************************
     * Code your program here
     *******************************/
}
struct Node *sortNumbers(struct Node *head)
{
    /*******************************
     * Code your program here
     *******************************/
}

struct Node *swapNode(struct Node *prev, struct Node *ptr)
{
    /*******************************
     * Code your program here
     *******************************/
}