#include <iostream>

namespace cpplab {
template <typename T> 
class vector {
    private:

        // Vector storage capacity
        int capacity;
        
        // Current - number of elements
        int current;
            
        // Integer ponter - stores vector address
        T* arr;

    public:

        typedef T value_type;
            
        // Default constructor
        vector() {
            arr = new T[1];
            capacity = 1;
            current = 0;
        }

        // Destructor to dellocate storage
        // prevents memory leak
        ~vector() {
            delete [] arr;
        }

        // function to add elements
        void push(T data) {

            if(current == capacity) {
                T* temp = new T[2 * capacity];
                //copy 
                for(int i = 0; i<capacity; i++) {
                    temp[i] = arr[i];
                }
                // deleting previous array 
                delete[] arr;
                capacity *= 2;
                arr = temp;
            }
            // inserting data 
            arr[current] = data;
            current++;
        }

        // Function to add data at any index
        void push(T data, int index) {
            if( index == capacity) {
                push(data);
            }
            else {
                arr[index] = data;
            }
        }    
        
        // function to extract alement at provided index
        T get(int index) {
            if(index < current) 
                return arr[index];
            else
                return 0;
        }

        // function to delete last element
        void pop() {
            current--;
        }

        //function to get vector size
        int size() {
            return current;
        }

        //function to get vector capacity
        int getcapacity() {
            return capacity;
        } 

        //function to get all vector elements
        void print() {
            for (int i=0; i<current; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
    };
}