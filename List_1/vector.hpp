#include <iostream>

namespace cpplab {
template <typename T> 
class vector {
    private:

        // Vector storage capacity
        size_t capacity_;
        
        // Current - number of elements
        size_t size_;
            
        // Integer ponter - stores vector address
        T* arr;

    public:

        typedef T value_type;
            
        // Default constructor
        vector() {
            arr = new T[1];
            capacity_ = 1;
            size_ = 0;
        }

        // Destructor to dellocate storage
        // should prevent memory leak
        ~vector() {
            delete [] arr;
        }

        T &operator[](size_t index) {
            if (index<0 || index >= size_)
                std::cout<<"Vector index out of range" <<std::endl;
            return arr[index];
        }
        
        T operator[](size_t index) const {
            if (index<0 || index>= size_)
                std::cout<<"Vector index out of range" <<std::endl;
            return arr[index];
        }

        friend std::ostream &operator<<(std::ostream &os, const vector<T> &v) {
            for (size_t i=0; i<v.size_; ++i)
                os << v[i] << " ";
            return os;
        }

        // function to add elements
        void push(T data) {

            if(size_ == capacity_) {
                T* temp = new T[2 * capacity_];
                //copy
                for(size_t i = 0; i<capacity_; i++) {
                    temp[i] = arr[i];
                }
                // deleting previous array 
                delete[] arr;
                capacity_ *= 2;
                arr = temp;
            }
            // inserting data 
            arr[size_] = data;
            size_++;
        }

        // Function to add data at any index
        void push(T data, size_t index) {
            if( index == capacity_) {
                push(data);
            }
            else {
                arr[index] = data;
            }
        }    
        
        // function to extract element at provided index
        T get(size_t index) {
            if(index < size_) 
                std::cout << arr[index] << std::endl;
            else
                // throw std::logic_error("Provided index does not exist.");
                std::cout<< "Provided index does not exist."<<std::endl;
                return EXIT_SUCCESS;
        }

        // function to delete last element
        void pop() {
            size_--;
        }

        //function to get vector size
        size_t size() const {
            return size_;
        }

        //function to get vector capacity
        size_t capacity() const {
            return capacity_;
        } 

        //function to get all vector elements
        void print() {
            for (size_t i=0; i<size_; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }

    };
   
}