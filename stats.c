/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief This file used to find calculation on the given data set and provide statistics on it.
 *
 * This is the main driver application and which accepts an unsigned char array and the length of the array.
 * Form main () we have invoked the APIs to calculate max,min,mean,median values from the array and display 
 * the statistics on the screen. This file contains all the implementation of functions declared in stats.h.
 *
 * @author Vysakh A V
 * @date 06-14-2017
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  //Varaibale declaration to store different values.
  unsigned char max_value    = 0;
  unsigned char min_value    = 0;
  unsigned char mean_value   = 0;
  unsigned char median_value = 0;

  //Find Maximum element in the array.
  max_value = find_maximum (test, SIZE);

  //Find Minimum element in the array.
  min_value = find_minimum (test, SIZE);

  //Find Mean value in the array.
  mean_value = find_mean (test, SIZE);

  //Find Median value in the array.
  median_value = find_median (test, SIZE);

  //Print statistics values.
  print_statistics (max_value, min_value, mean_value, median_value);

  return 0;
}

/* Implementation of find_maximum. */
unsigned char find_maximum (unsigned char test [], int size) {

  unsigned char max;
  int counter;

  max = test [0];
  for ( counter = 1 ; counter < size ; ++ counter ){
    if (max < test [counter]){
    max = test [counter];
    }
  }

  return max;
}

//Implementation of find_minimum.
unsigned char find_minimum (unsigned char test [], int size){
  unsigned char min;
  int counter;

  min = test[0];
  for ( counter = 1; counter < size ; ++ counter ){
    if ( min > test [counter])
    min = test [counter];
  }

  return min;
}

//Implementation of find_mean.
unsigned char find_mean (unsigned char arr [], int size){

  float sum = 0.0;
  int icnt;
  int mean_val = 0;
    
  for (icnt = 0; icnt < size; ++icnt){
    sum += arr [icnt];
  }  

  //mean_val = round (sum / size);
  mean_val = sum / size;
  return (unsigned char)mean_val;
}

//Implementation of find_median.
unsigned char find_median (unsigned char arr [], int size){

  float median = 0.0;
  int icnt;

  //First we need to sort the array to find median. So calling sort_array function here.
  sort_array (arr, size);

  //Find median.
  if ( size % 2 == 0 ) {
    //If even number of elements in the array, use mean of the 2 elements in the middle of the array.
    // median = round ((arr [size / 2] + arr [size / 2 - 1]) / 2.0);
    median = (arr [size / 2] + arr [size / 2 - 1]) / 2.0;
  }else {
     //odd number of elements.
     //median = round ((arr [size / 2] + 1 ));
     median = (arr [size / 2] + 1 );
  }

  return (unsigned char)median;
}

//Implementation of sort_array.
void sort_array (unsigned char array [], int size){

  unsigned char temp;
  int icnt;
  int jcnt;

  for (icnt = 0 ; icnt < size - 1; ++ icnt){
    for ( jcnt = icnt + 1; jcnt < size ; ++ jcnt){
      if ( array [icnt] < array [jcnt] ){
        temp = array [icnt];
        array [icnt] = array [jcnt];
        array [jcnt] = temp;
      }
    }
  }
}

//Implementation of print_array.
void print_array (unsigned char arr [], int size){
  int icnt;
  printf ("\nThe elements of the array is:\n");
  printf ("===============================\n");
    
  for ( icnt = 0; icnt < size; ++icnt){
    printf ("%u, ", arr[icnt]);
  }
  printf ("\n===============================\n");
}

//Implementation fo print_statistics.
void print_statistics (unsigned char max, unsigned char min, unsigned char mean, unsigned char median){
  printf ("\n=====================Statistics on the data set============================\n");
  printf ("\t\t Maximum value = %u\n", max);
  printf ("\t\t Minumum value = %u\n", min);
  printf ("\t\t    Mean value = %u\n", mean);
  printf ("\t\t  Median value = %u\n", median);
  printf ("============================================================================\n");
}
