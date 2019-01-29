#include "src/model.h"
#include <string>
#include "utils.h"
class Output;

Model::Model(size_t &N):
    n_arg(N), controle_str("")
{

}

void Model::update(const std::string &str){
    if(str != "{"&&str != "}"){
        vecBulk.emplace_back(str);
        vecCommands.emplace_back(str);
        if(vecBulk.size()==1)
            setFirstFixedTime();
        if(vecCommands.size()==this->n_arg&&controle_str==""){//режим статический
            /*for(auto&i:_views)
                i->print();*/
            for(auto&i:_views_static){
                i->mThread = std::thread([i]{i->print();});
            }
            for(auto&i:_views_static){
                if(i->mThread.joinable())
                        i->mThread.join();
            }
            vecCommands.clear();
            vecBulk.clear();
        }
    }
    else{
        if(str=="{"){
            if(controle_str.size()==0&&vecBulk.size()!=0){//режим динамический
                /*for(auto&i:_views)
                    i->print();*/
                for(auto&i:_views_dynamic){
                    i->mThread = std::thread([i]{i->print();});
                }
                for(auto&i:_views_dynamic){
                    if(i->mThread.joinable())
                            i->mThread.join();
                }//нужно исправить*/
                vecCommands.clear();
                vecBulk.clear();
            }
            controle_str+="{";
            vecCommands.emplace_back("{");
        }
        else if(controle_str.size()!=0){
            vecCommands.emplace_back("}");
            controle_str = controle_str.substr(0, controle_str.size()-1);
            if(controle_str==""){//режим статический
                /*for(auto&i:_views)
                    i->print();*/

                for(auto&i:_views_static){
                    i->mThread = std::thread([i]{i->print();});
                }
                for(auto&i:_views_static){
                    if(i->mThread.joinable())
                            i->mThread.join();
                }
                vecCommands.clear();
                vecBulk.clear();
            }
        }
    }
}

void Model::get_time(){
    _fixedTime = clock();
}

size_t Model::get_fixed_time(){
    return _fixedTime;
}

void Model::setFirstFixedTime(){
    _firstFixedTime = get_fixed_time();
}

void Model::set_str(std::string& str){
    remove_space(str);
    if(str!=""){
        update(str);
    }
}
