#include <cstdio>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

using namespace std;

int main(int argc, char** argv)
{
	

	if (argc != 3)
	{
		printf("[exe 파일1 파일2] 형식으로 입력해주세요.");
		return 0;
	}
	
	FILE *fp1;
	FILE *fp2;
	//unsigned int == uint32_t
	//unsigned char == uint8_8
	uint32_t buffer1[32];
	uint32_t buffer2[32];
	int num1;
	int num2;
  
	if ((fp1 = fopen(argv[1], "rb"))!= NULL){
		num1=fread(buffer1, sizeof(1), 32, fp1);
		if (num1 !=0) {
			//printf("buffer1 = %x\n", buffer1);
			//printf("What's in the buffer1: %x\n", *buffer1);
			fclose(fp1);
		}
		else{printf("인식실패");}
	}
	else {
	printf("인식 실패");
	}
	
	if ((fp2 = fopen(argv[2], "rb"))!=NULL){
		num2=fread(buffer2, sizeof(1), 32, fp2);
		if (num2 != 0) {
			//printf("buffer2 = %x\n", buffer2);
			//printf("What's in the buffer2 : %x\n", *buffer2);
			fclose(fp2);
		}
		else{printf("인식실패");}
	}
	
	else {
	printf("인식 실패");
	}
	
	uint16_t right_num1= ntohl(*buffer1);
	uint16_t right_num2= ntohl(*buffer2);
	int sum = right_num1 + right_num2;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", right_num1, right_num1, right_num2, right_num2, sum, sum);
	
	return 0;
	

}
