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
            printf("Created!!\n");
            capacity_ = 1;
            size_ = 0;
            arr = new T[1];
        }

        //Copy constructor
        vector(const vector& other) {
            printf("Copied\n");
            capacity_ = other.capacity_;
            size_ = other.size_;
            arr = new T[capacity_];
            for (size_t i = 0; i< size_; i++) {
                arr[i] = other.arr[i];
            }
        }

        //Copy operator "="
        vector& operator=(const vector& other) {
            delete[] arr;
            capacity_ = other.capacity_;
            size_ = other.size_;
            arr = new T[capacity_];
            for (size_t i = 0; i<size_; i++) {
                arr[i] = other.arr[i];
            }
            return *this;
        }
        
        //Move constructor
        vector(vector&& other) noexcept {
            printf("Moved\n");
            capacity_ = other.capacity_;
            size_ = other.size_;
            arr = other.arr;

            other.capacity_ = 0;
            other.size_ = 0;
            other.arr = nullptr;
        }
        // Move operator "="
        vector& operator=(vector&& other) noexcept {
            delete[] arr;
            capacity_ = other.capacity_;
            size = other.size_;
            arr = other.arr;

            other.capacity_ = 0;
            other.size_ = 0;
            other.arr = nullptr;
        }
        // Destructor to dellocate storage
        // Memory leak prevention
        ~vector() {
            printf("Destroyed!\n");
            delete [] arr;
        }

        T &operator[](size_t index) {
            if (index<0 || index >= size_)
                throw std::logic_error("Vector index out of range");
            return arr[index];
        }
        
        T operator[](size_t index) const {
            if (index<0 || index>= size_)
                throw std::logic_error("Vector index out of range");
            return arr[index];
        }

        // method to add elements
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

        // method to add data at any index
        void push(T data, size_t index) {
            if( index == capacity_) {
                push(data);
            }
            else {
                arr[index] = data;
            }
        }    
        
        // method to extract element at provided index
        T get(size_t index) {
            if(index < size_) 
                std::cout << arr[index] << std::endl;
            else
                throw std::logic_error("Provided index does not exist.");
                // std::cout<< "Provided index does not exist."<<std::endl;
                return EXIT_SUCCESS;
        }

        // method to delete last element
        void pop() {
            size_--;
        }

        //method to get vector size
        size_t size() const {
            return size_;
        }

        //method to get vector capacity
        size_t capacity() const {
            return capacity_;
        } 

        //method to get all vector elements
        void print() {
            for (size_t i=0; i<size_; i++) {
                printf("%i",arr[i]);
            }
            printf("\n");
        }

        // modified method for Pixel structure
        void print2() {
            for (size_t i=0; i<size_; i++) {
                std::cout << "(" << arr[i].r << ", " << arr[i].g << ", " << arr[i].b << ")" <<std::endl;
            }
            printf("\n");
        }

        template <typename... Args>
        void emplace_back(Args&&... args) {
            printf("Emplace\n");
            if (size_ == capacity_) {
                T* temp = new T[2* capacity_];
                for (size_t i=0;i<capacity_;i++) {
                    temp[i] = std::move(arr[i]);
                }
                delete[] arr;
                capacity_ *=2;
                arr = temp;
            }
            arr[size_] = T(std::forward<Args>(args)...);
            size_++;
        }

    };
}

