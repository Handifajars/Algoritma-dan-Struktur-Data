/*	
	Date created: Saturday, 26 May 2018, 10:51 PM
	Author		: mramirid
*/

// WARNING: Written in C++ instead of C, Sorry.

#include <iostream>

#ifndef nullptr
#define nullptr NULL
#endif // nullptr

struct node {
	int data;
	node *next;
};

class list {
	node *head, *tail;
public:
	list() {
		head = nullptr;
		tail = nullptr;
	}

	void create_node(int value) {
		node *temp = new node;
		temp->data = value;
		temp->next = nullptr;

		if (head == nullptr) {
			head = temp;
			tail = temp;
			temp = nullptr;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	void display() {
		node *temp = new node;
		temp = head;

		while (temp != nullptr) {
			std::cout << temp->data << '\t';
			temp = temp->next;
		}
	}

	void insert_start(int value) {
		node *temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;
	}

	void insert_position(int pos, int value) {
		node *pre = new node;
		node *cur = new node;
		node *temp = new node;
		cur = head;

		for (auto i = 1; i < pos; ++i) {
			pre = cur;
			cur = cur->next;
		}

		temp->data = value;
		pre->next = temp;
		temp->next = cur;
	}

	void delete_first() {
		node *temp = new node;
		temp = head;
		head = head->next;
		delete temp;
	}

	void delete_last() {
		node *current = new node;
		node *previous = new node;
		current = head;

		while (current->next != nullptr) {
			previous = current;
			current = current->next;
		}

		tail = previous;
		previous->next = nullptr;
		delete current;
	}

	void delete_position(int pos) {
		node *current = new node;
		node *previous = new node;
		current = head;

		for (auto i = 1; i < pos; ++i) {
			previous = current;
			current = current->next;
		}

		previous->next = current->next;
		delete current;
	}
};

int main() {
	int num, pos, val;
	bool condition = true;
	list opr;
	
	while (condition) {
		system("CLS");
		std::cout << "Single Linked List" << std::endl;
		std::cout << "1. Create node" << std::endl;
		std::cout << "2. Display" << std::endl;
		std::cout << "3. Insert start" << std::endl;
		std::cout << "4. Insert position" << std::endl;
		std::cout << "5. Delete first" << std::endl;
		std::cout << "6. Delete last" << std::endl;
		std::cout << "7. Delete position" << std::endl;
		std::cout << "8. EXIT" << std::endl;
		std::cout << "Select operation: ";
		std::cin >> num;

		switch (num) {
			case 1: {
				std::cout << "New value: ";
				std::cin >> val;
				opr.create_node(val);
				break;
			}
			case 2: {
				opr.display();
				std::cout << std::endl;
				break;
			}
			case 3: {
				std::cout << "Insert value: ";
				std::cin >> val;
				opr.insert_start(val);
				break;
			}
			case 4: {
				std::cout << "Insert position: ";
				std::cin >> pos;
				std::cout << "Insert value: ";
				std::cin >> val;
				opr.insert_position(pos, val);
				break;
			}
			case 5: {
				opr.delete_first();
				break;
			}
			case 6: {
				opr.delete_last();
				break;
			}
			case 7: {
				std::cout << "Delete position: ";
				std::cin >> pos;
				opr.delete_position(pos);
				break;
			}
			case 8:	condition = false; break;
			default: std::cout << "Wrong input!" << std::endl;
		}
		
		system("PAUSE");
	}

	return 0;
}