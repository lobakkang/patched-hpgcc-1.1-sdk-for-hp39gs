
//Modified by Al, remove extra minifont.

char * get_minifont(); //In Ingo's 'putcon.s'

union {
	struct {
	int cdatalow,cdatahigh;
	} word;
	char bytes[8];
} _MFchar;

char *getMF(int z){
int offset,rot;
	char  * minifont = get_minifont();

// ADDED BY CLAUDIO, CORRECT THE MISALIGNMENT IN SYSTEM MINIFONT

// CALC OFFSET IN NIBBLES
offset=z*6+7;
// OFFSET IN NIBBLES
rot=offset&7;
// WORD WITH THE START OF CHAR
offset&=0xfffffff8;
// READ THE DATA CHARACTER
_MFchar.word.cdatalow=*(int *)(minifont+(offset>>1));
_MFchar.word.cdatahigh=*(int *)(minifont+4+(offset>>1));

while(rot) {
_MFchar.word.cdatalow= (_MFchar.word.cdatalow>>4) | (_MFchar.word.cdatahigh<<28);
_MFchar.word.cdatahigh>>=4;
--rot;
}
	return _MFchar.bytes;
}
