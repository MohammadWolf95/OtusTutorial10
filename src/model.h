#pragma once
#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include "output.h"

class Output;

class Model
{
public:
    Model(size_t &N);
    void attach_static(Output*obs){
        _views_static.emplace_back(obs);
    }
    void attach_dynamic(Output*obs){
        _views_dynamic.emplace_back(obs);
    }
    void set_str(std::string &str);
    void get_time();
    void setFirstFixedTime();
    size_t getFirstFixedTime(){
        return _firstFixedTime;
    }
    std::vector<std::string>vecCommands;
    std::vector<std::string>vecBulk;
private:
    std::vector<Output *> _views_static, _views_dynamic;
    void update(const std::string& str);
    size_t get_fixed_time();

    size_t _fixedTime;
    size_t _firstFixedTime;
    size_t n_arg;
    std::string controle_str;
};

#endif // MODEL_H
