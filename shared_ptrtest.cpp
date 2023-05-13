#include <memory>
#include <iostream>

using namespace std;

class a;

class b;

class a {
public:
    shared_ptr<b> atob;

    ~a() {
        cout << "a delete" << endl;
    }
};

class b {
public:
    weak_ptr<a> btoa;

    ~b() {
        cout << "b delete" << endl;
    }
};

void fun() {
    shared_ptr<a> pa(new a());
    shared_ptr<b> pb(new b());
    pa->atob = pb;
    pb->btoa = pa;
    cout << pa.use_count() << endl;
    cout << pb.use_count() << endl;
}

int main() {
    fun();

    return 0;
}