# C++ Linked List and Infix to Postfix Conversion Implementation

This repository contains two C++ programs: one that implements a doubly linked list and another that performs infix to postfix conversion using a stack. The programs allow you to perform various operations on the linked list and convert infix expressions to postfix notation.

## Linked List Implementation

The `main.cpp` file implements a doubly linked list with the following operations:

- Append a new element to the end of the list.
- Insert a new element at a specific position in the list.
- Remove an element by its value from the list.
- Remove an element by its index from the list.
- Print all the elements of the list.
- Print all the elements of the list in reverse order.
- Print the length of the list.
- Reverse the order of elements in the list.
- Erase all elements from the list.

To use the linked list implementation, compile the `main.cpp` file and run the executable. The program will prompt you to enter commands to perform different operations on the linked list.
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
```

## Infix to Postfix Conversion

The `infix_to_postfix.cpp` file contains a program that converts infix expressions to postfix notation using a stack. The `infixToPostfix` function in this program implements the conversion algorithm. To use the program, compile the `infix_to_postfix.cpp` file and run the executable. The program will prompt you to enter an infix expression, and it will output the corresponding postfix expression.

## Example

Here's an example of how you can use the infix to postfix conversion program:

```bash
$ g++ infix_to_postfix.cpp -o infix_to_postfix
$ ./infix_to_postfix
a+b*c-(d+e)*f
abc*+de+f*-
