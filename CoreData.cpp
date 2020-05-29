#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
using namespace std;

//Funtion prototypes
void getData();
void displayMenu();
void displayDataFrame();
void displayTown();
void addTown();
void editTownObservation();
void deleteTown();
void findTownByRegion();
void findObservationByTown();
void saveObservation();
void createBarChart();
void showDashboard();
void exit();
void Converse();

//Variables
bool done =0;        //Control the loop
string var;          //To save the table header
int rowsCounter = 0; //Keeps track of stored rows
int choice;          //Strore user selection from main menu
int maxTowns = 78;    //to set the size of the array 
struct data          //Stores the information of the file
  {
    string id = "";
    string name = "";
    string region = "";
    int Molecular = 0;
    string molecular = "";
    int Serological = 0;
    string serological = "";
    string population = "";
    string lastUpdate = "";
    bool deleted = false;
  } ; 

 struct data *towns = new struct data[maxTowns]; //to manipulate the size of the array

int main()
{
   do
   {
    displayMenu();
    
    
    switch(choice)
      {
        case 1:
                displayDataFrame();
                cout<<"<Press ENTER to continue>"<<endl;
                cin.get();
                cin.ignore();
                system("clear");
        break;

        case 2: displayTown();
                cout<<"<Press ENTER to continue>"<<endl;
                cin.get();
                cin.ignore();
                system("clear");
        break;

        case 3: addTown();
                cout<<"<Press ENTER to continue>"<<endl;
                cin.get();
                cin.ignore();
                system("clear");
        break;

        case 4: editTownObservation();
                cout<<"<Press ENTER to continue>"<<endl;
                cin.get();
                cin.ignore();
                system("clear");
        break;

        case 5: deleteTown();
                cout<<"<Press ENTER to continue>"<<endl;
                cin.get();
                cin.ignore();
                system("clear");
        break;

        case 6: findTownByRegion();
                cout<<"<Press ENTER to continue>"<<endl;
                cin.get();
                cin.ignore();
                system("clear");
        break;

        case 7: findObservationByTown();
                cout<<"<Press ENTER to continue>"<<endl;
                cin.get();
                cin.ignore();
                system("clear");
        break;

        case 8: saveObservation();
                cout<<"<Press ENTER to continue>"<<endl;
                cin.get();
                cin.ignore();
                system("clear");
        break;

        case 9: getData();
                cout<<"<Press ENTER to continue>"<<endl;
                cin.get();
                cin.ignore();
                system("clear");
        break;

        case 10: createBarChart();
                 cout<<"<Press ENTER to continue>"<<endl;
                 cin.get();
                 cin.ignore();
                 system("clear");
        break;

        case 11: showDashboard();
                 cout<<"<Press ENTER to continue>"<<endl;
                 cin.get();
                 cin.ignore();
                 system("clear");
        break;

        case 12: exit();
        break;

        default: cout<<"|----------------------------------------------|"<<endl;
                 cout<<"|      Invalid input, please try again.        |"<<endl;
                 cout<<"|----------------------------------------------|"<<endl;
                 cout<<"<Press ENTER to continue>"<<endl;
                 cin.get();
                 cin.ignore();
                 system("clear");
      }
   }while(!done);
}

void displayMenu()
{
  //Main menu
    cout<< endl;
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
      
  for(int i = 0; i<rowsCounter; i++)
  {
    if(!towns[i].deleted)//verifying that the town is not erased
    {

         cout << "|" << setw(7)  << towns[i].id          <<  setw(8) << "|";
         cout        << setw(11) << towns[i].name        <<  setw(4) << "|"; 
         cout        << setw(11) << towns[i].region      <<  setw(4) << "|";
         cout        << setw(8)  << towns[i].molecular   <<  setw(6) << "|";
         cout        << setw(8)  << towns[i].serological <<  setw(8) << "|";
         cout        << setw(10) << towns[i].population  <<  setw(5) << "|";
         cout        << setw(12) << towns[i].lastUpdate  <<  setw(3) << "|" << endl;
    
         cout<<"|--------------------------------------------------------";
         cout<<"------------------------------------------------|"<<endl;
    }
  
  }
}

