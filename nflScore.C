#include <stdio.h>

int main(){
    int score;

    while (1) {
        // Ask the user for NFL score
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);

        // Stop the program if the score is less than 2
        if (score <= 1) {
            break;
        } 

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        // Loop through every possible combination of TD + 2pt conversion
        for (int td_2 = 0; td_2 <= score / 8; td_2++) {

            // Loop through every possible combination of TD + FG
            for (int td_1 = 0; td_1 <= score / 7; td_1++) {

                // Loop through every possible combination of TD
                for (int td = 0; td <= score / 6; td++) {

                    // Loop through every possible combination of FG
                    for (int fg = 0; fg <= score / 3; fg++) {

                        // Find the remaining score based on the number of each scoring play
                        int remaining = score - (8 * td_2 + 7 * td_1 + 6 * td + 3 * fg);

                        // Confirm the score is possible with the number of each scoring play
                        if (remaining >= 0 && remaining % 2 == 0) {

                            // Find the number of safeties needed
                            int safety = remaining / 2;

                            // Output the combination
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2, td_1, td, fg, safety);
                        }
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}