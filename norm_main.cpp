#include <iostream>

int main()
{
    std::string result = "";
    char buf[400];


    FILE *file = popen("top", "r");
    for (int i = 0; i < 10;i++)
        result += fgets(buf, 400, file);
    std::cout << result << std::endl;
}
