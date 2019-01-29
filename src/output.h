#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>

class Model;
#include "model.h"
#include <thread>

class Output
{
public:
    Output();
    virtual ~Output(){}
    virtual void print()=0;
    auto getModel(){
        return model;
    }
    std::thread mThread;
protected:
    Model*model;
    size_t count;
};

#endif // OUTPUT_H
