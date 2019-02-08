#include "comp0019.h"
#include <stdlib.h>
// Prototypes
unsigned char *cPandC (unsigned char *previousbase, unsigned char *charBaseValue);
int getCode(unsigned char* base);

unsigned int numberOfBases = 0;

struct codeTableValues {
    unsigned char concatenationOfBaseValue[5000];
    unsigned int codeValue;
    struct codeTableValues *next;
};
typedef struct codeTableValues codeTable;
codeTable *listHead = NULL;
codeTable *listTail = NULL;

int findLength(unsigned char *array) {
	unsigned int counter = 0;

	while( *(array + counter) != '\0') {
		counter++;
	} 
	return counter;
}

void addNode(unsigned char *stringBaseValue, unsigned int code ) {
    codeTable *newNode =(codeTable *) malloc(sizeof(codeTable));

    int myLength = findLength(stringBaseValue);
    printf("adding... %s ... length is %d\n", stringBaseValue, myLength);

    for(int i = 0; i < myLength; i++) {
    	newNode->concatenationOfBaseValue[i] = *(stringBaseValue + i);
    }
    newNode->codeValue = code;

    newNode->next=NULL;

    if(listHead==NULL) {
        listHead=newNode;
        listTail=newNode;
    }
    else {
        listTail->next = newNode;
        listTail = newNode;
    }

}

char checkExists(unsigned char *base) {
    codeTable *codeTableNode = listHead;
    int baseLength = findLength(base);
    int counter = 0;
    // printf("base is.. %d \n", baseLength);
    unsigned char baseEle;
    unsigned char codeEle;

    while(codeTableNode != NULL) {
		counter = 0;
		int codeTableBaseLength = findLength(codeTableNode->concatenationOfBaseValue);
		if (baseLength == codeTableBaseLength) {
		// printf("im here in checkexists codeTableLen %d\n", codeTableBaseLength);
			  while ( (*base + counter) != '\0' && counter < baseLength) {
			  	baseEle = *(base + counter);
			  	codeEle = codeTableNode->concatenationOfBaseValue[counter];
			  	// printf("base is.. %s and codeTable is.. %s", base, codeTableNode->concatenationOfBaseValue);
			  	// printf("im second loop\n");
			  	// printf("current element is... %c\n", baseEle);
			  	// printf("compared to.... %c\n", codeEle);

    			if (baseEle != codeEle) goto nextNode;
    			counter++;
    			
    		}

    		return 1;
		}
          nextNode:
      
        	codeTableNode = codeTableNode->next;
    }
  	return 0;
}

void printCodeTable() {
	codeTable *codeTableNode = listHead;
	if (codeTableNode == NULL) return ;
	while(codeTableNode != NULL) {
		// printf("Code number: %d Value: %s\n", codeTableNode->codeValue, codeTableNode->concatenationOfBaseValue);
		codeTableNode = codeTableNode->next;
	}
	return ;
}

void freeList(codeTable* head) {
   codeTable* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}


