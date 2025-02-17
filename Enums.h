#ifndef ENUMS_H
#define ENUMS_H

enum Command
{
    C_Invalid = 0,
    C_Manual,
    C_Automatic,
    C_Blinking,
    C_Strobe,
    C_Random,
    C_Count,
};


static const int MinTime = 250;
static const int MaxTime = 180 * 1000;

#endif // ENUMS_H
