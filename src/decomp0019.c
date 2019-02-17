#include "comp0019.h"
#include <stdlib.h>

unsigned char concatenatedD[5000];

struct codeTableValuesD {
    unsigned char concatenationOfBaseValue[5000];
    unsigned int codeValue;
    struct codeTableValuesD *next;
};
typedef struct codeTableValuesD codeTableD;
codeTableD *listHeadD = NULL;
codeTableD *listTailD = NULL;


int findLengthD(unsigned char *array) {
	unsigned int counter = 0;

	while( *(array + counter) != '\0') {
		counter++;
	} 
	return counter;
}

void addNodeD(unsigned char *stringBaseValue, unsigned int code ) {
    codeTableD *newNode =(codeTableD *) malloc(sizeof(codeTableD));

    int myLength = findLengthD(stringBaseValue);
    // printf("adding... %s ... length is %d\n", stringBaseValue, myLength);

    for(int i = 0; i < myLength; i++) {
    	newNode->concatenationOfBaseValue[i] = *(stringBaseValue + i);
    }
    newNode->concatenationOfBaseValue[myLength] = '\0';
    newNode->codeValue = code;

    newNode->next=NULL;

    if(listHeadD==NULL) {
        listHeadD=newNode;
        listTailD=newNode;
    }
    else {
        listTailD->next = newNode;
        listTailD = newNode;
    }

}

char checkExistsD() {
    codeTableD *codeTableNode = listHeadD;
    int baseLength = findLengthD(concatenatedD);
    int counter = 0;
    // printf("base is.. %d \n", baseLength);
    unsigned char baseEle;
    unsigned char codeEle;
    unsigned char breakFlag = 0;
    while(codeTableNode != NULL) {
		counter = 0;
		int codeTableBaseLength = findLengthD(codeTableNode->concatenationOfBaseValue);
		if (baseLength == codeTableBaseLength) {
		// printf("im here in checkexists codeTableLen %d\n", codeTableBaseLength);
			  while ( counter < baseLength) {
			  	baseEle = *(concatenatedD + counter);
			  	codeEle = codeTableNode->concatenationOfBaseValue[counter];
			  	// printf("base is.. %s and codeTableD is.. %s", base, codeTableNode->concatenationOfBaseValue);
			  	// printf("im second loop\n");
			  	// printf("current element is... %c\n", baseEle);
			  	// printf("compared to.... %c\n", codeEle);

    			if (baseEle != codeEle) {

    				breakFlag = 1;
    				break;

    			}
    			counter++;
    			
    		}
    		if (breakFlag == 1) {
    			codeTableNode = codeTableNode->next;
    			breakFlag = 0;
    		}
    		else {
      		return 1;
    		}
		}
		else {
        	codeTableNode = codeTableNode->next;

		}
    }
  	return 0;
}

void printCodeTableD() {
	codeTableD *codeTableNode = listHeadD;
	if (codeTableNode == NULL) {

   	printf("null head.. return!\n");
		return ;

	}
	while(codeTableNode != NULL) {
		printf("Code number: %d Value: %s\n", codeTableNode->codeValue, codeTableNode->concatenationOfBaseValue);
		codeTableNode = codeTableNode->next;
	}
	return ;
}

void freeListD(codeTableD* head) {
   codeTableD* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
       // if(tmp != NULL) free(tmp);
    }
}

void cPandCZD (unsigned char *preFix, unsigned char *charBaseValue) {
	unsigned int pBaseLength = findLengthD(preFix);
	unsigned int totalLength = pBaseLength + 2;

	// unsigned char *concatenatedD = (unsigned char *) malloc(totalLength + 1);

	// printf("charbaseString is ..  %s\n", charBaseValue);
	// printf("preFixString is..  %s and length is.... %d\n", preFix, pBaseLength);
	// printf("totalLength is %d\n", totalLength);
	if(pBaseLength == 0) {
		
		for (unsigned z = 0; z < totalLength; z++) {
			*(concatenatedD + z) = *(charBaseValue + z);
		}
		*(concatenatedD + totalLength) = '\0';
	}
	else {

		for (unsigned int i = 0; i < pBaseLength; i++) {
			*(concatenatedD + i) = *(preFix + i);
		}

		int only2 = 0;

		for (unsigned int j = pBaseLength; j < totalLength; j++ ){
			*(concatenatedD + j) = *(charBaseValue + only2);
			only2++;

		}

		*(concatenatedD + totalLength) = '\0';

	}

}


unsigned char gotString[5000];
unsigned char previousString[5000];
void getCodeStringD(unsigned int code) {
	
    codeTableD *codeTableNode = listHeadD;

    int counter = 0;

    while(codeTableNode != NULL) {
		counter = 0;
		// int codeTableBaseLength = findLengthD(codeTableNode->concatenationOfBaseValue);
		if (code == codeTableNode->codeValue) {
			  while ( codeTableNode->concatenationOfBaseValue[counter] != '\0') {
			  	gotString[counter] = codeTableNode->concatenationOfBaseValue[counter];
    			counter++;
    		} 

    		gotString[counter] = '\0';

    		return;
		}
        codeTableNode = codeTableNode->next;
    }
  	return;
}



unsigned int nextBitshift[4] = {6,4,2,0};
unsigned char temp[2];
unsigned int read2 = 0;
unsigned int stringCounter = 0;
unsigned char currentBaseWrite = 0;
unsigned int nextBitshiftCounter = 0;