void displayTown()
{
  string observationId; //User input
  bool exist = false; 
  cout<<"|-------------------------------------------------|"<<endl;
  cout<<"           Enter the observation ID: ";
  cin>>observationId;
  cout<<"|-------------------------------------------------|"<<endl;

  for(int i = 0; i<rowsCounter; i++)
  {
    if(observationId == towns[i].id && towns[i].deleted == true) //if exist but is deleted
    {
      cout << "    Did not find any observation with that id!" << endl;
      cout << "|-------------------------------------------------|" << endl;
      exist = true;
      break;
    }

    if(observationId == towns[i].id) //if exist
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
      exist = true;
    }
    
  }
   if(exist == false) //if not exist
    {
      cout << "    Did not find any observation with that id!" << endl;
      cout << "|-------------------------------------------------|" << endl;
    }
}

void addTown()
{
  bool exist = 0;
  string id;

    string Id;
    string Name;
    string Region;
    string Molecular;
    string Serological;
    string Population;
    string LastUpdate;
   
   cout<<"               ADDING AN OBSERVATION"<<endl;
   cout << "|-------------------------------------------------|"<<endl;

   if(rowsCounter >= maxTowns) //if it's full.
    {
      cout<<"              Your Data frame is full!"<<endl;
      cout << "|-------------------------------------------------|"<<endl;
      exist = 1;
    }
    else //if it's not full
    {
      cout << "  Enter observation id     :  " ;
      cin>>Id;
      id = Id;
      cout << "|-------------------------------------------------|" << endl;
      cout << "  Enter town               :  " ;
      cin.ignore();
      getline(cin, Name);
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter region             :  " ;
      cin >> Region;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter molecular cases    :  " ;
      cin >> Molecular;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter serological cases  :  " ;
      cin >> Serological;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter population         :  " ;
      cin >> Population;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter last update        :  " ;
      cin >> LastUpdate;
      cout << "|-------------------------------------------------|" << endl;   
      
      for(int i =0; i<rowsCounter;  i++)
      {
        if(Name == towns[i].name && towns[i].deleted == false) //verifying that the name does not exist
        {
          cout << "        The town " << Name << " already exists!" << endl;
          cout << "|-------------------------------------------------|" << endl; 
          exist = 1;
        }
        if(id == towns[i].id  && towns[i].deleted == false) //verifying that the id does not exist
        {
          cout<<"           The id " << Id << " already exists!"<<endl;
          cout << "|-------------------------------------------------|"<<endl; 
          exist = 1;
        }
      }
    } 
    if(!exist)//storing the town in the structure
    {
      towns[rowsCounter].id          = id;
      towns[rowsCounter].name        = Name;    
      towns[rowsCounter].region      = Region;
      towns[rowsCounter].molecular   = Molecular;
      towns[rowsCounter].serological = Serological;
      towns[rowsCounter].population  = Population;
      towns[rowsCounter].lastUpdate  = LastUpdate;
      towns[rowsCounter].deleted     = false;
      cout << "    " << towns[rowsCounter].name << " was added succesfully!"<<endl;
      cout << "|-------------------------------------------------|"<<endl;
      rowsCounter++;
    }
}

void  editTownObservation()
{
  int index;            // array position
  string observationId; //User input
  bool incorrectId = 1; //flag
  string Molecular;     //new data
  string Serological;   //new data
  string Population;    //new data
  string LastUpdate;    //new data

  cout<<"          EDITING A TOWN INFORMATION"<<endl;
  cout<<"|-------------------------------------------------|"<<endl;
  cout<<"           Enter the observation ID: ";
  cin>>observationId;

  for(int i = 0; i<rowsCounter; i++)
  {
    if(towns[i].id == observationId) //if exist
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
      index =  i;
    }
  }
  if(incorrectId) //if not exist
    {
      cout << "|-------------------------------------------------|" << endl;
      cout << "    Did not find any observation with that id!" << endl;
      cout << "|-------------------------------------------------|" << endl;
    }
  else //if exist
  {
    cout << endl << "|-------------------------------------------------|" << endl;
    cout << "| Please enter the new information for the town:  |" <<endl;
    cout << "|-------------------------------------------------|" << endl << endl;
    cout << " MOLECULAR    :  ";
    cin>>towns[index].molecular;
    cout << "---------------------------------------------------" << endl;
    cout << " SEROLOGIC    :  ";
    cin>>towns[index].serological;
    cout << "---------------------------------------------------" << endl;
    cout << " POPULATION   :  ";
    cin>>towns[index].population;
    cout << "---------------------------------------------------" << endl;
    cout << " LAST UPDATE  :  ";
    cin>>towns[index].lastUpdate;
    cout << "|-------------------------------------------------|" << endl;
    cout << setw(18) << towns[index].name << " was updated successfully!" << endl;
    cout << "|-------------------------------------------------|" << endl;
  }
}

