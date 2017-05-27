/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package syntaxnazinew;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

/**
 *
 * @author Asus-PC
 */
public class Umacob4 {
    public static ArrayList <String> dType, returnType;
    public static File file = new File("umacob4.out");
    public static int varDecStates[][];
    public static int funcDecStates[][];
    public static int funcDefStates[][];
    
    Umacob4(){
        varDecStates = new int[26][21];
        funcDecStates = new int[15][21];
        funcDefStates = new int[100][21];
        dType = new ArrayList<String>();
        returnType = new ArrayList<String>();
        initdType();
        initreturnType();
        initVarDecStates();
        initFuncDecStates();
        initFuncDefStates();
    }
    public void initdType(){
        dType.add("char"); dType.add("int"); dType.add("float"); dType.add("double"); dType.add("long");
    }
    public void initreturnType(){
        returnType.add("char"); returnType.add("int"); returnType.add("float"); returnType.add("double"); returnType.add("long"); returnType.add("void");
    }
    public void initVarDecStates(){
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 21; j++){
                varDecStates[i][j] = 0; //set to the dead state
            }
        }
        varDecStates[1][0] = 2;
        varDecStates[2][1] = 3;
        varDecStates[2][12] = 21;
        varDecStates[3][8] = 4;
        varDecStates[3][2] = 7;
        varDecStates[3][3] = 8;
        varDecStates[3][7] = 16;
        varDecStates[4][6] = 5;
        varDecStates[4][9] = 6;
        varDecStates[5][9] = 6;
        varDecStates[6][2] = 7;
        varDecStates[6][3] = 9;
        varDecStates[6][7] = 16;
        varDecStates[7][1] = 3;
        varDecStates[7][12] = 21;
        varDecStates[8][1] = 17;
        varDecStates[8][6] = 17;
        varDecStates[8][16] = 18;
        varDecStates[9][4] = 10;
        varDecStates[10][6] = 11;
        varDecStates[10][1] = 11;
        varDecStates[10][16] = 12;
        varDecStates[10][5] = 15;
        varDecStates[11][2] = 10;
        varDecStates[11][5] = 15;
        varDecStates[12][1] = 13;
        varDecStates[12][3] = 13;
        varDecStates[12][4] = 13;
        varDecStates[12][5] = 13;
        varDecStates[12][6] = 13;
        varDecStates[12][7] = 13;
        varDecStates[12][8] = 13;
        varDecStates[12][9] = 13;
        varDecStates[12][10] = 13;
        varDecStates[12][11] = 13;
        varDecStates[12][12] = 13;
        varDecStates[12][13] = 13;
        varDecStates[12][14] = 13;
        varDecStates[12][15] = 13;
        varDecStates[12][16] = 14;
        varDecStates[13][1] = 13;
        varDecStates[13][3] = 13;
        varDecStates[13][4] = 13;
        varDecStates[13][5] = 13;
        varDecStates[13][6] = 13;
        varDecStates[13][7] = 13;
        varDecStates[13][8] = 13;
        varDecStates[13][9] = 13;
        varDecStates[13][10] = 13;
        varDecStates[13][11] = 13;
        varDecStates[13][12] = 13;
        varDecStates[13][13] = 13;
        varDecStates[13][14] = 13;
        varDecStates[13][15] = 13;
        varDecStates[13][16] = 14;
        varDecStates[14][2] = 10;
        varDecStates[14][5] = 15;
        varDecStates[15][7] = 16;
        varDecStates[16][7] = 16;
        varDecStates[16][0] = 2;
        varDecStates[17][1] = 7;
        varDecStates[17][7] = 16;
        varDecStates[18][1] = 19;
        varDecStates[18][3] = 19;
        varDecStates[18][4] = 19;
        varDecStates[18][5] = 19;
        varDecStates[18][6] = 19;
        varDecStates[18][7] = 19;
        varDecStates[18][8] = 19;
        varDecStates[18][9] = 19;
        varDecStates[18][10] = 19;
        varDecStates[18][11] = 19;
        varDecStates[18][12] = 19;
        varDecStates[18][13] = 19;
        varDecStates[18][14] = 19;
        varDecStates[18][15] = 19;
        varDecStates[19][1] = 19;
        varDecStates[19][3] = 19;
        varDecStates[19][4] = 19;
        varDecStates[19][5] = 19;
        varDecStates[19][6] = 19;
        varDecStates[19][7] = 19;
        varDecStates[19][8] = 19;
        varDecStates[19][9] = 19;
        varDecStates[19][10] = 19;
        varDecStates[19][11] = 19;
        varDecStates[19][12] = 19;
        varDecStates[19][13] = 19;
        varDecStates[19][14] = 19;
        varDecStates[19][15] = 19;
        varDecStates[19][16] = 20;
        varDecStates[20][2] = 7;
        varDecStates[20][7] = 16;
        varDecStates[21][1] = 22;
        varDecStates[22][7] = 16;
        varDecStates[22][3] = 23;
        varDecStates[22][2] = 7;
        varDecStates[23][18] = 24;
        varDecStates[24][1] = 25;
        varDecStates[25][7] = 16;
        varDecStates[25][2] = 7;
        
    }
    public void initFuncDecStates(){
        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 21; j++){
                funcDecStates[i][j] = 0; //set to the dead state
            }
        }
        funcDecStates[1][19] = 2;
        funcDecStates[2][1] = 3;
        funcDecStates[3][10] = 4;
        funcDecStates[4][0] = 5;
        funcDecStates[4][11] = 11;
        funcDecStates[5][1] = 10;
        funcDecStates[5][8] = 6;
        funcDecStates[5][2] = 9;
        funcDecStates[5][11] = 11;
        funcDecStates[5][12] = 13;
        funcDecStates[6][6] = 7;
        funcDecStates[6][9] = 8;
        funcDecStates[7][9] = 8;
        funcDecStates[8][2] = 9;
        funcDecStates[8][11] = 11;
        funcDecStates[9][0] = 5;
        funcDecStates[10][8] = 6;
        funcDecStates[10][11] = 11;
        funcDecStates[10][2] = 9;
        funcDecStates[11][7] = 12;
        funcDecStates[12][7] = 12;
        funcDecStates[12][19] = 2;
        funcDecStates[13][2] = 9;
        funcDecStates[13][1] = 14;
        funcDecStates[13][11] = 11;
        funcDecStates[14][2] = 9;
        funcDecStates[14][11] = 11;
    }
    public void initFuncDefStates(){
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 21; j++){
                funcDefStates[i][j] = 0; //set to the dead state
            }
        }
        funcDefStates[1][0] = 2;
        funcDefStates[1][19] = 2;
        funcDefStates[2][1] = 3;
        funcDefStates[3][10] = 4;
        funcDefStates[4][0] = 5;
        funcDefStates[4][11] = 11;
        funcDefStates[5][1] = 10;
        funcDefStates[5][8] = 6;
        //funcDefStates[5][2] = 9;
        //funcDefStates[5][11] = 11;
        funcDefStates[5][12] = 86;
        funcDefStates[6][6] = 7;
        funcDefStates[6][9] = 8;
        funcDefStates[7][9] = 8;
        funcDefStates[8][2] = 9;
        funcDefStates[8][11] = 11;
        funcDefStates[9][0] = 5;
        funcDefStates[10][8] = 6;
        funcDefStates[10][11] = 11;
        funcDefStates[10][2] = 9;
        funcDefStates[11][4] = 12;
        // funcDefStates[12][0] = 62; //Connection to VarDec
        funcDefStates[12][0] = 62;
        funcDefStates[12][19] = 62;
        funcDefStates[86][2] = 9;
        funcDefStates[86][1] = 87;
        funcDefStates[86][11] = 11;
        funcDefStates[87][2] = 9;
        funcDefStates[87][11] = 11;
        funcDefStates[12][17] = 13;
        funcDefStates[13][15] = 29;
        funcDefStates[13][14] = 28;
        funcDefStates[13][1] = 15;
        funcDefStates[13][6] = 23;
        funcDefStates[14][1] = 15;
        funcDefStates[14][6] = 23;
        funcDefStates[15][14] = 16;
        funcDefStates[15][15] = 17;
        funcDefStates[15][12] = 18;
        funcDefStates[15][13] = 19;
        funcDefStates[15][7] = 20;
        funcDefStates[16][6] = 23;
        funcDefStates[16][14] = 21;
        funcDefStates[16][1] = 15;
        funcDefStates[17][1] = 15;
        funcDefStates[17][6] = 23;
        funcDefStates[17][15] = 20;
        funcDefStates[18][1] = 15;
        funcDefStates[18][6] = 23;
        funcDefStates[19][1] = 15;
        funcDefStates[19][6] = 23;
        funcDefStates[20][17] = 13;
        funcDefStates[20][7] = 20;
        funcDefStates[20][15] = 40;
        funcDefStates[20][0] = 62;
        funcDefStates[20][1] = 32;
        funcDefStates[20][5] = 98;
        funcDefStates[20][14] = 42;
        funcDefStates[21][7] = 20;
        funcDefStates[22][7] = 20;
        funcDefStates[23][14] = 28;
        funcDefStates[23][13] = 24;
        funcDefStates[23][12] = 25;
        funcDefStates[23][15] = 26;
        funcDefStates[23][14] = 27;
        funcDefStates[24][1] = 15;
        funcDefStates[24][6] = 23;
        funcDefStates[25][1] = 15;
        funcDefStates[25][6] = 23;
        funcDefStates[26][1] = 15;
        funcDefStates[26][6] = 23;
        funcDefStates[27][1] = 15;
        funcDefStates[27][6] = 23;
        funcDefStates[28][14] = 30;
        funcDefStates[29][15] = 31;
        funcDefStates[30][1] = 15;
        funcDefStates[31][1] = 15;
        funcDefStates[15][3] = 14;
        funcDefStates[16][3] = 14;
        funcDefStates[17][3] = 14;
        funcDefStates[18][3] = 14;
        funcDefStates[19][3] = 14;
        funcDefStates[24][3] = 14;
        funcDefStates[25][3] = 14;
        funcDefStates[26][3] = 14;
        funcDefStates[27][3] = 14;
        funcDefStates[12][15] = 40;
        funcDefStates[12][14] = 42;
        funcDefStates[12][1] = 32;
        funcDefStates[12][12] = 36;
        funcDefStates[32][14] = 33;
        funcDefStates[32][15] = 34;
        funcDefStates[32][13] = 35;
        funcDefStates[32][12] = 35;
        funcDefStates[32][3] = 39;
        funcDefStates[33][14] = 38;
        funcDefStates[33][15] = 37;
        funcDefStates[33][3] = 39;
        funcDefStates[34][14] = 37;
        funcDefStates[34][15] = 38;
        funcDefStates[34][3] = 39;
        funcDefStates[35][3] = 39;
        funcDefStates[36][1] = 32;
        funcDefStates[37][1] = 48;
        funcDefStates[38][1] = 48;
        funcDefStates[38][7] = 20;
        funcDefStates[39][15] = 40;
        funcDefStates[39][14] = 42;
        funcDefStates[39][18] = 44;
        funcDefStates[39][12] = 44;
        funcDefStates[39][1] = 48;
        funcDefStates[39][6] = 45;
        funcDefStates[40][15] = 41;
        funcDefStates[40][1] = 48;
        funcDefStates[40][14] = 43;
        funcDefStates[40][6] = 45;
        funcDefStates[41][1] = 48;
        funcDefStates[42][6] = 45;
        funcDefStates[42][15] = 41;
        funcDefStates[42][14] = 43;
        funcDefStates[42][1] = 48;
        funcDefStates[43][1] = 48;
        funcDefStates[44][1] = 48;
        funcDefStates[45][7] = 20;
        funcDefStates[45][14] = 46;
        funcDefStates[45][15] = 46;
        funcDefStates[45][12] = 46;
        funcDefStates[45][13] = 46;
        funcDefStates[46][6] = 45;
        funcDefStates[46][1] = 48;
        funcDefStates[46][14] = 47;
        funcDefStates[46][15] = 47;
        funcDefStates[47][6] = 45;
        funcDefStates[47][1] = 48;
        funcDefStates[47][2] = 39;
        funcDefStates[48][2] = 39;
        funcDefStates[48][7] = 20;
        funcDefStates[48][15] = 50;
        funcDefStates[48][14] = 51;
        funcDefStates[48][12] = 49;
        funcDefStates[48][13] = 49;
        funcDefStates[49][6] = 45;
        funcDefStates[49][3] = 39;
        funcDefStates[49][14] = 51;
        funcDefStates[49][15] = 50;
        funcDefStates[49][1] = 48;
        funcDefStates[50][1] = 48;
        funcDefStates[50][3] = 39;
        funcDefStates[50][6] = 45;
        funcDefStates[50][14] = 54;
        funcDefStates[50][15] = 52;
        funcDefStates[52][1] = 48;
        funcDefStates[52][7] = 20;
        funcDefStates[52][6] = 45;
        funcDefStates[52][2] = 39;
        funcDefStates[52][12] = 39;
        funcDefStates[52][13] = 39;
        funcDefStates[52][14] = 39;
        funcDefStates[52][15] = 39;
        funcDefStates[51][1] = 48;
        funcDefStates[51][15] = 54;
        funcDefStates[51][14] = 53;
        funcDefStates[51][3] = 39;
        funcDefStates[53][12] = 39;
        funcDefStates[53][13] = 39;
        funcDefStates[53][14] = 39;
        funcDefStates[53][15] = 39;
        funcDefStates[53][2] = 39;
        funcDefStates[53][1] = 48;
        funcDefStates[53][7] = 20;
        funcDefStates[53][6] = 45;
        funcDefStates[54][1] = 48;
        funcDefStates[48][10] = 55;
        funcDefStates[55][6] = 57;
        funcDefStates[55][1] = 57;
        funcDefStates[55][16] = 59;
        funcDefStates[59][1] = 60;
        funcDefStates[59][3] = 60;
        funcDefStates[59][4] = 60;
        funcDefStates[59][5] = 60;
        funcDefStates[59][6] = 60;
        funcDefStates[59][7] = 60;
        funcDefStates[59][8] = 60;
        funcDefStates[59][9] = 60;
        funcDefStates[59][10] = 60;
        funcDefStates[59][11] = 60;
        funcDefStates[59][12] = 60;
        funcDefStates[59][13] = 60;
        funcDefStates[59][14] = 60;
        funcDefStates[59][15] = 60;
        funcDefStates[59][20] = 60;
        funcDefStates[59][16] = 57;
        funcDefStates[60][16] = 57;
        funcDefStates[56][1] = 57;
        funcDefStates[57][2] = 55;
        funcDefStates[57][11] = 58;
        funcDefStates[58][12] = 39;
        funcDefStates[58][13] = 39;
        funcDefStates[58][14] = 39;
        funcDefStates[58][15] = 39;
        funcDefStates[58][7] = 20;
        funcDefStates[32][8] = 88;
        funcDefStates[88][6] = 91;
        funcDefStates[88][1] = 91;
        funcDefStates[88][16] = 89;
        funcDefStates[89][16] = 91;
        funcDefStates[89][1] = 90;
        funcDefStates[89][3] = 90;
        funcDefStates[89][4] = 90;
        funcDefStates[89][5] = 90;
        funcDefStates[89][6] = 90;
        funcDefStates[89][7] = 90;
        funcDefStates[89][8] = 90;
        funcDefStates[89][9] = 90;
        funcDefStates[89][10] = 90;
        funcDefStates[89][11] = 90;
        funcDefStates[89][12] = 90;
        funcDefStates[89][13] = 90;
        funcDefStates[89][14] = 90;
        funcDefStates[89][15] = 90;
        funcDefStates[89][20] = 90;
        funcDefStates[90][16] = 91;
        funcDefStates[91][9] = 92;
        funcDefStates[92][7] = 20;
        funcDefStates[92][3] = 39;
        funcDefStates[39][1] = 48;
        funcDefStates[48][8] = 93;
        funcDefStates[93][16] = 94;
        funcDefStates[94][1] = 95;
        funcDefStates[94][3] = 95;
        funcDefStates[94][4] = 95;
        funcDefStates[94][5] = 95;
        funcDefStates[94][6] = 95;
        funcDefStates[94][7] = 95;
        funcDefStates[94][8] = 95;
        funcDefStates[94][9] = 95;
        funcDefStates[94][10] = 95;
        funcDefStates[94][11] = 95;
        funcDefStates[94][12] = 95;
        funcDefStates[94][13] = 95;
        funcDefStates[94][14] = 95;
        funcDefStates[94][15] = 95;
        funcDefStates[94][20] = 95;
        funcDefStates[95][16] = 96;
        funcDefStates[93][6] = 96;
        funcDefStates[93][1] = 96;
        funcDefStates[96][9] = 97;
        funcDefStates[97][12] = 39;
        funcDefStates[97][13] = 39;
        funcDefStates[97][14] = 39;
        funcDefStates[97][15] = 39;
        funcDefStates[97][7] = 20;
        funcDefStates[97][2] = 39;
        funcDefStates[12][5] = 98;
        funcDefStates[20][5] = 98;
        funcDefStates[61][0] = 62;
        funcDefStates[62][1] = 63;
        // funcDefStates[62][1] = 32;
        funcDefStates[62][12] = 81;
        funcDefStates[63][8] = 64;
        funcDefStates[63][2] = 67;
        // funcDefStates[63][3] = 68;
        funcDefStates[63][3] = 39;
        // funcDefStates[63][7] = 76;
         funcDefStates[63][7] = 20;
        funcDefStates[64][6] = 65;
        funcDefStates[64][9] = 66;
        funcDefStates[65][9] = 66;
        funcDefStates[66][2] = 67;
        funcDefStates[66][3] = 69;
        funcDefStates[66][7] = 20;
        funcDefStates[67][1] = 63;
        funcDefStates[67][12] = 81;
        funcDefStates[68][1] = 77;
        funcDefStates[68][6] = 77;
        funcDefStates[68][16] = 78;
        funcDefStates[69][4] = 70;
        funcDefStates[70][6] = 71;
        funcDefStates[70][1] = 71;
        funcDefStates[70][16] = 72;
        funcDefStates[70][5] = 75;
        funcDefStates[71][2] = 70;
        funcDefStates[71][5] = 75;
        funcDefStates[72][1] = 73;
        funcDefStates[72][3] = 73;
        funcDefStates[72][4] = 73;
        funcDefStates[72][5] = 73;
        funcDefStates[72][6] = 73;
        funcDefStates[72][7] = 73;
        funcDefStates[72][8] = 73;
        funcDefStates[72][9] = 73;
        funcDefStates[72][10] = 73;
        funcDefStates[72][11] = 73;
        funcDefStates[72][12] = 73;
        funcDefStates[72][13] = 73;
        funcDefStates[72][14] = 73;
        funcDefStates[72][15] = 73;
        funcDefStates[72][16] = 74;
        funcDefStates[73][1] = 73;
        funcDefStates[73][3] = 73;
        funcDefStates[73][4] = 73;
        funcDefStates[73][5] = 73;
        funcDefStates[73][6] = 73;
        funcDefStates[73][7] = 73;
        funcDefStates[73][8] = 73;
        funcDefStates[73][9] = 73;
        funcDefStates[73][10] = 73;
        funcDefStates[73][11] = 73;
        funcDefStates[73][12] = 73;
        funcDefStates[73][13] = 73;
        funcDefStates[73][14] = 73;
        funcDefStates[73][15] = 73;
        funcDefStates[73][16] = 74;
        funcDefStates[74][2] = 70;
        funcDefStates[74][5] = 75;
        funcDefStates[75][7] = 20;
        funcDefStates[76][7] = 20;
        funcDefStates[76][0] = 62;
        funcDefStates[77][1] = 67;
        funcDefStates[77][7] = 20;
        funcDefStates[78][1] = 79;
        funcDefStates[78][3] = 79;
        funcDefStates[78][4] = 79;
        funcDefStates[78][5] = 79;
        funcDefStates[78][6] = 79;
        funcDefStates[78][7] = 79;
        funcDefStates[78][8] = 79;
        funcDefStates[78][9] = 79;
        funcDefStates[78][10] = 79;
        funcDefStates[78][11] = 79;
        funcDefStates[78][12] = 79;
        funcDefStates[78][13] = 79;
        funcDefStates[78][14] = 79;
        funcDefStates[78][15] = 79;
        funcDefStates[79][1] = 79;
        funcDefStates[79][3] = 79;
        funcDefStates[79][4] = 79;
        funcDefStates[79][5] = 79;
        funcDefStates[79][6] = 79;
        funcDefStates[79][7] = 79;
        funcDefStates[79][8] = 79;
        funcDefStates[79][9] = 79;
        funcDefStates[79][10] = 79;
        funcDefStates[79][11] = 79;
        funcDefStates[79][12] = 79;
        funcDefStates[79][13] = 79;
        funcDefStates[79][14] = 79;
        funcDefStates[79][15] = 79;
        funcDefStates[79][16] = 80;
        funcDefStates[80][2] = 67;
        funcDefStates[80][7] = 20;
        funcDefStates[81][1] = 82;
        funcDefStates[82][7] = 20;
        funcDefStates[82][3] = 83;
        funcDefStates[82][2] = 67;
        funcDefStates[83][18] = 84;
        funcDefStates[84][1] = 85;
        funcDefStates[85][7] = 20;
        funcDefStates[85][2] = 67;
        funcDefStates[12][7] = 20;
        funcDefStates[98][19] = 2;
        funcDefStates[45][2] = 99;
        funcDefStates[99][1] = 32;
        funcDefStates[98][0] = 2;
        funcDefStates[99][6] = 39;
        funcDefStates[41][6] = 45;
        funcDefStates[43][6] = 45;
        funcDefStates[76][1] = 45;
        funcDefStates[55][18] = 56;
    }
    public ArrayList<String>Tokenizer(String str){
        ArrayList<String> token = new ArrayList<String>();
        String temp = "";
        Character ch;
        Boolean whiteSpace = true;
        String symbols = " ;=(){}[],*/+-&'";
        int ctr = 0;
        for(int i = 0; i < str.length(); i++){
            if(symbols.indexOf(str.charAt(i)) < 0){
                    temp+=str.charAt(i);
                    whiteSpace = false;
            }
            if(symbols.indexOf(str.charAt(i)) >= 0|| str.length() == i+1){
                if(whiteSpace == false){
                    token.add(temp);
                    temp = "";
                    whiteSpace = true;
                }
            }
            if(symbols.indexOf(str.charAt(i)) > 0){
                ch = str.charAt(i);
                token.add(ch.toString());
            }
        }
        return token;
    }
    public int inputTokenizer(String s){
        if(dType.contains(s)){
            return 0;
        } else if(returnType.contains(s)){
            return 19;
        } else if(s.charAt(0) >= 'A' && s.charAt(0) <= 'Z' || s.charAt(0) >= 'a' && s.charAt(0) <= 'z' || s.charAt(0) == '_'){
            return 1;
        } else if(s.equals(",")){
            return 2;
        } else if(s.equals("=")){
            return 3;
        } else if(s.equals("{")){
            return 4;
        } else if(s.equals("}")){
            return 5;
        } else if(isNumber(s)){
            return 6;
        } else if(s.equals(";")){
            return 7;
        } else if(s.equals("[")){
            return 8;
        } else if(s.equals("]")){
            return 9;
        } else if(s.equals("(")){
            return 10;
        } else if(s.equals(")")){
            return 11;
        } else if(s.equals("*")){
            return 12;
        } else if(s.equals("/")){
            return 13;
        } else if(s.equals("+")){
            return 14;
        } else if(s.equals("-")){
            return 15;
        } else if(s.equals("'")){
            return 16;
        } else if(s.equals("return")){
            return 17;
        } else if(s.equals("&")){
            return 18;
        } else{
            return 20;
        }
    }
    public boolean isNumber(String s){
        int dot  = 0;
        for(int i = 0; i < s.length(); i++){
            if(!(s.charAt(i) >= '0' && s.charAt(i) <= '9')){
                return false;
            }
            if(s.charAt(i) == '.'){
                dot++;
            }
            if(dot >= 2){
                return false;
            }
        }
        return true;
    }
    public String isValidVarDec(ArrayList<String> a){
        Umacob4 nazi = new Umacob4();
        int state = 1;
        for(int i = 0; i < a.size(); i++){
            System.out.println(state + " , " + "\"" +a.get(i)+"\" "+"[" + inputTokenizer(a.get(i))+"]" + " --> " + varDecStates[state][nazi.inputTokenizer(a.get(i))]);
            state = varDecStates[state][nazi.inputTokenizer(a.get(i))];
        }
        if(state == 16){
            return "yes";
        } else{
            return "no";
        }
    }
    public String isValidFuncDec(ArrayList<String> a){
        Umacob4 nazi = new Umacob4();
        int state = 1;
        for(int i = 0; i < a.size(); i++){
            //System.out.println(state + " , " + "\"" +a.get(i)+"\" "+"[" + inputTokenizer(a.get(i))+"]" + " --> " + funcDecStates[state][nazi.inputTokenizer(a.get(i))]);
            state = funcDecStates[state][nazi.inputTokenizer(a.get(i))];
        }
        if(state == 12){
            return "yes";
        } else{
            return "no";
        }
    }
    public String isValidFuncDef(ArrayList<String> a){
        Umacob4 nazi = new Umacob4();
        int state = 1;
        for(int i = 0; i < a.size(); i++){
            System.out.println(state + " , " + "\"" +a.get(i)+"\" "+"[" + inputTokenizer(a.get(i))+"]" + " --> " + funcDefStates[state][nazi.inputTokenizer(a.get(i))]);
            state = funcDefStates[state][nazi.inputTokenizer(a.get(i))];
        }
        if(state == 98){
            return "yes";
        } else{
            return "no";
        }
    }
    public static void FileWriter(String s){
    	PrintWriter out = null;
        try 
        {
            out = new PrintWriter(new BufferedWriter(new FileWriter(file, true)));
            out.println(s);
        }
        catch (IOException e) 
        {
            System.err.println(e);
        }
        finally
        {
            if(out != null)
            {
                out.close();
            }
        } 
    }
    public static void main(String[] args) {
        Umacob4 nazi = new Umacob4();
        File f = new File("mpa4.in");
        int testCaseType;
        String testCase;
        try{
            BufferedReader br = new BufferedReader(new FileReader(f));
         	String line;
         	int testCaseNum = new Integer(br.readLine());
         	for(int i = 0; i < testCaseNum; i++){
         		testCaseType = new Integer(br.readLine());
         		line = br.readLine();
	         	ArrayList<String> token = nazi.Tokenizer(line);
	         	System.out.println(token);
	         	if(testCaseType == 1){
	         		FileWriter(nazi.isValidVarDec(token));
	         	}
	         	else if(testCaseType == 2){
	         		FileWriter(nazi.isValidFuncDec(token));
	         	}
	         	else if(testCaseType == 3){
	         		FileWriter(nazi.isValidFuncDef(nazi.Tokenizer(line)));
	         	}
         	}
         	
      		
      	}catch(Exception e){
         	e.printStackTrace();
      	}
//        System.out.println("Final: " + nazi.isValidVarDec(nazi.Tokenizer("int x = a + a;")));
//        System.out.println("Final: " + nazi.isValidFuncDec(nazi.Tokenizer("void func(int x[], char h, long *b);")));
//        System.out.println("Final: " + nazi.isValidFuncDef(nazi.Tokenizer("void function(int ) {int x = a * a; return x;} int square(int b}{return b*b;}")));
    }
    
}
