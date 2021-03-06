#include "comp0019.h"
#include <stdlib.h>
#include <stdio.h>

void writeToFile(unsigned int *codeArray, unsigned int numberOfCodes, FILE *out_file);
unsigned long long int powerFunc( int exponent);
unsigned char concatenated[5000];

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
    // printf("adding... %s ... length is %d\n", stringBaseValue, myLength);

    for(int i = 0; i < myLength; i++) {
    	newNode->concatenationOfBaseValue[i] = *(stringBaseValue + i);
    }
    newNode->concatenationOfBaseValue[myLength] = '\0';
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

char checkExists() {
    codeTable *codeTableNode = listHead;
    int baseLength = findLength(concatenated);
    int counter = 0;
    // printf("base is.. %d \n", baseLength);
    unsigned char baseEle;
    unsigned char codeEle;
    unsigned char breakFlag = 0;
    while(codeTableNode != NULL) {
		counter = 0;
		int codeTableBaseLength = findLength(codeTableNode->concatenationOfBaseValue);
		if (baseLength == codeTableBaseLength) {
		// printf("im here in checkexists codeTableLen %d\n", codeTableBaseLength);
			  while ( counter < baseLength) {
			  	baseEle = *(concatenated + counter);
			  	codeEle = codeTableNode->concatenationOfBaseValue[counter];
			  	// printf("base is.. %s and codeTable is.. %s", base, codeTableNode->concatenationOfBaseValue);
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

void printCodeTable() {
	codeTable *codeTableNode = listHead;
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

void freeList(codeTable* head) {
   codeTable* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
       // if(tmp != NULL) free(tmp);
    }
}

void cPandC (unsigned char *preFix, unsigned char *charBaseValue) {
	unsigned int pBaseLength = findLength(preFix);
	unsigned int totalLength = pBaseLength + 2;

	// unsigned char *concatenated = (unsigned char *) malloc(totalLength + 1);

	// printf("charbaseString is ..  %s\n", charBaseValue);
	// printf("preFixString is..  %s and length is.... %d\n", preFix, pBaseLength);
	// printf("totalLength is %d\n", totalLength);
	if(pBaseLength == 0) {
		
		for (unsigned z = 0; z < totalLength; z++) {
			*(concatenated + z) = *(charBaseValue + z);
		}
		*(concatenated + totalLength) = '\0';
	}
	else {

		for (unsigned int i = 0; i < pBaseLength; i++) {
			*(concatenated + i) = *(preFix + i);
		}

		int only2 = 0;

		for (unsigned int j = pBaseLength; j < totalLength; j++ ){
			*(concatenated + j) = *(charBaseValue + only2);
			only2++;

		}

		*(concatenated + totalLength) = '\0';

	}

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

void Encode(FILE* in_file, FILE* out_file) {
	// Code 

	printf("hello\n");
	// Initilise first few nodes
	freeList(listHead);
	codeTable *NewlistHead = NULL;
	codeTable *NewlistTail = NULL;
	listHead = NewlistHead;
	listTail = NewlistTail;

	unsigned char base0[] = "00";
	unsigned char base1[] = "01";
	unsigned char base2[] = "10";
	unsigned char base3[] = "11";

	// freeList(listHead);
	// listHead = NULL;
	// listTail = NULL;

	addNode(base0, 0);
	addNode(base1, 1);
	addNode(base2, 2);
	addNode(base3, 3);


	// unsigned char checking[] = "0000";
	// int results = checkExists(checking);
	// printf("exists.... %d\n", results);
	unsigned int numberOfBases = 0;
	unsigned int numberOfBytes = 0;
	numberOfBases |= fgetc(in_file);
	numberOfBases |= (fgetc(in_file) << 8);
	numberOfBases |= (fgetc(in_file) << 16);
	numberOfBases |= (fgetc(in_file) << 24);

	char writeError[] = "Invalid encoder input: .*";
	while(fgetc(in_file) != EOF) {
		numberOfBytes++;
	}
	printf("number of byts is... %d and number of bases is %d\n", numberOfBytes, numberOfBases);
	if (numberOfBytes == 0 && numberOfBases != 0) {
		fputs(writeError, out_file);
		return;
	}
	else {
		unsigned int totalBasesPossible = numberOfBytes * 4;
		unsigned int lowerBoundBases = totalBasesPossible - 3;

		if (numberOfBases <= totalBasesPossible && numberOfBases >= lowerBoundBases) {
			printf("good\n");
		}
		else {
			fputs(writeError, out_file);
			return;
		}

	}

	rewind(in_file);
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



	unsigned int shiftingAmount[4] = {6, 4 ,2, 0};
	unsigned int makingAmount = 3;

	// printf("number of bases is = %d\n", numberOfBases);
	
	unsigned int allCodes[5000];
	unsigned int numberOfCodes = 0;
	unsigned int counter = 0;
	unsigned int codeCounter = 4;
	char myByteValue = 0;
	unsigned int myBaseValue = 0;


	unsigned char preFix[5000];
	*preFix = '\0';
	unsigned char charBaseValue[2];
	unsigned char *concatenatedBase ;
	int concatLength = 0;
	int result = 0;
	while (1) {
		if (counter == numberOfBases) break;
		myByteValue = fgetc(in_file);
		printf("myByteValue\n");
		for(unsigned int i = 0; i < 4; i++) {
			myBaseValue = (myByteValue >> shiftingAmount[i]) & 3;
			// printf("myBaseValue: %d\n", myBaseValue);
			counter ++;
			// fputc(myBaseValue, out_file);	
			
			if(myBaseValue == 0) {
					charBaseValue[0] = '0';
					charBaseValue[1] = '0';
			}
			if(myBaseValue == 1) {
					charBaseValue[0] = '0';
					charBaseValue[1] = '1';
			}
			if(myBaseValue == 2) {
					charBaseValue[0] = '1';
					charBaseValue[1] = '0';
			}
			if(myBaseValue == 3) {
					charBaseValue[0] = '1';
					charBaseValue[1] = '1';
			}

			 cPandC(preFix, charBaseValue); 
			// printf("concatenatedBase is: %s\n", concatenatedBase);

			
			if (checkExists() == 1) {
				// printf("Im here bcus it EXISTS\n");
				concatLength = findLength(concatenated);
				// printf("ConcatLen = %d\n", concatLength);
				// free(preFix)
				// unsigned char* preFix = (unsigned char*) malloc(concatLength + 1);

				

				for (int i = 0; i < concatLength; i++) {
					*(preFix + i) = *(concatenated + i);
				}
				*(preFix + concatLength) = '\0';
	

				// printf("previoisbase is P + C now.. %s\n",preFix);
			}
			else {
				result = getCode(preFix);
				// printf("Current Final code are...................... %d\n", result);
				allCodes[numberOfCodes] = result;
				numberOfCodes++;
				printf("Output String: %s\n", preFix);
				addNode(concatenated, codeCounter);

				codeCounter++;
				
				// free(preFix);
				// unsigned char* preFix = (unsigned char*) malloc(3);

			
				*preFix = *charBaseValue;
				*(preFix + 1) = *(charBaseValue + 1);
				*(preFix + 2) = *(charBaseValue + 2);
				printf("preFix from else is P = INPUT CHAR now %s\n", preFix);
			}

			if (counter == numberOfBases) break;

		}

	}
		result = getCode(preFix);
		printf("final result code is.. %d\n", result );
		allCodes[numberOfCodes] = result;
		numberOfCodes++;
		codeCounter--;

		writeToFile(allCodes, numberOfCodes, out_file);


		unsigned char packed = 0;
		unsigned int shifting[2] = {5,3};
		unsigned int shiftingCounter = 0;
		unsigned char storeLastBit = 0;
		unsigned char secondLastBit = 0;
		unsigned char thirdBit = 0;
		// for (int i = 0; i < numberOfCodes; i++) {

		// 	if (shiftingCounter == 0) {
		// 		packed = packed | ((allCodes[i] << 5));
		// 		shiftingCounter++;
		// 		if(numberOfCodes == 1) fputc(packed, out_file);
		// 	}
		// 	else if (shiftingCounter == 1){ 
		// 		packed = packed | ((allCodes[i]) << 2);
		// 		shiftingCounter++;
		// 		if(numberOfCodes == 2) fputc(packed, out_file);
		// 	}
		// 	else if (shiftingCounter == 2) {
		// 		storeLastBit = allCodes[i] & 0x1;
			
		// 		// thirdBit = allCodes[i] & 0x4;
		// 		// printf("stored last bit should be %d\n", storeLastBit);

		// 		packed = packed | ((allCodes[i]) >> 1);
		// 		// printf("packed first is %d\n", packed);
		// 		fputc(packed, out_file);
		// 		packed = 0;
		// 		packed = packed | ( storeLastBit << 7);

		// 		// printf("packed shold only contain 1 is %d\n", packed);
		// 		shiftingCounter++;
		// 		if (numberOfCodes == 3) fputc(packed, out_file);
		// 	}
		// 	else if (shiftingCounter == 3) {

		// 		packed = packed | (allCodes[i] << 4);

		// 		// printf("packed on shfiting 3 is.. %d\n", packed);
		// 		shiftingCounter++;
		// 		if (numberOfCodes == 4) fputc(packed, out_file);
		// 	}
		// 	else if (shiftingCounter == 4) {
		// 		packed = packed | (allCodes[i] << 1);
		// 		shiftingCounter++;
		// 		if (numberOfCodes == 5) fputc(packed, out_file);
		// 	}
		// 	else if (shiftingCounter == 5) {
		// 		storeLastBit = allCodes[i] & 0x1;
		// 		secondLastBit = allCodes[i] & 0x2;
		// 		thirdBit = allCodes[i] & 0x4;
		// 		// printf("stored last bit should be %d\n", storeLastBit);
		// 		// if (codeCounter >= 8 && codeCounter < 16 ) {
		// 			printf("................\n");
		// 			packed = packed | ((allCodes[i]) >> 3);
		// 			// printf("packed first is %d\n", packed);
		// 			fputc(packed, out_file);
		// 			packed = 0;
		// 			packed = packed | ( thirdBit << 5 );
		// 			packed = packed | ( secondLastBit << 5);
		// 			packed = packed | ( storeLastBit << 5 );

		// 		// }
		// 		// else {

		// 		// 	packed = packed | ((allCodes[i]) >> 2);
		// 		// 	fputc(packed, out_file);
		// 		// 	packed = 0;
		// 		// 	packed = packed | ( secondLastBit << 5);
		// 		// 	packed = packed | ( storeLastBit << 6);


		// 		// }
		// 		// printf("packed first is %d\n", packed);
		// 		// // printf("packed shold only contain 1 is %d\n", packed);
		// 		shiftingCounter++;
		// 		if(numberOfCodes==6) putc(packed, out_file);
		// 	}
		// 	else if(shiftingCounter == 6 || shiftingCounter == 8 || shiftingCounter == 10 || shiftingCounter == 12) {
		// 		packed = packed | (allCodes[i] << 1);
		// 		shiftingCounter++;
		// 		if(shiftingCounter == 13) fputc(packed, out_file);
		// 	}
		// 	else if (shiftingCounter == 7 || shiftingCounter == 9 || shiftingCounter==11) {
		// 		storeLastBit = allCodes[i] & 0x1;
		// 		secondLastBit = allCodes[i] & 0x2;
		// 		thirdBit = allCodes[i] & 0x4;

		// 		packed = packed | (allCodes[i] >> 3);
		// 		fputc(packed, out_file);
		// 		packed = 0;
		// 		packed = packed | ( thirdBit << 5 );
		// 		packed = packed | ( secondLastBit << 5);
		// 		packed = packed | ( storeLastBit << 5 );
		// 		shiftingCounter++;
		// 		if(numberOfCodes == 7 || numberOfCodes == 9 || numberOfCodes == 11) fputc(packed, out_file);
		// 	}

		// 	// printf("codes are..%d................... %d\n", i, allCodes[i]);

		// }


		for (int i = 0; i < 5000; i++) {
			concatenated[i] = '\0';
		}

		
		// free(concatenatedBase);
		// freeList(listHead);

		// printCodeTable();

		// printf("concabases... %s\n", concatenatedBase);
		// listHead = NULL;
		// listTail = NULL;
		// numberOfBases = 0;


		// for (int i = 0; i < numberOfCodes; i++) {
		// 	allCodes[i] = '0';
		// }
		

}

unsigned long long int powerFunc(int exponent) {

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

void writeToFile(unsigned int *codeArray, unsigned int numberOfCodes, FILE *out_file) {
		printf("These are the codes....\n");
		unsigned codeValueCounter = 4;
		unsigned int writeTheseBits = 3;
		unsigned long long int baseValue = 0;
		unsigned long long int temp8bitBase = 0;
		unsigned int totalWritten = 3;
		unsigned int totalWrittenDifference = 0;
		unsigned int maskingAmount = 0;
		unsigned int endOfBaseWrite = 2;
		unsigned int flagOfWritten = 0;
		unsigned int z = 8;
		unsigned int biggerMask = 0;
		unsigned int moveFlag = 0;
		for (int i = 0; i < numberOfCodes; i++) {
			printf("pick %d\n",*(codeArray + i));
		}

		for (int i = 0; i < numberOfCodes; i++) {
			printf("code array is %d \n",*(codeArray + i) );


			baseValue = baseValue | *(codeArray + i);
			// if (writeTheseBits == 9) z = 9;
			totalWrittenDifference = abs(totalWritten - 8);
			maskingAmount = powerFunc(totalWrittenDifference) - 1;
			endOfBaseWrite = 8 - totalWrittenDifference;
										// printf("total written is %d\n", totalWritten);

			if (totalWritten >= 8) 	{
				temp8bitBase = baseValue;
				printf("totalWrittenDiff is %d\n", totalWrittenDifference);
				temp8bitBase = temp8bitBase >> totalWrittenDifference;
			
				fputc(temp8bitBase, out_file);

				printf("masking amoutn is %d\n", maskingAmount);
				baseValue = baseValue & maskingAmount;
				biggerMask = totalWrittenDifference - 8;
				if (biggerMask == 2 && writeTheseBits == 9) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 2;
					moveFlag = 1;
				}				
				else if (biggerMask == 1 && writeTheseBits == 9) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 1;
					moveFlag = 1;
				}
				else if(biggerMask == 0 && writeTheseBits == 9) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 0;
					moveFlag = 1;
					// continue;
				}
				if (biggerMask == 4 && writeTheseBits == 10) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 4;
					moveFlag = 1;		
				}
				else if (biggerMask == 4 && writeTheseBits == 10) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 4;
					moveFlag = 1;		
				}
				else if (biggerMask == 3 && writeTheseBits == 10) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 3;
					moveFlag = 1;		
				}				
				else if (biggerMask == 2 && writeTheseBits == 10) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 2;
					moveFlag = 1;		
				}
				else if (biggerMask == 1 && writeTheseBits == 10) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 1;
					moveFlag = 1;		
				}
				else if (biggerMask == 0 && writeTheseBits == 10) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 0;
					moveFlag = 1;		
				}

				if (biggerMask == 6 && writeTheseBits == 11) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 6;
					moveFlag = 1;				
				}
				else if (biggerMask == 5 && writeTheseBits == 11) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 5;
					moveFlag = 1;				
				}
				else if (biggerMask == 4 && writeTheseBits == 11) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 4;
					moveFlag = 1;				
				}
				else if (biggerMask == 3 && writeTheseBits == 11) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 3;
					moveFlag = 1;				
				}
				else if (biggerMask == 2 && writeTheseBits == 11) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 2;
					moveFlag = 1;				
				}
				else if (biggerMask == 1 && writeTheseBits == 11) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 1;
					moveFlag = 1;				
				}
				else if (biggerMask == 0 && writeTheseBits == 11) {
					fputc(baseValue, out_file);
					baseValue = 0;
					totalWrittenDifference = 0;
					moveFlag = 1;				
				}




				// if((writeTheseBits == 10 || writeTheseBits == 11 || writeTheseBits == 12) && totalWrittenDifference == 8) {
				// 	fputc(baseValue, out_file);
				// 	baseValue = 0;
				// 	if(writeTheseBits == 11) totalWritten = 9;
				// 	if(writeTheseBits == 10) totalWritten = 10;
				// 	if(writeTheseBits == 11) totalWritten = 11;
				// 	if(writeTheseBits == 12) totalWritten = 12;
					
				// }


				totalWritten = totalWrittenDifference;
				printf("basevalue should be 00.0000..: %llu\n", baseValue);
				flagOfWritten = 1;
			}

			if (( i + 1) == numberOfCodes && flagOfWritten == 1) {

				printf("im here... base value is %d and endOfBaseWrite is %d\n", baseValue, endOfBaseWrite);
				printf("masking amount is.... %d\n", maskingAmount);
				baseValue = baseValue << endOfBaseWrite;
				fputc(baseValue, out_file);
				flagOfWritten = 0;
				break;
			}
			flagOfWritten = 0;

			if( (i + 1) == numberOfCodes) {
				totalWrittenDifference = 8 - totalWritten;
				printf("im her in second if e\n");
				baseValue = baseValue << totalWrittenDifference;
				fputc(baseValue, out_file);
				flagOfWritten = 0;
				break;
				}

			codeValueCounter++;	
			if (codeValueCounter > 8 && codeValueCounter <= 16) writeTheseBits = 4;
			if (codeValueCounter > 16 && codeValueCounter <= 32) writeTheseBits = 5;
			if (codeValueCounter > 32 && codeValueCounter <= 64) writeTheseBits = 6;
			if (codeValueCounter > 64 && codeValueCounter <= 128) writeTheseBits = 7;
			if (codeValueCounter > 128 && codeValueCounter <= 256) writeTheseBits = 8;
			if (codeValueCounter > 256 && codeValueCounter <= 512) writeTheseBits = 9;
			if (codeValueCounter > 512 && codeValueCounter <= 1024) writeTheseBits = 10;
			if (codeValueCounter > 1024 && codeValueCounter <= 2048) writeTheseBits = 11;
			if (codeValueCounter > 2048 && codeValueCounter <= 4096) writeTheseBits = 12;

			if (moveFlag != 1) baseValue = baseValue << writeTheseBits;
			moveFlag = 0;
			printf("base value is....... %d\n", baseValue );
			totalWritten = totalWritten + writeTheseBits;
			printf("writethsesbits is.... %d and totalwritten is %d \n", writeTheseBits, totalWritten);
			
		}




}