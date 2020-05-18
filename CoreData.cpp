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
int rowsCounter = 0;
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
  struct data towns[78];

int main()
{
    getData();
    towns[0].id.replace(0, 1, "");//to delete  \n
    displayMenu();
   
    switch(choice)
    {
        case 1: displayDataFrame();
        break;

        case 2: displayTown();
        break;

        case 3: addTown();
        break;

        case 4: editTownObservation();
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
  //Main menu
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
    cout<<"------------------------------------------"<<endl<<endl;
}

void displayDataFrame()
{
  cout<<"|--------------------------------------------------------";
  cout<<"------------------------------------------------|"<<endl;
  cout<< "|      ID      |     TOWN     |    REGION    |  MOLECULAR  |";
  cout<< "   SEROLOGIC   |  POPULATION  |  LAST UPDATE |"<<endl;
  cout<<"|------------------------------------------------";
  cout<<"--------------------------------------------------------|"<<endl;
  
  for(int x = 0; x<rowsCounter; x++)
  {
    towns[x].lastUpdate.erase(10, 18);//deliting spaces errors
    cout << "|" << setw(7)  << towns[x].id          <<  setw(8) << "|";
    cout        << setw(11) << towns[x].name        <<  setw(4) << "|"; 
    cout        << setw(11) << towns[x].region      <<  setw(4) << "|";
    cout        << setw(8)  << towns[x].molecular   <<  setw(6) << "|";
    cout        << setw(8)  << towns[x].serological <<  setw(8) << "|";
    cout        << setw(10) << towns[x].population  <<  setw(5) << "|";
    cout        << setw(12)  << towns[x].lastUpdate <<  setw(3) << "|" << endl;
    
    cout<<"|--------------------------------------------------------";
    cout<<"------------------------------------------------|"<<endl;
  }
}

void displayTown()
{
  string observationId;
  bool incorrectId = 1;

  cout<<"|-------------------------------------------------|"<<endl;
  cout<<"           Enter the observation ID: ";
  cin>>observationId;
  cout<<"|-------------------------------------------------|"<<endl;

  for(int i = 0; i<rowsCounter; i++)
  {
    if(towns[i].id == observationId)
    {
      cout << "  ID           :    " << towns[i].id          << endl;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  TOWN         :    " << towns[i].name        << endl;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  REGION       :    " << towns[i].region      << endl;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  MOLECULAR    :    " << towns[i].molecular   << endl;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  SEROLOGIC    :    " << towns[i].serological << endl;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  POPULATION   :    " << towns[i].population  << endl;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  LAST UPDATE  :    " << towns[i].lastUpdate  << endl;
      cout << "|-------------------------------------------------|"<<endl;
      incorrectId = 0;
    }
  }
  if(incorrectId)
    {
      cout << "    Did not find any observation with that id!" << endl;
      cout << "|-------------------------------------------------|" << endl;
    }
}

void addTown()
{
  string id;
  struct newData 
  {
    string newId;
    string newName;
    string newRegion;
    string newMolecular;
    string newSerological;
    string newPopulation;
    string newLastUpdate;
  } newTown;

   cout<<"               ADDING AN OBSERVATION"<<endl;
   cout << "|-------------------------------------------------|"<<endl;

   if(rowsCounter >= 78)
    {
      cout<<"              Your Data frame is full!"<<endl;
      cout << "|-------------------------------------------------|"<<endl;
    }
    else
    {
      cout << "  Enter observation id     :  " ;
      cin>>newTown.newId;
      id = newTown.newId;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter town               :  " ;
      cin.ignore();
      getline(cin, newTown.newName);
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter region             :  " ;
      cin>>newTown.newRegion;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter molecular cases    :  " ;
      cin>>newTown.newMolecular;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter serological cases  :  " ;
      cin>>newTown.newSerological;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter population         :  " ;
      cin>>newTown.newPopulation;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter last update        :  " ;
      cin>>newTown.newLastUpdate;
      cout << "|-------------------------------------------------|"<<endl;   
      
      for(int i =0; i<rowsCounter;  i++)
      {
        if(newTown.newName == towns[i].name)
        {
          cout<<"        The town " << newTown.newName << " already exists!"<<endl;
          cout << "|-------------------------------------------------|"<<endl; 
        }
        if(id == towns[i].id)
        {
          cout<<"           The id " << newTown.newId << " already exists!"<<endl;
          cout << "|-------------------------------------------------|"<<endl; 
        }
      }
    } 
}

void  editTownObservation()
{
  int townId;
  string observationId;
  bool incorrectId = 1;

  cout<<"          EDITING A TOWN INFORMATION"<<endl;
  cout<<"|-------------------------------------------------|"<<endl;
  cout<<"           Enter the observation ID: ";
  cin>>observationId;

  for(int i = 0; i<rowsCounter; i++)
  {
    if(towns[i].id == observationId)
    {
       cout<<"|-------------------------------------------------|"<<endl;
       cout<<"             CURRENT Information:"<<endl;
       cout<<"|-------------------------------------------------|"<<endl;
       cout << "  ID           :    " << towns[i].id          << endl;
       cout << "|-------------------------------------------------|"<<endl;
       cout << "  TOWN         :    " << towns[i].name        << endl;
       cout << "|-------------------------------------------------|"<<endl;
       cout << "  REGION       :    " << towns[i].region      << endl;
       cout << "|-------------------------------------------------|"<<endl;
       cout << "  MOLECULAR    :    " << towns[i].molecular   << endl;
       cout << "|-------------------------------------------------|"<<endl;
       cout << "  SEROLOGIC    :    " << towns[i].serological << endl;
       cout << "|-------------------------------------------------|"<<endl;
       cout << "  POPULATION   :    " << towns[i].population  << endl;
       cout << "|-------------------------------------------------|"<<endl;
       cout << "  LAST UPDATE  :    " << towns[i].lastUpdate  << endl;
       cout << "|-------------------------------------------------|"<<endl;
      incorrectId = 0;
      townId =  i;
    }
  }
  if(incorrectId)
    {
      cout << "|-------------------------------------------------|" << endl;
      cout << "    Did not find any observation with that id!" << endl;
      cout << "|-------------------------------------------------|" << endl;
    }
  else
  {
    cout << endl << "|-------------------------------------------------|" << endl;
    cout << "| Please enter the new information for the town:  |" <<endl;
    cout << "|-------------------------------------------------|" << endl << endl;
    cout << " MOLECULAR    :  ";
    cin>>towns[townId].molecular;
    cout << "---------------------------------------------------" << endl;
    cout << " SEROLOGIC    :  ";
    cin>>towns[townId].serological;
    cout << "---------------------------------------------------" << endl;
    cout << " POPULATION   :  ";
    cin>>towns[townId].population;
    cout << "---------------------------------------------------" << endl;
    cout << " LAST UPDATE  :  ";
    cin>>towns[townId].lastUpdate;
    cout << "|-------------------------------------------------|" << endl;
    cout << setw(18) << towns[townId].name << " was updated successfully!" << endl;
    cout << "|-------------------------------------------------|" << endl;
  }
}

void getData()
{
    ifstream covidData;
    covidData.open("PuertoRicoCovid19DF.csv");
    string var;
    bool finish = 0;
    covidData>>var; //Discarding the table header
      
     while(covidData)
        {
         getline(covidData ,  towns[rowsCounter].id          , ',');
         getline(covidData ,  towns[rowsCounter].name        , ',');
         getline(covidData ,  towns[rowsCounter].region      , ',');
         getline(covidData ,  towns[rowsCounter].molecular   , ',');
         getline(covidData ,  towns[rowsCounter].serological , ',');
         getline(covidData ,  towns[rowsCounter].population  , ',');
         getline(covidData ,  towns[rowsCounter].lastUpdate       ); 
         rowsCounter++;
        }
      
      if(!covidData)
      {
        covidData.close();
      }
    rowsCounter--;
}