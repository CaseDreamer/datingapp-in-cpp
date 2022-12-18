#include <iostream>
#include <string>

using namespace std;

class dapp{

private:
    // Private member variables
    string name[4], gender[4], bloodtyp[4], descgentyp, descbloodtype;
    int age[4], score[4], meage, descage;
    int i = 0;

public:
    // Public member functions
    void inputdata(){
        cout << "Enter name: " << endl;
        cin.ignore();
        getline(cin, name[i]);
        cout << "Enter age: ";
        cin >> age[i];
        cout << "Enter gender: ";
        cin >> gender[i];
        cout << "Enter bloodtype: ";
        cin >> bloodtyp[i];
    }

    void findcrit(){
        cout << "Enter your criteria: " << endl;
        cout << "Male/Female: ";
        cin >> descgentyp;
        cout << "Enter your age: ";
        cin >> meage;
        cout << "more 'old'/more 'young': ";
        cin >> descage;
        cout << "Blood type selection: ";
        cin >> descbloodtype;
    }

    void ageyoung(){
        if (age[i] <= meage){
            score[i] += 1;
        }
    }

    void ageold(){
        if (age[i] > meage){
            score[i] += 1;
        }
    }

    void output(){
        cout << "Criteria that match your choice:" << endl;
        cout << "Name: " << name[i] << endl;
        cout << "Age: " << age[i] << endl;
        cout << "Gender: " << gender[i] << endl;
        cout << "Blood Type: " << bloodtyp[i] << endl;
    }

    void ngender(){
        if (gender[i] != descgentyp){
            score[i] += 1;
        }
    }

    void nage(){
        if (descage == "young"){
            ageyoung();
        }
        else if (descage == "old"){
            ageold();
        }
        if (bloodtyp[i] == descbloodtype){
            score[i] += 1;
        }
    }

    void nbloodtyp(){
        if (bloodtyp[i] == descbloodtype){
            score[i] += 1;
        }
    }

    void nscore(){
        int highest_score_index = 0;
        int highest_score = score[0];
        for (int j = 1; j < 4; j++){
            if (score[j] > highest_score){
                highest_score = score[j];
                highest_score_index = j;
            }
        }
        i = highest_score_index;
    }
};

int main()
{
    dapp ndapp;
    char cari;
        for (int i;i<4;i++){
                ndapp.inputdata();

        }
        ndapp.findcrit();
        ndapp.nage();
        ndapp.ngender();
        ndapp.nbloodtyp();
        ndapp.nscore();
        ndapp.output();

    return 0;
}