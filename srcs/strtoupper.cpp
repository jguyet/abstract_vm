
#include <string>
#include <iostream>

std::string strtoupper(std::string str)
{
	std::string	tmp;

	tmp += str;
    int leng = tmp.length();
    for(int i = 0; i < leng; i++)
        if (97 <= tmp[i] && tmp[i] <= 122)//a-z
            tmp[i] -= 32;
    return tmp;
}
