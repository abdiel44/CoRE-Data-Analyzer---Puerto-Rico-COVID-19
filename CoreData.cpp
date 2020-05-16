#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Funtion prototypes
void getData();
void displayMenu();
void displayDataFrame();
void displayTown();
void addTown();
void editTownObservation();
void deleteTown();
void findTown();
void findObservation();
void saveObservation();
void loadObservation();
void createBarChart();
void showDashboard();
void exit();

//Variables
int choice;
struct data
  {
    string id;
    string name;
    string region;
    string molecular;
    string serological;
    string population;
    string lastUpdate;
  };

int main()
{
    getData();
    displayMenu();
   

    switch(choice)
    {
        case 1: displayDataFrame();
        break;

        case 2: //displayTown();
        break;

        case 3: //addTown();
        break;

        case 4: //editTownObservation();
        break;

        case 5: //deleteTown();
        break;

        case 6:  //findTown();
        break;

        case 7: //findObservation();
        break;

        case 8: //saveObservation();
        break;

        case 9: //loadObservation();
        break;

        case 10: //createBarChart();
        break;

        case 11: //showDashboard();
        break;

        case 12: //exit();
        break;
    }
}

void displayMenu()
{
    cout<<"------------------------------------------"<<endl;
    cout<<"|  CoRE COVID-19 Dashboard and Analyzer  |"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"|1." << setw(20) << "Display Data Frame" << setw(19) << "|" << endl;
    cout<<"|----------------------------------------|"<<endl;
    cout<<"|2." << setw(16) << "Display a town" << setw(23) << "|" << endl;
    cout<<"|----------------------------------------|"<<endl;
    cout<<"|3." << setw(12) << "Add a town" << setw(27) << "|" << endl;
    cout<<"|----------------------------------------|"<<endl;
    cout<<"|4." << setw(25) << "Edit a town observation" << setw(14) << "|" << endl;
    cout<<"|----------------------------------------|"<<endl;
    cout<<"|5." << setw(15) << "Delete a town" << setw(24) << "|" << endl;
    cout<<"|----------------------------------------|"<<endl;
    cout<<"|6." << setw(22) << "Find towns by region" << setw(17) << "|" << endl;
    cout<<"|----------------------------------------|"<<endl;
    cout<<"|7." << setw(31) << "Find observation by town name" << setw(8) << "|" << endl;
    cout<<"|----------------------------------------|"<<endl;
    cout<<"|8." << setw(27) << "Save observations to file" << setw(12) << "|" << endl;
    cout<<"|----------------------------------------|"<<endl;
    cout<<"|9." << setw(29) << "Load observations from file" << setw(10) << "|" <<endl;
    cout<<"|----------------------------------------|"<<endl;
    cout<<"|10." << setw(17) << "Create Bar chart" << setw(21) << "|" <<endl;
    cout<<"|----------------------------------------|"<<endl;
    cout<<"|11." << setw(27) << "Show Puerto Rico Dashboard" << setw(11) << "|" <<endl;
    cout<<"|----------------------------------------|"<<endl;
    cout<<"|12." << setw(17) << "Exit application" << setw(21) << "|" <<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"     Enter option number: ";
    cin>>choice;
    cout<<"------------------------------------------"<<endl;
}

void getData()
{
    ifstream covidData;
    covidData.open("PuertoRicoCovid19DF.csv");
    struct data towns[78];
    string var;
    bool finish = 0;

      covidData>>var; //Discarding the table header

    while(!finish)
    {
      for(int x = 0; x<78; x++)
      {
         getline(covidData ,  towns[x].id          , ',');
         getline(covidData ,  towns[x].name        , ',');
         getline(covidData ,  towns[x].region      , ',');
         getline(covidData ,  towns[x].molecular   , ',');
         getline(covidData ,  towns[x].serological , ',');
         getline(covidData ,  towns[x].population  , ',');
         getline(covidData ,  towns[x].lastUpdate);
      }
      
      if(!covidData)
      {
        finish = 1;
        covidData.close();
      }
    }
}