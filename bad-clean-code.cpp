#include <iostream>
#include <string>
#include <vector>

class Car
{
private:
    // more than 2 variables, we can make a new class for it
    std::string brand;
    double dstnc_km; // don't use abbreviation
    double dstnc_m;  // don't use abbreviation
    double speed;
    std::vector<double> speed_numbers = {};

public:
    // Constructor
    Car()
    {
        speed = 0.0;
        speed_numbers.push_back(0.0);
    }

    void viewCurrentSpeed()
    {
        std::cout << "Current Speed: " << speed << " km/h" << std::endl;
    }

    // This method is not directly correlated to the class, we can make a new class for it
    double getDistanceCentimeter()
    {
        dstnc_m = speed * 1000;
        return dstnc_m;
    }

    // No setter/getter, give more contextually meaningful name such as Accelerate
    void setSpeed(double spd)
    {
        speed = spd;
        speed_numbers.push_back(speed);
    }

    void stop(double deceleration)
    {
        if (speed - deceleration <= 0)
        {
            speed = 0.0;
            speed_numbers.push_back(speed);
        }
        else
        { //  Dont use else, also too many indentation, we can use another function to simplify it.
            while (speed > 0)
            {
                if (speed - deceleration >= 0)
                {
                    speed -= deceleration;
                    speed_numbers.push_back(speed);
                    return;
                }

                speed = 0.0;
            }
        }
    }

    void viewSpeedHistory()
    {
        std::cout << "Speed History: " << std::endl;
        for (int i = 0; i < speed_numbers.size(); i++)
        {
            std::cout << speed_numbers[i] << " km/h" << std::endl;
        }
    }

    double findMaxSpeed()
    {
        double max_num = speed_numbers[0];

        for (int i = 0; i < speed_numbers.size(); i++)
        {
            if (speed_numbers[i] > max_num)
            {
                max_num = speed_numbers[i];
            }
        }

        return max_num;
    }
};

int main()
{
    double distance_in_kilometer = 56.7;
    double distance_in_meter = distance_in_kilometer * 1000;
    std::cout << "Distance in meter: " << distance_in_meter << std::endl;
}
