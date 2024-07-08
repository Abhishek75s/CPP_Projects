#include<iostream>
#include<fstream>
using namespace std;

struct Bank {

    string firstName, lastName, phoneNumber, address, cnic;
    int amount;

    Bank(): firstName(""), lastName(""), phoneNumber(""), address(""), cnic(""), amount(0) {};
    
    void greet_user(){
        cout<<"\t\tMy Banking System! -> Welcome to laxmi chit fund \n";
        cout<<"--------------**********************--------------"<<endl;
    }

    void openAcc()
    {
        cout<<"\nEnter First Name: ";
        cin>>firstName;
        cout<<"Enter Last Name: ";
        cin>>lastName;
        cout<<"Enter Phone Number: ";
        cin>>phoneNumber;
        cout<<"Enter Address: ";
        cin>>address;
        cout<<"Enter cnic: ";
        cin>>cnic;
    }

    void displayUserDetails()
    {   
        cout << "\nUser Details are: "<<endl;
        cout << "\tFirst Name is: " << firstName << endl;
        cout << "\tLast Name is: " << lastName << endl;
        cout << "\tPhone Number is: " << phoneNumber << endl;
        cout << "\tAddress is: " << address << endl;
        cout << "\tcnic is: " << cnic << endl;
        cout << "\tAvailable Balance is: " << amount << endl;
    }

};

// ofstream 

int main()
{
    Bank bk;
    bk.greet_user();

    // printing choicces
    cout<<"\n Pls select an option below:"<<endl;
    cout<<"\n\t1. Open New Account."<<endl;
    cout<<"\t2. Deposit Money."<<endl;
    cout<<"\t3. Withdraw Money."<<endl;
    cout<<"\t4. Check your Balance."<<endl;
    cout<<"\t5. Update existing Record."<<endl;
    cout<<"\t6. Search Record."<<endl;
    cout<<"\t7. Delete Record."<<endl;
    cout<<"\t8. Exit."<<endl;

    int selectChoice;

    do
    {
        cout<<"\n-> Enter your choice: ";
        cin>>selectChoice;

        if(selectChoice == 1){
            bk.openAcc();

            ofstream userDetailsFile("C:\\Users\\abhis\\OneDrive\\Desktop\\code to Decode\\My Projects\\Banking mgmt\\User Data\\User_Details.dat", ios::app);
            userDetailsFile.write((char*)&userDetailsFile, sizeof(userDetailsFile));
            userDetailsFile.close();

            bk.displayUserDetails();
        }

        else if(selectChoice == 2){
            string tempName; int tempAmount=0;
            cout<<"\nEnter First Name, to check its existence: "; cin>>tempName;
            
            ifstream u("C:\\Users\\abhis\\OneDrive\\Desktop\\code to Decode\\My Projects\\Banking mgmt\\User Data\\User_Details.dat");

            // cout<<"->" <<bk.firstName<<endl;;

            while(u.read((char*)&bk, sizeof(bk)))
            {
                // cout<<tempName<<" "<<bk.firstName<<endl;;
                if(tempName == bk.firstName){
                    // cout<<"found"<<endl;
                    // // bk.displayUserDetails();

                    // cout<<"Enter amount to be deposited: "; cin>>tempAmount;
                    // bk.amount += tempAmount;
                }
                else{
                    cout<<"\nData Not found for entered name :("<<endl;
                    // bk.displayUserDetails();
                }
            }
        }

    } while(selectChoice >= 1 and selectChoice <= 7);

    cout<<"\n ******** Hope you enjoyed! Thank you for using our services :))  ***************";

    return 0;
}
