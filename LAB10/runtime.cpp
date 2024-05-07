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
/**
 * @brief writes to file the time it took to search with respect to the
 *  size of the vecor, n
 * Number of elements (n)         time (n)
 *                                 X.XXXXX
 *  XXXX                           X.XXXXX
 *  XXXX 
 * 
 * @param filename (string) : filename (e.g. output_1000_numbers.csv)
 * @param times (vector <double>) : anverage time 
 * @param n (vector<int>) : size of vectors 
 * 
 */
void writeTime(string filename, const vector <double> time, const vector<int> n){

    ofstream myFile(filename); 

    myFile << "Number of Elements (n)\t Time (sec)" << endl; 
    for(int i = 0; i < time.size(); i++){

        myFile << n[i] << "\t" << time[i] << "\n"; 
    } 
    myFile.close();
    cout << "wrote to " << filename << endl; 
} 
/**
 * @brief computes the average of the element in vector, a
 * 
 * @param a vector of double 
 * @return double 
 */ 
double average(const vector<double> a){

    double sum = 0; 

    for(int i = 0; i < a.size(); i++){

        sum = sum + a[i]; 
    } 
    return sum / a.size(); 
}
int main(){
    // test elemtn to search for 
    vector <int> elem_to_find; 
    vecGen("test_elem.csv", elem_to_find); 

    // size (n) of all tests 
    vector<int> file_sizes; 
    vecGen("sizes.csv", file_sizes); 

    //n list of numbers 
    vector<int> v; 

    // results of time 
    vector<double> times; 

    // results of time 
    vector <double> avg; 

    // create a for loop to iterate through the file size
        for(int i = 0; i < file_sizes.size(); i++){
            // get the name/size of the file and assign it to string called filename
           string filename = to_string(file_sizes[i]) + "_numbers (1).csv"; 
            // call vecGen on filename and v 
            vecGen(filename, v); 
            // print filename (this will be good for debugging)
            cout << filename << endl; 
            // call times.clear() // this ensures that we reset time everytime we read a new file 
            times.clear();

        
        // create another for loop to iterate through all the element from elem_to_find.
        // the code here should be nearly identical to the code from the pervious lab 
        for(int i = 0; i < elem_to_find.size(); i++){

            int elem = elem_to_find[i]; 

            clock_t start = clock(); 

            int index_if_found = iterativeSearch(v, elem); 

            clock_t end = clock(); 

            double elapsed_time_in_sec = (double (end - start)/CLOCKS_PER_SEC);

            times.push_back(elapsed_time_in_sec);
        }
        //call average on the vector, time, and save it as a double. this code should be 
        // out side the for loop that iterates through all the element from elem_to_find
        // but within the for loop that iterates throght the file size  
        
        double average_time = average(times); 
        
        
        

        // append the double to avg. (hint: push_back()) 
        // this code ahould be outside the for loop that iterates through 
        // all the elements from elem_to_find 
        // but within the for loop that iterates throgh the files sizes
        avg.push_back(average_time); 
    
    }

    // outside both for loops call writeTime with the appropriate parameters 
    // the first parameter should be "iterativeSearch_time.csv" 
    // read the funcation brief to complete the rest of the parameters 
    writeTime("iterativeSearch_time.csv", avg, file_sizes);

    // call avg.clear() to rest avg, so we can use it for binarySearch
    avg.clear(); 

    // repeat the nested for loops used for itrativeSerch, but call binarySearch instead 

    for(int i = 0; i < elem_to_find.size(); i++){

            int elem = elem_to_find[i]; 

            clock_t start = clock(); 

            int index_if_found = binarySearch(v, 0, v.size(), elem); 

            clock_t end = clock(); 

            double elapsed_time_in_sec = (double (end - start)/CLOCKS_PER_SEC);

            times.push_back(elapsed_time_in_sec); 
            
        //call average on the vector, time, and save it as a double. this code should be 
        // out side the for loop that iterates through all the element from elem_to_find
        // but within the for loop that iterates throght the file size 
        double avg_time_binary = average(times); 

        // append the double to avg. (hint: push_back()) 
        // this code ahould be outside the for loop that iterates through 
        // all the elements from elem_to_find 
        // but within the for loop that iterates throgh the files sizes
        avg.push_back(avg_time_binary); 
    }

    // outside both for loops call writeTime with the appropriate parameters
    // the first parameter ahould be "BinarySearch_time.csv"
    // read the funcation brief to complete the rest of the paramters 
    writeTime("binarySearch_time.csv", avg, file_sizes);  

    


}


     

   


        
