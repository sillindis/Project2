#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
	struct stat file1_stat;
	
	stat("file1", &file1_stat);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
	struct stat file2_stat;

	stat("file1", &file2_stat);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
	struct tm* file1_time;

	file1_time = localtime(&file1_stat.st_mtime);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
	struct tm* file2_time;

	file2_time = localtime(&file2_stat.st_mtime);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    
}