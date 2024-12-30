
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct User { // tạo ra một cấu trúc,
    string name;
    int easyScore;
    int mediumScore;
    int hardScore;
};

string reading_file(string filename) {
    string printChosenLevel ;

    ifstream instance;
    instance.open(filename);

    string line;
    string para;
    while (getline(instance, line)) {

        para = line + "\n" + para ;;

    }

    instance.close();

    return para;
}

string attaching_in_one_line(string filename) {
    string printChosenLevel ;

    ifstream instance;
    instance.open(filename);

    string line;
    string para;
    while (getline(instance, line)) {

        para = line + " " + para ;;

    }

    instance.close();

    return para;
}

string attaching_string(User userName, string text) {
    string para = text + userName.name;
    return para;
}

void writing_into_file(string attaching, User username) {
    ofstream outfile;
    outfile.open(R"(C:\Users\NGUYEN THIEN TU\Desktop\WordleGame\user.txt)");


    if (outfile.is_open()) {
        outfile << attaching;
        outfile <<" "<< username.easyScore;
        outfile <<" "<< username.mediumScore;
        outfile <<" "<< username.hardScore;
        outfile.close();

    } else {
        cout << "Error opening file." << endl;
    }

}

void split(string arr[],string &text, int &arraySize){
    char *word= new char[10];//  khởi tạo word
    int wordSize = 0;// kích cỡ word

    for(int i=0;i<11;i++){// dam bao 100& empty
        word[i] = '\0';
    }

    if(text[text.size()] != ' '){ // them space vao cuoi string
        text[text.size()] = ' ';
    }

    for(int i =0;i<text.size()+1;i++){ //
        if(text[i] != ' ' ){
            word[wordSize] = text[i];
            wordSize++;

        }else{
            arr[arraySize]=word;
            arraySize++;

            for(int i=0;i<10;i++){
                word[i] = '\0';
            }

            wordSize=0;
        }
    }
}

void storing_name_into_userNameStore_Struct(User userNameStore[], string textString, string arr[]) {
    for(int i = 0; i < textString.size() ; i++){
        userNameStore[i].name = arr[4*i];
    }

}

int size_of_serNameStore_Struct(User userNameStore[]) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if (userNameStore[i].name != "") {
            count ++;
        }
    }
    return count;
}

void change_score_string_to_integer(string textString, string arr[], User userNameStore[]) {
    string arrEasyScore[1000];
    string arrMediumScore[1000];
    string arrHardScore[1000];


    for(int i = 0; i < textString.size() ; i++){
        arrEasyScore [i] = arr[4*i + 1] ;
        arrMediumScore[i] = arr[4*i + 2] ;
        arrHardScore[i] = arr[4*i + 3];
    }

    int count = size_of_serNameStore_Struct(userNameStore);

    for(int i = 0; i < count; i++) {
        userNameStore[i].easyScore = stoi(arrEasyScore[i]);
        userNameStore[i].mediumScore = stoi(arrMediumScore[i]);
        userNameStore[i].hardScore= stoi(arrHardScore[i]);
    }
}

