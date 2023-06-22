//#include"ThreadPool.h"
#include <chrono>
#include"Quicksort.h"


int main() 
{
    setlocale(LC_ALL, "");
    srand(0);
    //создание массивов
    long arr_size = 5'000'000;
    std::shared_ptr<int[]> array (new int[arr_size]);
    for (long i = 0; i < arr_size; i++) {
        array[i] = rand() % 50000;        
    }

    std::cout << "\n";   

    long arr_size2 = 600'000;
    std::shared_ptr<int[]> array2(new int[arr_size2]);
    for (long i = 0; i < arr_size2; i++) {
        array2[i] = rand() % 500'000;        
    }

    long arr_size3 = 50'000;
    std::shared_ptr<int[]> array3(new int[arr_size2]);
    for (long i = 0; i < arr_size3; i++) {
        array3[i] = rand() % 500'000;
    }   
    //сортировка с подзадачами через RequestHandler

    quicksort(array2, 0, arr_size2 - 1);//300'000

    quicksort(array3, 0, arr_size3 - 1);//50'000

    //сортировка напрямую через ThreadPool без разделения на подзадачи
    ThreadPool pool;
    pool.start();
    pool.push_task(quicksort1, array, 0, arr_size - 1);//300'000
    pool.stop();

    std::cout << "\n";   
   
    //проверка сортировки
    long i = 0;
    for (; i < arr_size - 1; i++) {
        if (array[i] > array[i + 1]) {
            std::cout << "\n Unsorted" << "\n";
            break;
        }
    }
    std::cout << i << "=i" << "\t";
    if (i == arr_size - 1)
        std::cout << "Sorted OK array \n";

    
    i = 0;
    for (; i < arr_size2 - 1; i++) {
        if (array2[i] > array2[i + 1]) {
            std::cout << "\n Unsorted 2" << std::endl;
            break;
        }
    }

    std::cout << i << "=i2" << "\t";
    if (i== arr_size2-1)
        std::cout << "Sorted OK array2\n"; 
        

    i = 0;
    for (; i < arr_size3 - 1; i++) {
        if (array3[i] > array3[i + 1]) {
            std::cout << "\n Unsorted 3" << std::endl;
            break;
        }
    }

    std::cout << i << "=i3" << "\t";
    if (i == arr_size3 - 1)
        std::cout << "Sorted OK array3\n";

       
    return 0;
}
