#include <iostream>
#include <fstream>
#include <conio.h>
#include "BSAI25019_Fraction.h"

using namespace std;



void menu() {
    cout << "-----------------# MENU #-----------------" << endl;
    cout << "1. Enter From Input" << endl;
    cout << "2. Read From File" << endl;
    cout << "3. Operation +" << endl;
    cout << "4. Operation -" << endl;
    cout << "5. Operation %" << endl;
    cout << "6. Operation *" << endl;
    cout << "7. Operation /" << endl;
    cout << "8. Operation A++" << endl;
    cout << "9. Operation A--" << endl;
    cout << "10. Operation !" << endl;
    cout << "11. Operation []" << endl;
    cout << "12. Operation []&" << endl;
    cout << "13. Operation ==" << endl;
    cout << "14. Operation <" << endl;
    cout << "16. Operation ++A" << endl;
    cout << "17. Operation --A" << endl;
    cout << "18. Operation >" << endl;
    
    cout << "\n\n0. Exit" << endl;
    cout << "------------------------------------------" << endl;
}
void menu1() {
    cout << "-----------------# MENU #-----------------" << endl;
    cout << "1. Enter From Input" << endl;
    cout << "2. Read From File" << endl;
    cout << "3. Operation +" << endl;
    cout << "4. Operation -" << endl;
    cout << "6. Operation *" << endl;
    cout << "7. Operation /" << endl;
    cout << "8. Operation !" << endl;
    cout << "9. Operation ==" << endl;
    cout << "10. Operation <" << endl;
    cout << "11. Operation >" << endl;

    cout << "\n\n0. Exit" << endl;
    cout << "------------------------------------------" << endl;
}

int main()
{
    cout << "1-FRACTION or 2-HUGE INTEGER";
    int F;
    cout << "\nENter Choice !--> ";
    cin >> F;
    if (F == 2)
    {
        int C;
        HI A;
        HI B;
        ifstream rdr("Test.txt");

        while (true)
        {
            system("cls");
            menu();
            cout << "\nEnter Your Choice #: ";
            cin >> C;
            cout << endl;

            switch (C)
            {
            case 1:
            {
                cout << "ENTER FIRST HI  ";
                cin >> A;
                cout << "ENTER SECOND HI  ";
                cin >> B;
                break;
            }
            case 2:
            {
                rdr >> A;
                rdr >> B;
                break;
            }
            case 3:
            {
                cout << "RESULT --> A+B =" << A + B;
                break;
            }
            case 4:
            {
                cout << "RESULT --> A-B =" << A - B;
                break;
            }
            case 5:
            {
                cout << "RESULT --> A%B =" << A % B;
                break;
            }
            case 6:
            {
                cout << "RESULT --> A*B =" << A * B;
                break;
            }
            case 7:
            {
                cout << "RESULT --> A/B =" << A / B; break;
            }
            case 8:
            {
                cout << "RESULT --> A++ =" << A++; break;
            }
            case 9:
            {
                cout << "RESULT --> A-- =" << A--; break;
            }
            case 10:
            {
                cout << "RESULT --> A+B =" << -A; break;
            }
            case 11:
            {
                cout << "ENTER WHICH INDEX-->";
                int r;
                cin >> r;
                cout << "RESULT --> A[i] =" << A[r]; break;
            }
            case 12:
            {
                cout << "ENTER WHICH INDEX-->";
                int r;
                cin >> r;
                cout << "RESULT --> A[i] =" << A[r]; break;
            }
            case 13:
            {
                cout << "RESULT --> A==B =" << ((A == B) ? "True" : "False"); break;
            }
            case 14:
            {
                cout << "RESULT --> A<B =" << ((A < B) ? "True" : "False"); break;
            }
            case 16:
            {
                cout << "RESULT --> --A =" << ++A; break;
            }
            case 17:
            {
                cout << "RESULT --> --A =" << --A; break;
            }
            case 18:
            {
                cout << "RESULT --> A<B =" << ((A > B) ? "True" : "False"); break;
            }
            case 0:
            {
                cout << "Exiting program..." << endl;
                return 0;
            }
            default:
                cout << "Invalid choice!" << endl;
            }

            cout << "\nPress any key to continue...";
            _getch();
        }




        return 0;
    }
    else
        {
            int C;
            Fraction A;
            Fraction B;
            ifstream rdr("Test.txt");

            while (true)
            {
                system("cls");
                menu1();
                cout << "\nEnter Your Choice #: ";
                cin >> C;
                cout << endl;

                switch (C)
                {
                case 1:
                {
                    cout << "ENTER FIRST HI  ";
                    cin >> A;
                    cout << "ENTER SECOND HI  ";
                    cin >> B;
                    break;
                }
                case 2:
                {
                    rdr >> A;
                    rdr >> B;
                    break;
                }
                case 3:
                {
                    cout << "RESULT --> A+B =" << A + B;
                    break;
                }
                case 4:
                {
                    cout << "RESULT --> A-B =" << A - B;
                    break;
                }
                case 6:
                {
                    cout << "RESULT --> A*B =" << A * B;
                    break;
                }
                case 7:
                {
                    cout << "RESULT --> A/B =" << A / B; break;
                }
                case 8:
                {
                    cout << "RESULT --> A+B =" << -A; break;
                }
                case 9:
                {
                    cout << "RESULT --> A==B =" << ((A == B) ? "True" : "False"); break;
                }
                case 10:
                {
                    cout << "RESULT --> A<B =" << ((A < B) ? "True" : "False"); break;
                }
                case 11:
                {
                    cout << "RESULT --> A>B =" << ((A > B) ? "True" : "False"); break;
                }

                case 0:
                {
                    cout << "Exiting program..." << endl;
                    return 0;
                }
                default:
                    cout << "Invalid choice!" << endl;
                }

                cout << "\nPress any key to continue...";
                _getch();
            }




            return 0;
 }

}




