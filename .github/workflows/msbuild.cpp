#include <stdio.h>
#include <string.h>
#define MAX_C 11

typedef struct Candidate {
    char name[50];
    int votes;
    char symbol;
} Candidate;

Candidate allCandidates[MAX_C];
int candidateCount = 0;
char symbols[10] = {'!', '@', '#', '$', '%', '^', '&', '*', '~', '+'};
int symbolTaken[11];

void fillCandidate(int);
void displayAllCandidates();
void getVotes(int);
void getResults();

int main() {
    for (int i = 0; i < 11; i++) {
        symbolTaken[i] = 0;
    }
    printf("Enter the number of candidates: ");
    scanf("%d", &candidateCount);
    if (candidateCount >= MAX_C) {
        printf("Number of candidates cannot be greater than 10.\n Terminating the program\n\n");
        return 0;
    }
    for (int i = 0; i < candidateCount; i++) {
        fillCandidate(i);
    }
    displayAllCandidates();
    getVotes(candidateCount);
    getResults();
    return 0;
}

void fillCandidate(int index) {
    printf("Enter the name of candidate %d: ", index + 1);
    scanf("%s", allCandidates[index].name);
    printf("Enter the symbol for candidate %d: ", index + 1);
    scanf(" %c", &allCandidates[index].symbol);
    while (1) {
        int flag = 0;
        for (int i = 0; i < index; i++) {
            if (allCandidates[i].symbol == allCandidates[index].symbol) {
                flag = 1;
                break;
            }
        }
        if (flag == 1 || allCandidates[index].symbol == ' ') {
            printf("Symbol already taken or invalid symbol. Please enter a new symbol: ");
            scanf(" %c", &allCandidates[index].symbol);
        } else {
            break;
        }
    }
    allCandidates[index].votes = 0;
}

void displayAllCandidates() {
    printf("\nList of candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s (%c)\n", i + 1, allCandidates[i].name, allCandidates[i].symbol);
    }
    printf("\n");
}

void getVotes(int candidateCount) {
    int voteCount = 0;
    printf("Enter the number of votes: ");
    scanf("%d", &voteCount);
    for (int i = 0; i < voteCount; i++) {
        printf("Enter the symbol of the candidate you want to vote for: ");
        char symbol;
        scanf(" %c", &symbol);
        int flag = 0;
        for (int j = 0; j < candidateCount; j++) {
            if (allCandidates[j].symbol == symbol) {
                allCandidates[j].votes++;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("Invalid symbol. Please try again.\n");
            i--;
        }
    }
}

void getResults() {
    int maxVotes = -1;
    int winnerIndex = -1;
    for (int i = 0; i < candidateCount; i++) {
        if (allCandidates[i].votes > maxVotes) {
            maxVotes = allCandidates[i].votes;
            winnerIndex = i;
        }
    }
    printf("\nResults:\n");
    printf("Winner: %s (%c) with %d votes\n", allCandidates[winnerIndex].name, allCandidates[winnerIndex].symbol, allCandidates[winnerIndex].votes);
    printf("Other candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        if (i != winnerIndex) {
            printf("%s (%c) with %d votes\n", allCandidates[i].name, allCandidates[i].symbol, allCandidates[i].votes);
        }
    }
}
