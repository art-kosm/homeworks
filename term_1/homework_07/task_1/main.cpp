#include <iostream>
#include <fstream>

using namespace std;

int convertToNumber(char character)
{
    int difference = '1' - 1;
    return character - difference;
}

int getVariant(int donators[], int student)
{
    while (student > 3)
        student = donators[student - 1];

    return student;
}

int main()
{
    const int maxLength = 512;

    char path[maxLength];
    cout << "Enter the file path: ";
    cin.getline(path, maxLength);
    ifstream in(path);

    if (in == nullptr)
    {
        cout << "No such file found.";
        return 0;
    }

    int studentsNumber = 0;
    char str[maxLength];
    in.getline(str, maxLength);
    for (int i = 0; str[i] != '\0'; i++)
        studentsNumber = 10 * studentsNumber + convertToNumber(str[i]);
    int *donators = new int[studentsNumber];
    while (!in.eof())
    {
        in.getline(str, maxLength);
        int student = 0;
        int counter = 0;
        while (str[counter] != ' ')
        {
            student = 10 * student + convertToNumber(str[counter]);
            counter++;
        }
        int donator = 0;
        counter++;
        while (str[counter] != '\0')
        {
            donator = 10 * donator + convertToNumber(str[counter]);
            counter++;
        }
        donators[student - 1] = donator;
    }

    cout << "Variants: \n";
    for (int i = 1; i <= studentsNumber; i++)
        if (donators[i - 1] != 0)
            cout << i << " " << getVariant(donators, i) << "\n";
        else if (i < 4)
            cout << i << " " << i << "\n";

    cout << "To eliminate: \n";
    for (int i = 4; i <= studentsNumber; i++)
        if (donators[i - 1] == 0)
            cout << i << "\n";

    delete [] donators;

    return 0;
}
