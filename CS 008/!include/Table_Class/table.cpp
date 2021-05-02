#include "table.h"
#include "stdio.h"
Table::Table(){

}

Table::Table(string name){
//    /*existing table.
//     * for starters, hardcode the fields.
//     * later, you must read the name of fields from
//     * a text file: student.fields
//     * create a map (or vector) of Multimaps (indices)
//     * and reindex the table.
//     */
//    /*
//     * open file, read the list of fields.
//     * create your index vector/map
//     * open the binary file and reindex your indices.
//     *
//    */
    fstream file;
    ofstream txtfileo;
    ifstream txtfilei;
    string temp;
    filename = name;
    recno = 0;
    open_fileRW(file, filename.c_str());
    file.close();
    readtxtfile(txtfilei, "student.fields");
    while(!txtfilei.eof()){
        txtfilei>>temp;
        field_list.push_back(temp);
    }
//    cout<<"this is field list: ["<<field_list<<"]"<<endl;
    for(int i = 0; i < field_list.size(); ++i){
        indices.emplace_back(mmap_sl());
//        indices[i][field_list[i]] += recno;
    }

    txtfilei.close();
    txtfileo.close();
//    if(file_exists(filename.c_str())){
    reindex();
//    }

}

Table::Table(string name, vector<string> f_list){
    /* field does not exist
     * i am given the names of list.
     * create the files: table file and field name files
     * and indices.
     */
    fstream file;
    ofstream txtfile;
    field_list = f_list;
    filename = name;
    recno = 0;


    writetxtfile(txtfile, "student.fields");

    for(int i = 0 ; i < field_list.size(); ++i){
        indices.emplace_back(mmap_sl());
        txtfile<<field_list[i];
        if(i != field_list.size() - 1){
            txtfile<<endl;
        }
    }
//    cout<<"this is field list: ["<<field_list<<"]"<<endl;

    txtfile.close();
//    if(file_exists(filename.c_str())){
    reindex();
//    }


}
Table Table::select_all(vector<string> f_list){
    /* open the file, grab ALL the stuff
     * and for now, just print it.
     * later, create a table with the indices
     * you extracted and return it.
     */
    fstream file, file2;
    string full = filename + ".STAR";
    Record rec;
    Table newtable;
    open_fileRW(file, filename.c_str());
    if(!f_list.empty()){
        newtable = build_new_table(full, vector<long>(), f_list);
    }
    else{
        file.seekp(0, ios_base::end);
        long temp = file.tellp();
        long size = temp/sizeof(rec.record);
        for(int i = 0; i < size; ++i){
            vector<string> indexvec;
            rec.read(file, i);
            for(int j = 0; j < field_list.size(); ++j){
                indexvec.push_back(rec.record[j]);
            }
    //        cout<<"out of loop"<<endl;
            Record rec2(indexvec);
            open_fileRW(file2, full.c_str()); //filename + ."indices"
            rec2.write(file2);
            file2.close();
        }
        newtable = Table(full.c_str());

//        newtable.drop_table();
    }
    file.close();




//    cout<<"================"<<endl;
//    cout<<setw(10)<<"Record #";
//    for(int i = 0; i < newtable.field_list.size(); ++i){
//        cout<<setw(10)<<newtable.field_list[i];
//    }
//    cout<<endl;
//    open_fileRW(file, newtable.filename.c_str());
//    file.seekp(0, ios_base::end);
//    long temp2 = file.tellp();
//    long size2 = temp2/sizeof(rec.record);

//    for(int i = 0 ; i < size2; ++i){
//        rec.read(file, i);
//        cout<<setw(10)<<i;
//        for(int j = 0; j < newtable.field_list.size(); ++j){
//            cout<<setw(10)<<rec.record[j];
//        }
//        cout<<endl;
//    }
//    cout<<"================"<<endl;
//    file.close();

    return newtable;

}

