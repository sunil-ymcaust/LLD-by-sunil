//delete middle element in O(1)
// here we can use DLL and keep track of middle element and update its position while pushing and poping
#include <bits/stdc++.h>
using namespace std;


class DLLNode {
public:
	DLLNode* prev;
	int data;
	DLLNode* next;
};



class myStack {
public:
	DLLNode* head;
	DLLNode* mid;
	int count;
};

myStack* createMyStack()
{
	myStack* ms = new myStack();
	ms->count = 0;
	return ms;
};

void push(myStack* ms, int new_data)
{
	DLLNode* new_DLLNode = new DLLNode();
	new_DLLNode->data = new_data;

	/* Since we are adding at the beginning,
	prev is always NULL */
	new_DLLNode->prev = NULL;

	/* link the old list off the new DLLNode */
	new_DLLNode->next = ms->head;

	/* Increment count of items in stack */
	ms->count += 1;

	/* Change mid pointer in two cases
	1) Linked List is empty
	2) Number of nodes in linked list is odd */
	if (ms->count == 1) {
		ms->mid = new_DLLNode;
	}
	else {
		ms->head->prev = new_DLLNode;

		if (!(ms->count
			& 1)) // Update mid if ms->count is even
			ms->mid = ms->mid->prev;
	}

	/* move head to point to the new DLLNode */
	ms->head = new_DLLNode;
}

/* Function to pop an element from stack */
int pop(myStack* ms)
{
	/* Stack underflow */
	if (ms->count == 0) {
		cout << "Stack is empty\n";
		return -1;
	}

	DLLNode* head = ms->head;
	int item = head->data;
	ms->head = head->next;

	// If linked list doesn't
	// become empty, update prev
	// of new head as NULL
	if (ms->head != NULL)
		ms->head->prev = NULL;

	ms->count -= 1;

	// update the mid pointer when
	// we have odd number of
	// elements in the stack, i,e
	// move down the mid pointer.
	if ((ms->count) & 1)
		ms->mid = ms->mid->next;

	free(head);

	return item;
}

// Function for finding middle of the stack
int findMiddle(myStack* ms)
{
	if (ms->count == 0) {
		cout << "Stack is empty now\n";
		return -1;
	}

	return ms->mid->data;

}
// Function for deleting middle of the stack
int deletemiddle(myStack* ms) // IMPROVED BY Sohaib Ayub
	{
		int temp=ms->mid->data;
		ms->mid->prev->next=ms->mid->next;
		ms->mid->next->prev=ms->mid->prev->next;
		
		delete ms->mid;
		ms->mid = ms->mid->next; //So that mid does not contain garbage value
		return temp;
	}





// Driver code
int main()
{
	/* Let us create a stack using push() operation*/
	myStack* ms = createMyStack();
	push(ms, 11);
	push(ms, 22);
	push(ms, 33);
	push(ms, 44);
	push(ms, 55);
	push(ms, 66);
	push(ms, 77);

	cout << "Item popped is " << pop(ms) << endl;
	cout << "Item popped is " << pop(ms) << endl;
	cout << "Item popped is " << pop(ms) << endl;
	cout << "Middle Element is " << findMiddle(ms) << endl;
	cout << "Deleted Middle Element is "<<deletemiddle(ms)<<endl;
	cout << "Middle Element is " << findMiddle(ms) << endl;
	return 0;
}

// This code is contributed by rathbhupendra
