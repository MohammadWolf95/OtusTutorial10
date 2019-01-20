#include "blockoutput.h"
#include <iostream>
#include <cstring>

Blockoutput::Blockoutput(Model *model){
    model->attach(this);
    this->model = model;
}

void Blockoutput::update(){
    print();
}

void Blockoutput::print(){
    auto&vec = model->vecCommands;
    if(vec.size()==0)
        return;

    std::string str = "bulk: ";
    for(auto it:model->vecBulk){
        str+=(it+", ");
    }
    str = str.substr(0, str.size()-2);
    std::cout<<str<<std::endl;
}
