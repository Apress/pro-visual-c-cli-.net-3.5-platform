using namespace System;

// Boxing in Action
value class POINT
{
public:
    int x, y;
    POINT(int x, int y) : x(x) , y(y) {}
};

void main()
{
    POINT p1(1,2);
    Object ^o = p1;
    POINT ^p2 = (POINT)o;

    Console::WriteLine("p1 x={0} y={1}\n", p1.x, p1.y);
    Console::WriteLine("o  x={0} y={1}\n", ((POINT)o).x, ((POINT)o).y);
    Console::WriteLine("p2 x={0} y={1}\n", p2->x, p2->y);
}