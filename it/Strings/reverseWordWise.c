#include<stdio.h>
#include<string.h>

///////////////////////////////////

void swap(char word[], int i, int j){
  char temp;
  temp = word[i];
  word[i] = word[j];
  word[j] = temp;
}

///////////////////////////////////

// Note - This function is from Qns 4

void flipWord(char word[], int frontIndex, int backIndex){
  while(frontIndex < backIndex){
    swap(word, frontIndex, backIndex);
    frontIndex += 1;
    backIndex -=1;
  }
}

///////////////////////////////////

void reverseWordWise(char string[], int stringLength){

  int word_starting_index = 0;
  int word_ending_index = 0;

  while(word_ending_index <= stringLength){

    if(string[word_ending_index] == ' ' || string[word_ending_index]== '\0'){

      flipWord(string, word_starting_index, word_ending_index-1); // current word is reversed

      word_starting_index = word_ending_index +1;  // that is next word starting index

    }
    word_ending_index += 1;
  }
}

///////////////////////////////////

int main(){
  char string[] = "How are you?";
  int stringLength = strlen(string);

  printf("Before reversal :- %s \n\n", string);

  reverseWordWise(string, stringLength);
  printf("After reverseWordWise() :- %s \n\n", string);

  flipWord(string, 0, stringLength-1);
  printf("After flipWord() :- %s \n\n", string);

  return 0;
}

///////////////////////////////////
