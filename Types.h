#ifndef TYPES_H
#define TYPES_H

#include "config.h"

/*==========================
      User Dynamic Structure
==========================*/
typedef struct {
    char name[MAX_NAME_LENGTH];
    char nid[20];
    char phone[MAX_PHONE_LENGTH + 1];
    char password[MAX_PASSWORD_LENGTH];
    int role; // 1: Passenger, 2: Vehicle Owner, 3: Admin
} User;

/*==========================
    Vehicle Dynamic Structure
==========================*/
typedef struct {
    int id;
    char name[MAX_MODEL_LENGTH];
    char type[20];                       // Bus, Taxi, Uber
    char route[MAX_ROUTE_LENGTH];        // Route details
    int total_seats;                     // Bus seat capacity / Taxi capacity
    int available_seats[3];              // Seats for 3 Shifts (Bus)
    double price_per_ticket;             // Ticket price OR Rate per KM
    char seats_info[50];
    double total_rating;
    int rating_count;
    
    /* Security, Discount & Validity Fields */
    char plate_no[MAX_PLATE_LENGTH];     // Vehicle Number Plate
    char promo_code[20];                 // Custom Promo Code
    double discount_percent;             // Discount percentage
    char validity_date[20];              // Expiry Date (YYYY-MM-DD)
} Vehicle;

/*==========================
    Booking Dynamic Structure
==========================*/
typedef struct {
    char ticket_id[20];
    char user_name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH + 1];
    int vehicle_id;
    char seat_number[20];                // Seat no or Service type
    int shift_choice;
    int tickets_booked;                  // Seats or Vehicles count
    double distance_km;                  // Distance for Taxi/Uber
    char pickup_location[MAX_ADDRESS_LENGTH];
    char drop_location[MAX_ADDRESS_LENGTH];
    double original_fare;
    double final_fare;
    double total_cost;
    int otp;
    char payment_method[20];             // bKash, Nagad, Cash
    char wallet_number[20];
    char status[20];                     // Booked, Cancelled
    int sos_alert;
} Booking;

#endif
