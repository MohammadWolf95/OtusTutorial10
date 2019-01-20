#include "fileoutput.h"
#include "blockoutput.h"
#include <iostream>
#include "model.h"

using namespace std;

int main(int argc, char *argv[])
{
    try{
        if(argc<=1)
            throw argc;
        string str;
        char*p;
        size_t N = strtol(argv[1],&p,10);
        Model mod(N);
        Blockoutput c_obs(&mod);
        Fileoutput f_obs(&mod);
        while(getline(cin, str)){
            mod.get_time();
            mod.set_str(str);
        }
    }
    catch(int&i){
        cout<<"Error: argc = "<<i<<endl;
    }
}
