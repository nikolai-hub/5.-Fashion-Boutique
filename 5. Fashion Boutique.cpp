#include <iostream>
#include <string>
#include <sstream>
#include <stack>

std::stack<int> readInput() {
    std::stack<int> input;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream istr(line);
    int numberOfClothes = 0;
    while (istr >> numberOfClothes)
    {
        input.push(numberOfClothes);
    }
    return input;
}

int main()
{
    std::stack<int> clothesInTheBox = readInput();
    int capacityOfRacks = 0;
    std::cin >> capacityOfRacks;
    std::cin.ignore();
    int fullRacks = 0;
    int sumValues = 0;

    while (!clothesInTheBox.empty())
    {
        sumValues += clothesInTheBox.top();
        if (sumValues <= capacityOfRacks)
        {
            clothesInTheBox.pop();
            continue;
        }
        else
        {
            fullRacks++;
            sumValues = 0;
        }
    }
    std::cout << fullRacks + 1 << std::endl;
    

    return 0;
}

