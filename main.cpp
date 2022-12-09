#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <algorithm>

int main()
{
    time_t start, end;
    time(&start);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);

    std::ofstream dataB;
    std::ofstream dataC;
    std::ofstream dataD;
    std::ofstream dataU;
    std::ofstream dataL;
    std::ofstream dataDC;

    dataB.open("dataB.txt");
    dataC.open("dataC.txt");
    dataD.open("dataD.txt");
    dataU.open("dataU.txt");
    dataL.open("dataL.txt");
    dataDC.open("dataDC.txt");


    unsigned int nTry = 0;

    for(unsigned int n = 1000; n <= 100000; n += 1000)
    {
        std::cout << n << std::endl;
        for(size_t k = 0; k < 50; k++)
        {

            nTry++;
            unsigned int pins[n]{0};
            unsigned int nThrows = 0;
            unsigned int max = 0;
            unsigned int notEmpty = 0;
            unsigned int numberOfB = 0;
            unsigned int C = 0;

            while (numberOfB != n)
            {
                unsigned int ball = generator();
                ball %= n;
                nThrows++;
                pins[ball]++;
                switch (pins[ball])
                {
                    case 1:
                        notEmpty++;
                        if(notEmpty == n)
                        {
                            C = nThrows;
                            dataC << nThrows << "|";
                        }
                        break;
                    case 2:
                        numberOfB++;
                        if(numberOfB == 1)
                        {
                            dataB << nThrows << "|";
                        }
                        break;
                    default:
                        if (nThrows <= n)
                        {
                            if (pins[ball] > max)
                            {
                                max = pins[ball];
                            }
                            if (nThrows == n)
                            {
                                dataU << n - notEmpty << "|";
                                dataL << max << "|";
                            }
                        }
                }
            }
            dataD << nThrows << "|";
            dataDC << nThrows - C;
        }
    }

    dataB.close();
    dataC.close();
    dataD.close();
    dataU.close();
    dataL.close();
    dataDC.close();
    time(&end);
    double time_taken = double(end - start);
    std::cout << "Time taken by program is : " << time_taken;
    return 0;
}