void Table::drop_table(vector<string> files2delete){
    const bool debug = false;
    string full = filename + ".and";
    string full2 = filename + ".or";
    string star = filename + ".STAR";
    if( remove( full.c_str() ) != 0 ){
        if(debug)
            cout<< "Error deleting file" <<endl;
    }
    else{
        if(debug)
            cout<< "File successfully deleted" <<endl;
    }
    if( remove( full2.c_str() ) != 0 ){
        if(debug)
            cout<< "Error deleting file" <<endl;
    }
    else{
        if(debug)
            cout<< "File successfully deleted" <<endl;
    }
    if( remove( star.c_str() ) != 0 ){
        if(debug)
            cout<< "Error deleting file" <<endl;
    }
    else{
        if(debug)
            cout<< "File successfully deleted" <<endl;
    }
    for (int i = 0; i < files2delete.size(); ++i) {
        if( remove( files2delete[i].c_str() ) != 0 ){
            if(debug)
                cout<< "Error deleting file" <<endl;
        }
        else{
            if(debug)
                cout<< "File successfully deleted" <<endl;
        }

    }
}

void Table::insert_into(vector<string> f_listactual){
    //Insert into record.
    fstream file;
    Record rec(f_listactual);
    open_fileRW(file, filename.c_str());
    recno = rec.write(file);

    for(int i = 0; i < f_listactual.size(); ++i){
//        cout<<"["<<f_listactual[i]<<"]"<<endl;
        indices[i][f_listactual[i].c_str()] += recno;
//        cout<<"==================="<<endl;
//        cout<<indices[i]<<endl;
//        indices[i].seeleaves();
//        cout<<endl;
//        cout<<"==================="<<endl;
    }


    file.close();


}

void Table::insert_into(Record rec){
    //Insert into record.
    fstream file;
    open_fileRW(file, filename.c_str());
    recno = rec.write(file);

    file.close();



}

int Table::findfield(string condition){
    for(int i = 0; i < field_list.size(); ++i){
        if(condition == field_list[i]){
            return i;
        }
    }
}

Table Table::select(vector<string> f_list, string condition){ //last first major?

    vector<long> recnos = get_rec_nos(condition);

    Table newtable = build_new_table(condition, recnos, f_list);

    return newtable;

}

vector<long> Table::get_rec_nos(string condition){
//    condition.erase(remove(condition.begin(), condition.end(), ' '), condition.end());
//    condition.erase(remove(condition.begin(), condition.end(), '"'), condition.end());
    std::size_t found = condition.find(">=");
    if (found!=std::string::npos) {
//        cout<<">= operator found"<<endl;
        int pos = condition.find(">=");
        string field = condition.substr(0, pos);
        string name = condition.substr(pos + 2);
        int find = findfield(field);
        vector<long> recnos;
//        if(!indices[find][name].empty()){
        for(MMap<string, long>::Iterator it =
                indices[find].find(name);
                it != indices[find].end(); it++){   //indices["first"]["Jason"]
            recnos += (*it).value_list;
        }
//        }
//        cout<<indices;
//        cout<<"this is valuelist: ["<<recnos<<"]"<<endl;
        return recnos;
    }
    found = condition.find("<=");
    if (found!=std::string::npos) {
//        cout<<"<= operator found"<<endl;
        int pos = condition.find("<=");
        string field = condition.substr(0, pos);
        string name = condition.substr(pos + 2);
        int find = findfield(field);
        vector<long> recnos;
        if(!indices[find][name].empty()){
            for(MMap<string, long>::Iterator it =
                    indices[find].begin();
                    it != indices[find].upper_bound(name); it++){   //indices["first"]["Jason"]
//                cout<<"in for loop: "<<endl;
                recnos += (*it).value_list;
            }
        }
        else {
            for(MMap<string, long>::Iterator it =
                    indices[find].begin();
                    it != indices[find].find(name); it++){   //indices["first"]["Jason"]
//                cout<<"in for loop: "<<endl;
                recnos += (*it).value_list;
            }
        }
//        cout<<indices;
//        cout<<"this is valuelist: ["<<recnos<<"]"<<endl;
        return recnos;
    }
    found = condition.find("=");
    if(found!=std::string::npos){
//        cout<<"= operator found"<<endl;
        int pos = condition.find("=");
        string field = condition.substr(0, pos);
        string name = condition.substr(pos + 1);
        int find = findfield(field);

        vector<long> recnos = indices[find][name]; //indices["first"]["Jason"]
        return recnos;
    }
    found = condition.find(">");
    if (found!=std::string::npos) {
//        cout<<"> operator found"<<endl;
        const bool debug = false;
        int pos = condition.find(">");
        string field = condition.substr(0, pos);
        string name = condition.substr(pos + 1);
        int find = findfield(field);
        vector<long> recnos = vector<long>();
        if(debug){
            cout<<indices<<endl;
            for(int i = 0; i < field_list.size(); ++i){
                indices[i].seeleaves();
                cout<<endl;
            }
        }
//        cout<<"This is get_recnos: indices[find].upperbound["<<name<<"]: "<<endl;
        if(!indices[find][name].empty()){
            for(MMap<string, long>::Iterator it =
                    indices[find].upper_bound(name);
                    it != indices[find].end(); it++){   //indices["first"]["Jason"]
    //            cout<<"inside here"<<endl;
                recnos += (*it).value_list;
            }
        }
        else {
            for(MMap<string, long>::Iterator it =
                    indices[find].find(name);
                    it != indices[find].end(); it++){   //indices["first"]["Jason"]
    //            cout<<"inside here"<<endl;
                recnos += (*it).value_list;
            }
        }
//        cout<<"This is recnos in get_recnos: "<<recnos<<endl;
        return recnos;

    }
    found = condition.find("<");
    if (found!=std::string::npos) {
//        cout<<"< operator found"<<endl;
        int pos = condition.find("<");
        string field = condition.substr(0, pos);
        string name = condition.substr(pos + 1);
        int find = findfield(field);
        vector<long> recnos;
//        if(!indices[find][name].empty()){
        for(MMap<string, long>::Iterator it =
                indices[find].begin();
                it != indices[find].lower_bound(name); it++){   //indices["first"]["Jason"]
            recnos += (*it).value_list;
        }
//        }
        return recnos;
    }




}

