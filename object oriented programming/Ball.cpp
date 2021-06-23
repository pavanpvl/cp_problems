#include <iostream>
#include <string>

class Ball
{
private:
    std::string m_color{};
    double m_radius{};

public:
    Ball(const std::string &s = "black", double r = 10.0)
    {
        m_color = s;
        m_radius = r;
    }
    Ball(double r)
    {
        m_radius = r;
        m_color = "black";
    }
    void print()
    {
        std::cout<<m_radius<<" "<<m_color<<"\n";
    }
};

int main()
{

    Ball def{};
    def.print();

    Ball blue{"blue"};
    blue.print();

    Ball twenty{20.0};
    twenty.print();

    Ball blueTwenty{"blue", 20.0};
    blueTwenty.print();

    return 0;
}