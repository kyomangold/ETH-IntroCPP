//
//  main.cpp
//  Dynamic Queue
//
//  Created by Kyo Mangold on 28.05.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//
#include <cassert>
#include <iostream>

/////////////////////////////////////////////////////////////////////////////
// DECLARATIONS
/////////////////////////////////////////////////////////////////////////////

class Queue {
public:
    // PRE:  -
    // POST: Valid and empty queue.
    Queue() : first(0), last(0) { };
    
    // PRE:  Valid queue.
    // POST: Valid queue with new node having value i added at end of queue.
    void enqueue(int value);
    
    // PRE:  Valid and non-empty queue.
    // POST: Removes first node from queue frees the unused memory.
    //       Returns content of first node.
    int dequeue();
    
    // PRE:  Valid queue.
    // POST: Returns true if queue is empty, false otherwise.
    bool is_empty() const;
    
    // PRE:  Valid queue.
    // POST: Outputs queue content in seqeuence from first to last.
    void print(std::ostream& os) const;
    
    // PRE:  -
    // POST: New queue containing copy of queue other.
    Queue(const Queue& other);
    
    // PRE:  Valid queue.
    // POST: Queue is emptied (memory is freed) and initialized with elements
    //       from queue other.
    void operator=(const Queue& other);
    
    // PRE:  Valid queue.
    // POST: Queue is emptied and memory is freed.
    ~Queue();
    
private:
    struct Node {
        Node(const int _value, Node* _next) : value(_value), next(_next) { }
        int value;
        Node* next;
    };
    
    // Class invariant: (!first == !last)
    Node* first; // pointer to first element of queue or 0 is queue is empty.
    Node* last;  // pointer to last element of queue or 0 if queue is empty.
    
    // PRE: Valid queues this* and other.
    // POST: Queue contains contents of queue "other" in the same sequence.
    void copy(const Queue& other);
    
    // PRE: Valid queue.
    // POST: Valid and empty queue.
    void clear();
    
    // PRE: -
    // POST: Ensures class invariant.
    void is_valid() const;
};

// PRE:  Valid queue.
// POST: Outputs queue content in seqeuence to ostream
//       starting with element pointed at by first.
std::ostream& operator<<(std::ostream& os, const Queue& queue);


/////////////////////////////////////////////////////////////////////////////
// TEST MAIN FUNCTION (NO NEED TO MODIFY)
/////////////////////////////////////////////////////////////////////////////

// The following main function implements the testing harness.
// Note: We use *(ref). as the operator -> is not introduced in the lecture.
int main() {
    const int MAX_QUEUE_CNT = 10; // defines the maximal number of available queues
    Queue* queues[MAX_QUEUE_CNT];
    
    // initialize array by allocating memory for MAX_QUEUE_CNT Queue objects
    for (int i = 0; i < MAX_QUEUE_CNT; ++i)
        queues[i] = new Queue();
    
    // parse and process the test data until the end marker occurs.
    // The format of the test data is:
    // <function> <queue_id> <parameter>
    // where <parameter> is optional and specific to the function.
    while(std::cin.good()) {
        
        // get <function>, exit if end marker occurs
        std::string function;
        std::cin >> function;
        if (function == "end")
            break;
        
        // parse and validate <queue_id>
        unsigned int queue;
        std::cin >> queue;
        if (queue >= MAX_QUEUE_CNT) {
            std::cout << "queue must be number between 0 and "
            << MAX_QUEUE_CNT - 1 << " (entered: " << queue << ")\n";
            break;
        }
        
        if (function == "dequeue") {
            int value;
            value = (*queues[queue]).dequeue();
            std::cout << value << "\n";
            
        } else if (function == "enqueue") {
            int value; // parameter "value"
            std::cin >> value;
            (*queues[queue]).enqueue(value);
            
        } else if (function == "is_empty") {
            std::cout << (*queues[queue]).is_empty() << "\n";
            
        } else if (function == "print") {
            std::cout << (*queues[queue]) << "\n";
            
        } else if (function == "assign") {
            int queue_from; // parameter "queue_id"
            std::cin >> queue_from;
            *queues[queue] = *queues[queue_from];
            
        } else if (function == "copy") {
            int queue_from; // parameter "queue_id"
            std::cin >> queue_from;
            delete queues[queue];
            queues[queue] = new Queue(*queues[queue_from]);
            
        } else {
            std::cout << "unknown function: " << function << "\n";
            break;
        }
    }
    
    // free dynamically allocated memory
    for (int i = 0; i < MAX_QUEUE_CNT; ++i)
        delete queues[i];
}

/////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION
/////////////////////////////////////////////////////////////////////////////

void Queue::copy(const Queue& other)
{
    Node* node = other.first;
    while(node != 0) {
        enqueue(node->value);
        node = node->next;
    }
}

void Queue::clear()
{
    Node* node = first;
    while(node != 0) {
        Node* to_delete = node;
        node = node->next;
        delete to_delete;
    }
    first = 0;
    last  = 0;
}

void Queue::is_valid() const
{
    assert(!first == !last);
}
void Queue::enqueue(int value)
{
    is_valid();
    
    Node* node = new Node(value, 0);
    if (first == 0) {
        first = node;
        last = node;
    } else {
        last->next = node;
        last = node;
    }
}

int Queue::dequeue()
{
    is_valid();
    assert(!is_empty());
    
    Node* node = first;
    first = first->next;
    if (first == 0) {
        last = 0;
    }
    
    int value = node->value;
    delete node;
    
    return value;
}

bool Queue::is_empty() const
{
    is_valid();
    return first == 0;
}

void Queue::print(std::ostream& os) const
{
    Node* node = first;
    os << "[";
    while(node != 0) {
        os << node->value;
        if (node->next != 0) {
            os << " ";
        }
        node = node->next;
    }
    os << "]";
}

std::ostream& operator<<(std::ostream& os, const Queue& queue)
{
    queue.print(os);
    return os;
}

Queue::Queue(const Queue& other) : first(0), last(0)
{
    copy(other);
}

void Queue::operator=(const Queue& other)
{
    is_valid();
    // ignore self-assignments (node objects are not shared among queues)
    if (first != other.first) {
        clear();
        copy(other);
    }
}

Queue::~Queue()
{
    is_valid();
    clear();
}
