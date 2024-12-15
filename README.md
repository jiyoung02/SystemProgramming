# SystemProgramming 과제
2024년 2학기 시스템프로그래밍 강의 라이브러리 생성 과제용 코드입니다.
피보나치수열과 소수 관련된 함수들을 담고있는 라이브러리를 리눅스환경에서 생성하였습니다.

## 파일 구성
  - library source code : fibo.c, prime.c
  - static library : libMyMath.a
  - shared library : libMyMath.so
  - test code : static.c(compiletime linking용), runtime.c(runtime linking용)


## 기능 소개
  - fibo : 피보나치수열에 대한 함수를 담은 파일입니다.
    - int getFibo(int a) : a번째 피보나치 수를 리턴합니다.
    - int* getFiboList(int a) : 1부터 a번째까지 피보나치 수를 담은 배열을 리턴합니다.
    - void printFibo(int a) : 1부터 a번째까지 피보나치 수를 출력합니다.

  
  -	prime : 소수관련 함수를 담은 파일입니다.
    - int isPrime(int a) :  a가 소수이면 1을 리턴, 아니면 0을 리턴



## StaticLibrary 생성
  ![](https://github.com/jiyoung02/SystemProgramming/blob/main/src/staticlib.png)
  
  1)	아카이브 파일에 담을 fibo와 prime을 object 파일로 컴파일합니다. 
  2)	ar -r 옵션을 사용해 fibo.o와 prime.o를 담은 libMyMath.a를 생성합니다.
  3)	StaticLinkage용 테스트 파일인 Static.c를 object파일로 만듭니다.
  4)	gcc -static static.o -L. -lMyMath 명령어로 실행파일을 만들어줍니다.

    	+ "-static" : staticLinkage를 하기 위한 옵션
    	+ "-L." : current working directory에서 파일 찾는 옵션



## SharedLibrary 생성
  ![](https://github.com/jiyoung02/SystemProgramming/blob/main/src/sharedlib.png)
  
  1)	fibo.c와 prime.c를 -fpic옵션을 사용하여 position independent code로 만들어줍니다.
  2)	-shared 옵션을 사용해 fibo.o와 prime.o를 담고있는 libMyMath.so파일을 생성합니다.
     
  ![](https://github.com/jiyoung02/SystemProgramming/blob/main/src/dynamic.png)
  
  3)	gcc -rdynamic runtime.c -ldl 옵션을 통해 runtimeLinking을 지원하는 실행파일을 생성합니다.
     > runtime.c는 dlfcn라이브러리를 포함하고 있습니다.

## 실행화면
  1. compiletime linking
     
  ![](https://github.com/jiyoung02/SystemProgramming/blob/main/src/compile.png)
    
  2. runtime linking
     
  ![](https://github.com/jiyoung02/SystemProgramming/blob/main/src/runtime.png)
