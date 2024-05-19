class Node {
   public:
    int num;
    Node* next;
    Node(int num, Node* node) : num(num), next(node) {
    }
};

class LinkedList {
   public:
    Node* head;
    Node* tail;
    int length = 0;

    LinkedList() {
        head = new Node(-1, nullptr);
        tail = head;
    }

    int get(int index) {
        Node* target;
        if (index + 1 > length) {
            return -1;
        } else if (head == tail) {
            return -1;
        } else {
            for (int num = -1; num < index; num++) {
                if (num == -1) {
                    target = head->next;
                } else {
                    target = target->next;
                }
            }
            return target->num;
            // if I delete target here, is it useful? check it later
        }
    }

    void insertHead(int val) {
        Node* node = new Node(val, nullptr);
        if (head == tail) {
            head->next = node;
            tail = node;
        } else {
            node->next = head->next;
            head->next = node;
        }
        length++;
    }

    void insertTail(int val) {
        Node* node = new Node(val, nullptr);
        tail->next = node;
        tail = node;
        length++;
    }

    bool remove(int index) {
        Node* target;
        Node* previous;
        if (index + 1 > length) {
            return false;
        } else if (head == tail) {
            return false;
        } else {
            for (int num = -1; num < index; num++) {
                if (num == -1) {
                    previous = head;
                    target = head->next;
                } else {
                    previous = target;
                    target = target->next;
                }
            }
            if (target == tail) {
                tail = previous;
                previous->next = nullptr;
            } else {
                previous->next = target->next;
            }
            length--;
            return true;
        }
    }

    vector<int> getValues() {
        vector<int> arr;
        Node* target = head->next;
        if (head == tail) {
            return arr;
        } else {
            while (target != tail) {
                arr.push_back(target->num);
                target = target->next;
            }
            arr.push_back(target->num);
            return arr;
        }
    }
};
