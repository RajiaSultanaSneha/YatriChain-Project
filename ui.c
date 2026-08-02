#include "config.h"

/* Windows e Sleep() lagbe, Linux/macOS e usleep() lagbe.
   Eta na thakle "undefined reference to Sleep" error dibe. */
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
    #define CLEAR_CMD "cls"
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep((ms) * 1000)
    #define CLEAR_CMD "clear"
#endif

void splashScreen(void)
{
    system(CLEAR_CMD);

    printf("\n");
    printf("=============================================\n");
    printf("           YATRI CHAIN SYSTEM\n");
    printf("=============================================\n");
    printf("      Secure Bus Ticket Management System\n");
    printf("=============================================\n");
}

void loadingAnimation(void)
{
    printf("\nLoading");

    for (int i = 0; i < 5; i++)
    {
        printf(".");
        fflush(stdout);
        SLEEP_MS(400);
    }

    printf("\n");
    pauseScreen();
}

void clearScreen(void)
{
    system(CLEAR_CMD);
}

void pauseScreen(void)
{
    printf("\nPress Enter to continue...");

    /* getchar() ekbar diye buffer clear kore,
       tarpor abar Enter chapa porjonto wait kore.
       Age eta na thakle scanf("%d", ...) er por
       pauseScreen thik kaj korto na. */
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int mainMenu(void)
{
    int choice;

    clearScreen();

    printf("====================================\n");
    printf("         YATRI CHAIN MENU\n");
    printf("====================================\n");
    printf("1. Passenger Login\n");
    printf("2. Passenger Signup\n");
    printf("3. Vehicle Owner Login\n");
    printf("4. Vehicle Owner Signup\n");
    printf("5. Bus Company Login\n");
    printf("6. Company Registration\n");
    printf("7. Admin Login\n");
    printf("8. About YatriChain\n");
    printf("9. Exit\n");
    printf("====================================\n");
    printf("Enter Choice: ");

    while (scanf("%d", &choice) != 1)
    {
        /* jodi kew number er bodole letter type kore,
           tahole ei loop infinite crash na kore
           buffer clear kore abar jiggasha korbe */
        if (feof(stdin))
        {
            /* input stream shesh hoye gele program safe vabe
               close hobe, infinite loop hobe na */
            printf("\nInput shesh. Program bondho hocche.\n");
            exit(0);
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        printf("Shudhu number din. Abar chesta korun: ");
    }

    return choice;
}