Table Table::build_new_table(string name, vector<long> recnos, vector<string> f_list){
    const bool debug = false;
    fstream file, file2;
    Record rec;
    Table temp(name, f_list);
    open_fileRW(file, filename.c_str());
    if(recnos.empty() && name == filename + ".STAR"){
        file.seekp(0, ios_base::end);
        long temp2 = file.tellp();
        long size = temp2/sizeof(rec.record);
        for(int i = 0; i < size; ++i){
            vector<string> vectoinsert;
            rec.read(file, i);
            vector<int> index = findalikeindices(f_list, field_list);
            for(int j = 0; j < index.size(); ++j){
                vectoinsert.push_back(rec.record[index[j]]);
            }

            temp.insert_into(vectoinsert);
        }


    }
    else{
        for(int i = 0; i < recnos.size(); ++i){
            vector<string> vectoinsert;
            rec.read(file, (recnos[i]));
            vector<int> index = findalikeindices(f_list, field_list);
            for(int j = 0; j < index.size(); ++j){
                vectoinsert.push_back(rec.record[index[j]]);
            }
            temp.insert_into(vectoinsert);
    //        cout<<"after insertinto: "<<endl;
    //        cout<<temp.indices<<endl;
        }
    }
    if(debug){
//        cout<<"temp.indices in build_new_table: "<<endl;
//        cout<<temp.indices<<endl;
    }
    file.close();
    return temp;
}

vector<int> Table::findalikeindices(vector<string> vec1, vector<string> vec2){
    vector<int> index;
    vector<string>::iterator it;
    for(int i = 0 ; i < vec1.size(); ++i){
        it = std::find(vec2.begin(), vec2.end(), vec1[i]);
        if (it != vec2.end()){
                index.push_back(distance(vec2.begin(), it));
        }
    }
//    cout<<"this is index: ["<<index<<"]"<<endl;
    return index;
}

ostream& operator<<(ostream& outs, const Table& t){
    Record rec;
    fstream file;
    outs<<"================"<<endl;
    outs<<setw(15)<<"Record #";
    for(int i = 0; i < t.field_list.size(); ++i){
        outs<<setw(15)<<t.field_list[i];
    }
    outs<<endl;
//    cout<<"["<<t.filename.c_str()<<"]"<<endl;
    open_fileRW(file, t.filename.c_str());
    file.seekp(0, ios_base::end);
    long temp = file.tellp();
    long size = temp/sizeof(rec.record);

    for(int i = 0 ; i < size; ++i){
        rec.read(file, i);
        outs<<setw(15)<<i;
        for(int j = 0; j < t.field_list.size(); ++j){
            outs<<setw(15)<<rec.record[j];
        }
        outs<<endl;
    }
    outs<<"================"<<endl;
    file.close();
    return outs;
}

