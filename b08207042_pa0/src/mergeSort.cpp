// **************************************************************************
// File       [mergeSort.cpp]
// Author     [Deitel How to program C++, 5ed. Ch 20, Fig. 20.06]
// Synopsis   [The implementation of the MergeSort Class]
// Modify     [2010/02/21 CM Li]
// **************************************************************************
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cstdlib> // prototypes for functions srand and rand
using std::rand;
using std::srand;

#include <ctime> // prototype for function time
using std::time;

#include "mergeSort.h" // class MergeSort definition

// constructor: fill vector with input_file
MergeSort::MergeSort(std::ifstream& input_file)
{
	//TODO  read input file 
  //hint: you can use the getline() function or stream operator to handle the input
	std::string line;
	MergeSort::size=0;
	while(std::getline(input_file, line)){
		size_t note=line.find_first_of('#');
		if(note!=std::string::npos) line.erase(note);
		if(line.empty()) continue;
		//printf("%d\n", stoi(line.substr(line.find_first_of(' ')+1)));
		MergeSort::data.push_back(stoi(line.substr(line.find_first_of(' ')+1)));
		MergeSort::size++;
	}

} // end MergeSort constructor  

// split vector, sort subvectors and merge subvectors into sorted vector
void MergeSort::sort()
{
  sortSubVector( 0, size - 1 ); // recursively sort entire vector
} // end function sort

// recursive function to sort subvectors                
void MergeSort::sortSubVector( int low, int high )
{                                                 
  // test base case; size of vector equals 1
  if ( ( high - low ) >= 1 ) // if not base case
    {
      // int middle1;  // calculate middle of vector
      // int middle2;  // calculate next element over
      int middle1;  // calculate middle of vector, (1+2)/2 = 1.
      int middle2;  // calculate next element over, (1+2)/2+1 = 2.
      /*TODO : assign middle1 and middle2
      middle1 = ???;
      middle2 = ???;
      */

      middle1=(low+high)/2;
      middle2=middle1+1;
      // output split step 
	  
     #ifdef _DEBUG_ON_	  
      cout << "split:   ";                                          
      displaySubVector( low, high );                                 
      cout << endl << "         ";                                  
      displaySubVector( low, middle1 );                              
      cout << endl << "         ";                                  
      displaySubVector( middle2, high );                             
      cout << endl << endl;                                         
	  #endif

      /*TODO : recursive function call to split vector in half; sort each half (recursive calls)
        ???               // first half of vector      
        ???               // second half of vector    
      */
      sortSubVector(low, middle1);
      sortSubVector(middle2, high);

      // merge two sorted vectors after split calls return
      merge( low, middle1, middle2, high );
   } // end if
} // end function sortSubVector

// merge two sorted subvectors into one sorted subvector
void MergeSort::merge( int left, int middle1, int middle2, int right ) 
{
  int leftIndex = left; // index into left subvector              
  int rightIndex = middle2; // index into right subvector         
  int combinedIndex = left; // index into temporary working vector
  vector< int > combined; // working vector              

  // output two subvectors before merging
  #ifdef _DEBUG_ON_
  cout << "merge:   ";                  
  displaySubVector( left, middle1 );     
  cout << endl << "         ";          
  displaySubVector( middle2, right );    
  cout << endl;  
  #endif
      
  /*TODO : merge vectors until reaching end of either
  while ( leftIndex <= middle1 && rightIndex <= right )
    {
      // place smaller of two current elements into result
      // and move to next space in vector
      ???
    } // end while
  
  if ( leftIndex == middle2 ) // if at end of left vector          
    {                                                               
      // copy in rest of right vector
      ???
    } // end if                                                     
  else // at end of right vector                                   
    {                                                               
       // copy in rest of left vector
      ???
    } // end else
  */

  combined.resize(MergeSort::size); 
  while(leftIndex<=middle1 && rightIndex<=right){
	  //printf("leftID:%d rightID:%d combined:%d middle1:%d right:%d\n", leftIndex, rightIndex, combinedIndex, middle1, right);
	  if(data[leftIndex]<=data[rightIndex]){
		  combined[combinedIndex]=data[leftIndex];
		  leftIndex++;
	  }
  else{
		  combined[combinedIndex]=data[rightIndex];
		  rightIndex++;
	  }
	  combinedIndex++;
  }

  if(leftIndex==middle2){
	  //printf("leftID:%d rightID:%d combined:%d middle2:%d\n", leftIndex, rightIndex, combinedIndex, middle2);
	  while(rightIndex<=right){
		  combined[combinedIndex]=data[rightIndex];
		  rightIndex++;
		  combinedIndex++;
	  }
  }
  else{
	  //printf("leftID:%d rightID:%d combined:%d\n", leftIndex, rightIndex, combinedIndex);
	  while(leftIndex<=middle1){
		  combined[combinedIndex]=data[leftIndex];
		  leftIndex++;
		  combinedIndex++;
	  }
  }

  /*TODO : copy values back into original vector
      ???
  */
  int i;
  for(i=left;i<=right;i++) data[i]=combined[i];
  
  // output merged vector         
  #ifdef _DEBUG_ON_
  cout << "         ";            
  displaySubVector( left, right );
  cout << endl << endl;           
  #endif
} // end function merge

// display elements in vector
void MergeSort::displayElements() const
{
  displaySubVector( 0, size - 1 );
  cout<<endl;
} // end function displayElements

// put the value of data array in the file_out
void MergeSort::displayResult(std::fstream& file_out) const
{
  // Warning: do not modify this function 
  cout<<"Output result.";
  for(int i = 0 ; i < size ; i++){
    file_out<<data[i]<<" ";
  }
  file_out<<endl;
} // end function displayResult

// display certain values in vector
void MergeSort::displaySubVector( int low, int high ) const
{
  // output spaces for alignment
  for ( int i = 0; i < low; i++ )
    cout << "   ";
  // output elements left in vector
  for ( int i = low; i <= high; i++ )
    cout << " " << data[ i ];
} // end function displaySubVector

