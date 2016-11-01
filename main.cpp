#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

void write_file(ofstream *file_ptr, vector<string>* str){

}

int main(int argc, char* argv[]){

    ifstream myReadFile;
    ofstream myWriteFile;
    string buf;
    vector<string> dest_buf;
    int num_strings = 0;

    dest_buf.reserve(100);

    myWriteFile.open("ztype.out");
    myReadFile.open(argv[1]);

    if(myReadFile.is_open()){
        while(1){
            if(getline(myReadFile, buf,' ')){
                if(num_strings++ <= 100){
                     dest_buf.push_back(buf);
                }else{
                    write_file(&myWriteFile, &dest_buf);
                    num_strings = 0;
                }
                cout << buf<<endl;
            }else{
                break;
            }
        }
    }else{
        cerr<<"File not valid \n";
    }

    myWriteFile.close();
    myReadFile.close();
    return 0;
}
