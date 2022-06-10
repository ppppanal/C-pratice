// Insert more header files when necessary
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

char Exit_selection[] = ""; //For R6 & R0

bool Error;
string title[100] = {};
string temptitle;
double type[100];
int DD[100] = {}, MM[100] = {}, YYYY[100] = {}, st_hh[100] = {}, st_mm[100] = {}, et_hh[100] = {}, et_mm[100] = {}, Type[100] = {};
int tempDD = 0, tempMM = 0, tempYYYY = 0, tempst_hh = 0, tempst_mm = 0, tempet_hh = 0, tempet_mm = 0,tempType = 0;
int record = 0;
int total_stmin[100] = {}, total_etmin[100] = {};
char op1, op2, op3, op4, op5, op6, op7;
char tempDate[] = "", tempST[] = "", tempET[] = "", tempTypeSelect[] = "";//for R1 & R2

void R1()
{
    if (record < 100) { //record = 0 - 99 (at most 100 record)

        int ErrorTime = 0;
        int start;
        bool Error = false, TimeConflict = false;
        bool wrongDataType = false, outRange = false, wrongFormat = false;
        bool wrongEndTime = false;

        Error = false;
        ErrorTime = 0;
        TimeConflict = false;

        //check Title
        if (Error == false && ErrorTime < 3) {
            do {
                Error = false;
                cout << "Enter event title: ";
                getline(cin, temptitle, '\n');
                if (temptitle.length() > 40) {
                    Error = true;
                }
                if (Error == true && ErrorTime < 3) {
                    cout << "Wrong input. The title is at most 40 characters long.\n\n";
                    ErrorTime++;
                }
            } while (Error == true && ErrorTime < 3);
        }


        //check Date
        cout << "\n";
        if (Error == false && ErrorTime < 3) {
            ErrorTime = 0;


            do {
                Error = false;
                wrongDataType = false;
                outRange = false;
                wrongFormat = false;

                cout << "Enter event date: ";

                cin.getline(tempDate, 999999, '\n');
                if (tempDate[2] != '-' || tempDate[5] != '-') {//check Date
                    Error = true;
                    wrongFormat = true;
                }
                if (strlen(tempDate) != 10) {
                    Error = true;
                    wrongFormat = true;
                }
                else if (strlen(tempDate) == 10) {

                    //check DD
                    switch (tempDate[0]) { //check DD (1st input)              
                    case '0': tempDD = 0 * 10; break;
                    case '1': tempDD = 1 * 10; break;
                    case '2': tempDD = 2 * 10; break;
                    case '3': tempDD = 3 * 10; break;
                    case '4': tempDD = 4 * 10; break;
                    case '5': tempDD = 5 * 10; break;
                    case '6': tempDD = 6 * 10; break;
                    case '7': tempDD = 7 * 10; break;
                    case '8': tempDD = 8 * 10; break;
                    case '9': tempDD = 9 * 10; break;
                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }
                    switch (tempDate[1]) { //check DD (2nd input)
                    case '0': tempDD += 0; break;
                    case '1': tempDD += 1; break;
                    case '2': tempDD += 2; break;
                    case '3': tempDD += 3; break;
                    case '4': tempDD += 4; break;
                    case '5': tempDD += 5; break;
                    case '6': tempDD += 6; break;
                    case '7': tempDD += 7; break;
                    case '8': tempDD += 8; break;
                    case '9': tempDD += 9; break;
                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }

                    //check MM
                    switch (tempDate[3]) { //check MM  (1st input)            
                    case '0': tempMM = 0 * 10; break;
                    case '1': tempMM = 1 * 10; break;
                    case '2': tempMM = 2 * 10; break;
                    case '3': tempMM = 3 * 10; break;
                    case '4': tempMM = 4 * 10; break;
                    case '5': tempMM = 5 * 10; break;
                    case '6': tempMM = 6 * 10; break;
                    case '7': tempMM = 7 * 10; break;
                    case '8': tempMM = 8 * 10; break;
                    case '9': tempMM = 9 * 10; break;
                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }

                    switch (tempDate[4]) { //check MM (2nd input)
                    case '0': tempMM += 0; break;
                    case '1': tempMM += 1; break;
                    case '2': tempMM += 2; break;
                    case '3': tempMM += 3; break;
                    case '4': tempMM += 4; break;
                    case '5': tempMM += 5; break;
                    case '6': tempMM += 6; break;
                    case '7': tempMM += 7; break;
                    case '8': tempMM += 8; break;
                    case '9': tempMM += 9; break;

                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }

                    //check YYYY
                    switch (tempDate[6]) { //check YYYY  (1st input)            
                    case '0': tempYYYY = 0 * 1000; break;
                    case '1': tempYYYY = 1 * 1000; break;
                    case '2': tempYYYY = 2 * 1000; break;
                    case '3': tempYYYY = 3 * 1000; break;
                    case '4': tempYYYY = 4 * 1000; break;
                    case '5': tempYYYY = 5 * 1000; break;
                    case '6': tempYYYY = 6 * 1000; break;
                    case '7': tempYYYY = 7 * 1000; break;
                    case '8': tempYYYY = 8 * 1000; break;
                    case '9': tempYYYY = 9 * 1000; break;

                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }

                    switch (tempDate[7]) { //check YYYY (2nd input)
                    case '0': tempYYYY += 0 * 100; break;
                    case '1': tempYYYY += 1 * 100; break;
                    case '2': tempYYYY += 2 * 100; break;
                    case '3': tempYYYY += 3 * 100; break;
                    case '4': tempYYYY += 4 * 100; break;
                    case '5': tempYYYY += 5 * 100; break;
                    case '6': tempYYYY += 6 * 100; break;
                    case '7': tempYYYY += 7 * 100; break;
                    case '8': tempYYYY += 8 * 100; break;
                    case '9': tempYYYY += 9 * 100; break;

                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }

                    switch (tempDate[8]) { //check YYYY  (3rd input)            
                    case '0': tempYYYY += 0 * 10; break;
                    case '1': tempYYYY += 1 * 10; break;
                    case '2': tempYYYY += 2 * 10; break;
                    case '3': tempYYYY += 3 * 10; break;
                    case '4': tempYYYY += 4 * 10; break;
                    case '5': tempYYYY += 5 * 10; break;
                    case '6': tempYYYY += 6 * 10; break;
                    case '7': tempYYYY += 7 * 10; break;
                    case '8': tempYYYY += 8 * 10; break;
                    case '9': tempYYYY += 9 * 10; break;

                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }

                    switch (tempDate[9]) { //check YYYY (4th input)
                    case '0': tempYYYY += 0; break;
                    case '1': tempYYYY += 1; break;
                    case '2': tempYYYY += 2; break;
                    case '3': tempYYYY += 3; break;
                    case '4': tempYYYY += 4; break;
                    case '5': tempYYYY += 5; break;
                    case '6': tempYYYY += 6; break;
                    case '7': tempYYYY += 7; break;
                    case '8': tempYYYY += 8; break;
                    case '9': tempYYYY += 9; break;

                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }
                }

                if (Error == false) {
                    if (tempYYYY > 9999 || tempYYYY < 1000)
                        Error = true; outRange = true;
                    if (tempMM > 12 || tempYYYY < 1)
                        Error = true; outRange = true;
                    if (tempDD > 31 || tempDD < 1)
                        Error = true; outRange = true;

                    cout << Error << endl;
                    switch (tempMM) {
                    case 2:if (tempYYYY % 4 == 0) {//check leap year
                        if (tempDD > 29 || tempDD < 1) {
                            Error = true; outRange = true;
                            break;
                        }
                    }
                          else if (tempDD > 28 || tempDD < 1) { //normal year
                        Error = true; outRange = true;
                        break;
                    }
                    case 4:if (tempDD > 30 || tempDD < 1) {
                        Error = true; outRange = true;
                        break;
                    }
                    case 6:if (tempDD > 30 || tempDD < 1) {
                        Error = true; outRange = true;
                        break;
                    }
                    case 9:if (tempDD > 30 || tempDD < 1) {
                        Error = true; outRange = true;
                        break;
                    }
                    case 11:if (tempDD > 30 || tempDD < 1) {
                        Error = true; outRange = true;
                        break;
                    }
                    }
                }if (Error == true && ErrorTime < 3) {
                    cout << "Wrong input.";
                    if (wrongFormat == true) {
                        cout << "Please input in \"DD-MM-YYYY\" format.";
                    }
                    if (wrongDataType == true) {
                        cout << "Data type is incorrect.";
                    }
                    if (outRange == true) {
                        cout << "Input value out of range.";
                    }
                    cout << "\n\n";
                    ErrorTime++;
                }
            } while (Error == true && ErrorTime < 3);
        }

        cout << Error << endl;
        //Time


        //Event Start Time
        if (Error == false && ErrorTime < 3) {
            ErrorTime = 0;
            do {
                Error = false;
                wrongDataType = false;
                outRange = false;
                wrongFormat = false;

                cout << "\n";
                cout << "Enter event start time: ";
                cin.getline(tempST, 999999, '\n');
                if (tempST[2] != ':') {
                    Error = true; wrongFormat = true;
                }
                if (strlen(tempST) != 5) {
                    Error = true; wrongFormat = true;
                }
                else if (strlen(tempST) == 5) {

                    switch (tempST[0]) {        //check st_hh 1st input
                    case '0': tempst_hh = 0 * 10; break;
                    case '1': tempst_hh = 1 * 10; break;
                    case '2': tempst_hh = 2 * 10; break;
                    case '3': tempst_hh = 3 * 10; break;
                    case '4': tempst_hh = 4 * 10; break;
                    case '5': tempst_hh = 5 * 10; break;
                    case '6': tempst_hh = 6 * 10; break;
                    case '7': tempst_hh = 7 * 10; break;
                    case '8': tempst_hh = 8 * 10; break;
                    case '9': tempst_hh = 9 * 10; break;

                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }

                    switch (tempST[1]) {        //check st_hh 2st input
                    case '0': tempst_hh += 0; break;
                    case '1': tempst_hh += 1; break;
                    case '2': tempst_hh += 2; break;
                    case '3': tempst_hh += 3; break;
                    case '4': tempst_hh += 4; break;
                    case '5': tempst_hh += 5; break;
                    case '6': tempst_hh += 6; break;
                    case '7': tempst_hh += 7; break;
                    case '8': tempst_hh += 8; break;
                    case '9': tempst_hh += 9; break;

                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }
                    switch (tempST[3]) {        //check st_mm 1st input
                    case '0': tempst_mm = 0 * 10; break;
                    case '1': tempst_mm = 1 * 10; break;
                    case '2': tempst_mm = 2 * 10; break;
                    case '3': tempst_mm = 3 * 10; break;
                    case '4': tempst_mm = 4 * 10; break;
                    case '5': tempst_mm = 5 * 10; break;
                    case '6': tempst_mm = 6 * 10; break;
                    case '7': tempst_mm = 7 * 10; break;
                    case '8': tempst_mm = 8 * 10; break;
                    case '9': tempst_mm = 9 * 10; break;

                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }

                    switch (tempST[4]) {        //check st_mm 2st input
                    case '0': tempst_mm += 0; break;
                    case '1': tempst_mm += 1; break;
                    case '2': tempst_mm += 2; break;
                    case '3': tempst_mm += 3; break;
                    case '4': tempst_mm += 4; break;
                    case '5': tempst_mm += 5; break;
                    case '6': tempst_mm += 6; break;
                    case '7': tempst_mm += 7; break;
                    case '8': tempst_mm += 8; break;
                    case '9': tempst_mm += 9; break;

                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }

                } if (Error == false) {
                    if (tempst_hh < 0 || tempst_hh > 23 || tempst_mm < 0 || tempst_mm > 59)
                    {
                        Error = true; outRange = true;
                    }
                }
                if (Error == true && ErrorTime < 3) {
                    cout << "Wrong input.";
                    if (wrongFormat == true) {
                        cout << " Please input in \"hh-mm\" format.";
                    }
                    if (wrongDataType == true) {
                        cout << "Data type is incorrect.";
                    }
                    if (outRange == true) {
                        cout << "Input value out of range.";
                    }
                    ErrorTime++;
                    cout << "\n\n";
                }
            } while (Error == true && ErrorTime < 3);
        }

        cout << Error << endl;


        //Event End Time

        if (Error == false && ErrorTime < 3) {

            ErrorTime = 0;
            do {
                Error = false;
                wrongDataType = false;
                outRange = false;
                wrongFormat = false;

                int ErrorTimesEndTime = 0;
                cout << "\nEnter event end time: ";
                cin.getline(tempET, 999999, '\n');
                if (tempET[2] != ':') {
                    Error = true; wrongFormat = true;
                }
                if (strlen(tempET) != 5) {
                    Error = true; wrongFormat = true;
                }
                else if (strlen(tempET) == 5) {

                    switch (tempET[0]) {        //check et_hh 1st input
                    case '0': tempet_hh = 0 * 10; break;
                    case '1': tempet_hh = 1 * 10; break;
                    case '2': tempet_hh = 2 * 10; break;
                    case '3': tempet_hh = 3 * 10; break;
                    case '4': tempet_hh = 4 * 10; break;
                    case '5': tempet_hh = 5 * 10; break;
                    case '6': tempet_hh = 6 * 10; break;
                    case '7': tempet_hh = 7 * 10; break;
                    case '8': tempet_hh = 8 * 10; break;
                    case '9': tempet_hh = 9 * 10; break;

                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }

                    switch (tempET[1]) {        //check et_hh 2st input
                    case '0': tempet_hh += 0; break;
                    case '1': tempet_hh += 1; break;
                    case '2': tempet_hh += 2; break;
                    case '3': tempet_hh += 3; break;
                    case '4': tempet_hh += 4; break;
                    case '5': tempet_hh += 5; break;
                    case '6': tempet_hh += 6; break;
                    case '7': tempet_hh += 7; break;
                    case '8': tempet_hh += 8; break;
                    case '9': tempet_hh += 9; break;

                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }
                    switch (tempET[3]) {        //check et_mm 1st input
                    case '0': tempet_mm = 0 * 10; break;
                    case '1': tempet_mm = 1 * 10; break;
                    case '2': tempet_mm = 2 * 10; break;
                    case '3': tempet_mm = 3 * 10; break;
                    case '4': tempet_mm = 4 * 10; break;
                    case '5': tempet_mm = 5 * 10; break;
                    case '6': tempet_mm = 6 * 10; break;
                    case '7': tempet_mm = 7 * 10; break;
                    case '8': tempet_mm = 8 * 10; break;
                    case '9': tempet_mm = 9 * 10; break;

                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }

                    switch (tempET[4]) {        //check et_mm 2st input
                    case '0': tempet_mm += 0; break;
                    case '1': tempet_mm += 1; break;
                    case '2': tempet_mm += 2; break;
                    case '3': tempet_mm += 3; break;
                    case '4': tempet_mm += 4; break;
                    case '5': tempet_mm += 5; break;
                    case '6': tempet_mm += 6; break;
                    case '7': tempet_mm += 7; break;
                    case '8': tempet_mm += 8; break;
                    case '9': tempet_mm += 9; break;

                    default: Error = true; wrongDataType = true; break; //wrong input 
                    }

                }
                if (Error == false) {
                    if (tempet_hh < 0 || tempet_hh >23 || tempet_mm < 0 || tempet_mm > 59)
                    {
                        Error = true; outRange = true;
                    }
                }


                //checking time
                if (Error == false) {
                    if (tempet_hh < tempst_hh)
                    {
                        Error = true; wrongEndTime = true;
                    }

                    if (tempet_hh == tempst_hh)
                    {
                        if (tempet_mm <= tempst_mm)
                        {
                            Error = true; wrongEndTime = true;
                        }
                    }
                }
                if (Error == true && ErrorTime < 3) {
                    cout << "Wrong input.";
                    if (wrongFormat == true) {
                        cout << " Please input in \"hh-mm\" format.";
                    }
                    if (wrongDataType == true) {
                        cout << "Data type is incorrect.";
                    }
                    if (outRange == true) {
                        cout << "Input value out of range.";
                    }
                    if (wrongEndTime == true) {
                        cout << "\"Event End Time\" should be later than \"Event Start Time\". ";
                    }
                    ErrorTime++;
                    cout << "\n\n";
                }
            } while (Error == true && ErrorTime < 3);
        }

        cout << Error << endl;




        //Event Type
        if (Error == false && ErrorTime < 3) {
            ErrorTime = 0;
            do {
                int ErrorTimesType = 0;
                cout << "\nEnter event type: " << endl;
                cout << "(1) Home, (2) Work, (3) Study, (4) Play" << endl;
                cin.getline(tempTypeSelect, 999999, '\n');
                if (strlen(tempTypeSelect) != 1) {
                    Error = true;
                }
                else if (strlen(tempTypeSelect) == 1) {
                    switch (tempTypeSelect[0]) {// check event type
                    case '1':tempType = 1; break;
                    case '2':tempType = 2; break;
                    case '3':tempType = 3; break;
                    case '4':tempType = 4; break;

                    default: Error = true; break;//wrong input

                    }
                }
                if (Error == true && ErrorTime < 3) {
                    cout << "No such event type. Please input \'1-4\' only.";
                    ErrorTime++;
                }
            } while (Error == true && ErrorTime < 3);
        }

        cout << "Error: " << Error << endl;

        //overall checking
        if (ErrorTime == 3)
        {

            cout << "\n3 rounds invalid input occured, return to main menu." << endl << endl;
        }
        else if (Error == false) {

            //check time conflict

            int hour = 0, min = 0, counter = 0, events = 0;
            int a, b, c, d = 0;
            char op;
            bool conflict[24][60]{ false };
            int consthh[100], constmm[100], conethh[100], conetmm[100] = { 0 };
            for (int c = 0; c == record; c++)
            {
                while (tempDD == DD[c])
                {
                    events = events + 1;
                    consthh[events] = st_hh[c];
                    constmm[events] = st_mm[c];
                    conethh[events] = et_hh[c];
                    conetmm[events] = et_mm[c];
                }
            }

            for (int x = 0; x == events; x++)
            {
                hour = conethh[x] - consthh[x];
                min = conetmm[x] - constmm[x];
                counter = min + (hour * 60);
                a = consthh[x];
                b = constmm[x];
                for (int i = 1; i <= counter; i++)
                {
                    conflict[a][b] = true;
                    b = b + 1;
                    if (b > 59)
                    {
                        a = a + 1;
                        b = 0;
                    }
                }
            }

            counter = 0;
            hour = tempet_hh - tempst_hh;
            min = tempet_mm - tempst_mm;
            counter = hour * 60 + min;
            c = tempst_hh;
            d = tempst_mm;
            for (int y = 1; y == counter; y++)
            {
                if (conflict[c][d] == true)
                {
                    TimeConflict = true;
                    cout << "There already has an event,plsease try another time slot." << endl;
                }
                else d = d + 1;
                if (d > 59)
                {
                    c = c + 1;
                    d = 0;
                }
            }
            if (TimeConflict == false) {
                cout << "Your event will be input to the schedule book... " << endl;
            }


            //if input valid
            if (Error == false && TimeConflict == false) {

                title[record] = temptitle;
                DD[record] = tempDD;
                MM[record] = tempMM;
                YYYY[record] = tempYYYY;
                st_hh[record] = tempst_hh;
                st_mm[record] = tempst_mm;
                et_hh[record] = tempet_hh;
                et_mm[record] = tempet_mm;
                Type[record] = tempType;

                //total_stmin
                switch (tempMM) {                       //year                  leap year                       month                    day                    hour               minute             
                case 1:total_stmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 0 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + st_hh[record] * 60 + st_mm[record]; break;
                case 2:total_stmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 31 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + st_hh[record] * 60 + st_mm[record]; break;
                case 3:total_stmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 59 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + st_hh[record] * 60 + st_mm[record]; break;
                case 4:total_stmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 90 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + st_hh[record] * 60 + st_mm[record]; break;
                case 5:total_stmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 120 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + st_hh[record] * 60 + st_mm[record]; break;
                case 6:total_stmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 151 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + st_hh[record] * 60 + st_mm[record]; break;
                case 7:total_stmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 181 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + st_hh[record] * 60 + st_mm[record]; break;
                case 8:total_stmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 212 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + st_hh[record] * 60 + st_mm[record]; break;
                case 9:total_stmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 243 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + st_hh[record] * 60 + st_mm[record]; break;
                case 10:total_stmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 273 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + st_hh[record] * 60 + st_mm[record]; break;
                case 11:total_stmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 304 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + st_hh[record] * 60 + st_mm[record]; break;
                case 12:total_stmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 334 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + st_hh[record] * 60 + st_mm[record]; break;

                }


                if (YYYY[record] % 4 != 0) { //example: 0001,2017
                    total_stmin[record] += 60 * 24;
                }
                if (tempYYYY % 4 == 0 && tempMM > 2) {
                    total_stmin[record] += 60 * 24;
                }


                //total_etmin
                switch (tempMM) {                       //year                  leap year                  month           day                       hour             minute             
                case 1:total_etmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 0 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + et_hh[record] * 60 + et_mm[record]; break;
                case 2:total_etmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 31 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + et_hh[record] * 60 + et_mm[record]; break;
                case 3:total_etmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 59 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + et_hh[record] * 60 + et_mm[record]; break;
                case 4:total_etmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 90 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + et_hh[record] * 60 + et_mm[record]; break;
                case 5:total_etmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 120 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + et_hh[record] * 60 + et_mm[record]; break;
                case 6:total_etmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 151 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + et_hh[record] * 60 + et_mm[record]; break;
                case 7:total_etmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 181 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + et_hh[record] * 60 + et_mm[record]; break;
                case 8:total_etmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 212 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + et_hh[record] * 60 + et_mm[record]; break;
                case 9:total_etmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 243 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + et_hh[record] * 60 + et_mm[record]; break;
                case 10:total_etmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 273 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + et_hh[record] * 60 + et_mm[record]; break;
                case 11:total_etmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 304 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + et_hh[record] * 60 + et_mm[record]; break;
                case 12:total_etmin[record] = 60 * 24 * 365 * YYYY[record] + YYYY[record] / 4 * 60 * 24 + 334 * 60 * 24 + DD[record] * 60 * 24 - 60 * 24 + et_hh[record] * 60 + et_mm[record]; break;

                }

                if (YYYY[record] % 4 != 0) { //example: 0001,2017
                    total_etmin[record] += 60 * 24;
                }
                if (tempYYYY % 4 == 0 && tempMM > 2) {
                    total_etmin[record] += 60 * 24;
                }
                record++;
            }
        }

    }
    else if (record = 100) {
        cout << "Record of events is fulled, please delete some event first.";
    }
}



