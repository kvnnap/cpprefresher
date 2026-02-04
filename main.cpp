import std;

using std::cout;
using std::endl;
using std::string;
using std::vector;

import test;

int main(int argc, const char** argv)
{
    vector<int> a;
    a.push_back(1);
    cout << "hello: " << string(argv[0]) << ":" << a.at(0) << endl;
    cout << "add: " << subtract(1, 2) << endl;
    return 0;
}
