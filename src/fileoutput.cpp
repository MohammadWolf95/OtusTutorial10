#include "fileoutput.h"
#include <string>
#include "model.h"
#include "output.h"
class Model;
class Output;

Fileoutput::Fileoutput(Model *model)
{
    count = 0;
    model->attach(this);
    this->model = model;
}

void Fileoutput::createFile(std::string name){
    closeFile();
    _outfile.open(name, std::fstream::in | std::fstream::out | std::fstream::app);
    _outfile<<"input | output"<<std::endl;
    _outfile<<"------|-------"<<std::endl;
}

void Fileoutput::closeFile(){
    if(_outfile.is_open())
        _outfile.close();
}

void Fileoutput::print(){
    std::string str = "";
    std::string tab = "\t\t|\n";
    for(auto it:model->vecCommands)
        _outfile<<it+tab;
    for(auto it:model->vecBulk){
        str+=(it+", ");
    }
    str = str.substr(0, str.size()-2);
    if(model->vecCommands.size()!=0)
        _outfile<<"\t\t| bulk: "<<str<<std::endl;
}

void Fileoutput::update(){
    if(model->vecBulk.size()!=0){
        createFile("bulk"+std::to_string(model->getFirstFixedTime())+".log");
        print();
    }
}
