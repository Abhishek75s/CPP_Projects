#include <iostream>
#include<climits> // INT_MAX
using namespace std;

class currConvertor{
    private:  // members for, rate of convesion
        double USDtoINR; // 12
        double USDtoEuro; // 13
        double USDtoDinar; // 14

        double INRtoUSD; // 21
        double INRtoEuro; // 23
        double INRtoDinar; // 24

        double EurotoUSD; // 31
        double EurotoINR; // 32
        double EurotoDinar; // 34

        double DinartoUSD; // 41
        double DinartoINR; // 42
        double DinartoEuro; // 43

    public:
        // Parameterised-constructor
        currConvertor(double a, double b, double c, double d, double e, double f, double g, double h, double i, double j, double k, double l){
    
            USDtoINR = a; 
            USDtoEuro = b;
            USDtoDinar = c;

            INRtoUSD = d;
            INRtoEuro = e;
            INRtoDinar = f;

            EurotoUSD = g;
            EurotoINR = h;
            EurotoDinar = i;

            DinartoUSD = j;
            DinartoINR = k;
            DinartoEuro = l;
        }

        // methods to convert currencies

        // fromcurrency: USD
        double convertUSDtoINR(double amount){
            return amount*USDtoINR;
        }
        double convertUSDtoEuro(double amount){
            return amount*USDtoEuro;
        }
        double convertUSDtoDinar(double amount){
            return amount*USDtoDinar;
        }

        // fromcurrency: INR
        double convertINRtoUSD(double amount){
            return amount*INRtoUSD;
        }
        double convertINRtoEuro(double amount){
            return amount*INRtoEuro;
        }
        double convertINRtoDinar(double amount){
            return amount*INRtoDinar;
        }

        // fromcurrency: Euro
        double convertEurotoUSD(double amount){
            return amount*EurotoUSD;
        }
        double convertEurotoINR(double amount){
            return amount*EurotoINR;
        }
        double convertEurotoDinar(double amount){
            return amount*EurotoDinar;
        }

        // fromcurrency: Dinar
        double convertDinartoUSD(double amount){
            return amount*DinartoUSD;
        }
        double convertDinartoINR(double amount){
            return amount*DinartoINR;
        }
        double convertDinartoEuro(double amount){
            return amount*DinartoEuro;
        }        
};

