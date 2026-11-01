#ifndef QUEUEARR_H
#define QUEUEARR_H

// Array-Based Circular Queue
template <typename T>
class queueArr {
    private:

        T* q_arr; // Pointer for allocation
        size_t q_capacity; // To define the maximum capacity
        size_t q_size; // To display the current size
        int q_front; // Index value of the front
        int q_back; // Index of the back

    public:

    // Constructor
    queueArr(size_t capacity) : q_capacity(capacity), q_size(0), q_front(0), q_back(-1) {
        q_arr = new T[q_capacity];
    }

    // Copy Constructor
    queueArr(const queueArr& other) : q_capacity(other.q_capacity), q_size(other.q_size), 
    q_front(other.q_front), q_back(other.q_back) {

        q_arr = new T[q_capacity];

        for (size_t i = 0; i < q_size; ++i) {
            q_arr[(q_front + i) % q_capacity] = other.q_arr[(other.q_front + i) % other.q_capacity];
        }
    }

    // Copy Assignment
    queueArr& operator=(const queueArr& other) {
        if (this != &other) {
            delete[] q_arr;

            q_capacity = other.q_capacity;
            q_size = other.q_size;
            q_front = other.q_front;
            q_back = other.q_back;

            q_arr = new T[q_capacity];
            for (size_t i = 0; i < q_size; ++i) {
                q_arr[(q_front + i) % q_capacity] = other.q_arr[(other.q_front + i) % other.q_capacity];
            }
        }
        return *this;
    }

    // Destructor
    ~queueArr() {
        delete[] q_arr;
    }

    // Queue Operations
    bool Empty();
    bool Full();
    size_t Size();
    void Clear();
    T Front();
    T Back();
    void enqueue(T value);
    T dequeue();
};

// isEmpty()
template <typename T>
bool queueArr<T>::Empty() {
    // CHECK IF EMPTY
    return q_size == 0;
}

// isFull
template <typename T>
bool queueArr<T>::Full() {
    return q_size == q_capacity;
}

// Size()
template <typename T>
size_t queueArr<T>::Size() {
    // RETURN CURRENT SIZE OF QUEUE
    return q_size;
}

// Front()
template <typename T>
T queueArr<T>::Front() {
    // Check if the queue is empty
    if (Empty()) {
        std::cout << "Queue is Empty\n";
        return T(); // Return default value of type T
    }
    // Return the front
    return q_arr[q_front];
}

// Back()
template <typename T>
T queueArr<T>::Back() {
    // Check if the queue is empty
    if (Empty()) {
        std::cout << "Queue is Empty\n";
        return T(); // Return default value of type T
    }
    // Return the back
    return q_arr[q_back];
}

// Clear()
template <typename T>
void queueArr<T>::Clear() {
    // Reset the queue to its initial state
    q_size = 0;
    q_front = 0;
    q_back = -1; // Set back to -1 since there are no elements
}

// Enqueue()
template <typename T>
void queueArr<T>::enqueue(T value) {
    // Check if the queue is full
    if (Full()) {
        std::cout << "Queue is Full\n";
        return;
    }
    // Increment the back
    q_back = (q_back + 1) % q_capacity;   
    // Add the new value to the back of the queue
    q_arr[q_back] = value;
    // Increment the size of the queue
    q_size++;
}

// Dequeue()
template <typename T>
T queueArr<T>::dequeue() {
    // Check if the queue is empty
    if (Empty()) {
        std::cout << "Queue is Empty\n";
        return T(); // Return default value of type T
    }
    // Store the front value
    T value = q_arr[q_front];
    // Increment the front index in a circular manner
    q_front = (q_front + 1) % q_capacity;
    // Decrement the size of the queue
    q_size--;
    // Reset the indexes
    if (Empty()) Clear();   
    // Return the dequeued value
    return value;
}

#endif