Table& Table::operator = (const Table& rhs){
    if(this != &rhs){
        field_list = rhs.field_list;
        filename = rhs.filename;
        for(int i = 0 ; i < rhs.indices.size(); i++){
            indices.emplace_back(mmap_sl());
            indices[i] = rhs.indices[i];
        }
    }
    return *this;
}

Table RPN(vector<string> expression, Table t, vector<string> f_list , vector<string>& del){
    const bool debug = false;
    Parser p;
    vector<string> expr = p.ShuntingYard(expression);
    stack<Table> s;
    Table newTable, x, y, result, temp, temp2, temp3;
    if(debug){
        cout<<expr<<endl;
    }
    for(unsigned int i = 0; i < expr.size(); i++){
//        cout<<"RPN at: "<<expr[i]<<endl;
        if(isOperand(expr[i])==true)
        {
            temp = t.select(f_list, expr[i]);
            s.push(temp);
            del += temp.filename;

        }
        if(expr[i]== "and")
        {
//            cout<<"here VVV"<<endl;
            x = s.top();
//            cout<<x<<endl;
            s.pop();
            y = s.top();
//            cout<<y<<endl;
            s.pop();
            temp2 = And(x,y);
            s.push(temp2);
            del += temp2.filename;
//            cout<<"here"<<endl;
//            t.drop_table();
//            y.drop_table();
//            cout<<"here ^^^"<<endl;

        }
        if(expr[i]== "or")
        {
//            cout<<"here VVV"<<endl;
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
            temp3 = Or(x,y);
            s.push(temp3);
            del += temp3.filename;
//            t.drop_table();
//            y.drop_table();
//            cout<<"here ^^^"<<endl;
        }

    }
    newTable = s.top();
//    x.drop_table();
//    y.drop_table();
//    result.drop_table();
//    newTable.drop_table();
//    temp.drop_table();
    return newTable;
}


Table And(Table x, Table y){
    Record rec, rec2;
    fstream file, file2;
    open_fileRW(file, x.filename.c_str());
    file.seekp(0, ios_base::end);
    long temp = file.tellp();
    long size = temp/sizeof(rec.record);
    string full = x.filename + ".and";
    vector<vector<string> > vecofvecx, vecofvecy;


    for(int i = 0 ; i < size; ++i){
        vector<string> vecx;
        rec.read(file, i);
        for(int j = 0; j < x.field_list.size(); ++j){
            vecx.push_back(rec.record[j]);
        }
        vecofvecx.push_back(vecx);
    }
    file.close();

    open_fileRW(file2, y.filename.c_str());
    file2.seekp(0, ios_base::end);
    long temp2 = file2.tellp();
    long size2 = temp2/sizeof(rec2.record);
    for(int i = 0 ; i < size2; ++i){
        vector<string> vecy;
        rec2.read(file2, i);
        for(int j = 0; j < y.field_list.size(); ++j){
            vecy.push_back(rec2.record[j]);
        }
        vecofvecy.push_back(vecy);
    }
    file2.close();

//    cout<<"FULL Vecofvecx and vecy: "<<endl;
//    cout<<vecofvecx.size()<<endl;
//    cout<<"VECOFVEC X: "<<vecofvecx<<endl;
//    cout<<vecofvecy.size()<<endl;
//    cout<<"VECOFVEC Y: "<<vecofvecy<<endl;

    vector<vector<string> > fullvecofvec;
    sort(vecofvecx.begin(), vecofvecx.end());
    sort(vecofvecy.begin(), vecofvecy.end());

//    cout<<"before"<<endl;

    set_intersection (vecofvecx.begin(), vecofvecx.end(), vecofvecy.begin(), vecofvecy.end(), back_inserter(fullvecofvec));

//    cout<<"INTERSECTION SET: "<<fullvecofvec<<endl;
//    cout<<"vecofvec[0] size: "<<fullvecofvec[0].size()<<endl;
//    cout<<"vecofvec[0] capacity: "<<fullvecofvec[0].capacity()<<endl;

    Table newTable(full, x.field_list);
    for(int i = 0; i < fullvecofvec.size(); i++){
        newTable.insert_into(fullvecofvec[i]);

    }

    return newTable;

}

