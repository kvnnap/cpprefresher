export module test;

export import :extra;

export int add(int a, int b)
{
    return a + b;
}

export int y = add(2,3);
