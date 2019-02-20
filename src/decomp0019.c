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

void cPandCZD (unsigned char *preFix, unsigned char  *charBaseValue) {
	unsigned int pBaseLength = findLengthD(preFix);
	unsigned int totalLength = pBaseLength + 2;

	// unsigned char *concatenatedD = (unsigned char *) malloc(totalLength + 1);

	// printf("charbaseString is ..  %s\n", charBaseValue);
	// printf("preFixString is..  %s and length is.... %d\n", preFix, pBaseLength);
	// printf("totalLength is %d\n", totalLength);

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



unsigned char gotString[5000];
unsigned char previousString[5000];

unsigned int getCodeStringD(unsigned int code) {
	
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

    		return 1;
		}
        codeTableNode = codeTableNode->next;
    }
  	return 0;
}



unsigned int nextBitshift[3] = {2,2,2};
unsigned char temp[2];
unsigned int read2 = 0;
unsigned int stringCounter = 0;
unsigned int currentBaseWrite = 0;
unsigned int nextBitshiftCounter = 0;
unsigned justGotStringFlag = 1;
unsigned int moreShifts = 0;
unsigned int returnFlag = 0;
// unsigned int checkBasesCounter = 0;
unsigned int checkBasesCounter = 0;
void write2Bits(FILE* out_file, unsigned int lastBase, unsigned int numberOfBases) {
	unsigned int insideFlag = 0;
	unsigned int writtenPerfectly = 0;

	if (justGotStringFlag == 1) {
		while (gotString[stringCounter] != '\0') {
			temp[read2] = gotString[stringCounter];
			stringCounter++;
			insideFlag = 0;
			writtenPerfectly = 0;

			if (read2 == 1) {
				read2 = 0;
				// checkBasesCounter += 1;
				checkBasesCounter += 1;
				printf("First If basescounter is... %d\n", checkBasesCounter);
				// printf("temp for gotString is... and checkBasesCounter is..%d and numberOfBases is..%d\n",temp, checkBasesCounter, numberOfBases);
				printf("First ifnumberOfBases is.. %d\n", numberOfBases);
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
						currentBaseWrite = (currentBaseWrite | 0x0);
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
						currentBaseWrite = (currentBaseWrite | 0x1);
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
						currentBaseWrite = (currentBaseWrite | 0x2);
					}
				
				}
				else if (temp[0] == '1' && temp[1] == '1') {
					if(nextBitshiftCounter == 0) {
						currentBaseWrite = (currentBaseWrite | 0x3) << nextBitshift[nextBitshiftCounter];
						printf("basewrie should be 12 %d\n",currentBaseWrite );
						printf("here 1\n");
					}
					if(nextBitshiftCounter == 1) {
						currentBaseWrite = (currentBaseWrite | 0x3) << nextBitshift[nextBitshiftCounter];
						printf("here 2\n");
					}
					if(nextBitshiftCounter == 2) {
						currentBaseWrite = (currentBaseWrite | 0x3) << nextBitshift[nextBitshiftCounter];
						printf("here 3\n");
					}
					if(nextBitshiftCounter == 3) {
						currentBaseWrite = (currentBaseWrite | 0x3);
					}	
			
				}

				nextBitshiftCounter++;
				if (nextBitshiftCounter == 4) {
					printf("hereeeeeeeeeeeeee\n");
					fputc(currentBaseWrite, out_file);
					nextBitshiftCounter = 0;
					currentBaseWrite = 0;
					writtenPerfectly = 1;

				} 
				insideFlag = 1;

			}
			if (insideFlag != 1) read2++;
		}
		stringCounter = 0;
		moreShifts = 3 - nextBitshiftCounter;
		printf("before comapre return numberOfBases is %d.. and checkBasesCounter is %d\n", numberOfBases, checkBasesCounter);
		if (checkBasesCounter == numberOfBases) {
			printf("in here????asdasdasdasd");
			for (int i =0; i < moreShifts; i++) {
				currentBaseWrite = currentBaseWrite << 2;
				}
			fputc(currentBaseWrite, out_file);
			returnFlag = 1;
			return;
		}

		// if(moreShifts != 0 && writtenPerfectly != 1) {

		// 	for (unsigned int i = 0; i < moreShifts; i++) {
		// 		currentBaseWrite = currentBaseWrite << 2;
		// 	}

		// 	fputc(currentBaseWrite, out_file);

		// }

	}
	else {
		while (concatenatedD[stringCounter] != '\0') {
			temp[read2] = concatenatedD[stringCounter];
			stringCounter++;
			insideFlag = 0;
			writtenPerfectly = 0;

			if (read2 == 1) {
				read2 = 0;
				// checkBasesCounter += 1;
				checkBasesCounter += 1;
				// checkBasesCounter = checkBasesCounter + 1;
				printf("temp is... %s\n",temp);
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
						currentBaseWrite = (currentBaseWrite | 0x0);
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
						currentBaseWrite = (currentBaseWrite | 0x1);
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
						currentBaseWrite = (currentBaseWrite | 0x2);
					}
				
				}
				else if (temp[0] == '1' && temp[1] == '1') {
					if(nextBitshiftCounter == 0) {
						currentBaseWrite = (currentBaseWrite | 0x3) << nextBitshift[nextBitshiftCounter];
						printf("basewrie should be 12 %d\n",currentBaseWrite );
						printf("here 1\n");
					}
					if(nextBitshiftCounter == 1) {
						currentBaseWrite = (currentBaseWrite | 0x3) << nextBitshift[nextBitshiftCounter];
						printf("here 2\n");
					}
					if(nextBitshiftCounter == 2) {
						currentBaseWrite = (currentBaseWrite | 0x3) << nextBitshift[nextBitshiftCounter];
						printf("here 3\n");
					}
					if(nextBitshiftCounter == 3) {
						currentBaseWrite = (currentBaseWrite | 0x3);
					}	
			
				}

				nextBitshiftCounter++;
				if (nextBitshiftCounter == 4) {
					printf("heree 2nd\n");
					fputc(currentBaseWrite, out_file);
					nextBitshiftCounter = 0;
					currentBaseWrite = 0;
					writtenPerfectly = 1;

				} 
				insideFlag = 1;

			}
			if (insideFlag != 1) read2++;
		}
		stringCounter = 0;
		moreShifts = 3 - nextBitshiftCounter;

		if (checkBasesCounter == numberOfBases) {
			for (int i =0; i < moreShifts; i++) {
				currentBaseWrite = currentBaseWrite << 2;
				}
			fputc(currentBaseWrite, out_file);
			returnFlag = 1;
			return;
		}


	}
}

