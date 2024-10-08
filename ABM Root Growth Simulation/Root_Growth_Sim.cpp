#include <iostream>

int main(){

    std::cout << "Agent-Based Modeling in C++!" << std::endl;
    return o;

}

// Step 2

class RootSegment{

public:
    float x, y; // Position
    float length // Length of the root
    float growthRate // Growth rate per time

    RootSegment(float xPos, float yPos, float initialLength, float rate) : x(xPos), y(yPos), length(initialLength), growthRate(rate){}

    // Function to simulate the growth

    void grow(){
        y += growthRate; // y direction growth
    }

    void displayPosition(){
        std::cout << "Position: (" << x << ", " << y << ")" << std::endl;
    }

};

int main(){
    RootSegment(0, 0, 1, 0.5); // Initial position (0,0)

    for (int i = 0; i < 10; i++){
        root.grow();
        root.displayPosition()
    }
    return 0;
}