char choseIndex[] = ""; //for R2
void R2()
{
    int input_total_stmin, input_total_etmin;
    int ErrorTime = 0;
    bool Error = false;
    bool wrongDataType = false, outRange = false, wrongFormat = false;

    do {
        Error = false;
        wrongDataType = false;
        outRange = false;
        wrongFormat = false;

        cout << "Enter event date: ";

        cin.getline(tempDate, 999999, '\n');
        if (tempDate[2] != '-' || tempDate[5] != '-') {//check Date
            Error = true;
            wrongFormat = true;
        }
        if (strlen(tempDate) != 10) {
            Error = true;
            wrongFormat = true;
        }
        else if (strlen(tempDate) == 10) {

            //check DD
            switch (tempDate[0]) { //check DD (1st input)              
            case '0': tempDD = 0 * 10; break;
            case '1': tempDD = 1 * 10; break;
            case '2': tempDD = 2 * 10; break;
            case '3': tempDD = 3 * 10; break;
            case '4': tempDD = 4 * 10; break;
            case '5': tempDD = 5 * 10; break;
            case '6': tempDD = 6 * 10; break;
            case '7': tempDD = 7 * 10; break;
            case '8': tempDD = 8 * 10; break;
            case '9': tempDD = 9 * 10; break;
            default: Error = true; wrongDataType = true; break; //wrong input 
            }
            switch (tempDate[1]) { //check DD (2nd input)
            case '0': tempDD += 0; break;
            case '1': tempDD += 1; break;
            case '2': tempDD += 2; break;
            case '3': tempDD += 3; break;
            case '4': tempDD += 4; break;
            case '5': tempDD += 5; break;
            case '6': tempDD += 6; break;
            case '7': tempDD += 7; break;
            case '8': tempDD += 8; break;
            case '9': tempDD += 9; break;
            default: Error = true; wrongDataType = true; break; //wrong input 
            }

            //check MM
            switch (tempDate[3]) { //check MM  (1st input)            
            case '0': tempMM = 0 * 10; break;
            case '1': tempMM = 1 * 10; break;
            case '2': tempMM = 2 * 10; break;
            case '3': tempMM = 3 * 10; break;
            case '4': tempMM = 4 * 10; break;
            case '5': tempMM = 5 * 10; break;
            case '6': tempMM = 6 * 10; break;
            case '7': tempMM = 7 * 10; break;
            case '8': tempMM = 8 * 10; break;
            case '9': tempMM = 9 * 10; break;
            default: Error = true; wrongDataType = true; break; //wrong input 
            }

            switch (tempDate[4]) { //check MM (2nd input)
            case '0': tempMM += 0; break;
            case '1': tempMM += 1; break;
            case '2': tempMM += 2; break;
            case '3': tempMM += 3; break;
            case '4': tempMM += 4; break;
            case '5': tempMM += 5; break;
            case '6': tempMM += 6; break;
            case '7': tempMM += 7; break;
            case '8': tempMM += 8; break;
            case '9': tempMM += 9; break;

            default: Error = true; wrongDataType = true; break; //wrong input 
            }

            //check YYYY
            switch (tempDate[6]) { //check YYYY  (1st input)            
            case '0': tempYYYY = 0 * 1000; break;
            case '1': tempYYYY = 1 * 1000; break;
            case '2': tempYYYY = 2 * 1000; break;
            case '3': tempYYYY = 3 * 1000; break;
            case '4': tempYYYY = 4 * 1000; break;
            case '5': tempYYYY = 5 * 1000; break;
            case '6': tempYYYY = 6 * 1000; break;
            case '7': tempYYYY = 7 * 1000; break;
            case '8': tempYYYY = 8 * 1000; break;
            case '9': tempYYYY = 9 * 1000; break;

            default: Error = true; wrongDataType = true; break; //wrong input 
            }

            switch (tempDate[7]) { //check YYYY (2nd input)
            case '0': tempYYYY += 0 * 100; break;
            case '1': tempYYYY += 1 * 100; break;
            case '2': tempYYYY += 2 * 100; break;
            case '3': tempYYYY += 3 * 100; break;
            case '4': tempYYYY += 4 * 100; break;
            case '5': tempYYYY += 5 * 100; break;
            case '6': tempYYYY += 6 * 100; break;
            case '7': tempYYYY += 7 * 100; break;
            case '8': tempYYYY += 8 * 100; break;
            case '9': tempYYYY += 9 * 100; break;

            default: Error = true; wrongDataType = true; break; //wrong input 
            }

            switch (tempDate[8]) { //check YYYY  (3rd input)            
            case '0': tempYYYY += 0 * 10; break;
            case '1': tempYYYY += 1 * 10; break;
            case '2': tempYYYY += 2 * 10; break;
            case '3': tempYYYY += 3 * 10; break;
            case '4': tempYYYY += 4 * 10; break;
            case '5': tempYYYY += 5 * 10; break;
            case '6': tempYYYY += 6 * 10; break;
            case '7': tempYYYY += 7 * 10; break;
            case '8': tempYYYY += 8 * 10; break;
            case '9': tempYYYY += 9 * 10; break;

            default: Error = true; wrongDataType = true; break; //wrong input 
            }

            switch (tempDate[9]) { //check YYYY (4th input)
            case '0': tempYYYY += 0; break;
            case '1': tempYYYY += 1; break;
            case '2': tempYYYY += 2; break;
            case '3': tempYYYY += 3; break;
            case '4': tempYYYY += 4; break;
            case '5': tempYYYY += 5; break;
            case '6': tempYYYY += 6; break;
            case '7': tempYYYY += 7; break;
            case '8': tempYYYY += 8; break;
            case '9': tempYYYY += 9; break;

            default: Error = true; wrongDataType = true; break; //wrong input 
            }
        }

        if (Error == false) {
            if (tempYYYY > 9999 || tempYYYY < 1000)
                Error = true; outRange = true;
            if (tempMM > 12 || tempYYYY < 1)
                Error = true; outRange = true;
            if (tempDD > 31 || tempDD < 1)
                Error = true; outRange = true;

            cout << Error << endl;
            switch (tempMM) {
            case 2:if (tempYYYY % 4 == 0) {//check leap year
                if (tempDD > 29 || tempDD < 1) {
                    Error = true; outRange = true;
                    break;
                }
            }
                  else if (tempDD > 28 || tempDD < 1) { //normal year
                Error = true; outRange = true;
                break;
            }
            case 4:if (tempDD > 30 || tempDD < 1) {
                Error = true; outRange = true;
                break;
            }
            case 6:if (tempDD > 30 || tempDD < 1) {
                Error = true; outRange = true;
                break;
            }
            case 9:if (tempDD > 30 || tempDD < 1) {
                Error = true; outRange = true;
                break;
            }
            case 11:if (tempDD > 30 || tempDD < 1) {
                Error = true; outRange = true;
                break;
            }
            }
        }if (Error == true && ErrorTime < 3) {
            cout << "Wrong input.";
            if (wrongFormat == true) {
                cout << "Please input in \"DD-MM-YYYY\" format.";
            }
            if (wrongDataType == true) {
                cout << "Data type is incorrect.";
            }
            if (outRange == true) {
                cout << "Input value out of range.";
            }
            cout << "\n\n";
            ErrorTime++;
        }
        if (ErrorTime == 3) {

            cout << "\n3 rounds invalid input occured, return to main menu." << endl << endl;
        }
    } while (Error == true && ErrorTime < 3);


    if (Error == false) {//Date correct

        switch (tempMM) {               //year                  leap year                 month          day                                    
        case 1:input_total_stmin = 60 * 24 * 365 * tempYYYY + tempYYYY / 4 * 60 * 24 + 0 * 60 * 24 + tempDD * 60 * 24 - 60 * 24; break;
        case 2:input_total_stmin = 60 * 24 * 365 * tempYYYY + tempYYYY / 4 * 60 * 24 + 31 * 60 * 24 + tempDD * 60 * 24 - 60 * 24; break;
        case 3:input_total_stmin = 60 * 24 * 365 * tempYYYY + tempYYYY / 4 * 60 * 24 + 59 * 60 * 24 + tempDD * 60 * 24 - 60 * 24; break;
        case 4:input_total_stmin = 60 * 24 * 365 * tempYYYY + tempYYYY / 4 * 60 * 24 + 90 * 60 * 24 + tempDD * 60 * 24 - 60 * 24; break;
        case 5:input_total_stmin = 60 * 24 * 365 * tempYYYY + tempYYYY / 4 * 60 * 24 + 120 * 60 * 24 + tempDD * 60 * 24 - 60 * 24; break;
        case 6:input_total_stmin = 60 * 24 * 365 * tempYYYY + tempYYYY / 4 * 60 * 24 + 151 * 60 * 24 + tempDD * 60 * 24 - 60 * 24; break;
        case 7:input_total_stmin = 60 * 24 * 365 * tempYYYY + tempYYYY / 4 * 60 * 24 + 181 * 60 * 24 + tempDD * 60 * 24 - 60 * 24; break;
        case 8:input_total_stmin = 60 * 24 * 365 * tempYYYY + tempYYYY / 4 * 60 * 24 + 212 * 60 * 24 + tempDD * 60 * 24 - 60 * 24; break;
        case 9:input_total_stmin = 60 * 24 * 365 * tempYYYY + tempYYYY / 4 * 60 * 24 + 243 * 60 * 24 + tempDD * 60 * 24 - 60 * 24; break;
        case 10:input_total_stmin = 60 * 24 * 365 * tempYYYY + tempYYYY / 4 * 60 * 24 + 273 * 60 * 24 + tempDD * 60 * 24 - 60 * 24; break;
        case 11:input_total_stmin = 60 * 24 * 365 * tempYYYY + tempYYYY / 4 * 60 * 24 + 304 * 60 * 24 + tempDD * 60 * 24 - 60 * 24; break;
        case 12:input_total_stmin = 60 * 24 * 365 * tempYYYY + tempYYYY / 4 * 60 * 24 + 334 * 60 * 24 + tempDD * 60 * 24 - 60 * 24; break;

        }

        if (tempYYYY % 4 != 0) { //example: 0001,2017
            input_total_stmin += 60 * 24;
        }
        if (tempYYYY % 4 == 0 && tempMM > 2) {
            input_total_stmin += 60 * 24;
        }

        input_total_etmin = input_total_stmin + 60 * 24;


        int min_index;

        for (int i = 0; i < record; i++) {//sort by start time
            min_index = i;
            for (int j = i + 1; j < record; j++) {
                if (total_stmin[j] < total_stmin[min_index]) {
                    min_index = j;
                }
            }

            int tempsortStmin = total_stmin[i];
            int tempsortEtmin = total_etmin[i];
            tempDD = DD[i];
            tempMM = MM[i];
            tempYYYY = YYYY[i];
            tempst_hh = st_hh[i];
            tempst_mm = st_mm[i];
            tempet_hh = et_hh[i];
            tempet_mm = et_mm[i];
            temptitle = title[i];
            tempType = Type[i];

            total_stmin[i] = total_stmin[min_index];
            total_etmin[i] = total_etmin[min_index];
            DD[i] = DD[min_index];
            MM[i] = MM[min_index];
            YYYY[i] = YYYY[min_index];
            st_hh[i] = st_hh[min_index];
            st_mm[i] = st_mm[min_index];
            et_hh[i] = et_hh[min_index];
            et_mm[i] = et_mm[min_index];
            title[i] = title[min_index];
            Type[i] = Type[min_index];

            total_stmin[min_index] = tempsortStmin;
            total_etmin[min_index] = tempsortEtmin;
            DD[min_index] = tempDD;
            MM[min_index] = tempMM;
            YYYY[min_index] = tempYYYY;
            st_hh[min_index] = tempst_hh;
            st_mm[min_index] = tempst_mm;
            et_hh[min_index] = tempet_hh;
            et_mm[min_index] = tempet_mm;
            title[min_index] = temptitle;
            Type[min_index] = tempType;
        }
        int index = 1;
        int list[101];
        for (int i = 0; i < 101; i++) {//initialize list[]
            list[i] = 999;
        }
        cout << endl; //the events scheduled on that day  display in sorted order (from earliest to latest).
        for (int i = 0; i < record; i++) {

            if (total_stmin[i] >= input_total_stmin && total_stmin[i] <= input_total_etmin) { //check day

                cout << "[" << index << "]   " << title[i] << endl;
                list[index] = i;
                index++;
            }
        }

        //input
        cout << "Please input the number of index to choose a event to delete.\n";
        int index_input = 0;

        cin.getline(choseIndex, 999999, '\n');

        if (strlen(choseIndex) == 1) {

            switch (choseIndex[0]) {//check input
            case '1':index_input = 1; break;
            case '2':index_input = 2; break;
            case '3':index_input = 3; break;
            case '4':index_input = 4; break;
            case '5':index_input = 5; break;
            case '6':index_input = 6; break;
            case '7':index_input = 7; break;
            case '8':index_input = 8; break;
            case '9':index_input = 9; break;
            default:Error = true;    break;
            }

        }

        else if (strlen(choseIndex) == 2) {

            switch (choseIndex[0]) {//check  input

            case '1':index_input += 10; break;
            case '2':index_input += 20; break;
            case '3':index_input += 30; break;
            case '4':index_input += 40; break;
            case '5':index_input += 50; break;
            case '6':index_input += 60; break;
            case '7':index_input += 70; break;
            case '8':index_input += 80; break;
            case '9':index_input += 90; break;
            default:Error = true;      break;
            }

            switch (choseIndex[1]) {//check input
            case '0':index_input += 0; break;
            case '1':index_input += 1; break;
            case '2':index_input += 2; break;
            case '3':index_input += 3; break;
            case '4':index_input += 4; break;
            case '5':index_input += 5; break;
            case '6':index_input += 6; break;
            case '7':index_input += 7; break;
            case '8':index_input += 8; break;
            case '9':index_input += 9; break;
            default:Error = true;     break;
            }
        }
        else if (strlen(choseIndex) == 3) {

            if (choseIndex[0] == '1' && choseIndex[1] == '0' && choseIndex[2] == '0') {
                index_input = 100;
            }
            else {
                Error = true;
            }
        }


        if (Error == false) {
            int temp_DeleteSelection = list[index_input]; // get 'i' of record being delete
            index_input = temp_DeleteSelection;

            if (index_input >= record) {//check whether record exist
                Error = true;
            }
        }

        //if input valid
        if (Error == false) {

            cout << "The record of event \"" << title[index_input] << "\" has been deleted successfully.";

            record--;

            DD[index_input] = {};
            MM[index_input] = {};      // for delete current record
            YYYY[index_input] = {};
            st_hh[index_input] = {};
            st_mm[index_input] = {};
            et_hh[index_input] = {};
            et_mm[index_input] = {};
            title[index_input] = {};
            Type[index_input] = {};
            total_stmin[index_input] = {};
            total_etmin[index_input] = {};

            DD[index_input] = DD[record]; //delete specific record, replace by newest record
            MM[index_input] = MM[record];
            YYYY[index_input] = YYYY[record];
            st_hh[index_input] = st_hh[record];
            st_mm[index_input] = st_mm[record];
            et_hh[index_input] = et_hh[record];
            et_mm[index_input] = et_mm[record];
            title[index_input] = title[record];
            Type[index_input] = Type[record];
            total_stmin[index_input] = total_stmin[record];
            total_etmin[index_input] = total_etmin[record];

            DD[record] = {};    //after newest record exchange,clear the newest record
            MM[record] = {};
            YYYY[record] = {};
            st_hh[record] = {};
            st_mm[record] = {};
            et_hh[record] = {};
            et_mm[record] = {};
            title[record] = {};
            Type[record] = {};
            total_stmin[record] = {};
            total_etmin[record] = {};

        }
        else if (Error == true) {
            cout << "No such event, deletion unsuccess.";
        }
    }
}


