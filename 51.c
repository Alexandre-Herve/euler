#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPrime(int num);
int testEightPrime(int size);
long replace(int num, int *currentReplacement, int nbDigitsReplaced, int replacer);
int *numToArray(int num, int size);
int arrayToNum(int *array, int size);
long getAmongst(int size, int num);
long getAmongstMax(int size);
long factorial(int num);
int *getNextReplacement(int *array, int length, int maxVal, int iteration);
int *propagatePlusOne(int *array, int length, int index);

int main() {
  int i, num;
  for(i=4; i<10; i++) {
    printf("size=%d\n", i);
    num = testEightPrime(i);
    if(num != 0) {
      printf("Found %d\n", num);
    }
  }
  printf("Finished\n");
  return 0;
}

int testEightPrime(int size) {

  int primesCount;
  int nbDigitsReplaced;
  long currentNum;
  long higherBoundAccordingToSize;
  long lowerBoundAccordingToSize;
  long replaced;
  long amongstMax = getAmongstMax(size);
  int nbReplacements;
  int maxVal;
  int i, j, k;
  int *p;
  long primes[8];

  for(nbDigitsReplaced = size; nbDigitsReplaced > 0; nbDigitsReplaced--) {

    higherBoundAccordingToSize = pow(10, size - nbDigitsReplaced) - 1;
    lowerBoundAccordingToSize = pow(10, size - nbDigitsReplaced - 1) + 1;

    nbReplacements = getAmongst(size, nbDigitsReplaced);
    int rep[nbDigitsReplaced];

    for (j=0; j < nbReplacements; j++) {

      p = getNextReplacement(rep, nbDigitsReplaced, size - 1, j);

      for(i=0; i<nbDigitsReplaced; i++) {
        rep[i] = p[i];
      }

      for(currentNum = lowerBoundAccordingToSize; currentNum < higherBoundAccordingToSize; currentNum+=2) {

        primesCount = 0;

        for(i=9; i>-1; i--) {
          replaced = replace(currentNum, rep, nbDigitsReplaced, i);
          if(isPrime(replaced)) {
            primes[primesCount] = replaced;
            primesCount++;
          }
        }
        if(primesCount == 8) {
          printf("primesCount: %d\n", primesCount);
          for(k = 0; k<8; k++) {
            printf("family member: %ld\n", primes[k]);
          }
        }
      }

    }
  }
  return 0;
}

int isPrime(int num) {
  int i;
  int root;
  root = (int) sqrt((double) num);
  for(i=2; i < root + 1; i++) {
    if(num % i == 0) {
      return 0;
    }
  }
  return 1;
}

long replace(int num, int *currentReplacement, int nbDigitsReplaced, int replacer) {
  int i, arrayNumIndex;
  long replaced;

  arrayNumIndex = 0;

  int numSize = (int) log10((float)num) + 1;
  int *arrayNum = numToArray(num, numSize);

  int size = numSize + nbDigitsReplaced;
  int combinedArray[size];

  for(i=0; i<size; i++) {
    combinedArray[i] = -1;
  }

  for(i=0; i<nbDigitsReplaced; i++) {
    *(combinedArray + *(currentReplacement + i)) = replacer;
  }

  for(i=0; i < size; i++) {
    if(combinedArray[i] == -1) {
      combinedArray[i] = arrayNum[arrayNumIndex];
      arrayNumIndex += 1;
    }
  }

  replaced = arrayToNum(combinedArray, size);
  free(arrayNum);

  return replaced;
}

int *numToArray(int num, int size) {
  int *array = malloc(size * sizeof(int));
  int temp;
  int i;
  for(i=0; i<size; i++) {
    temp = num / 10;
    *(array + i) = num - 10 * temp;
    num /= 10;
  }
  return array;
}

int arrayToNum(int *array, int size) {
  int i;
  int num = 0;
  for(i=0; i<size; i++) {
    num += array[i] * pow(10, i);
  }
  return num;
}

long getAmongst(int size, int num) {
  return factorial(size) / (factorial(num) * factorial(size - num));
}

long getAmongstMax(int size) {
  return getAmongst(size, size / 2);
}

long factorial(int num) {
  if(num == 0) {
    return 1;
  } else {
    return num * factorial(num - 1);
  }
}

int *getNextReplacement(int *array, int length, int maxVal, int iteration) {
  int i;
  if(iteration == 0) {
    for(i=0; i < length; i++) {
      *(array + length - 1 - i) = i;
    }
    return array;
  } else {
    for(i=0; i<length; i++) {
      if(*(array + i) < maxVal) {
        return propagatePlusOne(array, length, i);
      }
    }
  }
}

int *propagatePlusOne(int *array, int length, int index) {
  int i;
  int val = *(array + index);
  for(i = 0; i < index + 1; i++) {
    *(array + index - i) = val + 1 + i;
  }
  return array;
}
