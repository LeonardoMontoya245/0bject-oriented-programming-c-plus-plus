#include <iostream> 
#include <vector> 

using namespace std; 

/**
 * @brief prints the element in the vector and their memory location 
 * 
 * @param v - vector of integers 
 * 
 */
void printMemVec(const vector <int> v){
  printf("vector - each int is worth %lu bytes\n,", sizeof(int)); 
    for (int i = 0; i < v.size(); i++){
        printf("value : %i at Memory Location: %p\n", v[i], & v[i]);   
    }

} 
/**
 * @brief increments all of the elements in v by 10 
 * 
 * @param v - address to a vector of integers 
 */
void incVecBy10(vector <int> v){

    for(int i = 0; i < v.size(); i++){
        v[i] += 10; 
    }

} 
int main(){

    vector <int> vec; 
    const int SIZE = 5; 
    //int vec[5]; 
    for(int i = 0; i < SIZE; i++){
        //vec[i] = 100 + i; 
        vec.push_back(100+i); 
    } 
    printf("Before Increment-------------\n"); 
    printMemVec(vec);   
    incVecBy10(vec); 
    printf("After Increment--------------\n"); 
    printMemVec(vec); 
    
    vec.pop_back(); 
    printf("After pop--------------\n"); 
    printMemVec(vec); 

    vec.push_back(101); 
    vec.push_back(102); 
    printf("After push_back--------------\n"); 
    printMemVec(vec); 
    
    return 0; 

}