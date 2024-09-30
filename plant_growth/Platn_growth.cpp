#include<iostream>
using namespace std;

// Function to calculate daily growth

double calculateGrowth(double sunlight, double water, double nutrients){
    return (sunlight * water * nutrients)/100;
}

int main(){
    double sunlight, water, nutrients;
    double growth = 0;

    // ask to the put the sunlight, water and nutrient values.
    cout << "Introduce the amount of daily sunlight (0-10): ";
    cin >> sunlight;

    cout << "Introduce the amount of daily water (0-10): ";
    cin >> water;

    cout << "Introduce the amount of daily nutrients (0-10): ";
    cin >> nutrients;

    // Simulate the growth during 10 days
    for (int day = 1; day <= 10; day++){
        // Obtian daily growht
        double dailyGrowth = calculateGrowth(sunlight, water, nutrients);
        // Add the total growth
        growth += dailyGrowth;
        // Show the daily growth and total growth
        cout << "Day " << day << " - Daily Growth: " << dailyGrowth << " - Total Growth: " << growth;
    }

    return 0;

}