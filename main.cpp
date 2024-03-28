#include <iostream> 
#include <fstream> 
using namespace std; 

/**
 * @brief  writes sample_size number of integers 
 * example output : if n = 3 and arr = [1,2,3]
 * 1
 * 2
 * 3
 * 
 * @param filename 
 * @param arr 
 * @param sample_size 
 * 
 */ 
void writeToFile(string filename, int * arr, int sample_size ){

    ofstream file (filename); 
     

    for(int i = 0; i < sample_size; i++ ){
        file << arr[i]; 
        file << "\n"; 
    }
    file.close(); 
    printf("Wrote to %s\n", filename.c_str()); 
} 
/**
 * @brief  writes sample_size number of strings 
 * example output : if n = 2 and arr = ["cat", "dog"]
 * cat 
 * dog 
 * @param filename 
 * @param arr 
 * @param sample_size 
 * 
 */
void writeToFile(string filename, string * arr, int sample_size){

    ofstream file(filename); 
     

    for(int i = 0; i < sample_size; i++){

        file << arr[i]; 
        file << "\n"; 

    }
    file.close(); 
    printf("Wrote to %s\n", filename.c_str()); 
    
} 
/**
 * @brief writes sample_size number of char 
 * example output: if n = 2 and arr = ["c","d"]
 * c 
 * d 
 * @param filename 
 * @param arr 
 * @param sample_size 
 */
void writeToFile(string filename, char * arr, int sample_size){

    ofstream file(filename); 
    

    for(int i = 0; i < sample_size; i++){

        file << arr[i]; 
        file << "\n"; 
    }
    file.close(); 
    printf("Wrote to %s\n", filename.c_str()); 
} 
/**
 * @brief read the content of any file 
 * 
 * @param filename 
 */
void readFile(string filename){

    ifstream file(filename); 
    string line; 

    while(!file.eof()){
        file >> line; 
        printf("%s\n", line.c_str()); 

    }
    cout << "end of the loop" << endl; 
} 

int main () {
    const int SAMPLE_SIZE = 10; 
    int array_int[SAMPLE_SIZE] = {1,2,3,4,5,6,7,8,9,10}; 
    string array_str[SAMPLE_SIZE] = {"this", "is", "sentence.", "this", "is", "another", "sentence", "the", "end"};
    char array_char[SAMPLE_SIZE] = {'a', 'b', 'c', 'd', 'e', '0', '1', '2', '3', '4'}; 

    string int_file = "array_int.csv"; 
    writeToFile(int_file, array_int, SAMPLE_SIZE); 

    string char_file = "array_char.csv"; 
    writeToFile(char_file, array_char, SAMPLE_SIZE); 

    string string_file = "array_string.csv";
    writeToFile(string_file, array_str, SAMPLE_SIZE); 

    //string str = "array_str.csv"; 

    //writeToFile(str, array_str, SAMPLE_SIZE); 

    //string character = "array_char.csv"; 

    //writeToFile(character, array_char, SAMPLE_SIZE); 

    readFile(int_file); 
    readFile(char_file); 
    readFile(string_file); 

    return 0; 


}