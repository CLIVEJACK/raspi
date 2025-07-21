#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100
#define MAX_ID 30
#define MAX_PW 30
#define FILE_NAME "userFile.txt"

void signUp(){
	char id[MAX_ID];
	char pw[MAX_PW];

	printf("회원가입- 아이디 입력: ");
	scanf("%s", id);
	printf("회원가입- 패스워드 입력: ");
	scanf("%s", pw);

	FILE *fp = fopen(FILE_NAME, "a");
	if(fp==NULL){
		printf("\n파일열기실패\n");
		return;
	}

	fprintf(fp, "%s %s\n", id, pw);
	fclose(fp);
	printf("\n== 회원가입 완료==\n");
}

void logIn(){
	char id[MAX_ID], pw[MAX_PW];
	char file_id[MAX_ID], file_pw[MAX_PW];
	int found = 0;

	printf("아이디 입력: ");
	scanf("%s", id);
	printf("패스워드 입력: ");
	scanf("%s", pw);

	FILE *fp = fopen(FILE_NAME, "r");
	if (fp==NULL){
		printf("\n파일열기실패\n");
		return;
	}

	while(fscanf(fp, "%s %s", file_id, file_pw) != EOF){
		if(strcmp(id, file_id) == 0 && strcmp(pw, file_pw) == 0){
			found = 1;
			break;
		}
	}
	fclose(fp);

	if(found){
		printf("\n== 로그인 성공==\n");
	} else {
		printf("\n로그인 실패: 아이디 및 패스워드 불일치\n");
	}
}

int main(){
	int choice;
	while(1){
		printf("\n1. 회원가입\n2. 로그인\n3. 종료\n\n선택: ");
		if (scanf("%d", &choice) != 1){
			printf("\n숫자만 입력!!\n");
			while(getchar() != '\n');
			continue;
		}
		while(getchar() != '\n');
		printf("\n");

		switch(choice){
			case 1:
				signUp();
				break;

			case 2:
				logIn();
				break;

			case 3:
				printf("프로그램 종료\n");
				return 0;

			default:
				printf("잘못된 입력!!! 다시 선택하시오\n");
		}
	}
	return 0;
}
