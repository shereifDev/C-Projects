/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
                                               BANK DATABASE PROJECT
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define size 50                                    // Maximum number of customers in the database

struct customer
{
    int id ;
    char name[50] ;
    long long phone_number ;
    char type [10] ;
    double balance ;
    int status ;
};

struct customer customers[size] ;
int index = 0  ;

/* ====================================ADD CUSTOMER===================================*/

// Function to add a new customer to the database

void add_customer (void )
{
    printf("enter customer name :\n") ;
    fflush (stdin) ;
    gets(&customers[index].name) ;

    printf("enter customer ID :\n") ;
    scanf("%i", &customers[index].id) ;

    printf("enter customer phone number (+20) :\n") ;
    scanf("%llu", &customers[index].phone_number) ;

l1:
    printf("enter customer balance :\n") ;
    scanf("%lf", &customers[index].balance) ;
    if (customers[index].balance <0)
    {
        printf("cash should be positive , try again .. \n") ;
        goto l1 ;                                                                                      // Retry if balance is negative
    }

    printf("enter customer type (debit or credit):\n") ;
    fflush (stdin) ;
    gets( &customers[index].type) ;

    customers[index].status = 1 ;
    printf("Customer number %i was added successfully!\n", index+1 );
    index ++ ;
}

/*=====================================FIND CUSTOMER BY ID================================*/

// Function to find a customer  by his ID

int find_customer (int search_id)
{
    for (int i=0 ; i<size ; i++)
    {
        if (customers[i].id==search_id)
        {
            return i ;
        }
    }
    return -1 ;                                                    // Return -1 if customer is not found
}

/*==================================DISPLAY CUSTOMER======================================*/

// Function to display customer  information

void dispaly_customer (void)
{
    int search_id, cust ;
    char choice ;

    printf("enter customer ID\n") ;
    scanf("%i", &search_id) ;
    cust = find_customer(search_id) ;
    if (cust != -1)
    {
        printf("\t\t=========CUSTOMER INFORMATOIN==========\n\n") ;
        printf("name : %s\n", customers[cust].name ) ;
        printf("ID : %i\n", customers[cust].id ) ;
        printf("phone number (+20): %llu\n", customers[cust].phone_number ) ;
        printf("type : %s\n", customers[cust].type ) ;
        printf("balance : %.2lf$\n", customers[cust].balance ) ;
        printf("status :%s\n",  customers[cust].status ? "active" : "closed" ) ;
        printf("\t\t======================================\n") ;
    }
    else
    {
        printf("customer not found !\n") ;
        return ;
    }
    printf("would you like to save the customer data in file ? (y/n)\n") ;                // Ask if the user wants to save customer data to a file
    scanf(" %c", &choice) ;
    if (choice == 'y' ||choice == 'Y' )
    {
        print_data() ;
    }
}

/*====================================DATA FILE =====================================*/

// Function to save customer data into a file

void print_data (void )
{
    int search_id, cust ;
    FILE *ptr = NULL ;
    ptr = fopen("data.text", "w") ;                             // Open new file  to write the information in it
    if (ptr != NULL)
    {
        printf("enter customer ID again\n") ;
        scanf("%i", &search_id) ;
        cust = find_customer(search_id)  ;
        fprintf(ptr, "\t\t=========CUSTOMER INFORMATOIN==========\n\n") ;
        fprintf(ptr,"name : %s\n", customers[cust].name ) ;
        fprintf(ptr, "ID : %i\n", customers[cust].id ) ;
        fprintf(ptr, "phone number (+20): %llu\n", customers[cust].phone_number ) ;
        fprintf(ptr, "type : %s\n", customers[cust].type ) ;
        fprintf(ptr, "balance : %.2lf\n", customers[cust].balance ) ;
        fprintf(ptr,"status : %s\n",  customers[cust].status ? "active" : "closed" ) ;
        fprintf(ptr,"\t\t=======================================\n") ;
        fclose(ptr) ;                                                        // Close the file after writing
    }
    else
    {
        printf("Error opening file!\n");
    }
}

/*=================================UPDATE BALANCE ======================================*/

// Function to update customer balance

void update_balance (void)
{
    int choice, search_id, cust ;
    double amount ;

    printf("would you like to make \n1. deposit\n2. withdraw\n") ;
    scanf("%i", &choice) ;
    printf("ok , enter customer ID\n") ;
    scanf("%i", &search_id) ;
    cust = find_customer(search_id) ;

    if (customers[cust].status == 0)                                          // Check if account is closed
    {
        printf("sorry , this account is closed !!\n") ;
        return ;
    }

    switch (choice)
    {
    case 1 :
        printf("enter the amount you want to deposit :\n") ;
        scanf("%lf",&amount) ;
        customers[cust].balance += amount ;
        printf("deposit successful! new balance: %.2lf$\n", customers[cust].balance);
        break ;

    case 2 :
        printf("enter the amount you want to withdraw :\n") ;
        scanf("%lf",&amount) ;

        if (customers[cust].balance >= amount)                  // Check if there is enough balance
        {
            customers[cust].balance -= amount ;
            printf("withdrawal successful! new balance: %.2lf$\n", customers[cust].balance) ;
        }
        else
        {
            printf("there is not enugh money in the account\n") ;
        }

        break ;

    default :
        printf("invalid choice !\n") ;

    }

}

