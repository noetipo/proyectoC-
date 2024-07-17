//
// Created by Noe on 29/06/24.
//

#ifndef DATABASE_INTSLLIST_H
#define DATABASE_INTSLLIST_H

class IntSLLNode {
        public:
            IntSLLNode()  {
            next = 0;
        }

        IntSLLNode(int el, IntSLLNode *ptr = 0) {
            info = el; next = ptr;
        }
        int info;
        IntSLLNode *next;
};

class IntSLList {
        public:
        IntSLList() {
            head = tail = 0;
        }

        ~IntSLList();

        bool isEmpty() const {
            return head == 0;
        }

        void addToHead(int);

        void addToTail(int);

        int deleteFromHead(); // delete the head and return its info;
        int deleteFromTail(); // delete the tail and return its info;
        void deleteNode(int);

        bool isInList(int) const;
        void printList() const;
        private:
        IntSLLNode *head, *tail;
};

#endif //DATABASE_INTSLLIST_H
