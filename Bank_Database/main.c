#include <stdio.h>
#include "bank_database.h"

int main()
{
    int  choice ;

    do
    {
        printf("\nBank Database System\n\n");
        printf("1. add new customer\n") ;
        printf("2. display customer\n") ;
        printf("3. update balance\n") ;
        printf("4. find customer id\n") ;
        printf("5. transfer cash\n") ;
        printf("6. account settings\n") ;
        printf("7. display list of customers\n") ;
        printf("8. display the number of active customers\n") ;
        printf("9. exit\n") ;
        printf("Enter your choice: ") ;
        scanf("%i", &choice) ;

        switch (choice)
        {
        case 1 :
            add_customer() ;
            break ;
        case 2 :
            dispaly_customer() ;
            break ;
        case 3 :
            update_balance() ;
            break ;
        case 4 :
            find_id() ;
            break ;
        case 5 :
            trans_cash() ;
            break ;
        case 6 :
            account_settings() ;
            break ;
        case 7 :
            list() ;
            break ;
        case 8 :
            active_customers() ;
            break ;
        case 9 :
            printf("exiting...\n") ;
            break ;
        default :
            printf("invalid choice !\n") ;
        }

    }while (choice != 9 ) ;

    return 0;
}