void R3()
{
    if (record < 100) { //record = 0 - 99 (at most 100 record)
        string date, time, etime, title, type;
        string tempevent;
        string tempstringDD, tempstringMM, tempstringYYYY;
        int countevent = 0, countallevent = 0, conflictevent;

        getline(cin, date, '/');
        getline(cin, time, '/');
        getline(cin, etime, '/');
        getline(cin, title, '/');
        getline(cin, type);
        tempevent = date + "/" + time + "/" + etime + "/" + title + "/" + type;
        while (tempevent != "0") {

        }



        if (type == "1") {
            type = "Home";
            cout << tempevent;
            countallevent++;
            countevent++;
        }
        else if (type == "2") {
            type = "Work";
            cout << tempevent;
            countallevent++;
            countevent++;
        }
        else if (type == "3") {
            type = "Study";
            cout << tempevent;
            countallevent++;
            countevent++;
        }
        else if (type == "4") {
            type = "Play";
            cout << tempevent;
            countallevent++;
            countevent++;
        }
        else { countallevent++; }
    }

    //split string to int
   /* tempstringDD = date.substr(0, 2);
    tempDD = stoi(tempstringDD);
    tempstringMM = date.substr(3, 2);
    tempMM = stoi(tempstringMM);
    tempstringYYYY = date.substr(6, 4);
    tempYYYY = stoi(tempstringYYYY);

    conflictevent = countallevent - countevent;*/

   /* cout << "Total " << countallevent << " events in batch" << endl;
    cout << countevent << " event(s) added" << endl;
    cout << conflictevent << " event(s) not added due to time conflict" << endl;



}
else if (record = 100) {
cout << "Record of events is fulled, please delete some event first.";
  }*/
}



