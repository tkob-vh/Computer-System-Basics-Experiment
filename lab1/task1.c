#include <stdio.h>
#include <string.h>
#include <stdint.h>

const int N = 5;
char message[1000];
int offset = 0;

typedef struct STUDENT{
    char name[8];
    short age;
    float score;
    char remark[200];
} student;

int pack_student_bytebybyte(student *s, int sno, char *buf);
int pack_student_whole(student *s, int sno, char *buf);
int restore_student(char *buf, int len, student *s);

int main(){
    student old_s[N];
    student new_s[N];
    int message_length;
    int old_length, new_length;


    // Student 0
    strcpy(old_s[0].name, "yyx");    
    old_s[0].score = 45;
    old_s[0].age = 100;
    strcpy(old_s[0].remark, "Hello Wolrd!");
    //Student 1
    strcpy(old_s[1].name, "asdg");
    old_s[1].score = 23;
    old_s[1].age = 32;
    strcpy(old_s[1].remark, "fjadfjsd");
    //Student 2
    strcpy(old_s[2].name, "gmnroei");
    old_s[2].score = 24;
    old_s[2].age = 65;
    strcpy(old_s[2].remark, "fjoiadsjgaiosgn");
    //Student 3
    strcpy(old_s[3].name, "jdsiof");
    old_s[3].score = 43;
    old_s[3].age = 53;
    strcpy(old_s[3].remark, "jdfoaijdfgaiojg");
    //Student 4
    strcpy(old_s[4].name, "jao");
    old_s[4].score = 76;
    old_s[4].age = 43;
    strcpy(old_s[4].remark, "gjknarignearogfnae");

    printf("The information of the old_s: \n");
    for(int i = 0; i < N; i++){
        old_length += sizeof(old_s[i]);
        printf("Student: %d, name: %s, age: %hd, score: %f \n", i, old_s[i].name, old_s[i].age, old_s[i].score);
        printf("Remark:\n%s\n\n", old_s[i].remark);
    }

    pack_student_bytebybyte(old_s, 2, message);
    pack_student_whole(&old_s[2], 3, message);

    message_length = offset;

    restore_student(message, message_length, new_s);

    printf("The information of the new_s: \n");
    for(int i = 0; i < N; i++){
        printf("Student: %d, name: %s, age: %hd, score: %f \n", i, new_s[i].name, new_s[i].age, new_s[i].score);
        printf("Remark:\n%s\n\n", new_s[i].remark);
    }


    printf("The length of the old_s: %d\n", old_length);
    printf("The length after packed: %d\n", message_length);
    
    printf("The first 20 bytes of message:\n");
    for(int i = 0; i < 20; i++){
        printf("%c",message[i]);
    }
    printf("\n");

    return 0;
}

/* 
 * s: the first address of the array to be packed
 * sno: the number of students to be packed
 * buf: the first address of the region after being packed
 * return value: the number of bytes after being packed
 */
int pack_student_bytebybyte(student *s, int sno, char *buf){
    //write to the buffer byte by byte
    for(int i = 0; i < sno; i++){
        //pack name
        for(int j = 0; s[i].name[j] != '\0'; j++){
            buf[offset++] = s[i].name[j];
        }
        buf[offset++] = '\0';
        //pack age
        buf[offset++] = (s[i].age) & 0xFF;
        buf[offset++] = (s[i].age >> 8) & 0xFF;
        //pack score
        uint32_t f2i = *(uint32_t *)&s[i].score;
        buf[offset++] = (f2i) & 0xFF;
        buf[offset++] = (f2i >> 8) & 0xFF;
        buf[offset++] = (f2i >> 16) & 0xFF;
        buf[offset++] = (f2i >> 24) & 0xFF;
        //pack remark
        for(int j = 0; s[i].remark[j] != '\0'; j++){
            buf[offset++] = s[i].remark[j];
        }
        buf[offset++] = '\0';


    }
    return 0;
}

int pack_student_whole(student *s, int sno, char *buf){
    //write short and float using one statement;
    //write char using strcpy;
    for(int i = 0; i < sno; i++){
        //pack name
        strcpy(&buf[offset], s[i].name); 
        while(buf[offset] != '\0') offset++;
        offset++;
        //pack age
        memcpy(&buf[offset], &s[i].age, sizeof(short));
        offset += sizeof(short);
        //pack score
        memcpy(&buf[offset], &s[i].score, sizeof(float));
        offset += sizeof(float);
        //pack remark
        strcpy(&buf[offset], s[i].remark);
        while(buf[offset] != '\0') offset++;
        offset++;

    }
    return 0;
}

/*
 * buf: same as above
 * len: the length of the data in the buffer (in bytes)
 * s: same as above
 * return value: the nmuber of students unpacked
 */
int restore_student(char *buf, int len, student *s){
    int local_offset = 0;
    int num = 0;
    while(local_offset < len){
        //unpack name
        int i;
        for(i = 0; buf[local_offset] != '\0'; i++){
            s[num].name[i] = buf[local_offset++];
        }
        s[num].name[i++] = buf[local_offset++];
        //unpack age
        s[num].age = 0;
        for(int i = 0; i < sizeof(short); i++){
            s[num].age += ((short)buf[local_offset++]) << (8 * i);
        }
        //unpack score
        /*
        uint32_t tmp_float = 0;
        for(int i = 0; i < sizeof(float); i++){
            tmp_float += ((uint32_t)buf[local_offset++]) << (8 * i);
        }
        s[num].score = *(float *)&tmp_float;
        */
        memcpy(&s[num].score, &buf[local_offset], sizeof(float));
        local_offset += sizeof(float);
        //unpack remark
        for(i = 0; buf[local_offset] != '\0'; i++){
            s[num].remark[i] = buf[local_offset++];
        }
        s[num].remark[i++] = buf[local_offset++];
        
        num++;
    }
    return num;
}

