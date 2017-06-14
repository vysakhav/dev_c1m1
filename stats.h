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
 * @file stats.h
 * @brief Header file for for the statistics application.
 *
 * @Description:
 *     - This application is used to perform statistical analytics on a given dataset.
 *     - This application provides APIs to find max,min,mean,median and display the 
 *       statistical values computed.
 *
 * @author Vysakh A V
 * @date 06-14-2017
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

#include <math.h>

/**
 * @brief Print statistics of the given data set including min, max,mean and median values.
 * 
 * This function takes input as max,min,mean and median value as unsigned char. Function 
 * will print all the statistics details on the screen.
 *
 * @param max An unsigned char as maximum element of the array.
 * @param min An unsigned char as minimum element of the array.
 * @param mean An unsigned char as mean element of the array
 * @param median An unsigned char as median element of the array
 *
 * @return Nothing
 */
void print_statistics (unsigned char max, unsigned char min, unsigned char mean, unsigned char median);

/**
 * @bried Print the elements of the given array into the screen.
 * 
 * @This function takes input as the given array and an unsigned integer as size of the array. Function
 * will print the elements of the array to the screen.
 *
 * @param array An unsigned char points to the given array of data elements/
 * @param size  An unsigned integer points to the size of the array.
 *
 */
void print_array (unsigned char array [], int size);

/**
 * @brief This function used to find the median value.
 * 
 * @This function takes input as an unsigned char pointer to an n-element data array and an unsigned 
 * integer as the size of the array. Function computes the median value and return the result.
 * 
 * @param array An unsigned char points to the given array of data elements/
 * @param size  An unsigned integer points to the size of the array.
 *
 * @Return : An unsigned char result from the function.
 */
unsigned char find_median (unsigned char array [], int size);

/**
 * @brief This function used to find the mean value.
 * 
 * @This function takes input as an unsigned char pointer to an n-element data array and an unsigned 
 * integer as the size of the array. Function computes the mean value from the given data set and returned the value.
 * 
 * @param array An unsigned char points to the given array of data elements.
 * @param size  An unsigned integer points to the size of the array.
 *
 * @Return : An unsigned char result from the function.
 */
unsigned char find_mean (unsigned char array [], int size);

/**
 * @brief This function used to find the maximum value.
 * 
 * @This function takes input as an unsigned char pointer to an n-element data array and an unsigned 
 * integer as the size of the array. Function computes the maximum value from the given data set and returned the value.
 * 
 * @param array An unsigned char points to the given array of data elements.
 * @param size  An unsigned integer points to the size of the array.
 *
 * @Return : An unsigned char result from the function.
 */
unsigned char find_maximum (unsigned char [], int);

/**
 * @brief This function used to find the minimum value.
 * 
 * @This function takes input as an unsigned char pointer to an n-element data array and an unsigned 
 * integer as the size of the array. Function computes the minimum value from the given data set and returned the value.
 * 
 * @param array An unsigned char points to the given array of data elements.
 * @param size  An unsigned integer points to the size of the array.
 *
 * @Return : An unsigned char result from the function.
 */
unsigned char find_minimum (unsigned char [], int);

/**
 * @brief This function used to sort the array.
 * 
 * @This function takes input as an unsigned char pointer to an n-element data array and unsigned integer as the size of the array.
 * Function will sort the array from smallest to largest.
 *
 * @param array An unsigned char points to the given array of data elements.
 * @param size  An unsigned integer points to the size of the array.
 *
 *
 * @Return Nothing.
 */
void sort_array (unsigned char [] , int);

#endif /* __STATS_H__ */
