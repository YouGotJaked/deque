/* 
 * File:  deque.cpp
 * Author: Jake Day
 * Class: COEN 12
 * Instructor: Atkinson
 * Section: T 5:15-8pm
 * Created on May 31, 2016, 5:46 PM
 * Description: This file implements a deque ADT using a circular, doubly-linked list with a sentinel or dummy node in C++
 */

#include <cassert>
#include "deque.h"

typedef struct node NODE;

struct node {
    NODE *next;
    NODE *prev;
    int data;
};

/*
 * Big-O Notation: O(1)
 * Constructor for the deque
 */
Deque::Deque() {
    count = 0;
    dummy = new NODE;
    dummy->next = dummy;
    dummy->prev = dummy;
}

/*
 * Big-O Notation: O(n)
 * Destructor for the deque
 */
Deque::~Deque() {
    NODE *np, *next;

    np = dummy;

    for (int i = 0; i < count; i++) {
        np = dummy->next;
        dummy->next = np->next;
        delete(np);
    }
}

/*
 * Big-O Notation: O(1)
 * Returns the number of items in the deque
 */
int Deque::size() {
    return count;
}

/*
 * Big-O Notation: O(1)
 * Add x as the first item in the deque
 */
void Deque::addFirst(int x) {
    NODE *np = new NODE;

    np->data = x;

    np->prev = dummy;
    np->next = dummy->next;

    dummy->next->prev = np;
    dummy->next = np;

    count++;
}

/*
 * Big-O Notation: O(1)
 * Add x as the last item in the deque
 */
void Deque::addLast(int x) {
    NODE *np = new NODE;

    np->data = x;

    np->next = dummy;
    np->prev = dummy->prev;

    dummy->prev->next = np;
    dummy->prev = np;

    count++;
}

/*
 * Big-O Notation: O(1)
 * Remove and return the first item in the deque, which must not be empty
 */
int Deque::removeFirst() {
    int data;
    NODE *np = dummy->next;
    NODE *tempNext = np->next;

    data = np->data;

    dummy->next = tempNext;

    tempNext->prev = dummy;
    tempNext->next = np->next->next;

    delete(np);

    count--;

    return data;
}

/*
 * Big-O Notation: O(1)
 * Remove and return the last item in the deque, which must not be empty
 */
int Deque::removeLast() {
    int data;

    NODE *np = dummy->prev;
    NODE *tempLast = np->prev;

    data = np->data;

    dummy->prev = np->prev;

    tempLast->next = dummy;
    dummy->prev = tempLast;

    delete(np);

    count--;

    return data;
}

/*
 * Big-O Notation: O(1)
 * Return, but do not remove, the first item in the deque, which must not be empty
 */
int Deque::getFirst() {
    return dummy->next->data;
}

/*
 * Big-O Notation: O(1)
 * Return, but do not remove, the last item in the deque, which must not be empty
 */
int Deque::getLast() {
    return dummy->prev->data;
}
