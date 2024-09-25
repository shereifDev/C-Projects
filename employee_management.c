#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typedef.h"
#define   max    50                                      // max_number of employees

employees arr[max];
vacation xat[max] ;
uint16_t  num = 0,  numOfVacations = 0;

/*....................................................................................................................................................................................................................................*/

// function to add anew employee in the database
void addEmployee (void)
{
    if (num >= max)
    {
        printf("Employee database is full . Cannot add more employees !\n");
        return;
    }

    printf ("enter employee ID :\n") ;
    scanf("%i", &arr[num].id) ;

    printf("enter employee name :\n") ;
    fflush(stdin) ;                                                        //using fflush to empty the input buffer  before using gets( )
    gets(&arr[num].name) ;

    printf("enter employee position :\n") ;
    printf("1. Developer\n2. Devops\n3. Data Analyst \n4. Web Developer \n5. Embedded Systems Engineer\n6. Content Creator \n7. Video Editor\n");
    scanf("%i",&arr[num].f) ;

    printf("enter employee salary :\n") ;
    scanf("%f", &arr[num].salary) ;

    arr[num].st = active ;                                        //employee active by default

    printf("employee number %i was added successfully \n\n", num+1) ;
    num++ ;
}

/*....................................................................................................................................................................................................................................*/

//function to find the index of employee by his ID
sint16_t  findIndexByID (sint16_t search_id )
{

    for (int i=0 ; i<num ; i++)
    {
        if (search_id == arr[i].id)                              //check if entered ID equal employee ID then return his index
        {
            return i ;
        }
    }
    return -1 ;                                                        // if ID not found i`ll return -1
}

/*....................................................................................................................................................................................................................................*/

//function to display specific employee by using ID
void displayEmployee (void)
{
    sint16_t  search_id, index ;
    printf ("enter the employee ID :\n") ;
    scanf ("%hd", &search_id) ;
    index = findIndexByID(search_id) ;
    if (index != -1)
    {
        printf("\t__________EMPLOYEE INFORMATION__________\n\n") ;
        printf ("name :  %s\n", arr[index].name) ;
        printf("ID :  %i\n", arr[index].id ) ;
        switch (arr[index].f)
        {
        case developer :
            printf("positoin : Developer \n");
            break ;
        case web :
            printf("positoin : Web Developer \n");
            break ;
        case devops :
            printf("positoin : Devops \n");
            break ;
        case embeddedSystem  :
            printf("positoin : Embedded Systems Engineer\n");
            break ;
        case  contentCreator :
            printf("positoin :  Content Creator \n");
            break ;
        case videoEditor :
            printf("positoin : Video Editor \n");
            break ;
        case dataAnalyst :
            printf("positoin : Data Analyst \n");
            break ;
        default :
            printf("position : unkown\n") ;
        }
        printf("salary : %0.2f$\n", arr[index].salary) ;
        arr[index].st == active ? printf("status : ACTIVE\n\n") :  printf("status : ON_LEAVE\n\n") ;
    }
    else
    {
        printf ("Employee not found ! try again ..\n\n") ;
    }

}

/*....................................................................................................................................................................................................................................*/

