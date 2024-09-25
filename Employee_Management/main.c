#include <stdio.h>
#include <stdlib.h>
#include "employee_management.h"
#include "typedef.h"


int main()
{
    uint8_t choice ;
    do
    {
        printf("1. Add anew employee\n" )  ;
        printf("2. Display employee\n") ;
        printf("3. Display company statistics\n") ;
        printf("4. Take a vacation\n") ;
        printf("5. Employee services\n") ;
        printf("6. diplay the vacations\n") ;
        printf("7. exit\n");
        printf("choose aprocess  ") ;
        scanf("%i", &choice) ;

        switch (choice)
        {
        case 1 :
            addEmployee() ;
            break ;
        case 2 :
            displayEmployee() ;
            break ;
        case 3 :
            statistics() ;
            break ;
        case 4 :
            take_avacation();
            break ;
        case 5 :
            employeeServices() ;
            break ;
        case 6 :
            display_vacations() ;
            break ;
        case 7:
            printf("exiting...") ;
            break ;
        default :
            printf("invalid choice !\n") ;
        }

    }while (choice !=7) ;
}