void write2Bits(FILE* out_file) {

	while (gotString[stringCounter] != '\0') {
		temp[read2] = gotString[stringCounter];
		stringCounter++;

		if (read2 == 1) {
			read2 = 0;

			if (temp[0] == '0' && temp[1] == '0') {
				if(nextBitshiftCounter == 0) {
					currentBaseWrite = (currentBaseWrite | 0x0) << nextBitshift[nextBitshiftCounter];
				}
				if(nextBitshiftCounter == 1) {
					currentBaseWrite = (currentBaseWrite | 0x0) << nextBitshift[nextBitshiftCounter];
				}
				if(nextBitshiftCounter == 2) {
					currentBaseWrite = (currentBaseWrite | 0x0) << nextBitshift[nextBitshiftCounter];
				}
				if(nextBitshiftCounter == 3) {
					currentBaseWrite = (currentBaseWrite | 0x0) << nextBitshift[nextBitshiftCounter];
				}
			}
			else if (temp[0] == '0' && temp[1] == '1') {
				if(nextBitshiftCounter == 0) {
					currentBaseWrite = (currentBaseWrite | 0x1) << nextBitshift[nextBitshiftCounter];
				}
				if(nextBitshiftCounter == 1) {
					currentBaseWrite = (currentBaseWrite | 0x1) << nextBitshift[nextBitshiftCounter];
				}
				if(nextBitshiftCounter == 2) {
					currentBaseWrite = (currentBaseWrite | 0x1) << nextBitshift[nextBitshiftCounter];
				}
				if(nextBitshiftCounter == 3) {
					currentBaseWrite = (currentBaseWrite | 0x1) << nextBitshift[nextBitshiftCounter];
				}

			}
			else if (temp[0] == '1' && temp[1] == '0') {
				if(nextBitshiftCounter == 0) {
					currentBaseWrite = (currentBaseWrite | 0x2) << nextBitshift[nextBitshiftCounter];
				}
				if(nextBitshiftCounter == 1) {
					currentBaseWrite = (currentBaseWrite | 0x2) << nextBitshift[nextBitshiftCounter];
				}
				if(nextBitshiftCounter == 2) {
					currentBaseWrite = (currentBaseWrite | 0x2) << nextBitshift[nextBitshiftCounter];
				}
				if(nextBitshiftCounter == 3) {
					currentBaseWrite = (currentBaseWrite | 0x2) << nextBitshift[nextBitshiftCounter];
				}
			
			}
			else if (temp[0] == '1' && temp[1] == '1') {
				if(nextBitshiftCounter == 0) {
					currentBaseWrite = (currentBaseWrite | 0x3) << nextBitshift[nextBitshiftCounter];
				}
				if(nextBitshiftCounter == 1) {
					currentBaseWrite = (currentBaseWrite | 0x3) << nextBitshift[nextBitshiftCounter];
				}
				if(nextBitshiftCounter == 2) {
					currentBaseWrite = (currentBaseWrite | 0x3) << nextBitshift[nextBitshiftCounter];
				}
				if(nextBitshiftCounter == 3) {
					currentBaseWrite = (currentBaseWrite | 0x3) << nextBitshift[nextBitshiftCounter];
				}	
		
			}

			nextBitshiftCounter++;
			if (nextBitshiftCounter == 4) {
				fputc(currentBaseWrite, out_file);
				nextBitshiftCounter = 0;
				currentBaseWrite = 0;

			} 
			

		}
		read2++;
	}
	stringCounter = 0;
	fputc(currentBaseWrite, out_file);
}

void storePreviousString() {
	unsigned int intialCounter = 0;

	while(gotString[intialCounter] != '\0') {
	*(previousString + intialCounter) = *(gotString + intialCounter);
	intialCounter++;
	}

	*(previousString + intialCounter) = '\0';
}

void Decode(FILE* in_file, FILE* out_file) {
	currentBaseWrite = 0;
	nextBitshiftCounter = 0;
	codeTableD *NewlistHead = NULL;
	codeTableD *NewlistTail = NULL;
	listHeadD = NewlistHead;
	listTailD = NewlistTail;
	printf("hello\n");
	unsigned char base0[] = "00";
	unsigned char base1[] = "01";
	unsigned char base2[] = "10";
	unsigned char base3[] = "11";

	// freeList(listHeadD);
	// listHeadD = NULL;
	// listTailD = NULL;

	addNodeD(base0, 0);
	addNodeD(base1, 1);
	addNodeD(base2, 2);
	addNodeD(base3, 3);

	printCodeTableD();

	unsigned int numberOfBases = 0;

	numberOfBases |= fgetc(in_file);
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

	fputc(buffer[0], out_file);
	fputc(buffer[1], out_file);
	fputc(buffer[2], out_file);
	fputc(buffer[3], out_file);


	printf("Number of bases %d\n", numberOfBases);

	unsigned basesCounter = 0;
	unsigned char outPut[5000];
	unsigned int codeTableCounter = 3;
	unsigned int intialCounter = 0;
	unsigned int currentCodeValue = 0;
	unsigned int currentBase8bits = fgetc(in_file);



	currentCodeValue = currentBase8bits >> 5;
	printf("currentCodeValue is %d\n", currentCodeValue);

	getCodeStringD(currentCodeValue);
	printf("gotString is %s\n",gotString);
	write2Bits(out_file);

	storePreviousString();



	while(basesCounter != numberOfBases) {
		

		basesCounter++;
	}
	freeListD(listHeadD);

	for (int i = 0; i < 5000; i++) {
		gotString[i] = '\0';
		concatenatedD[i] = '\0';
		previousString[i] = '\0';
	}
}
