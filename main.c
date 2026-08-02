/*==========================================
        YatriChain v2.0
Smart Transport & Vehicle Rental System
===========================================*/

#include "YatriChain Config.H"
#include "YatriChain Types.H"

/*==============================
    Function Prototypes
===============================*/

void splashScreen();
void loadingAnimation();
void clearScreen();
void pauseScreen();
void createDatabaseFiles();
int mainMenu();

/*==============================
            Main
===============================*/

int main()
{

    splashScreen();

    loadingAnimation();

    createDatabaseFiles();

    while (1)
    {

        clearScreen();

        int choice = mainMenu();

        switch(choice)
        {

        case 1:

            printf("\nPassenger Login Module\n");

            pauseScreen();

            break;

        case 2:

            printf("\nPassenger Signup Module\n");

            pauseScreen();

            break;

        case 3:

            printf("\nVehicle Owner Login Module\n");

            pauseScreen();

            break;

        case 4:

            printf("\nVehicle Owner Signup Module\n");

            pauseScreen();

            break;

        case 5:

            printf("\nBus Company Login Module\n");

            pauseScreen();

            break;

        case 6:

            printf("\nCompany Registration Module\n");

            pauseScreen();

            break;

        case 7:

            printf("\nAdmin Login Module\n");

            pauseScreen();

            break;

        case 8:

            printf("\nAbout YatriChain\n");

            pauseScreen();

            break;

        case 9:

            printf("\nThank You For Using YatriChain.\n");

            return 0;

        default:

            printf("\nInvalid Choice!\n");

            pauseScreen();

        }

    }

    return 0;

}
