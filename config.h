#ifndef CONFIG_H
#define CONFIG_H

/*====================================================
                YATRICHAIN v2.0
      Smart Transport & Vehicle Rental System
=====================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

/*==========================
      Application Info
==========================*/

#define APP_NAME        "YatriChain"
#define APP_VERSION     "2.0"
#define APP_YEAR        "2026"

/*==========================
      System Limits
==========================*/

#define MAX_USERS              500
#define MAX_OWNERS             300
#define MAX_COMPANIES          50
#define MAX_VEHICLES          1000
#define MAX_BOOKINGS          5000
#define MAX_NOTIFICATIONS     1000

/*==========================
      String Limits
==========================*/

#define MAX_NAME_LENGTH        50
#define MAX_PHONE_LENGTH       15
#define MAX_EMAIL_LENGTH       60
#define MAX_PASSWORD_LENGTH    30
#define MAX_ADDRESS_LENGTH    100
#define MAX_ROUTE_LENGTH       50
#define MAX_PLATE_LENGTH       20
#define MAX_MODEL_LENGTH       50

/*==========================
      Database Files
==========================*/

#define USERS_FILE          "database/users.txt"
#define OWNERS_FILE         "database/owners.txt"
#define COMPANIES_FILE      "database/companies.txt"
#define VEHICLES_FILE       "database/vehicles.txt"
#define BOOKINGS_FILE       "database/bookings.txt"
#define WALLET_FILE         "database/wallet.txt"
#define NOTIFICATION_FILE   "database/notifications.txt"

/*==========================
   Function Prototypes
   (ui.c te define kora)
==========================*/

void splashScreen(void);
void loadingAnimation(void);
void clearScreen(void);
void pauseScreen(void);
int  mainMenu(void);

/*==========================
   Function Prototype
   (database.c te define kora)
==========================*/

void createDatabaseFiles(void);

#endif
