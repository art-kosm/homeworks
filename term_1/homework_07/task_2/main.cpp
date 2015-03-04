#include <iostream>
#include "string.h"

int main()
{
    char string[] = "C:\\Users\\kofochka\\Documents\\Qt projects\\other_projects\\scanningNumbers\\myFile.txt";
    String *str1 = createString(string);
    std::cout << length(str1) << "\n";

    deleteString(str1);

    return 0;
}

