#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include <typeinfo>
#include <cstdlib>

//using namespace std;

int main(int argc, char* argv[]){
  if(argc != 4){
    std::cout << "argc wrong" << std::endl;
    return 1;
  }
  const int n=72;
  std::string col[n];
  std::string ME11 = "1,";
  std::string ME21 = "2,";
  std::ifstream file;
  //  std::cout <<typeid(std::string(argv[1])).name()<<argv[1]<<"\n"<<typeid(ME11).name()<<ME11<<ME21<<std::endl;
  if(std::string(argv[1]).compare(ME11)==0) file.open("ME11.txt"); 
    else if(std::string(argv[1]).compare(ME21)==0) file.open("ME21dose.txt");
         else std::cout << "input argv[] wrong" << std::endl;
  if (!(file.is_open())){
    std::cout << "can't open file" << std::endl;
    if (file.fail()) std::cout << "maybe not doesn't exist" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (file) std::cout << "file does exit" << std::endl;

  bool fexists(file);

  std::cout << "condition::" << fexists << std::endl;

  for (std::string line; getline(file,line); ){
    std::istringstream iss(line);
    for (int i=0;i<n;i++)
      iss >> col[i];
    if(col[4] == std::string(argv[2]) && col[5] == std::string(argv[3]))
      std::cout << "col[5]::" <<col[3]<<col[4]<<col[5]<<col[6]<<col[7]<<col[8] << std::endl;
    //analyze data;
  }
}


bool fexists(const char* f){
  std::ifstream ifile(f);
  return ifile;
}
