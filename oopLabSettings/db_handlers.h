#pragma once
#include "Parcel.h"
#include "DTOs.h"


template <typename T> class Db {
public:
    virtual int read_number()=0;
    virtual T* read_data()=0;

};

class Map_db :Db<connection> {
public:
    Map_db() = default;
    int read_number() override;
    connection* read_data() override;
};

class History_db :Db<Parcel> {
public:
    History_db() = default;
    int read_number() override;
    Parcel* read_data() override;
    void save_data(int weight, int volume, Date sending_date, Date receiving_date, int price, int origin, int destination, bool premium, string sender, string recipient);
};
