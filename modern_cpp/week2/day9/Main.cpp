#include"Functionalities.h"

int main() {
    Container data{1, 2, 3, 4, 5};
    try{
        Adaptor(lfn1, data);
        Adaptor(lfn2, data);
        Adaptor(lfn3, data);
    } catch(std::runtime_error& ex) {
        std::cout<<ex.what();
    }
}