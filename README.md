# C++ Linked List Implementation

This repository contains a C++ program that implements a doubly linked list. The program allows you to perform various operations on the linked list, including appending elements, inserting elements at specific positions, removing elements by value or index, printing the list items, printing the list in reverse order, printing the length of the list, reversing the order of elements in the list, and erasing all items from the list.

## Usage

To use the linked list implementation, compile the `main.cpp` file and run the executable. The program will prompt you to enter commands to perform different operations on the linked list. Here are the available commands:

- `a`: Append a new element to the end of the list.
- `i`: Insert a new element at a specific position in the list.
- `r`: Remove an element by its value from the list.
- `d`: Remove an element by its index from the list.
- `p`: Print all the elements of the list.
- `t`: Print all the elements of the list in reverse order.
- `l`: Print the length of the list.
- `v`: Reverse the order of elements in the list.
- `e`: Erase all elements from the list.

Enter `x` to exit the program.

## Example

Here's an example of how you can use the program:

```bash
$ g++ main.cpp -o linked_list
$ ./linked_list
a 5
a 10
i 7 1
p
5 7 10
t
10 7 5
l
3
e
l
Not exist
