import std;
import test;
import shape;
import separated;
import split;

int main(int, const char**)
{
    using namespace std;
    println("Println yay: {}", subtract(2,3));
    println("{}", get_area());
    println("{}", compute());
    println("module var: {}", y);
    println("split sp: {}", sp());
    return 0;
}
