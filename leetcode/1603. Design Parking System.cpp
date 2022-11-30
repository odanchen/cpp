class ParkingSystem {
private:
    int bigSpace;
    int mediumSpace;
    int smallSpace;
public:
    ParkingSystem(int big, int medium, int small) {
        this->bigSpace = big;
        this->mediumSpace = medium;
        this->smallSpace = small;
    }
    
    bool addCar(int carType) {
        if (carType == 3) 
        {
            smallSpace--;
            return smallSpace >= 0;
        }
        if (carType == 2) 
        {
            mediumSpace--;
            return mediumSpace >= 0;
        }
        bigSpace--;
        return bigSpace >= 0;
    }
};
