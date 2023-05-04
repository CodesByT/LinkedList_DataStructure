#include "LinkedList.h"

int main() {

	LinkedList<int> list1;
	
	//  . . . Insertion . . .

	list1.InsertNodeAtHead(10);
	list1.InsertNodeAtTail(20);
	list1.InsertNodeAtTail(30);
	list1.InsertNodeAtTail(40);
	list1.InsertNodeAtTail(50);
	list1.InsertNodeAtTail(60);
	list1.displayList();

	list1.InsertANode(69, 10);
	list1.displayList();
	list1.InsertANode(69, 40);
	list1.displayList();
	list1.InsertANode(69, 60);
	list1.displayList();

	list1.InsertNodeAtTail(69);
	list1.displayList();
	list1.InsertNodeAtTail(555);
	list1.displayList();
	list1.InsertNodeAtTail(222);
	list1.displayList();
	list1.InsertNodeAtHead(888);
	list1.displayList();
	list1.InsertNodeAtHead(444);
	list1.displayList();
	list1.InsertANode(999, 50);
	list1.displayList();

	//  . . . Searching  . . .

	list1.FindANode(555);
	list1.FindANode(888);
	list1.FindANode(999);
	list1.FindANode(12345);

	//  . . . Updation . . .

	list1.UpdateANode(666, 555);
	list1.displayList();
	list1.UpdateANode(333, 888);
	list1.displayList();
	list1.UpdateANode(777, 999);
	list1.displayList();

	//  . . . Deletion . . .

	list1.DeletionOfHeadnode();
	list1.DeletionOfHeadnode();
	list1.displayList();

	list1.DeletionOfTailnode();
	list1.DeletionOfTailnode();
	list1.displayList();

	list1.DeleteANode(69);
	list1.displayList();
	list1.DeleteANode(69);
	list1.displayList();
	list1.DeleteANode(771);
	list1.displayList();
	list1.DeleteANode(69);
	list1.displayList();

	//  . . . Reversing List . . .

	list1.ReverseTheList();
	list1.displayList();
	list1.ReverseTheList();
	list1.displayList();

	return 0;
}

