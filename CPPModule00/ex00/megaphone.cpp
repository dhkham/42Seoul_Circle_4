#include <iostream>
#include <string>

void ToUpper(std::string str) // std::string 표준 라이브러리에 정의된 문자열 클래스
{
    for (size_t i = 0; i < str.length(); ++i)
        std::cout << (char)toupper(str[i]); // ToUpper: char를 받아 내부적으로 int로 변환 후, 다시 int를 리턴해 char로 변환 필요
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
            ToUpper(argv[i]); 
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}
