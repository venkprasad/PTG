#include<iostream>
#include<thread>
#include<chrono>
#include<random>
#include<mutex>
using namespace std;
class VehicleData {
    public:
    float speed,fuel,temp;
    VehicleData(): speed(0),fuel(100),temp(90) {}
   void updatedata() {
        // Generating random values using rand() function
        speed = rand() % 201;  // Speed between 0 and 200
        fuel = rand() % 101;   // Fuel between 0 and 100
        temp = rand() % 121;   // Temperature between 0 and 120
    }
};
class Display {
    private:
    VehicleData &vehicledata;
    mutex mtx;
    public:
    Display(VehicleData &data) : vehicledata(data) {
    }
    void showdata(){
        lock_guard<mutex>lock(mtx);
        cout<<"speed"<<vehicledata.speed<<"km/h"<<endl; 
        cout<<"Fuel"<<vehicledata.fuel<<"%"<<endl;
        cout<<"Temp"<<vehicledata.temp<<"\u00B0C"<<endl;
        if(vehicledata.fuel<10) cout<<"Warning: Fuel low!";
        if(vehicledata.temp>100) { cout<<"Warning : Engine overheating!"; 
        }
        cout.flush();  //to get the output fast
    }
    };
    void updateVehicleData(VehicleData & vehicledata){
        while(true){
            vehicledata.updatedata();
            this_thread::sleep_for(chrono::seconds(1)); 
        }
    }
int main()   {
   VehicleData vehicledata;
   Display display(vehicledata);
   thread dataupdater(updateVehicleData,ref(vehicledata));  //creating a thread
   while(true){
       display.showdata();
       this_thread::sleep_for(chrono::seconds(1)); //to sleep the thread for 1 second
   }
   dataupdater.join(); 
    return 0;
}