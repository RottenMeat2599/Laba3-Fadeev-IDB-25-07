#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    int front() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    void printAll() {
        stack<int> t1 = s1, t2 = s2;
        vector<int> left, right;

        while (!t2.empty()) {
            left.push_back(t2.top());
            t2.pop();
        }
        while (!t1.empty()) {
            right.insert(right.begin(), t1.top());
            t1.pop();
        }

        left.insert(left.end(), right.begin(), right.end());
        for (int x : left) cout << x << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front: " << q.front() << endl;
    cout << "printAll: ";
    q.printAll();

    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "printAll: ";
    q.printAll();

    return 0;
}
