int main() {

    Container data;
    CreateObjects(data);

    // Container result = FirstNmatchingInstance(data, 3);
    // for(TouristVehicle* ptr : result) {
    //     std::cout<<*ptr
    // }




    // {
    //     Container result = FirstNmatchingInstance(data, 3);
    //     for(TouristVehicle* ptr : result) {
    //         std::cout<<*ptr
    //     }
    // }






    if(Container result = FirstNmatchingInstance(data, 3); !result.empty()) {
        for(TouristVehicle* ptr : result) {
            std::cout<<*ptr
        }
    } else {
        std::cout<<"result empty";
    }

}