void deleteTown()
{
  string observationId; //User input
  int pos; //array position
  cout<<"   DELETING AN OBSERVATION"<<endl;
  cout<<"|-----------------------------------|"<<endl;
  cout<<"     Enter observation id: ";
  cin >> observationId;
  cout<<"|-----------------------------------|"<<endl;
    
  for(int i = 0; i < rowsCounter; i++)
  {

     if(observationId  == towns[i].id && towns[i].deleted == true) //if exist and is deleted 
    {
     cout << "Did not find town with that id!"<<endl;
     cout<<"|-----------------------------------|"<<endl;
     break;
    }
    if(observationId  == towns[i].id) //if exist and is not deleted
    {
      pos = i;
      towns[i].deleted = true;
      cout << towns[pos].name <<" was deleted successfull!"<<endl;
      cout<<"|-----------------------------------|"<<endl;
      maxTowns++; //increasing the space in the array by 1
    }
  }
}

void findTownByRegion()
{
  bool exist = false; 
  string region; //user input

  cout<<"|--------------------------------------------------------";
   cout<<"------------------------------------------------|"<<endl;
   cout<<"|"<<setw(65)<<"FINDING OBSERVATIONS BY REGION"<<setw(40)<<"|"<<endl;
   cout<<"|--------------------------------------------------------";
   cout<<"------------------------------------------------|"<<endl;
   cout<<setw(56)<<"Enter REGION name: ";
   cin>>region;

   for(int i = 0; i<rowsCounter; i++)
   {
     if(region == towns[i].region && !towns[i].deleted) //if exist and is not deleted
     {
          exist = true;
     }
   }
  
  if(exist) //if exist and is not deleted
  {
   cout<<"|--------------------------------------------------------";
   cout<<"------------------------------------------------|"<<endl;
   cout<< "|      ID      |     TOWN     |    REGION    |  MOLECULAR  |";
   cout<< "   SEROLOGIC   |  POPULATION  |  LAST UPDATE |"<<endl;
   cout<<"|------------------------------------------------";
   cout<<"--------------------------------------------------------|"<<endl;
    
    for(int i =0; i<rowsCounter; i++)
    {
      if(!towns[i].deleted && region == towns[i].region) //if exist and is not deleted
     {
         cout << "|" << setw(7)  << towns[i].id          <<  setw(8) << "|";
         cout        << setw(11) << towns[i].name        <<  setw(4) << "|"; 
         cout        << setw(11) << towns[i].region      <<  setw(4) << "|";
         cout        << setw(8)  << towns[i].molecular   <<  setw(6) << "|";
         cout        << setw(8)  << towns[i].serological <<  setw(8) << "|";
         cout        << setw(10) << towns[i].population  <<  setw(5) << "|";
         cout        << setw(12) << towns[i].lastUpdate  <<  setw(3) << "|" << endl;
         cout<<"|--------------------------------------------------------";
         cout<<"------------------------------------------------|"<<endl;
     }
    }
  }
  else // if not exist or is deleted
  {
    cout << "|--------------------------------------------------------";
    cout <<         "------------------------------------------------|"<<endl;
    cout << "|" << setw(75) << "Did not find any Observation with that region!" << setw(30) << "|" << endl;
    cout << "|--------------------------------------------------------";
    cout <<         "------------------------------------------------|"<<endl;
  }
}

