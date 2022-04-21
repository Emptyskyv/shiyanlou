#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, int> m;
    m[1] = 2;
    m[2] = 4;
    cout << m.size();
    cout << "Hello, World!" << std::endl;
    return 0;
}
