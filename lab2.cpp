#include <iostream>
#include <random>
#include <chrono>
const int hh = 10;
class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::chrono::time_point<clock_t> m_beg;
public:
    Timer() : m_beg(clock_t::now())
    {
    }
    void reset()
    {
        m_beg = clock_t::now();
    }
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};




void quicksort(int a, int b, int* x) {
    if (a >= b) {
        return;
    }
    int m, k, l, r;
    m = rand() % (b - a + 1) + a;
    k = x[m];
    l = a-1;
    r = b+1;
    while(1) {
        do { l = l + 1; 
        } while (x[l] < k);

            do { r = r - 1; 
        } while (x[r] > k);
        if (l >= r)
            break;
        
          std::swap(x[l], x[r]);
    }
    r = l;
    l = l - 1;
    quicksort(a, l, x);
    quicksort(r, b, x);
}

void BUBBLESORT(int *mas, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (mas[i] >= mas[i - 1])
            continue;
        int j = i - 1;
        while (j >= 0 && mas[j] > mas[j + 1])
        {
            std::swap(mas[j], mas[j + 1]);
            j--;
        }
    }
}






int main()
{
    std::cout << "Quicksort" << std::endl;
    int mas[hh];
    for (int i = 0; i < hh; i++) {
        mas[i] = rand() % 10;
    }

    for (int i = 0; i < hh; i++) {
        std::cout << mas[i] << std::endl;                  
    }
    int maas[hh];
    for (int i = 0; i < hh; i++) {
        maas[i] = mas[i];
    }

    Timer t;
    quicksort(0, hh-1, mas);
    std::cout << "Time elapsed: " << t.elapsed() << '\n';

    for (int i = 0; i < hh; i++) {
        std::cout<< mas[i]<<std::endl;                    
    }





    std::cout << "Bubblesort" << std::endl;

    for (int i = 0; i < hh; i++) {
        std::cout << maas[i] << std::endl;
    }

    Timer v;
    BUBBLESORT(maas, hh);
    std::cout << "Time elapsed: " << v.elapsed() << '\n';

    for (int i = 0; i < hh; i++) {
        std::cout << maas[i] << std::endl;
    }


}


