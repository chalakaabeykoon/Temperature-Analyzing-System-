#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int DAYS_IN_MONTH = 30;
int day = 1;

void readTemperaturesFromFile(float dayTemps[], float nightTemps[]);
void calculateFluctuations(float dayTemps[], float nightTemps[], float fluctuations[]);
void calculateAverages(float dayTemps[], float nightTemps[], float &avgDayTemp, float &avgNightTemp);
void findMaxMin(float temps[], float &maxTemp, float &minTemp);
float convertToFahrenheit(float celsius);
void analyzeSuitability(float avgDayTemp, float avgNightTemp);
void Temperaturedatasavedtofile(float dayTemps[], float nightTemps[], float fluctuations[], float avgDayTemp, float avgNightTemp, float maxDayTemp, float minDayTemp, float maxNightTemp, float minNightTemp);

int main() {
    float dayTemps[DAYS_IN_MONTH], nightTemps[DAYS_IN_MONTH];
    float fluctuations[DAYS_IN_MONTH];
    float avgDayTemp, avgNightTemp;
    float maxDayTemp, minDayTemp, maxNightTemp, minNightTemp;
    int choice;

    do {
        cout << "\n--------------------------------------------- \n";
        cout << "\n Orchid-Flora Temperature Analyzing System \n";
        cout << "\n--------------------------------------------- \n";
        cout << "\n";
        cout << "1. Read Temperatures from File\n";
        cout << "2. Calculate Fluctuations\n";
        cout << "3. Calculate Averages\n";
        cout << "4. Find Max/Min Temperatures\n";
        cout << "5. Convert Celsius to Fahrenheit\n";
        cout << "6. Analyze Suitability\n";
        cout << "7. Temperature Data Saved To File\n";
        cout << "8. Exit\n";
        cout << "\n----------------------------------------------\n";
        cout << "\n";
        cout << "Enter your choice : ";
        cin >> choice;
        cout << "\n";

        switch (choice) {
            case 1:
                readTemperaturesFromFile(dayTemps, nightTemps);
                break;
            case 2:
                calculateFluctuations(dayTemps, nightTemps, fluctuations);
                break;
            case 3:
                calculateAverages(dayTemps, nightTemps, avgDayTemp, avgNightTemp);
                cout << "Average Daytime Temperature   : " << avgDayTemp << " F\n";
                cout << "Average Nighttime Temperature : " << avgNightTemp << " F\n";
                break;
            case 4:
                findMaxMin(dayTemps, maxDayTemp, minDayTemp);
                findMaxMin(nightTemps, maxNightTemp, minNightTemp);
                cout << "Max Day Temperature   : " << maxDayTemp << " F\n";
                cout << "Min Day Temperature   : " << minDayTemp << " F\n";
                cout << "\n";
                cout << "Max Night Temperature : " << maxNightTemp << " F\n";
                cout << "Min Night Temperature : " << minNightTemp << " F\n";
                break;
            case 5: {
                float celsius;
                cout << "Enter Temperature In Celsius : ";
                cin >> celsius;
                cout << "Temperature In Fahrenheit    : " << convertToFahrenheit(celsius) << " F\n";
                break;
            }
            case 6:
                analyzeSuitability(avgDayTemp, avgNightTemp);
                break;
            case 7:
                Temperaturedatasavedtofile(dayTemps, nightTemps, fluctuations, avgDayTemp, avgNightTemp, maxDayTemp, minDayTemp, maxNightTemp, minNightTemp);
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 8);

    return 0;
}

void readTemperaturesFromFile(float dayTemps[], float nightTemps[]) {
    ifstream inFile("Input Temperature.txt");
    if (!inFile) {
        cout << "Error opening file for reading temperatures!\n";
        return;
    }
    for (int i = 0; i < DAYS_IN_MONTH; i++) {
    if(inFile >> dayTemps[i] >> nightTemps[i]);

    std::cout << "\n";
    std::cout << " Day "<<day<< "\n ";
    std::cout << "Daytime Temperature   : " << dayTemps[i]<< "F\n";
    std::cout << " Nighttime Temperature : " << nightTemps[i] << "F\n";

    day++;
    }
    inFile.close();
}

void calculateFluctuations(float dayTemps[], float nightTemps[], float fluctuations[]) {
    for (int i = 0; i < DAYS_IN_MONTH; i++) {
        fluctuations[i] = dayTemps[i] - nightTemps[i];
        cout << "Day " << i + 1 << "  Fluctuation : " << fluctuations[i] << " F\n";
    }
}

void calculateAverages(float dayTemps[], float nightTemps[], float &avgDayTemp, float &avgNightTemp) {
    float totalDayTemp = 0, totalNightTemp = 0;
    for (int i = 0; i < DAYS_IN_MONTH; i++) {
        totalDayTemp += dayTemps[i];
        totalNightTemp += nightTemps[i];
    }
    avgDayTemp = totalDayTemp / DAYS_IN_MONTH;
    avgNightTemp = totalNightTemp / DAYS_IN_MONTH;
}

void findMaxMin(float temps[], float &maxTemp, float &minTemp) {
    maxTemp = temps[0];
    minTemp = temps[0];
    for (int i = 0; i < DAYS_IN_MONTH; i++) {
        if (temps[i] > maxTemp) maxTemp = temps[i];
        if (temps[i] < minTemp) minTemp = temps[i];
    }
}

float convertToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

void analyzeSuitability(float avgDayTemp, float avgNightTemp) {
    if (avgNightTemp >= 60 && avgNightTemp <= 62 && avgDayTemp >= 70 && avgDayTemp <= 80) {
        cout << "Temperature conditions are suitable for orchid blooming.\n";
    } else {
        cout << "Temperature conditions are not suitable for orchid blooming.\n";
    }
}

void Temperaturedatasavedtofile(float dayTemps[], float nightTemps[], float fluctuations[], float avgDayTemp, float avgNightTemp, float maxDayTemp, float minDayTemp, float maxNightTemp, float minNightTemp) {
    ofstream outFile("Save Temperature Data.txt");
    if (!outFile) {
        cout << "Error opening file for saving analysis!\n";
        return;}

    for(int day = 1; day <= DAYS_IN_MONTH; day++){
        outFile << "\nDay " << day << "\n";
        outFile << "Daytime Temperatures   : " << dayTemps[day - 1] << " F\n";
        outFile << "Nighttime Temperatures : " << nightTemps[day - 1] << " F\n";
        outFile << "Temperature Fluctuations : " << fluctuations[day - 1] << " F\n";
    }
    {
    outFile << "\nAverage Daytime Temperature    : " << avgDayTemp << " F";
    outFile << "\nAverage Nighttime Temperature : " << avgNightTemp << " F\n";
    outFile << "\nMax Day Temperature          : " << maxDayTemp << " F";
    outFile << "\nMin Day Temperature           : " << minDayTemp << " F\n";
    outFile << "\nMax Night Temperature        : " << maxNightTemp << " F\n";
    outFile << "Min Night Temperature         : " << minNightTemp << " F\n";

    if (avgNightTemp >= 60 && avgNightTemp <= 62 && avgDayTemp >= 70 && avgDayTemp <= 80) {
        outFile << "\n\nTemperature conditions are suitable for orchid blooming.\n";
    } else {
        outFile << "\n\nTemperature conditions are not suitable for orchid blooming.\n";
    }

    day++;
    }
    outFile.close();
    cout << "Temperature Data Saved to Text Document.\n";
}
