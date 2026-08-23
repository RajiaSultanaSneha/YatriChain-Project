#include <stdio.h>
#include "sos.h"

int sos_alert = 0;
int is_Active_Passenger = 0;

void trigger_sos_alert(){
if (!is_Active_Passenger){
printf("No active passenger.\n  No SOS alert can be triggered.\n");
  return;
  }

    printf("\n============================================\n");
    printf("\n[!!!]EMERGENCY SOS ALERT TRIGGERED [!!!]\n");
    printf("============================================\n");

    printf("contacting emergency services...\n");
    printf("Contact Immediately Local Authorities \n");
    printf(" Police           : 999\n");
    printf(" Ambulance        : 999\n");
    printf("Fire Service      :999\n");

    sos_alert = 1;
    printf("==============================================\n");
    printf("SOS alert has been triggered successfully.\n");
    printf("===============================================\n");
}
