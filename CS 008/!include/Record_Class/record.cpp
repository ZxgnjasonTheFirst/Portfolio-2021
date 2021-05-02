#include "record.h"


long Record::overwrite(fstream &outs){
    //overwrite the file.
    const bool debug = false;
    long pos = outs.tellp();
    if (debug) cout<<"Record::write(): pos: "<<pos<<endl;

    //outs.write(&record[0], sizeof(record));
    outs.write(&record[0][0], sizeof(record));

    return pos/sizeof (record);
}

long Record::write(fstream &outs){
    //write to the end of the file.
    const bool debug = false;
    outs.seekp(0, ios_base::end);
    long pos = outs.tellp();
    if (debug) cout<<"Record::write(): pos: "<<pos<<endl;

    //outs.write(&record[0], sizeof(record));
    outs.write(&record[0][0], sizeof(record));

    return pos/sizeof (record);
}
long Record::read(fstream &ins, long recno){
    long pos= recno * sizeof(record);
    ins.seekg(pos, ios_base::beg);


    ins.read(&record[0][0], sizeof(record));
    return ins.gcount() * recno;

}
ostream& operator<<(ostream& outs,
                    const Record& r){
    for(int i = 0; i < sizeof(r.record)/sizeof(r.record[0]); ++i){
        outs<<r.record[i]<<endl;
    }
    return outs;
}

//-------------------------------------------------
bool file_exists(const char filename[]){
    const bool debug = false;
    fstream ff;
    ff.open (filename,
        std::fstream::in | std::fstream::binary );
    if (ff.fail()){
        if (debug) cout<<"file_exists(): File does NOT exist: "<<filename<<endl;
        return false;
    }
    if (debug) cout<<"file_exists(): File DOES exist: "<<filename<<endl;
    ff.close();
    return true;
}

void open_fileRW(fstream& f, const char filename[]) throw(char*){
    const bool debug = false;
    //openning a nonexistent file for in|out|app causes a fail()
    //  so, if the file does not exist, create it by openning it for
    //  output:
    if (debug){
        cout<<"open_fileRW: top."<<endl;
    }
    if (!file_exists(filename)){
        if (debug) cout<<"file does not exist. creating."<<endl;
        f.open(filename, std::fstream::out|std::fstream::binary);
        if (f.fail()){
            cout<<"file open (RW) failed: with out|"<<filename<<"]"<<endl;
            throw("file RW failed  ");
        }
        else{
            if (debug) cout<<"open_fileRW: file created successfully: "<<filename<<endl;
        }
    }
    else{
        if (debug) cout<<"file does exist. "<<endl;
        f.open (filename,
            std::fstream::in | std::fstream::out| std::fstream::binary );
        if (f.fail()){
            cout<<"file open (RW) failed. ["<<filename<<"]"<<endl;
            throw("file failed to open.");
        }
    }

}
void open_fileW(fstream& f, const char filename[]){
    f.open (filename,
            std::fstream::out| std::fstream::binary );
    if (f.fail()){
        cout<<"file open failed: "<<filename<<endl;
        throw("file failed to open.");
    }

}
void save_list(Record list[], int count, const char filename[]){
    fstream f;
    open_fileW(f, filename);
    for (int i= 0; i<count; i++){
        list[i].write(f);
    }
    f.close();

}
