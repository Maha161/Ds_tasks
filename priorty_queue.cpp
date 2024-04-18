template<typename ItemType>
class PriorityQueue {
private:
    struct Item {
        ItemType value;
        int priority;
    };
    int front;
    int rear;
    Item* items;
    int maxQue;
    int counter;
public:
    PriorityQueue() {
        maxQue = 500; 
        front = maxQue - 1;
        rear = maxQue - 1;
        items = new Item[maxQue];
        counter = 0;
    }
    PriorityQueue(int max) {
        maxQue = max;
        front = maxQue - 1;
        rear = maxQue - 1;
        items = new Item[maxQue];
        counter = 0;
    }

    ~PriorityQueue() {
        delete[] items;
    }

    bool IsFull() const {
        return counter == maxQue;
    }

    bool IsEmpty() const {
        return counter == 0;
    }

    void Enqueue(const ItemType& newItem, int priority) {  
        if (IsFull()) { 
            cout << "Queue is full\n";
        }
        else {
            rear = (rear + 1) % maxQue; 
            int pos = rear;
            while (pos != front && priority > items[pos].priority) {
                items[(pos + 1) % maxQue] = items[pos];
                pos = (pos - 1 + maxQue) % maxQue;
            }
            items[(pos + 1) % maxQue].value = newItem;
            items[(pos + 1) % maxQue].priority = priority;
            counter++;
        }
    }
    
    void Dequeue() {
        if (IsEmpty()) {
            std::cout << "Queue is empty\n";
        }
        else {
            front = (front + 1) % maxQue;
            counter--;
        }
    }

    ItemType get_front() {
        return items[(front + 1) % maxQue].value;
    }

    void printQueue() {
        int idx = (front + 1) % maxQue;
        while (idx != (rear + 1) % maxQue) {
            cout << items[idx].value << " ";
            idx = (idx + 1) % maxQue;
        }
        cout << endl;
    }
};
