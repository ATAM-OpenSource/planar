#include <iostream>
#include <string>
#include <Windows.h>
#include "portController.h"
#include "common.h"

using namespace std;

int main(int argc, char **argv){
    // First parameter is position, second parameter is speed
    if(argc<3){
        cerr << "This program works with at least 2 arguments!" << endl;
        return 0;
    }
    ex_atoi(argv[1]);
    ex_atoi(argv[2]);
    try{
        PortController ser("\\\\.\\COM"+to_string(getPortIni()));
        ser.writeData("ORDER 201 " + string(argv[1]) + " " + string(argv[2]) + " 8193 100 100 0 0 0 0\r\nMOVE 201\r\n");
    } catch (PortControllerException err){
        cerr << err.getMessage();
    }
    return 0;
}
