#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

vector<int> x;
vector<int> y;

void extractIntegerWords(string str)
{
    stringstream ss;

    /* Storing the whole string into string stream */
    ss << str;

    /* Running loop till the end of the stream */
    string temp;
    int found;
    bool is = false;
    while (!ss.eof()) {

        /* extracting word by word from stream */
        ss >> temp;

        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found)
        {
            if(!is)
           {
               x.push_back(found);
               is=true;
           }
           else {
               y.push_back(found);
               is = false;
           }

        }


        /* To save from space at the end of string */
        temp = "";
    }
}
bool loadOutFile(string fileName, vector<int> x, vector<int> y)
{
    //
    ofstream file;

    file.open(fileName.c_str());
    if(!file.good())
        return false;

    file<<"dimension 2"<<endl;
    for(int i=0; i<x.size();i++)
    {
        file<<"("<<x[i]<<","<<y[i]<<")"<<endl;
    }

    file.close();
    return true;
}
bool loadFile(string fileName)
{
    //Ladowanie danych z pliku
    ifstream file;

    file.open(fileName.c_str());
    if(!file.good())
        return false;
    while(!file.eof())
    {
        string s;
        getline(file,s);
        if(s[0]!='d'&&s[0]!=';')
        {
            for(int i=0;i<s.length();i++)
            {
                if(s[i]==',' || s[i]=='('||s[i]==')')
                    s.replace(i,1," ");
            }
            extractIntegerWords(s);
        }

    }
    file.close();
    return true;
}

int main()
{
    string nameOfFile;
    cin>>nameOfFile;

    if(!loadFile(nameOfFile))
        cout<<"Blad z wczytywaniem pliku";
    vector<int> moreX, moreY;

    //Dodawanie nowych wspolrzednych
    for(int i=0;i<x.size();i++)
    {
        moreX.push_back(x[i]-1);
        moreY.push_back(y[i]-1);

        moreX.push_back(x[i]-1);
        moreY.push_back(y[i]);

        moreX.push_back(x[i]-1);
        moreY.push_back(y[i]+1);

        moreX.push_back(x[i]);
        moreY.push_back(y[i]-1);

        moreX.push_back(x[i]);
        moreY.push_back(y[i]);

        moreX.push_back(x[i]);
        moreY.push_back(y[i]+1);

        moreX.push_back(x[i]+1);
        moreY.push_back(y[i]-1);

        moreX.push_back(x[i]+1);
        moreY.push_back(y[i]);

        moreX.push_back(x[i]+1);
        moreY.push_back(y[i]+1);
    }

    //Usuwanie powtorzen
    for(int i=0;i<moreX.size();i++)
    {
        for(int j=i+1; j<moreX.size();j++)
        {
            if(moreX[i]==moreX[j]&&moreY[i]==moreY[j])
            {
                moreX.erase(moreX.begin()+j);
                moreY.erase(moreY.begin()+j);
            }
        }

    }
    if(!loadOutFile("filtered_"+nameOfFile,moreX,moreY))
        cout<<"Wystapil blad z plikiem out";

    return 0;
}
