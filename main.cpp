#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // For srand and rand

using namespace std;

struct User {
    string name;
    int easyScore = 0;
    int mediumScore = 0;
    int hardScore = 0;
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

void duplicate_username_modifying(User userNameStore[], User &userNameInput, int userSize){
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


            }
        }
    }
}

void inputing_scores(User userNameStore[], User &userNameInput, int userSize, int level){
    int count = 0;

    for (int i = 0; i < userSize; i++){
        if(userNameStore[i].name != userNameInput.name){
            count++;

        }

    }

    if (count == userSize){
        if (level == 1) {
            userNameStore[userSize].easyScore = userNameInput.easyScore;
        }
        if (level == 2) {
            userNameStore[userSize].mediumScore = userNameInput.mediumScore;
        }
        if (level == 3) {
            userNameStore[userSize].hardScore = userNameInput.hardScore;
        }

    }



    if (count == (userSize -1)){

        for(int i = 0; i < userSize ; i++){
            if( userNameInput.name == userNameStore[i].name){
                if (level == 1) {
                    userNameStore[i].easyScore = userNameInput.easyScore;
                }
                if (level == 2) {
                    userNameStore[i].mediumScore = userNameInput.mediumScore;
                }
                if (level == 3) {
                    userNameStore[i].hardScore = userNameInput.hardScore;
                }

            }
        }
    }
}

// Read words from file and store in an array
void readWordsFromFile(string filename, string words[], int &wordCount, int maxWords) {
    ifstream file(filename);
    wordCount = 0;
    while (file >> words[wordCount] && wordCount < maxWords) {
        wordCount++;
    }
    file.close();
}

void getRandomWords(string words[], string randomWords[], int wordCount, int numWords) {
    int indices[wordCount];
    for (int i = 0; i < wordCount; i++) {
        indices[i] = i;
    }

    // Shuffle indices
    for (int i = 0; i < wordCount; i++) {
        int j = rand() % wordCount;
        swap(indices[i], indices[j]);
    }

    for (int i = 0; i < numWords; i++) {
        randomWords[i] = words[indices[i]];
    }
}

string obscureWord(const string &word) {
    int len = word.length();
    if (len < 2) return word; // Do not obscure if the word is too short

    int index = rand() % len; // Randomly choose a position to obscure
    string obscuredWord = word;
    obscuredWord[index] = '_';
    return obscuredWord;
}

int play_easy_game(int choice) {
    string easyWords[50];
    int easyWordCount = 0;
    int score = 0;
    if (choice == 1) {
        readWordsFromFile(R"(C:\Users\NGUYEN THIEN TU\Desktop\WordleGame\easy.txt)", easyWords, easyWordCount, 50);
        string randomWords[10];
        getRandomWords(easyWords, randomWords, easyWordCount, 10);

        cin.ignore(); // Clear input buffer before using getline

        for (int i = 0; i < 10; i++) {
            string obscuredWord = obscureWord(randomWords[i]);
            cout << "Obscured word: " << obscuredWord << endl;

            string guess;
            cout << "Guess the word: ";
            getline(cin, guess);

            if (guess == randomWords[i]) {
                cout << "Correct!" << endl;
                score++;
            } else {
                cout << "Wrong! The correct word was: " << randomWords[i] << endl;
            }
        }
        cout << "Game over! Your score: " << score << "/10" << endl;
    }
    return score;

}

int play_medium_game( int choice) {

    string mediumWords[80];
    int mediumWordCount = 0;
    int score = 0;

    if (choice == 2) {
        readWordsFromFile(R"(C:\Users\NGUYEN THIEN TU\Desktop\WordleGame\medium.txt)", mediumWords, mediumWordCount, 80);
        string randomWords[15];
        getRandomWords(mediumWords, randomWords, mediumWordCount, 15);

        cin.ignore(); // Clear input buffer before using getline

        for (int i = 0; i < 15; i++) {
            string obscuredWord = obscureWord(randomWords[i]);
            cout << "Obscured word: " << obscuredWord << endl;

            string guess;
            cout << "Guess the word: ";
            getline(cin, guess);

            if (guess == randomWords[i]) {
                cout << "Correct!" << endl;
                score++;
            } else {
                cout << "Wrong! The correct word was: " << randomWords[i] << endl;
            }
        }
        cout << "Game over! Your score: " << score << "/15" << endl;
    }
    return score;
}

