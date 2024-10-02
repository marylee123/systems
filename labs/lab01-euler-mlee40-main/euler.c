// Problem 01
int multOf3or5(int max){
    int sum = 0;
    int num = 1;
    while(num < max){
        if(num % 3 == 0 || num % 5 == 0){
            sum += num;
        }
        num++;
    }
    return sum;
}

//Problem 05
int lcm(int max){
    int lcm = 1;
    int num = 2;
    while(num <= max){
        int increment = lcm;
        while(lcm % num != 0){
            lcm += increment;
        }
        num++;
    }
    return lcm;
}

//Problem 06
int sumSqDiff(int max){
    int sumSq = 0;
    int sum = 0;
    for(int i = 1; i <= max ; i++){
        sum += i;
        sumSq += i*i;
    }
    int sqSum = sum*sum;
    return sqSum - sumSq;
}

//Problem 14
int collatz(int max){
    unsigned int startNum = 1;
    unsigned int longestStart = startNum;
    
    int maxCount = 1;
    
    while(startNum < max){
        unsigned int num = startNum;
        int count = 1;
        while(num != 1){
            if(num % 2 == 0){
                num = num/2;
            }
            else{
                num = 3*num + 1;
            }
            count++;
        }
        if(maxCount < count){
            maxCount = count;
            longestStart = startNum;
        }
        startNum++;
    }
    return longestStart;
}

//Problem 02
int evenFib(int max){
    if(max < 2){
        return 0;
    }
    int num1 = 1;
    int num2 = 2;
    int sum = num2;
    int nextNum = num1 + num2;
    while(nextNum <= max){
        if(nextNum%2 == 0){
            sum += nextNum;
        }
        num1 = num2;
        num2 = nextNum;
        nextNum = num1 + num2;
    }
    return sum;
}
