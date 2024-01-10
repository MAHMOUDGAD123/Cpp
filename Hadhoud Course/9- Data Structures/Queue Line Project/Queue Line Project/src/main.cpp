#include <iostream>

#include "../Header Files/Queue Line.h"

#define MAIN_BEGIN int main(){
#define MAIN_END }


MAIN_BEGIN


Queue_Line PayBill_Queue("A0", "Pay Bill", 10);

PayBill_Queue.add_ticket();
PayBill_Queue.add_ticket();
PayBill_Queue.add_ticket();

PayBill_Queue.print_queue_info();

PayBill_Queue.printQline_rtl();
PayBill_Queue.printQline_ltr();

std::cout << "\n\n";

MAIN_END