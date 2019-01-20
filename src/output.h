#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>

class Model;
#include "model.h"

class Output
{
public:
    Output();
    virtual ~Output(){}
    virtual void update()=0;
    auto getModel(){
        return model;
    }
protected:
    Model*model;
    size_t count;
    virtual void print()=0;
};

#endif // OUTPUT_H
