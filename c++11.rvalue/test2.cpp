#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class MyPoint{
public:
    MyPoint():comment(""), x(0), y(0){}
    MyPoint(const MyPoint& p):comment(p.comment),x(p.x),y(p.y) {}
    MyPoint(MyPoint&& p):comment(move(p.comment)), x(p.x), y(p.y)
	{
        p.x = 0;
        p.y = 0;
    }
    string toString()
    {
        char buf[100];
        sprintf(buf, "%s: %d %d", comment.c_str(), x, y);
        return buf;
    }
    string comment;
    int x;
    int y;
};


void test2()
{

    MyPoint p;
    p.comment = "First point";
    p.x = 9;
    p.y = 7;

    vector<MyPoint> v;
    v.push_back(p);
    cout << "After copy, str is \"" << p.toString() << "\"\n";
    v.push_back(move(p));
    cout << "After move, str is \"" << p.toString() << "\"\n";
    cout << "The contents of the vector are \"" << v[0].toString()
		<< "\", \"" << v[1].toString() << "\"\n";
}