void findObservationByTown()
{
   bool exist = false;  
    string name; // User input

  cout<<"|--------------------------------------------------------";
   cout<<"------------------------------------------------|"<<endl;
   cout<<"|"<<setw(65)<<"FINDING OBSERVATIONS BY TOWN NAME"<<setw(40)<<"|"<<endl;
   cout<<"|--------------------------------------------------------";
   cout<<"------------------------------------------------|"<<endl;
   cout<<setw(56)<<"Enter REGION name: ";
   cin.ignore(); //to ignore anything in the buffer
   getline(cin, name);

   for(int i = 0; i<rowsCounter; i++)
   {
     if(name == towns[i].name && !towns[i].deleted) //if exist and is not deleted
     {
          exist = true;
     }
   }
  
  if(exist) //if exist and is not deleted
  {
   cout<<"|--------------------------------------------------------";
   cout<<"------------------------------------------------|"<<endl;
   cout<< "|      ID      |     TOWN     |    REGION    |  MOLECULAR  |";
   cout<< "   SEROLOGIC   |  POPULATION  |  LAST UPDATE |"<<endl;
   cout<<"|------------------------------------------------";
   cout<<"--------------------------------------------------------|"<<endl;
    
    for(int i =0; i<rowsCounter; i++)
    {
      if(!towns[i].deleted && name == towns[i].name) //if exist and is not deleted
     {
         cout << "|" << setw(7)  << towns[i].id          <<  setw(8) << "|";
         cout        << setw(11) << towns[i].name        <<  setw(4) << "|"; 
         cout        << setw(11) << towns[i].region      <<  setw(4) << "|";
         cout        << setw(8)  << towns[i].molecular   <<  setw(6) << "|";
         cout        << setw(8)  << towns[i].serological <<  setw(8) << "|";
         cout        << setw(10) << towns[i].population  <<  setw(5) << "|";
         cout        << setw(12) << towns[i].lastUpdate  <<  setw(3) << "|" << endl;
         cout<<"|--------------------------------------------------------";
         cout<<"------------------------------------------------|"<<endl;
     }
    }
  }
  else
  {
    cout << "|--------------------------------------------------------";
    cout <<         "------------------------------------------------|"<<endl;
    cout << "|" << setw(75) << "Did not find any Observation with that name!" << setw(30 ) << "|"<<endl;
    cout << "|--------------------------------------------------------";
    cout <<         "------------------------------------------------|"<<endl;
  }
}

void saveObservation()
{
  
  bool saved = false;
  cout<<"|--------------------------------------------|"<<endl;
  cout<<"|            SAVING TO FILE...               |"<<endl;
  cout<<"|--------------------------------------------|"<<endl;
  if(rowsCounter>0) //if exist data 
  {
      ofstream covidData;
      covidData.open("PuertoRicoCovid19DF.csv");
      covidData<<var<<endl;

      for(int i=0; i<rowsCounter; i++)
      {
        if(towns[i].deleted) //to remove the data from the deleted towns
        {
          towns[i].id = "";
          towns[i].name = "";
          towns[i].region = "";
          towns[i].molecular = "";
          towns[i].serological = "";
          towns[i].population = "";
          towns[i].lastUpdate = "";
        }
        else //to write all the data in the file
        {
          covidData<<towns[i].id<<",";
          covidData<<towns[i].name<<",";
          covidData<<towns[i].region<<",";
          covidData<<towns[i].molecular<<",";
          covidData<<towns[i].serological<<",";
          covidData<<towns[i].population<<",";
          covidData<<towns[i].lastUpdate<<endl;
        }
      }
  cout<<"| Your observations were successfully saved! |"<<endl;
  cout<<"|--------------------------------------------|"<<endl;
  covidData.close();
  }
  else //if not exist data
  {
    cout<< "|         Could not save to file!            |"<<endl;
    cout<<"|--------------------------------------------|"<<endl;
  }
}

void getData()
{
    ifstream covidData;
    covidData.open("PuertoRicoCovid19DF.csv");
    bool finish = 0;
    covidData>>var; //Discarding the table header

      if(covidData) //if there's unread information 
      {
        cout<<"|---------------------------------------------|"<<endl;
        cout<<"|             LOADING FROM FILE...            |"<<endl;
        cout<<"|---------------------------------------------|"<<endl;
        cout<<"| Your observations were successfully loaded! |"<<endl;
        cout<<"|---------------------------------------------|"<<endl;
         
         while(covidData) //while exiting unread information, save the data on the struct.
          {
             getline(covidData ,  towns[rowsCounter].id          , ',');
             getline(covidData ,  towns[rowsCounter].name        , ',');
             getline(covidData ,  towns[rowsCounter].region      , ',');
             getline(covidData ,  towns[rowsCounter].molecular   , ',');
             getline(covidData ,  towns[rowsCounter].serological , ',');
             getline(covidData ,  towns[rowsCounter].population  , ',');
             getline(covidData ,  towns[rowsCounter].lastUpdate       );

             if(!covidData) //if there's no more to read
               {
                  covidData.close();
               }
             else
               {
                rowsCounter++; // to count the towns
               }
          }
        towns[0].id.replace(0, 2, "");//to delete  \n, please ignore.
        towns[5].name.replace(0, 1, "");//to delete a space, please ignore.
        for(int x=0 ; x<=5; x++)//deliting spaces errors, please ignore.
          {
              towns[x].lastUpdate.erase(10, 18); 
          }
      }
      else  //if there's nothing left to read
      {
        cout<<"|---------------------------------------------|"<<endl;
        cout<<"|             LOADING FROM FILE...            |"<<endl;
        cout<<"|---------------------------------------------|"<<endl;
        cout<<"|             Could not load file!            |"<<endl;
        cout<<"|---------------------------------------------|"<<endl;
      }
}

