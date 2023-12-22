//
// Created by Admin on 10.10.2023.
//

#ifndef TIMEMETER_MEMBERSWIN_H
#define TIMEMETER_MEMBERSWIN_H

#include <memory>
#include <windows.h>

class Members {
private:
    unsigned count;
    std::unique_ptr<double[]> timeStamps;
    LARGE_INTEGER start;
    LARGE_INTEGER frequency;
public:
    explicit Members(unsigned count) {
        this->count = count;
        this->timeStamps = std::unique_ptr<double[]>(new double[count]);
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start);
    }

    double setTimeStamp(unsigned num) {
        LARGE_INTEGER current;
        QueryPerformanceCounter(&current);
        timeStamps[num] = (current.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;
        return timeStamps[num];
    }

    double getSTimeStamp(unsigned num) {
        return timeStamps[num];
    }

    int64_t getMSTimeStamp(unsigned num) {
        return timeStamps[num];
    }

    double getSDiff(unsigned first, unsigned second) {
        return (timeStamps[second] - timeStamps[first]);
    }

    int64_t getMSDiff(unsigned first, unsigned second) {
        return (timeStamps[second] - timeStamps[first]);
    }

    bool isLess(unsigned first, unsigned second, int64_t expected) {
        return getMSTimeStamp(second) - getMSTimeStamp(first) < expected;
    }

    bool isLess(unsigned num, int64_t expected) {
        return getMSTimeStamp(num) < expected;
    }
};

#endif //TIMEMETER_MEMBERSWIN_H
