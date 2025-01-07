#include <iostream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct User { // Create a structure
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

        para = line + " " + para ;;

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
    string para = text + userName.name  ;
    return para;
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

int checking_space(string name) {
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == ' ') {
            return 0; // Space found
        }
    }
    return 1; // No spaces found
}

void inputing_username(User &userNameInput){
    int spaceCheck = 0; // Initialize spaceCheck to indicate no spaces initially

    do {
        cout << "Please input user name: ";
        getline(cin, userNameInput.name);
        spaceCheck = checking_space(userNameInput.name); // Update spaceCheck
        if (spaceCheck == 0) {
            cout << "Please input no space in your username" << endl;
        }
    } while (spaceCheck == 0); // Loop until spaces are found
    cout << endl;
}

void storing_name_into_userNameStore_Struct(User userNameStore[],int arrUserSize, string arr[]) {
    for(int i = 0; i <= arrUserSize ; i++){
        userNameStore[i].name = arr[4*i];
    }

}

int size_of_userNameStore_Struct(User userNameStore[]) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if (userNameStore[i].name != "") {
            count ++;
        }
    }
    return count;
}

int size_of_array(string arr[]) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if (arr[i] != "") {
            count ++;
        }
    }
    return count;
}

void change_score_string_to_integer(int arrUserSize, string arr[], User userNameStore[]) {
    string arrEasyScore[1000];
    string arrMediumScore[1000];
    string arrHardScore[1000];


    for(int i = 0; i < arrUserSize ; i++){
        arrEasyScore [i] = arr[4*i + 1] ;
        arrMediumScore[i] = arr[4*i + 2] ;
        arrHardScore[i] = arr[4*i + 3];
    }

    int count = size_of_userNameStore_Struct(userNameStore);

    for(int i = 0; i < arrUserSize; i++) {
        userNameStore[i].easyScore = stoi(arrEasyScore[i]);
        userNameStore[i].mediumScore = stoi(arrMediumScore[i]);
        userNameStore[i].hardScore= stoi(arrHardScore[i]);
    }
}

void writing_into_file(User username[],   int sizeFinalUserNameStore) {
    ofstream outfile;
    outfile.open(R"(C:\Users\NGUYEN THIEN TU\Desktop\WordleGame\user.txt)");

    if (outfile.is_open()) {



            for (int i = 0; i < sizeFinalUserNameStore; i++){
                outfile << username[i].name;
                outfile <<" "<< username[i].easyScore;
                outfile <<" "<< username[i].mediumScore;
                outfile <<" "<< username[i].hardScore;
                outfile<< endl;
            }



        outfile.close();

    } else {
        cout << "Error opening file." << endl;
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
    int top1Score;
    int top2Score;
    int top3Score;
};

struct top3Medium {
    string top1;
    string top2;
    string top3;
    int top1Score;
    int top2Score;
    int top3Score;
};

struct top3Hard {
    string top1;
    string top2;
    string top3;
    int top1Score;
    int top2Score;
    int top3Score;
};

int size_of_struct(top3Easy top3E[]) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if (top3E[i].top1 != "") {
            count ++;
        }
    }
    return count;
}

User *sorting_easyScores_of_userNameStore_Struct_max_to_min( User userNameStore[], int size){
    User *sortedUserNameStore = new User[size];

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
        sortedUserNameStore[i] = userNameStore[i];
    }

    return sortedUserNameStore;

}

