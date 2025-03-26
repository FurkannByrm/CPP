#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

mutex coutMutex;  // 👈 cout işlemlerini kilitlemek için mutex

void function1() {
  for (int i = 0; i < 200; ++i) {
    {
      lock_guard<mutex> lock(coutMutex);  // 👈 mutex ile cout kilitleniyor
      cout << "A";
    }
    this_thread::sleep_for(chrono::nanoseconds(1));
  }
}

void function2() {
  for (int i = 0; i < 200; ++i) {
    {
      lock_guard<mutex> lock(coutMutex);
      cout << "B";
    }
    this_thread::sleep_for(chrono::nanoseconds(1));
  }
}

void function3(char c) {
  for (int i = 0; i < 200; ++i) {
    {
      lock_guard<mutex> lock(coutMutex);
      cout << c;
    }
    this_thread::sleep_for(chrono::nanoseconds(1));
  }
}

int main() {
  thread worker1(function1);
  thread worker2(function2);
  thread worker3(function3, '-');
  worker1.join();
  worker2.join();
  worker3.join();
  cout << "\n";
}
