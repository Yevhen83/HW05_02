#include <iostream>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <time.h>
////#inciude <stddef.h>
using namespace std;
//int main()
//{
//    auto start = std::chrono::system_clock::now();
//    
//    auto end = std::chrono::system_clock::now();
//
//    std::chrono::duration<double>elapsed_seconds = end - start;
//    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
//    //std::chrono::duration<double>elapsed_seconds = start;
//
//    std::cout << " Finished computation at " << std::time(&end_time)
//        << " elapsed time: " << elapsed_seconds.count() << "s\n";
//    cout << end_time << endl;
//    //cout << start.count() << endl;
//    //cout << end << endl;
//}

//#include <ctime>
//#include <iostream>
//
//int main() {
//    std::time_t t = std::time(0);   // get time now
//    std::tm* now = std::localtime(&t);
//    std::cout << (now->tm_year + 1900) << '-'
//        << (now->tm_mon + 1) << '-'
//        << now->tm_mday
//        << "\n";
//}


using namespace std;

int main() {
    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    //char* dt = ctime(&now);

    //cout << "The local date and time is: " << dt << endl;

    // convert now to tm struct for UTC
    tm* gmtm = localtime(&now);
    char* dt = asctime(gmtm);
    cout << "The UTC date and time is:" << dt << endl;
}