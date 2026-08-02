#include "config.h"

#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(path) _mkdir(path)
#else
    #include <sys/stat.h>
    #define MKDIR(path) mkdir(path, 0777)
#endif

void createDatabaseFiles(void)
{
    FILE *fp;

    MKDIR("database");

    fp = fopen(USERS_FILE, "a");
    if (fp) fclose(fp);

    fp = fopen(OWNERS_FILE, "a");
    if (fp) fclose(fp);

    fp = fopen(COMPANIES_FILE, "a");
    if (fp) fclose(fp);

    fp = fopen(VEHICLES_FILE, "a");
    if (fp) fclose(fp);

    fp = fopen(BOOKINGS_FILE, "a");
    if (fp) fclose(fp);

    fp = fopen(WALLET_FILE, "a");
    if (fp) fclose(fp);

    fp = fopen(NOTIFICATION_FILE, "a");
    if (fp) fclose(fp);
}
