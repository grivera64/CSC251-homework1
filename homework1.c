/*
Program Name: homework1.c
Purpose: To determine the value of
the trancendental constant number e (euler)
Author: Giovanni Rivera
Date: 02/17/2021 (Spring 2021)

Current Lesson: Lecture 1 - Lecture 5
Used: printf, scanf, variables, loops, switch, exit
*/

//adding standard libraries
#include <stdio.h>
#include <stdlib.h>

//main function  (entry point)
int main(void)
{
    //declaring local variables
    long double eulerEstimate = 1.0;
    int userNum = 0;
    char placeHolder[20];                   //this will placehold invalid values

    //ask for integer from user
    while(userNum == 0)                     //loops until a valid integer is
    {                                       //inputted

        //Request from the user for an integer to calculate euler up to
        printf("Please enter a non-negative integer, which will be the term\n");
        printf("you want to perform summation up to to find euler (e):\n>> ");

        int worked = scanf("%d", &userNum); //checking if the scanner
                                            //worked (returns 1 for TRUE)

        if (worked && userNum >= 0)         //worked != 0 constitutes true
        {
            
            //Calculate the euler eulerEstimate
            printf("\nCalculating...\n\n"); //pinging user to let them know
                                            //the program didn't crash
            break;                          //stop loops
            
        }
        else if (worked)                    //if the input was an invalid %d type
        {                                   //(i.e. int, long, etc.)
            
            printf("\nInput is not supported.\n");
            printf("Please try again...\n\n");

            userNum = 0;                    //make the program loop again
        
        }
        else                                //if its a different data type
        {
        
            printf("Input is not an integer. Please try again...\n\n");

            userNum = 0;                    //make the program loop again
            scanf("%s", placeHolder);       //removes from the queue of improper
                                            //input
        
        }
    }

    //storing the denominator n! as a variable (1! = 1)
    double long denominator = 1;

    //going  through each of the requested terms if not 0
    if (userNum > 0)
    {
        
        for (int term = 1; term <= userNum; term++)
        {
            
            if (term % 50000000 == 0)       //tell the user that the
            {                               //program is
                                            //still calculating
                
                printf("\nStill calculating...\n\n");
                
            }
            
            denominator *= term;            //finds n! = n-1! * n

            // adds 1/n! to the euler estimate per term after 1
            eulerEstimate += (1.0) / (denominator);
            
        }
        
    }
    else
    {
        
        eulerEstimate = 0;
    
    }


    //Display to user the eulerEstimate (encompassed in-between the ****'s
    //*******************************************************
    printf("The estimate of euler to the %d", userNum);

    //adds st, nd, rd, th to the end of the statement based
    //on the number of terms (i.e. 1st, 2nd, 3rd, 4th)
    switch (userNum)
    {
            
        case 11:
        case 12:
        case 13:
            
            printf("th ");
            break;
            
        default:
            
            if (userNum % 10 == 1)          //i.e. 21st, 31st, 41st
            {
                
                printf("st ");
                
            }
            else if (userNum % 10 == 2)     //i.e. 22nd, 32nd, 42nd
            {
                
                printf("nd ");
                
            }
            else if (userNum % 10 == 3)     //i.e. 23rd, 33rd, 43rd
            {
                
                printf("rd ");
                
            }
            else                            //i.e. 25th, 38th, 50th
            {
                
                printf("th ");
            
            }
            
            break;
            
    }

    printf("term is %Lf\n", eulerEstimate); //up to 6 decimal places

    //*********************************************************

    //terminate program
    printf("\nProgram terminated!\n\n");



    return 0;
}
