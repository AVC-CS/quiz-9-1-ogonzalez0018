#include "main.hpp"

int main()
{
	Student *head;
	int N = 10;

	head = makeStudent(N);
	printStudent(head);
	cout << "The length of the list " << getLength(head) << endl;
	head = sortStudent(head, 1);
	printStudent(head);
	head = sortStudent(head, 0);
	printStudent(head);
}
