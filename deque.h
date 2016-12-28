/* 
 * File:  deque.h
 * Author: Jake Day
 * Class: COEN 12
 * Instructor: Atkinson
 * Section: T 5:15-8pm
 * Created on May 31, 2016, 5:36 PM
 * Description:
 */

#ifndef DEQUE_H
#define	DEQUE_H

class Deque {
    int count;
    class node *dummy;

public:
    Deque();
    ~Deque();
    int size();
    void addFirst(int x);
    void addLast(int x);
    int removeFirst();
    int removeLast();
    int getFirst();
    int getLast();
};

#endif	/* DEQUE_H */