int main(){

    int fromCurrency, toCurrency;
    int amount;
    double ans = 0.0;
    char ch;

    // these values can be fetched from internet for realtime conversion
    // values as per date: 01-July-2024
    const double intial_USDtoINR_Rate = 83.46;
    const double intial_USDtoEuro_Rate = 0.93;
    const double intial_USDtoDinar_Rate = 0.31;
 
    const double intial_INRtoUSD_Rate = 0.012;
    const double intial_INRtoEuro_Rate = 0.011;
    const double intial_INRtoDinar_Rate = 0.0037;
 
    const double intial_EurotoUSD_Rate = 1.07;
    const double intial_EurotoINR_Rate = 89.57;
    const double intial_EurotoDinar_Rate = 0.33;
 
    const double intial_DinartoUSD_Rate = 3.26;
    const double intial_DinartoINR_Rate = 272.24;
    const double intial_DinartoEuro_Rate = 3.04;

    // constructor to initialize private members
    currConvertor Convertor(intial_USDtoINR_Rate, intial_USDtoEuro_Rate, intial_USDtoDinar_Rate, intial_INRtoUSD_Rate, intial_INRtoEuro_Rate, intial_INRtoDinar_Rate, intial_EurotoUSD_Rate, intial_EurotoINR_Rate, intial_EurotoDinar_Rate, intial_DinartoUSD_Rate, intial_DinartoINR_Rate, intial_DinartoEuro_Rate);
    
    do{
        cout<<"\n***------- Convert Currecies -------***\n"<<endl;
        // From currency section
        cout<<"\tFROM Currency:"<<endl;
        cout<<"\t1. USD"<<endl;
        cout<<"\t2. INR"<<endl;
        cout<<"\t3. Euro"<<endl;
        cout<<"\t4. Dinar\n"<<endl;
        
        cout<<"Selcet choice: ";
        cin>>fromCurrency;

        // check for valid selection
        if(fromCurrency >= 1 && fromCurrency <=4){
            cout<<"\nEnter amount to be converted: ";
            cin>>amount;
        }
        else{
            cout<<"\nOops!, Selection is out of range\n";
        }
        
        // To currency section
        cout<<"\n\tTO Currency:"<<endl;
        cout<<"\t1. USD"<<endl;
        cout<<"\t2. INR"<<endl;
        cout<<"\t3. Euro"<<endl;
        cout<<"\t4. Dinar\n"<<endl;
        
        cout<<"Selcet choice: ";
        cin>>toCurrency;

        // check for invalid selection
        if(toCurrency < 1 && toCurrency > 4){
            cout<<"\nOops!, Selection is out of range\n";
        }

        // proceed for calculation
        else{

            if(fromCurrency == toCurrency){
                ans = amount; 
                cout<<"\nResult: "<<ans<<endl<<endl;
            }

            else{
                if(fromCurrency == 1){
                    switch(toCurrency){
                        case 2: 
                            ans = Convertor.convertUSDtoINR(amount);
                            cout<<"\n Amount after conversion: "<<ans<<endl<<endl;
                            break;

                        case 3:
                            ans = Convertor.convertUSDtoEuro(amount);
                            cout<<"\n Amount after conversion: "<<ans<<endl<<endl;
                            break;

                        case 4:
                            ans = Convertor.convertUSDtoDinar(amount);
                            cout<<"\n Amount after conversion: "<<ans<<endl<<endl;
                            break;                      
                    }
                }

                if(fromCurrency == 2){
                    switch(toCurrency){
                        case 1: 
                            ans = Convertor.convertINRtoUSD(amount);
                            cout<<"\n Amount after conversion: "<<ans<<endl<<endl;
                            break;

                        case 3:
                            ans = Convertor.convertINRtoEuro(amount);
                            cout<<"\n Amount after conversion: "<<ans<<endl<<endl;
                            break;

                        case 4:
                            ans = Convertor.convertINRtoDinar(amount);
                            cout<<"\n Amount after conversion: "<<ans<<endl<<endl;
                            break;                      
                    }
                }

                if(fromCurrency == 3){
                    switch(toCurrency){
                        case 1: 
                            ans = Convertor.convertEurotoUSD(amount);
                            cout<<"\n Amount after conversion: "<<ans<<endl<<endl;
                            break;

                        case 2:
                            ans = Convertor.convertEurotoINR(amount);
                            cout<<"\n Amount after conversion: "<<ans<<endl<<endl;
                            break;

                        case 4:
                            ans = Convertor.convertEurotoDinar(amount);
                            cout<<"\n Amount after conversion: "<<ans<<endl<<endl;
                            break;                      
                    }
                }

                if(fromCurrency == 4){
                    switch(toCurrency){
                        case 1: 
                            ans = Convertor.convertDinartoUSD(amount);
                            cout<<"\n Amount after conversion: "<<ans<<endl<<endl;
                            break;

                        case 2:
                            ans = Convertor.convertDinartoINR(amount);
                            cout<<"\n Amount after conversion: "<<ans<<endl<<endl;
                            break;

                        case 3:
                            ans = Convertor.convertDinartoEuro(amount);
                            cout<<"\n Amount after conversion: "<<ans<<endl<<endl;
                            break;                      
                    }
                }
            }  
        }
 
 // no default cases are used in any switch statements because the values switch will get, will always be valid becuase the values are checked before passsing to switch statement.

        system("pause"); // to hold the screen, until a key is not pressed

        cout<<"\t\n- - - Want to proceed, for another round?? [Y/N]"<<endl;
        cin>>ch;

    } while(ch == 'Y' or ch == 'y');

    cout<<"\n***-----Visit again, Happy conversion :) -----***"<<endl;

}
