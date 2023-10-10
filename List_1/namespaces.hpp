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
        
        // function to extract element at provided index
        T get(int index) {
            if(index < current) 
                std::cout << arr[index] << std::endl;
            else
                std::cout << "Provided index does not exist." << std::endl;
                return EXIT_SUCCESS;
        }

        // function to delete last element
        void pop() {
            current--;
        }

        //function to get vector size
        int get_size() {
            return current;
        }

        //function to get vector capacity
        int get_capacity() {
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
        template <typename T>
    T operator*(const vector<T>& v1, const std::vector<T>& v2) {
        if (v1.get_size() != v2.size()) {
            throw std::invalid_argument("Vectors must have the same number of elements for dot product.");
        }

        T result = 0;
        for (int i = 0; i < v1.get_size(); i++) {
            result += v1[i] * v2[i];
        }

        return result;
    }
}