int play_hard_game(User &user, int choice) {

    string hardWords[105];
    int hardWordCount = 0;
    int score = 0;


    if (choice == 3) {
        readWordsFromFile(R"(C:\Users\NGUYEN THIEN TU\Desktop\WordleGame\hard.txt)", hardWords, hardWordCount, 105);
        string randomWords[20];
        getRandomWords(hardWords, randomWords, hardWordCount, 20);

        cin.ignore(); // Clear input buffer before using getline

        for (int i = 0; i < 20; i++) {
            string obscuredWord = obscureWord(randomWords[i]);
            cout << "Obscured word: " << obscuredWord << endl;

            string guess;
            cout << "Guess the word: ";
            getline(cin, guess);

            if (guess == randomWords[i]) {
                cout << "Correct!" << endl;
                score++;
            } else {
                cout << "Wrong! The correct word was: " << randomWords[i] << endl;
            }
        }
        //user.hardScore = max(user.hardScore, score);
        cout << "Game over! Your score: " << score << "/20" << endl;

    }
    return score;
}

void swap_integer(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_string(string *a, string *b){
    string temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_userNameStore(User userNameStore[], int userSize) {

    for (int i = 0; i < userSize / 2; i++) {
        swap_string(&userNameStore[i].name, &userNameStore[userSize - i - 1].name);
        swap_integer(&userNameStore[i].easyScore, &userNameStore[userSize - i - 1].easyScore);
        swap_integer(&userNameStore[i].mediumScore, &userNameStore[userSize - i - 1].mediumScore);
        swap_integer(&userNameStore[i].hardScore, &userNameStore[userSize - i - 1].hardScore);


    }

}

void writing_into_file(User username[] ) {
    ofstream outfile;
    outfile.open(R"(C:\Users\NGUYEN THIEN TU\Desktop\WordleGame\user.txt)");

    if (outfile.is_open()) {

        for (int i = 0; i <1; i++){
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

void inputing_level(int &level) {
    cout << "Level 1" << endl;
    cout << "Level 2" << endl;
    cout << "Level 3" << endl;

    do {
        cout << "Please input the level (1, 2, or 3): ";
        cin >> level;

        if (level != 1 && level != 2 && level != 3) {
            cout << "Invalid input. Please enter 1, 2, or 3." << endl;
        }
    } while (level != 1 && level != 2 && level != 3);
}

void generate_level_and_playing_game(int level, int &storingScore, User &userNameInput ) {
    if (level == 1) {
        storingScore= play_easy_game(level);
        userNameInput.easyScore = storingScore ;
    }
    else if (level == 2) {
        storingScore = play_medium_game(level);
        userNameInput.mediumScore = storingScore ;
    }
    else if (level == 3) {
        storingScore = play_hard_game(userNameInput, level);
        userNameInput.hardScore = storingScore;

    }
}
// top3 players and scores
struct top3Ranked {
    string top1Player;
    string top2Player;
    string top3Player;
    int top1Score;
    int top2Score;
    int top3Score;
};

int size_of_struct(top3Ranked top3E[]) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if (top3E[i].top1Player != "") {
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
                swap_string(&userNameStore[i].name,&userNameStore[j].name);
                swap_integer(&userNameStore[i].easyScore,&userNameStore[j].easyScore);
                swap_integer(&userNameStore[i].mediumScore,&userNameStore[j].mediumScore);
                swap_integer(&userNameStore[i].hardScore,&userNameStore[j].hardScore);

            }
        }
    }

    for(int i = 0; i < size; i++) {
        sortedUserNameStore[i] = userNameStore[i];
    }

    return sortedUserNameStore;

}

top3Ranked* top3_easy_level(User userNameStore[], int size) {
    top3Ranked *top3EasyLevel = new top3Ranked[size];
    // Find all the top 1 score
    int countFirstTop =1;
    for(int i = 0; i < size; i++) {
        top3EasyLevel[0].top1Player = userNameStore[0].name;
        top3EasyLevel[0].top1Score = userNameStore[0].easyScore;
        if(userNameStore[0].easyScore == userNameStore[i+1].easyScore) {
            top3EasyLevel[i+1].top1Player = userNameStore[i+1].name;
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
        top3EasyLevel[0].top2Player = userNameStore[countFirstTop].name;
        top3EasyLevel[0].top2Score = userNameStore[countFirstTop].easyScore;
        if(userNameStore[countFirstTop].easyScore == userNameStore[i+1].easyScore) {
            for(int j =countSecondTop-1; j<countSecondTop; j++) { // từ từ làm lại =)))))))
                top3EasyLevel[j+1].top2Player = userNameStore[i+1].name;
            }
            countSecondTop++;
        }
    }


    int countThirdTop =1;
    int totalTop1and2= countFirstTop+ countSecondTop;

    for(int i = totalTop1and2; i<size; i++) {
        top3EasyLevel[0].top3Player = userNameStore[totalTop1and2].name;
        top3EasyLevel[0].top3Score = userNameStore[totalTop1and2].easyScore;
        if(userNameStore[totalTop1and2].easyScore == userNameStore[i+1].easyScore) {
            for(int j =countThirdTop-1; j<countThirdTop; j++) { // từ từ làm lại =)))))))
                top3EasyLevel[j+1].top3Player = userNameStore[i+1].name;
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
                swap_string(&userNameStore[i].name,&userNameStore[j].name);
                swap_integer(&userNameStore[i].easyScore,&userNameStore[j].easyScore);
                swap_integer(&userNameStore[i].mediumScore,&userNameStore[j].mediumScore);
                swap_integer(&userNameStore[i].hardScore,&userNameStore[j].hardScore);

            }
        }
    }

    for(int i = 0; i < size; i++) {
        sortedUserNameStore[i] = userNameStore[i];
    }

    return sortedUserNameStore;
}

top3Ranked* top3_medium_level(User userNameStore[], int size) {
    top3Ranked *top3MediumLevel = new top3Ranked[size];
    // Find all the top 1 score
    int countFirstTop =1;
    for(int i = 0; i < size; i++) {
        top3MediumLevel[0].top1Player = userNameStore[0].name;
        top3MediumLevel[0].top1Score = userNameStore[0].mediumScore;
        if(userNameStore[0].mediumScore == userNameStore[i+1].mediumScore) {
            top3MediumLevel[i+1].top1Player = userNameStore[i+1].name;
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
        top3MediumLevel[0].top2Player = userNameStore[countFirstTop].name;
        top3MediumLevel[0].top2Score = userNameStore[countFirstTop].mediumScore;
        if(userNameStore[countFirstTop].mediumScore == userNameStore[i+1].mediumScore) {
            for(int j =countSecondTop-1; j<countSecondTop; j++) { // từ từ làm lại =)))))))
                top3MediumLevel[j+1].top2Player = userNameStore[i+1].name;
            }
            countSecondTop++;
        }
    }


    int countThirdTop =1;
    int totalTop1and2= countFirstTop+ countSecondTop;

    for(int i = totalTop1and2; i<size; i++) {
        top3MediumLevel[0].top3Player = userNameStore[totalTop1and2].name;
        top3MediumLevel[0].top3Score = userNameStore[totalTop1and2].mediumScore;
        if(userNameStore[totalTop1and2].mediumScore == userNameStore[i+1].mediumScore) {
            for(int j =countThirdTop-1; j<countThirdTop; j++) { // từ từ làm lại =)))))))
                top3MediumLevel[j+1].top3Player = userNameStore[i+1].name;
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
                swap_string(&userNameStore[i].name,&userNameStore[j].name);
                swap_integer(&userNameStore[i].easyScore,&userNameStore[j].easyScore);
                swap_integer(&userNameStore[i].mediumScore,&userNameStore[j].mediumScore);
                swap_integer(&userNameStore[i].hardScore,&userNameStore[j].hardScore);

            }
        }
    }

    for(int i = 0; i < size; i++) {
        sortedUserNameStore[i] = userNameStore[i];
    }

    return sortedUserNameStore;

}

top3Ranked* top3_hard_level(User userNameStore[], int size) {
    top3Ranked *top3HardLevel = new top3Ranked[size];
    // Find all the top 1 score
    int countFirstTop =1;
    for(int i = 0; i < size; i++) {
        top3HardLevel[0].top1Player = userNameStore[0].name;
        top3HardLevel[0].top1Score = userNameStore[0].hardScore;
        if(userNameStore[0].hardScore == userNameStore[i+1].hardScore) {
            top3HardLevel[i+1].top1Player = userNameStore[i+1].name;
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
        top3HardLevel[0].top2Player = userNameStore[countFirstTop].name;
        top3HardLevel[0].top2Score = userNameStore[countFirstTop].hardScore;
        if(userNameStore[countFirstTop].hardScore == userNameStore[i+1].hardScore) {
            for(int j =countSecondTop-1; j<countSecondTop; j++) { // từ từ làm lại =)))))))
                top3HardLevel[j+1].top2Player = userNameStore[i+1].name;
            }
            countSecondTop++;
        }
    }


    int countThirdTop =1;
    int totalTop1and2= countFirstTop+ countSecondTop;

    for(int i = totalTop1and2; i<size; i++) {
        top3HardLevel[0].top3Player = userNameStore[totalTop1and2].name;
        top3HardLevel[0].top3Score = userNameStore[totalTop1and2].hardScore;
        if(userNameStore[totalTop1and2].hardScore == userNameStore[i+1].hardScore) {
            for(int j =countThirdTop-1; j<countThirdTop; j++) { // từ từ làm lại =)))))))
                top3HardLevel[j+1].top3Player = userNameStore[i+1].name;
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
                swap_string(&userNameStore[i].name,&userNameStore[j].name);
                swap_integer(&userNameStore[i].easyScore,&userNameStore[j].easyScore);
                swap_integer(&userNameStore[i].mediumScore,&userNameStore[j].mediumScore);
                swap_integer(&userNameStore[i].hardScore,&userNameStore[j].hardScore);

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
                swap_string(&userNameStore[i].name,&userNameStore[j].name);
                swap_integer(&userNameStore[i].easyScore,&userNameStore[j].easyScore);
                swap_integer(&userNameStore[i].mediumScore,&userNameStore[j].mediumScore);
                swap_integer(&userNameStore[i].hardScore,&userNameStore[j].hardScore);

            }
        }
    }

    // for(int i = 0; i < size; i++) {
    //     sortedUserNameStore[i] = userNameStore[i];
    // }

    // return sortedUserNameStore;
}

void print_easy_level(top3Ranked top3E[], int size) {
    cout << endl;
    cout << "EASY LEVEL"<< endl;

    int sizeEasyTop1 = 0;
    for (int i = 0; i < size; i++) {
        if(top3E[i].top1Player != "" ){
            sizeEasyTop1++;
        }

    }
    if(top3E[0].top1Score > 0 && top3E[0].top1Score <= 10) {
        cout << "Top 1 - Score: " << top3E[0].top1Score << endl;
        cout << " PLayer: " ;
        for(int i = 0; i < sizeEasyTop1; i++) {
            cout <<" "<< top3E[i].top1Player;

        }
    }
    else {
        cout << "Top 1 - Score: " << endl;
        cout << " PLayer: " ;
    }
    cout << endl;

    int sizeEasyTop2 = 0;
    for (int i = 0; i < size; i++) {
        if(top3E[i].top2Player != "" ){
            sizeEasyTop2++;
        }

    }


    if(top3E[0].top2Score > 0 && top3E[0].top2Score <= 15) {
        cout << "Top 2 - Score: " << top3E[0].top2Score << endl;
        cout << " PLayer: " ;
        for(int i = 0; i < sizeEasyTop2; i++) {
            cout <<" "<< top3E[i].top2Player;

        }
    }
    else {
        cout << "Top 2 - Score: " << endl;
        cout << " PLayer: " ;
    }

    cout << endl;

    int sizeEasyTop3 = 0;
    for (int i = 0; i < size; i++) {
        if(top3E[i].top3Player != "" ){
            sizeEasyTop3++;
        }

    }
    if(top3E[0].top3Score > 0 && top3E[0].top3Score <= 20) {
        cout << "Top 3 - Score: " << top3E[0].top3Score << endl;
        cout << " PLayer: " ;
        for(int i = 0; i < sizeEasyTop3; i++) {
            cout <<" "<< top3E[i].top3Player;

        }
    }
    else {
        cout << "Top 3 - Score: " << endl;
        cout << " PLayer: " ;
    }
    cout << endl;
}

void print_medium_level(top3Ranked top3M[], int size) {
    cout << endl;
    cout << "MEDIUM LEVEL"<< endl;

    int sizeMediumTop1 = 0;
    for (int i = 0; i < size; i++) {
        if(top3M[i].top1Player != "" ){
            sizeMediumTop1++;
        }

    }
    if(top3M[0].top1Score > 0 && top3M[0].top1Score <= 15) {
        cout << "Top 1 - Score: " << top3M[0].top1Score << endl;
        cout << " PLayer: " ;
        for(int i = 0; i < sizeMediumTop1; i++) {
            cout <<" "<< top3M[i].top1Player;

        }
    }
    else {
        cout << "Top 1 - Score: " << endl;
        cout << " PLayer: " ;
    }

    cout << endl;

    int sizeMediumTop2 = 0;
    for (int i = 0; i < size; i++) {
        if(top3M[i].top2Player != "" ){
            sizeMediumTop2++;
        }

    }
    if(top3M[0].top2Score > 0 && top3M[0].top2Score <= 15) {
        cout << "Top 2 - Score: " << top3M[0].top2Score << endl;
        cout << " PLayer: " ;
        for(int i = 0; i < sizeMediumTop2; i++) {
            cout <<" "<< top3M[i].top2Player;

        }
    }
    else {
        cout << "Top 2 - Score: " << endl;
        cout << " PLayer: " ;
    }

    cout << endl;

    int sizeMediumTop3 = 0;
    for (int i = 0; i < size; i++) {
        if(top3M[i].top3Player != "" ){
            sizeMediumTop3++;
        }

    }
    if(top3M[0].top3Score > 0 && top3M[0].top3Score <= 15) {
        cout << "Top 3 - Score: " << top3M[0].top3Score << endl;
        cout << " PLayer: " ;
        for(int i = 0; i < sizeMediumTop3; i++) {
            cout <<" "<< top3M[i].top3Player;

        }
    }
    else {
        cout << "Top 3 - Score: " << endl;
        cout << " PLayer: " ;
    }
    cout << endl;;
}

void print_hard_level(top3Ranked top3H[], int size) {
    cout << endl;
    cout << "HARD LEVEL"<< endl;

    int sizeHardTop1 = 0;
    for (int i = 0; i < size; i++) {
        if(top3H[i].top1Player != "" ){
            sizeHardTop1++;
        }

    }
    if(top3H[0].top1Score > 0 && top3H[0].top1Score <= 20) {
        cout << "Top 1 - Score: " << top3H[0].top1Score << endl;
        cout << " PLayer: " ;
        for(int i = 0; i < sizeHardTop1; i++) {
            cout <<" "<< top3H[i].top1Player;

        }
    }
    else {
        cout << "Top 1 - Score: " << endl;
        cout << " PLayer: " ;
    }

    cout << endl;

    int sizeHardTop2 = 0;
    for (int i = 0; i < size; i++) {
        if(top3H[i].top2Player != "" ){
            sizeHardTop2++;
        }

    }

    if(top3H[0].top2Score > 0 && top3H[0].top2Score <= 20) {
        cout << "Top 2 - Score: " << top3H[0].top2Score << endl;
        cout << " PLayer: " ;
        for(int i = 0; i < sizeHardTop2; i++) {
            cout <<" "<< top3H[i].top2Player;

        }
    }
    else {
        cout << "Top 2 - Score: " << endl;
        cout << " PLayer: " ;
    }

    cout << endl;
    int sizeHardTop3 = 0;
    for (int i = 0; i < size; i++) {
        if(top3H[i].top3Player != "" ){
            sizeHardTop3++;
        }

    }
    if(top3H[0].top3Score > 0 && top3H[0].top3Score <= 20) {
        cout << "Top 3 - Score: " << top3H[0].top3Score << endl;
        cout << " PLayer: " ;
        for(int i = 0; i < sizeHardTop3; i++) {
            cout <<" "<< top3H[i].top3Player;

        }
    }
    else {
        cout << "Top 3 - Score: " << endl;
        cout << " PLayer: " ;
    }

    cout << endl;

}

int main() {
    srand(time(0)); // Initialize random seed
    cout << "***** Wordle Game *****";
    cout << endl;
    User userNameInput;
    User userNameStore[1000];

    string arrUser[1000];
    int arraySize = 0;

    int storingScore;

    int level;

    //writing_into_file(userNameInput);

    string text = reading_file(R"(C:\Users\NGUYEN THIEN TU\Desktop\WordleGame\user.txt)");

    split(arrUser,text, arraySize);

    int arrUserSize = size_of_array(arrUser);

    int userSize = arrUserSize/4;

    change_score_string_to_integer(userSize, arrUser, userNameStore);

    storing_name_into_userNameStore_Struct( userNameStore, userSize, arrUser );

    reverse_userNameStore(userNameStore, userSize);

    inputing_username(userNameInput);

    duplicate_username_modifying(userNameStore, userNameInput, userSize);

    int sizeFinalUserNameStore = size_of_userNameStore_Struct(userNameStore);

    string choice;
    int isRun = 1;

    cout << "A. Playing game" << endl;
    cout << "B. Scores record" << endl;
    cout << "C. Exit" << endl;

    do {
        cout << "Inputting your choice: ";
        getline(cin, choice);
        if (choice != "A" && choice != "B" && choice != "C") {
            cout << "Please input your choice again " << endl;
        }
    } while (choice != "A" && choice != "B" && choice != "C"); // Loop until spaces are found

    while (isRun) {

        if (choice == "A"|| choice == "a") {
            inputing_level( level);
            generate_level_and_playing_game(level, storingScore, userNameInput );
            inputing_scores( userNameStore, userNameInput, userSize, level);
            writing_into_file(userNameStore,sizeFinalUserNameStore);


        }

        if (choice == "B" || choice == "b") {
            User *userSortedEasyLevel = sorting_easyScores_of_userNameStore_Struct_max_to_min(userNameStore, sizeFinalUserNameStore);
            User *userSortedMediumLevel = sorting_mediumScores_of_userNameStore_Struct_max_to_min(userNameStore, sizeFinalUserNameStore);
            User *userSortedHardLevel = sorting_hardScores_of_userNameStore_Struct_max_to_min(userNameStore,sizeFinalUserNameStore);

            top3Ranked  *top3Easy = top3_easy_level(userSortedEasyLevel, sizeFinalUserNameStore);
            top3Ranked *top3Medium = top3_medium_level(userSortedMediumLevel, sizeFinalUserNameStore);
            top3Ranked *top3Hard = top3_hard_level(userSortedHardLevel,sizeFinalUserNameStore);
            print_easy_level(top3Easy,sizeFinalUserNameStore);
            print_medium_level(top3Medium, sizeFinalUserNameStore);
            print_hard_level(top3Hard, sizeFinalUserNameStore);


        }


        if (choice == "C" || choice == "c") {
            isRun = 0;
        }

        cout << endl;
        cout << "Would you like to continue the game? " << endl;
        cout << "1. Yes, keep playing" << endl;
        cout << "0. Exit"<< endl;
        cout << "Your choice: ";
        cin >> isRun ;
        system("CLS");

    }



    return 0;
}