//R4

char R4option_choice[] = ""; //for R4
char eventType[] = "", n[] = ""; //n is coming n day
void R41()
{
    int min_index;   //sort

    for (int i = 0; i < record; i++) {//sort by start time
        min_index = i;
        for (int j = i + 1; j < record; j++) {
            if (total_stmin[j] < total_stmin[min_index]) {
                min_index = j;
            }
        }

        int tempsortStmin = total_stmin[i];
        int tempsortEtmin = total_etmin[i];
        tempDD = DD[i];
        tempMM = MM[i];
        tempYYYY = YYYY[i];
        tempst_hh = st_hh[i];
        tempst_mm = st_mm[i];
        tempet_hh = et_hh[i];
        tempet_mm = et_mm[i];
        temptitle = title[i];
        tempType = Type[i];

        total_stmin[i] = total_stmin[min_index];
        total_etmin[i] = total_etmin[min_index];
        DD[i] = DD[min_index];
        MM[i] = MM[min_index];
        YYYY[i] = YYYY[min_index];
        st_hh[i] = st_hh[min_index];
        st_mm[i] = st_mm[min_index];
        et_hh[i] = et_hh[min_index];
        et_mm[i] = et_mm[min_index];
        title[i] = title[min_index];
        Type[i] = Type[min_index];

        total_stmin[min_index] = tempsortStmin;
        total_etmin[min_index] = tempsortEtmin;
        DD[min_index] = tempDD;
        MM[min_index] = tempMM;
        YYYY[min_index] = tempYYYY;
        st_hh[min_index] = tempst_hh;
        st_mm[min_index] = tempst_mm;
        et_hh[min_index] = tempet_hh;
        et_mm[min_index] = tempet_mm;
        title[min_index] = temptitle;
        Type[min_index] = tempType;
    }

    cout << endl << left << setw(25) << "Date and Time" << setw(45) << "Title" << setw(5) << "Type" << endl; //the events  display in sorted order (from earliest to latest).
    for (int i = 0; i < record; i++) {

        //Date and Time   
        //             DD-MM-YYYY,hh:mm-hh:mm
        if (DD[i] < 10) { cout << "0"; }  //eg DD = 9 , cout                
        cout << DD[i] << "-";
        if (MM[i] < 10) { cout << "0"; }    //eg MM = 6 , cout 06
        cout << MM[i] << "-";

        if (YYYY[i] < 10) { cout << "000"; }       //eg   0003
        else if (YYYY[i] < 100) { cout << "00"; }  //eg   0096
        else if (YYYY[i] < 1000) { cout << "0"; }  //eg   0128
        cout << YYYY[i] << ",";

        if (st_hh[i] < 10) { cout << "0"; }    //eg  03:06
        cout << st_hh[i] << ":";

        if (st_mm[i] < 10) { cout << "0"; }
        cout << st_mm[i] << "-";

        if (et_hh[i] < 10) { cout << "0"; }    //eg  05:04
        cout << et_hh[i] << ":";

        if (et_mm[i] < 10) { cout << "0"; }
        cout << et_mm[i] << "   ";


        //Title and Type 
        //                     Title      Type
        cout << left << setw(45) << title[i] << Type[i] << endl;
    }
    cout << endl << endl;
}

