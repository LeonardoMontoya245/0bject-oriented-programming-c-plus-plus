#include <iostream>
#include <vector> 
#include <fstream>
#include <ctime> 

using namespace std; 


/**
 * @brief return the first index of elem if it exists, otherwise return -1
 * iterativeSearch starts at the first index and iterates sequentially to the next until it either 
 * finds the element or unitl it reaches the the end (i.e element dose not exits)
 *  
 * @param v: vector of elements 
 * @param elem : integer to look for 
 * @return int 
 */
int iterativeSearch(vector <int> v, int elem){

    for(int i = 0; i < v.size(); i++){
        
        if (v[i] == elem){ 
            return i; 
        } 
     }

    return -1; 
}

/**
 * @brief returns the index of elem, if exists in v. otherwise it return -1 
 * binarysearch is recursive (i.e funcation calls itself).
 * it utilizes the fact that v is increasing order(e.g values go up and 
 * duplicates are not allowed). 
 * 
 * it calculates the mid from the starts and end index. it compares v[mid] (i.e. value 
 * at mid) with elem and decides whether to search the left half (lower values)
 * or right half ( upper values)
 * 
 * @param v : vector of elements 
 * @param start : leftmost index (starting value is 0)
 * @param end : rightmost index  ( starting value is v.size)
 * @param elem : integer to look for 
 * @return int 
 * 
 */
int binarySearch(vector <int> & v, int start, int end, int elem){

    if (start > end){
        return -1; 
    }

int mid = (start + end) / 2; 

if (v[mid] > elem){
     
     end = mid - 1; 

} else if (v[mid] < mid){ 
    
    start = mid +1; 

} else {
    return mid; 
}
return binarySearch(v, start, end, elem); 

} 

/**
 * @brief update v to contain the values from filename (leave as is)
 * 
 * it is expected that hte files contain values ranging from one to one hundred million in ascending order ( no duplicates). 
 * @param fileanme : string 
 * @param v : vector 
 * 
 */ 
void vecGen(string filename, vector <int> & v){

    ifstream file(filename);
    int num; 
    v.clear(); 
    while (file.is_open() && file >> num){

        v.push_back(num); 
    }
   file.close(); 
}

int main(){
    // populate v with 10000 sorted numbers (leaves as is)
    vector <int> v;
    vecGen("10000_numbers.csv", v); 

    // test elements to search for (leave as is)
    vector <int> elem_to_find; 
    vecGen("test_elem.csv", elem_to_find); 

    // read through all 10 of the test_elem vales and calls itreatives search 
    // and records how long each search took (leave as is)
    for (int i = 0; i < elem_to_find.size(); i++ ){
        // gets the elem to search for 
        int elem = elem_to_find[i];  

        // stopwatchs the time 
        clock_t start = clock(); 
        int index_if_found = iterativeSearch(v, elem); 
        clock_t end = clock(); 

        // calculate the total time it took in seconds 
        double elapsed_time_in_sec = (double (end - start)/CLOCKS_PER_SEC); 

        // prints the index and how long it took to find it 
        cout << index_if_found << ": " << elapsed_time_in_sec << endl; 

    }
    // repeat the for loop 
    for (int i = 0; i < elem_to_find.size(); i++ ){
        // gets the elem to search for 
        int elem = elem_to_find[i];  

        // stopwatchs the time 
        clock_t start = clock(); 
        int index_if_found = binarySearch(v, 0, v.size() -1,  elem); 
        clock_t end = clock(); 

        // calculate the total time it took in seconds 
        double elapsed_time_in_sec = (double (end - start)/CLOCKS_PER_SEC); 

        // prints the index and how long it took to find it 
        cout << index_if_found << ": " << elapsed_time_in_sec << endl;  
}
} 