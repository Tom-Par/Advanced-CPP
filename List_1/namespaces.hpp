#include <iostream>

namespace cpplab {
template <typename T> 
class vector {
    private:

        // Vector storage capacity
        int capacity;
        
        // Current - number of elements
        int size;
            
        // Integer ponter - stores vector address
        T* arr;

    public:

        typedef T value_type;
            
        // Default constructor
        vector() {
            arr = new T[1];
            capacity = 1;
            size = 0;
        }

        // Destructor to dellocate storage
        // should prevent memory leak
        ~vector() {
            delete [] arr;
        }

        // function to add elements
        void push(T data) {

            if(size == capacity) {
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
            arr[size] = data;
            size++;
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
            if(index < size) 
                std::cout << arr[index] << std::endl;
            else
                throw std::logic_error("Provided index does not exist.");
                return EXIT_SUCCESS;
        }

        // function to delete last element
        void pop() {
            size--;
        }

        //function to get vector size
        int get_size() {
            return size;
        }

        //function to get vector capacity
        int get_capacity() {
            return capacity;
        } 

        //function to get all vector elements
        void print() {
            for (int i=0; i<size; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }


    };
    //TODO
    template <typename T, typename T2>
    auto operator*(T const &a, T2 const &b) -> decltype(a[0] * b[0]) {
        if(a.size() != b.size()) {
           throw std::logic_error("Both sizes should me equal");
        }
        auto result = a[0] * b[0];
        for (int i =0; i< a.size(); i++)
        {
            result += a[i] * b[i];
        }
        return result;
    }
}