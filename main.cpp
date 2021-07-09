/*
Author: April Miller
Description: File will be a binary file containing the 10 numbers (from 1 to 10) each as an int, followed by the square roots of those numbers each as a double.
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
	
  //Constant for name of array
	const string fileName = "array.dat";
	
  //output stream
	ofstream data_file(fileName, ios::binary | ios::out);
	
  //Close file and exit program if file could not be found.
	if(!data_file) 
	{
		data_file.close();
		cout << "Error. File could not be opened." << endl;
		exit(1) ;
	}
	
  //write numbers 1-10 stored as binary numbers
	for(int i = 1; i <= 10; i++) 
	{
		data_file.write(reinterpret_cast <char *>(&i), sizeof(int));  
  }
	
	double sqrtNum;
	
  //Get square root of numbers, store in double variable, write to file.
	for(double i = 1; i <= 10; i++) 
	{
		sqrtNum = sqrt(i);
		data_file.write(reinterpret_cast <char *>(&sqrtNum), sizeof(double));  
    }
	
	cout << "Data has been written to the file." << endl;
	
  //Close file
	data_file.close();
	return 0;
}