void R42()
{
    double currentTime;

    bool Error = false;

    int min_index;   //sort

    for (int i = 0; i < record; i++) {//sort by start time
        min_index = i;
        for (int j = i + 1; j < record; j++) {
            if (total_stmin[j] < total_stmin[min_index]) {
                min_index = j;
            }
        }

        int tempsortStmin = total_stmin[i];
        int tempsortEtmin = total_etmin[i];
        tempDD = DD[i];
        tempMM = MM[i];
        tempYYYY = YYYY[i];
        tempst_hh = st_hh[i];
        tempst_mm = st_mm[i];
        tempet_hh = et_hh[i];
        tempet_mm = et_mm[i];
        temptitle = title[i];
        tempType = Type[i];

        total_stmin[i] = total_stmin[min_index];
        total_etmin[i] = total_etmin[min_index];
        DD[i] = DD[min_index];
        MM[i] = MM[min_index];
        YYYY[i] = YYYY[min_index];
        st_hh[i] = st_hh[min_index];
        st_mm[i] = st_mm[min_index];
        et_hh[i] = et_hh[min_index];
        et_mm[i] = et_mm[min_index];
        title[i] = title[min_index];
        Type[i] = Type[min_index];

        total_stmin[min_index] = tempsortStmin;
        total_etmin[min_index] = tempsortEtmin;
        DD[min_index] = tempDD;
        MM[min_index] = tempMM;
        YYYY[min_index] = tempYYYY;
        st_hh[min_index] = tempst_hh;
        st_mm[min_index] = tempst_mm;
        et_hh[min_index] = tempet_hh;
        et_mm[min_index] = tempet_mm;
        title[min_index] = temptitle;
        Type[min_index] = tempType;
    }

    //input
    int choseType = 0, chose_n = 0;

    cout << "Please input a event type(1-4).\n";
    cin.getline(eventType, 999999);
    if (strlen(eventType) != 1) {
        Error = true;
    }
    else if (strlen(eventType) == 1) {    // check event type
        switch (eventType[0]) {
        case '1': choseType = 1; break;
        case '2': choseType = 2; break;
        case '3': choseType = 3; break;
        case '4': choseType = 4; break;
        default: Error = true; break;      //wrong input 
        }
    }
    if (Error == true) {
        cout << "No such event type, please input \'1-4\' only.\n";
    }


    if (Error == false) {
        cout << "Please input the value of \'n\'(1-7) which \'n\' is coming \'n\' day.\n";
        cin.getline(n, 999999, '\n');
        //                                            change second to minute
        currentTime = 1970 * 60 * 24 * 365 + 1970 / 4 * 60 * 24 + 60 * 24 + time(0) / 60.0;  //current time in minutes form
        int currentDay = currentTime / (60 * 24);    //measure : day

        int currentDayMin = currentDay * 60 * 24;      //measure : minute

        if (strlen(n) != 1) {
            Error = true;
        }
        else if (strlen(n) == 1) {

            switch (n[0]) {                //check n
            case '1': chose_n = 1; break;
            case '2': chose_n = 2; break;
            case '3': chose_n = 3; break;
            case '4': chose_n = 4; break;
            case '5': chose_n = 5; break;
            case '6': chose_n = 6; break;
            case '7': chose_n = 7; break;
            default: Error = true; break;      //wrong input 
            }
        }
        if (Error == true) {
            cout << "Wrong input. please input \'1-7\' only.\n";
        }

        //if both inputs are correct
        if (Error == false) { //show event

            int n_dayAfter = currentDayMin + 60 * 24 + chose_n * 60 * 24;


            cout << endl << left << setw(25) << "Date and Time" << setw(45) << "Title" << setw(5) << "Type" << endl; //the events  display in sorted order (from earliest to latest).
            for (int i = 0; i < record; i++) {

                //          choose specific type                   check start time within today-nDay                                  check end time within today-nDay
                if (Type[i] == choseType && total_stmin[i] >= currentDayMin && total_stmin[i] <= n_dayAfter && total_etmin[i] >= currentDayMin && total_etmin[i] <= n_dayAfter) {
                    //Date and Time   
                    //             DD-MM-YYYY,hh:mm-hh:mm
                    if (DD[i] < 10) { cout << "0"; }  //eg DD = 9 , cout                
                    cout << DD[i] << "-";
                    if (MM[i] < 10) { cout << "0"; }    //eg MM = 6 , cout 06
                    cout << MM[i] << "-";

                    if (YYYY[i] < 10) { cout << "000"; }       //eg   0003
                    else if (YYYY[i] < 100) { cout << "00"; }  //eg   0096
                    else if (YYYY[i] < 1000) { cout << "0"; }  //eg   0128
                    cout << YYYY[i] << ",";

                    if (st_hh[i] < 10) { cout << "0"; }    //eg  03:06
                    cout << st_hh[i] << ":";

                    if (st_mm[i] < 10) { cout << "0"; }
                    cout << st_mm[i] << "-";

                    if (et_hh[i] < 10) { cout << "0"; }    //eg  05:04
                    cout << et_hh[i] << ":";

                    if (et_mm[i] < 10) { cout << "0"; }
                    cout << et_mm[i] << "   ";


                    //Title and Type 
                    //                     Title      Type
                    cout << left << setw(45) << title[i] << Type[i] << endl;
                }
            }

        }
    }

    cout << endl << endl;
}

