#include <stdio.h>
#include <string.h>
#define MAX_LEN 30
//مقدار ماکسیمم تعداد دانشجویان را ثابت تعریف کردم 

struct Student   //استراکتی به نام دانشجو تعریف کردم که نام دانشجو و نمره را ذخیره می‌کند
{
    char name[50];
    int grade;
};

int addstudents(struct Student students[], int max_len, int countStudent) 
{ //این تابع نام دانشجویان و نمره آنها را گرفته و به استراکت اضافه می‌کند
    if (countStudent < max_len) //بررسی اینکه آرایه دانشجویان هنوز جای خالی دارد یا نه
    {
        printf("\nenter your name: ");
        scanf("%s", students[countStudent].name);
        printf("enter your grade:");
        scanf("%d", &students[countStudent].grade);
        
        printf("\nkhosh omadi!\n");
        return countStudent+1; //یکی به تعداد دانشجوها اضافه می کند
    } 
    else 
    {
        printf("ja nadarim!\n");
        return countStudent;
    }
}

void displayGrades(struct Student students[], int countStudent) 
{ //این تابع لیست نمرات را نمایش می‌دهد
    printf("\nstudents grades list:\n");
    for (int i = 0; i < countStudent; i++) 
    { //این حلقه بازه نمرات را مشخص می‌کند
        printf("\nname:%s / grade:%d\n", students[i].name, students[i].grade);
    }
}

float averageGrades(struct Student students[], int countStudent) 
{ //این تابع میانگین نمرات را محاسبه می‌کند
    if (countStudent == 0) 
    { //این شرط بررسی می‌کند که آیا اصلا دانشجویی در لیست وجود دارد یا نه
        printf("\nthere are no students.\n");
        return 0.0;
    }

    int sum = 0; //متغیر مجموع نمرات
    for (int i = 0; i < countStudent; i++) 
    {
        sum = sum+students[i].grade; 
        //در بازه ای که حلقه مشخص کرده، هر نمره ای که پیدا کرد را به مجموع اضافه کند
    }

    return (float)sum / countStudent; 
    //مجموع را بر تعداد دانشجویان تقسیم کرده(فرمول میانگین) و جواب را به صورت اعشاری برگرداند
}

void check(struct Student students[], int countStudent) 
{  //این تابع قبولی دانشجو را بررسی می‌کند
    if (countStudent == 0) 
    {
        printf("\nthere are no students.\n");
        return;
    }

    printf("\npass status of students:\n");
    for (int i = 0; i < countStudent; i++) 
    {
        if (students[i].grade >= 50) 
        //این شرط بررسی می‌کند که نمره دانشجو بزرگتر مساوی پنجاه هست یا نه
        printf("name: %s → passed\n", students[i].name);
        //اگر بود پرینت کند که دانشجو قبول است
        else 
        printf("name: %s → not passed\n", students[i].name);
        //در غیر این صورت پرینت کند دانشجو قبول نشده
    }
}

int findMaxGrade(struct Student students[], int start, int end) 
{ //این تابع بالاترین نمره را پیدا می‌کند
    if (start == end) 
    //اگر ابتدا و انتهای آرایه یکی بود(یعنی فقط یک نمره داشتیم)، همان را برگرداند 
    return students[start].grade;
    
    int middle = (start+end) / 2; 
    //وسط آرایه را پیدا کرده و در هر قسمت ماکسیمم را یافته و بعد دو عدد به دست آمده را مقایسه می‌کنیم 

    int max1= findMaxGrade(students, start, middle);
    //محاسبه ماکسیمم در بخش اول آرایه
    int max2= findMaxGrade(students, middle+1, end);
    //محاسبه ماکسیمم در بخش دوم آرایه
    if(max1>max2) //مقایسه مقدار های به دست آمده و برگرداندن ماکسیمم بزرگتر 
    return max1;
    
    else
    return max2;
}