Table Or(Table x, Table y){
    Record rec, rec2;
    fstream file, file2;
    open_fileRW(file, x.filename.c_str());
    file.seekp(0, ios_base::end);
    long temp = file.tellp();
    long size = temp/sizeof(rec.record);
    string full = x.filename + ".or";

    vector<vector<string> > vecofvecx, vecofvecy;

    for(int i = 0 ; i < size; ++i){
        vector<string> vecx;
        rec.read(file, i);
        for(int j = 0; j < x.field_list.size(); ++j){
            vecx.push_back(rec.record[j]);
        }
        vecofvecx.push_back(vecx);
    }
    file.close();

    open_fileRW(file2, y.filename.c_str());
    file2.seekp(0, ios_base::end);
    long temp2 = file2.tellp();
    long size2 = temp2/sizeof(rec2.record);
    for(int i = 0 ; i < size2; ++i){
        vector<string> vecy;
        rec2.read(file2, i);
        for(int j = 0; j < y.field_list.size(); ++j){
            vecy.push_back(rec2.record[j]);
        }
        vecofvecy.push_back(vecy);
    }
    file2.close();

    vector<vector<string> > fullvecofvec;
    sort(vecofvecx.begin(), vecofvecx.end());
    sort(vecofvecy.begin(), vecofvecy.end());

    set_union (vecofvecx.begin(), vecofvecx.end(), vecofvecy.begin(), vecofvecy.end(), back_inserter(fullvecofvec));

    Table newTable(full, x.field_list);
    for(int i = 0; i < fullvecofvec.size(); i++){
        newTable.insert_into(fullvecofvec[i]);
    }
    return newTable;
}

bool isOperator(const string &c){
    return (c == "and" || c == "or");
}

bool isOperand(const string &symbol){
    return !isOperator(symbol);
}

void Table::reindex(){
    const bool debug = false;
    fstream file;
    Record rec;
    open_fileRW(file, filename.c_str());
    file.seekp(0, ios_base::end);
    long temp = file.tellp();
    long size = temp/sizeof(rec.record);
    file.close();
    for(int i = 0; i < size; ++i){
        open_fileRW(file, filename.c_str());
        recno = rec.read(file, i);
        if(debug){
            cout<<"Inside reindex rec: "<<endl;
            cout<<rec<<endl;
        }
        for(int j = 0; j < field_list.size(); ++j){
            indices[j][rec.record[j]] += recno;
        }
        file.close();
    }
    if(debug){
        cout<<"indices reindex"<<endl;
        cout<<indices<<endl;
    }
}

void writetxtfile(ofstream &f, const char filename[]){
    const bool debug = false;
    string txt = ".txt";
    string full = filename + txt;
    if (!file_exists(full.c_str())){
        f.open(full.c_str());
        if (f.fail()){
            cout<<"file open maketxt failed: with out|"<<full<<"]"<<endl;
            throw("file maketxt failed  ");
        }
        else{
            if (debug) cout<<"open_fileRW: file created successfully: "<<full<<endl;
        }
    }
    else{
        f.open (full.c_str());
        if (f.fail()){
            cout<<"file open maketxt failed. ["<<full<<"]"<<endl;
            throw("file failed to open.");
        }
    }

}


void readtxtfile(ifstream &f, const char *filename){
    const bool debug = false;
    string txt = ".txt";
    string full = filename + txt;
    if (!file_exists(full.c_str())){
        f.open(full.c_str());
        if (f.fail()){
            cout<<"file open maketxt failed: with out|"<<full<<"]"<<endl;
            throw("file maketxt failed  ");
        }
        else{
            if (debug) cout<<"open_fileRW: file created successfully: "<<full<<endl;
        }
    }
    else{
        f.open (full.c_str());
        if (f.fail()){
            cout<<"file open maketxt failed. ["<<full<<"]"<<endl;
            throw("file failed to open.");
        }
    }

}

