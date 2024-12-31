
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

void print_easy_level(top3Easy top3E[], int size) {
    cout << endl;
    cout << "EASY LEVEL"<< endl;

    cout << "Top 1 - Player: ";

    for(int i = 0; i < size; i++) {
        cout << top3E[i].top1 << " ";

    }
    cout << endl;
    cout << "  Score: "<<top3E[0].top1Score;;

    cout << endl;
    cout << "Top 2 - Player: ";
    for(int i = 0; i < size; i++) {
        cout << top3E[i].top2 << " ";

    }
    cout << endl;
    cout << "  Score: "<<top3E[0].top2Score;;

    cout << endl;
    cout << "Top 3 - Player: ";
    for(int i = 0; i < size; i++) {
        cout << top3E[i].top3 << " ";

    }
    cout << endl;
    cout << "  Score: "<<top3E[0].top3Score;;
}

void print_medium_level(top3Medium top3M[], int size) {
    cout << endl;
    cout << endl;

    cout << "MEDIUM LEVEL"<< endl;
    cout << "Top 1 - Player: ";
    for(int i = 0; i < size; i++) {
        cout << top3M[i].top1 << " ";

    }
    cout << endl;
    cout << "  Score: "<<top3M[0].top1Score;;

    cout << endl;
    cout << "Top 2: ";
    for(int i = 0; i < size; i++) {
        cout << top3M[i].top2 << " ";

    }
    cout << endl;
    cout << "  Score: "<<top3M[0].top2Score;;

    cout << endl;
    cout << "Top 3: ";
    for(int i = 0; i < size; i++) {
        cout << top3M[i].top3 << " ";

    }
    cout << endl;
    cout << "  Score: "<<top3M[0].top3Score;;
}

void print_hard_level(top3Hard top3H[], int size) {
    cout << endl;
    cout << endl;
    cout << "HARD LEVEL"<< endl;
    cout << "Top 1 - Player: ";
    for(int i = 0; i < size; i++) {
        cout << top3H[i].top1 << " ";

    }
    cout << endl;
    cout << "  Score: "<<top3H[0].top1Score;;

    cout << endl;
    cout << "Top 2 - Player: ";
    for(int i = 0; i < size; i++) {
        cout << top3H[i].top2 << " ";

    }
    cout << endl;
    cout << "  Score: "<<top3H[0].top2Score;;
    cout << endl;
    cout << "Top 3 - Player: ";
    for(int i = 0; i < size; i++) {
        cout << top3H[i].top3 << " ";

    }
    cout << endl;
    cout << "  Score: "<<top3H[0].top3Score;;
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

    User *userSortedEasyLevel = new User[1000];
    User *userSortedMediumLevel = new User[1000];
    User *userSortedHardLevel = new User[1000];

    userSortedEasyLevel = sorting_easyScores_of_userNameStore_Struct_max_to_min(userNameStore, size);
    userSortedMediumLevel = sorting_mediumScores_of_userNameStore_Struct_max_to_min(userNameStore, size);
    userSortedHardLevel = sorting_hardScores_of_userNameStore_Struct_max_to_min(userNameStore, size);


    top3Easy  *top3E = new top3Easy[1000];
    top3E = top3_easy_level(userSortedEasyLevel, size);
    print_easy_level(top3E, size);

    top3Medium *top3M = new top3Medium[1000];
    top3M = top3_medium_level(userSortedMediumLevel, size);
    print_medium_level(top3M, size);

    top3Hard *top3H = new top3Hard[1000];
    top3H = top3_hard_level(userSortedHardLevel, size);
    print_hard_level(top3H, size);


    return 0;
}
