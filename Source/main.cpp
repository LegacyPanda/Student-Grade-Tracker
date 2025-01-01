#include <iostream>

using namespace std;

typedef double* OneDArray;

int main()
{
    bool boolContinue = true;
    OneDArray dblGrades = nullptr;


    int intNumOfGrades;
    cout << "How many grades do you want to input? ";
    cin >> intNumOfGrades;

    dblGrades = new double[intNumOfGrades];    

    for(int i = 0; i < intNumOfGrades; i++)
    {
        double dblGrade;
        cout << "Enter the grade percentage for position #" << i + 1 << endl;
        cin >> dblGrade;
        dblGrades[i] = dblGrade;
    }

    do
    {
        char chOption;
        cout << endl;
        cout << "Here are the following options" << endl
             << "Option A: Calculate the average" << endl 
             << "Option B: Get the minimum grade" << endl 
             << "Option C: Get the maximum grade" << endl 
             << "Option D: Enter new values" << endl
             << "Option X: Exit" << endl;

        cin >> chOption;

        switch(chOption)
        {
        case 'A':
        case 'a':
        {
            double dblTotal;
            for(int i = 0; i < intNumOfGrades; i++)
            {
                dblTotal += dblGrades[i];
            }

            cout << "The total is: " << dblTotal << endl;
            double dblAvarage = dblTotal / intNumOfGrades;
            cout << "The average is: " << dblAvarage;

            dblAvarage = 0;
            dblTotal = 0;
            break;
        }
        
        case 'B':
        case 'b':
        {
            double dblMinimum;
            dblMinimum = dblGrades[0];

            for(int i = 1; i < intNumOfGrades; i++)
            {
                if(dblMinimum > dblGrades[i])
                {
                    dblMinimum = dblGrades[i];
                }
            }

            cout << "The lowest grade is: " << dblMinimum << endl;
            break;
        }

        case 'C':
        case 'c':
        {
            double dblMaximum;
            dblMaximum = dblGrades[0];

            for(int i = 1; i < intNumOfGrades; i++)
            {
                if(dblMaximum < dblGrades[i])
                {
                    dblMaximum = dblGrades[i];
                }
            }

            cout << "The highest grade is: " << dblMaximum << endl;
            break;
        }

        case 'D':
        case 'd':
        {
            // Get the new grades
            int intMoreGrades;
            cout << "How many more grades do you want to add? " << endl;
            cin >> intMoreGrades;

            // Create a new array
            int intNewTotal = intMoreGrades + intNumOfGrades;
            OneDArray newGrades = new double[intNewTotal];

            // Copy old copy into the new copy
            for(int i = 0; i < intNumOfGrades; i++)
            {
                newGrades[i] = dblGrades[i];
            }

            // Input new grades
            for(int i = intNumOfGrades; i < intNewTotal; i++)
            {
                double dblInput;
                cout << "Enter the grade percentage for position #" << i + 1 << ": ";
                cin >> dblInput;
                newGrades[i] = dblInput;
            }

            // Delete old array and ressign the new pointer
            delete[] dblGrades; // This is a dangling pointer until I point to something else
            dblGrades = newGrades;
            intNumOfGrades = intNewTotal;

            newGrades = nullptr;
            break;
        }

        case 'X':
        case 'x':
        {
            cout << "Thank you for participating" << endl;
            boolContinue = false;
            break;
        }
        default:
            cerr << "Invalid option. Please try again!!!" << endl;
            break;
        }        

    }while(boolContinue);
    
    delete[] dblGrades;

    return 0;
}