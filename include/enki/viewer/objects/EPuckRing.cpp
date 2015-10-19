
/*
    Enki - a fast 2D robot simulator
    Copyright (C) 1999-2013 Stephane Magnenat <stephane at magnenat dot net>
    Copyright (C) 2004-2005 Markus Waibel <markus dot waibel at epfl dot ch>
    Copyright (c) 2004-2005 Antoine Beyeler <abeyeler at ab-ware dot com>
    Copyright (C) 2005-2006 Laboratory of Intelligent Systems, EPFL, Lausanne
    Copyright (C) 2006 Laboratory of Robotics Systems, EPFL, Lausanne
    See AUTHORS for details

    This program is free software; the authors of any publication 
    arising from research using this software are asked to add the 
    following reference:
    Enki - a fast 2D robot simulator
    http://home.gna.org/enki
    Stephane Magnenat <stephane at magnenat dot net>,
    Markus Waibel <markus dot waibel at epfl dot ch>
    Laboratory of Intelligent Systems, EPFL, Lausanne.

    You can redistribute this program and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

// E-puck object file

#include <QtOpenGL>
#define BYTE unsigned char

namespace Enki
{
	// 168 Verticies
	// 151 Texture Coordinates
	// 217 Normals
	// 336 Triangles
	
	static BYTE face_indicies[336][9] = {
	// (unnamed)
		{48,0,23 ,0,1,2 ,0,1,2 }, {48,49,0 ,0,3,1 ,0,3,1 }, {47,49,48 ,4,3,0 ,4,3,0 },
		{47,24,49 ,4,5,3 ,4,5,3 }, {49,1,0 ,3,6,1 ,3,6,1 }, {49,50,1 ,3,7,6 ,3,7,6 },
		{24,50,49 ,5,7,3 ,5,7,3 }, {24,25,50 ,5,8,7 ,5,8,7 }, {50,2,1 ,7,9,6 ,7,9,6 },
		{50,51,2 ,7,10,9 ,7,10,9 }, {25,51,50 ,8,10,7 ,8,10,7 }, {25,26,51 ,8,11,10 ,8,11,10 },
		{51,3,2 ,10,12,9 ,10,12,9 }, {51,52,3 ,10,13,12 ,10,13,12 },
		{26,52,51 ,11,13,10 ,11,13,10 }, {26,27,52 ,11,14,13 ,11,14,13 },
		{52,4,3 ,13,15,12 ,13,15,12 }, {52,53,4 ,13,16,15 ,13,16,15 },
		{27,53,52 ,14,16,13 ,14,16,13 }, {27,28,53 ,14,17,16 ,14,17,16 },
		{53,5,4 ,16,18,15 ,16,18,15 }, {53,54,5 ,16,19,18 ,16,19,18 },
		{28,54,53 ,17,19,16 ,17,19,16 }, {28,29,54 ,17,20,19 ,17,20,19 },
		{54,6,5 ,19,21,18 ,19,21,18 }, {54,55,6 ,19,22,21 ,19,22,21 },
		{29,55,54 ,20,22,19 ,20,22,19 }, {29,30,55 ,20,23,22 ,20,23,22 },
		{55,7,6 ,22,24,21 ,22,24,21 }, {55,56,7 ,22,25,24 ,22,25,24 },
		{30,56,55 ,23,25,22 ,23,25,22 }, {30,31,56 ,23,26,25 ,23,26,25 },
		{56,8,7 ,25,27,24 ,25,27,24 }, {56,57,8 ,25,28,27 ,25,28,27 },
		{31,57,56 ,26,28,25 ,26,28,25 }, {31,32,57 ,26,29,28 ,26,29,28 },
		{57,9,8 ,28,30,27 ,28,30,27 }, {57,58,9 ,28,31,30 ,28,31,30 },
		{32,58,57 ,29,31,28 ,29,31,28 }, {32,33,58 ,29,32,31 ,29,32,31 },
		{58,10,9 ,31,33,30 ,31,33,30 }, {58,59,10 ,31,34,33 ,31,34,33 },
		{33,59,58 ,32,34,31 ,32,34,31 }, {33,34,59 ,32,35,34 ,32,35,34 },
		{59,11,10 ,34,36,33 ,34,36,33 }, {59,60,11 ,34,37,36 ,34,37,36 },
		{34,60,59 ,35,37,34 ,35,37,34 }, {34,35,60 ,35,38,37 ,35,38,37 },
		{60,12,11 ,37,39,36 ,37,39,36 }, {60,61,12 ,37,40,39 ,37,40,39 },
		{35,61,60 ,38,40,37 ,38,40,37 }, {35,36,61 ,38,41,40 ,38,41,40 },
		{61,13,12 ,40,42,39 ,42,43,44 }, {61,62,13 ,40,43,42 ,42,45,43 },
		{36,62,61 ,41,43,40 ,46,45,42 }, {36,37,62 ,41,44,43 ,46,47,45 },
		{62,14,13 ,43,45,42 ,45,48,43 }, {62,63,14 ,43,46,45 ,45,49,48 },
		{37,63,62 ,44,46,43 ,47,49,45 }, {37,38,63 ,44,47,46 ,47,50,49 },
		{63,15,14 ,46,48,45 ,49,51,48 }, {63,64,15 ,46,49,48 ,49,52,51 },
		{38,64,63 ,47,49,46 ,50,52,49 }, {38,39,64 ,47,50,49 ,50,53,52 },
		{64,16,15 ,49,51,48 ,52,54,51 }, {64,65,16 ,49,52,51 ,52,55,54 },
		{39,65,64 ,50,52,49 ,53,55,52 }, {39,40,65 ,50,53,52 ,53,56,55 },
		{65,17,16 ,52,54,51 ,55,57,54 }, {65,66,17 ,52,55,54 ,55,58,57 },
		{40,66,65 ,53,55,52 ,56,58,55 }, {40,41,66 ,53,56,55 ,56,59,58 },
		{66,18,17 ,55,57,54 ,58,60,57 }, {66,67,18 ,55,58,57 ,58,61,60 },
		{41,67,66 ,56,58,55 ,59,61,58 }, {41,42,67 ,56,59,58 ,59,62,61 },
		{67,19,18 ,58,60,57 ,61,63,60 }, {67,68,19 ,58,61,60 ,61,64,63 },
		{42,68,67 ,59,61,58 ,62,64,61 }, {42,43,68 ,59,62,61 ,62,65,64 },
		{68,20,19 ,61,63,60 ,64,66,63 }, {68,69,20 ,61,64,63 ,64,67,66 },
		{43,69,68 ,62,64,61 ,65,67,64 }, {43,44,69 ,62,65,64 ,65,68,67 },
		{69,21,20 ,64,66,63 ,67,69,66 }, {69,70,21 ,64,67,66 ,67,70,69 },
		{44,70,69 ,65,67,64 ,68,70,67 }, {44,45,70 ,65,68,67 ,68,71,70 },
		{70,22,21 ,67,69,66 ,70,72,69 }, {70,71,22 ,67,70,69 ,70,73,72 },
		{45,71,70 ,68,70,67 ,71,73,70 }, {45,46,71 ,68,71,70 ,71,74,73 },
		{71,23,22 ,70,2,69 ,73,2,72 }, {71,48,23 ,70,0,2 ,73,0,2 }, {46,48,71 ,71,0,70 ,74,0,73 },
		{46,47,48 ,71,4,0 ,74,4,0 }, {24,95,72 ,72,73,74 ,5,75,76 },
		{24,47,95 ,72,72,73 ,5,4,75 }, {24,73,25 ,72,75,72 ,5,77,8 },
		{24,72,73 ,72,74,75 ,5,76,77 }, {25,74,26 ,72,76,72 ,8,78,11 },
		{25,73,74 ,72,75,76 ,8,77,78 }, {26,75,27 ,72,77,72 ,11,79,14 },
		{26,74,75 ,72,76,77 ,11,78,79 }, {27,76,28 ,72,78,72 ,14,80,17 },
		{27,75,76 ,72,77,78 ,14,79,80 }, {28,77,29 ,72,79,72 ,17,81,20 },
		{28,76,77 ,72,78,79 ,17,80,81 }, {29,78,30 ,72,80,72 ,20,82,23 },
		{29,77,78 ,72,79,80 ,20,81,82 }, {78,31,30 ,80,72,72 ,82,26,23 },
		{78,79,31 ,80,81,72 ,82,83,26 }, {79,32,31 ,81,72,72 ,83,29,26 },
		{79,80,32 ,81,82,72 ,83,84,29 }, {80,33,32 ,82,72,72 ,84,32,29 },
		{80,81,33 ,82,83,72 ,84,85,32 }, {81,34,33 ,83,72,72 ,85,35,32 },
		{81,82,34 ,83,84,72 ,85,86,35 }, {82,35,34 ,84,72,72 ,86,38,35 },
		{82,83,35 ,84,85,72 ,86,87,38 }, {83,36,35 ,85,72,72 ,87,41,38 },
		{83,84,36 ,85,86,72 ,87,88,41 }, {85,36,84 ,87,72,86 ,89,46,90 },
		{85,37,36 ,87,72,72 ,89,47,46 }, {86,37,85 ,88,72,87 ,91,47,89 },
		{86,38,37 ,88,72,72 ,91,50,47 }, {87,38,86 ,89,72,88 ,92,50,91 },
		{87,39,38 ,89,72,72 ,92,53,50 }, {88,39,87 ,90,72,89 ,93,53,92 },
		{88,40,39 ,90,72,72 ,93,56,53 }, {89,40,88 ,91,72,90 ,94,56,93 },
		{89,41,40 ,91,72,72 ,94,59,56 }, {90,41,89 ,92,72,91 ,95,59,94 },
		{90,42,41 ,92,72,72 ,95,62,59 }, {43,90,91 ,72,92,93 ,65,95,96 },
		{43,42,90 ,72,72,92 ,65,62,95 }, {44,91,92 ,72,93,94 ,68,96,97 },
		{44,43,91 ,72,72,93 ,68,65,96 }, {45,92,93 ,72,94,95 ,71,97,98 },
		{45,44,92 ,72,72,94 ,71,68,97 }, {46,93,94 ,72,95,96 ,74,98,99 },
		{46,45,93 ,72,72,95 ,74,71,98 }, {47,94,95 ,72,96,73 ,4,99,75 },
		{47,46,94 ,72,72,96 ,4,74,99 }, {72,119,96 ,74,97,98 ,76,100,101 },
		{72,95,119 ,74,73,97 ,76,75,100 }, {73,96,97 ,75,98,99 ,77,101,102 },
		{73,72,96 ,75,74,98 ,77,76,101 }, {74,97,98 ,76,99,100 ,78,102,103 },
		{74,73,97 ,76,75,99 ,78,77,102 }, {75,98,99 ,77,100,101 ,79,103,104 },
		{75,74,98 ,77,76,100 ,79,78,103 }, {76,99,100 ,78,101,102 ,80,104,105 },
		{76,75,99 ,78,77,101 ,80,79,104 }, {77,100,101 ,79,102,103 ,81,105,106 },
		{77,76,100 ,79,78,102 ,81,80,105 }, {78,101,102 ,80,103,104 ,82,106,107 },
		{78,77,101 ,80,79,103 ,82,81,106 }, {103,78,102 ,105,80,104 ,108,82,107 },
		{103,79,78 ,105,81,80 ,108,83,82 }, {104,79,103 ,106,81,105 ,109,83,108 },
		{104,80,79 ,106,82,81 ,109,84,83 }, {105,80,104 ,107,82,106 ,110,84,109 },
		{105,81,80 ,107,83,82 ,110,85,84 }, {106,81,105 ,108,83,107 ,111,85,110 },
		{106,82,81 ,108,84,83 ,111,86,85 }, {107,82,106 ,109,84,108 ,112,86,111 },
		{107,83,82 ,109,85,84 ,112,87,86 }, {108,83,107 ,110,85,109 ,113,87,112 },
		{108,84,83 ,110,86,85 ,113,88,87 }, {109,84,108 ,111,86,110 ,114,90,115 },
		{109,85,84 ,111,87,86 ,114,89,90 }, {110,85,109 ,112,87,111 ,116,89,114 },
		{110,86,85 ,112,88,87 ,116,91,89 }, {111,86,110 ,113,88,112 ,117,91,116 },
		{111,87,86 ,113,89,88 ,117,92,91 }, {112,87,111 ,114,89,113 ,118,92,117 },
		{112,88,87 ,114,90,89 ,118,93,92 }, {113,88,112 ,115,90,114 ,119,93,118 },
		{113,89,88 ,115,91,90 ,119,94,93 }, {114,89,113 ,116,91,115 ,120,94,119 },
		{114,90,89 ,116,92,91 ,120,95,94 }, {91,114,115 ,93,116,117 ,96,120,121 },
		{91,90,114 ,93,92,116 ,96,95,120 }, {92,115,116 ,94,117,118 ,97,121,122 },
		{92,91,115 ,94,93,117 ,97,96,121 }, {93,116,117 ,95,118,119 ,98,122,123 },
		{93,92,116 ,95,94,118 ,98,97,122 }, {94,117,118 ,96,119,120 ,99,123,124 },
		{94,93,117 ,96,95,119 ,99,98,123 }, {95,118,119 ,73,120,97 ,75,124,100 },
		{95,94,118 ,73,96,120 ,75,99,124 }, {96,143,120 ,121,122,123 ,101,125,3 },
		{96,119,143 ,121,124,122 ,101,100,125 }, {97,120,121 ,125,123,126 ,102,3,7 },
		{97,96,120 ,125,121,123 ,102,101,3 }, {98,121,122 ,127,126,128 ,103,7,10 },
		{98,97,121 ,127,125,126 ,103,102,7 }, {99,122,123 ,129,128,130 ,104,10,13 },
		{99,98,122 ,129,127,128 ,104,103,10 }, {100,123,124 ,131,130,132 ,105,13,16 },
		{100,99,123 ,131,129,130 ,105,104,13 }, {101,124,125 ,133,132,134 ,106,16,19 },
		{101,100,124 ,133,131,132 ,106,105,16 }, {102,125,126 ,135,134,136 ,107,19,22 },
		{102,101,125 ,135,133,134 ,107,106,19 }, {127,102,126 ,137,135,136 ,25,107,22 },
		{127,103,102 ,137,138,135 ,25,108,107 }, {128,103,127 ,139,138,137 ,28,108,25 },
		{128,104,103 ,139,140,138 ,28,109,108 }, {129,104,128 ,141,140,139 ,31,109,28 },
		{129,105,104 ,141,142,140 ,31,110,109 }, {130,105,129 ,143,142,141 ,34,110,31 },
		{130,106,105 ,143,144,142 ,34,111,110 }, {131,106,130 ,145,144,143 ,37,111,34 },
		{131,107,106 ,145,146,144 ,37,112,111 }, {132,107,131 ,147,146,145 ,40,112,37 },
		{132,108,107 ,147,148,146 ,40,113,112 }, {133,108,132 ,149,148,147 ,45,115,42 },
		{133,109,108 ,149,150,148 ,45,114,115 }, {134,109,133 ,151,150,149 ,49,114,45 },
		{134,110,109 ,151,152,150 ,49,116,114 }, {135,110,134 ,153,152,151 ,52,116,49 },
		{135,111,110 ,153,154,152 ,52,117,116 }, {136,111,135 ,155,154,153 ,55,117,52 },
		{136,112,111 ,155,156,154 ,55,118,117 }, {137,112,136 ,157,156,155 ,58,118,55 },
		{137,113,112 ,157,158,156 ,58,119,118 }, {138,113,137 ,159,158,157 ,61,119,58 },
		{138,114,113 ,159,159,158 ,61,120,119 }, {115,138,139 ,160,159,161 ,121,61,64 },
		{115,114,138 ,160,159,159 ,121,120,61 }, {116,139,140 ,162,161,163 ,122,64,67 },
		{116,115,139 ,162,160,161 ,122,121,64 }, {117,140,141 ,164,163,165 ,123,67,70 },
		{117,116,140 ,164,162,163 ,123,122,67 }, {118,141,142 ,166,165,167 ,124,70,126 },
		{118,117,141 ,166,164,165 ,124,123,70 }, {119,142,143 ,124,167,122 ,100,126,125 },
		{119,118,142 ,124,166,167 ,100,124,126 }, {120,162,161 ,168,169,170 ,3,127,128 },
		{120,143,162 ,168,171,169 ,3,125,127 }, {121,161,160 ,172,170,173 ,7,128,129 },
		{121,120,161 ,172,168,170 ,7,3,128 }, {122,160,159 ,174,173,175 ,10,129,130 },
		{122,121,160 ,174,172,173 ,10,7,129 }, {123,159,158 ,176,175,177 ,13,130,131 },
		{123,122,159 ,176,174,175 ,13,10,130 }, {124,158,156 ,178,177,179 ,16,131,15 },
		{124,123,158 ,178,176,177 ,16,13,131 }, {125,156,157 ,180,179,181 ,19,15,132 },
		{125,124,156 ,180,178,179 ,19,16,15 }, {126,157,155 ,182,181,183 ,22,132,133 },
		{126,125,157 ,182,180,181 ,22,19,132 }, {154,126,155 ,184,182,183 ,134,22,133 },
		{154,127,126 ,184,185,182 ,134,25,22 }, {153,127,154 ,186,185,184 ,135,25,134 },
		{153,128,127 ,186,187,185 ,135,28,25 }, {152,128,153 ,188,187,186 ,136,28,135 },
		{152,129,128 ,188,189,187 ,136,31,28 }, {151,129,152 ,190,189,188 ,137,31,136 },
		{151,130,129 ,190,191,189 ,137,34,31 }, {150,130,151 ,192,191,190 ,138,34,137 },
		{150,131,130 ,192,193,191 ,138,37,34 }, {149,131,150 ,194,193,192 ,39,37,138 },
		{149,132,131 ,194,195,193 ,39,40,37 }, {148,132,149 ,196,195,194 ,139,42,140 },
		{148,133,132 ,196,197,195 ,139,45,42 }, {147,133,148 ,198,197,196 ,141,45,139 },
		{147,134,133 ,198,199,197 ,141,49,45 }, {146,134,147 ,200,199,198 ,142,49,141 },
		{146,135,134 ,200,201,199 ,142,52,49 }, {145,135,146 ,202,201,200 ,143,52,142 },
		{145,136,135 ,202,203,201 ,143,55,52 }, {144,136,145 ,204,203,202 ,144,55,143 },
		{144,137,136 ,204,205,203 ,144,58,55 }, {167,137,144 ,206,205,204 ,145,58,144 },
		{167,138,137 ,206,207,205 ,145,61,58 }, {139,167,166 ,208,206,209 ,64,145,146 },
		{139,138,167 ,208,207,206 ,64,61,145 }, {140,166,165 ,210,209,211 ,67,146,147 },
		{140,139,166 ,210,208,209 ,67,64,146 }, {141,165,164 ,212,211,213 ,70,147,148 },
		{141,140,165 ,212,210,211 ,70,67,147 }, {142,164,163 ,214,213,215 ,126,148,149 },
		{142,141,164 ,214,212,213 ,126,70,148 }, {143,163,162 ,171,215,169 ,125,149,127 },
		{143,142,163 ,171,214,215 ,125,126,149 }, {160,0,1 ,216,216,216 ,129,1,6 },
		{160,161,0 ,216,216,216 ,129,128,1 }, {162,0,161 ,216,216,216 ,127,1,128 },
		{162,23,0 ,216,216,216 ,127,2,1 }, {163,23,162 ,216,216,216 ,149,2,127 },
		{163,22,23 ,216,216,216 ,149,72,2 }, {164,22,163 ,216,216,216 ,148,72,149 },
		{164,21,22 ,216,216,216 ,148,69,72 }, {165,21,164 ,216,216,216 ,147,69,148 },
		{165,20,21 ,216,216,216 ,147,66,69 }, {166,20,165 ,216,216,216 ,146,66,147 },
		{166,19,20 ,216,216,216 ,146,63,66 }, {167,19,166 ,216,216,216 ,145,63,146 },
		{167,18,19 ,216,216,216 ,145,60,63 }, {17,167,144 ,216,216,216 ,57,145,144 },
		{17,18,167 ,216,216,216 ,57,60,145 }, {16,144,145 ,216,216,216 ,54,144,143 },
		{16,17,144 ,216,216,216 ,54,57,144 }, {15,145,146 ,216,216,216 ,51,143,142 },
		{15,16,145 ,216,216,216 ,51,54,143 }, {14,146,147 ,216,216,216 ,48,142,141 },
		{14,15,146 ,216,216,216 ,48,51,142 }, {13,147,148 ,216,216,216 ,43,141,139 },
		{13,14,147 ,216,216,216 ,43,48,141 }, {12,148,149 ,216,216,216 ,44,139,140 },
		{12,13,148 ,216,216,216 ,44,43,139 }, {12,150,11 ,216,216,216 ,150,138,36 },
		{12,149,150 ,216,216,216 ,150,39,138 }, {11,151,10 ,216,216,216 ,36,137,33 },
		{11,150,151 ,216,216,216 ,36,138,137 }, {10,152,9 ,216,216,216 ,33,136,30 },
		{10,151,152 ,216,216,216 ,33,137,136 }, {9,153,8 ,216,216,216 ,30,135,27 },
		{9,152,153 ,216,216,216 ,30,136,135 }, {8,154,7 ,216,216,216 ,27,134,24 },
		{8,153,154 ,216,216,216 ,27,135,134 }, {7,155,6 ,216,216,216 ,24,133,21 },
		{7,154,155 ,216,216,216 ,24,134,133 }, {155,5,6 ,216,216,216 ,133,18,21 },
		{155,157,5 ,216,216,216 ,133,132,18 }, {157,4,5 ,216,216,216 ,132,15,18 },
		{157,156,4 ,216,216,216 ,132,15,15 }, {156,3,4 ,216,216,216 ,15,12,15 },
		{156,158,3 ,216,216,216 ,15,131,12 }, {158,2,3 ,216,216,216 ,131,9,12 },
		{158,159,2 ,216,216,216 ,131,130,9 }, {159,1,2 ,216,216,216 ,130,6,9 },
		{159,160,1 ,216,216,216 ,130,129,6 }
	};
	static GLfloat vertices [168][3] = {
	{3.65f,0.0f,1.42393f},{3.52563f,-0.944689f,1.42393f},{3.16099f,-1.825f,1.42393f},
	{2.58094f,-2.58094f,1.42393f},{1.825f,-3.16099f,1.42393f},{0.944689f,-3.52563f,1.42393f},
	{0.0f,-3.65f,1.42393f},{-0.944689f,-3.52563f,1.42393f},{-1.825f,-3.16099f,1.42393f},
	{-2.58094f,-2.58094f,1.42393f},{-3.16099f,-1.825f,1.42393f},{-3.52563f,-0.944689f,1.42393f},
	{-3.65f,0.0f,1.42393f},{-3.52563f,0.944689f,1.42393f},{-3.16099f,1.825f,1.42393f},
	{-2.58094f,2.58094f,1.42393f},{-1.825f,3.16099f,1.42393f},{-0.944689f,3.52563f,1.42393f},
	{0.0f,3.65f,1.42393f},{0.944689f,3.52563f,1.42393f},{1.825f,3.16099f,1.42393f},
	{2.58094f,2.58094f,1.42393f},{3.16099f,1.825f,1.42393f},{3.52563f,0.944689f,1.42393f},
	{3.65f,0.0f,2.22393f},{3.52563f,-0.944689f,2.22393f},{3.16099f,-1.825f,2.22393f},
	{2.58094f,-2.58094f,2.22393f},{1.825f,-3.16099f,2.22393f},{0.944689f,-3.52563f,2.22393f},
	{0.0f,-3.65f,2.22393f},{-0.944689f,-3.52563f,2.22393f},{-1.825f,-3.16099f,2.22393f},
	{-2.58094f,-2.58094f,2.22393f},{-3.16099f,-1.825f,2.22393f},{-3.52563f,-0.944689f,2.22393f},
	{-3.65f,0.0f,2.22393f},{-3.52563f,0.944689f,2.22393f},{-3.16099f,1.825f,2.22393f},
	{-2.58094f,2.58094f,2.22393f},{-1.825f,3.16099f,2.22393f},{-0.944689f,3.52563f,2.22393f},
	{0.0f,3.65f,2.22393f},{0.944689f,3.52563f,2.22393f},{1.825f,3.16099f,2.22393f},
	{2.58094f,2.58094f,2.22393f},{3.16099f,1.825f,2.22393f},{3.52563f,0.944689f,2.22393f},
	{3.59614f,0.963583f,1.87393f},{3.723f,0.0f,1.87393f},{3.59614f,-0.963583f,1.87393f},
	{3.22421f,-1.8615f,1.87393f},{2.63256f,-2.63256f,1.87393f},{1.8615f,-3.22421f,1.87393f},
	{0.963583f,-3.59614f,1.87393f},{0.0f,-3.723f,1.87393f},{-0.963583f,-3.59614f,1.87393f},
	{-1.8615f,-3.22421f,1.87393f},{-2.63256f,-2.63256f,1.87393f},{-3.22421f,-1.8615f,1.87393f},
	{-3.59614f,-0.963583f,1.87393f},{-3.723f,0.0f,1.87393f},{-3.59614f,0.963583f,1.87393f},
	{-3.22421f,1.8615f,1.87393f},{-2.63256f,2.63256f,1.87393f},{-1.8615f,3.22421f,1.87393f},
	{-0.963583f,3.59614f,1.87393f},{0.0f,3.723f,1.87393f},{0.963583f,3.59614f,1.87393f},
	{1.8615f,3.22421f,1.87393f},{2.63256f,2.63256f,1.87393f},{3.22421f,1.8615f,1.87393f},
	{3.59957f,0.0f,2.22393f},{3.47692f,-0.931637f,2.22393f},{3.11732f,-1.79978f,2.22393f},
	{2.54528f,-2.54528f,2.22393f},{1.79978f,-3.11732f,2.22393f},{0.931637f,-3.47692f,2.22393f},
	{0.0f,-3.59957f,2.22393f},{-0.931637f,-3.47692f,2.22393f},{-1.79978f,-3.11732f,2.22393f},
	{-2.54528f,-2.54528f,2.22393f},{-3.11732f,-1.79978f,2.22393f},{-3.47692f,-0.931637f,2.22393f},
	{-3.59957f,0.0f,2.22393f},{-3.47692f,0.931637f,2.22393f},{-3.11732f,1.79978f,2.22393f},
	{-2.54528f,2.54528f,2.22393f},{-1.79978f,3.11732f,2.22393f},{-0.931637f,3.47692f,2.22393f},
	{0.0f,3.59957f,2.22393f},{0.931637f,3.47692f,2.22393f},{1.79978f,3.11732f,2.22393f},
	{2.54528f,2.54528f,2.22393f},{3.11732f,1.79978f,2.22393f},{3.47692f,0.931637f,2.22393f},
	{3.24655f,0.0f,1.92393f},{3.13592f,-0.840268f,1.92393f},{2.81159f,-1.62327f,1.92393f},
	{2.29566f,-2.29566f,1.92393f},{1.62327f,-2.81159f,1.92393f},{0.840268f,-3.13592f,1.92393f},
	{0.0f,-3.24655f,1.92393f},{-0.840268f,-3.13592f,1.92393f},{-1.62327f,-2.81159f,1.92393f},
	{-2.29566f,-2.29566f,1.92393f},{-2.81159f,-1.62327f,1.92393f},{-3.13592f,-0.840268f,1.92393f},
	{-3.24655f,0.0f,1.92393f},{-3.13592f,0.840268f,1.92393f},{-2.81159f,1.62327f,1.92393f},
	{-2.29566f,2.29566f,1.92393f},{-1.62327f,2.81159f,1.92393f},{-0.840268f,3.13592f,1.92393f},
	{0.0f,3.24655f,1.92393f},{0.840268f,3.13592f,1.92393f},{1.62327f,2.81159f,1.92393f},
	{2.29566f,2.29566f,1.92393f},{2.81159f,1.62327f,1.92393f},{3.13592f,0.840268f,1.92393f},
	{3.50627f,0.0f,1.87393f},{3.3868f,-0.90749f,1.87393f},{3.03652f,-1.75314f,1.87393f},
	{2.47931f,-2.47931f,1.87393f},{1.75314f,-3.03652f,1.87393f},{0.90749f,-3.3868f,1.87393f},
	{0.0f,-3.50627f,1.87393f},{-0.90749f,-3.3868f,1.87393f},{-1.75314f,-3.03652f,1.87393f},
	{-2.47931f,-2.47931f,1.87393f},{-3.03652f,-1.75314f,1.87393f},{-3.3868f,-0.90749f,1.87393f},
	{-3.50627f,0.0f,1.87393f},{-3.3868f,0.90749f,1.87393f},{-3.03652f,1.75314f,1.87393f},
	{-2.47931f,2.47931f,1.87393f},{-1.75314f,3.03652f,1.87393f},{-0.90749f,3.3868f,1.87393f},
	{0.0f,3.50627f,1.87393f},{0.90749f,3.3868f,1.87393f},{1.75314f,3.03652f,1.87393f},
	{2.47931f,2.47931f,1.87393f},{3.03652f,1.75314f,1.87393f},{3.3868f,0.90749f,1.87393f},
	{-0.905532f,3.37949f,1.42393f},{-1.74935f,3.02997f,1.42393f},{-2.47396f,2.47396f,1.42393f},
	{-3.02997f,1.74935f,1.42393f},{-3.37949f,0.905532f,1.42393f},{-3.49871f,0.0f,1.42393f},
	{-3.37949f,-0.905532f,1.42393f},{-3.02997f,-1.74935f,1.42393f},{-2.47396f,-2.47396f,1.42393f},
	{-1.74935f,-3.02997f,1.42393f},{-0.905532f,-3.37949f,1.42393f},{0.0f,-3.49871f,1.42393f},
	{1.74935f,-3.02997f,1.42393f},{0.905532f,-3.37949f,1.42393f},{2.47396f,-2.47396f,1.42393f},
	{3.02997f,-1.74935f,1.42393f},{3.37949f,-0.905532f,1.42393f},{3.49871f,0.0f,1.42393f},
	{3.37949f,0.905532f,1.42393f},{3.02997f,1.74935f,1.42393f},{2.47396f,2.47396f,1.42393f},
	{1.74935f,3.02997f,1.42393f},{0.905532f,3.37949f,1.42393f},{0.0f,3.49871f,1.42393f}
	};
	static GLfloat normals [217][3] = {
	{0.96573f,0.258581f,0.0224122f},{0.986171f,0.0432773f,-0.159979f},{0.941367f,0.297043f,-0.159979f},
	{0.999749f,-0.000179149f,0.0224121f},{0.955815f,0.211676f,0.20399f},{0.978032f,-0.0429201f,0.20399f},
	{0.963769f,-0.213437f,-0.159979f},{0.965637f,-0.258927f,0.0224121f},{0.933598f,-0.294591f,0.20399f},
	{0.875688f,-0.455606f,-0.159979f},{0.865718f,-0.50003f,0.0224122f},{0.82554f,-0.526186f,0.20399f},
	{0.72793f,-0.666727f,-0.159979f},{0.706802f,-0.707056f,0.0224121f},{0.661224f,-0.721922f,0.20399f},
	{0.530565f,-0.832411f,-0.159979f},{0.499719f,-0.865897f,0.0224121f},{0.451846f,-0.86846f,0.20399f},
	{0.297043f,-0.941367f,-0.159979f},{0.258581f,-0.96573f,0.0224122f},{0.211676f,-0.955815f,0.20399f},
	{0.0432773f,-0.986171f,-0.159979f},{-0.000179149f,-0.999749f,0.0224121f},{-0.0429201f,-0.978032f,0.20399f},
	{-0.213437f,-0.963769f,-0.159979f},{-0.258927f,-0.965637f,0.0224121f},{-0.294591f,-0.933598f,0.20399f},
	{-0.455606f,-0.875688f,-0.159979f},{-0.50003f,-0.865718f,0.0224122f},{-0.526186f,-0.82554f,0.20399f},
	{-0.666727f,-0.72793f,-0.159979f},{-0.707056f,-0.706802f,0.0224121f},{-0.721922f,-0.661224f,0.20399f},
	{-0.832411f,-0.530565f,-0.159979f},{-0.865897f,-0.499719f,0.0224121f},{-0.86846f,-0.451846f,0.20399f},
	{-0.941367f,-0.297043f,-0.159979f},{-0.96573f,-0.258581f,0.0224122f},{-0.955815f,-0.211676f,0.20399f},
	{-0.986171f,-0.0432773f,-0.159979f},{-0.999749f,0.000179149f,0.0224121f},{-0.978032f,0.0429201f,0.20399f},
	{-0.963769f,0.213437f,-0.159979f},{-0.965637f,0.258927f,0.0224121f},{-0.933598f,0.294591f,0.20399f},
	{-0.875688f,0.455606f,-0.159979f},{-0.865718f,0.50003f,0.0224122f},{-0.82554f,0.526186f,0.20399f},
	{-0.72793f,0.666727f,-0.159979f},{-0.706802f,0.707056f,0.0224121f},{-0.661224f,0.721922f,0.20399f},
	{-0.530565f,0.832411f,-0.159979f},{-0.499719f,0.865897f,0.0224121f},{-0.451846f,0.86846f,0.20399f},
	{-0.297043f,0.941367f,-0.159979f},{-0.258581f,0.96573f,0.0224122f},{-0.211676f,0.955815f,0.20399f},
	{-0.0432773f,0.986171f,-0.159979f},{0.000179149f,0.999749f,0.0224121f},{0.0429201f,0.978032f,0.20399f},
	{0.213437f,0.963769f,-0.159979f},{0.258927f,0.965637f,0.0224121f},{0.294591f,0.933598f,0.20399f},
	{0.455606f,0.875688f,-0.159979f},{0.50003f,0.865718f,0.0224122f},{0.526186f,0.82554f,0.20399f},
	{0.666727f,0.72793f,-0.159979f},{0.707056f,0.706802f,0.0224121f},{0.721922f,0.661224f,0.20399f},
	{0.832411f,0.530565f,-0.159979f},{0.865897f,0.499719f,0.0224121f},{0.86846f,0.451846f,0.20399f},
	{0.0f,0.0f,1.0f},{-0.32865f,-0.103703f,0.938741f},{-0.412187f,-0.0180885f,0.91092f},
	{-0.336471f,0.0745152f,0.938741f},{-0.30572f,0.159061f,0.938741f},{-0.254135f,0.232768f,0.938741f},
	{-0.185231f,0.290611f,0.938741f},{-0.103703f,0.32865f,0.938741f},{0.0f,0.344331f,0.938848f},
	{0.103703f,0.32865f,0.938741f},{0.185231f,0.290611f,0.938741f},{0.254135f,0.232768f,0.938741f},
	{0.30572f,0.159061f,0.938741f},{0.336471f,0.0745152f,0.938741f},{0.412187f,-0.0180885f,0.91092f},
	{0.32865f,-0.103703f,0.938741f},{0.290611f,-0.185231f,0.938741f},{0.232768f,-0.254135f,0.938741f},
	{0.159061f,-0.30572f,0.938741f},{0.0745152f,-0.336471f,0.938741f},{0.0f,-0.227697f,0.973732f},
	{-0.0745152f,-0.336471f,0.938741f},{-0.159061f,-0.30572f,0.938741f},{-0.232768f,-0.254135f,0.938741f},
	{-0.290611f,-0.185231f,0.938741f},{-0.632599f,-0.140096f,0.761704f},{-0.647303f,0.0284063f,0.761703f},
	{-0.617894f,0.194973f,0.761703f},{-0.546378f,0.348252f,0.761703f},{-0.437626f,0.477799f,0.761703f},
	{-0.299051f,0.574784f,0.761703f},{-0.140096f,0.632599f,0.761704f},{0.0f,0.647564f,0.762011f},
	{0.140096f,0.632599f,0.761704f},{0.299051f,0.574784f,0.761703f},{0.437626f,0.477799f,0.761703f},
	{0.546378f,0.348252f,0.761703f},{0.617894f,0.194973f,0.761703f},{0.647303f,0.0284063f,0.761703f},
	{0.632599f,-0.140096f,0.761704f},{0.574784f,-0.299051f,0.761703f},{0.477799f,-0.437626f,0.761703f},
	{0.348252f,-0.546378f,0.761703f},{0.194973f,-0.617894f,0.761703f},{0.0f,-0.647564f,0.762011f},
	{-0.194973f,-0.617894f,0.761703f},{-0.348252f,-0.546378f,0.761703f},{-0.477799f,-0.437626f,0.761703f},
	{-0.574784f,-0.299051f,0.761703f},{-0.189033f,-0.00829558f,-0.981936f},{-0.184739f,-0.0409125f,-0.981936f},
	{-0.189033f,0.00829559f,-0.981936f},{-0.180445f,-0.0569383f,-0.981936f},{-0.184739f,0.0409125f,-0.981936f},
	{-0.180445f,0.0569383f,-0.981936f},{-0.167856f,0.0873325f,-0.981936f},{-0.15956f,0.101701f,-0.981936f},
	{-0.139533f,0.127801f,-0.981936f},{-0.127801f,0.139533f,-0.981936f},{-0.101701f,0.15956f,-0.981936f},
	{-0.0873325f,0.167856f,-0.981936f},{-0.0569383f,0.180445f,-0.981936f},{-0.0409125f,0.184739f,-0.981936f},
	{-4.65805e-010f,0.18904f,-0.981969f},{0.0f,0.18904f,-0.981969f},{0.0409125f,0.184739f,-0.981936f},
	{0.0569383f,0.180445f,-0.981936f},{0.0873325f,0.167856f,-0.981936f},{0.101701f,0.15956f,-0.981936f},
	{0.127801f,0.139533f,-0.981936f},{0.139533f,0.127801f,-0.981936f},{0.15956f,0.101701f,-0.981936f},
	{0.167856f,0.0873325f,-0.981936f},{0.180445f,0.0569383f,-0.981936f},{0.184739f,0.0409125f,-0.981936f},
	{0.189033f,0.00829559f,-0.981936f},{0.189033f,-0.00829558f,-0.981936f},{0.184739f,-0.0409125f,-0.981936f},
	{0.180445f,-0.0569383f,-0.981936f},{0.167856f,-0.0873325f,-0.981936f},{0.15956f,-0.101701f,-0.981936f},
	{0.139533f,-0.127801f,-0.981936f},{0.127801f,-0.139533f,-0.981936f},{0.101701f,-0.15956f,-0.981936f},
	{0.0873325f,-0.167856f,-0.981936f},{0.0569383f,-0.180445f,-0.981936f},{0.0409125f,-0.184739f,-0.981936f},
	{0.0f,-0.18904f,-0.981969f},{-0.0409125f,-0.184739f,-0.981936f},{-0.0569383f,-0.180445f,-0.981936f},
	{-0.0873325f,-0.167856f,-0.981936f},{-0.101701f,-0.15956f,-0.981936f},{-0.127801f,-0.139533f,-0.981936f},
	{-0.139533f,-0.127801f,-0.981936f},{-0.15956f,-0.101701f,-0.981936f},{-0.167856f,-0.0873325f,-0.981936f},
	{-0.998897f,-0.0438359f,0.0167964f},{-0.976206f,-0.216192f,0.0167964f},{-0.998897f,0.0438358f,0.0167964f},
	{-0.953515f,-0.300876f,0.0167966f},{-0.976206f,0.216192f,0.0167964f},{-0.953515f,0.300876f,0.0167966f},
	{-0.886989f,0.461486f,0.0167967f},{-0.843153f,0.537412f,0.0167965f},{-0.737324f,0.675331f,0.0167962f},
	{-0.675331f,0.737324f,0.0167962f},{-0.537412f,0.843153f,0.0167965f},{-0.461486f,0.886989f,0.0167967f},
	{-0.300876f,0.953515f,0.0167966f},{-0.216192f,0.976206f,0.0167964f},{3.75743e-009f,0.999859f,0.0168126f},
	{0.0f,0.999859f,0.0168125f},{0.216192f,0.976206f,0.0167964f},{0.300876f,0.953515f,0.0167966f},
	{0.461486f,0.886989f,0.0167967f},{0.537412f,0.843153f,0.0167965f},{0.675331f,0.737324f,0.0167962f},
	{0.737324f,0.675331f,0.0167962f},{0.843153f,0.537412f,0.0167965f},{0.886989f,0.461486f,0.0167967f},
	{0.953515f,0.300876f,0.0167966f},{0.976206f,0.216192f,0.0167964f},{0.998897f,0.0438358f,0.0167964f},
	{0.998897f,-0.0438359f,0.0167964f},{0.976206f,-0.216192f,0.0167964f},{0.953515f,-0.300876f,0.0167966f},
	{0.886989f,-0.461486f,0.0167967f},{0.843153f,-0.537412f,0.0167965f},{0.737324f,-0.675331f,0.0167962f},
	{0.675331f,-0.737324f,0.0167962f},{0.537412f,-0.843153f,0.0167965f},{0.461486f,-0.886989f,0.0167967f},
	{0.300876f,-0.953515f,0.0167966f},{0.216192f,-0.976206f,0.0167964f},{-3.75743e-009f,-0.999859f,0.0168126f},
	{0.0f,-0.999859f,0.0168125f},{-0.216192f,-0.976206f,0.0167964f},{-0.300876f,-0.953515f,0.0167966f},
	{-0.461486f,-0.886989f,0.0167967f},{-0.537412f,-0.843153f,0.0167965f},{-0.675331f,-0.737324f,0.0167962f},
	{-0.737324f,-0.675331f,0.0167962f},{-0.843153f,-0.537412f,0.0167965f},{-0.886989f,-0.461486f,0.0167967f},
	{0.0f,0.0f,-1.0f}
	};
	static GLfloat textures [151][2] = {
	{0.281812f,0.72213f},{0.2602f,0.699725f},{0.281812f,0.699725f},
	{0.2602f,0.72213f},{0.281812f,0.739556f},{0.2602f,0.739556f},
	{0.238588f,0.699725f},{0.238588f,0.72213f},{0.238588f,0.739556f},
	{0.216977f,0.699725f},{0.216977f,0.72213f},{0.216977f,0.739556f},
	{0.195365f,0.699725f},{0.195365f,0.72213f},{0.195365f,0.739556f},
	{0.173753f,0.699725f},{0.173753f,0.72213f},{0.173753f,0.739556f},
	{0.152141f,0.699725f},{0.152141f,0.72213f},{0.152141f,0.739556f},
	{0.13053f,0.699725f},{0.13053f,0.72213f},{0.13053f,0.739556f},
	{0.108918f,0.699725f},{0.108918f,0.72213f},{0.108918f,0.739556f},
	{0.0873061f,0.699725f},{0.0873061f,0.72213f},{0.0873061f,0.739556f},
	{0.0656943f,0.699725f},{0.0656943f,0.72213f},{0.0656943f,0.739556f},
	{0.0440826f,0.699725f},{0.0440826f,0.72213f},{0.0440826f,0.739556f},
	{0.0224709f,0.699725f},{0.0224709f,0.72213f},{0.0224709f,0.739556f},
	{0.000859129f,0.699725f},{0.000859129f,0.72213f},{0.000859129f,0.739556f},
	{0.519541f,0.72213f},{0.497929f,0.699725f},{0.519541f,0.699725f},
	{0.497929f,0.72213f},{0.519541f,0.739556f},{0.497929f,0.739556f},
	{0.476317f,0.699725f},{0.476317f,0.72213f},{0.476317f,0.739556f},
	{0.454706f,0.699725f},{0.454706f,0.72213f},{0.454706f,0.739556f},
	{0.433094f,0.699725f},{0.433094f,0.72213f},{0.433094f,0.739556f},
	{0.411482f,0.699725f},{0.411482f,0.72213f},{0.411482f,0.739556f},
	{0.38987f,0.699725f},{0.38987f,0.72213f},{0.38987f,0.739556f},
	{0.368259f,0.699725f},{0.368259f,0.72213f},{0.368259f,0.739556f},
	{0.346647f,0.699725f},{0.346647f,0.72213f},{0.346647f,0.739556f},
	{0.325035f,0.699725f},{0.325035f,0.72213f},{0.325035f,0.739556f},
	{0.303423f,0.699725f},{0.303423f,0.72213f},{0.303423f,0.739556f},
	{0.281812f,0.741985f},{0.2602f,0.741985f},{0.238588f,0.741985f},
	{0.216977f,0.741985f},{0.195365f,0.741985f},{0.173753f,0.741985f},
	{0.152141f,0.741985f},{0.13053f,0.741985f},{0.108918f,0.741985f},
	{0.0873061f,0.741985f},{0.0656943f,0.741985f},{0.0440826f,0.741985f},
	{0.0224709f,0.741985f},{0.000859129f,0.741985f},{0.497929f,0.741985f},
	{0.519541f,0.741985f},{0.476317f,0.741985f},{0.454706f,0.741985f},
	{0.433094f,0.741985f},{0.411482f,0.741985f},{0.38987f,0.741985f},
	{0.368259f,0.741985f},{0.346647f,0.741985f},{0.325035f,0.741985f},
	{0.303423f,0.741985f},{0.281812f,0.757003f},{0.2602f,0.757003f},
	{0.238588f,0.757003f},{0.216977f,0.757003f},{0.195365f,0.757003f},
	{0.173753f,0.757003f},{0.152141f,0.757003f},{0.13053f,0.757003f},
	{0.108918f,0.757003f},{0.0873061f,0.757003f},{0.0656943f,0.757003f},
	{0.0440826f,0.757003f},{0.0224709f,0.757003f},{0.000859129f,0.757003f},
	{0.497929f,0.757003f},{0.519541f,0.757003f},{0.476317f,0.757003f},
	{0.454706f,0.757003f},{0.433094f,0.757003f},{0.411482f,0.757003f},
	{0.38987f,0.757003f},{0.368259f,0.757003f},{0.346647f,0.757003f},
	{0.325035f,0.757003f},{0.303423f,0.757003f},{0.281812f,0.72213f},
	{0.303423f,0.72213f},{0.281812f,0.699725f},{0.2602f,0.699725f},
	{0.238588f,0.699725f},{0.216977f,0.699725f},{0.195365f,0.699725f},
	{0.152141f,0.699725f},{0.13053f,0.699725f},{0.108918f,0.699725f},
	{0.0873061f,0.699725f},{0.0656943f,0.699725f},{0.0440826f,0.699725f},
	{0.0224709f,0.699725f},{0.497929f,0.699725f},{0.519541f,0.699725f},
	{0.476317f,0.699725f},{0.454706f,0.699725f},{0.433094f,0.699725f},
	{0.411482f,0.699725f},{0.38987f,0.699725f},{0.368259f,0.699725f},
	{0.346647f,0.699725f},{0.325035f,0.699725f},{0.303423f,0.699725f},
	{0.000859129f,0.700337f}
	};
	GLint GenEPuckRing()
	{
	unsigned i;
	unsigned j;
	
	GLint lid=glGenLists(1);
	glNewList(lid, GL_COMPILE);
		glBegin (GL_TRIANGLES);
		for(i=0;i<sizeof(face_indicies)/sizeof(face_indicies[0]);i++)
		{
		for(j=0;j<3;j++)
			{
			int vi=face_indicies[i][j];
			int ni=face_indicies[i][j+3];//Normal index
			int ti=face_indicies[i][j+6];//Texture index
			/*glNormal3f (normals[ni][0],normals[ni][1],normals[ni][2]);
			glTexCoord2f(textures[ti][0],textures[ti][1]);
			glVertex3f (vertices[vi][0],vertices[vi][1],vertices[vi][2]);*/
			
			// rotate 90 deg around z
			glNormal3f (normals[ni][1],-normals[ni][0],normals[ni][2]);
			glTexCoord2f(textures[ti][0],textures[ti][1]);
			glVertex3f (vertices[vi][1],-vertices[vi][0],vertices[vi][2]);
			}
		}
		glEnd ();
	
	glEndList();
	return lid;
	};
}
