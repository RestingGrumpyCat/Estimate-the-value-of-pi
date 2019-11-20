#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


/****************************************** I HATE THIS ONE * _ * **************************************************/

/**This program takes user input to run a function which estimates the value of Pi ENOUGH times so the value
 * is so close to pi's original value
 *
 *Student Name:   Shiyu Wang
 *Student number: 250890597
 *
 **/

 /****************************************** I HATE THIS ONE * _ * **************************************************/

//the function that operates to estimate the value of Pi
double estimate_pi(long long n){

    //use num to count how many points fall into the quadrant
    int num = 0, i;

    //use pi to store the value after operation
    double pi;



    //use loop to generate random numbers
    for(i = 0; i < n; i++){

        //generate random numbers x and y
        double y = (double)rand()/RAND_MAX;
        double x = (double)rand()/RAND_MAX;


        //compute the value to check if the point is inside the quadrant
        double product = x*x + y*y;
        if(product <= 1) {

            //if the point is inside the quadrant, increment num by 1
            num++;
        }
    }


    //finally compute the pi value
    pi = (double)num/(double)n *(double)4;


    return pi;
}

int main() {

    //initialize counters and user input
    int counter = 10, i;

    long long N;

    //initialize variables used for computing the mean and standard deviation
    double mean, sdv, result, sum1 = 0, sum2 = 0, adder = 0;

    //initialize an array with the size of counter
    double array[counter];


    //use time function to generate a varying seed value every time
    srand(time(NULL));

    //get user input using printf and scanf
    printf("\nWanna estimate Pi? \n");
    printf("I know you don't but just give me a positive integer: \n");

    //check if the input is string, exit if it is string
    if(scanf(" %ld", &N) != 1){
        printf("Whoopsy, told you it has to be an integer. Now you have to run the program again :)\n", N);
        exit(1);
    }

    //and check if the input is negative, exit if negative
    else if( N <= 0 ){
        printf("Whoopsy, told you it has to be a positive integer. Now you have to run the program again :)\n", N);
        exit(2);
    }

    //estimate the pi value ten times using a loop
    for(i=0; i < counter; i++) {


        //store the return value of function in result
        result = estimate_pi(N);

        //appending each estimated pi value into array, so we can calculate mean and sd later
        array[i] = result;

        //add every estimate pi value together to compute mean
        sum1 = sum1 + result;

        //print the pi value with ten digits
        printf("%d: The estimated Pi value is %.10f\n", i+1, result);

    }

    //compute mean
    mean = sum1 / counter;


    //loop through array to compute standard deviation
    for(i=0; i < sizeof(array)/sizeof(array[0]); i++){

        adder = (array[i]- mean)*(array[i]- mean);
        sum2 = sum2 + adder;

    }

    sdv = sqrt(sum2/ counter);


    //finally print mean and sd with ten digits
    printf("\n\nThe standard deviation of the estimated Pi values is %.10f\n", sdv);
    printf("\nThe mean of the estimated Pi values is %.10f\n", mean);

    return 0;
}
