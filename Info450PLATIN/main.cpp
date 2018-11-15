// This program will allow user to input the word in english and translate the word to PigLatin


#include <iostream>
#include <cstring>
using namespace std;
const int MAX_LETTER_INPUT = 50;   //  max lenght for the letter
// Methods declaration
void welcomeMessage();
void byeMessage();
bool ifVow ( char vol);
bool ifNumber (char input[MAX_LETTER_INPUT]);
bool ifTooShort (char input[MAX_LETTER_INPUT]);
char translate (char input[MAX_LETTER_INPUT], char pigLatin[MAX_LETTER_INPUT]);


int main()
{
    char answer;
    welcomeMessage();

    do {
        char userEnter [MAX_LETTER_INPUT] = " "; // input array
        char pigLatin[MAX_LETTER_INPUT] = " "; // translated array to pigLatin
        cout << "Please Enter Your Word: " << endl;
        cin.getline(userEnter, MAX_LETTER_INPUT);
        
        // Call the function in order to translate the input to pigLatin
        translate (userEnter, pigLatin);
        cout << endl;
        cout << "Do You Want to Enter Another Word? Y or y to continue: ";
        cout << endl;
        cin >> answer;
        if (answer != 'y' && answer!= 'Y')
        {
            byeMessage();
        }
        // have to clear the buffer before inputting another word
        cin.ignore(MAX_INPUT, '\n');
        cin.clear();
    }
    
    while (answer == 'Y' || answer == 'y');
    return 0;
}

// simply welcome function
void welcomeMessage()
{
  
    cout << "**" << " ********************* " << "**" << endl;
    cout << "**" << "     Welcome to the    " << "**" << endl;
    cout << "**" << "        pig latin      " << "**" << endl;
    cout << "**" << "      translator       " << "**" << endl;
    cout << "**" << " ********************* " << "**" << endl;
    cout << endl;
}

void byeMessage()
{
    cout << endl;
    cout << "**" << " ****************************** " << "**" << endl;
    cout << "**" << "    Thank You for Choosing Us   " << "**" << endl;
    cout << "**" << "     Our PigLatin Translator    " << "**" << endl;
    cout << "**" << "        Come BacK Soon         " << "**" << endl;
    cout << "**" << "      We are working on        " << "**" << endl;
    cout << "**" << " *******************************" << "**" << endl;
    cout << endl;
}


// this function will check whether the first letter is a vowel
bool ifVow ( char input[MAX_LETTER_INPUT])
{
    if (input[0]=='a'||
        input[0]=='i'||
        input[0]=='e'||
        input[0]=='o'||
        input[0]=='u'||
        input[0]=='A'||
        input[0]=='I'||
        input[0]=='E'||
        input[0]=='O'||
        input[0]=='U')
        
        return true;
    else
        return false;
    
}

// this function will check whether the input word is an integer number
bool ifNumber (char input[MAX_LETTER_INPUT])
{
    
    if (atoi(input) || input[0] == '\0')
        return true;
    else
        return false;
    
}

// this function will check whether the input word is longer than 2 letter
bool ifTooShort (char input[MAX_LETTER_INPUT])
{
    if (input[2] == '\0')
        
        return true;
    else
        return false;
}

// This function will check whether the input word is a conjunction
// the strlen == 3 is there so that if user were to input a word like "normal" or "order" then it will translate
// differently than NOR or OR
bool ifConjunction (char input[MAX_LETTER_INPUT])

{
    if ((strstr(input, "and") && strlen(input) == 3) ||
        (strstr(input, "but") && strlen(input) == 3) ||
        (strstr(input, "yet") && strlen(input) == 3) ||
        (strstr(input, "nor") && strlen(input) == 3) ||
        (strstr(input, "for") && strlen(input) == 3) ||
        (strstr(input, "or") && strlen(input) == 3) ||
        (strstr(input, "AND") && strlen(input) == 3) ||
        (strstr(input, "BUT") && strlen(input) == 3) ||
        (strstr(input, "YET") && strlen(input) == 3) ||
        (strstr(input, "NOR") && strlen(input) == 3) ||
        (strstr(input, "FOR") && strlen(input) == 3) ||
        (strstr(input, "OR") && strlen(input) == 3) ||
        (strstr(input, "And") && strlen(input) == 3) ||
        (strstr(input, "But") && strlen(input) == 3) ||
        (strstr(input, "Yet") && strlen(input) == 3) ||
        (strstr(input, "Nor") && strlen(input) == 3) ||
        (strstr(input, "For") && strlen(input) == 3) ||
        (strstr(input, "Or") && strlen(input) == 3))
        
        return true;
    else
        return false;
    
}

// This function will check all the conditions and translate the user input word according to the conditions
char translate (char input[MAX_LETTER_INPUT], char pigLatin[MAX_LETTER_INPUT])
{
    // check if the input is at least 3 characters long, if not it will not be translated
    if (ifTooShort(input))
    {
        strcpy(pigLatin, input);
        cout << "Sorry, I can't translate \"" << pigLatin << "\" because it is less than or equal to 2 letters long." << endl;
        return 0;
    }
    
    // check if the user input is number, if it is, then we are not translating the input
    else if (ifNumber(input))
    {
        strcpy(pigLatin, input);
        cout << "Sorry,  I can't translate \""<< pigLatin << "\" because I can't translate umber! " << endl;
        return -1;
    }
    
    // Check if the user input is a conjunction, if it is then we are not translating
    else if (ifConjunction(input))
    {
        strcpy(pigLatin, input);
        cout << "Sorry, I can't translate  \"" << pigLatin << "\" because it is an article or a conjunction." << endl;
        return 0;
    }
    
    
    // check if the first letter of the user input starts with a VOWEL, if it is then we will just add
    // a AY at the end of the word
    else if (ifVow(input))
    {
        strcat(pigLatin, input);
        strcat(pigLatin, "ay");
        cout << "Okay, I will translate \"" << input << "\" to pig latin." << endl << endl;
        cout << "Your word translated is: " << pigLatin << endl;
        return 0;
    }
    
    else
    {
        
        // assigning the loop controler to be one less than the array lenght
        int lastIndex = strlen(input) - 1;
        for (int i = 1; i <= lastIndex; i++)
        {
            pigLatin[i - 1] = input[i];  // first array of pigLatin will start at input [1]
        }
        pigLatin[lastIndex] = input[0]; // assinging the input[0] to pigLatin last index before the null
        strcat(pigLatin, "ay");
        cout << "Okay, I will translate \"" << input << "\" to pig latin." << endl;
        cout << "Your word translated is: " << pigLatin << endl;
        return 0;
    }
    return 0;
}



