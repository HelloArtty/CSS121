#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

struct Friend {
	float ne, ni, te, ti, se, si, fe, fi;
	string type, nickname, name, number; 
	float distance = 0;
};

int main()
{
    struct Friend datafriends[65];
    struct Friend me;
    
    string number, name, sex, ne, ni, te, ti, se, si, fe, fi, type, enneagram , nickname;
    int count = 0;

	ifstream myFile;
    myFile.open("MBTI.csv", ios::in);
    

    while (myFile.good())
    {

        getline(myFile, number, ',');
        getline(myFile, name, ',');
        getline(myFile, sex, ',');
        getline(myFile, ne, ',');		
		getline(myFile, ni, ',');		
		getline(myFile, te, ',');		
		getline(myFile, ti, ',');		
		getline(myFile, se, ',');		
		getline(myFile, si, ',');		
		getline(myFile, fe, ',');		
		getline(myFile, fi, ',');		
		getline(myFile, type, ',');		
		getline(myFile, enneagram, ',');
        getline(myFile, nickname, '\n');

        if(nickname == "Art")
        {
            me.number = number;
            me.name = name;
            me.ne = stof(ne);
            me.ni = stof(ni);
            me.te = stof(te);
            me.ti = stof(ti);
            me.se = stof(se);
            me.si = stof(si);
            me.fe = stof(fe);
            me.fi = stof(fi);
            me.type = type;
            me.nickname = nickname;
            me.distance = sqrt(pow((me.ne),2) + 
                                pow((me.ni),2) + 
                                pow((me.te),2) + 
                                pow((me.ti),2) + 
                                pow((me.se),2) + 
                                pow((me.si),2) + 
                                pow((me.fe),2) + 
                                pow((me.fi),2));
            count--;

        }
        else
        {
            datafriends[count].number = number;
            datafriends[count].name = name;
            datafriends[count].ne = stof(ne);
            datafriends[count].ni = stof(ni);
            datafriends[count].te = stof(te);
            datafriends[count].ti = stof(ti);
            datafriends[count].se = stof(se);
            datafriends[count].si = stof(si);
            datafriends[count].fe = stof(fe);
            datafriends[count].fi = stof(fi);
            datafriends[count].type = type;
            datafriends[count].nickname = nickname;
            
        }
        count++;
    }

    //distance friends
    for (int i = 0; i < count; i++)
    {
        datafriends[i].distance = sqrt(pow((me.ne - datafriends[i].ne),2) + 
                                        pow((me.ni - datafriends[i].ni),2) + 
                                        pow((me.te - datafriends[i].te),2) + 
                                        pow((me.ti - datafriends[i].ti),2) + 
                                        pow((me.se - datafriends[i].se),2) + 
                                        pow((me.si - datafriends[i].si),2) + 
                                        pow((me.fe - datafriends[i].fe),2) + 
                                        pow((me.fi - datafriends[i].fi),2));
    }
    

    //sort
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (datafriends[i].distance < datafriends[j].distance)
            {
                struct Friend temp = datafriends[i];
                datafriends[i] = datafriends[j];
                datafriends[j] = temp;
            }
        }
    }

    int mincount = 0;
    int maxcount = 0;
    string minType[5];
    string maxType[5];
    
    for (int i = 0; i < count; i++)
    {
        if (datafriends[i].distance == datafriends[0].distance)
        {
            minType[mincount] = datafriends[i].type;
            mincount++;
        }
        else if (datafriends[i].distance == datafriends[1].distance)
        {
            maxType[maxcount] = datafriends[i].type;
            maxcount++;
        }
        else
        {
            break;
        }
    }
    //print 
    cout << "======================================= " << endl;
    cout << "\t\t\tMy Friends" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "\t\t" << i+1 << " : "<< datafriends[i].nickname << " : " << datafriends[i].type << endl;
    }
    cout << "======================================= " << endl;

	cout << "\t\tI am " << me.nickname << " : " << me.type << endl;
    for (int i = 0; i < mincount; i++)
    {
        cout << "\tActual type is : " << minType[i] << endl;
    }
	cout << "======================================= " << endl;
}