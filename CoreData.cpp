
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
void findTownByRegion();
void findObservationByTown();
void saveObservation();
void createBarChart();
void showDashboard();
void exit();

//Variables
bool done =0;        //Control the loop

int rowsCounter = 0; //Keeps track of stored rows
int choice;          //Strore user selection from main menu
int maxTowns = 78;

struct data          //Stores the information of the file
  {
    string id;
    string name;
    string region;
    string molecular;
    string serological;
    string population;
    string lastUpdate;
    bool deleted = false;
  } towns[78]; 

int main()
{
   do
   {
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

        case 5: deleteTown();
        break;

        case 6: findTownByRegion();
        break;

        case 7: findObservationByTown();
        break;

        case 8: saveObservation();
        break;

        case 9: getData();
        break;

        case 10: //createBarChart();
        break;

        case 11: //showDashboard();
        break;

        case 12: exit();
        break;
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
  string observationId;
  bool exist = false;
  cout<<"|-------------------------------------------------|"<<endl;
  cout<<"           Enter the observation ID: ";
  cin>>observationId;
  cout<<"|-------------------------------------------------|"<<endl;

  for(int i = 0; i<rowsCounter; i++)
  {
    if(observationId  == towns[i].id && towns[i].deleted == true)
    {
      cout << "    Did not find any observation with that id!" << endl;
      cout << "|-------------------------------------------------|" << endl;
      exist = true;
      break;
    }

    if(observationId == towns[i].id)
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
   if(exist == false)
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

   if(rowsCounter >= maxTowns)
    {
      cout<<"              Your Data frame is full!"<<endl;
      cout << "|-------------------------------------------------|"<<endl;
      exist = 1;
    }
    else
    {
      cout << "  Enter observation id     :  " ;
      cin>>Id;
      id = Id;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter town               :  " ;
      cin.ignore();
      getline(cin, Name);
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter region             :  " ;
      cin>>Region;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter molecular cases    :  " ;
      cin>>Molecular;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter serological cases  :  " ;
      cin>>Serological;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter population         :  " ;
      cin>>Population;
      cout << "|-------------------------------------------------|"<<endl;
      cout << "  Enter last update        :  " ;
      cin>>LastUpdate;
      cout << "|-------------------------------------------------|"<<endl;   
      
      for(int i =0; i<rowsCounter;  i++)
      {
        if(Name == towns[i].name && towns[i].deleted == false) //verifying that the name does not exist
        {
          cout<<"        The town " << Name << " already exists!"<<endl;
          cout << "|-------------------------------------------------|"<<endl; 
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
    if(!exist)
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
  int indexId;
  string observationId;
  bool incorrectId = 1;
  string Molecular;
  string Serological;
  string Population;
  string LastUpdate;

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
      indexId =  i;
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
    cin>>towns[indexId].molecular;
    cout << "---------------------------------------------------" << endl;
    cout << " SEROLOGIC    :  ";
    cin>>towns[indexId].serological;
    cout << "---------------------------------------------------" << endl;
    cout << " POPULATION   :  ";
    cin>>towns[indexId].population;
    cout << "---------------------------------------------------" << endl;
    cout << " LAST UPDATE  :  ";
    cin>>towns[indexId].lastUpdate;
    cout << "|-------------------------------------------------|" << endl;
    cout << setw(18) << towns[indexId].name << " was updated successfully!" << endl;
    cout << "|-------------------------------------------------|" << endl;
  }
}

void deleteTown()
{
  string observationId;
  int pos;
  cout<<"   DELETING AN OBSERVATION"<<endl;
  cout<<"|-----------------------------------|"<<endl;
  cout<<"     Enter observation id: ";
  cin >> observationId;
  cout<<"|-----------------------------------|"<<endl;
    
  for(int i = 0; i < rowsCounter; i++)
  {

     if(observationId  == towns[i].id && towns[i].deleted == true)
    {
     cout << "Did not find town with that id!"<<endl;
     cout<<"|-----------------------------------|"<<endl;
     break;
    }
    if(observationId  == towns[i].id)
    {
      pos = i;
      towns[i].deleted = true;
      cout << towns[pos].name <<" was deleted successfull!"<<endl;
      cout<<"|-----------------------------------|"<<endl;
      maxTowns++;
    }
  }
}

void findTownByRegion()
{
  bool exist = false; 
  string region;

  cout<<"|--------------------------------------------------------";
   cout<<"------------------------------------------------|"<<endl;
   cout<<"|"<<setw(65)<<"FINDING OBSERVATIONS BY REGION"<<setw(40)<<"|"<<endl;
   cout<<"|--------------------------------------------------------";
   cout<<"------------------------------------------------|"<<endl;
   cout<<setw(56)<<"Enter REGION name: ";
   cin>>region;

   for(int i = 0; i<rowsCounter; i++)
   {
     if(region == towns[i].region && !towns[i].deleted)
     {
          exist = true;
     }
   }
  
  if(exist)
  {
   cout<<"|--------------------------------------------------------";
   cout<<"------------------------------------------------|"<<endl;
   cout<< "|      ID      |     TOWN     |    REGION    |  MOLECULAR  |";
   cout<< "   SEROLOGIC   |  POPULATION  |  LAST UPDATE |"<<endl;
   cout<<"|------------------------------------------------";
   cout<<"--------------------------------------------------------|"<<endl;
    
    for(int i =0; i<rowsCounter; i++)
    {
      if(!towns[i].deleted && region == towns[i].region)
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
    cout<<"|--------------------------------------------------------";
         cout<<"------------------------------------------------|"<<endl;
    cout<<"|"<<setw(75)<<"Did not find any Observation with that region!"<<setw(30)<<"|"<<endl;
    cout<<"|--------------------------------------------------------";
         cout<<"------------------------------------------------|"<<endl;
  }
}

void findObservationByTown()
{
   bool exist = false;  
  string name;

  cout<<"|--------------------------------------------------------";
   cout<<"------------------------------------------------|"<<endl;
   cout<<"|"<<setw(65)<<"FINDING OBSERVATIONS BY TOWN NAME"<<setw(40)<<"|"<<endl;
   cout<<"|--------------------------------------------------------";
   cout<<"------------------------------------------------|"<<endl;
   cout<<setw(56)<<"Enter REGION name: ";
   cin.ignore();
   getline(cin, name);

   for(int i = 0; i<rowsCounter; i++)
   {
     if(name == towns[i].name && !towns[i].deleted)
     {
          exist = true;
     }
   }
  
  if(exist)
  {
   cout<<"|--------------------------------------------------------";
   cout<<"------------------------------------------------|"<<endl;
   cout<< "|      ID      |     TOWN     |    REGION    |  MOLECULAR  |";
   cout<< "   SEROLOGIC   |  POPULATION  |  LAST UPDATE |"<<endl;
   cout<<"|------------------------------------------------";
   cout<<"--------------------------------------------------------|"<<endl;
    
    for(int i =0; i<rowsCounter; i++)
    {
      if(!towns[i].deleted && name == towns[i].name)
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
    cout<<"|--------------------------------------------------------";
         cout<<"------------------------------------------------|"<<endl;
    cout<<"|"<<setw(75)<<"Did not find any Observation with that name!"<<setw(30)<<"|"<<endl;
    cout<<"|--------------------------------------------------------";
         cout<<"------------------------------------------------|"<<endl;
  }
}

void saveObservation()
{
  ofstream covidData;
  covidData.open("PuertoRicoCovid19DF.csv");

  for(int i=0; i<rowsCounter; i++)
  {
    if(towns[i].deleted)
    {
      towns[i].id = "";
      towns[i].name = "";
      towns[i].region = "";
      towns[i].molecular = "";
      towns[i].serological = "";
      towns[i].population = "";
      towns[i].lastUpdate = "";
    }
    else
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
  covidData.close();
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
         if(!covidData)
           {
              covidData.close();
           }
           else
           {
             rowsCounter++;
           }
      }
   
   towns[0].id.replace(0, 1, "");//to delete  \n, please ignore.
   
   for(int x=0 ; x<=5; x++)//deliting spaces errors, please ignore.
    {
      towns[x].lastUpdate.erase(10, 18); 
    }
}

void exit()
{
  done = 1;

}