top3Easy* top3_easy_level(User userNameStore[], int size) {
    top3Easy *top3EasyLevel = new top3Easy[size];
    // Find all the top 1 score
    int countFirstTop =1;
    for(int i = 0; i < size; i++) {
        top3EasyLevel[0].top1 = userNameStore[0].name;
        top3EasyLevel[0].top1Score = userNameStore[0].easyScore;
        if(userNameStore[0].easyScore == userNameStore[i+1].easyScore) {
            top3EasyLevel[i+1].top1 = userNameStore[i+1].name;
            countFirstTop++;

        }
    }
    // cout << endl;
    // for (int i = 0; i < 10; i++) {
    //     cout << top3EasyLevel[i].top1<< " ";
    //
    // }

    // Find all the top 2 score
    int countSecondTop =1;
    for(int i = countFirstTop; i<size; i++) {
        top3EasyLevel[0].top2 = userNameStore[countFirstTop].name;
        top3EasyLevel[0].top2Score = userNameStore[countFirstTop].easyScore;
        if(userNameStore[countFirstTop].easyScore == userNameStore[i+1].easyScore) {
            for(int j =countSecondTop-1; j<countSecondTop; j++) { // từ từ làm lại =)))))))
                top3EasyLevel[j+1].top2 = userNameStore[i+1].name;
            }
            countSecondTop++;
        }
    }


    int countThirdTop =1;
    int totalTop1and2= countFirstTop+ countSecondTop;

    for(int i = totalTop1and2; i<size; i++) {
        top3EasyLevel[0].top3 = userNameStore[totalTop1and2].name;
        top3EasyLevel[0].top3Score = userNameStore[totalTop1and2].easyScore;
        if(userNameStore[totalTop1and2].easyScore == userNameStore[i+1].easyScore) {
            for(int j =countThirdTop-1; j<countThirdTop; j++) { // từ từ làm lại =)))))))
                top3EasyLevel[j+1].top3 = userNameStore[i+1].name;
            }
            countThirdTop++;
        }
    }
    for(int i = 0; i < size; i++) {
        top3EasyLevel[i] = top3EasyLevel[i];
    }
    return top3EasyLevel;
}

User *sorting_mediumScores_of_userNameStore_Struct_max_to_min( User userNameStore[], int size){
    User *sortedUserNameStore = new User[size];

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

    for(int i = 0; i < size; i++) {
        sortedUserNameStore[i] = userNameStore[i];
    }

    return sortedUserNameStore;
}

top3Medium* top3_medium_level(User userNameStore[], int size) {
    top3Medium *top3MediumLevel = new top3Medium[size];
    // Find all the top 1 score
    int countFirstTop =1;
    for(int i = 0; i < size; i++) {
        top3MediumLevel[0].top1 = userNameStore[0].name;
        top3MediumLevel[0].top1Score = userNameStore[0].mediumScore;
        if(userNameStore[0].mediumScore == userNameStore[i+1].mediumScore) {
            top3MediumLevel[i+1].top1 = userNameStore[i+1].name;
            countFirstTop++;

        }
    }
    // cout << endl;
    // for (int i = 0; i < 10; i++) {
    //     cout << top3EasyLevel[i].top1<< " ";
    //
    // }

    // Find all the top 2 score
    int countSecondTop =1;
    for(int i = countFirstTop; i<size; i++) {
        top3MediumLevel[0].top2 = userNameStore[countFirstTop].name;
        top3MediumLevel[0].top2Score = userNameStore[countFirstTop].mediumScore;
        if(userNameStore[countFirstTop].mediumScore == userNameStore[i+1].mediumScore) {
            for(int j =countSecondTop-1; j<countSecondTop; j++) { // từ từ làm lại =)))))))
                top3MediumLevel[j+1].top2 = userNameStore[i+1].name;
            }
            countSecondTop++;
        }
    }


    int countThirdTop =1;
    int totalTop1and2= countFirstTop+ countSecondTop;

    for(int i = totalTop1and2; i<size; i++) {
        top3MediumLevel[0].top3 = userNameStore[totalTop1and2].name;
        top3MediumLevel[0].top3Score = userNameStore[totalTop1and2].mediumScore;
        if(userNameStore[totalTop1and2].mediumScore == userNameStore[i+1].mediumScore) {
            for(int j =countThirdTop-1; j<countThirdTop; j++) { // từ từ làm lại =)))))))
                top3MediumLevel[j+1].top3 = userNameStore[i+1].name;
            }
            countThirdTop++;
        }
    }
    for(int i = 0; i < size; i++) {
        top3MediumLevel[i] = top3MediumLevel[i];
    }
    return top3MediumLevel;
}

User *sorting_hardScores_of_userNameStore_Struct_max_to_min( User userNameStore[], int size){
    User *sortedUserNameStore = new User[size];

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

    for(int i = 0; i < size; i++) {
        sortedUserNameStore[i] = userNameStore[i];
    }

    return sortedUserNameStore;

}