void storePreviousString() {
	unsigned int intialCounter = 0;

	while(gotString[intialCounter] != '\0') {
	*(previousString + intialCounter) = *(gotString + intialCounter);
	intialCounter++;
	}

	*(previousString + intialCounter) = '\0';
}

unsigned long long int powerFuncD(int exponent) {

	if (exponent < 0) return 4;
	unsigned int base = 2;
	unsigned long long int result = 1;
	while (exponent != 0) {
		result = result * base;
		--exponent;
	}

	printf("returining result is %llu \n", result);
	return result;
}

void Decode(FILE* in_file, FILE* out_file) {
	currentBaseWrite = 0;
	nextBitshiftCounter = 0;
	codeTableD *NewlistHead = NULL;
	codeTableD *NewlistTail = NULL;
	listHeadD = NewlistHead;
	listTailD = NewlistTail;
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
	unsigned int numberOfBytes = 0;
	while(fgetc(in_file) != EOF) {
		numberOfBytes++;
	}
	rewind(in_file);
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
	//check if there are more bases then total bytes /2.
	if (numberOfBases >= numberOfBytes) {
		printf("Invalid decoder input: .*\n");
		fputs("invalid input: .*", out_file);
		return;
	}
	fputc(buffer[0], out_file);
	fputc(buffer[1], out_file);
	fputc(buffer[2], out_file);
	fputc(buffer[3], out_file);


	printf("Number of bases %d\n", numberOfBases);

	unsigned basesCounter = 0;
	unsigned int codeTableCounter = 4;
	unsigned int intialCounter = 0;

	unsigned int currentCodeValue = 0;
	unsigned int currentBase8bits;

    int check;
    int remainder = 8;
    int reading = 3;
    int shiftingAmount;


	unsigned int maskAmount = 0;
	unsigned int tempBase = 0;

	// previousString[0] = '1';
	// previousString[1] = '0';
	// previousString[2] = '1';
	// previousString[3] = '1';
	// previousString[4] = '1';
	// previousString[5] = '0';
	// previousString[6] = '1';
	// previousString[7] = '1';


	// gotString[0] = '1';
	// gotString[1] = '0';
	// gotString[2] = '1';
	// gotString[3] = '1';
	// gotString[4] = '1';
	// gotString[5] = '1';
	// cPandCZD(previousString, gotString);

	// justGotStringFlag = 0;
	// write2Bits(out_file, 0);

	unsigned int fGetFlag = 0;
	unsigned int newShiftingAmountRight = 0;
	unsigned int initilise = 1;
	unsigned int totalPossibleCodesReadable = (numberOfBases * 2) / 3;
	unsigned int totalCounter = 0;
	currentBase8bits = fgetc(in_file);
	unsigned int existsOrNot;

	printf("starting with checkBasesCounter is. %d\n", checkBasesCounter);
	while(1) {

		
		printf("currentbase*bits is..... %d \n", currentBase8bits);
		if (codeTableCounter > 8 && codeTableCounter <= 16) reading = 4;
		if (codeTableCounter > 16 && codeTableCounter <= 32) reading = 5;
		if (codeTableCounter > 32 && codeTableCounter <= 64) reading = 6;
		if (codeTableCounter > 64 && codeTableCounter <= 128) reading = 7;
		if (codeTableCounter > 128 && codeTableCounter <= 256) reading = 8;
		if (codeTableCounter > 256 && codeTableCounter <= 512) reading = 9;
		if (codeTableCounter > 512 && codeTableCounter <= 1024) reading = 10;
		if (codeTableCounter > 1024 && codeTableCounter <= 2048) reading = 11;
		if (codeTableCounter > 2048 && codeTableCounter <= 4096) reading = 12;

		shiftingAmount = remainder - reading; // 8 - 3

		if (shiftingAmount > 0) {
			// if (checkBasesCounter == numberOfBases) {
			// 		break;
			// 	}
			printf("shifting amount is.. %d\n", shiftingAmount );
			fGetFlag = 1;
			maskAmount = powerFuncD(reading) - 1;
			currentCodeValue = currentBase8bits >> shiftingAmount;
			currentCodeValue = currentCodeValue & maskAmount;
			remainder = remainder - reading; // 8 - 3 
			printf("remainder is.. %d\n", remainder);
		}
		else if (shiftingAmount < 0) {
			printf("am i here? in else if from shiftingAmount is %d\n", shiftingAmount);
			fGetFlag = 1;
			maskAmount = powerFuncD(remainder) - 1;
			tempBase = currentBase8bits & maskAmount;
			tempBase = tempBase << abs(shiftingAmount);
			if ((currentBase8bits = fgetc(in_file)) != EOF) {
			// currentBase8bits = fgetc(in_file);
			remainder = 8;
			remainder = 8 - abs(shiftingAmount); 
			currentCodeValue = currentBase8bits >> remainder;
			currentCodeValue = tempBase | currentCodeValue;				
			}
			else {
				printf("currentBaseWrite is %d and moreShifts is.. %d\n", currentBaseWrite, moreShifts);
				printf("should be < 0 in break\n");
				printf("checkBasesCounter is: %d ..... numberOfBases is.... %d\n", checkBasesCounter, numberOfBases);
				if (checkBasesCounter == numberOfBases) {
					break;
				}
				else {
					for (int i =0; i < moreShifts; i++) {
					currentBaseWrite = currentBaseWrite << 2;
					}
					fputc(currentBaseWrite, out_file);
					break;
				}
			}

		}

		printf("code values are...%d\n", currentCodeValue);
		/// int currentCodeValue = we get the code somehoh

		check = getCodeStringD(currentCodeValue);

		if (check == 1) {
			justGotStringFlag = 1;
			printf("should behere first.. numberOfBases is %d\n", numberOfBases);
			write2Bits(out_file, 0, numberOfBases);
			if (returnFlag == 1) break;
			if (initilise != 1) {
				printf("in initliase bAD!!!!!\n");
				cPandCZD(previousString, gotString);
				existsOrNot = checkExistsD();
				if (existsOrNot == 0) addNodeD(concatenatedD, codeTableCounter);
				codeTableCounter++;	
			}
			initilise = 0;
		}
		else if (check == 0) {
			printf("not from end of base?\n");
			justGotStringFlag = 0;
			cPandCZD(previousString, previousString);
			existsOrNot = checkExistsD();
			if (existsOrNot == 0)addNodeD(concatenatedD, codeTableCounter);
			codeTableCounter++;	
			write2Bits(out_file, 0, numberOfBases);
			if (returnFlag == 1) break;
		}
		
		storePreviousString();
		basesCounter++;
	}

printCodeTableD();



	freeListD(listHeadD);
	for (int i = 0; i < 5000; i++) {
		gotString[i] = '\0';
		concatenatedD[i] = '\0';
		previousString[i] = '\0';
	}
	temp[0] = '\0';
	temp[1] = '\0';
	read2 = 0;
	stringCounter = 0;
	nextBitshiftCounter = 0;
	currentBaseWrite = 0;
	justGotStringFlag = 1;
	moreShifts = 0;
	checkBasesCounter = 0;
	returnFlag = 0;

}