//R4.3

int mod(int integer, int modnum) {
    int mod;
    if (integer % modnum < 0)
        mod = integer;
    else
        mod = integer % modnum;
    return mod;
}

int CenturyCode(int year) {
    int ccode;
    ccode = 2 * (3 - mod((year / 100), 4));
    return ccode;
}

int YearCode(int year, int month) {
    int ycode;
    ycode = year % 100;
    ycode = mod(ycode, 28) + mod(ycode, 28) / 4;
    ycode = mod(ycode, 7);
    if (year % 4 == 0 && year % 100 != 0 && (month == 1 || month == 2)) {
        ycode--;
    }
    return ycode;
}

int MonthCode(int month) {//M¡G((3.4+(m-3)mod12¡Ñ2.6)mod7¡]1¡B2¤ë¥÷M-1¡^
    double mcode;
    if (month == 1)      //-2mod12=10
        mcode = 29.4;      //(3.4+(m-3)mod12¡Ñ2.6)mod7
    else if (month == 2)
        mcode = 4;
    else {
        mcode = mod(month - 3, 12); //(m-3)mod12
        mcode = 3.4 + mcode * 2.6;  //(3.4+(m-3)mod12¡Ñ2.6)
        mcode = mod(mcode, 7);      //(3.4+(m-3)mod12¡Ñ2.6)mod7
    }
    if (month == 1 || month == 2)
    {
        mcode--;
    }
    return mcode;
}