top3Hard* top3_hard_level(User userNameStore[], int size) {
    top3Hard *top3HardLevel = new top3Hard[size];
    // Find all the top 1 score
    int countFirstTop =1;
    for(int i = 0; i < size; i++) {
        top3HardLevel[0].top1 = userNameStore[0].name;
        top3HardLevel[0].top1Score = userNameStore[0].hardScore;
        if(userNameStore[0].hardScore == userNameStore[i+1].hardScore) {
            top3HardLevel[i+1].top1 = userNameStore[i+1].name;
            countFirstTop++;

        }
    }
    // cout << endl;
    // for (int i = 0; i < 10; i++) {
    //     cout << top3EasyLevel[i].top1<< " ";
    //
    // }

    // Find all the top 2 score
    int countSecondTop =1;
    for(int i = countFirstTop; i<size; i++) {
        top3HardLevel[0].top2 = userNameStore[countFirstTop].name;
        top3HardLevel[0].top2Score = userNameStore[countFirstTop].hardScore;
        if(userNameStore[countFirstTop].hardScore == userNameStore[i+1].hardScore) {
            for(int j =countSecondTop-1; j<countSecondTop; j++) { // từ từ làm lại =)))))))
                top3HardLevel[j+1].top2 = userNameStore[i+1].name;
            }
            countSecondTop++;
        }
    }


    int countThirdTop =1;
    int totalTop1and2= countFirstTop+ countSecondTop;

    for(int i = totalTop1and2; i<size; i++) {
        top3HardLevel[0].top3 = userNameStore[totalTop1and2].name;
        top3HardLevel[0].top3Score = userNameStore[totalTop1and2].hardScore;
        if(userNameStore[totalTop1and2].hardScore == userNameStore[i+1].hardScore) {
            for(int j =countThirdTop-1; j<countThirdTop; j++) { // từ từ làm lại =)))))))
                top3HardLevel[j+1].top3 = userNameStore[i+1].name;
            }
            countThirdTop++;
        }
    }
    for(int i = 0; i < size; i++) {
        top3HardLevel[i] = top3HardLevel[i];
    }
    return top3HardLevel;
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

void duplicate_username_modifying(User userNameStore[], User userNameInput, int userSize){
    int count = 0;

    for (int i = 0; i < userSize; i++){
        if(userNameStore[i].name != userNameInput.name){
            count++;

        }

    }

    if (count == userSize){
            userNameStore[userSize].name = userNameInput.name;
            userNameStore[userSize].easyScore = userNameInput.easyScore;
            userNameStore[userSize].mediumScore = userNameInput.mediumScore;
            userNameStore[userSize].hardScore = userNameInput.hardScore;
    }



    if (count == (userSize -1)){

        for(int i = 0; i < userSize ; i++){
            if( userNameInput.name == userNameStore[i].name){
                //cout << userNameInput.name << " " << userNameStore[i].name << i ;

                userNameStore[i].name = userNameInput.name;
                userNameStore[i].easyScore = userNameInput.easyScore;
                userNameStore[i].mediumScore = userNameInput.mediumScore;
                userNameStore[i].hardScore = userNameInput.hardScore;

            }
        }
    }
}

void print_easy_level(top3Easy top3E[], int size) {
    cout << endl;
    cout << "EASY LEVEL"<< endl;

    int sizeEasyTop1 = 0;
    for (int i = 0; i < size; i++) {
        if(top3E[i].top1 != "" ){
            sizeEasyTop1++;
        }

    }
    cout << "Top 1 - Score: " << top3E[0].top1Score << endl;
    cout << " PLayer: " ;
    for(int i = 0; i < sizeEasyTop1; i++) {
        cout << " "<< top3E[i].top1;

    }
    cout << endl;

    int sizeEasyTop2 = 0;
    for (int i = 0; i < size; i++) {
        if(top3E[i].top2 != "" ){
            sizeEasyTop2++;
        }

    }
    cout << "Top 2 - Score: " << top3E[0].top2Score << endl;
    cout << " PLayer: " ;
    for(int i = 0; i < sizeEasyTop2; i++) {
        cout <<" "<< top3E[i].top2;

    }

    int sizeEasyTop3 = 0;
    for (int i = 0; i < size; i++) {
        if(top3E[i].top3 != "" ){
            sizeEasyTop3++;
        }

    }
    cout << endl;
    cout << "Top 3 - Score: " << top3E[0].top3Score << endl;
    cout << " PLayer: " ;
    for(int i = 0; i < sizeEasyTop3; i++) {
        cout << " "<<top3E[i].top3 ;

    }
    cout << endl;
}

void print_medium_level(top3Medium top3M[], int size) {
    cout << endl;
    cout << "MEDIUM LEVEL"<< endl;

    int sizeMediumTop1 = 0;
    for (int i = 0; i < size; i++) {
        if(top3M[i].top1 != "" ){
            sizeMediumTop1++;
        }

    }
    cout << "Top 1 - Score: " << top3M[0].top1Score << endl;
    cout << " PLayer: " ;
    for(int i = 0; i < sizeMediumTop1; i++) {
        cout << " "<< top3M[i].top1;

    }

    cout << endl;

    int sizeMediumTop2 = 0;
    for (int i = 0; i < size; i++) {
        if(top3M[i].top2 != "" ){
            sizeMediumTop2++;
        }

    }
    cout << "Top 2 - Score: " << top3M[0].top2Score << endl;
    cout << " PLayer: " ;
    for(int i = 0; i < sizeMediumTop2; i++) {
        cout <<" "<< top3M[i].top2;

    }

    cout << endl;

    int sizeMediumTop3 = 0;
    for (int i = 0; i < size; i++) {
        if(top3M[i].top3 != "" ){
            sizeMediumTop3++;
        }

    }
    cout << "Top 3 - Score: " << top3M[0].top3Score << endl;
    cout << " PLayer: ";
    for(int i = 0; i < sizeMediumTop3; i++) {
        cout << " "<<top3M[i].top3 ;

    }
    cout << endl;;
}

void print_hard_level(top3Hard top3H[], int size) {
    cout << endl;
    cout << "HARD LEVEL"<< endl;

    int sizeHardTop1 = 0;
    for (int i = 0; i < size; i++) {
        if(top3H[i].top1 != "" ){
            sizeHardTop1++;
        }

    }
    cout << "Top 1 - Score: " << top3H[0].top1Score << endl;
    cout << " PLayer: " ;
    for(int i = 0; i < sizeHardTop1; i++) {
        cout << " "<< top3H[i].top1;

    }

    cout << endl;

    int sizeHardTop2 = 0;
    for (int i = 0; i < size; i++) {
        if(top3H[i].top2 != "" ){
            sizeHardTop2++;
        }

    }
    cout << "Top 2 - Score: " << top3H[0].top2Score << endl;
    cout << " PLayer: " ;

    for(int i = 0; i < sizeHardTop2; i++) {
        cout <<" "<< top3H[i].top2;

    }

    cout << endl;
    int sizeHardTop3 = 0;
    for (int i = 0; i < size; i++) {
        if(top3H[i].top3 != "" ){
            sizeHardTop3++;
        }

    }
    cout << "Top 3 - Score: " << top3H[0].top3Score << endl;
    cout << " PLayer: ";
    for(int i = 0; i < sizeHardTop3; i++) {

        cout << " "<<top3H[i].top3 ;

    }

    cout << endl;

}

// Function to check for spaces in the string

int main()
{
    User userNameInput;
    User userNameStore[1000];

    string arrUser[1000];
    int arraySize = 0;

    userNameInput.easyScore = 6;
    userNameInput.mediumScore = 7;
    userNameInput.hardScore = 10;

    string text = reading_file(R"(C:\Users\NGUYEN THIEN TU\Desktop\WordleGame\user.txt)");

    split(arrUser,text, arraySize);

    int arrUserSize = size_of_array(arrUser);

    int userSize = arrUserSize/4;

    change_score_string_to_integer(userSize, arrUser, userNameStore);

    storing_name_into_userNameStore_Struct( userNameStore, userSize, arrUser );

    inputing_username(userNameInput);

    duplicate_username_modifying(userNameStore, userNameInput, userSize);

    int sizeFinalUserNameStore = size_of_userNameStore_Struct(userNameStore);

    writing_into_file(userNameStore,sizeFinalUserNameStore);

    User *userSortedEasyLevel = sorting_easyScores_of_userNameStore_Struct_max_to_min(userNameStore, sizeFinalUserNameStore);
    User *userSortedMediumLevel = sorting_mediumScores_of_userNameStore_Struct_max_to_min(userNameStore, sizeFinalUserNameStore);
    User *userSortedHardLevel = sorting_hardScores_of_userNameStore_Struct_max_to_min(userNameStore,sizeFinalUserNameStore);

    top3Easy  *top3E = top3_easy_level(userSortedEasyLevel, sizeFinalUserNameStore);
    print_easy_level(top3E,sizeFinalUserNameStore);

    top3Medium *top3M = top3_medium_level(userSortedMediumLevel, sizeFinalUserNameStore);
    print_medium_level(top3M, sizeFinalUserNameStore);

    top3Hard *top3H = top3_hard_level(userSortedHardLevel,sizeFinalUserNameStore);
    print_hard_level(top3H, sizeFinalUserNameStore);

    return 0;
}