#ifndef Z_OUTPUT_MAIN_H
#define Z_OUTPUT_MAIN_H
/*
***** ALL RESULTS ARE VERIFIED ******
*
**
***
****
>_!batch_file.batch_old.batch
[0] Table employee created!


SQL: DONE.


[1] insert into employee values Blow, 		Joe, 			CS,	100000, 	2018
SQL::run: inserted


SQL: DONE.


[2] insert into employee values Blow, 		JoAnn,			Physics, 	200000, 	2016
SQL::run: inserted


SQL: DONE.


[3] insert into employee values Johnson, 	Jack, 			HR, 	150000, 	2014
SQL::run: inserted


SQL: DONE.


[4] insert into employee values Johnson, 	"Jimmy", 		Chemistry,	140000, 	2018
SQL::run: inserted


SQL: DONE.


[5] insert into employee values Yao,	 	Jimmy, 			Math,	145000, 	2014
SQL::run: inserted


SQL: DONE.


[6] insert into employee values "Yao", 		Flo, 			CS,	147000, 	2012
SQL::run: inserted


SQL: DONE.


[7] insert into employee values Yang, 		Bo, 			CS,	160000, 	2013
SQL::run: inserted


SQL: DONE.


[8] insert into employee values Jackson,	"Flo", 			Math,	165000, 	2017
SQL::run: inserted


SQL: DONE.


[9] insert into employee values Jackson,	Bo,	 			Chemistry,	130000, 	2011
SQL::run: inserted


SQL: DONE.


[10] insert into employee values "Jackson",	Billy, 			Math,	170000, 	2017
SQL::run: inserted


SQL: DONE.


[11] insert into employee values Johnson,	"Mary Ann", 	Math,		165000, 	2014
SQL::run: inserted


SQL: DONE.


[12] insert into employee values Johnson,	"Billy Bob", 	Physics,	142000, 	2014
SQL::run: inserted


SQL: DONE.


[13] insert into employee values "Van Gogh",	Vincent, 		Art,	240000, 	2015
SQL::run: inserted


SQL: DONE.


[14] insert into employee values "Van Gogh",	Vincent, 		CS,	240000, 	2015
SQL::run: inserted


SQL: DONE.


[15] select * from employee where salary > 150000
================
       Record #           last          first            dep         salary           year
              0           Yang             Bo             CS         160000           2013
              1        Jackson            Flo           Math         165000           2017
              2        Johnson       Mary Ann           Math         165000           2014
              3        Jackson          Billy           Math         170000           2017
              4           Blow          JoAnn        Physics         200000           2016
              5       Van Gogh        Vincent            Art         240000           2015
              6       Van Gogh        Vincent             CS         240000           2015
================


SQL: DONE.


[16] select * from employee
================
       Record #           last          first            dep         salary           year
              0           Blow            Joe             CS         100000           2018
              1           Blow          JoAnn        Physics         200000           2016
              2        Johnson           Jack             HR         150000           2014
              3        Johnson          Jimmy      Chemistry         140000           2018
              4            Yao          Jimmy           Math         145000           2014
              5            Yao            Flo             CS         147000           2012
              6           Yang             Bo             CS         160000           2013
              7        Jackson            Flo           Math         165000           2017
              8        Jackson             Bo      Chemistry         130000           2011
              9        Jackson          Billy           Math         170000           2017
             10        Johnson       Mary Ann           Math         165000           2014
             11        Johnson      Billy Bob        Physics         142000           2014
             12       Van Gogh        Vincent            Art         240000           2015
             13       Van Gogh        Vincent             CS         240000           2015
================


SQL: DONE.


[17] select first, last, dep, year, salary from employee
================
       Record #          first           last            dep           year         salary
              0            Joe           Blow             CS           2018         100000
              1          JoAnn           Blow        Physics           2016         200000
              2           Jack        Johnson             HR           2014         150000
              3          Jimmy        Johnson      Chemistry           2018         140000
              4          Jimmy            Yao           Math           2014         145000
              5            Flo            Yao             CS           2012         147000
              6             Bo           Yang             CS           2013         160000
              7            Flo        Jackson           Math           2017         165000
              8             Bo        Jackson      Chemistry           2011         130000
              9          Billy        Jackson           Math           2017         170000
             10       Mary Ann        Johnson           Math           2014         165000
             11      Billy Bob        Johnson        Physics           2014         142000
             12        Vincent       Van Gogh            Art           2015         240000
             13        Vincent       Van Gogh             CS           2015         240000
================


SQL: DONE.


[18] select first, last, year, salary from employee where dep > CS or year = 2015
================
       Record #          first           last           year         salary
              0          Billy        Jackson           2017         170000
              1      Billy Bob        Johnson           2014         142000
              2             Bo        Jackson           2011         130000
              3            Flo        Jackson           2017         165000
              4           Jack        Johnson           2014         150000
              5          Jimmy        Johnson           2018         140000
              6          Jimmy            Yao           2014         145000
              7          JoAnn           Blow           2016         200000
              8       Mary Ann        Johnson           2014         165000
              9        Vincent       Van Gogh           2015         240000
             10        Vincent       Van Gogh           2015         240000
================


SQL: DONE.


[19] select * from employee
================
       Record #          first           last           year         salary
              0           Blow            Joe             CS         100000
              1           Blow          JoAnn        Physics         200000
              2        Johnson           Jack             HR         150000
              3        Johnson          Jimmy      Chemistry         140000
              4            Yao          Jimmy           Math         145000
              5            Yao            Flo             CS         147000
              6           Yang             Bo             CS         160000
              7        Jackson            Flo           Math         165000
              8        Jackson             Bo      Chemistry         130000
              9        Jackson          Billy           Math         170000
             10        Johnson       Mary Ann           Math         165000
             11        Johnson      Billy Bob        Physics         142000
             12       Van Gogh        Vincent            Art         240000
             13       Van Gogh        Vincent             CS         240000
================


SQL: DONE.


[20] Table student created!


SQL: DONE.


[21] insert into student values Flo, 			Yao, 		CS, 	20
SQL::run: inserted


SQL: DONE.


[22] insert into student values Bo, 				Yang, 		CS, 		28
SQL::run: inserted


SQL: DONE.


[23] insert into student values "Sammuel L.", 	Jackson, 	CS, 		40
SQL::run: inserted


SQL: DONE.


[24] insert into student values "Flo", 			"Jackson", 	Math,	21
SQL::run: inserted


SQL: DONE.


[25] insert into student values "Greg", 			"Pearson", 	Physics,	20
SQL::run: inserted


SQL: DONE.


[26] insert into student values "Jim Bob", 		Smith, 		Math,	23
SQL::run: inserted


SQL: DONE.


[27] insert into student values Calvin, 			Woo, 		Physics,	22
SQL::run: inserted


SQL: DONE.


[28] insert into student values "Ali Reza", 		Yang, 		CS,	22
SQL::run: inserted


SQL: DONE.


[29] insert into student values "Teresa Mae", 	Gowers, 	Chemistry,	22
SQL::run: inserted


SQL: DONE.


[30] insert into student values Alex,			Smith,		"Gender Studies", 53
SQL::run: inserted


SQL: DONE.


[31] select * from student
================
       Record #          fname          lname          major            age
              0            Flo            Yao             CS             20
              1             Bo           Yang             CS             28
              2     Sammuel L.        Jackson             CS             40
              3            Flo        Jackson           Math             21
              4           Greg        Pearson        Physics             20
              5        Jim Bob          Smith           Math             23
              6         Calvin            Woo        Physics             22
              7       Ali Reza           Yang             CS             22
              8     Teresa Mae         Gowers      Chemistry             22
              9           Alex          Smith Gender Studies             53
================


SQL: DONE.


<= operator found
[32] select * from student where age <= 23 and name = "Jim Bob"
================
       Record #          fname          lname          major            age
              0        Jim Bob          Smith           Math             23
================


SQL: DONE.


[33] select fname, major, age from student
================
       Record #          fname          major            age
              0            Flo             CS             20
              1             Bo             CS             28
              2     Sammuel L.             CS             40
              3            Flo           Math             21
              4           Greg        Physics             20
              5        Jim Bob           Math             23
              6         Calvin        Physics             22
              7       Ali Reza             CS             22
              8     Teresa Mae      Chemistry             22
              9           Alex Gender Studies             53
================


SQL: DONE.


[34] select first, last, year, salary from employee where dep < CS or year >= 2015
================
       Record #          first           last           year         salary
              0          Billy        Jackson           2017         170000
              1            Flo        Jackson           2017         165000
              2          Jimmy        Johnson           2018         140000
              3          JoAnn           Blow           2016         200000
              4            Joe           Blow           2018         100000
              5        Vincent       Van Gogh           2015         240000
              6        Vincent       Van Gogh           2015         240000
================


SQL: DONE.





*/
#endif // Z_OUTPUT_MAIN_H
