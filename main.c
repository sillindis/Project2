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
	stat("file1.txt", &stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
	stat("file2.txt", &stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
	time1 = localtime(&stat1.st_mtime);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
	time2 = localtime(&stat2.st_mtime);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    printf("size compare");
    if (stat1.st_size > stat2.st_size) printf("\nfile1 is bigger\n");
    else if (stat1.st_size < stat2.st_size) printf("\nfile2 is bigger\n");
    else printf("\nsizes are same\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    printf("\nblock compare");
    if (stat1.st_blocks > stat2.st_blocks) printf("\nfile1 has more blocks\n");
    else if (stat1.st_blocks < stat2.st_blocks) printf("\nfile2 has more blocks\n");
    else printf("\nboth block sizes are same\n");

}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    printf("\ndate compare");
    if (time1->tm_mon > time2->tm_mon) {
        if (time1->tm_mday > time2->tm_mday) {
            if (time1->tm_hour > time2->tm_hour) {
                if (time1->tm_min > time2->tm_min) {
                    printf("\nfile2 is early\n");
                }
            }
        }
    }
    else if (time1->tm_mon == time2->tm_mon) {
        if (time1->tm_mday == time2->tm_mday) {
            if (time1->tm_hour == time2->tm_hour) {
                if (time1->tm_min == time2->tm_min) {
                    printf("\nsame date\n");
                }
            }
        }
    }
    else
        printf("\nfile1 is early\n");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    printf("\ntime compare");
    if (stat1.st_mtime > stat2.st_mtime)
        printf("\nfile2 is early\n");
    else if (stat1.st_mtime == stat2.st_mtime)
        printf("\nsame time\n");
    else
        printf("\nfile1 is early\n");
}