void swaping_integer(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swaping_string(string *a, string *b){
    string temp = *a;
    *a = *b;
    *b = temp;
}

struct top3Easy {
    string top1;
    string top2;
    string top3;
};

void sorting_easyScores_of_userNameStore_Struct(top3Easy top3EasyLevel[], User userNameStore[], int size){
    //User *sortedUserNameStore = new User[size];

    for(int i = 0; i< size; i++){
        for(int j = i + 1; j < size; j++){
            if (userNameStore[i].easyScore < userNameStore[j].easyScore){
                swaping_string(&userNameStore[i].name,&userNameStore[j].name);
                swaping_integer(&userNameStore[i].easyScore,&userNameStore[j].easyScore);
                swaping_integer(&userNameStore[i].mediumScore,&userNameStore[j].mediumScore);
                swaping_integer(&userNameStore[i].hardScore,&userNameStore[j].hardScore);

            }
        }
    }

    for(int i = 0; i < size; i++) {
        top3EasyLevel[0].top1 = userNameStore[0].name;
        if(userNameStore[0].easyScore == userNameStore[i+1].easyScore) {
            top3EasyLevel[i+1].top1 = userNameStore[i+1].name;
        }
    }



    // for(int i = 0; i < size; i++) {
    //     sortedUserNameStore[i] = userNameStore[i];
    // }

    // return sortedUserNameStore;

}

void sorting_mediumScores_of_userNameStore_Struct(User userNameStore[], int size){
    //User *sortedUserNameStore = new User[size];

    for(int i = 0; i< size; i++){
        for(int j = i + 1; j < size; j++){
            if (userNameStore[i].mediumScore < userNameStore[j].mediumScore){
                swaping_string(&userNameStore[i].name,&userNameStore[j].name);
                swaping_integer(&userNameStore[i].easyScore,&userNameStore[j].easyScore);
                swaping_integer(&userNameStore[i].mediumScore,&userNameStore[j].mediumScore);
                swaping_integer(&userNameStore[i].hardScore,&userNameStore[j].hardScore);

            }
        }
    }

    // for(int i = 0; i < size; i++) {
    //     sortedUserNameStore[i] = userNameStore[i];
    // }

    // return sortedUserNameStore;
}

void sorting_hardScores_of_userNameStore_Struct(User userNameStore[], int size){
    //User *sortedUserNameStore = new User[size];

    for(int i = 0; i< size; i++){
        for(int j = i + 1; j < size; j++){
            if (userNameStore[i].hardScore < userNameStore[j].hardScore){
                swaping_string(&userNameStore[i].name,&userNameStore[j].name);
                swaping_integer(&userNameStore[i].easyScore,&userNameStore[j].easyScore);
                swaping_integer(&userNameStore[i].mediumScore,&userNameStore[j].mediumScore);
                swaping_integer(&userNameStore[i].hardScore,&userNameStore[j].hardScore);

            }
        }
    }

    // for(int i = 0; i < size; i++) {
    //     sortedUserNameStore[i] = userNameStore[i];
    // }

    // return sortedUserNameStore;
}

int main() {

    User userNameInput;
    User userNameStore[1000];
    top3Easy top3ELevel[1000];

    string arrUser[1000];
    int arraySize = 0;

    userNameInput.easyScore = 6;
    userNameInput.mediumScore = 7;
    userNameInput.hardScore = 10;

    cout << "Welcome to Wordle Game" << endl;

    cout << "Please input user name: ";

    getline(cin, userNameInput.name);

    string text = reading_file(R"(C:\Users\NGUYEN THIEN TU\Desktop\WordleGame\user.txt)");

    string attaching = attaching_string( userNameInput, text);

    writing_into_file(attaching,  userNameInput) ;

    string textString = attaching_in_one_line(R"(C:\Users\NGUYEN THIEN TU\Desktop\WordleGame\user.txt)");

    split(arrUser,textString, arraySize);

    storing_name_into_userNameStore_Struct( userNameStore, textString, arrUser );

    change_score_string_to_integer(textString, arrUser, userNameStore);

    int size = size_of_serNameStore_Struct(userNameStore);




    cout<< endl;
    for(int i = 0; i < size; i++) {
        cout << userNameStore[i].name << " ";
    }

    cout<< endl;
    for(int i = 0; i < size; i++) {
        cout << userNameStore[i].easyScore << " ";
    }

    cout << endl;
    for(int i = 0; i < size; i++) {
        cout << userNameStore[i].mediumScore<< " ";
    }

    cout << endl;
    for(int i = 0; i < size; i++) {
        cout << userNameStore[i].hardScore << " ";
    }

    cout << endl;

    sorting_easyScores_of_userNameStore_Struct(top3ELevel, userNameStore, size);


    return 0;
}