int findMinGrade(struct Student students[], int start, int end) 
{ //این تابع پایین ترین نمره را پیدا می‌کند 
    if (start == end) 
    return students[start].grade;
    
    int middle = (start+end) / 2;

    int min1= findMinGrade(students, start, middle);
    //محاسبه مینیمم در بخش اول آرایه 
    int min2= findMinGrade(students, middle+1, end);
    //محاسبه مینیمم در بخش دوم آرایه 
    if(min1>min2) //مقایسه مقدار های به دست آمده و برگرداندن مینیمم کوچکتر 
    return min2;
    
    else
    return min1;
}

void sortGrades(struct Student students[], int countStudent) 
{ //این تابع نمرات را مرتب می‌کند 
    for (int i = 0; i < countStudent - 1; i++) 
    {
        int max = i; //فرض میکنیم این متغیر ماکسیمم است و بعد بقیه نمرات را با آن مقایسه می‌کنیم 
        for (int j = i + 1; j < countStudent; j++) 
        { //حلقه بازه نمرات بعد از آی را در نظر می‌گیرد 
            if (students[j].grade > students[max].grade) 
            //اگر نمرات بعدی بزرگتر از متغیر فرضی ما بودند، نمره بزرگتر را در مکس بریزد
            max = j;
        }
     
        struct Student t; //متغیر تی را از نوع استراکت دانشجو تعریف کردم
        //در مراحل پایین عملیات سواپ(جابه‌جایی مقدار های دو متغیر) را با استفاده از متغیر تی انجام دادم
        t = students[i]; 
        students[i] = students[max];
        students[max] = t;
    }
}

int main() 
{
    struct Student students[MAX_LEN];
    int countStudent = 0;
    int choice;

    while (1) 
    { //وقتی یک را داخل شرط حلقه قرار می‌دهیم یعنی حلقه پیوسته اجرا شود تا وقتی که کاربر خروج را انتخاب کند
        printf("\nMenu:\n");
        printf("1- enter student name and grade\n");
        printf("2- list of grades\n");
        printf("3- finding the highest grade\n");
        printf("4- finding the lowest grade\n");
        printf("5- average of grades\n");
        printf("6- check pass status of students\n");
        printf("7- exit of system\n");
        printf("8- sort grades\n");
        printf("\nenter your choice:");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                countStudent = addstudents(students, MAX_LEN, countStudent);
                //دانشجوی جدید و نمره آن را گرفته و داخل شمارنده تعداد دانشجویان می‌ریزد 
                break;

            case 2:
                displayGrades(students, countStudent);
                //لیست نمرات را نمایش می‌دهد 
                break;

            case 3:
                if (countStudent == 0) 
                printf("\nthere are no students.\n");
                
                else 
                {
                   int maxGrade = findMaxGrade(students, 0, countStudent-1);
                   //از آرایه صفر تا آخرین دانشجو دنبال ماکسیمم می‌گردد 
                   printf("\nmaximum of grades is: %d\n", maxGrade);
                }
                break;

            case 4:
                if (countStudent == 0) 
                printf("\nthere are no students.\n");
                
                else 
                {
                   int minGrade = findMinGrade(students, 0, countStudent-1);
                   //از آرایه صفر تا آخرین دانشجو دنبال مینیمم می‌گردد
                   printf("\nminimum of grades is: %d\n", minGrade);
                }
                break;

            case 5:
                printf("\naverage is: %.2f\n", averageGrades(students, countStudent));
                //میانگین را با دو رقم اعشار پرینت می‌کند 
                break;
            
            case 6:
                check(students, countStudent);
                //قبولی را بررسی می‌کند 
                break;

            case 7:
                printf("\nyou exit the system.\n");
                return 0; //با این دستور به طور کلی از حلقه خارج می‌شود 
                
            case 8:
                if (countStudent == 0) 
                printf("\nthere are no students.\n");
                
                else 
                {
                    sortGrades(students, countStudent);
                    displayGrades(students, countStudent);
                    //نمرات را مرتب کرده و نمایش می‌دهد 
                }
                break;
                
            default:
                printf("unknown choice! Please try again.\n");
                //اگر چیزی غیر گزینه های منو وارد کردیم این پیام را پرینت کند 
        }
    }
    return 0;
}