#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 10000

// พื้นที่สำหรับการประกาศ function prototype หรือ struct
// ห้ามประกาศ global variables โดยเด็ดขาด

char *trimwhitespace(char *str);
void shorten(char **text);
void print_abbreviations();

int main()
{
    // พื้นที่สำหรับประกาศ local variables
    char texts[10000];

    char test_case[10];
    fgets(test_case, 10, stdin);
    trimwhitespace(test_case); // ดู function definition ของ trimwhitespace ที่ด้านล่าง

    if (strcmp(test_case, "CASE A") == 0)
    {
        shorten();
    }
    else if (strcmp(test_case, "CASE B") == 0)
    {
        shorten();
        print_abbreviations();
    }
}

// ฟังก์ชัน `shorten()` สำหรับการดำเนินการย่อคำในประโยคและแสดงผล (`CASE A`)
void shorten(char *text)
{
    char *buff;

    while (1)
    {
        scanf("%s", buff);

        if (!strcmp(buff, "."))
        {
            break;
        }

        strcat(&text, buff);
    }


}

// ฟังก์ชัน `print_abbreviations()` สำหรับการดำเนินการแสดงชุดคำศัพท์ของตัวย่อ (`CASE B`)
// กรณีที่นิสิตไม่ทำ CASE B นิสิตไม่จำเป็นต้องกรอกโค้ดใด ๆ ในฟังก์ชันนี้ เพื่อหลีกเลี่ยงการเกิด syntax error
void print_abbreviations(
)
{}

// ฟังก์ชันสำหรับการตัด white space หน้าและหลังสตริง
char *trimwhitespace(char *str) {
    char *end;
    while(isspace((unsigned char)*str)) str++;
    if(*str == 0) return str;
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    return str;
}

// พื้นที่สำหรับ function definition อื่น ๆ ที่นิสิตสร้างขึ้น
// หากไม่มีการประกาศฟังก์ชันเพิ่มเติม นิสิตไม่จำเป็นต้องกรอกโค้ดใด ๆ ในพื้นที่นี้ เพื่อหลีกเลี่ยงการเกิด syntax error
/*  */