void createBarChart()
{
  int total[maxTowns]; // to save the total cases for each town
  int longBar;   // to stipulate the length of the bar
  int globalTotal; //to get the total cases in Puerto Rico 
  char bar = '*';// bar simbol
  int townsLength; //to know the length of a string
  cout<<"|-------------------------------------------------------------------------------|"<<endl;
  cout<<"|                              BAR CHART OPTION                                 |"<<endl;
  cout<<"|-------------------------------------------------------------------------------|"<<endl;

  if(rowsCounter>0) //if exist data
  {
    cout<<"|                            TOTAL CASES FOR TOWN                               |"<<endl;
    cout<<"|-------------------------------------------------------------------------------|"<<endl;
    cout<<"                                                                                 "<<endl;
    cout<<"   Town         |                                                     |Total     "<<endl;
    for(int i =0; i<rowsCounter; i++)
    {
      townsLength = towns[i].name.length(); //to know the length of a town name
      Converse(); // to convert the string to integers
      
      total[i]= towns[i].Molecular + towns[i].Serological;
      globalTotal = globalTotal + total[i];
      longBar = total[i]/10;
      
      cout<<"  "<<towns[i].name<<setw(15 - townsLength)<<"|"<<setw(2);
      for(int x =0; x<=longBar; x++)
      {
        cout<<bar;
      }
      cout<<setw(52 - longBar)<<"|"<<total[i]<<endl;
    }
     cout<<"                                                                                 "<<endl;
     cout<<"|-------------------------------------------------------------------------------|"<<endl;
     cout<<"   Total        |                                                     |"<<globalTotal<<endl;
  }
  else //if not exist data
  {
     cout<<"|                                                                               |"<<endl;
     cout<<"|                           The data frame is empty!                            |"<<endl;
     cout<<"|                                                                               |"<<endl;
     cout<<"|-------------------------------------------------------------------------------|"<<endl;
  }
}

void showDashboard()
{
  int totalCases =0;
  int totalMolecular =0;
  int totalSerological =0;
  int mean;
  int mode;
  int median;
  
  Converse(); // to convert the string to integers
  for(int i =0; i<rowsCounter; i++)
  {
    totalCases = totalCases + towns[i].Molecular;
    totalCases = totalCases + towns[i].Serological;

    totalMolecular = totalMolecular + towns[i].Molecular;

    totalSerological = totalSerological + towns[i].Serological;
  }
  
  cout<<"|-------------------------------------------------------|"<<endl;
  cout<<"|          PUERTO RICO COVID DASHBOARD                  |"<<endl;
  cout<<"|-------------------------------------------------------|"<<endl;
  cout<<"|                                                       |"<<endl;
  cout<<"| Date        : "<<towns[0].lastUpdate << setw(31)  << "|"<<endl;
  cout<<"| Total Cases : "<<totalCases          << setw(38)  << "|"<<endl;
  cout<<"| Molecular   : "<<totalMolecular      << setw(38)  << "|"<<endl;
  cout<<"| Serological : "<<totalSerological    << setw(38)  << "|"<<endl;
  cout<<"|-------------------------------------------------------|"<<endl;

}

void Converse() // to convert the string to integers
{
  for(int i =0; i<rowsCounter; i++)
  {
    towns[i].Molecular = stoi(towns[i].molecular);
    towns[i].Serological = stoi(towns[i].serological);
  }
}

void exit()
{
  done = 1;

}