int DayCode(int day) {
    int dcode;
    dcode = mod(day, 7);
    return dcode;
}

int CalDate(int day, int month, int year) {
    int weekday;
    weekday = CenturyCode(year) + YearCode(year, month) + MonthCode(month) + DayCode(day);
    weekday = mod(weekday, 7);
    return weekday;
}

void R43()
{
    int month, year;
    char op8;
    cout << "Please input month and year (MM-YYYY):\n";
    cin >> month >> op8 >> year;
    cout << setw(45) << "Sun" << setw(45) << "Mon" << setw(45) << "Tue" << setw(45) << "Wed" << setw(45) << "Thu" << setw(45) << "Fri" << setw(45) << "Sat";




    int count;
    for (int i = 0; i < record;i++) {
        if (MM[i] == month && YYYY[i] == year) {
            cout << setw(45) << st_hh[i] << ":" << st_mm[i] << "-" << et_hh[i] << ":" << et_mm << endl;
            cout << setw(45) << title[i] << endl;

        }
    }
}




















void R4()
{
    // Insert your codes for R4 here
    bool Loop = true;

    do {

        cout << "***** Show Event Menu *****" << endl;
        cout << "[1] Show all events" << endl;
        cout << "[2] Show events (list view)" << endl;
        cout << "[3] Show events (calendar view)" << endl;
        cout << "[4] Return to Main Menu" << endl;
        cout << "***************************" << endl;
        cout << "Option (1 - 4): ";
        cin.getline(R4option_choice, 999999, '\n');
        cout << "\n\n";

        if (strlen(R4option_choice) == 1) {

            switch (R4option_choice[0]) {  //input digit = 1

            case '1': Loop = true; R41(); break;
            case '2': Loop = true; R42(); break;
            case '3': Loop = true; R43(); break;
            case '4': Loop = false; break;         //menu
            default:        //wrong input 
                cout << "No such option,please enter \'1-4\' only.\n " << endl;
                Loop = true;
                break;
            }

        }
        else {        //input digit > 1
            cout << "No such option,please enter \'1-4\' only.\n " << endl;
            Loop = true;
        }
    } while (Loop == true);


}




