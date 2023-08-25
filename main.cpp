#include <stdio.h>

#include "io.h"
#include "solve.h"
#include "tests.h"
#include "struct.h"
                                    //maketutorial -
/**
    \authors Ludmila Stemp
    \date 24.08.2023
*/

int main()
{
#ifdef DEBUG
    Test();
#else
    Coeffs coeffs = { .a = 0, .b = 0, .c = 0 };
    Roots roots = { .x1 = 0, .x2 = 0, .rootsCount = ROOTS_ZERO };
    {
    printf("                _                         \n");
    printf("                \\`*-.                    \n");
    printf("                 )  _`-.                  \n");
    printf("                .  : `. .                 \n");
    printf("               :  _   '  \\               \n");
    printf("               ;  *` _.   `*-._           \n");
    printf("                `-.-'          `-.        \n");
    printf("                  ;       `       `.      \n");
    printf("                  :.       .        \\    \n");
    printf("                  . \\  .   :   .-'   .   \n");
    printf("                  '  `+.;  ;  '      :    \n");
    printf("                  :  '  |    ;       ;-.  \n");
    printf("                  ; '   : :`-:     _.`* ; \n");
    printf("               .*' /  .*' ; .*`- +'  `*'  \n");
    printf("               `*-*   `*-*  `*-*'         \n");
    }
    /*
    {
    printf("        SSSS                                    \n");
    printf("       SSSS                                     \n");
    printf("      S___SS                 SSSSS              \n");
    printf("    SSSS____SS_SSSSSSS    SSS____S              \n");
    printf("   SS___________SSSSSSSSS____S__S               \n");
    printf("   S________________________SS_S                \n");
    printf("   SS__________________________S                \n");
    printf("   SS_________________________SS                \n");
    printf("   SSS________________________S                 \n");
    printf("  SS__________________________S                 \n");
    printf(" SS__________________________SS                 \n");
    printf(" S________SSS________________SS                 \n");
    printf("SS_______S__SS_______SSS_____S                  \n");
    printf("SS_______SSSSS______SS__S____SS                 \n");
    printf("SS__________________SSSSS____SS                 \n");
    printf("SS____SSS____SSS______SSS_____SS                \n");
    printf(" SS_____SSSSS_S__SS_SSSSSSS___S                 \n");
    printf("  SS_SS____SSS_SSS_SSS______SS                  \n");
    printf("   SS__SSSSS______SSSSSS_____S                  \n");
    printf("    SS_____SSSSSSS____SSS__SS                   \n");
    printf("   SS_____SSSSS____________SSS                  \n");
    printf("  SS________________________SSS                 \n");
    printf("  S___________________________SSS               \n");
    printf(" S_____________________________SSS              \n");
    printf("S_______________________________SSS       S     \n");
    printf("S_________________________________SSS   SS_S    \n");
    printf("S___________________________________SS SS__S    \n");
    printf("S____________________________________SSSS__S    \n");
    printf("SS___________________________________SSS___S    \n");
    printf(" SSS_____________S________S___________SS___S    \n");
    printf("  SS____________S_________S____________S___S    \n");
    printf("  SS____S____SSS__________S________________S    \n");
    printf("   SS____S___SS___________S_____________S__S    \n");
    printf("   S____SSS___S__________S_____________S__S     \n");
    printf("    SS______SS__S________S______________SSS     \n");
    printf("     S________SSS_______S________________SS     \n");
    printf("      S_________SS___SSSS_________S______SS     \n");
    printf("       S__________S___S_________SSS______SS     \n");
    printf("       S_______________S______SS_________S      \n");
    printf("       SS______________S___SSS__________S       \n");
    printf("        S___S__________S__S___________SS        \n");
    printf("        SS__S__________SSS_S_________SS         \n");
    printf("        SS___S________SS_SSS_S__S_S_SS          \n");
    printf("        S____SS_S_S_SS    SSSSSSSSSS            \n");
    printf("        S_____SSSSSSS                           \n");
    printf("        S______SS                               \n");
    printf("        SS_S_S_SS                               \n");
    printf("        SSSSSSSS                                \n");
    }
     */
    //попытка полторашки
    /*
    {
    printf(";;;;;;;;;;;;;;;;;;;;rrrr;;;;;;;;;;;;;;;;:::::::::S&95S522Xs,,,,,,,,,,,,,,,,,,::riii525SSSSSiiiiisrS9iXS23Srir;\n");
    printf(";;;;;;;;;;;;;;;;;;;;;;r;;;;;;;;;;;;;;;;::::;;:;::;hGh55SSS39r,,,,,,,,,,,,,,,:::riiiS25SSSSSiii;i22SSii5X25Ssr;\n");
    printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;::::;;;::::Sh5srssSX3&h;::,,,,,,,,,,,,::;iiS525SSSSSirXX5isssSS3h95isr;\n");
    printf(";;;;;;;;;;;rrrrrrrrrrrrrr;;;;;;;;;;;;;::::::::::::;3393SSi53hh&3Xi:::,,,,,,,:::riiS525SSSSiG2SSsr2S,i5G9XSisrr\n");
    printf("rrrrrssssssssssssssssssssssrrrrrrrr;;;;::::::::::,,5995SsiXX99A&XAAGXXXhh9922XXX993522h9sh&hi2s;:..;;S22SSirrr\n");
    printf("rsssrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr;;:::::::,,;h2srr;rs23&BG9G9325i2&3X3h3XX23Xh&33GHH93XsrSiiX9X22iSSsss\n");
    printf("rrrrrrrrrrrrrrrrrrrrrrrrrrr;;;;;;;;;;;;rrrrrr;;;::::S339X33XX3hG3233X25rirSh9999G&hAhAABMM&92S5539232X5iS5Sisr\n");
    printf("ssssssiiiiiiiiissssssssrrrrr;;;;;;;;;;;;;;;;;r;;;;;:r5S2iS5S5S52h3322hiiir939222&AAA&3HHhHG&A2S55X3X9XsiS5issr\n");
    printf("iSSSSSSSSSSSSSSSSSSiiiiiissssrrr;;;;;;;;;;;:;;;;;;;rs5X5SSssS59X939532sS;S39Xh33AAAGhBhAGXG&99HG329X3XssiSSsss\n");
    printf("555522222222222222555555SSSSSiiissrr;;;;;;;;;;:;;;;;r222252X2292X92XSS5:29XX93A&3XhX&29GG9hX32XhhAAh25iii5Sssr\n");
    printf("2XX33339999999999333XXXX222555SSSiisssrrr;;;;;;::::;i322XX333X292i32sS,.3&33i9&3X2i92rX5hhG&G3293G9hiSiiSSSSss\n");
    printf("hGGGGGGh933XXXXX2XX3339hh9933XX255SSSSiissrrr;;;;;;;iX5523hXX2X5sii5;s:.SGA5&hAhh2S9S33i93XGGSB3&A&2ASiiS5Siii\n");
    printf("G9X25Sisrrr;;;;;;:::;;rriS52X9h993X2255SSiiissrrr;;riS23GGX222Srri5i:.,.2Ah23hH2&ABss5s,9SS2532929&B5SiiS5SSSi\n");
    printf("rr;::::::::,,:,,,,,,,,,,,,,,:;rsS23993X225SSSiiissrs222XhG2S2522sihir. :.&9GGh3&GBh,i;SS;SS3XS3SX5X&2SSS5255Si\n");
    printf(":::::,,,,,,,,,,,,,,,,,..,,,,,,,,,,:ri5X99X255SSSiii5XX3&AABB@#M@@@5S;, .5AAA#HBAh9XB@@M#h&95X25X232XXSSS5225S5\n");
    printf("::::,,,,,,,,,,,,.,,,,,...,,,,:::::,::;;ri5X93225Sii293h3XXXiXBA@#@AHi:,.9hGhAM52@MM@@@AA&S2593h9932395SS5222SS\n");
    printf(":::::;;:,,,:,::::::::,:::;;;rrrrrrrrrr;;::;i5X3X5s532X522Xhh2SAB@39&B:..3XB9H9rM#H9@@9XB;:2S552hh9XXX2552325SS\n");
    printf("AHHHHHHHBBHHHHHHAHAAAAAAAHAAH&AAAh993X3s;::::riS25siS2222XhG&hA3hBBMH..,;3G&G3SB@G5iSHi:Sh5s2539Gh3X3922X325S5\n");
    printf("A&B&HHA&GAHBBHHBHHHAA&ABBHAHHBBBBBHh9X3&G2;::;;rSXXSi5XS5i22G9S5Si:S3,,..&h3X&AH2r,:59352iS293h93h99hhXX39X2SS\n");
    printf("93AB&B&GAAA&HBBBHA&AHAHBBMMBHABB#MM&h9h&A&G2si59999XS222iS5S5Ss;.    ,  .,X339MGSs,si2XG99S55hh93X29&G3399X25S\n");
    printf("XGh&HHHA&A9&hh&AABHHGGAA&&MMMBBBBM#MHGhGAG&&G9GMHGGh993GG32is::     .:.,.,,;;99GX2S,i535SiiShh3X5i5Xh9XX9hX25S\n");
    printf("9939h&BHHH#&h9GhABB&B&GAABBBMMMMBBB#MAhhGA&GG&&HB&h&hh9G932ir:..     :ss,:,;r;.r;:  ,srsi59HAhX222AAG333993X5S\n");
    printf("&GG999GBMBAHGXGh9AHHHMBXhhHMMMMBMMHBMMA&G&GAhAAAMBHGGGh2iiir:.  .. : ,hhhhisiS ..  .:si2X2X5h3XXS53X3X33hG322S\n");
    printf("HA&XG9hBMMHh&&9GAhHHHHB&999AHMMBHBBBB#HAGGh&&hAHMAH9Xh9hX3Xs.i,, .;:i;5&G&Gh ..  ...,rrSsssi;rSXhh333X33hG3X25\n");
    printf("HHB2hh9&HBBBBGhGAA&AHh&AHGGh&AMMHBBBBMMB&hGGG&&BX@MHXS2232:Sr,:,:,.;s;r:A#M:::,, ..:,:Sis;;;rrs;rrs5X99hGG3X55\n");
    printf("HAh9G3GG&AMBBAAhh&GAGGAGBHGAHAABHHAHBMBMH&hhGAhBAh@#H2iss,i;. :rr;:::;;s52s;:,;:::;:irSis:::;;;,:;S3h9hG&&3X25\n");
    printf("B&B&&GhGA9&HBHHH&&&GH&GA&BHhHMMBBBMHHHBHHAGhhX5GAHA@@&5r;:r,..:riissSXXXhG9GGh3XiSS5rSir;:::.,:;rSh9G59G&&3X2S\n");
    printf("BMHG&G&A&A&GAHAGH2h3G&AGGHAHMM#BBBBMHAABBM&Gh&G&XB9@BBBhi;,,:;,,:;r;::::r;srs2s;ri5SSis:,,.,:;rs2h&2&A&GGG9X22\n");
    printf("9HMGHHA&&G&GBB&AH&&9HAGAA&GABMBMMHMHBAABMBH9AGiMi&H#M&@&X;,,,.,....:rrrrr;sssiis53332Ssr:;riiiS2h&AHHAhG&G3XXX\n");
    printf("AGhGHH&&&AhAGhG&HHG&HA&&BHBHMMMHHA&AHBBHBBAHHHAA&h3M@@MMhh;:,.,. . ..:sSissii5X2Sir:,.:s5S255529&AAHHHA&&G3XX2\n");
    printf("Gh&hhGG&h33ShXG9&3HAAXhBM&HMMMBMBHHAHB#BHMM#MsB&&XG@&@@HMB3hX;,. ... .. ,:;:::::::,. ...:;52223G&GGGAAAAAG3X22\n");
    printf("&995&&9&X3Xh99X25&HAAABB#MHM#MBHMBMHBBM#MM#GHHBhAAGh@#@@M&#BBM39S3sr;.       ,.....,,.,,,::s2XG&&Gh99h&AAG3X22\n");
    printf("A&3&G92Gh99A99G3X9AhA&BHh&BHA&MBHHM#HM#MB#MHMM#9&BG@@@@@##@@BH&9HGhh22:;,       ..,.,..,,:::i2h&&h3X223GA&3X25\n");
    printf("A3G9G9XXG&9h223G2h9A9&hA32&GG#@BHMMBHMBMHHBBBhMHG3A#@@#@BMBMB#HMB&MB&&Xr,..   ..,,,, ,,,::::rShh93X555529G3XX2\n");
    }*/


    printf("Please enter the meowfficients:\n");
    while (true)
    {
        ScanReturn scanStatus = ScanCoeff(&coeffs);
        if (scanStatus == SCAN_TERMINATE)
        {
            return 0;
        }
        if (scanStatus == SCAN_CORRECT)
        {
            break;
        }
    }

    SolveQuadraticEquation(&coeffs, &roots);

    PrintRoots(&roots);

#endif
    return 0;
}
