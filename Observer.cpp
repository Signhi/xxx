// 需求：在操作文件的时候展示文件操作进度，将一个大文件分别存到不同的小文件
// 变化：不同的文件展示进度的方式，现在是百分比，以后可能是进度条

#include <string>

using namespace std;

class Iprogress{
public:
    virtual void setValue(double value) = 0;
    virtual ~Iprogress(){}
}

class ProgressBar : public Iprogress{
public:
    virtual void setValue(double value){
        cout << "ProgressBar: " << value << endl;
    }
}


class Filesplitter{
private:
    string file_path;
    int file_size;
    Iprogress *progress;
public:
    Filesplitter(string file_path, int file_size, Iprogress *progress): 
        file_path(file_path), file_size(file_size), progress(progress){}
    void split(){
        for(int ii = 0; ii < file_size; ii++){
            if(progress != nullptr){
                progress->setValue(ii * 1.0 / file_size); // 更新进度条
            }
        }
    }
}

// 主类

class Main : public Filesplitter, public Iprogress{
    string file_path;
    int file_size;
    Iprogress *progress;
public:
    
    Main(string file_path, int file_size, Iprogress *progress):
        file_path(file_path), file_size(file_size), progress(progress){}

    void ButtonClick(){
        Filesplitter *filesplitter = new Filesplitter("test.txt", 100, this);
        filesplitter->split();
    }

    void setValue(double value){
        cout << "Main: " << value << endl;
    }

}   