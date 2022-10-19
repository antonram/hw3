#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
	// if empty, return
	if(head == NULL) {
		return;
	}
	// if less than, save to smaller and disconnect from rest
	if(head->val <= pivot) {
		smaller = head;
		head = head->next;
		smaller->next = NULL;
		llpivot(head, smaller->next, larger, pivot);
	}
	// if greater, save to larger and disconnect from rest
	else if(head->val > pivot) {
		larger = head;
		head = head->next;
		larger->next = NULL;
		llpivot(head, smaller, larger->next, pivot);
	}
}

