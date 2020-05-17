/** 
 * @file main.cpp
 * @author lcv
 * @date 10 de febrero de 2020, 12:59
 */

#include <iostream>
using namespace std;

class Helloworld {
private:
  string message;
public:
  Helloworld();
  void print()const;
  void set(string s);
};

int main() {
  Helloworld hw;
  hw.set("Hola mundo!");
  hw.print();
  return 0;
}

Helloworld::Helloworld(){ 
    message="Hello world!";
  }
void Helloworld::print()const{
    cout << endl << message << endl;
  }
void Helloworld::set(string s) {
    message = s;
  }