void R5()
{
    // Insert your codes for R5 here
  // student name, ID , class ,tutor GP

    cout << "Li Yiu       19022970A 204C\n";
    cout << "Lau Ying Pan 19018156A 204A\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
}

void R6()
{
    bool Error;

    do {

        cout << "Are you sure to exit this program?" << endl;
        cin.getline(Exit_selection, 999999, '\n');

        cout << endl;
        if (strlen(Exit_selection) == 1) {  //if input digit = 1
            switch (Exit_selection[0]) {
            case 'Y':Error = false; break;
            case 'y':Error = false; break;
            case 'N':Error = false; break;
            case 'n':Error = false; break;
            default:Error = true;       //wrong input
                cout << "Wrong input,please input again.\n(Please input \'Y\' or \'y\' to exit this program,or input \'N\' or \'n\' to go back to menu only.)\n\n";
                break;
            }
        }
        else  //input digit > 1 , wrong
        {
            cout << "Wrong input,please input again.\n(Please input \'Y\' or \'y\' to exit this program,or input \'N\' or \'n\' to go back to menu only.)\n\n";
            Error = true;
        }

    } while (Error == true);

}



int main() {



    cout << "\nWelcome to Schedule Book program";

    char option_choice[] = "";

    do {
        cout << "\n\n";
        cout << "*** Main Menu ***" << endl;
        cout << "[1] Add one event" << endl;
        cout << "[2] Delete one event" << endl;
        cout << "[3] Add events in batch" << endl;
        cout << "[4] Show events" << endl;
        cout << "[5] Credits" << endl;
        cout << "[6] Exit" << endl;
        cout << "*****************" << endl;
        cout << "Option (1 - 6): ";
        cin.getline(option_choice, 999999, '\n');
        cout << "\n\n";

        if (strlen(option_choice) == 1) { //input digit=1

            switch (option_choice[0]) {

            case '1': R1(); break;
            case '2': R2(); break;
            case '3': R3(); break;
            case '4': R4(); break;
            case '5': R5(); break;
            case '6': R6(); break;
            default:              //wrong input
                cout << "No such option,please enter \'1-6\' only. " << endl;
                break;
            }

        }
        else {         //input digit > 1
            cout << "No such option,please enter \'1-6\' only. " << endl;
        }

    } while (Exit_selection[0] != 'Y' && Exit_selection[0] != 'y');

    cout << "Program terminates. Good bye!" << endl;
    return 0;
}
//END