#include "filedynamic.h"
#include <string>
#include "model.h"
#include "output.h"
class Model;
class Output;

Filedynamic::Filedynamic(Model *model)
{
    count = 0;
    model->attach_dynamic(this);
    this->model = model;
}

void Filedynamic::createFile(std::string name){
    closeFile();
    _outfile.open(name, std::fstream::in | std::fstream::out | std::fstream::app);
    _outfile<<"input | output"<<std::endl;
    _outfile<<"------|-------"<<std::endl;
}

void Filedynamic::closeFile(){
    if(_outfile.is_open())
        _outfile.close();
}

void Filedynamic::print(){
    if(model->vecBulk.size()!=0){
        createFile("bulk"+std::to_string(model->getFirstFixedTime())+".log");
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
}

