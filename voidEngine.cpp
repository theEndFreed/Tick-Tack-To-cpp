
#include <iostream>
#include <vector>
#include <cmath>
#include <string>


struct PushResults {
    float distance;
    float acceleration;
};

PushResults CalculateDistanceOnPushFromObject(float PushingObjectMass,float PushObjectMass, float PushingObjectSpeed, float PushDuration) {
    PushResults res;
    // calculating impulse
    float p = PushingObjectMass * PushingObjectSpeed;
    // calculating velocity imparted to the pushed object
    float v = (PushingObjectMass / (PushingObjectMass + PushObjectMass)) * PushingObjectSpeed;
    std::cout << "Imparted Velocity: " << v << " m/s" << std::endl;
    //calculating acceleration during the push
    res.acceleration = v / PushDuration;
    //calculating distance traveled during the push duration
    res.distance = 0.5f * v * PushDuration;
   
    return res;
}


int main() {
    float pushingMass = 0.0f;
    float pushedMass  = 0.0f;
    float speed       = 0.0f;
    float duration    = 0.0f;

    std::cout << "Enter Mass of the Pushingobject, Mass of the Pushedobject, Speed of the PushingObject and Duration of the push: " << std::endl;
    //get values from user
    std::cin >>pushingMass >> pushedMass >> speed >> duration;
    
    //calculate distance and acceleration
    PushResults results = CalculateDistanceOnPushFromObject(pushingMass, pushedMass, speed, duration);

    //print results
    std::cout << "The object will travel a distance of: " << results.distance << " m." 
              << " with an acceleration of: " << results.acceleration << " m/s^2." 
              << std::endl;
    return 0;
}

