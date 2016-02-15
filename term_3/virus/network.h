#pragma once

#include <initializer_list>
#include <vector>
#include "computer.h"

class Network
{
public:
    void addNewComputer(Computer *computer, std::initializer_list<Computer*> list = {});
    void showConnections();
    void showState();
    void update();

private:
    std::vector<Computer*> computers;
    std::vector< std::vector<bool> > connections;
};
