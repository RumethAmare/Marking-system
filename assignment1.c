#include <stdio.h>
#include <string.h>

int main() {
    char names[100][20];  // array to store names
    int marks[100][3];    // array to store marks
    int count = 0;        
    int highestM = -1, secondHighestM = -1; // highest and second highest average declaration
    char highest[20], secondHighest[20]; // names of highest and second highest students
    char gradeHighest[20], gradeSecond[20];

    while (1) { // for infinite inputs till end
    	
        printf("Enter name (or 'End of Data' to finish): ");
        fgets(names[count], sizeof(names[count]), stdin);
        
        names[count][strcspn(names[count], "\n")] = 0;

        if (strcmp(names[count], "End of Data") == 0) {
        	printf("\n");
            break;
        }

        printf("Enter marks for Economics: ");
        scanf("%d", &marks[count][0]);
        
        printf("Enter marks for English: ");
        scanf("%d", &marks[count][1]);
        
        printf("Enter marks for Mathematics: ");
        scanf("%d", &marks[count][2]);
        
        printf("\n");
        
        // Clear the input buffer
        while (getchar() != '\n');

        count++;
    }
    
    int i;
    
    // Find the highest and second highest marks
    for (i = 0; i < count; i++) {
        int average = (marks[i][0] + marks[i][1] + marks[i][2]) / 3;
        	
        	// condition according to the notes
    if( (marks[i][0] >= 50 && marks[i][1] >= 50 && marks[i][2] >= 50) || ((marks[i][0] < 50 || marks[i][1] < 50 || marks[i][2] < 50 ) && (average >= 80)) ) {
        if (average > highestM) {
        	
            secondHighestM = highestM;
            strcpy(secondHighest, highest);
            highestM = average;
            strcpy(highest, names[i]);
            
        } else if (average > secondHighestM && average < highestM) {
        	
            secondHighestM = average;
            strcpy(secondHighest, names[i]);
        }
    }
    }
    
    if (highestM >= 80 ){
    	strcpy(gradeHighest, "Honours" );
    	
	}else if (highestM >= 65 ){
		strcpy(gradeHighest, "Distinction" );
		
	}else if (highestM >= 50 ){
		strcpy(gradeHighest, "Credit" );
		 
	}else{
		strcpy(gradeHighest, "Fail" );
		 
	}
	
	
	if (secondHighestM >= 80 ){
    	strcpy(gradeSecond, "Honours" );
		 
	}else if (secondHighestM >= 65 ){
		strcpy(gradeSecond, "Distinction" );
		 
	}else if (secondHighestM >= 50 ){
		strcpy(gradeSecond, "Credit" );
		 
	}else{
		strcpy(gradeSecond, "Fail" );
		 
	}
    
    

    // Output the results
    if (highestM != -1) {
        printf("Highest average :\n%s with an average of %d : %s\n\n", highest, highestM,gradeHighest);
    }
    if (secondHighestM != -1) {
        printf("Second highest average :\n%s with an average of %d : %s\n\n", secondHighest, secondHighestM,gradeSecond);
    }

    return 0;
}
