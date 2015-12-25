#include <iostream>
#include "network.h"

void Network::addNewComputer(Computer *computer, std::initializer_list<Computer*> list)
{
    computers.push_back(computer);
    std::vector<bool> row;
    connections.push_back(row);

    int last = connections.size() - 1;
    for (int i = 0; i < last; i++)
    {
        bool edge = false;
        for (auto element : list)
            if (element == computers[i])
            {
                edge = true;
                break;
            }

        connections[i].push_back(edge);
        connections[last].push_back(edge);
    }

    connections[last].push_back(false);
}

void Network::showConnections()
{
    int size = connections.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            std::cout << (connections[i][j] ? "1" : "0");
        std::cout << "\n";
    }
}

void Network::showState()
{
    int size = computers.size();
    for (int i = 0; i < size; i++)
        std::cout << "Computer " << i + 1 << " is " << (computers[i]->isInfected() ? "" : "NOT ") << "infected.\n";
}

void Network::update()
{
    int size = computers.size();
    std::vector<int> toAttack; // contains neighbours of the infected computers

    for (int i = 0; i < size; i++)
        if (computers[i]->isInfected()) // choosing the infected ones
            for (int j = 0; j < size; j++)
                if (connections[i][j]) // choosing their neighbours
                    toAttack.push_back(j);

    for (auto i : toAttack)
        computers[i]->attack();
}
