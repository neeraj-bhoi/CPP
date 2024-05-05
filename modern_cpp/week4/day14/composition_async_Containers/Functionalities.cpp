#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"

void CreateObjects(Container &data)
{
    data.emplace(
        "c101", 
        std::make_shared<Car> (
            "c101", 
            7500000.0f, 
            "Honda city", 
            std::make_shared<Engine> (
                400, 
                118
            ), 
            CarType::SEDAN
        )
    );

    data.emplace(
        "c102", 
        std::make_shared<Car> (
            "c102", 
            5500000.0f, 
            "amaze", 
            std::make_shared<Engine> (
                300, 
                100
            ), 
            CarType::HATCHBACK
        )
    );

    data.emplace(
        "c103", 
        std::make_shared<Car> (
            "c103", 
            8500000.0f, 
            "kia seltos", 
            std::make_shared<Engine> (
                500, 
                150
            ), 
            CarType::SUV
        )
    );
}

// void DeleteObjects(const Container &data)
// {
//     if(data.empty()) {
//         throw EmptyContainerException("data is empty", std::future_errc::no_state);
//     }

//     for(Car* c: data) {
//         delete c->engine(); //due to 
//         delete c;
//     }
// }

void TotalHorsepower1(const Container &data)
{
    if(data.empty()) {
        throw EmptyContainerException("data is empty", std::future_errc::no_state);
    }

    std::cout<< std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](float answer_upto_current_point, const std::pair<std::string, CarPointer>& row) {
            return answer_upto_current_point + row.second->engine()->horsepower();
        }
    );

    // float total = 0.0f;

    // for(Car* c: data) {
    //     total += c->engine()->horsepower();
    // }

    // std::cout<< total<<"   jeirfioewnifni\n";


}

bool IsContainerAllCarAbove700000(const Container &data)
{
    if(data.empty()) {
        throw EmptyContainerException("data is empty", std::future_errc::no_state);
    }

    return std::all_of(
        data.begin(),
        data.end(),
        [](const std::pair<std::string, CarPointer>& row) {
            return row.second->price() > 700000.0f;
        }
    );

    // for(Car* c:data) {
    //     if(c->price() <= 700000) {
    //         return false;
    //     }
    // }

    // return true;    //reaching this point means, no car has price below 7 lakh


}

Engine* EnginePointerToMinPriceCar(const Container &data)
{
    if(data.empty()) {
        throw EmptyContainerException("data is empty", std::future_errc::no_state);
    }

    auto itr = std::min_element(
        data.begin(),
        data.end(),
        [](const std::pair<std::string, CarPointer>& row1, const std::pair<std::string, CarPointer>& row2) {
            return row1.second->price() < row2.second->price();
        }
    );

    return (*itr).second->engine().get();

    // //assume first data as min
    // float min_price = data[0]->price();
    // Engine* e = data[0]->engine();

    // for(Car* c: data) {
    //     if(c->price() < min_price) {
    //         min_price = c->price();
    //         e = c->engine();
    //     }
    // }

    // return e;



}

float AverageEngineTorque(const Container &data)
{
    if(data.empty()) {
        throw EmptyContainerException("data is empty", std::future_errc::no_state);
    }

    std::size_t count{0};
    float answer =  std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](float answer_upto_current_point, const std::pair<std::string, CarPointer>& row) {
            if(row.second->engine()) {
                count++;
                return answer_upto_current_point + row.second->engine()->horsepower();
            }
            return answer_upto_current_point;
        }
    );

    return answer / static_cast<float>(count);

    // int arr[] = {1, 2, 3, 4};
    // Engine e1(500, 120.0f);
    // Engine* eptr = new Engine(500, 120.0f);
    // // struct Demo d1 = {90, 100};
    // // std::

    //in modern cpp initialization can be done universely in {};

    
    // float total_value {0.0f};
    // for(Car* c: data) {
    //     total_value += c->engine()->torque();
    // }

    // return total_value/data.size();


}

std::string FindCarModelById(const Container &data, std::string carId)
{
    if(data.empty()) {
        throw EmptyContainerException("data is empty", std::future_errc::no_state);
    }

    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](const std::pair<std::string, CarPointer>& row) {
            return row.second->id() == carId;
        }
    );
    if(itr == data.end()) {
        std::cerr<< " data not found.";
        // return (*itr).second->id();
        throw std::runtime_error("Id not found\n");
    }
    return (*itr).second->model();

    // for(Car* c: data) {
    //     if(c->id() == carId) {
    //         return c->model();
    //     }
    // }


    // throw IdNotFoundException("id not found");
    // // return ;


}
