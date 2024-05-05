#include <iostream>
#include "Functionalities.h"
#include "IdNotFoundException.h"
#include "EmptyContainerException.h"
#include<thread>
#include<future>

int main() {
    Container data;

    std::thread t1(CreateObjects, std::ref(data));
    t1.join();
    try {
        std::future<void> ans = std::async(TotalHorsepower1, std::ref(data));
        // std::cout<< "Total horsepower is :" <<ans<<"\n";

        std::future<float> result = std::async(&AverageEngineTorque, std::ref(data));
        // std::cout<<"Average value is : "<<result<<"\n";

        std::future<std::string> model = std::async(&FindCarModelById, std::ref(data), "c101");
        // std::cout<<"Model for given id found "<< model <<"\n";

        std::future<bool> flag = std::async(&IsContainerAllCarAbove700000, std::ref(data));
        // if(flag) {
        //     std::cout<<"All vehicles have price above 7 lakh.\n";
        // } else {
        //     std::cout<<"Some vehicles have price below 7 lakh.\n";
        // }

        std::future<Engine*> e = std::async(&EnginePointerToMinPriceCar, std::ref(data));
        // std::cout<<"Engine found : "<<*e<<"\n";


        // std::cout<< "Total horsepower is :" <<ans.get()<<"\n";
        ans.get();
        std::cout<<"Average value is : "<<result.get()<<"\n";
        std::cout<<"Model for given id found "<< model.get() <<"\n";
        if(flag.get()) {
            std::cout<<"All vehicles have price above 7 lakh.\n";
        } else {
            std::cout<<"Some vehicles have price below 7 lakh.\n";
        }
        std::cout<<"Engine found : "<<*e.get()<<"\n";

        // DeleteObjects(data);
    } catch(const std::future_error& ex) {
        if(ex.code() == std::future_errc::no_state) {
            std::cout<< "Missing input/result value. \n" ;
        }
        if(ex.code() == std::future_errc::future_already_retrieved) {
            std::cout<< "you already retrieved the value. don't try again! \n" ;
        }
    }

    //  catch(const EmptyContainerException& ex) {        //these exceptcdions will not work... in future exceptions
    //     std::cout<<ex.what()<<"\n";
    // } catch(const IdNotFoundException& ex) {
    //     std::cout<<ex.what()<<"\n";
    // }
    
}


