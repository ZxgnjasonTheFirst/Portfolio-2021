#include "sql.h"

SQL::SQL()
{
//    Table temp("student");
//    _tables["student"] = temp;
//    temp.drop_table();

//    _tables["student"].insert_into({"Jason", "Pambuena", "CS"});
//    _tables["student"].insert_into({"Jason", "Kai", "CS"});
//    _tables["student"].insert_into({"Jason", "Burgandy", "Math"});
//    _tables["student"].insert_into({"Kyle", "Chu", "History"});

    //set up your _tables mmap;
}

void SQL::run(){
    const bool debug = false;
    vector<string> files2delete, maintablefiles;
    ifstream batch;
    ofstream text;
    string batchfile, textfile;
    Table t;
    char command[256];
    int commandnum = 0;
    cin>>batchfile;
    textfile = batchfile + ".output";
    readbatchfile(batch, batchfile.c_str());
    writetxtfile(text, textfile.c_str());
    cout<<">"<<batchfile<<endl;
    text<<">"<<batchfile<<endl;
    while (batch.getline(command, 256)){
        if(command[0] == '/' && command[1] == '/' || command[0] == '\0'){
            cout<<command<<endl;
            text<<command<<endl;
        }
        else{
            parser.set_string(command);
            _ptree = parser.get_parse_tree();
            if(debug){
                cout<<"Here is the parse tree: "<<endl;
                cout<<_ptree<<endl;
            }
    //        Table t("student", {"first","last","major"});
    //        _tables["student"] = t;
    //        _tables["student"].insert_into({"Jason", "Pambuena", "CS"});
    //        _tables["student"].insert_into({"Jason", "Kai", "CS"});
    //        _tables["student"].insert_into({"Jason", "Burgandy", "Math"});
    //        _tables["student"].insert_into({"Kyle", "Chu", "CS"});
    //        _tables["student"].insert_into({"Mary Ann", "Stevens", "Anthro"});

            //here, figure out what the command is and
            // what the parameters are for what table...

        //    make sure the table exists...
            if(_ptree.empty()){
                cout<<"["<<commandnum<<"] COMMAND IS INVALID"<<endl;
                text<<"["<<commandnum<<"] COMMAND IS INVALID"<<endl;
            }
            else if(_ptree["COMMAND:"][0] == "select"){
                if(!_tables[_ptree["TABLE:"][0]].exists()){
                    cout<<"["<<commandnum<<"] INVALID: TABLE "<<_ptree["TABLE:"][0]<<" DOES NOT EXIST"<<endl;
                    text<<"["<<commandnum<<"] INVALID: TABLE "<<_ptree["TABLE:"][0]<<" DOES NOT EXIST"<<endl;
                }
                else{
                    t = _tables[_ptree["TABLE:"][0]];
                    if(!_ptree["STAR:"].empty()){
                        if(_ptree["WHERE:"].empty()){
                            _tables["select"] = t.select_all();
                            cout<<"["<<commandnum<<"] "<<command<<endl;
                            text<<"["<<commandnum<<"] "<<command<<endl;
                            cout<<_tables["select"];
                            text<<_tables["select"];
                        }
                        else {
                            _tables["select"] = RPN(_ptree["SELWHERE:"], t, t.field_list, files2delete);
                            cout<<"["<<commandnum<<"] "<<command<<endl;
                            text<<"["<<commandnum<<"] "<<command<<endl;
                            cout<<_tables["select"];
                            text<<_tables["select"];
                        }
                    }
                    else{
                        if(!_ptree["WHERE:"].empty()){
                            _tables["select"] = RPN(_ptree["SELWHERE:"], t, _ptree["FIELDS:"], files2delete);
                            cout<<"["<<commandnum<<"] "<<command<<endl;
                            text<<"["<<commandnum<<"] "<<command<<endl;
                            cout<<_tables["select"];
                            text<<_tables["select"];
                        }
                        else{
                            _tables["select"] = t.select_all(_ptree["FIELDS:"]);
                            cout<<"["<<commandnum<<"] "<<command<<endl;
                            text<<"["<<commandnum<<"] "<<command<<endl;
                            cout<<_tables["select"];
                            text<<_tables["select"];
                        }
                    }
                    _tables["select"].drop_table();
                    t.drop_table(files2delete);
                    maintablefiles.push_back(_ptree["TABLE:"][0]);
                }
            }
            else if (_ptree["COMMAND:"][0] == "create" || _ptree["COMMAND:"][0] == "make"){
                _tables[_ptree["TABLE:"][0]] = Table(_ptree["TABLE:"][0], _ptree["FIELDS:"]);
                cout<<"["<<commandnum<<"] Table "<<_ptree["TABLE:"][0]<<" created!"<<endl;
                text<<"["<<commandnum<<"] Table "<<_ptree["TABLE:"][0]<<" created!"<<endl;
            }
            else if (_ptree["COMMAND:"][0] == "insert"){
                _tables[_ptree["TABLE:"][0]].insert_into(_ptree["VALUES:"]);
                cout<<"["<<commandnum<<"] "<<command<<endl;
                cout<<"SQL::run: inserted"<<endl;
                text<<"["<<commandnum<<"] "<<command<<endl;
                text<<"SQL::run: inserted"<<endl;
            }
            cout<<endl<<endl<<"SQL: DONE."<<endl<<endl<<endl;
            text<<endl<<endl<<"SQL: DONE."<<endl<<endl<<endl;
            ++commandnum;
        }

        parser = Parser();
    }
    t.drop_table(maintablefiles);
    batch.close();
    text.close();
}

void SQL::readbatchfile(ifstream &f, const char filename[]){
    const bool debug = false;
    if (!file_exists(filename)){
        f.open(filename);
        if (f.fail()){
            cout<<"file open maketxt failed: with out|"<<filename<<"]"<<endl;
            throw("file maketxt failed  ");
        }
        else{
            if (debug) cout<<"open_fileRW: file created successfully: "<<filename<<endl;
        }
    }
    else{
        f.open (filename);
        if (f.fail()){
            cout<<"file open maketxt failed. ["<<filename<<"]"<<endl;
            throw("file failed to open.");
        }
    }

}
