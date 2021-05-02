#include <iostream>
#include <iomanip>

/*
 * Name: Jason Pambuena
 * Project: recursive_drill
 * Purpose: Showcases ways in which recursion is implemented
 * Notes: Recursions in a for loop exits the for loop after the last function returns.
 *        and having an argument pass by reference keeps the argument changed till the
 *        last function is called back to main.
 */
using namespace std;
void R1_levls(int lvl = 0);
void R2_Box(string prefix = "BOX: ", unsigned int levels = 3);
void R3_first_second(string first = "CAT", string second = "MAN");
void R4_Boxes(int &totalboxes, string prefix = "BOX: ", unsigned int levels = 0);
double R5_Sum(unsigned int n);
void R16_Guess(int low, int high);
void Cin(); //Testing cin in recursions.

int main()
{
    int totalboxes = 0; //NEEDED FOR R4_Boxes couts the totalboxes at the end.
    int ourlow = 1;
    int ourhigh = 1000000;
//    R1_levls();
//    R2_Box();
//    R3_first_second();
//    R4_Boxes(totalboxes);
//    cout<<setprecision(5)<<R5_Sum(10)<<endl;
//    cout<<"Here's a guessing game! Think of a number between "<<ourlow<<" and "<<ourhigh<<
//          " and we'll try to guess it! Press ENTER to start!"<<endl;
//    cin.ignore();
//    R16_Guess(ourlow,ourhigh);
//    Cin();
    return 0;
}

void R1_levls(int lvl){

    ++lvl;
    if(lvl <= 5){
        for(int space = 1; space < lvl; ++space)
            cout<<" ";
        cout<<"This was written by call number "<<lvl<<"."<<endl;
        R1_levls(lvl);
    }
    --lvl;
    if(lvl > 0){
        for(int space = 1; space < lvl; ++space)
            cout<<" ";
        cout<<"This was ALSO written by call number "<<lvl<<"."<<endl;
    }
}

void R2_Box(string prefix, unsigned int levels){
//    cout<<"Here we go"<<endl;
    if(levels == 0){
        cout<<prefix<<endl;
        return;
    }
    for(int i = 1; i < 10 ; ++i){  //This for loop is important, it causes the string s to grow levels
        string s = prefix;         //whatever level deep then is returned by the if statement on top.
        s += char('0' + i);        //Since it is in a for loop between 1 and 9, the s before the level is 0
        s += '.';                  //for ex: 1.1., keeps returning and incrementing due to recursion.

//        cout<<s<<endl;
        R2_Box(s, levels - 1); //***CANNOT DO --levels

    }

//   cout<<"Now on our way back"<<endl;
}

void R3_first_second(string first, string second){
    //ABCD xxx vv
    //BCD Axxx -> ACD Bxxx -> ABD Cxxx -> ABC Dxxx vv
    bool DEBUG = false;
    if(first.empty()){
        if(DEBUG)
            cout<<"second: ";
        cout<<second<<endl;
        return;
    }
    else{
        for(size_t i = 0; i < first.length(); ++i){
            if(DEBUG)
                cout<<"here "<<first<<" "<<second<<endl;
            char c = first[i];
            first.erase(i,1);
            if(DEBUG)
                cout<<"enter "<<first<<" "<<c+second<<endl;
            R3_first_second(first, c + second);
            if(DEBUG)
                cout<<"then "<<first<<" "<<second<<endl;
            first.insert(0,1,c);
            if(DEBUG)
                cout<<"there "<<first<<" "<<second<<endl;

        }
        if(DEBUG)
            cout<<"exit"<<endl;
    }


}

void R4_Boxes(int &totalboxes, string prefix, unsigned int levels){
//    cout<<"Here we go"<<endl;
    bool DEBUG = false;
    int numboxes = 0;
    string s;
    char yes = 'y';
    if(levels > 0){
        cout<<"Would you like to open "<<prefix<<"?"<<endl;
        cin>>yes;
    }
    if(toupper(yes) == 'Y'){
        ++levels;
        cout<<"How many boxes do you see?"<<endl;
        while(!(cin>>numboxes)){
            cout<<"Invalid input please input a number"<<endl;
            cin.clear();
            cin.ignore();
        }
        cin.clear();
        cin.ignore();
        totalboxes += numboxes;
    }
    else{
        if(DEBUG)
            cout<<prefix<<endl;
        return;
    }
    for(int i = 1; i <= numboxes ; ++i){
        s = prefix;
        s += char('0' + i);
        s += '.';
        R4_Boxes(totalboxes, s, levels);
    }
    --levels;
    if(levels == 0){
        cout<<"Here is how many boxes you found! "<<totalboxes<<endl;
    }
//   cout<<"Now on our way back"<<endl;
}

double R5_Sum(unsigned int n){

    if(n == 0){
        return 0.0;
    }
    return 1.0/n + R5_Sum(n-1);


}

void R16_Guess(int low, int high){
    int midpoint;
    char ans;
    midpoint = (low + high) / 2;

    if(low == high){
        cout<<"Your number has to be "<<midpoint<<endl;
        return;
    }
    else if(low > high){
        cout<<"Your number has to be "<<low<<endl;
        return;
    }
    cout<<"Is your number "<<midpoint<<"? ('Y' for yes or any key for no)"<<endl;
    cin>>ans;


    if(toupper(ans) == 'Y'){
        cout<<"Yes I knew it!"<<endl;
        return;
    }
    else{
        cout<<"Is your number higher or lower?"<<endl;
        while(!(toupper(ans) == 'H' || toupper(ans) == 'L')){
            cin>>ans;
        }
        if(toupper(ans) == 'H'){
            return R16_Guess(midpoint+1, high);
        }
        else if(toupper(ans) == 'L'){
            return R16_Guess(low, midpoint-1);
        }

    }

}

void Cin(){
    int test;
    while(!(cin>>test)){
        cout<<"Invalid input please input a number"<<endl;
        cin.clear();
        cin.ignore();
    }
    Cin();

}
