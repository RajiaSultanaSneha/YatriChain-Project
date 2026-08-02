#ifndef TYPES_H
#define TYPES_H

#include "config.h"

/*==============================
        User Types
===============================*/

typedef enum
{
    PASSENGER = 1,
    VEHICLE_OWNER,
    COMPANY,
    ADMIN

} UserType;

/*==============================
        Vehicle Types
===============================*/

typedef enum
{
    BIKE = 1,
    CAR,
    MICROBUS,
    CNG,
    PICKUP,
    VAN,
    TRUCK,
    BUS

} VehicleType;

/*==============================
        Booking Status
===============================*/

typedef enum
{
    PENDING = 1,
    ACCEPTED,
    COMPLETED,
    CANCELLED

} BookingStatus;

/*==============================
        Payment Status
===============================*/

typedef enum
{
    UNPAID = 1,
    PAID,
    REFUNDED

} PaymentStatus;

/*==============================
        User Structure
===============================*/

typedef struct
{
    int userID;
    UserType type;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    double walletBalance;

} User;

/*==============================
        Vehicle Structure
===============================*/

typedef struct
{
    int vehicleID;
    int ownerID;
    VehicleType type;
    char model[MAX_MODEL_LENGTH];
    char plateNumber[MAX_PLATE_LENGTH];
    double rentPerKM;
    bool available;

} Vehicle;

/*==============================
        Company Structure
===============================*/

typedef struct
{
    int companyID;
    char companyName[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

} Company;

/*==============================
        Booking Structure
===============================*/

typedef struct
{
    int bookingID;
    int passengerID;
    int vehicleID;
    char pickup[MAX_ADDRESS_LENGTH];
    char destination[MAX_ADDRESS_LENGTH];
    double distance;
    double fare;
    BookingStatus bookingStatus;
    PaymentStatus paymentStatus;

} Booking;

#endif
