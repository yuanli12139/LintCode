/*
498. Parking Lot
Design a parking lot.

see CC150 OO Design for details.

n levels, each level has m rows of spots and each row has k spots.So each level has m x k spots.
The parking lot can park motorcycles, cars and buses
The parking lot has motorcycle spots, compact spots, and large spots
Each row, motorcycle spots id is in range [0,k/4)(0 is included, k/4 is not included), compact spots id is in range [k/4,k/4*3) and large spots id is in range [k/4*3,k).
A motorcycle can park in any spot
A car park in single compact spot or large spot
A bus can park in five large spots that are consecutive and within same row. it can not park in small spots

Example
level=1, num_rows=1, spots_per_row=11
parkVehicle("Motorcycle_1") // return true
parkVehicle("Car_1") // return true
parkVehicle("Car_2") // return true
parkVehicle("Car_3") // return true
parkVehicle("Car_4") // return true
parkVehicle("Car_5") // return true
parkVehicle("Bus_1") // return false
unParkVehicle("Car_5")
parkVehicle("Bus_1") // return true


Author: Yuan Li
Date: 8/22/2018 
Difficulty: Hard
*/

// enum type for Vehicle
enum class VehicleSize {
    Motorcycle,
    Compact,
    Large
};

class Vehicle {
    // Write your code here
  public:
    virtual VehicleSize size() = 0;
    virtual int spotSize() = 0;
};

class Bus : public Vehicle {
    // Write your code here
  public:
    VehicleSize size() {
        return VehicleSize::Large;
    }
    
    int spotSize() {
        return 5;
    }
};

class Car : public Vehicle {
    // Write your code here
  public:
    VehicleSize size() {
        return VehicleSize::Compact;
    }
    
    int spotSize() {
        return 1;
    }
};

class Motorcycle : public Vehicle {
    // Write your code here
  public:
    VehicleSize size() {
        return VehicleSize::Motorcycle;
    }
    
    int spotSize() {
        return 1;
    }
};

class Level {
    // Write your code here
  public:
    Level(int num_rows, int spots_per_row) {
        num_rows_ = num_rows;
        spots_per_row_ = spots_per_row;
        
        for (int r = 0; r < num_rows; ++r) {
            spots_.push_back(vector<Vehicle*>(spots_per_row, nullptr));
        }
    }
    
    bool parkVehicle(Vehicle* vehicle) {
        for (int r = 0; r < num_rows_; ++r) {
            int start = 0;
            
            if (vehicle->size() == VehicleSize::Compact) {
                start = spots_per_row_ / 4; 
            }
            
            if (vehicle->size() == VehicleSize::Large) {
                start = spots_per_row_ / 4 * 3;
            }
            
            for (int i = start; i <= spots_per_row_ - vehicle->spotSize(); ++i) {
                if (spots_[r][i]) {
                    continue;
                }
                
                bool isAvailable = true;
                for (int j = i; j < i + vehicle->spotSize(); ++j) {
                    if (spots_[r][j]) {
                        isAvailable = false;
                        break;
                    }
                }
                
                if (isAvailable) {
                    fill(spots_[r].begin()+i, spots_[r].begin()+i+vehicle->spotSize(), vehicle);
                    return true;
                }
            }
        }
            
        return false;
    }
    
    void unParkVehicle(Vehicle* vehicle) {
        for (auto &row : spots_) {
            for (auto &spot : row) {
                if (spot == vehicle) {
                    spot = nullptr;
                }
            }
        }
    }
    
  private:
    vector<vector<Vehicle*>> spots_;
    int num_rows_;
    int spots_per_row_;
};

class ParkingLot {
  public:
    // @param n number of leves
    // @param num_rows  each level has num_rows rows of spots
    // @param spots_per_row each row has spots_per_row spots
    ParkingLot(int n, int num_rows, int spots_per_row) {
        // Write your code here
        for (int i = 0; i < n; ++i) {
            Level* level = new Level(num_rows, spots_per_row);
            levels_.push_back(level);
        }
    }

    // Park the vehicle in a spot (or multiple spots)
    // Return false if failed
    bool parkVehicle(Vehicle* vehicle) {
        // Write your code here
        for (auto &level : levels_) {
            if (level->parkVehicle(vehicle)) {
                vehicle_to_level_[vehicle] = level;
                return true;
            }
        }
        
        return false;
    }

    // unPark the vehicle
    void unParkVehicle(Vehicle* vehicle) {
        // Write your code here
        if (vehicle_to_level_.count(vehicle)) {
            vehicle_to_level_[vehicle]->unParkVehicle(vehicle);
        }
    }
    
  private:
    vector<Level*> levels_;
    unordered_map<Vehicle*, Level*> vehicle_to_level_;
};
