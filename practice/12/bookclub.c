#include <stdio.h>
#include <string.h>
#define MAX_MEMBER 20
#define MAX_RECORD 100
#define MAX_RESULT 1000
#define MAX_LENGTH 50

typedef struct {
	char name[MAX_LENGTH+1];
	char title[MAX_LENGTH+1];
} result_t;

typedef struct {
	int memID;
	char name[MAX_LENGTH+1];
} member_t;

typedef struct {
	int id;
	char title[MAX_LENGTH+1];
} record_t;

void sortResults(result_t results[], int);
void printResults(result_t results[], int);
int readInputs(member_t members[], record_t records[], result_t results[]);
int innerJoin(int, member_t members[], int, record_t records[], result_t results[]);
int leftJoin(int, member_t members[], int, record_t records[], result_t results[]);

int main(void) {
	int numRes;
	result_t results[MAX_RESULT];
	member_t members[MAX_MEMBER];
	record_t records[MAX_RECORD];

	numRes = readInputs(members, records, results);

	sortResults(results, numRes);

	printf("The results of the join are as follows: \n");
	printResults(results, numRes);

	return 0;
}

int readInputs(member_t members[], record_t records[], result_t results[]){
	int num_members, num_records, operation;

	printf("Enter operation of members: ");
	scanf("%d", &num_members);

	printf("Enter members: \n");
	for (int i = 0; i < num_members; i++) {
		scanf("%d %s", &members[i].memID, members[i].name);
	}

	printf("Enter operation of records: ");
	scanf("%d", &num_records);

	printf("Enter records: \n");
	for (int i = 0; i < num_records; i++) {
		scanf("%d %s", &records[i].id, records[i].title);	
	}

	printf("Enter operation: ");
	scanf("%d", &operation);
	if (operation == 1) {
		return innerJoin(num_members, members, num_records, records, results);
	}
	return leftJoin(num_members, members, num_records, records, results);
}

int innerJoin(int num_members, member_t members[], int num_records, record_t records[], result_t results[]) {
	int count = 0;
	
	/**
	for (int i = 0; i < num_members; i++) {
		printf("%d, %s\n", members[i].memID, members[i].name);
	}

	for (int i = 0; i < num_records; i++) {
		printf("%d, %s\n", records[i].id, records[i].title);
	}
	**/
	
	for (int i = 0; i < num_members; i++) {
		for (int j = 0; j < num_records; j++) {
			if (members[i].memID == records[j].id) {
				strcpy(results[count].name, members[i].name);
				strcpy(results[count].title, records[j].title);
				count++;
				printf("%s, %s, %d\n", members[i].name, records[j].title, count);
			}
		}
	}

	return count;
}


int leftJoin(int num_members, member_t members[], int num_records, record_t records[], result_t results[]) {
	int count = 0;

	for (int i = 0; i < num_members; i++) {
		int initial = count;
		for (int j = 0; j < num_records; j++) {
			if (members[i].memID == records[j].id) {
				strcpy(results[count].name, members[i].name);
				strcpy(results[count].title, records[j].title);
				count++;
			}
		}

		if (initial == count) {	
			strcpy(results[count].name, members[i].name);
			strcpy(results[count].title, "***");
			count++;
		}
	}

	return count;
}

// Sort the results first by name and then by book title
// in alphabetical order
void sortResults(result_t results[], int size){
	int i, start, index;
	result_t temp;

	for (start = 0; start < size-1; start++) {
		index = start;
		for (i = start+1; i < size; i++)
			if (strcmp(results[i].name, results[index].name) < 0 || 
					(strcmp(results[i].name, results[index].name) == 0 
					 && strcmp(results[i].title, results[index].title) < 0))
				index = i;

		temp = results[start];
		results[start] = results[index];
		results[index] = temp;
	}
}

void printResults(result_t results[], int size){
	int i;

	for (i = 0; i < size; i++){
		printf("%s %s\n", results[i].name, results[i].title);
	}
}
