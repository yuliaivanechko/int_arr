#include <iostream>
#include <ctime>

float mean(int*, int );
float median(int*, int);
int mode(int*, int );
void sort (int*, int );

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    std::cout<<"Array of random integers: "<<std::endl;
    const int SIZE = 20;
    int random_integer[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        random_integer[i] = rand() % 80 + 10;
        std::cout<<random_integer[i]<<" ";
    }
    std::cout<<std::endl;
    
    int answer = 0;
    std::cout<<"1 - mean, \n2 - median, \n3 - mode \nEnter a digit: " ; std::cin>>answer;
    
    switch(answer) {
        case 1: std::cout<<"Mean is: "<<mean(random_integer, SIZE)<<std::endl; break;
        case 2: std::cout<<"Median is: "<<median(random_integer, SIZE)<<std::endl; break;
        case 3: std::cout<<"Mode is: "<<mode(random_integer, SIZE)<<std::endl; break;
        default: std::cout<<"Incorrect value! \n";
    }
    
    return 0;
}

float mean(int* arr, int size) {
    float sum = 0.0f;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}
int mode(int* arr, const int size) {
        int counter = 1, max_counter = 1, mode = 0, current_value = arr[0];
        sort(arr, size);
  
        for(int i = 0; i < size; i++) {
            if(arr[i] == current_value) {
                ++counter;
                for(int j = i + 1; j < size; j++) {
                    if (arr[j] == current_value) {
                        ++counter;
                    }
                }
            } else { if (counter > max_counter) {
                max_counter = counter;
                mode = current_value;
            }
            current_value = arr[i];
            counter = 1;
        }
    }
    return mode;
}
float median(int* arr, int size) {
    float median = 0;
    sort(arr, size);
    median = (float(arr[size/2-1]) + float(arr[size/2])) / 2;
    return median;
}
void sort (int* arr, int size) {
    int temp, item;
    for(int i = 1; i < size; i++) {
        temp = arr[i];
        item = i - 1;
        while(item >= 0&& arr[item] > temp) {
            arr[item + 1] = arr[item];
            arr[item] = temp;
            item--;
        }
    }
}