//function to display company statistics
void statistics(void)
{
    uint16_t developerCount = 0, devopsCount = 0, webCount = 0, dataAnalystCount = 0;
    uint16_t videoEditorCount = 0, contentCreatorCount = 0, embeddedSystemCount = 0;

    for (int i = 0; i < num; i++)
    {
        if (arr[i].f == developer)
        {
            developerCount++;
        }
        if (arr[i].f == devops)
        {
            devopsCount++;
        }
        if (arr[i].f == web)
        {
            webCount++;
        }
        if (arr[i].f == dataAnalyst)
        {
            dataAnalystCount++;
        }
        if (arr[i].f == videoEditor)
        {
            videoEditorCount++;
        }
        if (arr[i].f == contentCreator)
        {
            contentCreatorCount++;
        }
        if (arr[i].f == embeddedSystem)
        {
            embeddedSystemCount++;
        }
    }
    printf("\t\t___________Company Statistics___________\n\n") ;
    printf("\nDevelopers: %i", developerCount);
    printf("\t\t\tDevOps: %i\n", devopsCount);
    printf("Web Developers: %i", webCount);
    printf("\t\tData Analysts: %i\n", dataAnalystCount);
    printf("Video Editors: %i", videoEditorCount);
    printf("\t\tContent Creators: %i\n", contentCreatorCount);
    printf("Embedded Systems Engineers: %i\n\n", embeddedSystemCount);


    uint16_t activeCount = 0, onLeaveCount = 0 ;
    for (int j=0 ; j<num; j++)
    {
        switch(arr[j].st)
        {
        case active :
            activeCount ++ ;
            break ;
        case onLeave :
            onLeaveCount ++ ;
            break ;
        }
    }
    printf("Actives : %i\nON_VACATION : %i\n\n", activeCount, onLeaveCount) ;


    float32_t  totalSalary = 0,  highestSalary = 0, lowestSalary = arr[0].salary ;
    for (int i = 0 ; i< num ; i++)
    {
        totalSalary += arr[i].salary ;
        if (highestSalary < arr[i].salary)
        {
            highestSalary = arr[i].salary ;
        }
        if (lowestSalary > arr[i].salary)
        {
            lowestSalary = arr[i].salary ;
        }
    }
    printf("highestSalary : %0.2f\n", highestSalary) ;
    printf("lowestSalary : %0.2f\n",lowestSalary) ;
    printf("totalSalary : %0.2f\n\n", totalSalary) ;

}
/*....................................................................................................................................................................................................................................*/

// function to create a vacation for employee
void take_avacation (void)
{
    sint16_t  search_id , index ;
    printf ("enter the employee ID :\n") ;
    scanf ("%hd", &search_id) ;
    index = findIndexByID(search_id) ;
    if (index != -1)
    {
        printf("enter the reason of the vacation :\n") ;
        fflush(stdin) ;
        gets(&xat[index].reason);

        printf("enter the number of days off :\n") ;
        scanf("%i",&xat[index].period) ;

        printf("enter the start date of the vacation (YY-MM-DD):\n") ;
        fflush(stdin);
        gets (&xat[index].vacationStartDate);

        arr[index].salary -= arr[index].salary *12/100 * xat[index].period ;       //discount 12% on every day off
        arr[index].st = onLeave ;                                                  // change the status from active to onLeave
        printf("completed successfully \n") ;
        numOfVacations ++ ;
    }
    else
    {
        printf ("Employee not found ! try again ..\n\n") ;
    }
}

/*....................................................................................................................................................................................................................................*/

// function to deal with employees
void employeeServices (void)
{
    sint16_t  search_id, index, choice ;
    float32_t  amount = 0;
    printf ("enter the employee ID :\n") ;
    scanf ("%hd", &search_id) ;
    index = findIndexByID(search_id) ;
    if (index != -1)
    {
        printf("1. deduction\n2. bonus\n3. update salary \n");
        scanf ("%hd", &choice) ;
        switch(choice)
        {
        case 1 :
            printf("enter the amount\n") ;
            scanf("%f",&amount);
            arr[index].salary -= amount ;
            break ;
        case 2:
            printf("enter the bonus\n");
            scanf("%f",&amount);
            arr[index].salary += amount ;
            break ;
        case 3:
            printf("enter the new salary\n") ;
            scanf("%f",&amount);
            arr[index].salary = amount ;
            break ;
        default:
            printf("invalid choice !\n") ;
        }
        printf("Salary updated successfully \n") ;
    }
    else
    {
        printf ("Employee not found ! try again ..\n\n") ;
    }

}

/*....................................................................................................................................................................................................................................*/

// function to display the employee who toke a vacations
void display_vacations (void)
{
    printf("number of employees on leave <%i>\n", numOfVacations) ;
    for (int i=0 ; i<num ; i++)
    {
       if (arr[i].st == onLeave )
       {
           printf("#employee %i\n", i+1) ;
           printf("name : %s\n", arr[i].name ) ;
           printf("the reason of the vacation is : %s\n", xat[i].reason) ;
           printf("the number of days off : %i days\n", xat[i].period) ;
           printf("the start date of the vacation is : %s\n\n", xat[i].vacationStartDate) ;
       }
    }
}
