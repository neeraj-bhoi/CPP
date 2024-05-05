#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "NotFoundException.h"

void CreateObject(PermitContainer& Pdata, TouristContainer &Tdata)
{
    Pdata.push_back(new Permit("ABC12", PermitType::LEASE, 34));

    Pdata.push_back(new Permit("ABC13", PermitType::OWNED, 24));
    Pdata.push_back(new Permit("ABC14", PermitType::OWNED, 20));
    Pdata.push_back(new Permit("ABC15", PermitType::LEASE, 38));

    
    Tdata.push_back(new TouristVehicle("XYZ790", TouristVehicleType::BUS, 14, 1500.0f, *Pdata[1]));
    Tdata.push_back(new TouristVehicle("XYZ789", TouristVehicleType::CAR, 4, 500.0f, *Pdata[0]));
    Tdata.push_back(new TouristVehicle("XYZ791", TouristVehicleType::BIKE, 2, 300.0f, *Pdata[2]));
    Tdata.push_back(new TouristVehicle("XYZ792", TouristVehicleType::CAR, 7, 1200.0f, *Pdata[3]));
}

TouristVehicle *Find_n_instances(TouristContainer &Tdata, int n)
{
    if (Tdata.empty())
    {
        throw EmptyContainerException("Empty Container");
    }
    if (n > Tdata.size())
    {
        throw NotFoundException("OUT OF RANGE");
    }

    for (int i = 0; i < n; i++)
    {
        if (Tdata[i]->seatCount() > 4 && Tdata[i]->permit().get().permitType() == PermitType::LEASE)
        {
            return Tdata[i];
        }
    }
    throw NotFoundException("NOT FOUND instance!!");

    return nullptr;
}

float Avg_BookingCharge(TouristContainer &Tdata, int n)
{
    if (Tdata.empty())
    {
        throw EmptyContainerException("Empty Container");
    }
    if (n > 3)
    {
        throw NotFoundException("OUT OF RANGE");
    }
    int cnt =0;
    float sum = 0.0f;
    for (TouristVehicle *v : Tdata)
    {
        if (v->type() == static_cast<TouristVehicleType>(n)){
            sum += v->perHourBookingCharge();
            cnt++;
        }
    } 
    float avg = 0.0f;
    avg = sum / cnt;
    return avg;
}

std::string Max_PerHour_BookingCharge(TouristContainer &Tdata)
{
    if (Tdata.empty())
    {
        throw EmptyContainerException("Empty Container");
    }
    float max = Tdata[0]->perHourBookingCharge();
    for (TouristVehicle *v : Tdata)
    {
        if (max < v->perHourBookingCharge())
        {
            max = v->perHourBookingCharge();
        }
    }
    for (TouristVehicle *v : Tdata)
    {
        if (max == v->perHourBookingCharge())
        {
            return v->permit().get().serialNumber();
        }
    }
    throw NotFoundException("NOT FOUND!!");

    return std::string();
}

void print_n_instanecs(TouristContainer &Tdata, int n)
{
    if (Tdata.empty())
    {
        throw EmptyContainerException("Empty Container");
    }
    if (n > Tdata.size())
    {
        throw NotFoundException("OUT OF RANGE");
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << *Tdata[i] << std::endl;
    }
}

void DeleteObject(TouristContainer &Tdata, PermitContainer& Pdata)
{
    if (Tdata.empty())
    {
        throw EmptyContainerException("Empty Container");
    }
    for (Permit *p : Pdata)
    {
        delete p;
        p = nullptr;
    }
    for (TouristVehicle *v : Tdata)
    {
        delete v;
    }
}
