#include <cpr/cpr.h>
#include <iostream>

int main(int argc, char** argv)
{
    cpr::Response r = cpr::Get(cpr::Url { "https://wttr.in/Taganrog?m&lang=ru" });

    std::cout << r.text << std::endl;
    return 0;
}