void Encode(FILE* in_file, FILE* out_file) {
	// Code 
	// Initilise first few nodes

	unsigned char base0[] = "00";
	unsigned char base1[] = "01";
	unsigned char base2[] = "10";
	unsigned char base3[] = "11";
	addNode(base0, 0);
	addNode(base1, 1);
	addNode(base2, 2);
	addNode(base3, 3);
	// printCodeTable();

	// unsigned char checking[] = "0000";
	// int results = checkExists(checking);
	// printf("exists.... %d\n", results);

	numberOfBases |= (fgetc(in_file));
	numberOfBases |= (fgetc(in_file) << 8);
	numberOfBases |= (fgetc(in_file) << 16);
	numberOfBases |= (fgetc(in_file) << 24);

	unsigned char lsbyte = numberOfBases & 0xFF;
	unsigned char nextLsByte = ((numberOfBases >> 8) & 0xFF);
	unsigned char thirdLsByte = ((numberOfBases >> 16) & 0xFF);
	unsigned char msbyte = ((numberOfBases >> 24) && 0xFF);

	unsigned char buffer[4];
	buffer[0] = lsbyte;
	buffer[1] = nextLsByte;
	buffer[2] = thirdLsByte;
	buffer[3] = msbyte;
	
	fwrite(&buffer[0], 1, 4, out_file);


	unsigned int shiftingAmount[4] = {6, 4 ,2, 0};
	unsigned int makingAmount = 3;

	printf("number of bases is = %d\n", numberOfBases);
	
	unsigned int allCodes[5000];
	unsigned int numberOfCodes = 0;
	unsigned int counter = 0;
	unsigned int codeCounter = 4;
	unsigned char myByteValue = 0;
	unsigned char myBaseValue = 0;

	unsigned char *previousBase = (unsigned char *) malloc(sizeof(char) * 1);
	*previousBase = '\0';
	unsigned char charBaseValue[2];
	unsigned char *concatenatedBase;

	while (1) {
		if (counter == numberOfBases+1) break;
		myByteValue = fgetc(in_file);
		if (myByteValue == EOF) return;
		for(int i = 0; i < 4; i++) {
			myBaseValue = (myByteValue >> shiftingAmount[i]) & 3;
			printf("myBaseValue: %d\n", myBaseValue);
			counter ++;
			// fputc(myBaseValue, out_file);	
			
			switch(myBaseValue) {
				case(0):
					charBaseValue[0] = '0';
					charBaseValue[1] = '0';
					break;
				case(1):
					charBaseValue[0] = '0';
					charBaseValue[1] = '1';		
					break;
				case(2):
					charBaseValue[0] = '1';
					charBaseValue[1] = '0';
					break;

				case(3):
					charBaseValue[0] = '1';
					charBaseValue[1] = '1';
					break;
				default:
				printf("Error!\n");
				} 
			concatenatedBase = cPandC(previousBase, charBaseValue); 
			printf("concatenatedBase is: %s\n", concatenatedBase);
			
			if (checkExists(concatenatedBase) == 1) {
				printf("Im here bcus it EXISTS\n");
				int concatLength = findLength(concatenatedBase);
				printf("ConcatLen = %d\n", concatLength);
				previousBase = (unsigned char *) realloc(previousBase, concatLength);

				for (int i = 0; i < concatLength; i++) {
					*(previousBase + i) = *(concatenatedBase + i);
				}
				printf("previoisbase is P + C now.. %s\n",previousBase);
			}
			else {

				int result = getCode(previousBase);
				printf("Final codes are...................... %d\n", result);
				allCodes[numberOfCodes] = result;
				numberOfCodes++;
				// printf("Output String: %s\n", previousBase);
				addNode(concatenatedBase, codeCounter);

				codeCounter ++;
				
				// free(previousBase);
				// unsigned char* previousBase = (unsigned char*) malloc(2);

				previousBase = (unsigned char *) realloc(previousBase, 2);
				*previousBase = *charBaseValue;
				*(previousBase + 1) = *(charBaseValue + 1);
				*(previousBase + 2) = '\0';
				printf("previousBase from else is P = INPUT CHAR now %s\n", previousBase);
			}

			if (counter == numberOfBases+1) break;

		}


	}

		
		unsigned char packed = 0;
		unsigned int shifting[2] = {5,3};
		unsigned int shiftingCounter = 0;
		unsigned char storeLastBit;
		for (int i = 0; i < numberOfCodes; i++) {

			if (shiftingCounter == 0) {
				packed = packed | ((allCodes[i] << 5));
				shiftingCounter++;
				if(numberOfCodes == 1) fputc(packed, out_file);
			}
			else if (shiftingCounter == 1){ 
				packed = packed | ((allCodes[i]) << 2);
				shiftingCounter++;
				if(numberOfCodes == 2) fputc(packed, out_file);
			}
			else if (shiftingCounter == 2) {
				storeLastBit = allCodes[i] & 0x1;
				// printf("stored last bit should be %d\n", storeLastBit);

				packed = packed | ((allCodes[i]) >> 1);
				// printf("packed first is %d\n", packed);
				fputc(packed, out_file);
				packed = 0;
				packed = packed | ( storeLastBit << 7);
				// printf("packed shold only contain 1 is %d\n", packed);
				shiftingCounter++;
			}
			else if (shiftingCounter == 3) {

				packed = packed | (allCodes[i] << 4);
				// printf("packed on shfiting 3 is.. %d\n", packed);

				fputc(packed, out_file);
			}

			// printf("codes are..%d................... %d\n", i, allCodes[i]);

		}


		printCodeTable();
		freeList(listHead);
		free(previousBase);
		free(concatenatedBase);

		for (int i = 0; i < numberOfCodes; i++) {
			allCodes[i] = '\0';
		}


	return;
}


unsigned char* cPandC (unsigned char *previousbase, unsigned char *charBaseValue) {
	unsigned int pBaseLength = findLength(previousbase);
	unsigned int totalLength = pBaseLength + 2;

	unsigned char *concatenated = (unsigned char *) malloc(totalLength);

	printf("charbaseString is ..  %s\n", charBaseValue);
	printf("previousBaseString is..  %s and length is.... %d\n", previousbase, pBaseLength);
	printf("totalLength is %d\n", totalLength);
	if(pBaseLength == 0) {
		
		for (unsigned z = 0; z < totalLength; z++) {
			*(concatenated + z) = *(charBaseValue + z);
		}
	}
	else {
		for (unsigned int i = 0; i < pBaseLength; i++) {
		*(concatenated + i) = *(previousbase + i);


		}

	int only2 = 0;

		for (unsigned int j = pBaseLength; j < totalLength; j++ ){
			*(concatenated + j) = *(charBaseValue + only2);
			only2++;
		}

	}

	return concatenated;
}

int getCode(unsigned char* base) {
	
    codeTable *codeTableNode = listHead;
    int baseLength = findLength(base);
    int counter = 0;

    unsigned char baseEle;
    unsigned char codeEle;

    while(codeTableNode != NULL) {
		counter = 0;
		int codeTableBaseLength = findLength(codeTableNode->concatenationOfBaseValue);
		if (baseLength == codeTableBaseLength) {
			  while ( (*base + counter) != '\0' && counter < baseLength) {
			  	baseEle = *(base + counter);
			  	codeEle = codeTableNode->concatenationOfBaseValue[counter];

    			if (baseEle != codeEle) goto nextNode;
    			counter++;
    			
    		}

    		return codeTableNode->codeValue;
		}
          nextNode:
        	codeTableNode = codeTableNode->next;
    }
  	return 0;
}