/* ====================================FIND THE CUSTOMER ID===============================*/

// Function to find a customer ID by his phone number

void find_id (void)
{
    long long phone ;
    int  found = 0  ;

    printf("enter the phone number :\n") ;
    scanf("%llu", &phone) ;

    for (int i=0 ; i<size ; i++)
    {
        if (customers[i].phone_number == phone)
        {
            printf("the customer ID is : %i\n", customers[i].id ) ;
            found ++ ;
        }
    }
    found ? found  : printf("phone number not found !\n") ;
}

/*===================================TRANSFER CASH ========================================*/

// Function to transfer cash from one customer to another

void trans_cash (void)
{
    int c1_id, c2_id, sender, receiver ;
    double cash_trans ;

    printf("here you can transfer cash form customer to another..\n\n") ;
    printf("plz enter customer ID you want to transfer from :\n") ;
    scanf("%i", &c1_id) ;
    printf("plz enter customer ID you want to transfer to :\n") ;
    scanf("%i", &c2_id) ;
    printf("enter the cash you want to transfer :\n") ;
    scanf("%lf", &cash_trans) ;
    sender = find_customer(c1_id) ;
    if (sender != -1)
    {
        if (customers[sender].status = 1)                                               // Check if sender account is active
        {
            if (customers[sender].balance >= cash_trans)                     // Check if there is enough balance
            {
                receiver = find_customer(c2_id) ;
                if (customers[receiver].status == 1)                                  // Check if receiver account is active
                {
                    customers[receiver].balance += cash_trans ;
                    customers[sender].balance -= cash_trans ;
                    printf("transferred successfully\n") ;
                }
                else
                {
                    printf("receiver account is closed !\n") ;
                }
            }
            else
            {
                printf("there is not enough money in sender account !\n") ;
            }
        }
        else
        {
            printf("sender account is closed !\n") ;
        }


    }

    else
    {
        printf("sender not found !\n") ;
    }
}
/*==================================ACCOUNT  SETTINGS====================================*/

// Function for managing account settings (delete, close, reopen, change type)

void account_settings(void)
{
    int choice, cust = -1, search_id ;
    char del_account ;

    printf("<Account Settings>\n1. delete an account\n2. close an account\n3. reopen an account\n4. change the type\nEnter your choice: ") ;
    scanf("%i", &choice) ;
    printf("\nok , enter customer ID :\n") ;
    scanf("%i", &search_id ) ;
    cust = find_customer(search_id) ;
    if (cust == -1)
    {
        printf("customer not found !") ;
        return ;
    }

    switch (choice)
    {
    case 1 :
        if (customers[cust].balance > 0)                                            // Check if balance is zero
        {
            printf("The account still has a balance of %.2lf.withdraw the balance before deleting\n", customers[cust].balance);
            return;
        }
        else
        {
            printf("are you sure you want to delete this account (y/n)\n") ;
            scanf(" %c", &del_account) ;
            if (del_account == 'y' || del_account == 'Y' )
            {
                for (int i = cust ; i<size-1; i++)                                // Shift all customers after the deleted one
                {
                    customers[i] = customers[i+1] ;
                }
                printf("account deleted successfully\n") ;
                index -- ;
            }
            else
            {
                printf("account deletion cancelled\n") ;
            }
        }
        break ;

    case 2 :
        customers[cust].status = 0 ;
        printf("account closed successfully\n") ;
        break ;

    case 3 :
        customers[cust].status = 1 ;
        printf("account opened successfully\n") ;
        break ;

    case 4 :
        printf("enter the new type (depit/credit) ?\n") ;
        fflush (stdin) ;
        gets( &customers[cust].type) ;
        printf("updated successfully\n") ;
        break ;

    default :
        printf("invalid choice !\n") ;
    }

}

/*========================================CUSTOMERS LIST====================================*/

// Function to list all customers

void list (void)
{
    for (int i=0 ; i < index ; i++)
    {
        printf("%i. name : %s  id : %i  balance : %.2lf\n", i+1, customers[i].name, customers[i].id, customers[i].balance) ;
    }
}

/*===================================NUMBER OF ACTIVE CUSTOMERS=================================*/

// Function to count and display the number of active customers

void active_customers(void)
{
    int counter = 0;
    for (int i = 0 ; i < index ; i++)
    {
        if (customers[i].status == 1)
        {
            counter ++;
        }
    }
    printf("number of active customers : %i\n", counter);
}




                                                                    /*   إِنَّ اللَّهَ وَمَلَائِكَتَهُ يُصَلُّونَ عَلَى النَّبِيِّ ۚ
                                                                     يَا أَيُّهَا الَّذِينَ آمَنُوا صَلُّوا عَلَيْهِ وَسَلِّمُوا تَسْلِيمًا   */
