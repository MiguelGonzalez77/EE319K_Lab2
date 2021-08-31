// ****************** Lab2.c ***************
// Program written by: Miguel Gonzalez
// Date Created: 1/18/2017 
// Last Modified: 1/17/2021 
// Put your name and EID in the next two line
char Name[] = "Miguel Gonzalez";
char EID[] = "mag9688";
// Brief description of the Lab: 
// An embedded system is capturing temperature data from a
// sensor and performing analysis on the captured data.
// The controller part of the system is periodically capturing size
// readings of the temperature sensor. Your task is to write three
// analysis routines to help the controller perform its function
//   The three analysis subroutines are:
//    1. Calculate the mean of the temperature readings 
//       rounded down to the nearest integer
//    2. Convert from Centigrate to Farenheit using integer math 
//    3. Check if the captured readings are a non-increasing monotonic series
//       This simply means that the readings are sorted in non-increasing order.
//       We do not say "decreasing" because it is possible for consecutive values
//       to be the same, hence the term "non-increasing". The controller performs 
//       some remedial operation and the desired effect of the operation is to 
//       raise the the temperature of the sensed system. This routine helps 
//       verify whether this has indeed happened
#include <stdint.h> // The C99 standard to declare for this file.
#define True 1 // This is a literal to define true as 1
#define False 0 // this is a literal to define false as 0

// Return the computed Mean
// Inputs: Data is an array of 16-bit unsigned distance measurements
//         N is the number of elements in the array
// Output: Average of the data
// Notes: you do not need to implement rounding
uint16_t Average(const uint16_t Data[],const uint32_t N){
// Replace this following line with your solution
		uint16_t avg = 0; // initialize avg to 0
	  for(uint16_t i = 0; i < N; i++){ // for loop to compute average from each ith element in the array until i < N.
			avg += Data[i];   // avg = avg + Data[i], where i is the ith element of the array    
		}
		avg /= N; // avg = avg / N, after for loop condition fails, then avg is then divided by N.
    return avg; // return the value avg
}

// Convert temperature in Farenheit to temperature in Centigrade
// Inputs: temperature in Farenheit 
// Output: temperature in Centigrade
// Notes: you do not need to implement rounding
int16_t FtoC(int16_t const TinF){
// Replace this following line with your solution
  int TinC = TinF - 32; // calculate the integer of TinF - 32 and initialize to TinC variable.
	TinC *= 5; // TinC = TinC * 5
	TinC /= 9; // TinC = TinC / 9
	return TinC; // returns the value of TinC after converting Farenheit to Centigrade.
}
	
	
// Return True of False based on whether the readings
// are an increasing monotonic series
// Inputs: Readings is an array of 16-bit distance measurements
//         N is the number of elements in the array
// Output: true if monotonic increasing, false if nonmonotonic
int IsMonotonic(uint16_t const Data[], int32_t const N){
// Replace this following line with your solution
	for(int i = 0; i < N - 1; i++){ // for loop that determines if the series is monotonic or nonmonotonic.
		if(Data[i] > Data[i+1]){ // conditonal statement stating if it is a non-increasing monotonic series.
			return False; // returns a False or 0 if the condition is met.
		}
	}
  return True; // else returns a True or a 1 if the condition is not met.
}




