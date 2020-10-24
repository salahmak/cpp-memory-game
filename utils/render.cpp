using namespace std;



template<typename T>
void render(vector<T> slots, int attempts){
    system("clear");
    // system("cls"); //for windows env
    cout << "+---+---+---+---+" << endl;
    cout << "| " << slots[0].Front << " | " << slots[1].Front << " | " << slots[2].Front << " | " << slots[3].Front << " |" <<endl;
    cout << "|---+---+---+---|" << endl;
    cout << "| " << slots[4].Front << " | " << slots[5].Front << " | " << slots[6].Front << " | " << slots[7].Front << " |"  <<endl;
    cout << "+---+---+---+---+" << endl;
    cout << endl << "attempts: " << attempts<<endl;
};