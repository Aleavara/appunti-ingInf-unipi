//
// Created by Alessio Avarappattu on 19/11/25.
//

#include "main.h"
#include  <iostream>

#include "CloudStorage.h"
using namespace std;
#include <iostream>
int main() {
    cout<<"ciao";
    CloudStorage cs(10,1000);
 cs.uploadFile(2,"alessio.png",100);
    cout<<"ciao";
    cout<<cs;

}