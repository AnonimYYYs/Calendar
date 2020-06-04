#include <jni.h>
#include <string>

using namespace std;
// ------------- start of alexey' part -----------------
int numberOfDays(int monthNumber, int year)
{
    // January
    if (monthNumber == 0)
        return (31);

    // February
    if (monthNumber == 1)
    {
        // If the year is leap then February has
        // 29 days
        if (year % 400 == 0 ||
            (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }

    // March
    if (monthNumber == 2)
        return (31);

    // April
    if (monthNumber == 3)
        return (30);

    // May
    if (monthNumber == 4)
        return (31);

    // June
    if (monthNumber == 5)
        return (30);

    // July
    if (monthNumber == 6)
        return (31);

    // August
    if (monthNumber == 7)
        return (31);

    // September
    if (monthNumber == 8)
        return (30);

    // October
    if (monthNumber == 9)
        return (31);

    // November
    if (monthNumber == 10)
        return (30);

    // December
    if (monthNumber == 11)
        return (31);
}

void generateDates(int* arr, int month, int year)
{
    if (month == 0 && year == 0)        //invalid input
    {
        for (int i = 0; i < 42; i++)arr[i] = -1;
    }
    else
    {
        for (int i = 0; i < 42; i++)arr[i] = 0;
        static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
        int firstDay = ((year + year / 4 - year / 100 + year / 400 + t[month - 1])) % 7;  //sunday first
        if (month == 1 || month == 2)
            if (year % 400 == 0 ||
                (year % 4 == 0 && year % 100 != 0))firstDay -= 2; else firstDay--;
        if (firstDay == -1)firstDay = 6;
        if (firstDay == -2)firstDay = 5;
        int lastDay = numberOfDays(month - 1, year) + firstDay;
        for (int i = firstDay, ind = 1; i != lastDay; i++, ind++) arr[i] = ind;
    }

}
// ------------- end of alexey' part 0------------------



// ------------- start of ivan' part -------------------
int isGoodMonth(string month){
    for(int i = 0; i < month.length(); i++){
        if(!(month[i] >= '0' && month[i] <= '9')){
            return(0);
        }
    }
    int num_month = stoi(month);
    if(!(num_month >= 1 && num_month <= 12)){
        return(0);
    }
    return(num_month);
}

int isGoodYear(string year){
    for(int i = 0; i < year.length(); i++){
        if(!(year[i] >= '0' && year[i] <= '9')){
            return(0);
        }
    }
    int num_year = stoi(year);
    if(!(num_year >= 1919 && num_year <= 2029)){
        return(0);
    }
    return(num_year);
}
// ------------- end of ivan' part ---------------------



// ------------- start of nikita' part -----------------
extern "C" JNIEXPORT jintArray JNICALL
Java_com_example_calendar_MainActivity_getCalendar(
        JNIEnv* env,
        jobject /* this */,
        jstring j_month,
        jstring j_year){
    string c_month = env->GetStringUTFChars(j_month, NULL);
    string c_year = env->GetStringUTFChars(j_year, NULL);

    int num_month = isGoodMonth(c_month);
    int num_year = isGoodYear(c_year);

    if(num_month == 0 || num_year == 0){
        num_month = 0;
        num_year = 0;
    }

    int days[42];

    generateDates(days, num_month, num_year);

    jintArray jarray_month = env->NewIntArray(42);
    env->SetIntArrayRegion(jarray_month, 0, 42, days);

    return(jarray_month);
}
// ------------- end of nikita' part -------------------


