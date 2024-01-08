#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Distance
{
private:
    float _value;
    std::string _unitType;

public:
    // Constructor
    Distance(float value, const std::string &unitType)
        : _value(value), _unitType(unitType) {}

    float toMeter()
    {
        if (_unitType == "kilometer")
        {
            return _value * 1000.0;
        }
        else if (_unitType == "mile")
        {
            return _value * 1609.34;
        }
        else if (_unitType == "yard")
        {
            return _value * 0.9144;
        }
        else if (_unitType == "foot")
        {
            return _value * 0.3048;
        }
        else
        {
            // Assuming the default unit is meter
            return _value;
        }
    }
};

class Car
{
private:
    double current_speed;
    std::vector<double> speed_record = {};

public:
    // Constructor
    Car()
    {
        current_speed = 0.0;
        speed_record.push_back(0.0);
    }

    void viewCurrentSpeed()
    {
        std::cout << "Current Speed: " << current_speed << " km/h" << std::endl;
    }

    void accelerate(double acceleration)
    {
        current_speed += acceleration;
        speed_record.push_back(current_speed);
    }

    void decelerate(double deceleration)
    {
        if (current_speed - deceleration >= 0)
        {
            current_speed -= deceleration;
            speed_record.push_back(current_speed);
            return;
        }

        current_speed = 0.0;
    }

    void brake()
    {
        while (current_speed > 0)
        {
            std::cout << "Stopping car" << std::endl;
            decelerate(5.0);
            viewCurrentSpeed();
        }
    }

    void viewSpeedHistory()
    {
        std::cout << "Speed History: " << std::endl;
        for (int i = 0; i < speed_record.size(); i++)
        {
            std::cout << speed_record[i] << " km/h" << std::endl;
        }
    }

    double findMaxSpeed()
    {
        double max_num = *max_element(speed_record.begin(), speed_record.end());
        return max_num;
    }
};

int main()
{
    Car myCar;

    myCar.accelerate(30.0);
    myCar.viewCurrentSpeed();

    myCar.decelerate(20.0);
    myCar.viewCurrentSpeed();

    myCar.brake();
    myCar.viewSpeedHistory();
    std::cout << "Max Speed: " << myCar.findMaxSpeed() << " km/h" << std::endl;

    Distance distance(5.67, "kilometer");

    float meter = distance.toMeter();
    std::cout << "Meters: " << meter << std::endl;
}
