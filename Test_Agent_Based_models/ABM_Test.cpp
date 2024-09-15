#include <iostream>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <fstream>  // For file operations

class Agent {
private:
    int x, y;

public:
    // Constructor to initialize the agent's position
    Agent(int maxX, int maxY) {
        x = rand() % maxX;
        y = rand() % maxY;
    }

    // Method to move the agent randomly
    void move(int maxX, int maxY) {
        int direction = rand() % 4;
        switch (direction) {
            case 0: if (x > 0) x--; break;  // Move left
            case 1: if (x < maxX - 1) x++; break;  // Move right
            case 2: if (y > 0) y--; break;  // Move up
            case 3: if (y < maxY - 1) y++; break;  // Move down
        }
    }

    // Method to display the agent's current position
    void showPosition() const {
        std::cout << "(" << x << ", " << y << ")";
    }

    // Getters for x and y
    int getX() const { return x; }
    int getY() const { return y; }
};

int main() {
    srand(static_cast<unsigned>(time(0)));  // Seed for random number generator

    const int numAgents = 5;
    const int maxX = 10, maxY = 10;
    const int steps = 10;

    // Create a vector of agents
    std::vector<Agent> agents;
    for (int i = 0; i < numAgents; ++i) {
        agents.push_back(Agent(maxX, maxY));
    }

    // Open a file to store the positions
    std::ofstream file("agent_positions.csv");
    file << "Step,Agent,X,Y\n";  // Header for CSV file

    // Movement simulation
    for (int step = 0; step < steps; ++step) {
        std::cout << "Step " << step + 1 << ":\n";
        for (int i = 0; i < numAgents; ++i) {
            agents[i].move(maxX, maxY);
            std::cout << "Agent " << i + 1 << ": ";
            agents[i].showPosition();
            std::cout << std::endl;
            // Save the position to the file
            file << step + 1 << "," << i + 1 << "," << agents[i].getX() << "," << agents[i].getY() << "\n";
        }
        std::cout << std::endl;
    }

    file.close();  // Close the file
    return 0;
}



