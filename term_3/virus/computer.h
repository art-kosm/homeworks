#pragma once

enum OperatingSystem
{
    Windows,
    Linux,
    MacOS,
    FreeBSD,
    NoSystem
};

class Computer
{
public:
    Computer(OperatingSystem system = NoSystem, bool infected = false);
    virtual ~Computer() {}
    virtual void attack();
    virtual bool isInfected();

protected:
    virtual bool tryToInfect(OperatingSystem system);
    OperatingSystem system;
    bool infected;
};
