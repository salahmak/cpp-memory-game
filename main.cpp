#include <iostream>
#include <string>
#include <vector>
#include "./utils/shuffle.cpp"
#include "./utils/render.cpp"
#include "./Card/Card.cpp"

using namespace std;

vector<Card> initializeSlots(vector<string> chars){
    vector<Card> returnSlot;
    for(int i = 0; i < chars.size(); i++){
        returnSlot.push_back(Card(to_string(i+1), chars[i]));
    };
    return returnSlot;
};

vector<string> chars = {"A", "B", "C", "D", "A", "B", "C", "D"};

void play(){
    vector<Card> slots = initializeSlots(shuffle(chars));
    int input1;
    int input2;
    int correctGuesses = 0;
    int attempts = 0;

    render(slots, attempts);

    Card pairs[] = {Card("0", "0"),Card("0", "0")};

    while(true){
        cout << "enter a number: ";
        cin >> input1;

        pairs[0] = slots[input1 - 1];
        slots[input1 - 1].Front = slots[input1 - 1].Back;

        render(slots, attempts);

        cout << "enter a number: ";
        cin >> input2;

        pairs[1] = slots[input2 - 1];
        slots[input2 - 1].Front = slots[input2 - 1].Back;

        attempts++;
        render(slots, attempts);

        if(pairs[0].Back == pairs[1].Back && input1 != input2){
            slots[input1 - 1].Front = pairs[0].Back;
            slots[input2 - 1].Front = pairs[1].Back;
            correctGuesses++;
            render(slots, attempts);
        }else {
            cout <<endl<< "wrong" << endl;
            // cout << "click any key to continue playing..."<<endl;
           
            string key;
            cin >> key;

            if(input1 == input2){
                slots[input1 - 1].Front = pairs[0].Front;
            }else{
            slots[input1 - 1].Front = pairs[0].Front;
            slots[input2 - 1].Front = pairs[1].Front;
            }
            render(slots, attempts);
        };

        if(correctGuesses == 4){
            cout << "Game is over, do you want to restart? (y or n) ";
            char answer;
            cin >> answer;
            switch(answer){
                case 'y':
                    play();
                    break;
                case 'n':
                    cout << endl << "Thanks for playing, see you later" <<endl;
                    terminate();
                default: 
                    cout << endl << "Will take that as a no, thanks" <<endl;
                    terminate();
            }
        };
        
    };

};

int main()
{
    play();
    return 0;
}